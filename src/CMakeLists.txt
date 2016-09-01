file(GLOB SOURCE_FILES *.cpp *.h)

add_library(SimpleContainer ${SOURCE_FILES})

set_target_properties(SimpleContainer PROPERTIES COMPILE_FLAGS "/MTd")
set_target_properties(SimpleContainer PROPERTIES SUFFIX ".lib")
set_target_properties(SimpleContainer PROPERTIES FOLDER "Container Targets")

