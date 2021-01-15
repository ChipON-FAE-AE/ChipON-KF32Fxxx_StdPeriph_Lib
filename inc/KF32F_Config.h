/**
  *********************************************************************
  * 文件名 KF32F_Config.h
  * 作  者  ChipON_AE/FAE_Group
  * 版  本  V2.3
  * 日  期  2019-11-16
  * 描  述  KF32F系列外设配置
  *
  *********************************************************************
  */

#ifndef _KF32F_Config_H_
#define _KF32F_Config_H_

/* 型号定义 */
#ifdef KF32F350KQT
	#define KF32F350
#elif defined KF32F350MQT
    #define KF32F350
#elif defined KF32F350MQV
	#define KF32F350
#elif defined KF32F350KQV
	#define KF32F350
#endif

#ifdef KF32F351KQT
	#define KF32F351
#elif defined KF32F351MQT
    #define KF32F351
#endif

#ifdef KF32F130GNP
	#define KF32F130
#elif defined KF32F130INP
    #define KF32F130
#endif

#ifdef KF32F351
    /* ADC */
	#define KF32F_Periph_adc
	#define KF32F_Periph_adc0
	#define KF32F_Periph_adc1
	#define KF32F_Periph_adc2
 	/* AES */
	#define KF32F_Periph_aes
	/* CAN */
	#define KF32F_Periph_can
    #define KF32F_Periph_can0
    /* CFGL */
    #define KF32F_Periph_cfgl
    /* CMP */
	#define KF32F_Periph_cmp
    /* OP */
	#define KF32F_Periph_cmp
	/* CRC */
	#define KF32F_Periph_crc
	/* DAC */
	#define KF32F_Periph_dac
	#define KF32F_Periph_dac0
	#define KF32F_Periph_dac1
	/* DMA */
	#define KF32F_Periph_dma
	#define KF32F_Periph_dma0
	#define KF32F_Periph_dma1
	/* EXIC */
	#define KF32F_Periph_exic
	/* I2C */
    #define KF32F_Periph_i2c
    #define KF32F_Periph_i2c0
	#define KF32F_Periph_i2c1
	#define KF32F_Periph_i2c2
	/* QEI */
	#define KF32F_Periph_qei
	#define KF32F_Periph_qei0
	#define KF32F_Periph_qei1
	/* SPI */
	#define KF32F_Periph_spi
	#define KF32F_Periph_spi0
	#define KF32F_Periph_spi1
	#define KF32F_Periph_spi2
    /* USART */
	#define KF32F_Periph_usart
	#define KF32F_Periph_usart0
	#define KF32F_Periph_usart1
	#define KF32F_Periph_usart2
	#define KF32F_Periph_usart3
	#define KF32F_Periph_usart4
	#define KF32F_Periph_usart5
	#define KF32F_Periph_usart6
	#define KF32F_Periph_usart7
    /* USB */
	#define KF32F_Periph_usb
	/* BTIME */
	#define KF32F_Periph_btime14
	#define KF32F_Periph_btime15
	/* GPTIME */
	#define KF32F_Periph_gptime0
	#define KF32F_Periph_gptime1
	#define KF32F_Periph_gptime2
	#define KF32F_Periph_gptime3
	#define KF32F_Periph_gptime4
	#define KF32F_Periph_gptime18
	#define KF32F_Periph_gptime19
	#define KF32F_Periph_gptime20
	#define KF32F_Periph_gptime21
	#define KF32F_Periph_gptime22_time23
	#define KF32F_Periph_gptime22
	#define KF32F_Periph_gptime23
	/* ATIME */
	#define KF32F_Periph_atime5_time6
	#define KF32F_Periph_atime5
	#define KF32F_Periph_atime6

	#define KF32F_Periph_atime9_time10
	#define KF32F_Periph_atime9
	#define KF32F_Periph_atime10
#endif

#ifdef  KF32F130
    /* ADC */
	#define KF32F_Periph_adc
	#define KF32F_Periph_adc0
 	/* AES */
	#define KF32F_Periph_aes
	/* CAN */
	#define KF32F_Periph_can
    #define KF32F_Periph_can0
    /* CFGL */
    #define KF32F_Periph_cfgl
	/* CRC */
	#define KF32F_Periph_crc
	/* DAC */
	#define KF32F_Periph_dac
	#define KF32F_Periph_dac0
	#define KF32F_Periph_dac1
	/* DMA */
	#define KF32F_Periph_dma
	#define KF32F_Periph_dma0
	#define KF32F_Periph_dma1
	/* I2C */
    #define KF32F_Periph_i2c
    #define KF32F_Periph_i2c0
	#define KF32F_Periph_i2c1
	/* QEI */
	#define KF32F_Periph_qei
	#define KF32F_Periph_qei0
	/* SPI */
	#define KF32F_Periph_spi
	#define KF32F_Periph_spi0
	#define KF32F_Periph_spi3
    /* USART */
	#define KF32F_Periph_usart
	#define KF32F_Periph_usart0
	#define KF32F_Periph_usart1
	/* BTIME */
	#define KF32F_Periph_btime14
	#define KF32F_Periph_btime15
	/* GPTIME */
	#define KF32F_Periph_gptime0
	#define KF32F_Periph_gptime1
	#define KF32F_Periph_gptime3
	#define KF32F_Periph_gptime4
	#define KF32F_Periph_gptime20
	/* ATIME */
	#define KF32F_Periph_atime5_time6
	#define KF32F_Periph_atime5
	#define KF32F_Periph_atime6
#endif //KF32F130

#ifdef KF32F350
    /* ADC */
	#define KF32F_Periph_adc
	#define KF32F_Periph_adc0
	#define KF32F_Periph_adc1
	#define KF32F_Periph_adc2
 	/* AES */
	#define KF32F_Periph_aes
	/* CAN */
	#define KF32F_Periph_can
    #define KF32F_Periph_can0
    #define KF32F_Periph_can1
	#define KF32F_Periph_can2
    /* CFGL */
    #define KF32F_Periph_cfgl
	/* CRC */
	#define KF32F_Periph_crc
	/* DAC */
	#define KF32F_Periph_dac
	#define KF32F_Periph_dac0
	#define KF32F_Periph_dac1
	/* DMA */
	#define KF32F_Periph_dma
	#define KF32F_Periph_dma0
	#define KF32F_Periph_dma1
	/* EXIC */
	#define KF32F_Periph_exic
	/* I2C */
    #define KF32F_Periph_i2c
    #define KF32F_Periph_i2c0
	#define KF32F_Periph_i2c1
	#define KF32F_Periph_i2c2
	#define KF32F_Periph_i2c3
	/* QEI */
	#define KF32F_Periph_qei
	#define KF32F_Periph_qei0
	#define KF32F_Periph_qei1
	/* SPI */
	#define KF32F_Periph_spi
	#define KF32F_Periph_spi0
	#define KF32F_Periph_spi1
	#define KF32F_Periph_spi2
	#define KF32F_Periph_spi3
    /* USART */
	#define KF32F_Periph_usart
	#define KF32F_Periph_usart0
	#define KF32F_Periph_usart1
	#define KF32F_Periph_usart2
	#define KF32F_Periph_usart3
	#define KF32F_Periph_usart4
	#define KF32F_Periph_usart5
	#define KF32F_Periph_usart6
	#define KF32F_Periph_usart7
    /* USB */
	#define KF32F_Periph_usb
	/* BTIME */
	#define KF32F_Periph_btime14
	#define KF32F_Periph_btime15
	/* GPTIME */
	#define KF32F_Periph_gptime0
	#define KF32F_Periph_gptime1
	#define KF32F_Periph_gptime2
	#define KF32F_Periph_gptime3
	#define KF32F_Periph_gptime4
	#define KF32F_Periph_gptime18
	#define KF32F_Periph_gptime19
	#define KF32F_Periph_gptime20
	#define KF32F_Periph_gptime21
	#define KF32F_Periph_gptime22_time23
	#define KF32F_Periph_gptime22
	#define KF32F_Periph_gptime23
	/* ATIME */
	#define KF32F_Periph_atime5_time6
	#define KF32F_Periph_atime5
	#define KF32F_Periph_atime6

	#define KF32F_Periph_atime9_time10
	#define KF32F_Periph_atime9
	#define KF32F_Periph_atime10
#endif //KF32F350
#endif /* _KF32F_Config_H */
