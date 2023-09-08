project (mlbase)

add_subdirectory(${PROJECT_SOURCE_DIR}/activations)
add_subdirectory(${PROJECT_SOURCE_DIR}/losses)
add_subdirectory(${PROJECT_SOURCE_DIR}/network)

file(GLOB_RECURSE mlbase_source CONFIGURE_DEPENDS *.h *.cpp $ *.hpp)
# Add a includesrary with the above sources
add_library(${PROJECT_NAME} SHARED ${mlbase_source})

