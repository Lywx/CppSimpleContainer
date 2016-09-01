file(GLOB TEST_SOURCE_FILES *.cpp *.hpp)

include_directories(${SIMPLE_CONTAINER_SOURCE_DIR})
link_directories(${SIMPLE_CONTAINER_SOURCE_DIR})

add_executable(SimpleContainer.Test ${TEST_SOURCE_FILES})

set_target_properties(SimpleContainer.Test PROPERTIES COMPILE_FLAGS "/MTd")
set_target_properties(SimpleContainer.Test PROPERTIES SUFFIX ".exe")
set_target_properties(SimpleContainer.Test PROPERTIES FOLDER "Container Targets")
