# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Specify the project name
project(rendererSolution)

# Specify the output directory for built binaries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Specify the location where the dependencies will be downloaded and built
set(DEPENDENCIES_DIR ${CMAKE_SOURCE_DIR}/dependencies)

# GLFW dependency configuration
set(GLFW_REPO "https://github.com/glfw/glfw")
set(GLFW_COMMIT "3fa2360720eeba1964df3c0ecf4b5df8648a8e52")

# Clone the GLFW repository and configure its build
include(ExternalProject)
ExternalProject_Add(
   glfw
   PREFIX ${DEPENDENCIES_DIR}/glfw
   GIT_REPOSITORY ${GLFW_REPO}
   GIT_TAG ${GLFW_COMMIT}
   CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${DEPENDENCIES_DIR}/glfw-install
)

# Specify the include directories for GLFW
include_directories(${DEPENDENCIES_DIR}/glfw-install/include)

# Your main graphics renderer project
add_executable(rendererSolution main.cpp)

# Additional configurations, compile options, etc.
# ...

# Add dependency on GLFW (ensure it is built before rendererSolution)
add_dependencies(rendererSolution glfw)

# Link against GLFW library
target_link_libraries(rendererSolution ${DEPENDENCIES_DIR}/glfw-install/lib/${CMAKE_STATIC_LIBRARY_PREFIX}glfw3${CMAKE_STATIC_LIBRARY_SUFFIX})

# Find the Vulkan package
find_package(Vulkan REQUIRED)

# Include Vulkan headers
include_directories(${Vulkan_INCLUDE_DIRS})

# Link against Vulkan libraries
target_link_libraries(rendererSolution ${Vulkan_LIBRARIES})