#!/usr/bin/env bash
set -Eeuo pipefail

PROJECT="$HOME/Desktop/C++/Ezu-Hub"
TOOLS="$HOME/AppImage-Build"

cd "$PROJECT"

read -rp "Version الجديدة (مثال 1.1.3): " VERSION

if [[ ! "$VERSION" =~ ^[0-9]+\.[0-9]+\.[0-9]+$ ]]; then
    echo "Version غير صالح."
    exit 1
fi

OUT="$PROJECT/releases/$VERSION"
APPDIR="$TOOLS/Ezu-Hub.AppDir"

mkdir -p "$OUT"

echo "==> Building Ezu-Hub..."
cmake -S "$PROJECT" -B "$PROJECT/build" -DCMAKE_BUILD_TYPE=Release
cmake --build "$PROJECT/build" -j"$(nproc)"

if [[ ! -x "$PROJECT/build/Ezu-Hub" ]]; then
    echo "خطأ: الملف build/Ezu-Hub غير موجود."
    exit 1
fi

echo "==> Creating .deb..."
STAGE="$(mktemp -d)"
trap 'rm -rf "$STAGE"' EXIT

mkdir -p \
    "$STAGE/DEBIAN" \
    "$STAGE/opt/ezu-hub" \
    "$STAGE/usr/bin" \
    "$STAGE/usr/share/applications" \
    "$STAGE/usr/share/icons/hicolor/256x256/apps" \
    "$STAGE/usr/share/ezu-hub/default-data"

install -m 755 "$PROJECT/build/Ezu-Hub" "$STAGE/opt/ezu-hub/Ezu-Hub"

cat > "$STAGE/usr/bin/ezu-hub" <<'LAUNCHER'
#!/bin/sh
exec /opt/ezu-hub/Ezu-Hub "$@"
LAUNCHER
chmod 755 "$STAGE/usr/bin/ezu-hub"

if [[ -f "$APPDIR/usr/share/applications/ezu-hub.desktop" ]]; then
    install -m 644 "$APPDIR/usr/share/applications/ezu-hub.desktop" \
        "$STAGE/usr/share/applications/ezu-hub.desktop"
else
    cat > "$STAGE/usr/share/applications/ezu-hub.desktop" <<'DESKTOP'
[Desktop Entry]
Name=Ezu-Hub
Exec=ezu-hub
Type=Application
Terminal=false
Categories=Development;IDE;
DESKTOP
fi

if [[ -f "$APPDIR/usr/share/icons/hicolor/256x256/apps/ezu-hub.png" ]]; then
    install -m 644 \
        "$APPDIR/usr/share/icons/hicolor/256x256/apps/ezu-hub.png" \
        "$STAGE/usr/share/icons/hicolor/256x256/apps/ezu-hub.png"
fi

for DB in Paramiter.db login_Database.db Editor_Database.db; do
    if [[ -f "$PROJECT/$DB" ]]; then
        install -m 644 "$PROJECT/$DB" "$STAGE/usr/share/ezu-hub/default-data/$DB"
    elif [[ -f "$APPDIR/usr/share/ezu-hub/default-data/$DB" ]]; then
        install -m 644 "$APPDIR/usr/share/ezu-hub/default-data/$DB" \
            "$STAGE/usr/share/ezu-hub/default-data/$DB"
    fi
done

cat > "$STAGE/DEBIAN/control" <<CONTROL
Package: ezu-hub
Version: $VERSION
Section: devel
Priority: optional
Architecture: amd64
Maintainer: Moha
Description: Ezu-Hub development environment
CONTROL

dpkg-deb --build "$STAGE" "$OUT/Ezu-Hub_${VERSION}_amd64.deb"

echo "==> Creating AppImage..."
if [[ ! -x "$TOOLS/linuxdeploy-x86_64.AppImage" ]]; then
    echo "خطأ: linuxdeploy غير موجود في $TOOLS"
    exit 1
fi

if [[ ! -d "$APPDIR" ]]; then
    echo "خطأ: AppDir غير موجود: $APPDIR"
    exit 1
fi

install -m 755 "$PROJECT/build/Ezu-Hub" "$APPDIR/usr/bin/Ezu-Hub"

(
    cd "$TOOLS"
    export ARCH=x86_64
    export VERSION="$VERSION"

    if command -v qmake6 >/dev/null 2>&1; then
        export QMAKE="$(command -v qmake6)"
    fi

    ./linuxdeploy-x86_64.AppImage \
        --appdir "$APPDIR" \
        --plugin qt \
        --output appimage

    GENERATED="$(find "$TOOLS" -maxdepth 1 -type f -name '*.AppImage' \
        -printf '%T@ %p\n' | sort -nr | head -n1 | cut -d' ' -f2-)"

    if [[ -z "$GENERATED" || ! -f "$GENERATED" ]]; then
        echo "خطأ: لم يتم العثور على AppImage."
        exit 1
    fi

    cp "$GENERATED" "$OUT/Ezu-Hub-${VERSION}-x86_64.AppImage"
)

echo
echo "تم إنشاء ملفات الإصدار:"
ls -lh "$OUT"
