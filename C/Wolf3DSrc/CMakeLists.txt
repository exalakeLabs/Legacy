cmake_minimum_required(VERSION 3.20)
project(wolf3d_port VERSION 0.1.0 LANGUAGES C)

option(WOLF3D_ENABLE_SANITIZERS "Enable address and undefined-behavior sanitizers" OFF)
option(WOLF3D_BUILD_TESTS "Build headless unit tests" ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(wolf3d_portable
    src/portable/assets.c
    src/portable/framebuffer.c
    src/portable/paths.c
    src/portable/persistence.c)
target_include_directories(wolf3d_portable PUBLIC include)
target_compile_options(wolf3d_portable PRIVATE -Wall -Wextra -Wpedantic)

if(WOLF3D_ENABLE_SANITIZERS AND CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(wolf3d_portable PUBLIC -fno-omit-frame-pointer -fsanitize=address,undefined)
    target_link_options(wolf3d_portable PUBLIC -fno-omit-frame-pointer -fsanitize=address,undefined)
endif()

find_package(SDL3 CONFIG QUIET)
if(SDL3_FOUND)
    add_executable(wolf3d-port
        src/portable/main.c
        src/portable/platform_sdl3.c)
    target_link_libraries(wolf3d-port PRIVATE wolf3d_portable SDL3::SDL3)
    install(TARGETS wolf3d-port RUNTIME DESTINATION bin)
    if(WOLF3D_BUILD_TESTS)
        add_test(NAME sdl-smoke-test COMMAND wolf3d-port --smoke-test)
        set_tests_properties(sdl-smoke-test PROPERTIES
            ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy")
    endif()
else()
    message(STATUS "SDL3 not found: the interactive wolf3d-port target is disabled")
endif()

if(WOLF3D_BUILD_TESTS)
    enable_testing()
    add_executable(portable-tests tests/portable_tests.c)
    target_link_libraries(portable-tests PRIVATE wolf3d_portable)
    add_test(NAME portable-tests COMMAND portable-tests)
endif()

install(FILES packaging/io.github.exalakeLabs.Wolf3D.desktop
        DESTINATION share/applications)
