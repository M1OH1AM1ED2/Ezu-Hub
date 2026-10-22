#!/bin/bash
set -e
cd "$(dirname "$(readlink -f "$0")")"

V="$1"
[ -z "$V" ] && { echo "الاستخدام: ./release.sh 2.16.0"; exit 1; }

# 1. تحديث الإصدار ورفعه
sed -i "s/project(Ezu-Hub VERSION [0-9.]*/project(Ezu-Hub VERSION $V/" CMakeLists.txt
git add CMakeLists.txt
git commit -m "Release v$V" || true     # لا يتوقف لو ما في تغييرات
git push origin main

# 2. البناء
rm -rf build AppDir
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
cmake --build build --parallel 2

# 3. حزمة deb
(cd build && cpack)
cp build/ezu-hub_*.deb .

# 4. AppImage
DESTDIR=AppDir cmake --install build
wget -nc https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage
wget -nc https://github.com/linuxdeploy/linuxdeploy-plugin-qt/releases/download/continuous/linuxdeploy-plugin-qt-x86_64.AppImage
chmod +x linuxdeploy*.AppImage

export QMAKE="$(command -v qmake6)"
export EXTRA_QT_PLUGINS="multimedia"
export LINUXDEPLOY_OUTPUT_VERSION="$V"
./linuxdeploy-x86_64.AppImage --appdir AppDir --plugin qt \
  --desktop-file Ezu-Hub.desktop --icon-file Ezu-Hub.png --output appimage

# 5. إنشاء Release على GitHub ورفع الملفات
git tag "v$V" && git push origin "v$V"
gh release create "v$V" Ezu-Hub-*.AppImage ezu-hub_*.deb \
  --title "Ezu-Hub v$V" --notes "الإصدار $V"
