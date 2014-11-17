project(testlib C)
cmake_minimum_required(VERSION 2.8)

option(ENABLE_COLOR "Enable terminal color support" ON)
option(ENABLE_HEXDUMP "Enable hexdump support" ON)
option(ENABLE_BENCHMARK "Enable benchmark support" ON)

# platform check
if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(ENABLE_COLOR OFF CACHE BOOL "Enable terminal color support" FORCE)
endif()

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    # we are adding some C99 stuff, that is still missing on Windows
    # Come on MS, it's 2014 and VS still only supports C89!!!
    include_directories(win32)
    # lets add also getopt() (POSIX)
    set(SOURCES ${SOURCES} win32/getopt.c)
    set(HEADERS ${HEADERS} win32/getopt.h)
    set(HAVE_GETOPT 1)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else ()
    # check if we have getopt.h
    include(CheckIncludeFile)
    CHECK_INCLUDE_FILE("getopt.h" HAVE_GETOPT)
endif ()

# create test_config.h
configure_file(
    ${PROJECT_SOURCE_DIR}/test_config.h.in
    ${PROJECT_BINARY_DIR}/test_config.h)
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(HEADERS ${HEADERS} ${PROJECT_BINARY_DIR}/test_config.h)
endif ()
# add current source and binary dir to include paths
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES ${SOURCES} testlib.c)
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(HEADERS ${HEADERS} testlib.h)
endif ()

if (ENABLE_BENCHMARK)
    set(SOURCES ${SOURCES} timer.c)
    if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        set(HEADERS ${HEADERS} timer.h)
    endif ()
endif ()

add_library(testlib ${SOURCES} ${HEADERS})


