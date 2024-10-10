cmake . -B"build" -G"Unix Makefiles" \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -DCMAKE_BUILD_TYPE=Release \
    -DUPSTREAM_GITREF=${UPSTREAM_GITREF} \
    -DBUILD_INTENT=${BUILD_INTENT}
cmake --build build
