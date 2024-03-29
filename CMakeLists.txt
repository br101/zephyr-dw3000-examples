# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

# add the dw3000-decadriver directory as a zephyr module by hand, not needed when using west
list(APPEND ZEPHYR_EXTRA_MODULES ${CMAKE_CURRENT_SOURCE_DIR}/dw3000-decadriver/)

#set(SHIELD qorvo_dws3000)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(dw3000-examples)

# the binary only library from Qorvo has problems with -Os or -O2
zephyr_library_compile_options(-O1)

## example selection (select one of below) by calling cmake -DEXAMPLE=NAME
## or by uncommenting ONE add_definitions() below
if (DEFINED EXAMPLE)
	add_definitions(-DTEST_${EXAMPLE})
else()
	add_definitions(-DTEST_READING_DEV_ID)
endif()

#add_definitions(-DTEST_READING_DEV_ID)
#add_definitions(-DTEST_SIMPLE_TX)
#add_definitions(-DTEST_SIMPLE_TX_PDOA)
#add_definitions(-DTEST_SIMPLE_RX)
#add_definitions(-DTEST_RX_SNIFF)
#add_definitions(-DTEST_RX_TRIM)
#add_definitions(-DTEST_RX_DIAG)
#add_definitions(-DTEST_TX_SLEEP)
#add_definitions(-DTEST_TX_SLEEP_IDLE_RC)
#add_definitions(-DTEST_TX_SLEEP_TIMED)
#add_definitions(-DTEST_TX_SLEEP_AUTO)
#add_definitions(-DTEST_TX_WITH_CCA)
#add_definitions(-DTEST_SIMPLE_TX_AES)
#add_definitions(-DTEST_SIMPLE_RX_AES)
#add_definitions(-DTEST_TX_WAIT_RESP)
#add_definitions(-DTEST_TX_WAIT_RESP_INT)
#add_definitions(-DTEST_RX_SEND_RESP)
#add_definitions(-DTEST_SS_TWR_RESPONDER)
#add_definitions(-DTEST_SS_TWR_INITIATOR)
#add_definitions(-DTEST_SS_TWR_INITIATOR_STS)
#add_definitions(-DTEST_SS_TWR_RESPONDER_STS)
#add_definitions(-DTEST_SS_TWR_INITIATOR_STS_NO_DATA)
#add_definitions(-DTEST_SS_TWR_RESPONDER_STS_NO_DATA)
#(broken) add_definitions(-DTX_RX_AES_VERIFICATION)
#add_definitions(-DTEST_AES_SS_TWR_INITIATOR)
#add_definitions(-DTEST_AES_SS_TWR_RESPONDER)
#add_definitions(-DTEST_DS_TWR_INITIATOR)
#add_definitions(-DTEST_DS_TWR_RESPONDER)
#add_definitions(-DTEST_DS_TWR_RESPONDER_STS)
#add_definitions(-DTEST_DS_TWR_INITIATOR_STS)
#add_definitions(-DTEST_DS_TWR_STS_SDC_INITIATOR)
#add_definitions(-DTEST_DS_TWR_STS_SDC_RESPONDER)
#add_definitions(-DTEST_CONTINUOUS_WAVE)
#add_definitions(-DTEST_CONTINUOUS_FRAME)
#add_definitions(-DTEST_ACK_DATA_RX)
#add_definitions(-DTEST_ACK_DATA_TX)
#add_definitions(-DTEST_GPIO)
#add_definitions(-DTEST_SIMPLE_TX_STS_SDC)
#add_definitions(-DTEST_SIMPLE_RX_STS_SDC)
#(broken) add_definitions(-DTEST_FRAME_FILTERING_TX)
#(broken) add_definitions(-DTEST_FRAME_FILTERING_RX)
#add_definitions(-DTEST_ACK_DATA_RX_DBL_BUFF)
#add_definitions(-DTEST_SPI_CRC)
#add_definitions(-DTEST_SIMPLE_RX_PDOA)
#add_definitions(-DTEST_OTP_WRITE)
#add_definitions(-DTEST_LE_PEND_TX)
#add_definitions(-DTEST_LE_PEND_RX)

target_sources(app PRIVATE src/main.c)

target_sources(app PRIVATE platform/port.c platform/config_options.c)
target_sources(app PRIVATE MAC_802_15_8/mac_802_15_8.c)
target_sources(app PRIVATE MAC_802_15_4/mac_802_15_4.c)

FILE(GLOB ex_sources examples/*/*.c)
target_sources(app PRIVATE ${ex_sources})

target_include_directories(app PRIVATE platform)
target_include_directories(app PRIVATE examples/shared_data)
target_include_directories(app PRIVATE MAC_802_15_8)
target_include_directories(app PRIVATE MAC_802_15_4)
