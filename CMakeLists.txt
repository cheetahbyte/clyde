cmake_minimum_required(VERSION 3.20)

project(clyde)
set (CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
include(FetchContent)

FetchContent_Declare(
  cpptoml
  GIT_REPOSITORY https://github.com/skystrife/cpptoml.git
  GIT_TAG        master  # You can specify a specific commit or tag here
)

FetchContent_MakeAvailable(cpptoml)

add_executable(${PROJECT_NAME} "${MY_SOURCES}")

target_link_libraries(${PROJECT_NAME} PRIVATE cpptoml)