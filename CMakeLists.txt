cmake_minimum_required(VERSION 3.10)


# Specify C++ Standard.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify warnings for all builds.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -g -Wno-unused-function")

# Specify debug symbols and no optimizations for Debug builds.
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -D_GLIBCXX_DEBUG -O0 -gdwarf-4")
project(ml_lib)

add_executable(main ../src/main.cpp)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_subdirectory(${PROJECT_SOURCE_DIR}/linalg)
add_subdirectory(${PROJECT_SOURCE_DIR}/MLBase)

file(GLOB_RECURSE tests_source ${CMAKE_SOURCE_DIR}/tests/*.cpp)

add_executable(tests ${tests_source})
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)


target_include_directories(tests
    PUBLIC ${PROJECT_SOURCE_DIR}/linalg ${PROJECT_SOURCE_DIR}/MLBase
)

target_include_directories(main
    PUBLIC ${PROJECT_SOURCE_DIR}/linalg ${PROJECT_SOURCE_DIR}/MLBase
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain linalg mlbase)
target_link_libraries(main PRIVATE linalg mlbase)

