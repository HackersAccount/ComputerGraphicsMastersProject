# CMakeLists.txt for "basic_triangle_rendering" concept

# Set target name
set(TARGET_NAME basic_triangle_rendering)

# Add source files
file(GLOB SOURCES "*.cpp")

# Create executable target
add_executable(${TARGET_NAME} ${SOURCES})

# Link GLFW
target_link_libraries(${TARGET_NAME} glfw)

# Include Glad directory
target_include_directories(${TARGET_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/external/glad)

# Link Glad (add glad.c to sources)
target_sources(${TARGET_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/external/glad/glad.c)

# Include common directory for shared utilities
target_include_directories(${TARGET_NAME} PRIVATE ../common)
