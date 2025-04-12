# VULKAN-PLAYGROUND (c) John J. Arroyo O. (2025) - MIT License
# cmake --preset windows-default
# cmake --build --preset debug

cmake_minimum_required(VERSION 3.21)

# PROJECT
project(VULKAN-PLAYGROUND CXX)
# Project language setting
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# LIBRARIES
include(FetchContent)
# GLFW 3.4
FetchContent_Declare(glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.4)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_VULKAN_STATIC OFF CACHE BOOL "" FORCE)
# GLM 1.0.1
FetchContent_Declare(glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 1.0.1)
# VULKAN 1.4.309.0
FetchContent_Declare(vulkan-headers
  GIT_REPOSITORY https://github.com/KhronosGroup/Vulkan-Headers.git
  GIT_TAG vulkan-sdk-1.4.309.0)

# DOWNLOAD
FetchContent_MakeAvailable(glfw glm vulkan-headers)
# Include libraries
find_package(Vulkan REQUIRED) # Vulkan SDK 1.4.309.0

# SOURCES
set(APP_SOURCES
  source/app/src/MyApp.cpp
  source/app/src/MyWindow.cpp
  source/app/src/MyGui.cpp
  source/app/src/Log.cpp)

set(COMMON_INCLUDE_DIRS
  ${CMAKE_SOURCE_DIR}/source/app/include)

set(EXECUTABLE_SOURCES
  Main.cpp
  ${APP_SOURCES})

# BUILD
add_executable(${PROJECT_NAME} ${EXECUTABLE_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${COMMON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glm Vulkan::Vulkan)