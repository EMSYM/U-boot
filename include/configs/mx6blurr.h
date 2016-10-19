/*
 * Copyright (C) 2012-2015 Freescale Semiconductor, Inc.
 *
 * Configuration settings for the Freescale i.MX6Q SabreAuto board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __MX6BLURR_CONFIG_H
#define __MX6BLURR_CONFIG_H

#ifndef CONFIG_CONSOLE_UART
#define CONFIG_CONSOLE_UART 1
#endif

#if CONFIG_CONSOLE_UART == 1
#define CONFIG_MXC_UART_BASE	UART1_BASE
#define CONFIG_CONSOLE_DEV		"ttymxc0"
#elif CONFIG_CONSOLE_UART == 4
#define CONFIG_MXC_UART_BASE UART4_BASE
#define CONFIG_CONSOLE_DEV		"ttymxc3"
#else
#error "DEBUG UART NOT SUPPORTED"
#endif

#define CONFIG_MMCROOT			"/dev/mmcblk2p2"  /* SDHC3 */
#if defined CONFIG_MX6QP
#define CONFIG_DEFAULT_FDT_FILE	"imx6qp-sabreauto.dtb"
#define PHYS_SDRAM_SIZE		(2u * 1024 * 1024 * 1024)
#elif defined CONFIG_MX6Q
#define CONFIG_DEFAULT_FDT_FILE	"imx6q-sabreauto.dtb"
#define PHYS_SDRAM_SIZE		(2u * 1024 * 1024 * 1024)
#elif defined(CONFIG_MX6DL)
#define CONFIG_DEFAULT_FDT_FILE	"imx6dl-sabreauto.dtb"
#define PHYS_SDRAM_SIZE		(1u * 1024 * 1024 * 1024)
#elif defined(CONFIG_MX6SOLO)
#define CONFIG_DEFAULT_FDT_FILE	"imx6dl-sabreauto.dtb"
#define PHYS_SDRAM_SIZE		(1u * 1024 * 1024 * 1024)
#endif

#define CONFIG_SYS_USE_NAND

#include "mx6sabre_common.h"
#include <asm/imx-common/gpio.h>

/*Since the pin conflicts on EIM D18, disable the USB host if the NOR flash is enabled */
#if !defined(CONFIG_SYS_USE_SPINOR) && !defined(CONFIG_SYS_USE_EIMNOR)
/* USB Configs */
#define CONFIG_CMD_USB
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_MX6
#define CONFIG_USB_STORAGE
#define CONFIG_USB_HOST_ETHER
#define CONFIG_USB_ETHER_ASIX
#define CONFIG_USB_MAX_CONTROLLER_COUNT 2
#define CONFIG_EHCI_HCD_INIT_AFTER_RESET	/* For OTG port */
#define CONFIG_MXC_USB_PORTSC	(PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_MXC_USB_FLAGS	0

/* MAX7310 configs */
#define CONFIG_MAX7310_IOEXP
#define CONFIG_IOEXP_DEVICES_NUM 3
#define CONFIG_IOEXP_DEV_PINS_NUM 8
#endif

#undef CONFIG_MFG_ENV_SETTINGS
#define CONFIG_MFG_ENV_SETTINGS "bootcmd_mfg=source 11000000\0" 

#undef CONFIG_MFG_NAND_PARTITION
#ifdef CONFIG_SYS_BOOT_NAND
#define CONFIG_MFG_NAND_PARTITION "mtdparts=8000000.nor:1m(boot),-(rootfs)\\\\;gpmi-nand:64m(boot),16m(kernel),16m(dtb),-(rootfs) "
#else
#define CONFIG_MFG_NAND_PARTITION ""
#endif

#ifdef CONFIG_SYS_USE_EIMNOR
#undef CONFIG_SYS_NO_FLASH
#define CONFIG_SYS_FLASH_BASE           WEIM_ARB_BASE_ADDR
#define CONFIG_SYS_FLASH_SECT_SIZE      (128 * 1024)
#define CONFIG_SYS_MAX_FLASH_BANKS 1    /* max number of memory banks */
#define CONFIG_SYS_MAX_FLASH_SECT 256   /* max number of sectors on one chip */
#define CONFIG_SYS_FLASH_CFI            /* Flash memory is CFI compliant */
#define CONFIG_FLASH_CFI_DRIVER         /* Use drivers/cfi_flash.c */
#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE /* Use buffered writes*/
#define CONFIG_SYS_FLASH_EMPTY_INFO
#endif

#define CONFIG_SYS_FSL_USDHC_NUM	2
#define CONFIG_SYS_MMC_ENV_DEV		1  /* SDHC3 */
#define CONFIG_SYS_MMC_ENV_PART                0       /* user partition */

#ifdef CONFIG_SYS_USE_SPINOR
#define CONFIG_SF_DEFAULT_CS   1
#endif
/* I2C Configs */
#define CONFIG_CMD_I2C
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_MXC
#define CONFIG_SYS_I2C_SPEED		100000

/* NAND flash command */
#define CONFIG_CMD_NAND
#define CONFIG_CMD_NAND_TRIMFFS
#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_RBTREE
#define CONFIG_LZO
#define CONFIG_CMD_UBI
#define CONFIG_CMD_UBIFS
#undef CONFIG_CMD_EXT2
#undef CONFIG_CMD_EXT4
#undef CONFIG_CMD_EXT4_WRITE

/* NAND stuff */
#define CONFIG_NAND_MXS
#define CONFIG_SYS_MAX_NAND_DEVICE     1
#define CONFIG_SYS_NAND_BASE           0x40000000
#define CONFIG_SYS_NAND_5_ADDR_CYCLE
#define CONFIG_SYS_NAND_ONFI_DETECTION

#ifdef CONFIG_ENV_IS_IN_NAND
#undef CONFIG_ENV_SECT_SIZE
#undef CONFIG_ENV_SIZE
#undef CONFIG_ENV_OFFSET
#ifndef CONFIG_NAND_SECT_SIZE
#define CONFIG_ENV_SECT_SIZE           (128 << 10)
#else 
#define CONFIG_ENV_SECT_SIZE CONFIG_NAND_SECT_SIZE
#endif
#define CONFIG_ENV_SIZE                CONFIG_ENV_SECT_SIZE
#define CONFIG_ENV_OFFSET              (15 * CONFIG_ENV_SECT_SIZE) /* mtd0 is 16 x sector */
#endif 

/* DMA stuff, needed for GPMI/MXS NAND support */
#define CONFIG_APBH_DMA
#define CONFIG_APBH_DMA_BURST
#define CONFIG_APBH_DMA_BURST8

/* PMIC */
#define CONFIG_POWER
#define CONFIG_POWER_I2C
#define CONFIG_POWER_PFUZE100
#define CONFIG_POWER_PFUZE100_I2C_ADDR	0x08

#define CONFIG_CMD_BMP
#define CONFIG_SPLASH_SCREEN
#endif                         /* __MX6BLURR_CONFIG_H */
