clear
cd ~/Desktop/C++/Ezu-Hub
rm -rf  CMakeCache.txt CMakeFiles
mkdir build
cd build
cmake ..
cmake --build . -j$(nproc)
env -i DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY HOME=$HOME ./Ezu-Hub
exit
