# CMakeLists.txt for "input_handling" concept

# Set target name
set(TARGET_NAME input_handling)

# Add source files
file(GLOB SOURCES "*.cpp")

# Create executable target
add_executable(${TARGET_NAME} ${SOURCES})

# Link GLFW and Glad
target_link_libraries(${TARGET_NAME} glfw)
target_link_libraries(${TARGET_NAME} glad)

# Include common directory for shared utilities
target_include_directories(${TARGET_NAME} PRIVATE ../common)
