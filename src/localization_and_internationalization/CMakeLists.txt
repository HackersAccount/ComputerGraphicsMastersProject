# CMakeLists.txt for "localization_and_internationalization" concept

# Set target name
set(TARGET_NAME localization_and_internationalization)

# Add source files
file(GLOB SOURCES "*.cpp")

# Create executable target
add_executable(${TARGET_NAME} ${SOURCES})

# Link GLFW and Glad
target_link_libraries(${TARGET_NAME} glfw)
target_link_libraries(${TARGET_NAME} glad)

# Include common directory for shared utilities
target_include_directories(${TARGET_NAME} PRIVATE ../common)
