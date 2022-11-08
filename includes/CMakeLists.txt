project (includes)

file(GLOB_RECURSE includes_src CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/includes/*.cpp)
# Add a library with the above sources
add_library(${PROJECT_NAME} ${includes_src})
