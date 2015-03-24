cmake_minimum_required(VERSION 2.8.4)
project(lidar-light)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -Wno-deprecated-register")

include (cmake/ChibiOS_2.6.7.cmake)
include (cmake/ugfx-2.1.cmake)

include_directories (${CHIBIOS_INCLUDE_DIRS} ${GFXLIB_INCLUDE_DIRS} )

set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/arm/main.c
    ${PROJECT_SOURCE_DIR}/arm/board.c
    ${PROJECT_SOURCE_DIR}/arm/syscalls.c)

add_subdirectory(arm)
