cmake_minimum_required(VERSION 3.1)

project(FontMod)

include_external_msproject(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.vcxproj)

set(YAML_CPP_BUILD_TESTS OFF CACHE BOOL "Enable testing")
set(YAML_CPP_BUILD_TOOLS OFF CACHE BOOL "Enable parse tools")
set(YAML_CPP_BUILD_CONTRIB OFF CACHE BOOL "Enable contrib stuff in library")
set(YAML_CPP_INSTALL OFF CACHE BOOL "Enable generation of install target")
set(MSVC_SHARED_RT OFF CACHE BOOL "MSVC: Build with shared runtime libs (/MD)")
add_subdirectory("yaml-cpp")

add_dependencies(${PROJECT_NAME} "yaml-cpp")
