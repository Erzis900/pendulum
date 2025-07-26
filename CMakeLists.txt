cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Pendulum)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

add_executable(pendulum 
    src/main.cpp 
    src/constants.cpp
    src/pendulum.cpp
    src/inputManager.cpp
)

target_link_libraries(pendulum PRIVATE raylib)