# CMake Build
## Windows with MinGW
	cmake -B build -G "MinGW Makefiles"; mingw32-make --directory build
## Linux
	cmake -B build && make --directory build