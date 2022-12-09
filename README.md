# Qorvo/Decawave DW3000 Examples for Zephyr

This is a port of the examples of the Qorvo/Decawave DWS3000_Release_v1.1 for Zephyr.

It uses the Zephyr DW3000 driver from https://github.com/br101/zephyr-dw3000-decadriver 
as a git submodule and otherwise tries to make the least amount of changes to the examples
from the original code (the rationale is that they will be updated).


As in https://github.com/br101/zephyr-dw3000-decadriver, there are two branches:

* The 'master' branch uses the last release from Qorvo (DW3xxx_XR6.0C_24Feb2022.zip), which
unfortunately uses the binary-only library for the driver.

* There is an 'opensource' branch which uses the code from the last open source release from Qorvo 
(DWS3000_Release_v1.1 / DW3000_API_C0_rev4p0), but this is older and not well tested any more.

The example to be executed can be selected by passing a variable to cmake, e.g.:
```
cmake -B build -DBOARD_ROOT=. -DBOARD=minew_ms151f7 -DEXAMPLE=EXAMPLE_NAME  .
```

Or by modifying CMakeLists.txt and uncommenting one of the definitions:

```
add_definitions(-DTEST_READING_DEV_ID)
```

## Available examples


| Example NAME					| Directory					| Status	 |
|-------------------------------|---------------------------|------------|
| READING_DEV_ID				| ex_00a_reading_dev_id		| Run tested |
| SIMPLE_TX						| ex_01a_simple_tx			| Run tested |
| SIMPLE_TX_PDOA				| ex_01h_simple_tx_pdoa 	| Compile tested |
| SIMPLE_RX 					| ex_02a_simple_rx			| Run tested |
| RX_SNIFF						| ex_02d_rx_sniff			| Compile tested |
| RX_TRIM						| ex_02f_rx_with_crystal_trim | Compile tested |
| RX_DIAG						| ex_02c_rx_diagnostics		| Compile tested |
| TX_SLEEP						| ex_01b_tx_sleep			| Compile tested |
| TX_SLEEP_IDLE_RC				| ex_01b_tx_sleep			| Compile tested |
| TX_SLEEP_TIMED				| ex_01d_tx_timed_sleep		| Compile tested |
| TX_SLEEP_AUTO					| ex_01c_tx_sleep_auto		| Compile tested |
| TX_WITH_CCA					| ex_01e_tx_with_cca		| Compile tested |
| SIMPLE_TX_AES					| ex_01i_simple_tx_aes		| Compile tested |
| SIMPLE_RX_AES					| ex_02i_simple_rx_aes		| Compile tested |
| TX_WAIT_RESP					| ex_03a_tx_wait_resp		| Compile tested |
| TX_WAIT_RESP_INT				| ex_03d_tx_wait_resp_interrupts | Compile tested |
| RX_SEND_RESP					| ex_03b_rx_send_resp		| Compile tested |
| SS_TWR_RESPONDER				| ex_06b_ss_twr_responder	| Compile tested |
| SS_TWR_INITIATOR				| ex_06a_ss_twr_initiator	| Compile tested |
| SS_TWR_INITIATOR_STS			| ex_06a_ss_twr_initiator	| Compile tested |
| SS_TWR_RESPONDER_STS			| ex_06b_ss_twr_responder	| Compile tested |
| SS_TWR_INITIATOR_STS_NO_DATA	| ex_06a_ss_twr_initiator	| Compile tested |
| SS_TWR_RESPONDER_STS_NO_DATA	| ex_06b_ss_twr_responder	| Compile tested |
| AES_SS_TWR_INITIATOR			| ex_06e_AES_ss_twr_initiator | Compile tested |
| AES_SS_TWR_RESPONDER			| ex_06f_AES_ss_twr_responder | Compile tested |
| DS_TWR_INITIATOR				| ex_05a_ds_twr_init		| Compile tested |
| DS_TWR_RESPONDER				| ex_05b_ds_twr_resp 		| Compile tested |
| DS_TWR_RESPONDER_STS			| ex_05b_ds_twr_resp		| Compile tested |
| DS_TWR_INITIATOR_STS			| ex_05a_ds_twr_init 		| Compile tested |
| DS_TWR_STS_SDC_INITIATOR		| ex_05c_ds_twr_init_sts_sdc | Compile tested |
| DS_TWR_STS_SDC_RESPONDER		| ex_05d_ds_twr_resp_sts_sdc | Compile tested |
| CONTINUOUS_WAVE				| ex_04a_cont_wave    		| Compile tested |
| CONTINUOUS_FRAME				| ex_04b_cont_frame 		| Compile tested |
| ACK_DATA_RX					| ex_07b_ack_data_rx 		| Compile tested |
| ACK_DATA_TX					| ex_07a_ack_data_tx 		| Compile tested |
| GPIO							| ex_13a_gpio 				| Compile tested |
| SIMPLE_TX_STS_SDC				| ex_01g_simple_tx_sts_sdc	| Compile tested |
| SIMPLE_RX_STS_SDC				| ex_01g_simple_tx_sts_sdc	| Compile tested |
| ACK_DATA_RX_DBL_BUFF			| ex_07c_ack_data_rx_dbl_buff | Compile tested |
| SPI_CRC						| ex_11a_spi_crc			| Compile tested |
| SIMPLE_RX_PDOA				| ex_02h_simple_rx_pdoa		| Run tested |
| OTP_WRITE						| ex_14_otp_write			| Compile tested |
| LE_PEND_TX					| ex_15_le_pend				| Compile tested |
| LE_PEND_RX					| ex_15_le_pend				| Compile tested |

Defined, but not available in source: TX_RX_AES_VERIFICATION, FRAME_FILTERING_TX, FRAME_FILTERING_RX
