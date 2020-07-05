cmake_minimum_required(VERSION 3.1)

# Enable MSVC_RUNTIME_LIBRARY target property
# https://cmake.org/cmake/help/latest/policy/CMP0091.html
if(POLICY CMP0091)
	cmake_policy(SET CMP0091 NEW)
endif()

project(FontMod)

include_external_msproject(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.vcxproj)

set(YAML_CPP_BUILD_CONTRIB OFF CACHE BOOL "Enable yaml-cpp contrib in library")
set(YAML_CPP_BUILD_TOOLS OFF CACHE BOOL "Enable parse tools")
set(YAML_CPP_BUILD_TESTS OFF CACHE BOOL "Enable yaml-cpp tests")
set(YAML_CPP_INSTALL OFF CACHE BOOL "Enable generation of yaml-cpp install targets")
set(YAML_MSVC_SHARED_RT OFF CACHE BOOL "MSVC: Build yaml-cpp with shared runtime libs (/MD)")
add_subdirectory("yaml-cpp")

include(detours.cmake)

add_dependencies(${PROJECT_NAME} "yaml-cpp" "detours")
