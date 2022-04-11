#include <zephyr.h>

#include <deca_device_api.h>
#include <dw3000.h>
#include <port.h>

void Sleep(uint32_t x)
{
	k_msleep(x);
}

void reset_DWIC(void)
{
	dw3000_spi_speed_slow();

	dwt_softreset();

	dw3000_spi_speed_fast();
}

void port_set_dw_ic_spi_slowrate(void)
{
	dw3000_spi_speed_slow();
}

void port_set_dw_ic_spi_fastrate(void)
{
	dw3000_spi_speed_fast();
}
