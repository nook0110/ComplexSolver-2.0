@echo off
REM Build script for ComplexSolver project on Windows

echo Cleaning git repository and submodules...
git reset --hard
git submodule foreach --recursive git clean -xfd

echo Configuring and building SFML...
cmake -DCMAKE_INSTALL_PREFIX=SFML/install -B SFML/build SFML
cmake --build SFML/build --target install

echo Cleaning and rebuilding main project...
rmdir /s /q build
mkdir build
cd build
cmake ..
cmake --build .