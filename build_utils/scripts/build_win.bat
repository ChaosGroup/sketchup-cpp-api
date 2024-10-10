call "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x64
cmake . -B"build" -G"Ninja" ^
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON  ^
    -DCMAKE_BUILD_TYPE=Release  ^
    -DUPSTREAM_GITREF=%UPSTREAM_GITREF% ^
    -DBUILD_INTENT=%BUILD_INTENT%
cmake --build "build"
