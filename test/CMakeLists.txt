file(GLOB TEST_SOURCE_FILES *.cpp *.hpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${SIMPLE_CONTAINER_ARCHIVE_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SIMPLE_CONTAINER_LIBRARY_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SIMPLE_CONTAINER_RUNTIME_OUTPUT_DIR})

include_directories(${SIMPLE_CONTAINER_SOURCE_DIR})
link_directories(${SIMPLE_CONTAINER_LIBRARY_OUTPUT_DIR})

add_executable(SimpleContainer.Test ${TEST_SOURCE_FILES})
target_link_libraries(SimpleContainer.Test 
	SimpleContainer)

set_target_properties(SimpleContainer.Test PROPERTIES COMPILE_FLAGS "/MTd")
set_target_properties(SimpleContainer.Test PROPERTIES SUFFIX ".exe")
set_target_properties(SimpleContainer.Test PROPERTIES FOLDER "Container Targets")
