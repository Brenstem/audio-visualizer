cmake_minimum_required(VERSION 3.21)
project(renderEngine LANGUAGES CXX)

# Set the output directory based on the build configuration
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin-obj/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}")


# Define the source files for the renderEngine project
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")

# Set the compiler options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



# Add the renderEngine executable target
add_executable(renderEngine ${SOURCE_FILES} ${HEADER_FILES})

# Set the include directories
target_include_directories(renderEngine PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/external/glfw-3.3.8.bin.WIN64/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/external/glm-master"
    "C:/VulkanSDK/1.3.250.1/Include"
)

# Set the library directories
target_link_directories(renderEngine PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/external/glfw-3.3.8.bin.WIN64/lib-vc2022"
    "C:/VulkanSDK/1.3.250.1/Lib"
)

#find_package(dxc CONFIG REQUIRED)

# Set the libraries to link against
target_link_libraries(renderEngine PRIVATE
    vulkan-1
    glfw3_mt
)

#target_compile_features(renderEngine PRIVATE cxx_std_20)

# Set the compiler flags
target_compile_options(renderEngine PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/MP>
)

# Set the build configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

# Set the debug configuration
if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(renderEngine PRIVATE DEBUG)
    target_compile_options(renderEngine PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/Zi>)
    target_compile_options(renderEngine PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/Od>)
    target_compile_options(renderEngine PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/Ob0>)
    target_compile_options(renderEngine PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/RTC1>)
    target_compile_options(renderEngine PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/D_DEBUG>)
    target_link_options(renderEngine PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/DEBUG>)
endif()

# Set the release configuration
if(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_definitions(renderEngine PRIVATE NDEBUG)
    target_compile_options(renderEngine PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/O2>)
    target_compile_options(renderEngine PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/Ob2>)
    target_compile_options(renderEngine PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/Oi>)
    target_link_options(renderEngine PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/DEBUG:NO>)
endif()

# Set the startup project
if (WIN32 AND MSVC)
    set(CMAKE_VS_STARTUP_PROJECT "renderEngine")
    # Specify the solution file location
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT renderEngine)
endif()