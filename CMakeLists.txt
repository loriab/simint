cmake_policy(SET CMP0048 NEW)  # project_VERSION* variables populated from project(... VERSION x.x.x) string
project(simint
        VERSION 0.7
        LANGUAGES C CXX)
set(simint_AUTHORS      "Benjamin P. Pritchard")
set(simint_DESCRIPTION  "Vectorized implementation of Obara-Saika Method toward Electron Repulsion Integrals")
set(simint_URL          "http://www.bennyp.org/research/simint/")
set(simint_LICENSE      "BSD 3-clause")

cmake_minimum_required(VERSION 3.0.2)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

##################################################
# Flags passed in
##################################################
set(SIMINT_VECTOR  "" CACHE BOOL "Type of vectorization to use")

option(BUILD_SHARED_LIBS "Build final library as shared, not static" OFF)
option(BUILD_FPIC "Libraries will be compiled with position independent code" ON)
if(${BUILD_SHARED_LIBS} AND NOT ${BUILD_FPIC})
    message(FATAL_ERROR "BUILD_SHARED_LIBS ON and BUILD_FPIC OFF are incompatible, as shared library requires position independent code")
endif()
option(ENABLE_GENERIC "Enable mostly static linking in shared library" OFF)
option(ENABLE_TESTS "Enable simint unit tests" ON)

##################################################
# Basic options for simint
##################################################
list(APPEND SIMINT_C_INCLUDES "${CMAKE_SOURCE_DIR}")
list(APPEND SIMINT_C_INCLUDES "${CMAKE_BINARY_DIR}/stage") # some CMake-generated files go here

# Default to "Release"
if("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(CMAKE_BUILD_TYPE "Release")
endif()

##################################################
# Read the default flags and generated flags file
##################################################
include(cmake/DefaultFlags.cmake)

message(STATUS "    SIMINT_C_INCLUDES: ${SIMINT_C_INCLUDES}")
message(STATUS "       SIMINT_C_FLAGS: ${SIMINT_C_FLAGS}")
message(STATUS "  SIMINT_C_LINK_FLAGS: ${SIMINT_C_LINK_FLAGS}")

# Configure & install the vector_config header
configure_file("simint/vectorization/vector_config.h.in"
               "${CMAKE_BINARY_DIR}/stage/simint/vectorization/vector_config.h"
               @ONLY)

foreach(def ${SIMINT_CONFIG_DEFINES})
  file(APPEND "${CMAKE_BINARY_DIR}/stage/simint/vectorization/vector_config.h"
              "#define ${def}\n")
endforeach()

install(FILES ${CMAKE_BINARY_DIR}/stage/simint/vectorization/vector_config.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/simint/vectorization)

# <<<  Export Config  >>>
include(GNUInstallDirs)
include(custom_static_library)
include(CMakePackageConfigHelpers)

set(PN ${PROJECT_NAME})

    # GNUInstallDirs "DATADIR" wrong here; CMake search path wants "share".
set(CMAKECONFIG_INSTALL_DIR "share/cmake/${PN}")

configure_package_config_file(cmake/${PN}Config.cmake.in
                              "${CMAKE_CURRENT_BINARY_DIR}/${PN}Config.cmake"
                              INSTALL_DESTINATION ${CMAKECONFIG_INSTALL_DIR})
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PN}ConfigVersion.cmake
                                 VERSION ${${PN}_VERSION}
                                 COMPATIBILITY AnyNewerVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PN}Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/${PN}ConfigVersion.cmake
        DESTINATION ${CMAKECONFIG_INSTALL_DIR})
install(EXPORT "${PN}Targets"
        NAMESPACE "${PN}::"
        DESTINATION ${CMAKECONFIG_INSTALL_DIR})

# Main code subdirectory
add_subdirectory(simint)

# Make the test executables
if(ENABLE_TESTS)
    add_subdirectory(test)
endif()

# Build examples
add_subdirectory(examples)

# Note: Building tests with shared library requires -liomp5 or -lgomp
#   added to CMAKE_CXX_FLAGS
