/*! ----------------------------------------------------------------------------
 *  @file    spi_crc.c
 *  @brief   This example demonstrates how SPI CRC mode should be used in DW3000. When enabled the SPI CRC mode will
 *  trigger a SPI write error interrupt event in the status register if the DW3000's own CRC generated on the transaction
 *  data does not match the CRC byte sent from the host.
 *
 * @attention
 *
 * Copyright 2018 - 2020 (c) Decawave Ltd, Dublin, Ireland.
 *
 * All rights reserved.
 *
 * @author Decawave
 */

#include <deca_device_api.h>
#include <deca_regs.h>
#include <deca_spi.h>
#include <port.h>
#include <shared_defines.h>
#include <example_selection.h>


#if defined(TEST_SPI_CRC)

extern void test_run_info(unsigned char *data);

/* Example application name and version to display on LCD screen. */
#define APP_NAME "SPI CRC EX"


/* Declaration of SPI read error callback, will be called if SPI read error is detected in  dwt_readfromdevice() function*/
static void spi_rd_err_cb(void);

/**
 * Application entry point.
 */

int spi_crc(void)
{
    /* Hold copy of status register state here for reference so that it can be examined at a debug breakpoint. */
    uint32_t status_reg,reg_val;
    uint32_t data = 0x11223344; /* Some random data to write into the TX_BUFFER register*/
    uint8_t  cnt = 0;
    uint32_t reg_addr;

    /* Display application name on LCD. */
    test_run_info((unsigned char *)APP_NAME);

    /* Configure SPI rate, DW3000 supports up to 38 MHz */

    port_set_dw_ic_spi_slowrate(); // NOTE: the max SPI rate is 20 MHz when using SPI CRC mode

    /* Reset DW IC */
    reset_DWIC(); /* Target specific drive of RSTn line into DW IC low for a period. */

    Sleep(2); // Time needed for DW3000 to start up (transition from INIT_RC to IDLE_RC

    while (!dwt_checkidlerc()) /* Need to make sure DW IC is in IDLE_RC before proceeding */
    { };
    if (dwt_initialise(DWT_DW_IDLE) == DWT_ERROR)
    {
        test_run_info((unsigned char *)"INIT FAILED");
        while (1)
        { };
    }

    /* see NOTE 1. */

    /* dwt_enablespicrccheck will enable SPI CRC check in DW3000 */
    dwt_enablespicrccheck(DWT_SPI_CRC_MODE_WRRD, &spi_rd_err_cb);



    /* Clear SPI CRC error event in the DW IC status register. It will be set on initialisation of DW3000 as CRC check is not enabled by default*/
    /* This is the 1st SPI write operation after configuring the SPI CRC check, and will have the CRC byte appended */
    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_SPICRCE_BIT_MASK);

    /* The $$$ code below is not needed when SPI CRC callback function is used in dwt_setcallbacks */

    /* $$$$$$$$$$$$ this code is used when polling status register $$$$$$$$$$$$$$ */
    /* Poll the STATUS register to check that SPI CRC error bit is clear. See Note 2. */
    if((status_reg = dwt_read8bitoffsetreg(SYS_STATUS_ID, 0)) & (SYS_STATUS_SPICRCE_BIT_MASK))
    {
        while(1);
    }
    /* $$$$$$$$$$$$ end of $$$$$$$$$$$$$$ */


    /* loop forever doing SPI writes and reads and STOP if error */
    while(1)
    {
        if (!cnt)
        {
            reg_addr=AES_IV0_ID;/*Regs AES_IV0 to AES_IV3 are one after another (addresses)*/
            data++;
        }
        else
        {
            reg_addr+=4;
        }
        cnt=(cnt+1)%4;

        /* write data to some regs and check if got CRC error. CRC will automatically appended in the dwt_writetodevice() function */
        dwt_write32bitoffsetreg(reg_addr, 0, data);
        reg_val=dwt_read32bitoffsetreg(reg_addr,0);

        /* if SPI error detected STOP */
        if (((status_reg = dwt_read8bitoffsetreg(SYS_STATUS_ID, 0)) & (SYS_STATUS_SPICRCE_BIT_MASK))||(reg_val!=data))
        {
            while(1);
            /* The recommended recovery from a write CRC error is to reset the DW3000 completely,
             * reinitialising and reconfiguring it into the desired operating mode for the application.
             */
        }
        Sleep(200);
    }
}

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn spi_rd_err_cb()
 *
 * @brief Callback to process SPI read error events
 *
 * @return  none
 */
static void spi_rd_err_cb(void)
{
    while(1);
    /* see Note 3 below */
}

#endif
/*****************************************************************************************************************************************************
 * NOTES:
 *
 * 1. When enabling the SPI CRC mode, the following sequence should be applied:
 *    a. call dwt_enablespicrccheck to enable the SPI CRC
 *    b. clear the SYS_STATUS_SPICRC bit in the status register (as this was set previously (e.g. on DW3000 power on) because CRC SPI was off)
 *    c. configure SPI CRC error interrupt callback with dwt_setcallbacks
 * 2. We use polled mode of operation here to keep the example as simple as possible, but the SYS_STATUS_SPICRC status event can be used to
 *    generate an interrupt. Please refer to DW3000 User Manual for more details on "interrupts".
 * 3. We call the spi_rd_err_cb as a result of reading the SPICRC_CFG_ID register. As long as the callback does not read SPICRC_CFG_ID register
 *    again there is no recursion issue, the host should reset device and exit this or raise some other error
 ****************************************************************************************************************************************************/
