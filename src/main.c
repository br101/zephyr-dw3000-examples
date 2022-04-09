/*
 * Copyright (c) 2022 Bruno Randolf <br1@einfach.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>

#include "../examples_info/examples_defines.h"

extern example_ptr example_pointer;

void test_run_info(unsigned char *data)
{
    printk("%s\n", data);
}

void main(void)
{
	printk("DW3000 Examples on %s\n", CONFIG_BOARD);

	build_examples();
	example_pointer();
}
