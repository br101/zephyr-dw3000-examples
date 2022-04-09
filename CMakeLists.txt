# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

# add the dw3000-decadriver directory as a zephyr module by hand, not needed when using west
list(APPEND ZEPHYR_EXTRA_MODULES ${CMAKE_CURRENT_SOURCE_DIR}/dw3000-decadriver/)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(dw3000-examples)

target_sources(app PRIVATE src/main.c)

add_definitions(-DTEST_READING_DEV_ID)

FILE(GLOB ex_sources examples/*/*.c)
target_sources(app PRIVATE ${ex_sources})
