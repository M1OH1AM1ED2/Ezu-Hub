clear
cd ~/Desktop/C++/nega
rm -rf build CMakeCache.txt CMakeFiles
mkdir build
cd build
cmake ..
cmake --build . -j$(nproc)
env -i DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY HOME=$HOME ./nega
#clear
