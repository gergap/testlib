project(testlib C)
cmake_minimum_required(VERSION 2.8)

set(SOURCES testlib.c)

add_definitions(-DHAVE_CONFIG)

if(WIN32)
    if(exists ${CMAKE_SOURCE_DIR}/pthread-win32/getopt.c)
        # enable getopt support on Windows
        set(SOURCES ${SOURCES} ${CMAKE_SOURCE_DIR}/pthread-win32/getopt.c)
    endif()
endif()

if(ENABLE_BENCHMARK)
    set(SOURCES ${SOURCES} timer.c)
endif()

add_library(testlib ${SOURCES})


