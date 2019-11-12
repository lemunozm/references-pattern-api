cmake_minimum_required(VERSION 3.5.0 FATAL_ERROR)

project(refapi
    VERSION "0.1.0"
    LANGUAGES CXX
    )

include(GNUInstallDirs)

option(BUILD_EXAMPLES "Build examples." OFF)

#####################################################################################
#                                    Library
#####################################################################################
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    )

target_compile_features(${PROJECT_NAME}
    INTERFACE
        cxx_std_11
    )

#####################################################################################
#                                    Example
#####################################################################################
set(EXAMPLE_NAME ${PROJECT_NAME}-example)

add_executable(${EXAMPLE_NAME} example/main.cpp)

target_link_libraries(${EXAMPLE_NAME}
    PRIVATE
        ${PROJECT_NAME}
    )

target_compile_options(${EXAMPLE_NAME}
    INTERFACE
        $<$<CXX_COMPILER_ID:GNU>:-Wall>
        $<$<CXX_COMPILER_ID:GNU>:-Wextra>
    )

set_target_properties(${EXAMPLE_NAME}
    PROPERTIES
        CXX_STANDARD 11
    )


#####################################################################################
#                                   Installation
#####################################################################################
install(
    DIRECTORY
        ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/
    DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    FILES_MATCHING
        PATTERN "*.hpp"
    )

install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        ${PROJECT_NAME}_Targets
    RUNTIME DESTINATION
        ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION
        ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION
        ${CMAKE_INSTALL_LIBDIR}
    )

install(
    EXPORT
        ${PROJECT_NAME}_Targets
    DESTINATION
        ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}/cmake
    )

