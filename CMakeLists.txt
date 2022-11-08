cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(ml_lib)

add_executable(main ../src/main.cpp)

target_include_directories(main
    PUBLIC ${PROJECT_SOURCE_DIR}/includes
)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests ../tests/testMatrix.cpp)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
add_subdirectory(${PROJECT_SOURCE_DIR}/includes)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain includes)
target_link_libraries(main PRIVATE includes)
