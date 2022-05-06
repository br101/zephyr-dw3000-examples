#include <zephyr.h>

#include <deca_device_api.h>
#include <dw3000.h>
#include <port.h>

int reset_semaphore;

void Sleep(uint32_t x)
{
	k_msleep(x);
}

void reset_DWIC(void)
{
#if 1
	dw3000_hw_reset();
#else
	dw3000_spi_speed_slow();
	dwt_softreset(reset_semaphore);
	dw3000_spi_speed_fast();
#endif
}

void port_set_dw_ic_spi_slowrate(void)
{
	dw3000_spi_speed_slow();
}

void port_set_dw_ic_spi_fastrate(void)
{
	dw3000_spi_speed_fast();
}

void port_set_dwic_isr(port_deca_isr_t deca_isr)
{
	dw3000_init_interrupt();
}
