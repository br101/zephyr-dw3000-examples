/*! ----------------------------------------------------------------------------
 * @file    port.h
 * @brief   HW specific definitions and functions for portability
 *
 * @attention
 *
 * Copyright 2015-2020 (c) DecaWave Ltd, Dublin, Ireland.
 *
 * All rights reserved.
 *
 * @author DecaWave
 */

#ifndef PORT_H_
#define PORT_H_

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

// this define is used in some examples, should depend on board
#define NRF52840_XXAA

void Sleep(uint32_t Delay);
void reset_DWIC(void);
void port_set_dw_ic_spi_slowrate(void);
void port_set_dw_ic_spi_fastrate(void);

#endif /* PORT_H_ */
