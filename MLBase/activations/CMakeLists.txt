project (activations)

file(GLOB_RECURSE activations_source CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/includes/*.h ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/includes/*.hpp)
# Add a includesrary with the above sources
add_library(${PROJECT_NAME} SHARED ${activations_source})