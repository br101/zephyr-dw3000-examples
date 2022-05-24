/*
 * Copyright (c) 2022 Bruno Randolf <br1@einfach.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>

#include <dw3000_hw.h>
#include "../examples_info/examples_defines.h"

extern example_ptr example_pointer;

void test_run_info(unsigned char *data)
{
    printk("%s\n", data);
}

void main(void)
{
	printk("DW3000 Examples on %s\n", CONFIG_BOARD);

	dw3000_hw_init();
	dw3000_hw_reset();

	build_examples();

	if (example_pointer != NULL) {
		example_pointer();
	} else {
		printk("NO EXAMPLE COMPILED IN\n");
	}
}
