# CMakeLists.txt for the external/glad directory

# Add all header files in the glad directory to the include path
file(GLOB GLAD_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
add_library(glad INTERFACE)
target_include_directories(glad INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# No need for linking or compilation, as glad is a header-only library
