/**
  *********************************************************************
  * �ļ��� KF32F_BASIC.h
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  V2.3
  * ��  ��  2019-11-16
  * ��  ��  KF32Fϵ�������������ļ���������
  *          - ����������ڴ�ṹ
  *          - ����ļĴ�����λ������������
  *          - ����Ĵ����ķ��ʺ�
  *          - ���⹦�ܼĴ���λ����ָ��ĺ�
  *
  *********************************************************************
  */


#ifndef _KF32F_BASIC_H_
#define _KF32F_BASIC_H_

#include <stdint.h>
#include "KF32F_Config.h"

#define _CLOSE_SERVICE_     1

/* �û����ϵ㹦�� */
#define USE_CHECK_ASSERT    0
#if USE_CHECK_ASSERT
   #define CHECK_RESTRICTION(expr) ((expr) ? (void)0 : check_failed((uint8_t *)__FILE__, __LINE__))
   /*  У������� ------------------------------------------------------- */
   void check_failed(uint8_t* file, uint32_t line);
#else
#define CHECK_RESTRICTION(expr) ((void)0)
#endif /* USE_CHECK_ASSERT */

/* �Ĵ���λ���ܵ�ʹ�ܿ��� */
typedef enum
{
    FALSE = 0,
    TRUE = !FALSE
} FunctionalState;
#define CHECK_FUNCTIONAL_STATE(STATE) (((STATE) == FALSE) || ((STATE) == TRUE))

/* �Ĵ���λ���״̬��־ */
typedef enum
{
    RESET = 0,
    SET = !RESET
} FlagStatus, INTStatus;

/* �������ص�״̬��־ */
typedef enum
{
    FAILURE = 0,
    SUCCESS = !FAILURE
} RetStatus;

/* ʹ�ܵ�״̬��־ */
typedef enum
{
    DISABLE = 0,
    ENABLE = !DISABLE
} AbleStatus;

/* ----------------------------------------------------------------------------
   -- �ж�������
   ---------------------------------------------------------------------------- */

/* �ж�������� */
typedef enum {
    INT_Initial_SP              = 0,         /* Initial stack pointer */
    INT_Reset                   = 1,         /* Reset */
    INT_NMI                     = 2,         /* NMI interrupt */
    INT_HardFault               = 3,         /* hard fault exception */
    INT_Reserved4               = 4,         /* Reserved interrupt 4 */
    INT_StackFault              = 5,         /* stack Fault exception */
    INT_AriFault                = 6,         /* arithmetic fault exception */
    INT_Reserved7               = 7,         /* Reserved interrupt 7 */
    INT_Reserved8               = 8,         /* Reserved interrupt 8 */
    INT_Reserved9               = 9,         /* Reserved interrupt 9 */
    INT_Reserved10              = 10,        /* Reserved interrupt 10 */
    INT_SVCAll                  = 11,        /* SVCall interrupt */
    INT_Reserved12              = 12,        /* Reserved interrupt 11 */
    INT_Reserved13              = 13,        /* Reserved interrupt 12 */
    INT_SoftSV                  = 14,        /* SoftSV interrupt */
    INT_SysTick                 = 15,        /* SysTick interrupt */
    INT_WWDT                    = 16,        /* WWDT interrupt */
    INT_EINT16                  = 17,        /* EINT16 interrupt */
    INT_EINT0                   = 18,        /* EINT0 interrupt */
    INT_EINT1                   = 19,        /* EINT1 interrupt */
    INT_EINT2                   = 20,        /* EINT2 interrupt */
    INT_EINT3                   = 21,        /* EINT3 interrupt */
    INT_EINT4                   = 22,        /* EINT4 interrupt */
    INT_EINT9TO5                = 23,        /* EINT<9:5> interrupt */
    INT_EINT15TO10              = 24,        /* EINT<15:10> interrupt */
    INT_T1                      = 25,        /* T1 interrupt */
    INT_T3                      = 26,        /* T3 interrupt */
    INT_T5                      = 27,        /* T5 interrupt */
    INT_T6                      = 28,        /* T6 interrupt */
    INT_QEI                     = 29,        /* (QEI) interrupt */
    INT_T7                      = INT_QEI,   /* T7(QEI) interrupt */
    INT_T8                      = INT_QEI,   /* T8(QEI) interrupt */
    INT_CAN2                    = 30,        /* CAN2 interrupt */
    INT_CAN3                    = 31,        /* CAN3 interrupt */
    INT_CAN4                    = 32,        /* CAN4 interrupt */
    INT_T14                     = 33,        /* T14 interrupt */
    INT_T15                     = 34,        /* T15 interrupt */
    INT_CAN5              		= 35,        /* CAN5 interrupt  */
    INT_EXIC			        = 36,        /* EXIC interrupt  */
    INT_ADC0                    = 37,        /* ADC0 interrupt */
    INT_ADC1                    = 38,        /* ADC1 interrupt */
    INT_CFGL                    = 39,        /* CFGL interrupt */
    INT_LCD                     = 40,        /* LCD interrupt */
    INT_T0                      = 41,        /* T0 interrupt */
    INT_DMA0                    = 42,        /* DMA0 interrupt */
    INT_CMP			            = 43,        /* CMP interrupt  */
    INT_USART0                  = 44,        /* USART0 interrupt */
    INT_USART1                  = 45,        /* USART1 interrupt */
    INT_SPI0                    = 46,        /* SPI0 interrupt */
    INT_SPI1                    = 47,        /* SPI1 interrupt */
    INT_DMA1                    = 48,        /* DMA1 interrupt */
    INT_EINT19TO17              = 49,        /* EINT18 interrupt */
    INT_CAN0                    = 50,        /* CAN0 interrupt */
    INT_CAN1                    = 51,        /* CAN1 interrupt */
    INT_T9                      = 52,        /* T9 interrupt */
    INT_T10                  	= 53,        /* T10 interrupt */
    INT_EINT21TO20              = 54,        /* EINT<21:20> interrupt */
    INT_EINT31TO22              = 55,        /* EINT<31:22> interrupt */
    INT_OSC                     = 56,        /* OSC(CLK) interrupt */
    INT_CLK                     = INT_OSC,   /* OSC(CLK) interrupt */
    INT_I2C0                    = 57,        /* I2C0 interrupt */
    INT_I2C1                    = 58,        /* I2C1 interrupt */
    INT_I2C2                    = 59,        /* I2C2 interrupt */
    INT_USB                     = 60,        /* USB interrupt */
    INT_T2                      = 61,        /* T2 interrupt */
    INT_T4                      = 62,        /* T4 interrupt */
    INT_CTOUCH                  = 63,        /* CTOUCH interrupt */
    INT_USART2                  = 64,        /* USART2 interrupt */
    INT_USART3                  = 65,        /* USART3 interrupt */
    INT_USART4                  = 66,        /* USART4 interrupt */
    INT_SPI2                    = 67,        /* SPI2 interrupt */
    INT_SPI3                    = 68,        /* SPI3 interrupt */
    INT_ADC2                    = 69,        /* ADC2 interrupt */
    INT_T18                     = 70,        /* T18 interrupt */
    INT_T19                     = 71,        /* T19 interrupt */
    INT_T22                     = 72,        /* T22 interrupt */
    INT_T23						=INT_T22,    /* T23 interrupt */
    INT_WKP0                    = 73,        /* WKP0 interrupt */
    INT_WKP1					=INT_WKP0,   /* WKP1 interrupt */
    INT_WKP2					=INT_WKP0,   /* WKP2 interrupt */
    INT_WKP3					=INT_WKP0,   /* WKP3 interrupt */
    INT_WKP4					=INT_WKP0,   /* WKP4 interrupt */
    INT_T20                     = 74,        /* T20 interrupt */
    INT_T21                     = 75,        /* T21 interrupt */
    INT_I2C3              		= 76,        /* I2C3 interrupt 76 */
    INT_USART5              	= 77,        /* USART5 interrupt 77 */
    INT_USART6              	= 78,        /* USART6 interrupt 78 */
    INT_USART7              	= 79,        /* USART7 interrupt 79 */
} InterruptIndex;
/* �ж�������Ŷ������ */


/* ----------------------------------------------------------------------------
   -- ������ض���
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- ͨ����������˿�(GPIO)
   ---------------------------------------------------------------------------- */

/* GPIO - ����Ĵ����ڴ�ṹ */
typedef struct GPIO_MemMap {
    volatile const uint32_t PIR;        /* GPIO����״̬�Ĵ���, ƫ��:0x0 */
    volatile       uint32_t POR;        /* GPIO���״̬�Ĵ���, ƫ��:0x4 */
    volatile       uint32_t PUR;        /* GPIO����ʹ�ܼĴ���, ƫ��:0x8 */
    volatile       uint32_t PDR;        /* GPIO����ʹ�ܼĴ���, ƫ��:0xC */
    volatile       uint32_t PODR;       /* GPIO��©������ƼĴ���, ƫ��:0x10 */
    volatile       uint32_t PMOD;       /* GPIO�˿ڷ�����ƼĴ���, ƫ��:0x14 */
    volatile       uint32_t OMOD;       /* GPIO�˿��ٶȿ��ƼĴ���, ƫ��:0x18 */
    volatile       uint32_t LOCK;       /* GPIO�˿������Ĵ���, ƫ��:0x1C */
    volatile       uint32_t RMP[2];     /* GPIO��ӳ����ƼĴ���, ƫ��:0x20 */
	               uint32_t RESERVED;	/* ƫ��:0x2C */
    volatile	   uint32_t CTMDCTL[2]; /* GPIO�����˿����üĴ���, ƫ��0x30 */
}GPIO_SFRmap;

/* ----------------------------------------------------------------------------
   -- GPIO - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* GPIO - �Ĵ�����ڵ�ַ */
#define GPIOA_ADDR                      ((uint32_t)0x50000000)
#define GPIOB_ADDR                      ((uint32_t)0x50000040)
#define GPIOC_ADDR                      ((uint32_t)0x50000080)
#define GPIOD_ADDR                      ((uint32_t)0x500000C0)
#define GPIOE_ADDR                      ((uint32_t)0x50000100)
#define GPIOF_ADDR                      ((uint32_t)0x50000140)
#define GPIOG_ADDR                      ((uint32_t)0x50000180)
#define GPIOH_ADDR                      ((uint32_t)0x500001C0)
#define GPIOA_SFR                       ((GPIO_SFRmap *) GPIOA_ADDR)
#define GPIOB_SFR                       ((GPIO_SFRmap *) GPIOB_ADDR)
#define GPIOC_SFR                       ((GPIO_SFRmap *) GPIOC_ADDR)
#define GPIOD_SFR                       ((GPIO_SFRmap *) GPIOD_ADDR)
#define GPIOE_SFR                       ((GPIO_SFRmap *) GPIOE_ADDR)
#define GPIOF_SFR                       ((GPIO_SFRmap *) GPIOF_ADDR)
#define GPIOG_SFR                       ((GPIO_SFRmap *) GPIOG_ADDR)
#define GPIOH_SFR                       ((GPIO_SFRmap *) GPIOH_ADDR)

/* GPIO - �Ĵ������ */
#define GPIOA_PIR                       (GPIOA_SFR->PIR)
#define GPIOA_POR                       (GPIOA_SFR->POR)
#define GPIOA_PUR                       (GPIOA_SFR->PUR)
#define GPIOA_PDR                       (GPIOA_SFR->PDR)
#define GPIOA_PODR                      (GPIOA_SFR->PODR)
#define GPIOA_PMOD                      (GPIOA_SFR->PMOD)
#define GPIOA_OMOD                      (GPIOA_SFR->OMOD)
#define GPIOA_LOCK                      (GPIOA_SFR->LOCK)
#define GPIOA_RMPL                      (GPIOA_SFR->RMP[0])
#define GPIOA_RMPH                      (GPIOA_SFR->RMP[1])
#define GPIOA_CTMDCTL0                  (GPIOA_SFR->CTMDCTL[0])
#define GPIOA_CTMDCTL1                  (GPIOA_SFR->CTMDCTL[1])
#define GPIOB_PIR                       (GPIOB_SFR->PIR)
#define GPIOB_POR                       (GPIOB_SFR->POR)
#define GPIOB_PUR                       (GPIOB_SFR->PUR)
#define GPIOB_PDR                       (GPIOB_SFR->PDR)
#define GPIOB_PODR                      (GPIOB_SFR->PODR)
#define GPIOB_PMOD                      (GPIOB_SFR->PMOD)
#define GPIOB_OMOD                      (GPIOB_SFR->OMOD)
#define GPIOB_LOCK                      (GPIOB_SFR->LOCK)
#define GPIOB_RMPL                      (GPIOB_SFR->RMP[0])
#define GPIOB_RMPH                      (GPIOB_SFR->RMP[1])
#define GPIOC_PIR                       (GPIOC_SFR->PIR)
#define GPIOC_POR                       (GPIOC_SFR->POR)
#define GPIOC_PUR                       (GPIOC_SFR->PUR)
#define GPIOC_PDR                       (GPIOC_SFR->PDR)
#define GPIOC_PODR                      (GPIOC_SFR->PODR)
#define GPIOC_PMOD                      (GPIOC_SFR->PMOD)
#define GPIOC_OMOD                      (GPIOC_SFR->OMOD)
#define GPIOC_LOCK                      (GPIOC_SFR->LOCK)
#define GPIOC_RMPL                      (GPIOC_SFR->RMP[0])
#define GPIOC_RMPH                      (GPIOC_SFR->RMP[1])
#define GPIOD_PIR                       (GPIOD_SFR->PIR)
#define GPIOD_POR                       (GPIOD_SFR->POR)
#define GPIOD_PUR                       (GPIOD_SFR->PUR)
#define GPIOD_PDR                       (GPIOD_SFR->PDR)
#define GPIOD_PODR                      (GPIOD_SFR->PODR)
#define GPIOD_PMOD                      (GPIOD_SFR->PMOD)
#define GPIOD_OMOD                      (GPIOD_SFR->OMOD)
#define GPIOD_LOCK                      (GPIOD_SFR->LOCK)
#define GPIOD_RMPL                      (GPIOD_SFR->RMP[0])
#define GPIOD_RMPH                      (GPIOD_SFR->RMP[1])
#define GPIOD_CTMDCTL                   (GPIOD_SFR->CTMDCTL[0])
#define GPIOE_PIR                       (GPIOE_SFR->PIR)
#define GPIOE_POR                       (GPIOE_SFR->POR)
#define GPIOE_PUR                       (GPIOE_SFR->PUR)
#define GPIOE_PDR                       (GPIOE_SFR->PDR)
#define GPIOE_PODR                      (GPIOE_SFR->PODR)
#define GPIOE_PMOD                      (GPIOE_SFR->PMOD)
#define GPIOE_OMOD                      (GPIOE_SFR->OMOD)
#define GPIOE_LOCK                      (GPIOE_SFR->LOCK)
#define GPIOE_RMPL                      (GPIOE_SFR->RMP[0])
#define GPIOE_RMPH                      (GPIOE_SFR->RMP[1])
#define GPIOE_CTMDCTL                   (GPIOE_SFR->CTMDCTL[0])
#define GPIOF_PIR                       (GPIOF_SFR->PIR)
#define GPIOF_POR                       (GPIOF_SFR->POR)
#define GPIOF_PUR                       (GPIOF_SFR->PUR)
#define GPIOF_PDR                       (GPIOF_SFR->PDR)
#define GPIOF_PODR                      (GPIOF_SFR->PODR)
#define GPIOF_PMOD                      (GPIOF_SFR->PMOD)
#define GPIOF_OMOD                      (GPIOF_SFR->OMOD)
#define GPIOF_LOCK                      (GPIOF_SFR->LOCK)
#define GPIOF_RMPL                      (GPIOF_SFR->RMP[0])
#define GPIOF_RMPH                      (GPIOF_SFR->RMP[1])
#define GPIOG_PIR                       (GPIOG_SFR->PIR)
#define GPIOG_POR                       (GPIOG_SFR->POR)
#define GPIOG_PUR                       (GPIOG_SFR->PUR)
#define GPIOG_PDR                       (GPIOG_SFR->PDR)
#define GPIOG_PODR                      (GPIOG_SFR->PODR)
#define GPIOG_PMOD                      (GPIOG_SFR->PMOD)
#define GPIOG_OMOD                      (GPIOG_SFR->OMOD)
#define GPIOG_LOCK                      (GPIOG_SFR->LOCK)
#define GPIOG_RMPL                      (GPIOG_SFR->RMP[0])
#define GPIOG_RMPH                      (GPIOG_SFR->RMP[1])
#define GPIOH_PIR                       (GPIOH_SFR->PIR)
#define GPIOH_POR                       (GPIOH_SFR->POR)
#define GPIOH_PUR                       (GPIOH_SFR->PUR)
#define GPIOH_PDR                       (GPIOH_SFR->PDR)
#define GPIOH_PODR                      (GPIOH_SFR->PODR)
#define GPIOH_PMOD                      (GPIOH_SFR->PMOD)
#define GPIOH_OMOD                      (GPIOH_SFR->OMOD)
#define GPIOH_LOCK                      (GPIOH_SFR->LOCK)
#define GPIOH_RMPL                      (GPIOH_SFR->RMP[0])
#define GPIOH_RMPH                      (GPIOH_SFR->RMP[1])
#define GPIOH_CTMDCTL                   (GPIOH_SFR->CTMDCTL[0])

/* GPIO_PIR λ�� */
#define GPIO_PIR_PXPIR0_POS             (0)
#define GPIO_PIR_PXPIR1_POS             (1)
#define GPIO_PIR_PXPIR2_POS             (2)
#define GPIO_PIR_PXPIR3_POS             (3)
#define GPIO_PIR_PXPIR4_POS             (4)
#define GPIO_PIR_PXPIR5_POS             (5)
#define GPIO_PIR_PXPIR6_POS             (6)
#define GPIO_PIR_PXPIR7_POS             (7)
#define GPIO_PIR_PXPIR8_POS             (8)
#define GPIO_PIR_PXPIR9_POS             (9)
#define GPIO_PIR_PXPIR10_POS            (10)
#define GPIO_PIR_PXPIR11_POS            (11)
#define GPIO_PIR_PXPIR12_POS            (12)
#define GPIO_PIR_PXPIR13_POS            (13)
#define GPIO_PIR_PXPIR14_POS            (14)
#define GPIO_PIR_PXPIR15_POS            (15)
#define GPIO_PIR_PXPIR                  ((uint32_t)0xFFFF<<(GPIO_PIR_PXPIR0_POS))
#define GPIO_PIR_PXPIR0                 ((uint32_t)1<<(GPIO_PIR_PXPIR0_POS))
#define GPIO_PIR_PXPIR1                 ((uint32_t)1<<(GPIO_PIR_PXPIR1_POS))
#define GPIO_PIR_PXPIR2                 ((uint32_t)1<<(GPIO_PIR_PXPIR2_POS))
#define GPIO_PIR_PXPIR3                 ((uint32_t)1<<(GPIO_PIR_PXPIR3_POS))
#define GPIO_PIR_PXPIR4                 ((uint32_t)1<<(GPIO_PIR_PXPIR4_POS))
#define GPIO_PIR_PXPIR5                 ((uint32_t)1<<(GPIO_PIR_PXPIR5_POS))
#define GPIO_PIR_PXPIR6                 ((uint32_t)1<<(GPIO_PIR_PXPIR6_POS))
#define GPIO_PIR_PXPIR7                 ((uint32_t)1<<(GPIO_PIR_PXPIR7_POS))
#define GPIO_PIR_PXPIR8                 ((uint32_t)1<<(GPIO_PIR_PXPIR8_POS))
#define GPIO_PIR_PXPIR9                 ((uint32_t)1<<(GPIO_PIR_PXPIR9_POS))
#define GPIO_PIR_PXPIR10                ((uint32_t)1<<(GPIO_PIR_PXPIR10_POS))
#define GPIO_PIR_PXPIR11                ((uint32_t)1<<(GPIO_PIR_PXPIR11_POS))
#define GPIO_PIR_PXPIR12                ((uint32_t)1<<(GPIO_PIR_PXPIR12_POS))
#define GPIO_PIR_PXPIR13                ((uint32_t)1<<(GPIO_PIR_PXPIR13_POS))
#define GPIO_PIR_PXPIR14                ((uint32_t)1<<(GPIO_PIR_PXPIR14_POS))
#define GPIO_PIR_PXPIR15                ((uint32_t)1<<(GPIO_PIR_PXPIR15_POS))

/* GPIO_POR λ�� */
#define GPIO_POR_PXPOR0_POS             (0)
#define GPIO_POR_PXPOR1_POS             (1)
#define GPIO_POR_PXPOR2_POS             (2)
#define GPIO_POR_PXPOR3_POS             (3)
#define GPIO_POR_PXPOR4_POS             (4)
#define GPIO_POR_PXPOR5_POS             (5)
#define GPIO_POR_PXPOR6_POS             (6)
#define GPIO_POR_PXPOR7_POS             (7)
#define GPIO_POR_PXPOR8_POS             (8)
#define GPIO_POR_PXPOR9_POS             (9)
#define GPIO_POR_PXPOR10_POS            (10)
#define GPIO_POR_PXPOR11_POS            (11)
#define GPIO_POR_PXPOR12_POS            (12)
#define GPIO_POR_PXPOR13_POS            (13)
#define GPIO_POR_PXPOR14_POS            (14)
#define GPIO_POR_PXPOR15_POS            (15)
#define GPIO_POR_PXPOR                  ((uint32_t)0xFFFF<<(GPIO_POR_PXPOR0_POS))
#define GPIO_POR_PXPOR0                 ((uint32_t)1<<(GPIO_POR_PXPOR0_POS))
#define GPIO_POR_PXPOR1                 ((uint32_t)1<<(GPIO_POR_PXPOR1_POS))
#define GPIO_POR_PXPOR2                 ((uint32_t)1<<(GPIO_POR_PXPOR2_POS))
#define GPIO_POR_PXPOR3                 ((uint32_t)1<<(GPIO_POR_PXPOR3_POS))
#define GPIO_POR_PXPOR4                 ((uint32_t)1<<(GPIO_POR_PXPOR4_POS))
#define GPIO_POR_PXPOR5                 ((uint32_t)1<<(GPIO_POR_PXPOR5_POS))
#define GPIO_POR_PXPOR6                 ((uint32_t)1<<(GPIO_POR_PXPOR6_POS))
#define GPIO_POR_PXPOR7                 ((uint32_t)1<<(GPIO_POR_PXPOR7_POS))
#define GPIO_POR_PXPOR8                 ((uint32_t)1<<(GPIO_POR_PXPOR8_POS))
#define GPIO_POR_PXPOR9                 ((uint32_t)1<<(GPIO_POR_PXPOR9_POS))
#define GPIO_POR_PXPOR10                ((uint32_t)1<<(GPIO_POR_PXPOR10_POS))
#define GPIO_POR_PXPOR11                ((uint32_t)1<<(GPIO_POR_PXPOR11_POS))
#define GPIO_POR_PXPOR12                ((uint32_t)1<<(GPIO_POR_PXPOR12_POS))
#define GPIO_POR_PXPOR13                ((uint32_t)1<<(GPIO_POR_PXPOR13_POS))
#define GPIO_POR_PXPOR14                ((uint32_t)1<<(GPIO_POR_PXPOR14_POS))
#define GPIO_POR_PXPOR15                ((uint32_t)1<<(GPIO_POR_PXPOR15_POS))

/* GPIO_PUR λ�� */
#define GPIO_PUR_PXPUR0_POS             (0)
#define GPIO_PUR_PXPUR1_POS             (1)
#define GPIO_PUR_PXPUR2_POS             (2)
#define GPIO_PUR_PXPUR3_POS             (3)
#define GPIO_PUR_PXPUR4_POS             (4)
#define GPIO_PUR_PXPUR5_POS             (5)
#define GPIO_PUR_PXPUR6_POS             (6)
#define GPIO_PUR_PXPUR7_POS             (7)
#define GPIO_PUR_PXPUR8_POS             (8)
#define GPIO_PUR_PXPUR9_POS             (9)
#define GPIO_PUR_PXPUR10_POS            (10)
#define GPIO_PUR_PXPUR11_POS            (11)
#define GPIO_PUR_PXPUR12_POS            (12)
#define GPIO_PUR_PXPUR13_POS            (13)
#define GPIO_PUR_PXPUR14_POS            (14)
#define GPIO_PUR_PXPUR15_POS            (15)
#define GPIO_PUR_PXPUR                  ((uint32_t)0xFFFF<<(GPIO_PUR_PXPUR0_POS))
#define GPIO_PUR_PXPUR0                 ((uint32_t)1<<(GPIO_PUR_PXPUR0_POS))
#define GPIO_PUR_PXPUR1                 ((uint32_t)1<<(GPIO_PUR_PXPUR1_POS))
#define GPIO_PUR_PXPUR2                 ((uint32_t)1<<(GPIO_PUR_PXPUR2_POS))
#define GPIO_PUR_PXPUR3                 ((uint32_t)1<<(GPIO_PUR_PXPUR3_POS))
#define GPIO_PUR_PXPUR4                 ((uint32_t)1<<(GPIO_PUR_PXPUR4_POS))
#define GPIO_PUR_PXPUR5                 ((uint32_t)1<<(GPIO_PUR_PXPUR5_POS))
#define GPIO_PUR_PXPUR6                 ((uint32_t)1<<(GPIO_PUR_PXPUR6_POS))
#define GPIO_PUR_PXPUR7                 ((uint32_t)1<<(GPIO_PUR_PXPUR7_POS))
#define GPIO_PUR_PXPUR8                 ((uint32_t)1<<(GPIO_PUR_PXPUR8_POS))
#define GPIO_PUR_PXPUR9                 ((uint32_t)1<<(GPIO_PUR_PXPUR9_POS))
#define GPIO_PUR_PXPUR10                ((uint32_t)1<<(GPIO_PUR_PXPUR10_POS))
#define GPIO_PUR_PXPUR11                ((uint32_t)1<<(GPIO_PUR_PXPUR11_POS))
#define GPIO_PUR_PXPUR12                ((uint32_t)1<<(GPIO_PUR_PXPUR12_POS))
#define GPIO_PUR_PXPUR13                ((uint32_t)1<<(GPIO_PUR_PXPUR13_POS))
#define GPIO_PUR_PXPUR14                ((uint32_t)1<<(GPIO_PUR_PXPUR14_POS))
#define GPIO_PUR_PXPUR15                ((uint32_t)1<<(GPIO_PUR_PXPUR15_POS))

/* GPIO_PDR λ�� */
#define GPIO_PDR_PXPDR0_POS             (0)
#define GPIO_PDR_PXPDR1_POS             (1)
#define GPIO_PDR_PXPDR2_POS             (2)
#define GPIO_PDR_PXPDR3_POS             (3)
#define GPIO_PDR_PXPDR4_POS             (4)
#define GPIO_PDR_PXPDR5_POS             (5)
#define GPIO_PDR_PXPDR6_POS             (6)
#define GPIO_PDR_PXPDR7_POS             (7)
#define GPIO_PDR_PXPDR8_POS             (8)
#define GPIO_PDR_PXPDR9_POS             (9)
#define GPIO_PDR_PXPDR10_POS            (10)
#define GPIO_PDR_PXPDR11_POS            (11)
#define GPIO_PDR_PXPDR12_POS            (12)
#define GPIO_PDR_PXPDR13_POS            (13)
#define GPIO_PDR_PXPDR14_POS            (14)
#define GPIO_PDR_PXPDR15_POS            (15)
#define GPIO_PDR_PXPDR                  ((uint32_t)0xFFFF<<(GPIO_PDR_PXPDR0_POS))
#define GPIO_PDR_PXPDR0                 ((uint32_t)1<<(GPIO_PDR_PXPDR0_POS))
#define GPIO_PDR_PXPDR1                 ((uint32_t)1<<(GPIO_PDR_PXPDR1_POS))
#define GPIO_PDR_PXPDR2                 ((uint32_t)1<<(GPIO_PDR_PXPDR2_POS))
#define GPIO_PDR_PXPDR3                 ((uint32_t)1<<(GPIO_PDR_PXPDR3_POS))
#define GPIO_PDR_PXPDR4                 ((uint32_t)1<<(GPIO_PDR_PXPDR4_POS))
#define GPIO_PDR_PXPDR5                 ((uint32_t)1<<(GPIO_PDR_PXPDR5_POS))
#define GPIO_PDR_PXPDR6                 ((uint32_t)1<<(GPIO_PDR_PXPDR6_POS))
#define GPIO_PDR_PXPDR7                 ((uint32_t)1<<(GPIO_PDR_PXPDR7_POS))
#define GPIO_PDR_PXPDR8                 ((uint32_t)1<<(GPIO_PDR_PXPDR8_POS))
#define GPIO_PDR_PXPDR9                 ((uint32_t)1<<(GPIO_PDR_PXPDR9_POS))
#define GPIO_PDR_PXPDR10                ((uint32_t)1<<(GPIO_PDR_PXPDR10_POS))
#define GPIO_PDR_PXPDR11                ((uint32_t)1<<(GPIO_PDR_PXPDR11_POS))
#define GPIO_PDR_PXPDR12                ((uint32_t)1<<(GPIO_PDR_PXPDR12_POS))
#define GPIO_PDR_PXPDR13                ((uint32_t)1<<(GPIO_PDR_PXPDR13_POS))
#define GPIO_PDR_PXPDR14                ((uint32_t)1<<(GPIO_PDR_PXPDR14_POS))
#define GPIO_PDR_PXPDR15                ((uint32_t)1<<(GPIO_PDR_PXPDR15_POS))

/* GPIO_PODR λ�� */
#define GPIO_PODR_PXPODR0_POS           (0)
#define GPIO_PODR_PXPODR1_POS           (1)
#define GPIO_PODR_PXPODR2_POS           (2)
#define GPIO_PODR_PXPODR3_POS           (3)
#define GPIO_PODR_PXPODR4_POS           (4)
#define GPIO_PODR_PXPODR5_POS           (5)
#define GPIO_PODR_PXPODR6_POS           (6)
#define GPIO_PODR_PXPODR7_POS           (7)
#define GPIO_PODR_PXPODR8_POS           (8)
#define GPIO_PODR_PXPODR9_POS           (9)
#define GPIO_PODR_PXPODR10_POS          (10)
#define GPIO_PODR_PXPODR11_POS          (11)
#define GPIO_PODR_PXPODR12_POS          (12)
#define GPIO_PODR_PXPODR13_POS          (13)
#define GPIO_PODR_PXPODR14_POS          (14)
#define GPIO_PODR_PXPODR15_POS          (15)
#define GPIO_PODR_PXPODR                ((uint32_t)0xFFFF<<(GPIO_PODR_PXPODR0_POS))
#define GPIO_PODR_PXPODR0               ((uint32_t)1<<(GPIO_PODR_PXPODR0_POS))
#define GPIO_PODR_PXPODR1               ((uint32_t)1<<(GPIO_PODR_PXPODR1_POS))
#define GPIO_PODR_PXPODR2               ((uint32_t)1<<(GPIO_PODR_PXPODR2_POS))
#define GPIO_PODR_PXPODR3               ((uint32_t)1<<(GPIO_PODR_PXPODR3_POS))
#define GPIO_PODR_PXPODR4               ((uint32_t)1<<(GPIO_PODR_PXPODR4_POS))
#define GPIO_PODR_PXPODR5               ((uint32_t)1<<(GPIO_PODR_PXPODR5_POS))
#define GPIO_PODR_PXPODR6               ((uint32_t)1<<(GPIO_PODR_PXPODR6_POS))
#define GPIO_PODR_PXPODR7               ((uint32_t)1<<(GPIO_PODR_PXPODR7_POS))
#define GPIO_PODR_PXPODR8               ((uint32_t)1<<(GPIO_PODR_PXPODR8_POS))
#define GPIO_PODR_PXPODR9               ((uint32_t)1<<(GPIO_PODR_PXPODR9_POS))
#define GPIO_PODR_PXPODR10              ((uint32_t)1<<(GPIO_PODR_PXPODR10_POS))
#define GPIO_PODR_PXPODR11              ((uint32_t)1<<(GPIO_PODR_PXPODR11_POS))
#define GPIO_PODR_PXPODR12              ((uint32_t)1<<(GPIO_PODR_PXPODR12_POS))
#define GPIO_PODR_PXPODR13              ((uint32_t)1<<(GPIO_PODR_PXPODR13_POS))
#define GPIO_PODR_PXPODR14              ((uint32_t)1<<(GPIO_PODR_PXPODR14_POS))
#define GPIO_PODR_PXPODR15              ((uint32_t)1<<(GPIO_PODR_PXPODR15_POS))

/* GPIO_PMOD λ�� */
#define GPIO_PMOD_PXPMD0_0_POS          (0)
#define GPIO_PMOD_PXPMD0_1_POS          (1)
#define GPIO_PMOD_PXPMD1_0_POS          (2)
#define GPIO_PMOD_PXPMD1_1_POS          (3)
#define GPIO_PMOD_PXPMD2_0_POS          (4)
#define GPIO_PMOD_PXPMD2_1_POS          (5)
#define GPIO_PMOD_PXPMD3_0_POS          (6)
#define GPIO_PMOD_PXPMD3_1_POS          (7)
#define GPIO_PMOD_PXPMD4_0_POS          (8)
#define GPIO_PMOD_PXPMD4_1_POS          (9)
#define GPIO_PMOD_PXPMD5_0_POS          (10)
#define GPIO_PMOD_PXPMD5_1_POS          (11)
#define GPIO_PMOD_PXPMD6_0_POS          (12)
#define GPIO_PMOD_PXPMD6_1_POS          (13)
#define GPIO_PMOD_PXPMD7_0_POS          (14)
#define GPIO_PMOD_PXPMD7_1_POS          (15)
#define GPIO_PMOD_PXPMD8_0_POS          (16)
#define GPIO_PMOD_PXPMD8_1_POS          (17)
#define GPIO_PMOD_PXPMD9_0_POS          (18)
#define GPIO_PMOD_PXPMD9_1_POS          (19)
#define GPIO_PMOD_PXPMD10_0_POS         (20)
#define GPIO_PMOD_PXPMD10_1_POS         (21)
#define GPIO_PMOD_PXPMD11_0_POS         (22)
#define GPIO_PMOD_PXPMD11_1_POS         (23)
#define GPIO_PMOD_PXPMD12_0_POS         (24)
#define GPIO_PMOD_PXPMD12_1_POS         (25)
#define GPIO_PMOD_PXPMD13_0_POS         (26)
#define GPIO_PMOD_PXPMD13_1_POS         (27)
#define GPIO_PMOD_PXPMD14_0_POS         (28)
#define GPIO_PMOD_PXPMD14_1_POS         (29)
#define GPIO_PMOD_PXPMD15_0_POS         (30)
#define GPIO_PMOD_PXPMD15_1_POS         (31)
#define GPIO_PMOD_PXPMD0                ((uint32_t)3<<(GPIO_PMOD_PXPMD0_0_POS))
#define GPIO_PMOD_PXPMD0_0              ((uint32_t)1<<(GPIO_PMOD_PXPMD0_0_POS))
#define GPIO_PMOD_PXPMD0_1              ((uint32_t)1<<(GPIO_PMOD_PXPMD0_1_POS))
#define GPIO_PMOD_PXPMD1                ((uint32_t)3<<(GPIO_PMOD_PXPMD1_0_POS))
#define GPIO_PMOD_PXPMD1_0              ((uint32_t)1<<(GPIO_PMOD_PXPMD1_0_POS))
#define GPIO_PMOD_PXPMD1_1              ((uint32_t)1<<(GPIO_PMOD_PXPMD1_1_POS))
#define GPIO_PMOD_PXPMD2                ((uint32_t)3<<(GPIO_PMOD_PXPMD2_0_POS))
#define GPIO_PMOD_PXPMD2_0              ((uint32_t)1<<(GPIO_PMOD_PXPMD2_0_POS))
#define GPIO_PMOD_PXPMD2_1              ((uint32_t)1<<(GPIO_PMOD_PXPMD2_1_POS))
#define GPIO_PMOD_PXPMD3                ((uint32_t)3<<(GPIO_PMOD_PXPMD3_0_POS))
#define GPIO_PMOD_PXPMD3_0              ((uint32_t)1<<(GPIO_PMOD_PXPMD3_0_POS))
#define GPIO_PMOD_PXPMD3_1              ((uint32_t)1<<(GPIO_PMOD_PXPMD3_1_POS))
#define GPIO_PMOD_PXPMD4                ((uint32_t)3<<(GPIO_PMOD_PXPMD4_0_POS))
#define GPIO_PMOD_PXPMD4_0              ((uint32_t)1<<(GPIO_PMOD_PXPMD4_0_POS))
#define GPIO_PMOD_PXPMD4_1              ((uint32_t)1<<(GPIO_PMOD_PXPMD4_1_POS))
#define GPIO_PMOD_PXPMD5                ((uint32_t)3<<(GPIO_PMOD_PXPMD5_0_POS))
#define GPIO_PMOD_PXPMD5_0              ((uint32_t)1<<(GPIO_PMOD_PXPMD5_0_POS))
#define GPIO_PMOD_PXPMD5_1              ((uint32_t)1<<(GPIO_PMOD_PXPMD5_1_POS))
#define GPIO_PMOD_PXPMD6                ((uint32_t)3<<(GPIO_PMOD_PXPMD6_0_POS))
#define GPIO_PMOD_PXPMD6_0              ((uint32_t)1<<(GPIO_PMOD_PXPMD6_0_POS))
#define GPIO_PMOD_PXPMD6_1              ((uint32_t)1<<(GPIO_PMOD_PXPMD6_1_POS))
#define GPIO_PMOD_PXPMD7                ((uint32_t)3<<(GPIO_PMOD_PXPMD7_0_POS))
#define GPIO_PMOD_PXPMD7_0              ((uint32_t)1<<(GPIO_PMOD_PXPMD7_0_POS))
#define GPIO_PMOD_PXPMD7_1              ((uint32_t)1<<(GPIO_PMOD_PXPMD7_1_POS))
#define GPIO_PMOD_PXPMD8                ((uint32_t)3<<(GPIO_PMOD_PXPMD8_0_POS))
#define GPIO_PMOD_PXPMD8_0              ((uint32_t)1<<(GPIO_PMOD_PXPMD8_0_POS))
#define GPIO_PMOD_PXPMD8_1              ((uint32_t)1<<(GPIO_PMOD_PXPMD8_1_POS))
#define GPIO_PMOD_PXPMD9                ((uint32_t)3<<(GPIO_PMOD_PXPMD9_0_POS))
#define GPIO_PMOD_PXPMD9_0              ((uint32_t)1<<(GPIO_PMOD_PXPMD9_0_POS))
#define GPIO_PMOD_PXPMD9_1              ((uint32_t)1<<(GPIO_PMOD_PXPMD9_1_POS))
#define GPIO_PMOD_PXPMD10               ((uint32_t)3<<(GPIO_PMOD_PXPMD10_0_POS))
#define GPIO_PMOD_PXPMD10_0             ((uint32_t)1<<(GPIO_PMOD_PXPMD10_0_POS))
#define GPIO_PMOD_PXPMD10_1             ((uint32_t)1<<(GPIO_PMOD_PXPMD10_1_POS))
#define GPIO_PMOD_PXPMD11               ((uint32_t)3<<(GPIO_PMOD_PXPMD11_0_POS))
#define GPIO_PMOD_PXPMD11_0             ((uint32_t)1<<(GPIO_PMOD_PXPMD11_0_POS))
#define GPIO_PMOD_PXPMD11_1             ((uint32_t)1<<(GPIO_PMOD_PXPMD11_1_POS))
#define GPIO_PMOD_PXPMD12               ((uint32_t)3<<(GPIO_PMOD_PXPMD12_0_POS))
#define GPIO_PMOD_PXPMD12_0             ((uint32_t)1<<(GPIO_PMOD_PXPMD12_0_POS))
#define GPIO_PMOD_PXPMD12_1             ((uint32_t)1<<(GPIO_PMOD_PXPMD12_1_POS))
#define GPIO_PMOD_PXPMD13               ((uint32_t)3<<(GPIO_PMOD_PXPMD13_0_POS))
#define GPIO_PMOD_PXPMD13_0             ((uint32_t)1<<(GPIO_PMOD_PXPMD13_0_POS))
#define GPIO_PMOD_PXPMD13_1             ((uint32_t)1<<(GPIO_PMOD_PXPMD13_1_POS))
#define GPIO_PMOD_PXPMD14               ((uint32_t)3<<(GPIO_PMOD_PXPMD14_0_POS))
#define GPIO_PMOD_PXPMD14_0             ((uint32_t)1<<(GPIO_PMOD_PXPMD14_0_POS))
#define GPIO_PMOD_PXPMD14_1             ((uint32_t)1<<(GPIO_PMOD_PXPMD14_1_POS))
#define GPIO_PMOD_PXPMD15               ((uint32_t)3<<(GPIO_PMOD_PXPMD15_0_POS))
#define GPIO_PMOD_PXPMD15_0             ((uint32_t)1<<(GPIO_PMOD_PXPMD15_0_POS))
#define GPIO_PMOD_PXPMD15_1             ((uint32_t)1<<(GPIO_PMOD_PXPMD15_1_POS))

/* GPIO_OMOD λ�� */
#define GPIO_OMOD_PXOMD0_POS            (0)
#define GPIO_OMOD_PXOMD1_POS            (2)
#define GPIO_OMOD_PXOMD2_POS            (4)
#define GPIO_OMOD_PXOMD3_POS            (6)
#define GPIO_OMOD_PXOMD4_POS            (8)
#define GPIO_OMOD_PXOMD5_POS            (10)
#define GPIO_OMOD_PXOMD6_POS            (12)
#define GPIO_OMOD_PXOMD7_POS            (14)
#define GPIO_OMOD_PXOMD8_POS            (16)
#define GPIO_OMOD_PXOMD9_POS            (18)
#define GPIO_OMOD_PXOMD10_POS           (20)
#define GPIO_OMOD_PXOMD11_POS           (22)
#define GPIO_OMOD_PXOMD12_POS           (24)
#define GPIO_OMOD_PXOMD13_POS           (26)
#define GPIO_OMOD_PXOMD14_POS           (28)
#define GPIO_OMOD_PXOMD15_POS           (30)
#define GPIO_OMOD_PXOMD0                ((uint32_t)1<<(GPIO_OMOD_PXOMD0_POS))
#define GPIO_OMOD_PXOMD1                ((uint32_t)1<<(GPIO_OMOD_PXOMD1_POS))
#define GPIO_OMOD_PXOMD2                ((uint32_t)1<<(GPIO_OMOD_PXOMD2_POS))
#define GPIO_OMOD_PXOMD3                ((uint32_t)1<<(GPIO_OMOD_PXOMD3_POS))
#define GPIO_OMOD_PXOMD4                ((uint32_t)1<<(GPIO_OMOD_PXOMD4_POS))
#define GPIO_OMOD_PXOMD5                ((uint32_t)1<<(GPIO_OMOD_PXOMD5_POS))
#define GPIO_OMOD_PXOMD6                ((uint32_t)1<<(GPIO_OMOD_PXOMD6_POS))
#define GPIO_OMOD_PXOMD7                ((uint32_t)1<<(GPIO_OMOD_PXOMD7_POS))
#define GPIO_OMOD_PXOMD8                ((uint32_t)1<<(GPIO_OMOD_PXOMD8_POS))
#define GPIO_OMOD_PXOMD9                ((uint32_t)1<<(GPIO_OMOD_PXOMD9_POS))
#define GPIO_OMOD_PXOMD10               ((uint32_t)1<<(GPIO_OMOD_PXOMD10_POS))
#define GPIO_OMOD_PXOMD11               ((uint32_t)1<<(GPIO_OMOD_PXOMD11_POS))
#define GPIO_OMOD_PXOMD12               ((uint32_t)1<<(GPIO_OMOD_PXOMD12_POS))
#define GPIO_OMOD_PXOMD13               ((uint32_t)1<<(GPIO_OMOD_PXOMD13_POS))
#define GPIO_OMOD_PXOMD14               ((uint32_t)1<<(GPIO_OMOD_PXOMD14_POS))
#define GPIO_OMOD_PXOMD15               ((uint32_t)1<<(GPIO_OMOD_PXOMD15_POS))

/* GPIO_LOCK λ�� */
#define GPIO_LOCK_PXLCK0_POS            (0)
#define GPIO_LOCK_PXLCK1_POS            (1)
#define GPIO_LOCK_PXLCK2_POS            (2)
#define GPIO_LOCK_PXLCK3_POS            (3)
#define GPIO_LOCK_PXLCK4_POS            (4)
#define GPIO_LOCK_PXLCK5_POS            (5)
#define GPIO_LOCK_PXLCK6_POS            (6)
#define GPIO_LOCK_PXLCK7_POS            (7)
#define GPIO_LOCK_PXLCK8_POS            (8)
#define GPIO_LOCK_PXLCK9_POS            (9)
#define GPIO_LOCK_PXLCK10_POS           (10)
#define GPIO_LOCK_PXLCK11_POS           (11)
#define GPIO_LOCK_PXLCK12_POS           (12)
#define GPIO_LOCK_PXLCK13_POS           (13)
#define GPIO_LOCK_PXLCK14_POS           (14)
#define GPIO_LOCK_PXLCK15_POS           (15)
#define GPIO_LOCK_PXLCKKEY0_POS         (16)
#define GPIO_LOCK_PXLCKKEY1_POS         (17)
#define GPIO_LOCK_PXLCKKEY2_POS         (18)
#define GPIO_LOCK_PXLCKKEY3_POS         (19)
#define GPIO_LOCK_PXLCKKEY4_POS         (20)
#define GPIO_LOCK_PXLCKKEY5_POS         (21)
#define GPIO_LOCK_PXLCKKEY6_POS         (22)
#define GPIO_LOCK_PXLCKKEY7_POS         (23)
#define GPIO_LOCK_PXLCKKEY8_POS         (24)
#define GPIO_LOCK_PXLCKKEY9_POS         (25)
#define GPIO_LOCK_PXLCKKEY10_POS        (26)
#define GPIO_LOCK_PXLCKKEY11_POS        (27)
#define GPIO_LOCK_PXLCKKEY12_POS        (28)
#define GPIO_LOCK_PXLCKKEY13_POS        (29)
#define GPIO_LOCK_PXLCKKEY14_POS        (30)
#define GPIO_LOCK_PXLCKKEY15_POS        (31)
#define GPIO_LOCK_PXLCK                 ((uint32_t)0xFFFF<<(GPIO_LOCK_PXLCK0_POS))
#define GPIO_LOCK_PXLCK0                ((uint32_t)1<<(GPIO_LOCK_PXLCK0_POS))
#define GPIO_LOCK_PXLCK1                ((uint32_t)1<<(GPIO_LOCK_PXLCK1_POS))
#define GPIO_LOCK_PXLCK2                ((uint32_t)1<<(GPIO_LOCK_PXLCK2_POS))
#define GPIO_LOCK_PXLCK3                ((uint32_t)1<<(GPIO_LOCK_PXLCK3_POS))
#define GPIO_LOCK_PXLCK4                ((uint32_t)1<<(GPIO_LOCK_PXLCK4_POS))
#define GPIO_LOCK_PXLCK5                ((uint32_t)1<<(GPIO_LOCK_PXLCK5_POS))
#define GPIO_LOCK_PXLCK6                ((uint32_t)1<<(GPIO_LOCK_PXLCK6_POS))
#define GPIO_LOCK_PXLCK7                ((uint32_t)1<<(GPIO_LOCK_PXLCK7_POS))
#define GPIO_LOCK_PXLCK8                ((uint32_t)1<<(GPIO_LOCK_PXLCK8_POS))
#define GPIO_LOCK_PXLCK9                ((uint32_t)1<<(GPIO_LOCK_PXLCK9_POS))
#define GPIO_LOCK_PXLCK10               ((uint32_t)1<<(GPIO_LOCK_PXLCK10_POS))
#define GPIO_LOCK_PXLCK11               ((uint32_t)1<<(GPIO_LOCK_PXLCK11_POS))
#define GPIO_LOCK_PXLCK12               ((uint32_t)1<<(GPIO_LOCK_PXLCK12_POS))
#define GPIO_LOCK_PXLCK13               ((uint32_t)1<<(GPIO_LOCK_PXLCK13_POS))
#define GPIO_LOCK_PXLCK14               ((uint32_t)1<<(GPIO_LOCK_PXLCK14_POS))
#define GPIO_LOCK_PXLCK15               ((uint32_t)1<<(GPIO_LOCK_PXLCK15_POS))
#define GPIO_LOCK_PXLCKKEY              ((uint32_t)0xFFFF<<(GPIO_LOCK_PXLCKKEY0_POS))
#define GPIO_LOCK_PXLCKKEY0             ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY0_POS))
#define GPIO_LOCK_PXLCKKEY1             ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY1_POS))
#define GPIO_LOCK_PXLCKKEY2             ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY2_POS))
#define GPIO_LOCK_PXLCKKEY3             ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY3_POS))
#define GPIO_LOCK_PXLCKKEY4             ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY4_POS))
#define GPIO_LOCK_PXLCKKEY5             ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY5_POS))
#define GPIO_LOCK_PXLCKKEY6             ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY6_POS))
#define GPIO_LOCK_PXLCKKEY7             ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY7_POS))
#define GPIO_LOCK_PXLCKKEY8             ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY8_POS))
#define GPIO_LOCK_PXLCKKEY9             ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY9_POS))
#define GPIO_LOCK_PXLCKKEY10            ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY10_POS))
#define GPIO_LOCK_PXLCKKEY11            ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY11_POS))
#define GPIO_LOCK_PXLCKKEY12            ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY12_POS))
#define GPIO_LOCK_PXLCKKEY13            ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY13_POS))
#define GPIO_LOCK_PXLCKKEY14            ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY14_POS))
#define GPIO_LOCK_PXLCKKEY15            ((uint32_t)1<<(GPIO_LOCK_PXLCKKEY15_POS))

/* GPIO_RMPL λ�� */
#define GPIO_RMPL_PXRMP0_0_POS          (0)
#define GPIO_RMPL_PXRMP0_1_POS          (1)
#define GPIO_RMPL_PXRMP0_2_POS          (2)
#define GPIO_RMPL_PXRMP0_3_POS          (3)
#define GPIO_RMPL_PXRMP1_0_POS          (4)
#define GPIO_RMPL_PXRMP1_1_POS          (5)
#define GPIO_RMPL_PXRMP1_2_POS          (6)
#define GPIO_RMPL_PXRMP1_3_POS          (7)
#define GPIO_RMPL_PXRMP2_0_POS          (8)
#define GPIO_RMPL_PXRMP2_1_POS          (9)
#define GPIO_RMPL_PXRMP2_2_POS          (10)
#define GPIO_RMPL_PXRMP2_3_POS          (11)
#define GPIO_RMPL_PXRMP3_0_POS          (12)
#define GPIO_RMPL_PXRMP3_1_POS          (13)
#define GPIO_RMPL_PXRMP3_2_POS          (14)
#define GPIO_RMPL_PXRMP3_3_POS          (15)
#define GPIO_RMPL_PXRMP4_0_POS          (16)
#define GPIO_RMPL_PXRMP4_1_POS          (17)
#define GPIO_RMPL_PXRMP4_2_POS          (18)
#define GPIO_RMPL_PXRMP4_3_POS          (19)
#define GPIO_RMPL_PXRMP5_0_POS          (20)
#define GPIO_RMPL_PXRMP5_1_POS          (21)
#define GPIO_RMPL_PXRMP5_2_POS          (22)
#define GPIO_RMPL_PXRMP5_3_POS          (23)
#define GPIO_RMPL_PXRMP6_0_POS          (24)
#define GPIO_RMPL_PXRMP6_1_POS          (25)
#define GPIO_RMPL_PXRMP6_2_POS          (26)
#define GPIO_RMPL_PXRMP6_3_POS          (27)
#define GPIO_RMPL_PXRMP7_0_POS          (28)
#define GPIO_RMPL_PXRMP7_1_POS          (29)
#define GPIO_RMPL_PXRMP7_2_POS          (30)
#define GPIO_RMPL_PXRMP7_3_POS          (31)
#define GPIO_RMPL_PXRMP0                ((uint32_t)0xF<<(GPIO_RMPL_PXRMP0_0_POS))
#define GPIO_RMPL_PXRMP0_0              ((uint32_t)1<<(GPIO_RMPL_PXRMP0_0_POS))
#define GPIO_RMPL_PXRMP0_1              ((uint32_t)1<<(GPIO_RMPL_PXRMP0_1_POS))
#define GPIO_RMPL_PXRMP0_2              ((uint32_t)1<<(GPIO_RMPL_PXRMP0_2_POS))
#define GPIO_RMPL_PXRMP0_3              ((uint32_t)1<<(GPIO_RMPL_PXRMP0_3_POS))
#define GPIO_RMPL_PXRMP1                ((uint32_t)0xF<<(GPIO_RMPL_PXRMP1_0_POS))
#define GPIO_RMPL_PXRMP1_0              ((uint32_t)1<<(GPIO_RMPL_PXRMP1_0_POS))
#define GPIO_RMPL_PXRMP1_1              ((uint32_t)1<<(GPIO_RMPL_PXRMP1_1_POS))
#define GPIO_RMPL_PXRMP1_2              ((uint32_t)1<<(GPIO_RMPL_PXRMP1_2_POS))
#define GPIO_RMPL_PXRMP1_3              ((uint32_t)1<<(GPIO_RMPL_PXRMP1_3_POS))
#define GPIO_RMPL_PXRMP2                ((uint32_t)0xF<<(GPIO_RMPL_PXRMP2_0_POS))
#define GPIO_RMPL_PXRMP2_0              ((uint32_t)1<<(GPIO_RMPL_PXRMP2_0_POS))
#define GPIO_RMPL_PXRMP2_1              ((uint32_t)1<<(GPIO_RMPL_PXRMP2_1_POS))
#define GPIO_RMPL_PXRMP2_2              ((uint32_t)1<<(GPIO_RMPL_PXRMP2_2_POS))
#define GPIO_RMPL_PXRMP2_3              ((uint32_t)1<<(GPIO_RMPL_PXRMP2_3_POS))
#define GPIO_RMPL_PXRMP3                ((uint32_t)0xF<<(GPIO_RMPL_PXRMP3_0_POS))
#define GPIO_RMPL_PXRMP3_0              ((uint32_t)1<<(GPIO_RMPL_PXRMP3_0_POS))
#define GPIO_RMPL_PXRMP3_1              ((uint32_t)1<<(GPIO_RMPL_PXRMP3_1_POS))
#define GPIO_RMPL_PXRMP3_2              ((uint32_t)1<<(GPIO_RMPL_PXRMP3_2_POS))
#define GPIO_RMPL_PXRMP3_3              ((uint32_t)1<<(GPIO_RMPL_PXRMP3_3_POS))
#define GPIO_RMPL_PXRMP4                ((uint32_t)0xF<<(GPIO_RMPL_PXRMP4_0_POS))
#define GPIO_RMPL_PXRMP4_0              ((uint32_t)1<<(GPIO_RMPL_PXRMP4_0_POS))
#define GPIO_RMPL_PXRMP4_1              ((uint32_t)1<<(GPIO_RMPL_PXRMP4_1_POS))
#define GPIO_RMPL_PXRMP4_2              ((uint32_t)1<<(GPIO_RMPL_PXRMP4_2_POS))
#define GPIO_RMPL_PXRMP4_3              ((uint32_t)1<<(GPIO_RMPL_PXRMP4_3_POS))
#define GPIO_RMPL_PXRMP5                ((uint32_t)0xF<<(GPIO_RMPL_PXRMP5_0_POS))
#define GPIO_RMPL_PXRMP5_0              ((uint32_t)1<<(GPIO_RMPL_PXRMP5_0_POS))
#define GPIO_RMPL_PXRMP5_1              ((uint32_t)1<<(GPIO_RMPL_PXRMP5_1_POS))
#define GPIO_RMPL_PXRMP5_2              ((uint32_t)1<<(GPIO_RMPL_PXRMP5_2_POS))
#define GPIO_RMPL_PXRMP5_3              ((uint32_t)1<<(GPIO_RMPL_PXRMP5_3_POS))
#define GPIO_RMPL_PXRMP6                ((uint32_t)0xF<<(GPIO_RMPL_PXRMP6_0_POS))
#define GPIO_RMPL_PXRMP6_0              ((uint32_t)1<<(GPIO_RMPL_PXRMP6_0_POS))
#define GPIO_RMPL_PXRMP6_1              ((uint32_t)1<<(GPIO_RMPL_PXRMP6_1_POS))
#define GPIO_RMPL_PXRMP6_2              ((uint32_t)1<<(GPIO_RMPL_PXRMP6_2_POS))
#define GPIO_RMPL_PXRMP6_3              ((uint32_t)1<<(GPIO_RMPL_PXRMP6_3_POS))
#define GPIO_RMPL_PXRMP7                ((uint32_t)0xF<<(GPIO_RMPL_PXRMP7_0_POS))
#define GPIO_RMPL_PXRMP7_0              ((uint32_t)1<<(GPIO_RMPL_PXRMP7_0_POS))
#define GPIO_RMPL_PXRMP7_1              ((uint32_t)1<<(GPIO_RMPL_PXRMP7_1_POS))
#define GPIO_RMPL_PXRMP7_2              ((uint32_t)1<<(GPIO_RMPL_PXRMP7_2_POS))
#define GPIO_RMPL_PXRMP7_3              ((uint32_t)1<<(GPIO_RMPL_PXRMP7_3_POS))

/* GPIO_RMPH λ�� */
#define GPIO_RMPH_PXRMP8_0_POS          (0)
#define GPIO_RMPH_PXRMP8_1_POS          (1)
#define GPIO_RMPH_PXRMP8_2_POS          (2)
#define GPIO_RMPH_PXRMP8_3_POS          (3)
#define GPIO_RMPH_PXRMP9_0_POS          (4)
#define GPIO_RMPH_PXRMP9_1_POS          (5)
#define GPIO_RMPH_PXRMP9_2_POS          (6)
#define GPIO_RMPH_PXRMP9_3_POS          (7)
#define GPIO_RMPH_PXRMP10_0_POS         (8)
#define GPIO_RMPH_PXRMP10_1_POS         (9)
#define GPIO_RMPH_PXRMP10_2_POS         (10)
#define GPIO_RMPH_PXRMP10_3_POS         (11)
#define GPIO_RMPH_PXRMP11_0_POS         (12)
#define GPIO_RMPH_PXRMP11_1_POS         (13)
#define GPIO_RMPH_PXRMP11_2_POS         (14)
#define GPIO_RMPH_PXRMP11_3_POS         (15)
#define GPIO_RMPH_PXRMP12_0_POS         (16)
#define GPIO_RMPH_PXRMP12_1_POS         (17)
#define GPIO_RMPH_PXRMP12_2_POS         (18)
#define GPIO_RMPH_PXRMP12_3_POS         (19)
#define GPIO_RMPH_PXRMP13_0_POS         (20)
#define GPIO_RMPH_PXRMP13_1_POS         (21)
#define GPIO_RMPH_PXRMP13_2_POS         (22)
#define GPIO_RMPH_PXRMP13_3_POS         (23)
#define GPIO_RMPH_PXRMP14_0_POS         (24)
#define GPIO_RMPH_PXRMP14_1_POS         (25)
#define GPIO_RMPH_PXRMP14_2_POS         (26)
#define GPIO_RMPH_PXRMP14_3_POS         (27)
#define GPIO_RMPH_PXRMP15_0_POS         (28)
#define GPIO_RMPH_PXRMP15_1_POS         (29)
#define GPIO_RMPH_PXRMP15_2_POS         (30)
#define GPIO_RMPH_PXRMP15_3_POS         (31)
#define GPIO_RMPH_PXRMP8                ((uint32_t)0xF<<(GPIO_RMPH_PXRMP8_0_POS))
#define GPIO_RMPH_PXRMP8_0              ((uint32_t)1<<(GPIO_RMPH_PXRMP8_0_POS))
#define GPIO_RMPH_PXRMP8_1              ((uint32_t)1<<(GPIO_RMPH_PXRMP8_1_POS))
#define GPIO_RMPH_PXRMP8_2              ((uint32_t)1<<(GPIO_RMPH_PXRMP8_2_POS))
#define GPIO_RMPH_PXRMP8_3              ((uint32_t)1<<(GPIO_RMPH_PXRMP8_3_POS))
#define GPIO_RMPH_PXRMP9                ((uint32_t)0xF<<(GPIO_RMPH_PXRMP9_0_POS))
#define GPIO_RMPH_PXRMP9_0              ((uint32_t)1<<(GPIO_RMPH_PXRMP9_0_POS))
#define GPIO_RMPH_PXRMP9_1              ((uint32_t)1<<(GPIO_RMPH_PXRMP9_1_POS))
#define GPIO_RMPH_PXRMP9_2              ((uint32_t)1<<(GPIO_RMPH_PXRMP9_2_POS))
#define GPIO_RMPH_PXRMP9_3              ((uint32_t)1<<(GPIO_RMPH_PXRMP9_3_POS))
#define GPIO_RMPH_PXRMP10               ((uint32_t)0xF<<(GPIO_RMPH_PXRMP10_0_POS))
#define GPIO_RMPH_PXRMP10_0             ((uint32_t)1<<(GPIO_RMPH_PXRMP10_0_POS))
#define GPIO_RMPH_PXRMP10_1             ((uint32_t)1<<(GPIO_RMPH_PXRMP10_1_POS))
#define GPIO_RMPH_PXRMP10_2             ((uint32_t)1<<(GPIO_RMPH_PXRMP10_2_POS))
#define GPIO_RMPH_PXRMP10_3             ((uint32_t)1<<(GPIO_RMPH_PXRMP10_3_POS))
#define GPIO_RMPH_PXRMP11               ((uint32_t)0xF<<(GPIO_RMPH_PXRMP11_0_POS))
#define GPIO_RMPH_PXRMP11_0             ((uint32_t)1<<(GPIO_RMPH_PXRMP11_0_POS))
#define GPIO_RMPH_PXRMP11_1             ((uint32_t)1<<(GPIO_RMPH_PXRMP11_1_POS))
#define GPIO_RMPH_PXRMP11_2             ((uint32_t)1<<(GPIO_RMPH_PXRMP11_2_POS))
#define GPIO_RMPH_PXRMP11_3             ((uint32_t)1<<(GPIO_RMPH_PXRMP11_3_POS))
#define GPIO_RMPH_PXRMP12               ((uint32_t)0xF<<(GPIO_RMPH_PXRMP12_0_POS))
#define GPIO_RMPH_PXRMP12_0             ((uint32_t)1<<(GPIO_RMPH_PXRMP12_0_POS))
#define GPIO_RMPH_PXRMP12_1             ((uint32_t)1<<(GPIO_RMPH_PXRMP12_1_POS))
#define GPIO_RMPH_PXRMP12_2             ((uint32_t)1<<(GPIO_RMPH_PXRMP12_2_POS))
#define GPIO_RMPH_PXRMP12_3             ((uint32_t)1<<(GPIO_RMPH_PXRMP12_3_POS))
#define GPIO_RMPH_PXRMP13               ((uint32_t)0xF<<(GPIO_RMPH_PXRMP13_0_POS))
#define GPIO_RMPH_PXRMP13_0             ((uint32_t)1<<(GPIO_RMPH_PXRMP13_0_POS))
#define GPIO_RMPH_PXRMP13_1             ((uint32_t)1<<(GPIO_RMPH_PXRMP13_1_POS))
#define GPIO_RMPH_PXRMP13_2             ((uint32_t)1<<(GPIO_RMPH_PXRMP13_2_POS))
#define GPIO_RMPH_PXRMP13_3             ((uint32_t)1<<(GPIO_RMPH_PXRMP13_3_POS))
#define GPIO_RMPH_PXRMP14               ((uint32_t)0xF<<(GPIO_RMPH_PXRMP14_0_POS))
#define GPIO_RMPH_PXRMP14_0             ((uint32_t)1<<(GPIO_RMPH_PXRMP14_0_POS))
#define GPIO_RMPH_PXRMP14_1             ((uint32_t)1<<(GPIO_RMPH_PXRMP14_1_POS))
#define GPIO_RMPH_PXRMP14_2             ((uint32_t)1<<(GPIO_RMPH_PXRMP14_2_POS))
#define GPIO_RMPH_PXRMP14_3             ((uint32_t)1<<(GPIO_RMPH_PXRMP14_3_POS))
#define GPIO_RMPH_PXRMP15               ((uint32_t)0xF<<(GPIO_RMPH_PXRMP15_0_POS))
#define GPIO_RMPH_PXRMP15_0             ((uint32_t)1<<(GPIO_RMPH_PXRMP15_0_POS))
#define GPIO_RMPH_PXRMP15_1             ((uint32_t)1<<(GPIO_RMPH_PXRMP15_1_POS))
#define GPIO_RMPH_PXRMP15_2             ((uint32_t)1<<(GPIO_RMPH_PXRMP15_2_POS))
#define GPIO_RMPH_PXRMP15_3             ((uint32_t)1<<(GPIO_RMPH_PXRMP15_3_POS))

/* GPIOA_CTMDCTL0 λ�� */
#define CTMDACTL0_CTAMODE0_0_POS     	(0)
#define CTMDACTL0_CTAMODE0_1_POS     	(1)
#define CTMDACTL0_CTAMODE0_2_POS     	(2)
#define CTMDACTL0_CTAMODE1_0_POS     	(3)
#define CTMDACTL0_CTAMODE1_1_POS     	(4)
#define CTMDACTL0_CTAMODE1_2_POS     	(5)
#define CTMDACTL0_CTAMODE2_0_POS     	(6)
#define CTMDACTL0_CTAMODE2_1_POS     	(7)
#define CTMDACTL0_CTAMODE2_2_POS     	(8)
#define CTMDACTL0_CTAMODE3_0_POS     	(9)
#define CTMDACTL0_CTAMODE3_1_POS     	(10)
#define CTMDACTL0_CTAMODE3_2_POS     	(11)
#define CTMDACTL0_CTAMODE4_0_POS     	(12)
#define CTMDACTL0_CTAMODE4_1_POS     	(13)
#define CTMDACTL0_CTAMODE4_2_POS     	(14)
#define CTMDACTL0_CTAMODE5_0_POS     	(15)
#define CTMDACTL0_CTAMODE5_1_POS     	(16)
#define CTMDACTL0_CTAMODE5_2_POS     	(17)
#define CTMDACTL0_CTAMODE6_0_POS     	(18)
#define CTMDACTL0_CTAMODE6_1_POS     	(19)
#define CTMDACTL0_CTAMODE6_2_POS     	(20)
#define CTMDACTL0_CTAMODE7_0_POS     	(21)
#define CTMDACTL0_CTAMODE7_1_POS     	(22)
#define CTMDACTL0_CTAMODE7_2_POS     	(23)
#define CTMDACTL0_CTAMODE8_0_POS     	(24)
#define CTMDACTL0_CTAMODE8_1_POS     	(25)
#define CTMDACTL0_CTAMODE8_2_POS     	(26)
#define CTMDACTL0_CTAMODE9_0_POS     	(27)
#define CTMDACTL0_CTAMODE9_1_POS     	(28)
#define CTMDACTL0_CTAMODE9_2_POS     	(29)
#define CTMDACTL0_CTAMODE0           	((uint32_t)0x7<<(CTMDACTL0_CTAMODE0_0_POS))
#define CTMDACTL0_CTAMODE0_0         	((uint32_t)1<<(CTMDACTL0_CTAMODE0_0_POS))
#define CTMDACTL0_CTAMODE0_1         	((uint32_t)1<<(CTMDACTL0_CTAMODE0_1_POS))
#define CTMDACTL0_CTAMODE0_2         	((uint32_t)1<<(CTMDACTL0_CTAMODE0_2_POS))
#define CTMDACTL0_CTAMODE1           	((uint32_t)0x7<<(CTMDACTL0_CTAMODE1_0_POS))
#define CTMDACTL0_CTAMODE1_0         	((uint32_t)1<<(CTMDACTL0_CTAMODE1_0_POS))
#define CTMDACTL0_CTAMODE1_1         	((uint32_t)1<<(CTMDACTL0_CTAMODE1_1_POS))
#define CTMDACTL0_CTAMODE1_2         	((uint32_t)1<<(CTMDACTL0_CTAMODE1_2_POS))
#define CTMDACTL0_CTAMODE2           	((uint32_t)0x7<<(CTMDACTL0_CTAMODE2_0_POS))
#define CTMDACTL0_CTAMODE2_0         	((uint32_t)1<<(CTMDACTL0_CTAMODE2_0_POS))
#define CTMDACTL0_CTAMODE2_1         	((uint32_t)1<<(CTMDACTL0_CTAMODE2_1_POS))
#define CTMDACTL0_CTAMODE2_2         	((uint32_t)1<<(CTMDACTL0_CTAMODE2_2_POS))
#define CTMDACTL0_CTAMODE3           	((uint32_t)0x7<<(CTMDACTL0_CTAMODE3_0_POS))
#define CTMDACTL0_CTAMODE3_0         	((uint32_t)1<<(CTMDACTL0_CTAMODE3_0_POS))
#define CTMDACTL0_CTAMODE3_1         	((uint32_t)1<<(CTMDACTL0_CTAMODE3_1_POS))
#define CTMDACTL0_CTAMODE3_2         	((uint32_t)1<<(CTMDACTL0_CTAMODE3_2_POS))
#define CTMDACTL0_CTAMODE4           	((uint32_t)0x7<<(CTMDACTL0_CTAMODE4_0_POS))
#define CTMDACTL0_CTAMODE4_0         	((uint32_t)1<<(CTMDACTL0_CTAMODE4_0_POS))
#define CTMDACTL0_CTAMODE4_1         	((uint32_t)1<<(CTMDACTL0_CTAMODE4_1_POS))
#define CTMDACTL0_CTAMODE4_2         	((uint32_t)1<<(CTMDACTL0_CTAMODE4_2_POS))
#define CTMDACTL0_CTAMODE5           	((uint32_t)0x7<<(CTMDACTL0_CTAMODE5_0_POS))
#define CTMDACTL0_CTAMODE5_0         	((uint32_t)1<<(CTMDACTL0_CTAMODE5_0_POS))
#define CTMDACTL0_CTAMODE5_1         	((uint32_t)1<<(CTMDACTL0_CTAMODE5_1_POS))
#define CTMDACTL0_CTAMODE5_2         	((uint32_t)1<<(CTMDACTL0_CTAMODE5_2_POS))
#define CTMDACTL0_CTAMODE6           	((uint32_t)0x7<<(CTMDACTL0_CTAMODE6_0_POS))
#define CTMDACTL0_CTAMODE6_0         	((uint32_t)1<<(CTMDACTL0_CTAMODE6_0_POS))
#define CTMDACTL0_CTAMODE6_1         	((uint32_t)1<<(CTMDACTL0_CTAMODE6_1_POS))
#define CTMDACTL0_CTAMODE6_2         	((uint32_t)1<<(CTMDACTL0_CTAMODE6_2_POS))
#define CTMDACTL0_CTAMODE7           	((uint32_t)0x7<<(CTMDACTL0_CTAMODE7_0_POS))
#define CTMDACTL0_CTAMODE7_0         	((uint32_t)1<<(CTMDACTL0_CTAMODE7_0_POS))
#define CTMDACTL0_CTAMODE7_1         	((uint32_t)1<<(CTMDACTL0_CTAMODE7_1_POS))
#define CTMDACTL0_CTAMODE7_2         	((uint32_t)1<<(CTMDACTL0_CTAMODE7_2_POS))
#define CTMDACTL0_CTAMODE8           	((uint32_t)0x7<<(CTMDACTL0_CTAMODE8_0_POS))
#define CTMDACTL0_CTAMODE8_0         	((uint32_t)1<<(CTMDACTL0_CTAMODE8_0_POS))
#define CTMDACTL0_CTAMODE8_1         	((uint32_t)1<<(CTMDACTL0_CTAMODE8_1_POS))
#define CTMDACTL0_CTAMODE8_2         	((uint32_t)1<<(CTMDACTL0_CTAMODE8_2_POS))
#define CTMDACTL0_CTAMODE9           	((uint32_t)0x7<<(CTMDACTL0_CTAMODE9_0_POS))
#define CTMDACTL0_CTAMODE9_0         	((uint32_t)1<<(CTMDACTL0_CTAMODE9_0_POS))
#define CTMDACTL0_CTAMODE9_1         	((uint32_t)1<<(CTMDACTL0_CTAMODE9_1_POS))
#define CTMDACTL0_CTAMODE9_2         	((uint32_t)1<<(CTMDACTL0_CTAMODE9_2_POS))

/* GPIOA_CTMDCTL1 λ�� */
#define CTMDACTL1_CTAMODE10_0_POS     	(0)
#define CTMDACTL1_CTAMODE10_1_POS     	(1)
#define CTMDACTL1_CTAMODE10_2_POS     	(2)
#define CTMDACTL1_CTAMODE11_0_POS     	(3)
#define CTMDACTL1_CTAMODE11_1_POS     	(4)
#define CTMDACTL1_CTAMODE11_2_POS     	(5)
#define CTMDACTL1_CTAMODE12_0_POS     	(6)
#define CTMDACTL1_CTAMODE12_1_POS     	(7)
#define CTMDACTL1_CTAMODE12_2_POS     	(8)
#define CTMDACTL1_CTAMODE13_0_POS     	(9)
#define CTMDACTL1_CTAMODE13_1_POS     	(10)
#define CTMDACTL1_CTAMODE13_2_POS     	(11)
#define CTMDACTL1_CTAMODE14_0_POS     	(12)
#define CTMDACTL1_CTAMODE14_1_POS     	(13)
#define CTMDACTL1_CTAMODE14_2_POS     	(14)
#define CTMDACTL1_CTAMODE15_0_POS     	(15)
#define CTMDACTL1_CTAMODE15_1_POS     	(16)
#define CTMDACTL1_CTAMODE15_2_POS     	(17)
#define CTMDACTL1_DRVCTANK_0_POS     	(20)
#define CTMDACTL1_DRVCTANK_1_POS     	(21)
#define CTMDACTL1_POLCTANK_POS     		(22)
#define CTMDACTL1_DRVCMOD_0_POS     	(24)
#define CTMDACTL1_DRVCMOD_1_POS     	(25)
#define CTMDACTL1_POLCMODE_POS     		(26)
#define CTMDACTL1_DRVPA_0_POS     		(28)
#define CTMDACTL1_DRVPA_1_POS     		(29)
#define CTMDACTL1_POLPA_POS     		(30)
#define CTMDACTL1_PABUSGDSEL_POS     	(31)
#define CTMDACTL1_CTAMODE10           	((uint32_t)0x7<<(CTMDACTL1_CTAMODE10_0_POS))
#define CTMDACTL1_CTAMODE10_0         	((uint32_t)1<<(CTMDACTL1_CTAMODE10_0_POS))
#define CTMDACTL1_CTAMODE10_1         	((uint32_t)1<<(CTMDACTL1_CTAMODE10_1_POS))
#define CTMDACTL1_CTAMODE10_2         	((uint32_t)1<<(CTMDACTL1_CTAMODE10_2_POS))
#define CTMDACTL1_CTAMODE11           	((uint32_t)0x7<<(CTMDACTL1_CTAMODE11_0_POS))
#define CTMDACTL1_CTAMODE11_0         	((uint32_t)1<<(CTMDACTL1_CTAMODE11_0_POS))
#define CTMDACTL1_CTAMODE11_1         	((uint32_t)1<<(CTMDACTL1_CTAMODE11_1_POS))
#define CTMDACTL1_CTAMODE11_2         	((uint32_t)1<<(CTMDACTL1_CTAMODE11_2_POS))
#define CTMDACTL1_CTAMODE12           	((uint32_t)0x7<<(CTMDACTL1_CTAMODE12_0_POS))
#define CTMDACTL1_CTAMODE12_0         	((uint32_t)1<<(CTMDACTL1_CTAMODE12_0_POS))
#define CTMDACTL1_CTAMODE12_1         	((uint32_t)1<<(CTMDACTL1_CTAMODE12_1_POS))
#define CTMDACTL1_CTAMODE12_2         	((uint32_t)1<<(CTMDACTL1_CTAMODE12_2_POS))
#define CTMDACTL1_CTAMODE13           	((uint32_t)0x7<<(CTMDACTL1_CTAMODE13_0_POS))
#define CTMDACTL1_CTAMODE13_0         	((uint32_t)1<<(CTMDACTL1_CTAMODE13_0_POS))
#define CTMDACTL1_CTAMODE13_1         	((uint32_t)1<<(CTMDACTL1_CTAMODE13_1_POS))
#define CTMDACTL1_CTAMODE13_2         	((uint32_t)1<<(CTMDACTL1_CTAMODE13_2_POS))
#define CTMDACTL1_CTAMODE14           	((uint32_t)0x7<<(CTMDACTL1_CTAMODE14_0_POS))
#define CTMDACTL1_CTAMODE14_0         	((uint32_t)1<<(CTMDACTL1_CTAMODE14_0_POS))
#define CTMDACTL1_CTAMODE14_1         	((uint32_t)1<<(CTMDACTL1_CTAMODE14_1_POS))
#define CTMDACTL1_CTAMODE14_2         	((uint32_t)1<<(CTMDACTL1_CTAMODE14_2_POS))
#define CTMDACTL1_CTAMODE15           	((uint32_t)0x7<<(CTMDACTL1_CTAMODE15_0_POS))
#define CTMDACTL1_CTAMODE15_0         	((uint32_t)1<<(CTMDACTL1_CTAMODE15_0_POS))
#define CTMDACTL1_CTAMODE15_1         	((uint32_t)1<<(CTMDACTL1_CTAMODE15_1_POS))
#define CTMDACTL1_CTAMODE15_2         	((uint32_t)1<<(CTMDACTL1_CTAMODE15_2_POS))
#define CTMDACTL1_DRVCTANK				((uint32_t)0x3<<(CTMDACTL1_DRVCTANK_0_POS))
#define CTMDACTL1_DRVCTANK_0			((uint32_t)1<<(CTMDACTL1_DRVCTANK_0_POS))
#define CTMDACTL1_DRVCTANK_1			((uint32_t)1<<(CTMDACTL1_DRVCTANK_1_POS))
#define CTMDACTL1_POLCTANK				((uint32_t)1<<(CTMDACTL1_POLCTANK_POS))
#define CTMDACTL1_DRVCMOD				((uint32_t)0x3<<(CTMDACTL1_DRVCMOD_0_POS))
#define CTMDACTL1_DRVCMOD_0				((uint32_t)1<<(CTMDACTL1_DRVCMOD_0_POS))
#define CTMDACTL1_DRVCMOD_1				((uint32_t)1<<(CTMDACTL1_DRVCMOD_1_POS))
#define CTMDACTL1_POLCMODE				((uint32_t)1<<(CTMDACTL1_POLCMODE_POS))
#define CTMDACTL1_DRVPA					((uint32_t)0x3<<(CTMDACTL1_DRVPA_0_POS))
#define CTMDACTL1_DRVPA_0				((uint32_t)1<<(CTMDACTL1_DRVPA_0_POS))
#define CTMDACTL1_DRVPA_1				((uint32_t)1<<(CTMDACTL1_DRVPA_1_POS))
#define CTMDACTL1_POLPA					((uint32_t)1<<(CTMDACTL1_POLPA_POS))
#define CTMDACTL1_PABUSGDSEL			((uint32_t)1<<(CTMDACTL1_PABUSGDSEL_POS))

/* GPIOD_CTMDCTL λ�� */
#define CTMDDCTL_CTDMODE2_0_POS     	(0)
#define CTMDDCTL_CTDMODE2_1_POS     	(1)
#define CTMDDCTL_CTDMODE2_2_POS     	(2)
#define CTMDDCTL_CTDMODE3_0_POS     	(3)
#define CTMDDCTL_CTDMODE3_1_POS     	(4)
#define CTMDDCTL_CTDMODE3_2_POS    	 	(5)
#define CTMDDCTL_CTDMODE4_0_POS     	(6)
#define CTMDDCTL_CTDMODE4_1_POS     	(7)
#define CTMDDCTL_CTDMODE4_2_POS     	(8)
#define CTMDDCTL_CTDMODE9_0_POS     	(9)
#define CTMDDCTL_CTDMODE9_1_POS     	(10)
#define CTMDDCTL_CTDMODE9_2_POS     	(11)
#define CTMDDCTL_CTDMODE10_0_POS     	(12)
#define CTMDDCTL_CTDMODE10_1_POS     	(13)
#define CTMDDCTL_CTDMODE10_2_POS     	(14)
#define CTMDDCTL_CTDMODE13_0_POS     	(15)
#define CTMDDCTL_CTDMODE13_1_POS     	(16)
#define CTMDDCTL_CTDMODE13_2_POS     	(17)
#define CTMDDCTL_CTDMODE14_0_POS     	(18)
#define CTMDDCTL_CTDMODE14_1_POS     	(19)
#define CTMDDCTL_CTDMODE14_2_POS     	(20)
#define CTMDDCTL_CTDMODE15_0_POS     	(21)
#define CTMDDCTL_CTDMODE15_1_POS     	(22)
#define CTMDDCTL_CTDMODE15_2_POS     	(23)
#define CTMDDCTL_DRVPD_0_POS     		(28)
#define CTMDDCTL_DRVPD_1_POS     		(29)
#define CTMDDCTL_POLPD_POS     			(30)
#define CTMDDCTL_PDBUSGDSEL_POS     	(31)
#define CTMDDCTL_CTDMODE2           	((uint32_t)0x7<<(CTMDDCTL_CTDMODE2_0_POS))
#define CTMDDCTL_CTDMODE2_0         	((uint32_t)1<<(CTMDDCTL_CTDMODE2_0_POS))
#define CTMDDCTL_CTDMODE2_1         	((uint32_t)1<<(CTMDDCTL_CTDMODE2_1_POS))
#define CTMDDCTL_CTDMODE2_2         	((uint32_t)1<<(CTMDDCTL_CTDMODE2_2_POS))
#define CTMDDCTL_CTDMODE3           	((uint32_t)0x7<<(CTMDDCTL_CTDMODE3_0_POS))
#define CTMDDCTL_CTDMODE3_0         	((uint32_t)1<<(CTMDDCTL_CTDMODE3_0_POS))
#define CTMDDCTL_CTDMODE3_1         	((uint32_t)1<<(CTMDDCTL_CTDMODE3_1_POS))
#define CTMDDCTL_CTDMODE3_2         	((uint32_t)1<<(CTMDDCTL_CTDMODE3_2_POS))
#define CTMDDCTL_CTDMODE4           	((uint32_t)0x7<<(CTMDDCTL0_CTDMODE4_0_POS))
#define CTMDDCTL_CTDMODE4_0         	((uint32_t)1<<(CTMDDCTL_CTDMODE4_0_POS))
#define CTMDDCTL_CTDMODE4_1         	((uint32_t)1<<(CTMDDCTL_CTDMODE4_1_POS))
#define CTMDDCTL_CTDMODE4_2         	((uint32_t)1<<(CTMDDCTL_CTDMODE4_2_POS))
#define CTMDDCTL_CTDMODE5           	((uint32_t)0x7<<(CTMDDCTL_CTDMODE9_0_POS))
#define CTMDDCTL_CTDMODE5_0         	((uint32_t)1<<(CTMDDCTL_CTDMODE9_0_POS))
#define CTMDDCTL_CTDMODE5_1         	((uint32_t)1<<(CTMDDCTL_CTDMODE9_1_POS))
#define CTMDDCTL_CTDMODE5_2         	((uint32_t)1<<(CTMDDCTL_CTDMODE9_2_POS))
#define CTMDDCTL_CTDMODE10           	((uint32_t)0x7<<(CTMDDCTL_CTDMODE10_0_POS))
#define CTMDDCTL_CTDMODE10_0         	((uint32_t)1<<(CTMDDCTL_CTDMODE10_0_POS))
#define CTMDDCTL_CTDMODE10_1         	((uint32_t)1<<(CTMDDCTL_CTDMODE10_1_POS))
#define CTMDDCTL_CTDMODE10_2         	((uint32_t)1<<(CTMDDCTL_CTDMODE10_2_POS))
#define CTMDDCTL_CTDMODE13           	((uint32_t)0x7<<(CTMDDCTL_CTDMODE13_0_POS))
#define CTMDDCTL_CTDMODE13_0         	((uint32_t)1<<(CTMDDCTL_CTDMODE13_0_POS))
#define CTMDDCTL_CTDMODE13_1         	((uint32_t)1<<(CTMDDCTL_CTDMODE13_1_POS))
#define CTMDDCTL_CTDMODE13_2         	((uint32_t)1<<(CTMDDCTL_CTDMODE13_2_POS))
#define CTMDDCTL_CTDMODE14           	((uint32_t)0x7<<(CTMDDCTL_CTDMODE14_0_POS))
#define CTMDDCTL_CTDMODE14_0         	((uint32_t)1<<(CTMDDCTL_CTDMODE14_0_POS))
#define CTMDDCTL_CTDMODE14_1         	((uint32_t)1<<(CTMDDCTL_CTDMODE14_1_POS))
#define CTMDDCTL_CTDMODE14_2         	((uint32_t)1<<(CTMDDCTL_CTDMODE14_2_POS))
#define CTMDDCTL_CTDMODE15           	((uint32_t)0x7<<(CTMDDCTL_CTDMODE15_0_POS))
#define CTMDDCTL_CTDMODE15_0         	((uint32_t)1<<(CTMDDCTL_CTDMODE15_0_POS))
#define CTMDDCTL_CTDMODE15_1         	((uint32_t)1<<(CTMDDCTL_CTDMODE15_1_POS))
#define CTMDDCTL_CTDMODE15_2         	((uint32_t)1<<(CTMDDCTL_CTDMODE15_2_POS))
#define CTMDDCTL_DRVPD           		((uint32_t)0x3<<(CTMDDCTL_DRVPD_0_POS))
#define CTMDDCTL_DRVPD_0         		((uint32_t)1<<(CTMDDCTL_DRVPD_0_POS))
#define CTMDDCTL_DRVPD_1         		((uint32_t)1<<(CTMDDCTL_DRVPD_1_POS))
#define CTMDDCTL_POLPD		           	((uint32_t)1<<(CTMDDCTL_POLPD_POS))
#define CTMDDCTL_PDBUSGDSEL         	((uint32_t)1<<(CTMDDCTL_PDBUSGDSEL_POS))

/* GPIOE_CTMDCTL λ�� */
#define CTMDECTL_CTEMODE0_0_POS     	(0)
#define CTMDECTL_CTEMODE0_1_POS     	(1)
#define CTMDECTL_CTEMODE0_2_POS     	(2)
#define CTMDECTL_CTEMODE1_0_POS     	(3)
#define CTMDECTL_CTEMODE1_1_POS     	(4)
#define CTMDECTL_CTEMODE1_2_POS    	 	(5)
#define CTMDECTL_CTEMODE2_0_POS     	(6)
#define CTMDECTL_CTEMODE2_1_POS     	(7)
#define CTMDECTL_CTEMODE2_2_POS     	(8)
#define CTMDECTL_CTEMODE6_0_POS     	(18)
#define CTMDECTL_CTEMODE6_1_POS     	(19)
#define CTMDECTL_CTEMODE6_2_POS     	(20)
#define CTMDECTL_DRVPE_0_POS     		(28)
#define CTMDECTL_DRVPE_1_POS     		(29)
#define CTMDECTL_POLPE_POS     			(30)
#define CTMDECTL_PEBUSGDSEL_POS     	(31)
#define CTMDECTL_CTEMODE0           	((uint32_t)0x7<<(CTMDECTL_CTEMODE0_0_POS))
#define CTMDECTL_CTEMODE0_0         	((uint32_t)1<<(CTMDECTL_CTEMODE0_0_POS))
#define CTMDECTL_CTEMODE0_1         	((uint32_t)1<<(CTMDECTL_CTEMODE0_1_POS))
#define CTMDECTL_CTEMODE0_2         	((uint32_t)1<<(CTMDECTL_CTEMODE0_2_POS))
#define CTMDECTL_CTEMODE1           	((uint32_t)0x7<<(CTMDECTL_CTEMODE1_0_POS))
#define CTMDECTL_CTEMODE1_0         	((uint32_t)1<<(CTMDECTL_CTEMODE1_0_POS))
#define CTMDECTL_CTEMODE1_1         	((uint32_t)1<<(CTMDECTL_CTEMODE1_0_POS))
#define CTMDECTL_CTEMODE1_2         	((uint32_t)1<<(CTMDECTL_CTEMODE1_0_POS))
#define CTMDECTL_CTEMODE2           	((uint32_t)0x7<<(CTMDECTL_CTEMODE2_0_POS))
#define CTMDECTL_CTEMODE2_0         	((uint32_t)1<<(CTMDECTL_CTEMODE2_0_POS))
#define CTMDECTL_CTEMODE2_1         	((uint32_t)1<<(CTMDECTL_CTEMODE2_0_POS))
#define CTMDECTL_CTEMODE2_2         	((uint32_t)1<<(CTMDECTL_CTEMODE2_0_POS))
#define CTMDECTL_CTEMODE6           	((uint32_t)0x7<<(CTMDECTL_CTEMODE6_0_POS))
#define CTMDECTL_CTEMODE6_0         	((uint32_t)1<<(CTMDECTL_CTEMODE6_0_POS))
#define CTMDECTL_CTEMODE6_1         	((uint32_t)1<<(CTMDECTL_CTEMODE6_1_POS))
#define CTMDECTL_CTEMODE6_2         	((uint32_t)1<<(CTMDECTL_CTEMODE6_2_POS))
#define CTMDECTL_DRVPE           		((uint32_t)0x3<<(CTMDECTL_DRVPE_0_POS))
#define CTMDECTL_DRVPE_0         		((uint32_t)1<<(CTMDECTL_DRVPE_0_POS))
#define CTMDECTL_DRVPE_1         		((uint32_t)1<<(CTMDECTL_DRVE_1_POS))
#define CTMDECTL_POLPE		           	((uint32_t)1<<(CTMDECTL_POLPE_POS))
#define CTMDECTL_PEBUSGDSEL         	((uint32_t)1<<(CTMDECTL_PEBUSGDSEL_POS))

/* GPIOH_CTMDCTL λ�� */
#define CTMDHCTL_CTEMODH5_0_POS     	(0)
#define CTMDHCTL_CTEMODH5_1_POS     	(1)
#define CTMDHCTL_CTEMODH5_2_POS     	(2)
#define CTMDHCTL_CTEMODH6_0_POS     	(3)
#define CTMDHCTL_CTEMODH6_1_POS     	(4)
#define CTMDHCTL_CTEMODH6_2_POS    	 	(5)
#define CTMDHCTL_CTEMODH10_0_POS     	(6)
#define CTMDHCTL_CTEMODH10_1_POS     	(7)
#define CTMDHCTL_CTEMODH10_2_POS     	(8)
#define CTMDHCTL_CTEMODH11_0_POS     	(9)
#define CTMDHCTL_CTEMODH11_1_POS     	(10)
#define CTMDHCTL_CTEMODH11_2_POS     	(11)
#define CTMDHCTL_CTEMODH12_0_POS     	(12)
#define CTMDHCTL_CTEMODH12_1_POS     	(13)
#define CTMDHCTL_CTEMODH12_2_POS     	(14)
#define CTMDHCTL_CTEMODH13_0_POS     	(15)
#define CTMDHCTL_CTEMODH13_1_POS     	(16)
#define CTMDHCTL_CTEMODH13_2_POS     	(17)
#define CTMDHCTL_CTEMODH15_0_POS     	(21)
#define CTMDHCTL_CTEMODH15_1_POS     	(22)
#define CTMDHCTL_CTEMODH15_2_POS     	(23)
#define CTMDHCTL_DRVPH_0_POS     		(28)
#define CTMDHCTL_DRVPH_1_POS     		(29)
#define CTMDHCTL_POLPH_POS     			(30)
#define CTMDHCTL_PHBUSGDSEL_POS     	(31)
#define CTMDHCTL_CTHMODE5           	((uint32_t)0x7<<(CTMDHCTL_CTHMODE5_0_POS))
#define CTMDHCTL_CTHMODE5_0         	((uint32_t)1<<(CTMDHCTL_CTHMODE5_0_POS))
#define CTMDHCTL_CTHMODE5_1         	((uint32_t)1<<(CTMDHCTL_CTHMODE5_1_POS))
#define CTMDHCTL_CTHMODE5_2         	((uint32_t)1<<(CTMDHCTL_CTHMODE5_2_POS))
#define CTMDHCTL_CTHMODE6           	((uint32_t)0x7<<(CTMDHCTL_CTHMODE6_0_POS))
#define CTMDHCTL_CTHMODE6_0         	((uint32_t)1<<(CTMDHCTL_CTHMODE6_0_POS))
#define CTMDHCTL_CTHMODE6_1         	((uint32_t)1<<(CTMDHCTL_CTHMODE6_1_POS))
#define CTMDHCTL_CTHMODE6_2         	((uint32_t)1<<(CTMDHCTL_CTHMODE6_2_POS))
#define CTMDHCTL_CTHMODE10           	((uint32_t)0x7<<(CTMDHCTL_CTHMODE10_0_POS))
#define CTMDHCTL_CTHMODE10_0         	((uint32_t)1<<(CTMDHCTL_CTHMODE10_0_POS))
#define CTMDHCTL_CTHMODE10_1         	((uint32_t)1<<(CTMDHCTL_CTHMODE10_0_POS))
#define CTMDHCTL_CTHMODE10_2         	((uint32_t)1<<(CTMDHCTL_CTHMODE10_0_POS))
#define CTMDHCTL_CTHMODE11           	((uint32_t)0x7<<(CTMDHCTL_CTHMODE11_0_POS))
#define CTMDHCTL_CTHMODE11_0         	((uint32_t)1<<(CTMDHCTL_CTHMODE11_0_POS))
#define CTMDHCTL_CTHMODE11_1         	((uint32_t)1<<(CTMDHCTL_CTHMODE11_0_POS))
#define CTMDHCTL_CTHMODE11_2         	((uint32_t)1<<(CTMDHCTL_CTHMODE11_0_POS))
#define CTMDHCTL_CTHMODE12           	((uint32_t)0x7<<(CTMDHCTL_CTHMODE12_0_POS))
#define CTMDHCTL_CTHMODE12_0         	((uint32_t)1<<(CTMDHCTL_CTHMODE12_0_POS))
#define CTMDHCTL_CTHMODE12_1         	((uint32_t)1<<(CTMDHCTL_CTHMODE12_0_POS))
#define CTMDHCTL_CTHMODE12_2         	((uint32_t)1<<(CTMDHCTL_CTHMODE12_0_POS))
#define CTMDHCTL_CTHMODE13           	((uint32_t)0x7<<(CTMDHCTL_CTHMODE13_0_POS))
#define CTMDHCTL_CTHMODE13_0         	((uint32_t)1<<(CTMDHCTL_CTHMODE13_0_POS))
#define CTMDHCTL_CTHMODE13_1         	((uint32_t)1<<(CTMDHCTL_CTHMODE13_1_POS))
#define CTMDHCTL_CTHMODE13_2         	((uint32_t)1<<(CTMDHCTL_CTHMODE13_2_POS))
#define CTMDHCTL_CTHMODE14           	((uint32_t)0x7<<(CTMDHCTL_CTHMODE14_0_POS))
#define CTMDHCTL_CTHMODE14_0         	((uint32_t)1<<(CTMDHCTL_CTHMODE14_0_POS))
#define CTMDHCTL_CTHMODE14_1         	((uint32_t)1<<(CTMDHCTL_CTHMODE14_1_POS))
#define CTMDHCTL_CTHMODE14_2         	((uint32_t)1<<(CTMDHCTL_CTHMODE14_2_POS))
#define CTMDHCTL_CTHMODE15           	((uint32_t)0x7<<(CTMDHCTL_CTHMODE15_0_POS))
#define CTMDHCTL_CTHMODE15_0         	((uint32_t)1<<(CTMDHCTL_CTHMODE15_0_POS))
#define CTMDHCTL_CTHMODE15_1         	((uint32_t)1<<(CTMDHCTL_CTHMODE15_1_POS))
#define CTMDHCTL_CTHMODE15_2         	((uint32_t)1<<(CTMDHCTL_CTHMODE15_2_POS))
#define CTMDHCTL_DRVPH           		((uint32_t)0x3<<(CTMDHCTL_DRVPH_0_POS))
#define CTMDHCTL_DRVPH_0         		((uint32_t)1<<(CTMDHCTL_DRVPH_0_POS))
#define CTMDHCTL_DRVPH_1         		((uint32_t)1<<(CTMDHCTL_DRVPH_1_POS))
#define CTMDHCTL_POLPH		           	((uint32_t)1<<(CTMDHCTL_POLPH_POS))
#define CTMDHCTL_PEBUSGDSHL         	((uint32_t)1<<(CTMDHCTL_PHBUSGDSEL_POS))

/* GPIOB_UHS λ�� */
#define GPIOB_UHS_UHSEN0_POS          (0)
#define GPIOB_UHS_UHSEN1_POS          (1)
#define GPIOB_UHS_UHSEN2_POS          (2)
#define GPIOB_UHS_UHSEN3_POS          (3)
#define GPIOB_UHS_UHSEN               ((uint32_t)0xF<<(GPIOB_UHS_UHSEN0_POS))
#define GPIOB_UHS_UHSEN0              ((uint32_t)1<<(GPIOB_UHS_UHSEN0_POS))
#define GPIOB_UHS_UHSEN1              ((uint32_t)1<<(GPIOB_UHS_UHSEN1_POS))
#define GPIOB_UHS_UHSEN2              ((uint32_t)1<<(GPIOB_UHS_UHSEN2_POS))
#define GPIOB_UHS_UHSEN3              ((uint32_t)1<<(GPIOB_UHS_UHSEN3_POS))
/* ͨ����������˿�(GPIO)������� */


/* ----------------------------------------------------------------------------
   -- ����(OSC)
   ---------------------------------------------------------------------------- */

/* OSC - ����Ĵ����ڴ�ṹ */
typedef struct OSC_MemMap {
    volatile uint32_t CTL0;             /* �������ƼĴ���0, ƫ��:0x00 */
    volatile uint32_t CTL1;             /* �������ƼĴ���1, ƫ��:0x04 */
    volatile uint32_t INT;              /* �����жϿ��ƼĴ���, ƫ��:0x08 */
    volatile uint32_t CTL2;             /* �������ƼĴ���2, ƫ��:0x0C */
    volatile uint32_t HFOSCCAL0;        /* ��Ƶ����У׼�Ĵ���0, ƫ��:0x10 */
    volatile uint32_t HFOSCCAL1;        /* ��Ƶ����У׼�Ĵ���1, ƫ��:0x14 */
}OSC_SFRmap;

/* PLL - ����Ĵ����ڴ�ṹ */
typedef struct PLL_MemMap {
	  volatile uint32_t CTL;            /* PLL���ƼĴ���0, ƫ��:0x00 */
}PLL_SFRmap;

/* ----------------------------------------------------------------------------
   -- OSC - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* OSC - �Ĵ�����ڵ�ַ */
#define OSC_ADDR                        ((uint32_t)0x40000000)
#define OSC_SFR                         ((OSC_SFRmap *) OSC_ADDR)
#define PLL_ADDR                        ((uint32_t)0x40002580)
#define PLL_SFR                         ((PLL_SFRmap *) PLL_ADDR)

/* OSC - �Ĵ������ */
#define OSC_CTL0                        (OSC_SFR->CTL0)
#define OSC_CTL1                        (OSC_SFR->CTL1)
#define OSC_INT                         (OSC_SFR->INT)
#define OSC_CTL2                        (OSC_SFR->CTL2)
#define OSC_HFOSCCAL0                   (OSC_SFR->HFOSCCAL0)
#define OSC_HFOSCCAL1                   (OSC_SFR->HFOSCCAL1)
#define PLL_CTL                         (PLL_SFR->CTL)

/* OSC_CTL0 λ�� */
#define OSC_CTL0_PMWREN_POS             (0)
#define OSC_CTL0_SCKS0_POS              (1)
#define OSC_CTL0_SCKS1_POS              (2)
#define OSC_CTL0_SCKS2_POS              (3)
#define OSC_CTL0_LFCKEN_POS             (4)
#define OSC_CTL0_LFCKS_POS              (6)
#define OSC_CTL0_HFCKEN_POS             (8)
#define OSC_CTL0_HFCKS0_POS             (9)
#define OSC_CTL0_HFCKS1_POS             (10)
#define OSC_CTL0_HFCKS2_POS             (11)
#define OSC_CTL0_PLL0CKS_POS            (12)
#define OSC_CTL0_SCKDIV0_POS            (16)
#define OSC_CTL0_SCKDIV1_POS            (17)
#define OSC_CTL0_SCKDIV2_POS            (18)
#define OSC_CTL0_HFCKDIV0_POS           (20)
#define OSC_CTL0_HFCKDIV1_POS           (21)
#define OSC_CTL0_HFCKDIV2_POS           (22)
#define OSC_CTL0_HFCKDIV3_POS           (23)
#define OSC_CTL0_LFCKDIV0_POS           (24)
#define OSC_CTL0_LFCKDIV1_POS           (25)
#define OSC_CTL0_LFCKDIV2_POS           (26)
#define OSC_CTL0_PMWREN                 ((uint32_t)1<<(OSC_CTL0_PMWREN_POS))
#define OSC_CTL0_SCKS                   ((uint32_t)7<<(OSC_CTL0_SCKS0_POS))
#define OSC_CTL0_SCKS0                  ((uint32_t)1<<(OSC_CTL0_SCKS0_POS))
#define OSC_CTL0_SCKS1                  ((uint32_t)1<<(OSC_CTL0_SCKS1_POS))
#define OSC_CTL0_SCKS2                  ((uint32_t)1<<(OSC_CTL0_SCKS2_POS))
#define OSC_CTL0_LFCKEN                 ((uint32_t)1<<(OSC_CTL0_LFCKEN_POS))
#define OSC_CTL0_LFCKS                  ((uint32_t)1<<(OSC_CTL0_LFCKS_POS))
#define OSC_CTL0_HFCKEN                 ((uint32_t)1<<(OSC_CTL0_HFCKEN_POS))
#define OSC_CTL0_HFCKS                  ((uint32_t)7<<(OSC_CTL0_HFCKS0_POS))
#define OSC_CTL0_HFCKS0                 ((uint32_t)1<<(OSC_CTL0_HFCKS0_POS))
#define OSC_CTL0_HFCKS1                 ((uint32_t)1<<(OSC_CTL0_HFCKS1_POS))
#define OSC_CTL0_HFCKS2                 ((uint32_t)1<<(OSC_CTL0_HFCKS2_POS))
#define OSC_CTL0_PLL0CKS                ((uint32_t)1<<(OSC_CTL0_PLL0CKS_POS))
#define OSC_CTL0_SCKDIV                 ((uint32_t)7<<(OSC_CTL0_SCKDIV0_POS))
#define OSC_CTL0_SCKDIV0                ((uint32_t)1<<(OSC_CTL0_SCKDIV0_POS))
#define OSC_CTL0_SCKDIV1                ((uint32_t)1<<(OSC_CTL0_SCKDIV1_POS))
#define OSC_CTL0_SCKDIV2                ((uint32_t)1<<(OSC_CTL0_SCKDIV2_POS))
#define OSC_CTL0_HFCKDIV                ((uint32_t)0xF<<(OSC_CTL0_HFCKDIV0_POS))
#define OSC_CTL0_HFCKDIV0               ((uint32_t)1<<(OSC_CTL0_HFCKDIV0_POS))
#define OSC_CTL0_HFCKDIV1               ((uint32_t)1<<(OSC_CTL0_HFCKDIV1_POS))
#define OSC_CTL0_HFCKDIV2               ((uint32_t)1<<(OSC_CTL0_HFCKDIV2_POS))
#define OSC_CTL0_HFCKDIV3               ((uint32_t)1<<(OSC_CTL0_HFCKDIV3_POS))
#define OSC_CTL0_LFCKDIV                ((uint32_t)7<<(OSC_CTL0_LFCKDIV0_POS))
#define OSC_CTL0_LFCKDIV0               ((uint32_t)1<<(OSC_CTL0_LFCKDIV0_POS))
#define OSC_CTL0_LFCKDIV1               ((uint32_t)1<<(OSC_CTL0_LFCKDIV1_POS))
#define OSC_CTL0_LFCKDIV2               ((uint32_t)1<<(OSC_CTL0_LFCKDIV2_POS))

/* OSC_CTL1 λ�� */
#define OSC_CTL1_CK48MEN_POS            (0)
#define OSC_CTL1_CK48MS0_POS            (1)
#define OSC_CTL1_CK48MS1_POS            (2)
#define OSC_CTL1_CK48MS2_POS            (3)
#define OSC_CTL1_CK48DIV0_POS           (4)
#define OSC_CTL1_CK48DIV1_POS           (5)
#define OSC_CTL1_FSCM_POS               (16)
#define OSC_CTL1_CLKOUTS0_POS           (25)
#define OSC_CTL1_CLKOUTS1_POS           (26)
#define OSC_CTL1_CLKOUTS2_POS           (27)
#define OSC_CTL1_SCLKOE_POS             (28)
#define OSC_CTL1_SCLKOUTDIV0_POS        (29)
#define OSC_CTL1_SCLKOUTDIV1_POS        (30)
#define OSC_CTL1_SCLKOUTDIV2_POS        (31)
#define OSC_CTL1_CK48MEN                ((uint32_t)1<<(OSC_CTL1_CK48MEN_POS))
#define OSC_CTL1_CK48MS                 ((uint32_t)7<<(OSC_CTL1_CK48MS0_POS))
#define OSC_CTL1_CK48MS0                ((uint32_t)1<<(OSC_CTL1_CK48MS0_POS))
#define OSC_CTL1_CK48MS1                ((uint32_t)1<<(OSC_CTL1_CK48MS1_POS))
#define OSC_CTL1_CK48MS2                ((uint32_t)1<<(OSC_CTL1_CK48MS2_POS))
#define OSC_CTL1_CK48DIV                ((uint32_t)3<<(OSC_CTL1_CK48DIV0_POS))
#define OSC_CTL1_CK48DIV0               ((uint32_t)1<<(OSC_CTL1_CK48DIV0_POS))
#define OSC_CTL1_CK48DIV1               ((uint32_t)1<<(OSC_CTL1_CK48DIV1_POS))
#define OSC_CTL1_CLKOUTS                ((uint32_t)0X7<<(OSC_CTL1_CLKOUTS0_POS))
#define OSC_CTL1_CLKOUTS0               ((uint32_t)1<<(OSC_CTL1_CLKOUTS0_POS))
#define OSC_CTL1_CLKOUTS1               ((uint32_t)1<<(OSC_CTL1_CLKOUTS1_POS))
#define OSC_CTL1_CLKOUTS2               ((uint32_t)1<<(OSC_CTL1_CLKOUTS2_POS))
#define OSC_CTL1_FSCM                   ((uint32_t)1<<(OSC_CTL1_FSCM_POS))
#define OSC_CTL1_SCLKOE                 ((uint32_t)1<<(OSC_CTL1_SCLKOE_POS))
#define OSC_CTL1_SCLKOUTDIV             ((uint32_t)7<<(OSC_CTL1_SCLKOUTDIV0_POS))
#define OSC_CTL1_SCLKOUTDIV0            ((uint32_t)1<<(OSC_CTL1_SCLKOUTDIV0_POS))
#define OSC_CTL1_SCLKOUTDIV1            ((uint32_t)1<<(OSC_CTL1_SCLKOUTDIV1_POS))
#define OSC_CTL1_SCLKOUTDIV2            ((uint32_t)1<<(OSC_CTL1_SCLKOUTDIV2_POS))

/* OSC_INT λ�� */
#define OSC_INT_ILFIF_POS               (0)
#define OSC_INT_IHFIF_POS               (1)
#define OSC_INT_ELFIF_POS               (2)
#define OSC_INT_EHFIF_POS               (3)
#define OSC_INT_PLLIF_POS               (4)
#define OSC_INT_LP4MIF_POS              (6)
#define OSC_INT_CKFIF_POS               (7)
#define OSC_INT_ILFIE_POS               (8)
#define OSC_INT_IHFIE_POS               (9)
#define OSC_INT_ELFIE_POS               (10)
#define OSC_INT_EHFIE_POS               (11)
#define OSC_INT_PLLIE_POS               (12)
#define OSC_INT_LP4MIE_POS              (14)
#define OSC_INT_ILFIF                   ((uint32_t)1<<(OSC_INT_ILFIF_POS))
#define OSC_INT_IHFIF                   ((uint32_t)1<<(OSC_INT_IHFIF_POS))
#define OSC_INT_ELFIF                   ((uint32_t)1<<(OSC_INT_ELFIF_POS))
#define OSC_INT_EHFIF                   ((uint32_t)1<<(OSC_INT_EHFIF_POS))
#define OSC_INT_PLLIF                   ((uint32_t)1<<(OSC_INT_PLLIF_POS))
#define OSC_INT_LP4MIF                  ((uint32_t)1<<(OSC_INT_LP4MIF_POS))
#define OSC_INT_CKFIF                   ((uint32_t)1<<(OSC_INT_CKFIF_POS))
#define OSC_INT_ILFIE                   ((uint32_t)1<<(OSC_INT_ILFIE_POS))
#define OSC_INT_IHFIE                   ((uint32_t)1<<(OSC_INT_IHFIE_POS))
#define OSC_INT_ELFIE                   ((uint32_t)1<<(OSC_INT_ELFIE_POS))
#define OSC_INT_EHFIE                   ((uint32_t)1<<(OSC_INT_EHFIE_POS))
#define OSC_INT_PLLIE                   ((uint32_t)1<<(OSC_INT_PLLIE_POS))
#define OSC_INT_LP4MIE                  ((uint32_t)1<<(OSC_INT_LP4MIE_POS))

/* OSC_CTL2 λ�� */
#define OSC_CTL2_INTLFSWEN_POS          (0)
#define OSC_CTL2_INTHFSWEN_POS          (1)
#define OSC_CTL2_EXTLFSWEN_POS          (2)
#define OSC_CTL2_EXTHFSWEN_POS          (3)
#define OSC_CTL2_PLLSWEN_POS            (4)
#define OSC_CTL2_LP4MSWEN_POS           (6)
#define OSC_CTL2_ELFDLY0_POS            (16)
#define OSC_CTL2_ELFDLY1_POS            (17)
#define OSC_CTL2_ELFDLY2_POS            (18)
#define OSC_CTL2_ELFDLY3_POS            (19)
#define OSC_CTL2_EHFDLY0_POS            (20)
#define OSC_CTL2_EHFDLY1_POS            (21)
#define OSC_CTL2_EHFDLY2_POS            (22)
#define OSC_CTL2_EHFDLY3_POS            (23)
#define OSC_CTL2_PLLDLY0_POS            (24)
#define OSC_CTL2_PLLDLY1_POS            (25)
#define OSC_CTL2_PLLDLY2_POS            (26)
#define OSC_CTL2_PLLDLY3_POS            (27)
#define OSC_CTL2_INTLFSWEN              ((uint32_t)1<<(OSC_CTL2_INTLFSWEN_POS))
#define OSC_CTL2_INTHFSWEN              ((uint32_t)1<<(OSC_CTL2_INTHFSWEN_POS))
#define OSC_CTL2_EXTLFSWEN              ((uint32_t)1<<(OSC_CTL2_EXTLFSWEN_POS))
#define OSC_CTL2_EXTHFSWEN              ((uint32_t)1<<(OSC_CTL2_EXTHFSWEN_POS))
#define OSC_CTL2_PLLSWEN                ((uint32_t)1<<(OSC_CTL2_PLL0SWEN_POS))
#define OSC_CTL2_LP4MSWEN               ((uint32_t)1<<(OSC_CTL2_LP4MSWEN_POS))
#define OSC_CTL2_ELFDLY                 ((uint32_t)0xF<<(OSC_CTL2_ELFDLY0_POS))
#define OSC_CTL2_ELFDLY0                ((uint32_t)1<<(OSC_CTL2_ELFDLY0_POS))
#define OSC_CTL2_ELFDLY1                ((uint32_t)1<<(OSC_CTL2_ELFDLY1_POS))
#define OSC_CTL2_ELFDLY2                ((uint32_t)1<<(OSC_CTL2_ELFDLY2_POS))
#define OSC_CTL2_ELFDLY3                ((uint32_t)1<<(OSC_CTL2_ELFDLY3_POS))
#define OSC_CTL2_EHFDLY                 ((uint32_t)0xF<<(OSC_CTL2_EHFDLY0_POS))
#define OSC_CTL2_EHFDLY0                ((uint32_t)1<<(OSC_CTL2_EHFDLY0_POS))
#define OSC_CTL2_EHFDLY1                ((uint32_t)1<<(OSC_CTL2_EHFDLY1_POS))
#define OSC_CTL2_EHFDLY2                ((uint32_t)1<<(OSC_CTL2_EHFDLY2_POS))
#define OSC_CTL2_EHFDLY3                ((uint32_t)1<<(OSC_CTL2_EHFDLY3_POS))
#define OSC_CTL2_PLLDLY                 ((uint32_t)0xF<<(OSC_CTL2_PLLDLY0_POS))
#define OSC_CTL2_PLLDLY0                ((uint32_t)1<<(OSC_CTL2_PLLDLY0_POS))
#define OSC_CTL2_PLLDLY1                ((uint32_t)1<<(OSC_CTL2_PLLDLY1_POS))
#define OSC_CTL2_PLLDLY2                ((uint32_t)1<<(OSC_CTL2_PLLDLY2_POS))
#define OSC_CTL2_PLLDLY3                ((uint32_t)1<<(OSC_CTL2_PLLDLY3_POS))

/* OSC_HFOSCCAL0 λ�� */
#define OSC_HFOSCCAL0_CTAT0_POS         (0)
#define OSC_HFOSCCAL0_CTAT1_POS         (1)
#define OSC_HFOSCCAL0_CTAT2_POS         (2)
#define OSC_HFOSCCAL0_CTAT3_POS         (3)
#define OSC_HFOSCCAL0_CTAT4_POS         (4)
#define OSC_HFOSCCAL0_PTAT0_POS         (5)
#define OSC_HFOSCCAL0_PTAT1_POS         (6)
#define OSC_HFOSCCAL0_PTAT2_POS         (7)
#define OSC_HFOSCCAL0_PTAT3_POS         (8)
#define OSC_HFOSCCAL0_PTAT4_POS         (9)
#define OSC_HFOSCCAL0_SCALEDIV32_POS    (17)
#define OSC_HFOSCCAL0_SCALEDIV16_POS    (18)
#define OSC_HFOSCCAL0_SCALEDIV8_POS     (19)
#define OSC_HFOSCCAL0_SCALEDIV4_POS     (20)
#define OSC_HFOSCCAL0_SCALEDIV2_POS     (21)
#define OSC_HFOSCCAL0_SCALE1X_POS       (22)
#define OSC_HFOSCCAL0_SCALE2X_POS       (23)
#define OSC_HFOSCCAL0_SCALE4X_POS       (24)
#define OSC_HFOSCCAL0_SCALE8X_POS       (25)
#define OSC_HFOSCCAL0_SCALE16X0_POS     (26)
#define OSC_HFOSCCAL0_SCALE16X1_POS     (27)
#define OSC_HFOSCCAL0_SCALE16X2_POS     (28)
#define OSC_HFOSCCAL0_SCALE16X3_POS     (29)
#define OSC_HFOSCCAL0_SCALE16X4_POS     (30)
#define OSC_HFOSCCAL0_SCALE32X_POS      (31)
#define OSC_HFOSCCAL0_CTAT              ((uint32_t)0x1F<<(OSC_HFOSCCAL0_CTAT0_POS))
#define OSC_HFOSCCAL0_CTAT0             ((uint32_t)1<<(OSC_HFOSCCAL0_CTAT0_POS))
#define OSC_HFOSCCAL0_CTAT1             ((uint32_t)1<<(OSC_HFOSCCAL0_CTAT1_POS))
#define OSC_HFOSCCAL0_CTAT2             ((uint32_t)1<<(OSC_HFOSCCAL0_CTAT2_POS))
#define OSC_HFOSCCAL0_CTAT3             ((uint32_t)1<<(OSC_HFOSCCAL0_CTAT3_POS))
#define OSC_HFOSCCAL0_CTAT4             ((uint32_t)1<<(OSC_HFOSCCAL0_CTAT4_POS))
#define OSC_HFOSCCAL0_PTAT              ((uint32_t)0x1F<<(OSC_HFOSCCAL0_PTAT0_POS))
#define OSC_HFOSCCAL0_PTAT0             ((uint32_t)1<<(OSC_HFOSCCAL0_PTAT0_POS))
#define OSC_HFOSCCAL0_PTAT1             ((uint32_t)1<<(OSC_HFOSCCAL0_PTAT1_POS))
#define OSC_HFOSCCAL0_PTAT2             ((uint32_t)1<<(OSC_HFOSCCAL0_PTAT2_POS))
#define OSC_HFOSCCAL0_PTAT3             ((uint32_t)1<<(OSC_HFOSCCAL0_PTAT3_POS))
#define OSC_HFOSCCAL0_PTAT4             ((uint32_t)1<<(OSC_HFOSCCAL0_PTAT4_POS))
#define OSC_HFOSCCAL0_SCALEDIV32        ((uint32_t)1<<(OSC_HFOSCCAL0_SCALEDIV32_POS))
#define OSC_HFOSCCAL0_SCALEDIV16        ((uint32_t)1<<(OSC_HFOSCCAL0_SCALEDIV16_POS))
#define OSC_HFOSCCAL0_SCALEDIV8         ((uint32_t)1<<(OSC_HFOSCCAL0_SCALEDIV8_POS))
#define OSC_HFOSCCAL0_SCALEDIV4         ((uint32_t)1<<(OSC_HFOSCCAL0_SCALEDIV4_POS))
#define OSC_HFOSCCAL0_SCALEDIV2         ((uint32_t)1<<(OSC_HFOSCCAL0_SCALEDIV2_POS))
#define OSC_HFOSCCAL0_SCALE1X           ((uint32_t)1<<(OSC_HFOSCCAL0_SCALE1X_POS))
#define OSC_HFOSCCAL0_SCALE2X           ((uint32_t)1<<(OSC_HFOSCCAL0_SCALE2X_POS))
#define OSC_HFOSCCAL0_SCALE4X           ((uint32_t)1<<(OSC_HFOSCCAL0_SCALE4X_POS))
#define OSC_HFOSCCAL0_SCALE8X           ((uint32_t)1<<(OSC_HFOSCCAL0_SCALE8X_POS))
#define OSC_HFOSCCAL0_SCALE16X          ((uint32_t)0x1F<<(OSC_HFOSCCAL0_SCALE16X0_POS))
#define OSC_HFOSCCAL0_SCALE16X0         ((uint32_t)1<<(OSC_HFOSCCAL0_SCALE16X0_POS))
#define OSC_HFOSCCAL0_SCALE16X1         ((uint32_t)1<<(OSC_HFOSCCAL0_SCALE16X1_POS))
#define OSC_HFOSCCAL0_SCALE16X2         ((uint32_t)1<<(OSC_HFOSCCAL0_SCALE16X2_POS))
#define OSC_HFOSCCAL0_SCALE16X3         ((uint32_t)1<<(OSC_HFOSCCAL0_SCALE16X3_POS))
#define OSC_HFOSCCAL0_SCALE16X4         ((uint32_t)1<<(OSC_HFOSCCAL0_SCALE16X4_POS))
#define OSC_HFOSCCAL0_SCALE32X          ((uint32_t)1<<(OSC_HFOSCCAL0_SCALE32X_POS))

/* OSC_HFOSCCAL1 λ�� */
#define OSC_HFOSCCAL1_HLSW_POS          (0)
#define OSC_HFOSCCAL1_HSXTALEXEN_POS    (1)
#define OSC_HFOSCCAL1_HSFSEN_POS        (2)
#define OSC_HFOSCCAL1_SELGAIN0_POS      (3)
#define OSC_HFOSCCAL1_SELGAIN1_POS      (4)
#define OSC_HFOSCCAL1_HLSW              ((uint32_t)1<<(OSC_HFOSCCAL1_HLSW_POS))
#define OSC_HFOSCCAL1_HSXTALEXEN        ((uint32_t)1<<(OSC_HFOSCCAL1_HSXTALEXEN_POS))
#define OSC_HFOSCCAL1_HSFSEN            ((uint32_t)1<<(OSC_HFOSCCAL1_HSFSEN_POS))
#define OSC_HFOSCCAL1_SELGAIN           ((uint32_t)3<<(OSC_HFOSCCAL1_SELGAIN0_POS))
#define OSC_HFOSCCAL1_SELGAIN0          ((uint32_t)1<<(OSC_HFOSCCAL1_SELGAIN0_POS))
#define OSC_HFOSCCAL1_SELGAIN1          ((uint32_t)1<<(OSC_HFOSCCAL1_SELGAIN1_POS))

/* PLL_CTL λ�� */
#define PLL_CTL_PDRST_POS               (0)
#define PLL_CTL_M0_POS                  (2)
#define PLL_CTL_M1_POS                  (3)
#define PLL_CTL_M2_POS                  (4)
#define PLL_CTL_M3_POS                  (5)
#define PLL_CTL_M4_POS                  (6)
#define PLL_CTL_M5_POS                  (7)
#define PLL_CTL_M6_POS                  (8)
#define PLL_CTL_M7_POS                  (9)
#define PLL_CTL_M8_POS                  (10)
#define PLL_CTL_M9_POS                  (11)
#define PLL_CTL_M10_POS                 (12)
#define PLL_CTL_M11_POS                 (13)
#define PLL_CTL_M12_POS                 (14)
#define PLL_CTL_M13_POS                 (15)
#define PLL_CTL_N0_POS                  (16)
#define PLL_CTL_N1_POS                  (17)
#define PLL_CTL_N2_POS                  (18)
#define PLL_CTL_N3_POS                  (19)
#define PLL_CTL_OD0_POS                 (20)
#define PLL_CTL_OD1_POS                 (21)
#define PLL_CTL_TSZEROIS_POS            (24)
#define PLL_CTL_TSVREF2V_POS            (25)
#define PLL_CTL_TSVREF0P5_POS           (26)
#define PLL_CTL_TSMRBG_POS              (27)
#define PLL_CTL_TSLSRCIS_POS            (28)
#define PLL_CTL_TSLPBG_POS              (29)
#define PLL_CTL_TSLCDIS_POS             (30)
#define PLL_CTL_TSHSILDO12_POS          (31)
#define PLL_CTL_PDRST                   ((uint32_t)1<<(PLL_CTL_PDRST_POS))
#define PLL_CTL_M                       ((uint32_t)0x3FFF<<(PLL_CTL_M0_POS))
#define PLL_CTL_M0                      ((uint32_t)1<<(PLL_CTL_M0_POS))
#define PLL_CTL_M1                      ((uint32_t)1<<(PLL_CTL_M1_POS))
#define PLL_CTL_M2                      ((uint32_t)1<<(PLL_CTL_M2_POS))
#define PLL_CTL_M3                      ((uint32_t)1<<(PLL_CTL_M3_POS))
#define PLL_CTL_M4                      ((uint32_t)1<<(PLL_CTL_M4_POS))
#define PLL_CTL_M5                      ((uint32_t)1<<(PLL_CTL_M5_POS))
#define PLL_CTL_M6                      ((uint32_t)1<<(PLL_CTL_M6_POS))
#define PLL_CTL_M7                      ((uint32_t)1<<(PLL_CTL_M7_POS))
#define PLL_CTL_M8                      ((uint32_t)1<<(PLL_CTL_M8_POS))
#define PLL_CTL_M9                      ((uint32_t)1<<(PLL_CTL_M9_POS))
#define PLL_CTL_M10                     ((uint32_t)1<<(PLL_CTL_M12_POS))
#define PLL_CTL_M11                     ((uint32_t)1<<(PLL_CTL_M12_POS))
#define PLL_CTL_M12                     ((uint32_t)1<<(PLL_CTL_M12_POS))
#define PLL_CTL_M13                     ((uint32_t)1<<(PLL_CTL_M13_POS))
#define PLL_CTL_N                       ((uint32_t)0xF<<(PLL_CTL_N0_POS))
#define PLL_CTL_N0                      ((uint32_t)1<<(PLL_CTL_N0_POS))
#define PLL_CTL_N1                      ((uint32_t)1<<(PLL_CTL_N1_POS))
#define PLL_CTL_N2                      ((uint32_t)1<<(PLL_CTL_N2_POS))
#define PLL_CTL_N3                      ((uint32_t)1<<(PLL_CTL_N3_POS))
#define PLL_CTL_OD                      ((uint32_t)0x3<<(PLL_CTL_OD0_POS))
#define PLL_CTL_OD0                     ((uint32_t)1<<(PLL_CTL_OD0_POS))
#define PLL_CTL_OD1                     ((uint32_t)1<<(PLL_CTL_OD1_POS))
#define PLL_CTL_TSZEROIS                ((uint32_t)1<<(PLL_CTL_TSZEROIS_POS))
#define PLL_CTL_TSVREF2V                ((uint32_t)1<<(PLL_CTL_TSVREF2V_POS))
#define PLL_CTL_TSVREF0P5               ((uint32_t)1<<(PLL_CTL_TSVREF0P5_POS))
#define PLL_CTL_TSMRBG                  ((uint32_t)1<<(PLL_CTL_TSMRBG_POS))
#define PLL_CTL_TSLSRCIS                ((uint32_t)1<<(PLL_CTL_TSLSRCIS_POS))
#define PLL_CTL_TSLPBG                  ((uint32_t)1<<(PLL_CTL_TSLPBG_POS))
#define PLL_CTL_TSLCDIS                 ((uint32_t)1<<(PLL_CTL_TSLCDIS_POS))
#define PLL_CTL_TSHSILDO12              ((uint32_t)1<<(PLL_CTL_TSHSILDO12_POS))

/* ����(OSC)������� */


/* ----------------------------------------------------------------------------
   -- �ж�(INT)
   ---------------------------------------------------------------------------- */

/* INT - �жϼĴ����ڴ�ṹ */
typedef struct INT_MemMap {
    volatile uint32_t CTL0;             /* �жϿ��ƼĴ���0, ƫ��:0x0000 */
    volatile uint32_t EIE0;             /* �ж�ʹ�ܼĴ���0, ƫ��:0x0004 */
             uint32_t RESERVED1;        /* ������ַ, ƫ��:0x0008 */
    volatile uint32_t EIE1;             /* �ж�ʹ�ܼĴ���1, ƫ��:0x000C */
             uint32_t RESERVED2;        /* ������ַ, ƫ��:0x0010 */
    volatile uint32_t EIE2;             /* �ж�ʹ�ܼĴ���2, ƫ��:0x0014 */
    		 uint32_t RESERVED3;        /* ������ַ, ƫ��:0x0018 */
    volatile uint32_t EIF0;             /* �жϱ�־λ�Ĵ���0, ƫ��:0x001C */
             uint32_t RESERVED4;        /* ������ַ, ƫ��:0x0020 */
    volatile uint32_t EIF1;             /* �жϱ�־λ�Ĵ���1, ƫ��:0x0024 */
             uint32_t RESERVED5;        /* ������ַ, ƫ��:0x0028 */
    volatile uint32_t EIF2;             /* �жϱ�־λ�Ĵ���2, ƫ��:0x002C */
             uint32_t RESERVED6;        /* ������ַ, ƫ��:0x0030 */
    volatile uint32_t IP0;              /* �ж����ȼ����ƼĴ���0, ƫ��:0x0034 */
    volatile uint32_t IP1;              /* �ж����ȼ����ƼĴ���1, ƫ��:0x0038 */
    volatile uint32_t IP2;              /* �ж����ȼ����ƼĴ���2, ƫ��:0x003C */
    volatile uint32_t IP3;              /* �ж����ȼ����ƼĴ���3, ƫ��:0x0040 */
    volatile uint32_t IP4;              /* �ж����ȼ����ƼĴ���4, ƫ��:0x0044 */
    volatile uint32_t IP5;              /* �ж����ȼ����ƼĴ���5, ƫ��:0x0048 */
    volatile uint32_t IP6;              /* �ж����ȼ����ƼĴ���6, ƫ��:0x004C */
    volatile uint32_t IP7;              /* �ж����ȼ����ƼĴ���7, ƫ��:0x0050 */
    volatile uint32_t IP8;              /* �ж����ȼ����ƼĴ���8, ƫ��:0x0054 */
    volatile uint32_t IP9;              /* �ж����ȼ����ƼĴ���9, ƫ��:0x0058 */
    volatile uint32_t IP10;             /* �ж����ȼ����ƼĴ���10, ƫ��:0x005C */
    volatile uint32_t IP11;             /* �ж����ȼ����ƼĴ���11, ƫ��:0x0060 */
    volatile uint32_t IP12;             /* �ж����ȼ����ƼĴ���12, ƫ��:0x0064 */
    volatile uint32_t IP13;             /* �ж����ȼ����ƼĴ���13, ƫ��:0x0068 */
    volatile uint32_t IP14;             /* �ж����ȼ����ƼĴ���14, ƫ��:0x006C */
    volatile uint32_t IP15;             /* �ж����ȼ����ƼĴ���15, ƫ��:0x0070 */
    volatile uint32_t IP16;             /* �ж����ȼ����ƼĴ���16, ƫ��:0x0074 */
    volatile uint32_t IP17;             /* �ж����ȼ����ƼĴ���17, ƫ��:0x0078 */
    volatile uint32_t IP18;             /* �ж����ȼ����ƼĴ���18, ƫ��:0x007C */
    volatile uint32_t EINTMASK;         /* �ⲿ�ж����μĴ���, ƫ��:0x0080 */
    volatile uint32_t EINTRISE;         /* �ⲿ�ж�������ѡ��Ĵ���, ƫ��:0x0084 */
    volatile uint32_t EINTFALL;         /* �ⲿ�ж��½���ѡ��Ĵ���, ƫ��:0x0088 */
    volatile uint32_t EINTF;            /* �ⲿ�жϱ�־λ�Ĵ���, ƫ��:0x008C */
             uint32_t RESERVED7;        /* ������ַ, ƫ��:0x0090 */
    volatile uint32_t EINTSS0;          /* �ⲿ�ж����ж�Դѡ��Ĵ���0, ƫ��:0x0094 */
    volatile uint32_t EINTSS1;          /* �ⲿ�ж����ж�Դѡ��Ĵ���1, ƫ��:0x0098 */
    volatile uint32_t CTL1;             /* �жϿ��ƼĴ���1, ƫ��:0x009C */
}INT_SFRmap;

/* ----------------------------------------------------------------------------
   -- INT - �жϼĴ�����ں�
   ---------------------------------------------------------------------------- */
/* INT - �Ĵ�����ڵ�ַ */
#define INT_ADDR                        ((uint32_t)0x40200000)
#define INT_SFR                         ((INT_SFRmap *) INT_ADDR)

/* INT - �Ĵ������ */
#define INT_CTL0                        (INT_SFR->CTL0)
#define INT_EIE0                        (INT_SFR->EIE0)
#define INT_EIE1                        (INT_SFR->EIE1)
#define INT_EIE2                        (INT_SFR->EIE2)
#define INT_EIF0                        (INT_SFR->EIF0)
#define INT_EIF1                        (INT_SFR->EIF1)
#define INT_EIF2                        (INT_SFR->EIF2)
#define INT_IP0                         (INT_SFR->IP0)
#define INT_IP1                         (INT_SFR->IP1)
#define INT_IP2                         (INT_SFR->IP2)
#define INT_IP3                         (INT_SFR->IP3)
#define INT_IP4                         (INT_SFR->IP4)
#define INT_IP5                         (INT_SFR->IP5)
#define INT_IP6                         (INT_SFR->IP6)
#define INT_IP7                         (INT_SFR->IP7)
#define INT_IP8                         (INT_SFR->IP8)
#define INT_IP9                         (INT_SFR->IP9)
#define INT_IP10                        (INT_SFR->IP10)
#define INT_IP11                        (INT_SFR->IP11)
#define INT_IP12                        (INT_SFR->IP12)
#define INT_IP13                        (INT_SFR->IP13)
#define INT_IP14                        (INT_SFR->IP14)
#define INT_IP15                        (INT_SFR->IP15)
#define INT_IP16                        (INT_SFR->IP16)
#define INT_IP17                        (INT_SFR->IP17)
#define INT_IP18                        (INT_SFR->IP18)
#define INT_EINTMASK                    (INT_SFR->EINTMASK)
#define INT_EINTRISE                    (INT_SFR->EINTRISE)
#define INT_EINTFALL                    (INT_SFR->EINTFALL)
#define INT_EINTF                       (INT_SFR->EINTF)
#define INT_EINTSS0                     (INT_SFR->EINTSS0)
#define INT_EINTSS1                     (INT_SFR->EINTSS1)
#define INT_CTL1                        (INT_SFR->CTL1)


/* INT_CTL0 λ�� */
#define INT_CTL0_AIE_POS                (0)
#define INT_CTL0_PRIGROUP0_POS          (1)
#define INT_CTL0_PRIGROUP1_POS          (2)
#define INT_CTL0_INTPENDING_POS         (4)
#define INT_CTL0_INTPREEMPT_POS         (5)
#define INT_CTL0_FAULTMASK_POS          (6)
#define INT_CTL0_DSALIGN_POS            (7)
#define INT_CTL0_PRIBASE0_POS           (12)
#define INT_CTL0_PRIBASE1_POS           (13)
#define INT_CTL0_PRIBASE2_POS           (14)
#define INT_CTL0_PRIBASE3_POS           (15)
#define INT_CTL0_INTPEND0_POS           (16)
#define INT_CTL0_INTPEND1_POS           (17)
#define INT_CTL0_INTPEND2_POS           (18)
#define INT_CTL0_INTPEND3_POS           (19)
#define INT_CTL0_INTPEND4_POS           (20)
#define INT_CTL0_INTPEND5_POS           (21)
#define INT_CTL0_INTPEND6_POS           (22)
#define INT_CTL0_INTACT0_POS            (24)
#define INT_CTL0_INTACT1_POS            (25)
#define INT_CTL0_INTACT2_POS            (26)
#define INT_CTL0_INTACT3_POS            (27)
#define INT_CTL0_INTACT4_POS            (28)
#define INT_CTL0_INTACT5_POS            (29)
#define INT_CTL0_INTACT6_POS            (30)
#define INT_CTL0_AIE                    ((uint32_t)1<<(INT_CTL0_AIE_POS))
#define INT_CTL0_PRIGROUP               ((uint32_t)3<<(INT_CTL0_PRIGROUP0_POS))
#define INT_CTL0_PRIGROUP0              ((uint32_t)1<<(INT_CTL0_PRIGROUP0_POS))
#define INT_CTL0_PRIGROUP1              ((uint32_t)1<<(INT_CTL0_PRIGROUP1_POS))
#define INT_CTL0_INTPENDING             ((uint32_t)1<<(INT_CTL0_INTPENDING_POS))
#define INT_CTL0_INTPREEMPT             ((uint32_t)1<<(INT_CTL0_INTPREEMPT_POS))
#define INT_CTL0_FAULTMASK              ((uint32_t)1<<(INT_CTL0_FAULTMASK_POS))
#define INT_CTL0_DSALIGN                ((uint32_t)1<<(INT_CTL0_DSALIGN_POS))
#define INT_CTL0_PRIBASE                ((uint32_t)0xF<<(INT_CTL0_PRIBASE0_POS))
#define INT_CTL0_PRIBASE0               ((uint32_t)1<<(INT_CTL0_PRIBASE0_POS))
#define INT_CTL0_PRIBASE1               ((uint32_t)1<<(INT_CTL0_PRIBASE1_POS))
#define INT_CTL0_PRIBASE2               ((uint32_t)1<<(INT_CTL0_PRIBASE2_POS))
#define INT_CTL0_PRIBASE3               ((uint32_t)1<<(INT_CTL0_PRIBASE3_POS))
#define INT_CTL0_INTPEND                ((uint32_t)0x7F<<(INT_CTL0_INTPEND0_POS))
#define INT_CTL0_INTPEND0               ((uint32_t)1<<(INT_CTL0_INTPEND0_POS))
#define INT_CTL0_INTPEND1               ((uint32_t)1<<(INT_CTL0_INTPEND1_POS))
#define INT_CTL0_INTPEND2               ((uint32_t)1<<(INT_CTL0_INTPEND2_POS))
#define INT_CTL0_INTPEND3               ((uint32_t)1<<(INT_CTL0_INTPEND3_POS))
#define INT_CTL0_INTPEND4               ((uint32_t)1<<(INT_CTL0_INTPEND4_POS))
#define INT_CTL0_INTPEND5               ((uint32_t)1<<(INT_CTL0_INTPEND5_POS))
#define INT_CTL0_INTPEND6               ((uint32_t)1<<(INT_CTL0_INTPEND6_POS))
#define INT_CTL0_INTACT                 ((uint32_t)0x7F<<(INT_CTL0_INTACT0_POS))
#define INT_CTL0_INTACT0                ((uint32_t)1<<(INT_CTL0_INTACT0_POS))
#define INT_CTL0_INTACT1                ((uint32_t)1<<(INT_CTL0_INTACT1_POS))
#define INT_CTL0_INTACT2                ((uint32_t)1<<(INT_CTL0_INTACT2_POS))
#define INT_CTL0_INTACT3                ((uint32_t)1<<(INT_CTL0_INTACT3_POS))
#define INT_CTL0_INTACT4                ((uint32_t)1<<(INT_CTL0_INTACT4_POS))
#define INT_CTL0_INTACT5                ((uint32_t)1<<(INT_CTL0_INTACT5_POS))
#define INT_CTL0_INTACT6                ((uint32_t)1<<(INT_CTL0_INTACT6_POS))

/* INT_EIE0 λ�� */
#define INT_EIE0_STACKIE_POS            (5)
#define INT_EIE0_ARIFAULTIE_POS         (6)
#define INT_EIE0_SVCALLIE_POS           (11)
#define INT_EIE0_PENDSVIE_POS           (14)
#define INT_EIE0_SYSTICKIE_POS          (15)
#define INT_EIE0_STACKIE                ((uint32_t)1<<(INT_EIE0_STACKIE_POS))
#define INT_EIE0_ARIFAULTIE             ((uint32_t)1<<(INT_EIE0_ARIFAULTIE_POS))
#define INT_EIE0_SVCALLIE               ((uint32_t)1<<(INT_EIE0_SVCALLIE_POS))
#define INT_EIE0_PENDSVIE               ((uint32_t)1<<(INT_EIE0_PENDSVIE_POS))
#define INT_EIE0_SYSTICKIE              ((uint32_t)1<<(INT_EIE0_SYSTICKIE_POS))

/* INT_EIE1 λ�� */
#define INT_EIE1_WWDTIE_POS             (0)
#define INT_EIE1_EINT16IE_POS           (1)
#define INT_EIE1_EINT0IE_POS            (2)
#define INT_EIE1_EINT1IE_POS            (3)
#define INT_EIE1_EINT2IE_POS            (4)
#define INT_EIE1_EINT3IE_POS            (5)
#define INT_EIE1_EINT4IE_POS            (6)
#define INT_EIE1_EINT9TO5IE_POS         (7)
#define INT_EIE1_EINT15TO10IE_POS       (8)
#ifdef  KF32F_Periph_gptime1
#define INT_EIE1_T1IE_POS               (9)
#endif
#ifdef  KF32F_Periph_gptime3
#define INT_EIE1_T3IE_POS               (10)
#endif
#ifdef  KF32F_Periph_atime5
#define INT_EIE1_T5IE_POS               (11)
#endif
#ifdef  KF32F_Periph_atime6
#define INT_EIE1_T6IE_POS               (12)
#endif
#ifdef  KF32F_Periph_qei
#define INT_EIE1_QEIIE_POS              (13)
#endif
#ifdef  KF32F_Periph_can2
#define INT_EIE1_CAN2IE_POS             (14)
#endif
#ifdef  KF32F_Periph_can3
#define INT_EIE1_CAN3IE_POS             (15)
#endif
#ifdef  KF32F_Periph_can4
#define INT_EIE1_CAN4IE_POS             (16)
#endif
#ifdef  KF32F_Periph_btime14
#define INT_EIE1_T14IE_POS              (17)
#endif
#ifdef  KF32F_Periph_btime15
#define INT_EIE1_T15IE_POS              (18)
#endif
#ifdef  KF32F_Periph_can5
#define INT_EIE1_CAN5IE_POS             (19)
#endif
#ifdef  KF32F_Periph_exic
#define INT_EIE1_EXIC_POS               (20)
#endif
#ifdef  KF32F_Periph_adc0
#define INT_EIE1_ADC0IE_POS             (21)
#endif
#ifdef  KF32F_Periph_adc1
#define INT_EIE1_ADC1IE_POS             (22)
#endif
#ifdef  KF32F_Periph_cfgl
#define INT_EIE1_CFGLIE_POS             (23)
#endif
#ifdef  KF32F_Periph_lcd
#define INT_EIE1_LCDIE_POS              (24)
#endif
#ifdef 	KF32F_Periph_gptime0
#define INT_EIE1_T0IE_POS               (25)
#endif
#define INT_EIE1_DMA0IE_POS             (26)
#ifdef  KF32F_Periph_cmp
#define INT_EIE1_CMPIE_POS              (27)
#endif
#ifdef  KF32F_Periph_usart0
#define INT_EIE1_USART0IE_POS           (28)
#endif
#ifdef  KF32F_Periph_usart1
#define INT_EIE1_USART1IE_POS           (29)
#endif
#ifdef  KF32F_Periph_spi0
#define INT_EIE1_SPI0IE_POS             (30)
#endif
#ifdef  KF32F_Periph_spi1
#define INT_EIE1_SPI1IE_POS             (31)
#endif
#define INT_EIE1_WWDTIE                 ((uint32_t)1<<(INT_EIE1_WWDTIE_POS))
#define INT_EIE1_EINT16IE               ((uint32_t)1<<(INT_EIE1_EINT16IE_POS))
#define INT_EIE1_EINT0IE                ((uint32_t)1<<(INT_EIE1_EINT0IE_POS))
#define INT_EIE1_EINT1IE                ((uint32_t)1<<(INT_EIE1_EINT1IE_POS))
#define INT_EIE1_EINT2IE                ((uint32_t)1<<(INT_EIE1_EINT2IE_POS))
#define INT_EIE1_EINT3IE                ((uint32_t)1<<(INT_EIE1_EINT3IE_POS))
#define INT_EIE1_EINT4IE                ((uint32_t)1<<(INT_EIE1_EINT4IE_POS))
#define INT_EIE1_EINT9TO5IE             ((uint32_t)1<<(INT_EIE1_EINT9TO5IE_POS))
#define INT_EIE1_EINT15TO10IE           ((uint32_t)1<<(INT_EIE1_EINT15TO10IE_POS))
#ifdef  KF32F_Periph_gptime1
#define INT_EIE1_T1IE                   ((uint32_t)1<<(INT_EIE1_T1IE_POS))
#endif
#ifdef  KF32F_Periph_gptime3
#define INT_EIE1_T3IE                   ((uint32_t)1<<(INT_EIE1_T3IE_POS))
#endif
#ifdef  KF32F_Periph_atime5
#define INT_EIE1_T5IE                   ((uint32_t)1<<(INT_EIE1_T5IE_POS))
#endif
#ifdef  KF32F_Periph_atime6
#define INT_EIE1_T6IE                   ((uint32_t)1<<(INT_EIE1_T6IE_POS))
#endif
#ifdef  KF32F_Periph_qei
#define INT_EIE1_QEIIE                  ((uint32_t)1<<(INT_EIE1_QEIIE_POS))
#endif
#ifdef  KF32F_Periph_can2
#define INT_EIE1_CAN2IE                 ((uint32_t)1<<(INT_EIE1_CAN2IE_POS))
#endif
#ifdef  KF32F_Periph_can3
#define INT_EIE1_CAN3IE                 ((uint32_t)1<<(INT_EIE1_CAN3IE_POS))
#endif
#ifdef  KF32F_Periph_can4
#define INT_EIE1_CAN4IE                 ((uint32_t)1<<(INT_EIE1_CAN4IE_POS))
#endif
#ifdef  KF32F_Periph_btime14
#define INT_EIE1_T14IE                  ((uint32_t)1<<(INT_EIE1_T14IE_POS))
#endif
#ifdef  KF32F_Periph_btime15
#define INT_EIE1_T15IE                  ((uint32_t)1<<(INT_EIE1_T15IE_POS))
#endif
#ifdef  KF32F_Periph_can5
#define INT_EIE1_CAN5IE                 ((uint32_t)1<<(INT_EIE1_CAN5IE_POS))
#endif
#ifdef  KF32F_Periph_exic
#define INT_EIE1_EXICIE                 ((uint32_t)1<<(INT_EIE1_EXICIE_POS))
#endif
#ifdef  KF32F_Periph_adc0
#define INT_EIE1_ADC0IE                 ((uint32_t)1<<(INT_EIE1_ADC0IE_POS))
#endif
#ifdef  KF32F_Periph_adc1
#define INT_EIE1_ADC1IE                 ((uint32_t)1<<(INT_EIE1_ADC1IE_POS))
#endif
#ifdef  KF32F_Periph_cfgl
#define INT_EIE1_CFGLIE                  ((uint32_t)1<<(INT_EIE1_CFGLIE_POS))
#endif
#ifdef  KF32F_Periph_lcd
#define INT_EIE1_LCDIE                  ((uint32_t)1<<(INT_EIE1_LCDIE_POS))
#endif
#ifdef 	KF32F_Periph_gptime0
#define INT_EIE1_T0IE                   ((uint32_t)1<<(INT_EIE1_T0IE_POS))
#endif
#define INT_EIE1_DMA0IE                 ((uint32_t)1<<(INT_EIE1_DMA0IE_POS))
#ifdef KF32F_Periph_cmp
#define INT_EIE1_CMPIE                  ((uint32_t)1<<(INT_EIE1_CMPIE_POS))
#endif
#ifdef  KF32F_Periph_usart0
#define INT_EIE1_USART0IE               ((uint32_t)1<<(INT_EIE1_USART0IE_POS))
#endif
#ifdef  KF32F_Periph_usart1
#define INT_EIE1_USART1IE               ((uint32_t)1<<(INT_EIE1_USART1IE_POS))
#endif
#ifdef  KF32F_Periph_spi0
#define INT_EIE1_SPI0IE                 ((uint32_t)1<<(INT_EIE1_SPI0IE_POS))
#endif
#ifdef  KF32F_Periph_spi1
#define INT_EIE1_SPI1IE                 ((uint32_t)1<<(INT_EIE1_SPI1IE_POS))
#endif

/* INT_EIE2 λ�� */
#define INT_EIE2_DMA1IE_POS             (0)
#define INT_EIE2_EINT19TO17IE_POS       (1)
#ifdef  KF32F_Periph_can0
#define INT_EIE2_CAN0IE_POS             (2)
#endif
#ifdef  KF32F_Periph_can1
#define INT_EIE2_CAN1IE_POS             (3)
#endif
#define INT_EIE2_T9IE_POS               (4)
#define INT_EIE2_T10IE_POS              (5)
#define INT_EIE2_EINT21TO20IE_POS       (6)
#define INT_EIE2_EINT31TO22IE_POS       (7)
#define INT_EIE2_OSCIE_POS              (8)
#ifdef  KF32F_Periph_i2c0
#define INT_EIE2_I2C0IE_POS             (9)
#endif
#ifdef  KF32F_Periph_i2c1
#define INT_EIE2_I2C1IE_POS             (10)
#endif
#ifdef  KF32F_Periph_i2c2
#define INT_EIE2_I2C2IE_POS             (11)
#endif
#ifdef  KF32F_Periph_usb
#define INT_EIE2_USBIE_POS              (12)
#endif
#ifdef  KF32F_Periph_gptime2
#define INT_EIE2_T2IE_POS               (13)
#endif
#ifdef  KF32F_Periph_gptime4
#define INT_EIE2_T4IE_POS               (14)
#endif
#define INT_EIE2_CTOUCHIE_POS           (15)
#ifdef  KF32F_Periph_usart2
#define INT_EIE2_USART2IE_POS           (16)
#endif
#ifdef  KF32F_Periph_usart3
#define INT_EIE2_USART3IE_POS           (17)
#endif
#ifdef  KF32F_Periph_usart4
#define INT_EIE2_USART4IE_POS           (18)
#endif
#ifdef  KF32F_Periph_spi2
#define INT_EIE2_SPI2IE_POS             (19)
#endif
#ifdef  KF32F_Periph_spi3
#define INT_EIE2_SPI3IE_POS             (20)
#endif
#ifdef  KF32F_Periph_adc2
#define INT_EIE2_ADC2IE_POS             (21)
#endif
#ifdef  KF32F_Periph_gptime18
#define INT_EIE2_T18IE_POS              (22)
#endif
#ifdef  KF32F_Periph_gptime19
#define INT_EIE2_T19IE_POS              (23)
#endif
#ifdef  KF32F_Periph_gptime22_time23
#define INT_EIE2_T22T23IE_POS           (24)
#endif
#define INT_EIE2_WKPIE_POS              (25)
#ifdef  KF32F_Periph_gptime20
#define INT_EIE2_T20IE_POS              (26)
#endif
#ifdef  KF32F_Periph_gptime21
#define INT_EIE2_T21IE_POS              (27)
#endif
#ifdef  KF32F_Periph_i2c3
#define INT_EIE2_I2C3IE_POS             (28)
#endif
#ifdef  KF32F_Periph_usart5
#define INT_EIE2_USART5IE_POS           (29)
#endif
#ifdef  KF32F_Periph_usart6
#define INT_EIE2_USART6IE_POS           (30)
#endif
#ifdef  KF32F_Periph_usart7
#define INT_EIE2_USART7IE_POS           (31)
#endif
#define INT_EIE2_DMA1IE                 ((uint32_t)1<<(INT_EIE2_DMA1IE_POS))
#define INT_EIE2_EINT19TO17IE           ((uint32_t)1<<(INT_EIE2_EINT19TO17IE_POS))
#ifdef  KF32F_Periph_can0
#define INT_EIE2_CAN0IE                 ((uint32_t)1<<(INT_EIE2_CAN0IE_POS))
#endif
#ifdef  KF32F_Periph_can1
#define INT_EIE2_CAN1IE                 ((uint32_t)1<<(INT_EIE2_CAN1IE_POS))
#endif
#define INT_EIE2_T9IE                   ((uint32_t)1<<(INT_EIE2_T9IE_POS))
#define INT_EIE2_T10IE                  ((uint32_t)1<<(INT_EIE2_T10IE_POS))
#define INT_EIE2_EINT21TO20IE           ((uint32_t)1<<(INT_EIE2_EINT21TO20IE_POS))
#define INT_EIE2_EINT31TO22IE           ((uint32_t)1<<(INT_EIE2_EINT31TO22IE_POS))
#define INT_EIE2_OSCIE                  ((uint32_t)1<<(INT_EIE2_OSCIE_POS))
#ifdef  KF32F_Periph_i2c0
#define INT_EIE2_I2C0IE                 ((uint32_t)1<<(INT_EIE2_I2C0IE_POS))
#endif
#ifdef  KF32F_Periph_i2c1
#define INT_EIE2_I2C1IE                 ((uint32_t)1<<(INT_EIE2_I2C1IE_POS))
#endif
#ifdef  KF32F_Periph_i2c2
#define INT_EIE2_I2C2IE                 ((uint32_t)1<<(INT_EIE2_I2C2IE_POS))
#endif
#ifdef  KF32F_Periph_usb
#define INT_EIE2_USBIE                  ((uint32_t)1<<(INT_EIE2_USBIE_POS))
#endif
#ifdef  KF32F_Periph_gptime2
#define INT_EIE2_T2IE                   ((uint32_t)1<<(INT_EIE2_T2IE_POS))
#endif
#ifdef  KF32F_Periph_gptime4
#define INT_EIE2_T4IE                   ((uint32_t)1<<(INT_EIE2_T4IE_POS))
#endif
#define INT_EIE2_CTOUCHIE               ((uint32_t)1<<(INT_EIE2_CTOUCHIE_POS))
#ifdef  KF32F_Periph_usart2
#define INT_EIE2_USART2IE               ((uint32_t)1<<(INT_EIE2_USART2IE_POS))
#endif
#ifdef  KF32F_Periph_usart3
#define INT_EIE2_USART3IE               ((uint32_t)1<<(INT_EIE2_USART3IE_POS))
#endif
#ifdef  KF32F_Periph_usart4
#define INT_EIE2_USART4IE               ((uint32_t)1<<(INT_EIE2_USART4IE_POS))
#endif
#ifdef  KF32F_Periph_spi2
#define INT_EIE2_SPI2IE                 ((uint32_t)1<<(INT_EIE2_SPI2IE_POS))
#endif
#ifdef  KF32F_Periph_spi3
#define INT_EIE2_SPI3IE                 ((uint32_t)1<<(INT_EIE2_SPI3IE_POS))
#endif
#ifdef  KF32F_Periph_adc2
#define INT_EIE2_ADC2IE                 ((uint32_t)1<<(INT_EIE2_ADC2IE_POS))
#endif
#ifdef  KF32F_Periph_gptime18
#define INT_EIE2_T18IE                  ((uint32_t)1<<(INT_EIE2_T18IE_POS))
#endif
#ifdef  KF32F_Periph_gptime19
#define INT_EIE2_T19IE                  ((uint32_t)1<<(INT_EIE2_T19IE_POS))
#endif
#ifdef  KF32F_Periph_gptime22_time23
#define INT_EIE2_T22T23IE               ((uint32_t)1<<(INT_EIE2_T22T23IE_POS))
#endif
#define INT_EIE2_WKPIE                  ((uint32_t)1<<(INT_EIE2_WKPIE_POS))
#ifdef  KF32F_Periph_gptime20
#define INT_EIE2_T20IE                  ((uint32_t)1<<(INT_EIE2_T20IE_POS))
#endif
#ifdef  KF32F_Periph_gptime21
#define INT_EIE2_T21IE                  ((uint32_t)1<<(INT_EIE2_T21IE_POS))
#endif
#ifdef  KF32F_Periph_i2c3
#define INT_EIE2_I2C3IE                 ((uint32_t)1<<(INT_EIE2_I2C3IE_POS))
#endif
#ifdef  KF32F_Periph_usart5
#define INT_EIE2_USART5IE               ((uint32_t)1<<(INT_EIE2_USART5IE_POS))
#endif
#ifdef  KF32F_Periph_usart6
#define INT_EIE2_USART6IE               ((uint32_t)1<<(INT_EIE2_USART6IE_POS))
#endif
#ifdef  KF32F_Periph_usart7
#define INT_EIE2_USART7IE               ((uint32_t)1<<(INT_EIE2_USART7IE_POS))
#endif
/* INT_EIF0 λ�� */
#define INT_EIF0_NMIIF_POS              (2)
#define INT_EIF0_HARDFAULTIF_POS        (3)
#define INT_EIF0_STACKIF_POS            (5)
#define INT_EIF0_ARIFAULTIF_POS         (6)
#define INT_EIF0_SVCALLIF_POS           (11)
#define INT_EIF0_PENDSVIF_POS           (14)
#define INT_EIF0_SYSTICKIF_POS          (15)
#define INT_EIF0_NMIIF                  ((uint32_t)1<<(INT_EIF0_NMIIF_POS))
#define INT_EIF0_HARDFAULTIF            ((uint32_t)1<<(INT_EIF0_HARDFAULTIF_POS))
#define INT_EIF0_STACKIF                ((uint32_t)1<<(INT_EIF0_STACKIF_POS))
#define INT_EIF0_ARIFAULTIF             ((uint32_t)1<<(INT_EIF0_ARIFAULTIF_POS))
#define INT_EIF0_SVCALLIF               ((uint32_t)1<<(INT_EIF0_SVCALLIF_POS))
#define INT_EIF0_PENDSVIF               ((uint32_t)1<<(INT_EIF0_PENDSVIF_POS))
#define INT_EIF0_SYSTICKIF              ((uint32_t)1<<(INT_EIF0_SYSTICKIF_POS))

/* INT_EIF1 λ�� */
#define INT_EIF1_WWDTIF_POS             (0)
#define INT_EIF1_EINT16IF_POS           (1)
#define INT_EIF1_EINT0IF_POS            (2)
#define INT_EIF1_EINT1IF_POS            (3)
#define INT_EIF1_EINT2IF_POS            (4)
#define INT_EIF1_EINT3IF_POS            (5)
#define INT_EIF1_EINT4IF_POS            (6)
#define INT_EIF1_EINT9TO5IF_POS         (7)
#define INT_EIF1_EINT15TO10IF_POS       (8)
#ifdef  KF32F_Periph_gptime1
#define INT_EIF1_T1IF_POS               (9)
#endif
#ifdef  KF32F_Periph_gptime3
#define INT_EIF1_T3IF_POS               (10)
#endif
#ifdef  KF32F_Periph_atime5
#define INT_EIF1_T5IF_POS               (11)
#endif
#ifdef  KF32F_Periph_atime6
#define INT_EIF1_T6IF_POS               (12)
#endif
#ifdef  KF32F_Periph_qei
#define INT_EIF1_QEIIF_POS              (13)
#endif
#ifdef  KF32F_Periph_can2
#define INT_EIF1_CAN2IF_POS             (14)
#endif
#ifdef  KF32F_Periph_can3
#define INT_EIF1_CAN3IF_POS             (15)
#endif
#ifdef  KF32F_Periph_can4
#define INT_EIF1_CAN4IF_POS             (16)
#endif
#ifdef  KF32F_Periph_btime14
#define INT_EIF1_T14IF_POS              (17)
#endif
#ifdef  KF32F_Periph_btime15
#define INT_EIF1_T15IF_POS              (18)
#endif
#ifdef  KF32F_Periph_can5
#define INT_EIF1_CAN5IF_POS             (19)
#endif
#ifdef  KF32F_Periph_exic
#define INT_EIF1_EXICIF_POS             (20)
#endif
#ifdef  KF32F_Periph_adc0
#define INT_EIF1_ADC0IF_POS             (21)
#endif
#ifdef  KF32F_Periph_adc1
#define INT_EIF1_ADC1IF_POS             (22)
#endif
#ifdef  KF32F_Periph_cfgl
#define INT_EIF1_CFGLIF_POS             (23)
#endif
#ifdef  KF32F_Periph_lcd
#define INT_EIF1_LCDIF_POS              (24)
#endif
#ifdef 	KF32F_Periph_gptime0
#define INT_EIF1_T0IF_POS               (25)
#endif
#define INT_EIF1_DMA0IF_POS             (26)
#ifdef  KF32F_Periph_cmp
#define INT_EIF1_CMPIF_POS              (27)
#endif
#ifdef  KF32F_Periph_usart0
#define INT_EIF1_USART0IF_POS           (28)
#endif
#ifdef  KF32F_Periph_usart1
#define INT_EIF1_USART1IF_POS           (29)
#endif
#ifdef  KF32F_Periph_spi0
#define INT_EIF1_SPI0IF_POS             (30)
#endif
#ifdef  KF32F_Periph_spi1
#define INT_EIF1_SPI1IF_POS             (31)
#endif
#define INT_EIF1_WWDTIF                 ((uint32_t)1<<(INT_EIF1_WWDTIF_POS))
#define INT_EIF1_EINT16IF               ((uint32_t)1<<(INT_EIF1_EINT16IF_POS))
#define INT_EIF1_EINT0IF                ((uint32_t)1<<(INT_EIF1_EINT0IF_POS))
#define INT_EIF1_EINT1IF                ((uint32_t)1<<(INT_EIF1_EINT1IF_POS))
#define INT_EIF1_EINT2IF                ((uint32_t)1<<(INT_EIF1_EINT2IF_POS))
#define INT_EIF1_EINT3IF                ((uint32_t)1<<(INT_EIF1_EINT3IF_POS))
#define INT_EIF1_EINT4IF                ((uint32_t)1<<(INT_EIF1_EINT4IF_POS))
#define INT_EIF1_EINT9TO5IF             ((uint32_t)1<<(INT_EIF1_EINT9TO5IF_POS))
#define INT_EIF1_EINT15TO10IF           ((uint32_t)1<<(INT_EIF1_EINT15TO10IF_POS))
#ifdef  KF32F_Periph_gptime1
#define INT_EIF1_T1IF                   ((uint32_t)1<<(INT_EIF1_T1IF_POS))
#endif
#ifdef  KF32F_Periph_gptime3
#define INT_EIF1_T3IF                   ((uint32_t)1<<(INT_EIF1_T3IF_POS))
#endif
#ifdef  KF32F_Periph_atime5
#define INT_EIF1_T5IF                   ((uint32_t)1<<(INT_EIF1_T5IF_POS))
#endif
#ifdef  KF32F_Periph_atime6
#define INT_EIF1_T6IF                   ((uint32_t)1<<(INT_EIF1_T6IF_POS))
#endif
#ifdef  KF32F_Periph_qei
#define INT_EIF1_QEIIF                  ((uint32_t)1<<(INT_EIF1_QEIIF_POS))
#endif
#ifdef  KF32F_Periph_can2
#define INT_EIF1_CAN2IF                 ((uint32_t)1<<(INT_EIF1_CAN2IF_POS))
#endif
#ifdef  KF32F_Periph_can3
#define INT_EIF1_CAN3IF                 ((uint32_t)1<<(INT_EIF1_CAN3IF_POS))
#endif
#ifdef  KF32F_Periph_can4
#define INT_EIF1_CAN4IF                 ((uint32_t)1<<(INT_EIF1_CAN4IF_POS))
#endif
#ifdef  KF32F_Periph_btime14
#define INT_EIF1_T14IF                  ((uint32_t)1<<(INT_EIF1_T14IF_POS))
#endif
#ifdef  KF32F_Periph_btime15
#define INT_EIF1_T15IF                  ((uint32_t)1<<(INT_EIF1_T15IF_POS))
#endif
#ifdef  KF32F_Periph_can5
#define INT_EIF1_CAN5IF                 ((uint32_t)1<<(INT_EIF1_CAN5IF_POS))
#endif
#ifdef  KF32F_Periph_exic
#define INT_EIF1_EXICIF                 ((uint32_t)1<<(INT_EIF1_EXICIF_POS))
#endif
#ifdef  KF32F_Periph_adc0
#define INT_EIF1_ADC0IF                 ((uint32_t)1<<(INT_EIF1_ADC0IF_POS))
#endif
#ifdef  KF32F_Periph_adc1
#define INT_EIF1_ADC1IF                 ((uint32_t)1<<(INT_EIF1_ADC1IF_POS))
#endif
#ifdef  KF32F_Periph_cfgl
#define INT_EIF1_CFGLIF                  ((uint32_t)1<<(INT_EIF1_CFGLIF_POS))
#endif
#ifdef  KF32F_Periph_lcd
#define INT_EIF1_LCDIF                  ((uint32_t)1<<(INT_EIF1_LCDIF_POS))
#endif
#ifdef 	KF32F_Periph_gptime0
#define INT_EIF1_T0IF                   ((uint32_t)1<<(INT_EIF1_T0IF_POS))
#endif
#define INT_EIF1_DMA0IF                 ((uint32_t)1<<(INT_EIF1_DMA0IF_POS))
#ifdef  KF32F_Periph_cmp
#define INT_EIF1_CMPIF                  ((uint32_t)1<<(INT_EIF1_CMPIF_POS))
#endif
#ifdef  KF32F_Periph_usart0
#define INT_EIF1_USART0IF               ((uint32_t)1<<(INT_EIF1_USART0IF_POS))
#endif
#ifdef  KF32F_Periph_usart1
#define INT_EIF1_USART1IF               ((uint32_t)1<<(INT_EIF1_USART1IF_POS))
#endif
#ifdef  KF32F_Periph_spi0
#define INT_EIF1_SPI0IF                 ((uint32_t)1<<(INT_EIF1_SPI0IF_POS))
#endif
#ifdef  KF32F_Periph_spi1
#define INT_EIF1_SPI1IF                 ((uint32_t)1<<(INT_EIF1_SPI1IF_POS))
#endif
/* INT_EIF2 λ�� */
#define INT_EIF2_DMA1IF_POS             (0)
#define INT_EIF2_EINT19TO17IF_POS       (1)
#ifdef KF32F_Periph_can0
#define INT_EIF2_CAN0IF_POS             (2)
#endif
#ifdef KF32F_Periph_can1
#define INT_EIF2_CAN1IF_POS             (3)
#endif
#define INT_EIF2_T9IF_POS               (4)
#define INT_EIF2_T10IF_POS              (5)
#define INT_EIF2_EINT21TO20IF_POS       (6)
#define INT_EIF2_EINT31TO22IF_POS       (7)
#define INT_EIF2_OSCIF_POS              (8)
#ifdef  KF32F_Periph_i2c0
#define INT_EIF2_I2C0IF_POS             (9)
#endif
#ifdef  KF32F_Periph_i2c1
#define INT_EIF2_I2C1IF_POS             (10)
#endif
#ifdef  KF32F_Periph_i2c2
#define INT_EIF2_I2C2IF_POS             (11)
#endif
#ifdef  KF32F_Periph_usb
#define INT_EIF2_USBIF_POS              (12)
#endif
#ifdef  KF32F_Periph_gptime2
#define INT_EIF2_T2IF_POS               (13)
#endif
#ifdef  KF32F_Periph_gptime4
#define INT_EIF2_T4IF_POS               (14)
#endif
#define INT_EIF2_CTOUCHIF_POS           (15)
#ifdef  KF32F_Periph_usart2
#define INT_EIF2_USART2IF_POS           (16)
#endif
#ifdef  KF32F_Periph_usart3
#define INT_EIF2_USART3IF_POS           (17)
#endif
#ifdef  KF32F_Periph_usart4
#define INT_EIF2_USART4IF_POS           (18)
#endif
#ifdef  KF32F_Periph_spi2
#define INT_EIF2_SPI2IF_POS             (19)
#endif
#ifdef  KF32F_Periph_spi3
#define INT_EIF2_SPI3IF_POS             (20)
#endif
#ifdef  KF32F_Periph_adc2
#define INT_EIF2_ADC2IF_POS             (21)
#endif
#ifdef  KF32F_Periph_gptime18
#define INT_EIF2_T18IF_POS              (22)
#endif
#ifdef  KF32F_Periph_gptime19
#define INT_EIF2_T19IF_POS              (23)
#endif
#ifdef  KF32F_Periph_gptime22_time23
#define INT_EIF2_T22T23IF_POS           (24)
#endif
#define INT_EIF2_WKPIF_POS              (25)
#ifdef  KF32F_Periph_gptime20
#define INT_EIF2_T20IF_POS              (26)
#endif
#ifdef  KF32F_Periph_gptime21
#define INT_EIF2_T21IF_POS              (27)
#endif
#ifdef  KF32F_Periph_i2c3
#define INT_EIF2_I2C3IF_POS             (28)
#endif
#ifdef  KF32F_Periph_usart5
#define INT_EIF2_USART5IF_POS           (29)
#endif
#ifdef  KF32F_Periph_usart6
#define INT_EIF2_USART6IF_POS           (30)
#endif
#ifdef  KF32F_Periph_usart7
#define INT_EIF2_USART7IF_POS           (31)
#endif
#define INT_EIF2_DMA1IF                 ((uint32_t)1<<(INT_EIF2_DMA1IF_POS))
#define INT_EIF2_EINT19TO17IF           ((uint32_t)1<<(INT_EIF2_EINT19TO17IF_POS))
#ifdef KF32F_Periph_can0
#define INT_EIF2_CAN0IF                 ((uint32_t)1<<(INT_EIF2_CAN0IF_POS))
#endif
#ifdef KF32F_Periph_can1
#define INT_EIF2_CAN1IF                 ((uint32_t)1<<(INT_EIF2_CAN1IF_POS))
#endif
#define INT_EIF2_T9IF                   ((uint32_t)1<<(INT_EIF2_T9IF_POS))
#define INT_EIF2_T10IF                  ((uint32_t)1<<(INT_EIF2_T10IF_POS))
#define INT_EIF2_EINT21TO20IF           ((uint32_t)1<<(INT_EIF2_EINT21TO20IF_POS))
#define INT_EIF2_EINT31TO22IF           ((uint32_t)1<<(INT_EIF2_EINT31TO22IF_POS))
#define INT_EIF2_OSCIF                  ((uint32_t)1<<(INT_EIF2_OSCIF_POS))
#ifdef  KF32F_Periph_i2c0
#define INT_EIF2_I2C0IF                 ((uint32_t)1<<(INT_EIF2_I2C0IF_POS))
#endif
#ifdef  KF32F_Periph_i2c1
#define INT_EIF2_I2C1IF                 ((uint32_t)1<<(INT_EIF2_I2C1IF_POS))
#endif
#ifdef  KF32F_Periph_i2c2
#define INT_EIF2_I2C2IF                 ((uint32_t)1<<(INT_EIF2_I2C2IF_POS))
#endif
#ifdef  KF32F_Periph_usb
#define INT_EIF2_USBIF                  ((uint32_t)1<<(INT_EIF2_USBIF_POS))
#endif
#ifdef  KF32F_Periph_gptime2
#define INT_EIF2_T2IF                   ((uint32_t)1<<(INT_EIF2_T2IF_POS))
#endif
#ifdef  KF32F_Periph_gptime4
#define INT_EIF2_T4IF                   ((uint32_t)1<<(INT_EIF2_T4IF_POS))
#endif
#define INT_EIF2_CTOUCHIF               ((uint32_t)1<<(INT_EIF2_CTOUCHIF_POS))
#ifdef  KF32F_Periph_usart2
#define INT_EIF2_USART2IF               ((uint32_t)1<<(INT_EIF2_USART2IF_POS))
#endif
#ifdef  KF32F_Periph_usart3
#define INT_EIF2_USART3IF               ((uint32_t)1<<(INT_EIF2_USART3IF_POS))
#endif
#ifdef  KF32F_Periph_usart4
#define INT_EIF2_USART4IF               ((uint32_t)1<<(INT_EIF2_USART4IF_POS))
#endif
#ifdef  KF32F_Periph_spi2
#define INT_EIF2_SPI2IF                 ((uint32_t)1<<(INT_EIF2_SPI2IF_POS))
#endif
#ifdef  KF32F_Periph_spi3
#define INT_EIF2_SPI3IF                 ((uint32_t)1<<(INT_EIF2_SPI3IF_POS))
#endif
#ifdef  KF32F_Periph_adc2
#define INT_EIF2_ADC2IF                 ((uint32_t)1<<(INT_EIF2_ADC2IF_POS))
#endif
#ifdef  KF32F_Periph_gptime18
#define INT_EIF2_T18IF                  ((uint32_t)1<<(INT_EIF2_T18IF_POS))
#endif
#ifdef  KF32F_Periph_gptime19
#define INT_EIF2_T19IF                  ((uint32_t)1<<(INT_EIF2_T19IF_POS))
#endif
#ifdef  KF32F_Periph_gptime22_time23
#define INT_EIF2_T22T23IF               ((uint32_t)1<<(INT_EIF2_T22T23IF_POS))
#endif
#define INT_EIF2_WKPIF                  ((uint32_t)1<<(INT_EIF2_WKPIF_POS))
#define INT_EIF2_EMIIF                  ((uint32_t)1<<(INT_EIF2_EMIIF_POS))
#ifdef  KF32F_Periph_gptime20
#define INT_EIF2_T20IF                  ((uint32_t)1<<(INT_EIF2_T20IF_POS))
#endif
#ifdef  KF32F_Periph_gptime21
#define INT_EIF2_T21IF                  ((uint32_t)1<<(INT_EIF2_T21IF_POS))
#endif
#ifdef  KF32F_Periph_i2c3
#define INT_EIF2_I2C3IF                 ((uint32_t)1<<(INT_EIF2_I2C3IF_POS))
#endif
#ifdef  KF32F_Periph_usart5
#define INT_EIF2_USART5IF               ((uint32_t)1<<(INT_EIF2_USART5IF))
#endif
#ifdef  KF32F_Periph_usart6
#define INT_EIF2_USART6IF               ((uint32_t)1<<(INT_EIF2_USART6IF))
#endif
#ifdef  KF32F_Periph_usart7
#define INT_EIF2_USART7IF               ((uint32_t)1<<(INT_EIF2_USART7IF))
#endif
/* INT_IP0 λ�� */
#define INT_IP0_PRI4_4_POS              (4)
#define INT_IP0_PRI4_5_POS              (5)
#define INT_IP0_PRI4_6_POS              (6)
#define INT_IP0_PRI4_7_POS              (7)
#define INT_IP0_PRI5_4_POS              (12)
#define INT_IP0_PRI5_5_POS              (13)
#define INT_IP0_PRI5_6_POS              (14)
#define INT_IP0_PRI5_7_POS              (15)
#define INT_IP0_PRI6_4_POS              (20)
#define INT_IP0_PRI6_5_POS              (21)
#define INT_IP0_PRI6_6_POS              (22)
#define INT_IP0_PRI6_7_POS              (23)
#define INT_IP0_PRI7_4_POS              (28)
#define INT_IP0_PRI7_5_POS              (29)
#define INT_IP0_PRI7_6_POS              (30)
#define INT_IP0_PRI7_7_POS              (31)
#define INT_IP0_PRI4_4                  ((uint32_t)1<<(INT_IP0_PRI4_4_POS))
#define INT_IP0_PRI4_5                  ((uint32_t)1<<(INT_IP0_PRI4_5_POS))
#define INT_IP0_PRI4_6                  ((uint32_t)1<<(INT_IP0_PRI4_6_POS))
#define INT_IP0_PRI4_7                  ((uint32_t)1<<(INT_IP0_PRI4_7_POS))
#define INT_IP0_PRI5_4                  ((uint32_t)1<<(INT_IP0_PRI5_4_POS))
#define INT_IP0_PRI5_5                  ((uint32_t)1<<(INT_IP0_PRI5_5_POS))
#define INT_IP0_PRI5_6                  ((uint32_t)1<<(INT_IP0_PRI5_6_POS))
#define INT_IP0_PRI5_7                  ((uint32_t)1<<(INT_IP0_PRI5_7_POS))
#define INT_IP0_PRI6_4                  ((uint32_t)1<<(INT_IP0_PRI6_4_POS))
#define INT_IP0_PRI6_5                  ((uint32_t)1<<(INT_IP0_PRI6_5_POS))
#define INT_IP0_PRI6_6                  ((uint32_t)1<<(INT_IP0_PRI6_6_POS))
#define INT_IP0_PRI6_7                  ((uint32_t)1<<(INT_IP0_PRI6_7_POS))
#define INT_IP0_PRI7_4                  ((uint32_t)1<<(INT_IP0_PRI7_4_POS))
#define INT_IP0_PRI7_5                  ((uint32_t)1<<(INT_IP0_PRI7_5_POS))
#define INT_IP0_PRI7_6                  ((uint32_t)1<<(INT_IP0_PRI7_6_POS))
#define INT_IP0_PRI7_7                  ((uint32_t)1<<(INT_IP0_PRI7_7_POS))

/* INT_IP1 λ�� */
#define INT_IP1_PRI8_4_POS              (4)
#define INT_IP1_PRI8_5_POS              (5)
#define INT_IP1_PRI8_6_POS              (6)
#define INT_IP1_PRI8_7_POS              (7)
#define INT_IP1_PRI9_4_POS              (12)
#define INT_IP1_PRI9_5_POS              (13)
#define INT_IP1_PRI9_6_POS              (14)
#define INT_IP1_PRI9_7_POS              (15)
#define INT_IP1_PRI10_4_POS             (20)
#define INT_IP1_PRI10_5_POS             (21)
#define INT_IP1_PRI10_6_POS             (22)
#define INT_IP1_PRI10_7_POS             (23)
#define INT_IP1_PRI11_4_POS             (28)
#define INT_IP1_PRI11_5_POS             (29)
#define INT_IP1_PRI11_6_POS             (30)
#define INT_IP1_PRI11_7_POS             (31)
#define INT_IP1_PRI8_4                  ((uint32_t)1<<(INT_IP1_PRI8_4_POS))
#define INT_IP1_PRI8_5                  ((uint32_t)1<<(INT_IP1_PRI8_5_POS))
#define INT_IP1_PRI8_6                  ((uint32_t)1<<(INT_IP1_PRI8_6_POS))
#define INT_IP1_PRI8_7                  ((uint32_t)1<<(INT_IP1_PRI8_7_POS))
#define INT_IP1_PRI9_4                  ((uint32_t)1<<(INT_IP1_PRI9_4_POS))
#define INT_IP1_PRI9_5                  ((uint32_t)1<<(INT_IP1_PRI9_5_POS))
#define INT_IP1_PRI9_6                  ((uint32_t)1<<(INT_IP1_PRI9_6_POS))
#define INT_IP1_PRI9_7                  ((uint32_t)1<<(INT_IP1_PRI9_7_POS))
#define INT_IP1_PRI10_4                 ((uint32_t)1<<(INT_IP1_PRI10_4_POS))
#define INT_IP1_PRI10_5                 ((uint32_t)1<<(INT_IP1_PRI10_5_POS))
#define INT_IP1_PRI10_6                 ((uint32_t)1<<(INT_IP1_PRI10_6_POS))
#define INT_IP1_PRI10_7                 ((uint32_t)1<<(INT_IP1_PRI10_7_POS))
#define INT_IP1_PRI11_4                 ((uint32_t)1<<(INT_IP1_PRI11_4_POS))
#define INT_IP1_PRI11_5                 ((uint32_t)1<<(INT_IP1_PRI11_5_POS))
#define INT_IP1_PRI11_6                 ((uint32_t)1<<(INT_IP1_PRI11_6_POS))
#define INT_IP1_PRI11_7                 ((uint32_t)1<<(INT_IP1_PRI11_7_POS))

/* INT_IP2 λ�� */
#define INT_IP2_PRI12_4_POS             (4)
#define INT_IP2_PRI12_5_POS             (5)
#define INT_IP2_PRI12_6_POS             (6)
#define INT_IP2_PRI12_7_POS             (7)
#define INT_IP2_PRI13_4_POS             (12)
#define INT_IP2_PRI13_5_POS             (13)
#define INT_IP2_PRI13_6_POS             (14)
#define INT_IP2_PRI13_7_POS             (15)
#define INT_IP2_PRI14_4_POS             (20)
#define INT_IP2_PRI14_5_POS             (21)
#define INT_IP2_PRI14_6_POS             (22)
#define INT_IP2_PRI14_7_POS             (23)
#define INT_IP2_PRI15_4_POS             (28)
#define INT_IP2_PRI15_5_POS             (29)
#define INT_IP2_PRI15_6_POS             (30)
#define INT_IP2_PRI15_7_POS             (31)
#define INT_IP2_PRI12_4                 ((uint32_t)1<<(INT_IP2_PRI12_4_POS))
#define INT_IP2_PRI12_5                 ((uint32_t)1<<(INT_IP2_PRI12_5_POS))
#define INT_IP2_PRI12_6                 ((uint32_t)1<<(INT_IP2_PRI12_6_POS))
#define INT_IP2_PRI12_7                 ((uint32_t)1<<(INT_IP2_PRI12_7_POS))
#define INT_IP2_PRI13_4                 ((uint32_t)1<<(INT_IP2_PRI13_4_POS))
#define INT_IP2_PRI13_5                 ((uint32_t)1<<(INT_IP2_PRI13_5_POS))
#define INT_IP2_PRI13_6                 ((uint32_t)1<<(INT_IP2_PRI13_6_POS))
#define INT_IP2_PRI13_7                 ((uint32_t)1<<(INT_IP2_PRI13_7_POS))
#define INT_IP2_PRI14_4                 ((uint32_t)1<<(INT_IP2_PRI14_4_POS))
#define INT_IP2_PRI14_5                 ((uint32_t)1<<(INT_IP2_PRI14_5_POS))
#define INT_IP2_PRI14_6                 ((uint32_t)1<<(INT_IP2_PRI14_6_POS))
#define INT_IP2_PRI14_7                 ((uint32_t)1<<(INT_IP2_PRI14_7_POS))
#define INT_IP2_PRI15_4                 ((uint32_t)1<<(INT_IP2_PRI15_4_POS))
#define INT_IP2_PRI15_5                 ((uint32_t)1<<(INT_IP2_PRI15_5_POS))
#define INT_IP2_PRI15_6                 ((uint32_t)1<<(INT_IP2_PRI15_6_POS))
#define INT_IP2_PRI15_7                 ((uint32_t)1<<(INT_IP2_PRI15_7_POS))

/* INT_IP3 λ�� */
#define INT_IP3_PRI16_4_POS             (4)
#define INT_IP3_PRI16_5_POS             (5)
#define INT_IP3_PRI16_6_POS             (6)
#define INT_IP3_PRI16_7_POS             (7)
#define INT_IP3_PRI17_4_POS             (12)
#define INT_IP3_PRI17_5_POS             (13)
#define INT_IP3_PRI17_6_POS             (14)
#define INT_IP3_PRI17_7_POS             (15)
#define INT_IP3_PRI18_4_POS             (20)
#define INT_IP3_PRI18_5_POS             (21)
#define INT_IP3_PRI18_6_POS             (22)
#define INT_IP3_PRI18_7_POS             (23)
#define INT_IP3_PRI19_4_POS             (28)
#define INT_IP3_PRI19_5_POS             (29)
#define INT_IP3_PRI19_6_POS             (30)
#define INT_IP3_PRI19_7_POS             (31)
#define INT_IP3_PRI16_4                 ((uint32_t)1<<(INT_IP3_PRI16_4_POS))
#define INT_IP3_PRI16_5                 ((uint32_t)1<<(INT_IP3_PRI16_5_POS))
#define INT_IP3_PRI16_6                 ((uint32_t)1<<(INT_IP3_PRI16_6_POS))
#define INT_IP3_PRI16_7                 ((uint32_t)1<<(INT_IP3_PRI16_7_POS))
#define INT_IP3_PRI17_4                 ((uint32_t)1<<(INT_IP3_PRI17_4_POS))
#define INT_IP3_PRI17_5                 ((uint32_t)1<<(INT_IP3_PRI17_5_POS))
#define INT_IP3_PRI17_6                 ((uint32_t)1<<(INT_IP3_PRI17_6_POS))
#define INT_IP3_PRI17_7                 ((uint32_t)1<<(INT_IP3_PRI17_7_POS))
#define INT_IP3_PRI18_4                 ((uint32_t)1<<(INT_IP3_PRI18_4_POS))
#define INT_IP3_PRI18_5                 ((uint32_t)1<<(INT_IP3_PRI18_5_POS))
#define INT_IP3_PRI18_6                 ((uint32_t)1<<(INT_IP3_PRI18_6_POS))
#define INT_IP3_PRI18_7                 ((uint32_t)1<<(INT_IP3_PRI18_7_POS))
#define INT_IP3_PRI19_4                 ((uint32_t)1<<(INT_IP3_PRI19_4_POS))
#define INT_IP3_PRI19_5                 ((uint32_t)1<<(INT_IP3_PRI19_5_POS))
#define INT_IP3_PRI19_6                 ((uint32_t)1<<(INT_IP3_PRI19_6_POS))
#define INT_IP3_PRI19_7                 ((uint32_t)1<<(INT_IP3_PRI19_7_POS))

/* INT_IP4 λ�� */
#define INT_IP4_PRI20_4_POS             (4)
#define INT_IP4_PRI20_5_POS             (5)
#define INT_IP4_PRI20_6_POS             (6)
#define INT_IP4_PRI20_7_POS             (7)
#define INT_IP4_PRI21_4_POS             (12)
#define INT_IP4_PRI21_5_POS             (13)
#define INT_IP4_PRI21_6_POS             (14)
#define INT_IP4_PRI21_7_POS             (15)
#define INT_IP4_PRI22_4_POS             (20)
#define INT_IP4_PRI22_5_POS             (21)
#define INT_IP4_PRI22_6_POS             (22)
#define INT_IP4_PRI22_7_POS             (23)
#define INT_IP4_PRI23_4_POS             (28)
#define INT_IP4_PRI23_5_POS             (29)
#define INT_IP4_PRI23_6_POS             (30)
#define INT_IP4_PRI23_7_POS             (31)
#define INT_IP4_PRI20_4                 ((uint32_t)1<<(INT_IP4_PRI20_4_POS))
#define INT_IP4_PRI20_5                 ((uint32_t)1<<(INT_IP4_PRI20_5_POS))
#define INT_IP4_PRI20_6                 ((uint32_t)1<<(INT_IP4_PRI20_6_POS))
#define INT_IP4_PRI20_7                 ((uint32_t)1<<(INT_IP4_PRI20_7_POS))
#define INT_IP4_PRI21_4                 ((uint32_t)1<<(INT_IP4_PRI21_4_POS))
#define INT_IP4_PRI21_5                 ((uint32_t)1<<(INT_IP4_PRI21_5_POS))
#define INT_IP4_PRI21_6                 ((uint32_t)1<<(INT_IP4_PRI21_6_POS))
#define INT_IP4_PRI21_7                 ((uint32_t)1<<(INT_IP4_PRI21_7_POS))
#define INT_IP4_PRI22_4                 ((uint32_t)1<<(INT_IP4_PRI22_4_POS))
#define INT_IP4_PRI22_5                 ((uint32_t)1<<(INT_IP4_PRI22_5_POS))
#define INT_IP4_PRI22_6                 ((uint32_t)1<<(INT_IP4_PRI22_6_POS))
#define INT_IP4_PRI22_7                 ((uint32_t)1<<(INT_IP4_PRI22_7_POS))
#define INT_IP4_PRI23_4                 ((uint32_t)1<<(INT_IP4_PRI23_4_POS))
#define INT_IP4_PRI23_5                 ((uint32_t)1<<(INT_IP4_PRI23_5_POS))
#define INT_IP4_PRI23_6                 ((uint32_t)1<<(INT_IP4_PRI23_6_POS))
#define INT_IP4_PRI23_7                 ((uint32_t)1<<(INT_IP4_PRI23_7_POS))
/* INT_IP5 λ�� */
#define INT_IP5_PRI24_4_POS             (4)
#define INT_IP5_PRI24_5_POS             (5)
#define INT_IP5_PRI24_6_POS             (6)
#define INT_IP5_PRI24_7_POS             (7)
#define INT_IP5_PRI25_4_POS             (12)
#define INT_IP5_PRI25_5_POS             (13)
#define INT_IP5_PRI25_6_POS             (14)
#define INT_IP5_PRI25_7_POS             (15)
#define INT_IP5_PRI26_4_POS             (20)
#define INT_IP5_PRI26_5_POS             (21)
#define INT_IP5_PRI26_6_POS             (22)
#define INT_IP5_PRI26_7_POS             (23)
#define INT_IP5_PRI27_4_POS             (28)
#define INT_IP5_PRI27_5_POS             (29)
#define INT_IP5_PRI27_6_POS             (30)
#define INT_IP5_PRI27_7_POS             (31)
#define INT_IP5_PRI24_4                 ((uint32_t)1<<(INT_IP5_PRI24_4_POS))
#define INT_IP5_PRI24_5                 ((uint32_t)1<<(INT_IP5_PRI24_5_POS))
#define INT_IP5_PRI24_6                 ((uint32_t)1<<(INT_IP5_PRI24_6_POS))
#define INT_IP5_PRI24_7                 ((uint32_t)1<<(INT_IP5_PRI24_7_POS))
#define INT_IP5_PRI25_4                 ((uint32_t)1<<(INT_IP5_PRI25_4_POS))
#define INT_IP5_PRI25_5                 ((uint32_t)1<<(INT_IP5_PRI25_5_POS))
#define INT_IP5_PRI25_6                 ((uint32_t)1<<(INT_IP5_PRI25_6_POS))
#define INT_IP5_PRI25_7                 ((uint32_t)1<<(INT_IP5_PRI25_7_POS))
#define INT_IP5_PRI26_4                 ((uint32_t)1<<(INT_IP5_PRI26_4_POS))
#define INT_IP5_PRI26_5                 ((uint32_t)1<<(INT_IP5_PRI26_5_POS))
#define INT_IP5_PRI26_6                 ((uint32_t)1<<(INT_IP5_PRI26_6_POS))
#define INT_IP5_PRI26_7                 ((uint32_t)1<<(INT_IP5_PRI26_7_POS))
#define INT_IP5_PRI27_4                 ((uint32_t)1<<(INT_IP5_PRI27_4_POS))
#define INT_IP5_PRI27_5                 ((uint32_t)1<<(INT_IP5_PRI27_5_POS))
#define INT_IP5_PRI27_6                 ((uint32_t)1<<(INT_IP5_PRI27_6_POS))
#define INT_IP5_PRI27_7                 ((uint32_t)1<<(INT_IP5_PRI27_7_POS))

/* INT_IP6 λ�� */
#define INT_IP6_PRI28_4_POS             (4)
#define INT_IP6_PRI28_5_POS             (5)
#define INT_IP6_PRI28_6_POS             (6)
#define INT_IP6_PRI28_7_POS             (7)
#define INT_IP6_PRI29_4_POS             (12)
#define INT_IP6_PRI29_5_POS             (13)
#define INT_IP6_PRI29_6_POS             (14)
#define INT_IP6_PRI29_7_POS             (15)
#define INT_IP6_PRI30_4_POS             (20)
#define INT_IP6_PRI30_5_POS             (21)
#define INT_IP6_PRI30_6_POS             (22)
#define INT_IP6_PRI30_7_POS             (23)
#define INT_IP6_PRI31_4_POS             (28)
#define INT_IP6_PRI31_5_POS             (29)
#define INT_IP6_PRI31_6_POS             (30)
#define INT_IP6_PRI31_7_POS             (31)
#define INT_IP6_PRI28_4                 ((uint32_t)1<<(INT_IP6_PRI28_4_POS))
#define INT_IP6_PRI28_5                 ((uint32_t)1<<(INT_IP6_PRI28_5_POS))
#define INT_IP6_PRI28_6                 ((uint32_t)1<<(INT_IP6_PRI28_6_POS))
#define INT_IP6_PRI28_7                 ((uint32_t)1<<(INT_IP6_PRI28_7_POS))
#define INT_IP6_PRI29_4                 ((uint32_t)1<<(INT_IP6_PRI29_4_POS))
#define INT_IP6_PRI29_5                 ((uint32_t)1<<(INT_IP6_PRI29_5_POS))
#define INT_IP6_PRI29_6                 ((uint32_t)1<<(INT_IP6_PRI29_6_POS))
#define INT_IP6_PRI29_7                 ((uint32_t)1<<(INT_IP6_PRI29_7_POS))
#define INT_IP6_PRI30_4                 ((uint32_t)1<<(INT_IP6_PRI30_4_POS))
#define INT_IP6_PRI30_5                 ((uint32_t)1<<(INT_IP6_PRI30_5_POS))
#define INT_IP6_PRI30_6                 ((uint32_t)1<<(INT_IP6_PRI30_6_POS))
#define INT_IP6_PRI30_7                 ((uint32_t)1<<(INT_IP6_PRI30_7_POS))
#define INT_IP6_PRI31_4                 ((uint32_t)1<<(INT_IP6_PRI31_4_POS))
#define INT_IP6_PRI31_5                 ((uint32_t)1<<(INT_IP6_PRI31_5_POS))
#define INT_IP6_PRI31_6                 ((uint32_t)1<<(INT_IP6_PRI31_6_POS))
#define INT_IP6_PRI31_7                 ((uint32_t)1<<(INT_IP6_PRI31_7_POS))

/* INT_IP7 λ�� */
#define INT_IP7_PRI32_4_POS             (4)
#define INT_IP7_PRI32_5_POS             (5)
#define INT_IP7_PRI32_6_POS             (6)
#define INT_IP7_PRI32_7_POS             (7)
#define INT_IP7_PRI33_4_POS             (12)
#define INT_IP7_PRI33_5_POS             (13)
#define INT_IP7_PRI33_6_POS             (14)
#define INT_IP7_PRI33_7_POS             (15)
#define INT_IP7_PRI34_4_POS             (20)
#define INT_IP7_PRI34_5_POS             (21)
#define INT_IP7_PRI34_6_POS             (22)
#define INT_IP7_PRI34_7_POS             (23)
#define INT_IP7_PRI35_4_POS             (28)
#define INT_IP7_PRI35_5_POS             (29)
#define INT_IP7_PRI35_6_POS             (30)
#define INT_IP7_PRI35_7_POS             (31)
#define INT_IP7_PRI32_4                 ((uint32_t)1<<(INT_IP7_PRI32_4_POS))
#define INT_IP7_PRI32_5                 ((uint32_t)1<<(INT_IP7_PRI32_5_POS))
#define INT_IP7_PRI32_6                 ((uint32_t)1<<(INT_IP7_PRI32_6_POS))
#define INT_IP7_PRI32_7                 ((uint32_t)1<<(INT_IP7_PRI32_7_POS))
#define INT_IP7_PRI33_4                 ((uint32_t)1<<(INT_IP7_PRI33_4_POS))
#define INT_IP7_PRI33_5                 ((uint32_t)1<<(INT_IP7_PRI33_5_POS))
#define INT_IP7_PRI33_6                 ((uint32_t)1<<(INT_IP7_PRI33_6_POS))
#define INT_IP7_PRI33_7                 ((uint32_t)1<<(INT_IP7_PRI33_7_POS))
#define INT_IP7_PRI34_4                 ((uint32_t)1<<(INT_IP7_PRI34_4_POS))
#define INT_IP7_PRI34_5                 ((uint32_t)1<<(INT_IP7_PRI34_5_POS))
#define INT_IP7_PRI34_6                 ((uint32_t)1<<(INT_IP7_PRI34_6_POS))
#define INT_IP7_PRI34_7                 ((uint32_t)1<<(INT_IP7_PRI34_7_POS))
#define INT_IP7_PRI35_4                 ((uint32_t)1<<(INT_IP7_PRI35_4_POS))
#define INT_IP7_PRI35_5                 ((uint32_t)1<<(INT_IP7_PRI35_5_POS))
#define INT_IP7_PRI35_6                 ((uint32_t)1<<(INT_IP7_PRI35_6_POS))
#define INT_IP7_PRI35_7                 ((uint32_t)1<<(INT_IP7_PRI35_7_POS))

/* INT_IP8 λ�� */
#define INT_IP8_PRI36_4_POS             (4)
#define INT_IP8_PRI36_5_POS             (5)
#define INT_IP8_PRI36_6_POS             (6)
#define INT_IP8_PRI36_7_POS             (7)
#define INT_IP8_PRI37_4_POS             (12)
#define INT_IP8_PRI37_5_POS             (13)
#define INT_IP8_PRI37_6_POS             (14)
#define INT_IP8_PRI37_7_POS             (15)
#define INT_IP8_PRI38_4_POS             (20)
#define INT_IP8_PRI38_5_POS             (21)
#define INT_IP8_PRI38_6_POS             (22)
#define INT_IP8_PRI38_7_POS             (23)
#define INT_IP8_PRI39_4_POS             (28)
#define INT_IP8_PRI39_5_POS             (29)
#define INT_IP8_PRI39_6_POS             (30)
#define INT_IP8_PRI39_7_POS             (31)
#define INT_IP8_PRI36_4                 ((uint32_t)1<<(INT_IP8_PRI36_4_POS))
#define INT_IP8_PRI36_5                 ((uint32_t)1<<(INT_IP8_PRI36_5_POS))
#define INT_IP8_PRI36_6                 ((uint32_t)1<<(INT_IP8_PRI36_6_POS))
#define INT_IP8_PRI36_7                 ((uint32_t)1<<(INT_IP8_PRI36_7_POS))
#define INT_IP8_PRI37_4                 ((uint32_t)1<<(INT_IP8_PRI37_4_POS))
#define INT_IP8_PRI37_5                 ((uint32_t)1<<(INT_IP8_PRI37_5_POS))
#define INT_IP8_PRI37_6                 ((uint32_t)1<<(INT_IP8_PRI37_6_POS))
#define INT_IP8_PRI37_7                 ((uint32_t)1<<(INT_IP8_PRI37_7_POS))
#define INT_IP8_PRI38_4                 ((uint32_t)1<<(INT_IP8_PRI38_4_POS))
#define INT_IP8_PRI38_5                 ((uint32_t)1<<(INT_IP8_PRI38_5_POS))
#define INT_IP8_PRI38_6                 ((uint32_t)1<<(INT_IP8_PRI38_6_POS))
#define INT_IP8_PRI38_7                 ((uint32_t)1<<(INT_IP8_PRI38_7_POS))
#define INT_IP8_PRI39_4                 ((uint32_t)1<<(INT_IP8_PRI39_4_POS))
#define INT_IP8_PRI39_5                 ((uint32_t)1<<(INT_IP8_PRI39_5_POS))
#define INT_IP8_PRI39_6                 ((uint32_t)1<<(INT_IP8_PRI39_6_POS))
#define INT_IP8_PRI39_7                 ((uint32_t)1<<(INT_IP8_PRI39_7_POS))

/* INT_IP9 λ�� */
#define INT_IP9_PRI40_4_POS             (4)
#define INT_IP9_PRI40_5_POS             (5)
#define INT_IP9_PRI40_6_POS             (6)
#define INT_IP9_PRI40_7_POS             (7)
#define INT_IP9_PRI41_4_POS             (12)
#define INT_IP9_PRI41_5_POS             (13)
#define INT_IP9_PRI41_6_POS             (14)
#define INT_IP9_PRI41_7_POS             (15)
#define INT_IP9_PRI42_4_POS             (20)
#define INT_IP9_PRI42_5_POS             (21)
#define INT_IP9_PRI42_6_POS             (22)
#define INT_IP9_PRI42_7_POS             (23)
#define INT_IP9_PRI43_4_POS             (28)
#define INT_IP9_PRI43_5_POS             (29)
#define INT_IP9_PRI43_6_POS             (30)
#define INT_IP9_PRI43_7_POS             (31)
#define INT_IP9_PRI40_4                 ((uint32_t)1<<(INT_IP9_PRI40_4_POS))
#define INT_IP9_PRI40_5                 ((uint32_t)1<<(INT_IP9_PRI40_5_POS))
#define INT_IP9_PRI40_6                 ((uint32_t)1<<(INT_IP9_PRI40_6_POS))
#define INT_IP9_PRI40_7                 ((uint32_t)1<<(INT_IP9_PRI40_7_POS))
#define INT_IP9_PRI41_4                 ((uint32_t)1<<(INT_IP9_PRI41_4_POS))
#define INT_IP9_PRI41_5                 ((uint32_t)1<<(INT_IP9_PRI41_5_POS))
#define INT_IP9_PRI41_6                 ((uint32_t)1<<(INT_IP9_PRI41_6_POS))
#define INT_IP9_PRI41_7                 ((uint32_t)1<<(INT_IP9_PRI41_7_POS))
#define INT_IP9_PRI42_4                 ((uint32_t)1<<(INT_IP9_PRI42_4_POS))
#define INT_IP9_PRI42_5                 ((uint32_t)1<<(INT_IP9_PRI42_5_POS))
#define INT_IP9_PRI42_6                 ((uint32_t)1<<(INT_IP9_PRI42_6_POS))
#define INT_IP9_PRI42_7                 ((uint32_t)1<<(INT_IP9_PRI42_7_POS))
#define INT_IP9_PRI43_4                 ((uint32_t)1<<(INT_IP9_PRI43_4_POS))
#define INT_IP9_PRI43_5                 ((uint32_t)1<<(INT_IP9_PRI43_5_POS))
#define INT_IP9_PRI43_6                 ((uint32_t)1<<(INT_IP9_PRI43_6_POS))
#define INT_IP9_PRI43_7                 ((uint32_t)1<<(INT_IP9_PRI43_7_POS))

/* INT_IP10 λ�� */
#define INT_IP10_PRI44_4_POS            (4)
#define INT_IP10_PRI44_5_POS            (5)
#define INT_IP10_PRI44_6_POS            (6)
#define INT_IP10_PRI44_7_POS            (7)
#define INT_IP10_PRI45_4_POS            (12)
#define INT_IP10_PRI45_5_POS            (13)
#define INT_IP10_PRI45_6_POS            (14)
#define INT_IP10_PRI45_7_POS            (15)
#define INT_IP10_PRI46_4_POS            (20)
#define INT_IP10_PRI46_5_POS            (21)
#define INT_IP10_PRI46_6_POS            (22)
#define INT_IP10_PRI46_7_POS            (23)
#define INT_IP10_PRI47_4_POS            (28)
#define INT_IP10_PRI47_5_POS            (29)
#define INT_IP10_PRI47_6_POS            (30)
#define INT_IP10_PRI47_7_POS            (31)
#define INT_IP10_PRI44_4                ((uint32_t)1<<(INT_IP10_PRI44_4_POS))
#define INT_IP10_PRI44_5                ((uint32_t)1<<(INT_IP10_PRI44_5_POS))
#define INT_IP10_PRI44_6                ((uint32_t)1<<(INT_IP10_PRI44_6_POS))
#define INT_IP10_PRI44_7                ((uint32_t)1<<(INT_IP10_PRI44_7_POS))
#define INT_IP10_PRI45_4                ((uint32_t)1<<(INT_IP10_PRI45_4_POS))
#define INT_IP10_PRI45_5                ((uint32_t)1<<(INT_IP10_PRI45_5_POS))
#define INT_IP10_PRI45_6                ((uint32_t)1<<(INT_IP10_PRI45_6_POS))
#define INT_IP10_PRI45_7                ((uint32_t)1<<(INT_IP10_PRI45_7_POS))
#define INT_IP10_PRI46_4                ((uint32_t)1<<(INT_IP10_PRI46_4_POS))
#define INT_IP10_PRI46_5                ((uint32_t)1<<(INT_IP10_PRI46_5_POS))
#define INT_IP10_PRI46_6                ((uint32_t)1<<(INT_IP10_PRI46_6_POS))
#define INT_IP10_PRI46_7                ((uint32_t)1<<(INT_IP10_PRI46_7_POS))
#define INT_IP10_PRI47_4                ((uint32_t)1<<(INT_IP10_PRI47_4_POS))
#define INT_IP10_PRI47_5                ((uint32_t)1<<(INT_IP10_PRI47_5_POS))
#define INT_IP10_PRI47_6                ((uint32_t)1<<(INT_IP10_PRI47_6_POS))
#define INT_IP10_PRI47_7                ((uint32_t)1<<(INT_IP10_PRI47_7_POS))

/* INT_IP11 λ�� */
#define INT_IP11_PRI48_4_POS            (4)
#define INT_IP11_PRI48_5_POS            (5)
#define INT_IP11_PRI48_6_POS            (6)
#define INT_IP11_PRI48_7_POS            (7)
#define INT_IP11_PRI49_4_POS            (12)
#define INT_IP11_PRI49_5_POS            (13)
#define INT_IP11_PRI49_6_POS            (14)
#define INT_IP11_PRI49_7_POS            (15)
#define INT_IP11_PRI50_4_POS            (20)
#define INT_IP11_PRI50_5_POS            (21)
#define INT_IP11_PRI50_6_POS            (22)
#define INT_IP11_PRI50_7_POS            (23)
#define INT_IP11_PRI51_4_POS            (28)
#define INT_IP11_PRI51_5_POS            (29)
#define INT_IP11_PRI51_6_POS            (30)
#define INT_IP11_PRI51_7_POS            (31)
#define INT_IP11_PRI48_4                ((uint32_t)1<<(INT_IP11_PRI48_4_POS))
#define INT_IP11_PRI48_5                ((uint32_t)1<<(INT_IP11_PRI48_5_POS))
#define INT_IP11_PRI48_6                ((uint32_t)1<<(INT_IP11_PRI48_6_POS))
#define INT_IP11_PRI48_7                ((uint32_t)1<<(INT_IP11_PRI48_7_POS))
#define INT_IP11_PRI49_4                ((uint32_t)1<<(INT_IP11_PRI49_4_POS))
#define INT_IP11_PRI49_5                ((uint32_t)1<<(INT_IP11_PRI49_5_POS))
#define INT_IP11_PRI49_6                ((uint32_t)1<<(INT_IP11_PRI49_6_POS))
#define INT_IP11_PRI49_7                ((uint32_t)1<<(INT_IP11_PRI49_7_POS))
#define INT_IP11_PRI50_4                ((uint32_t)1<<(INT_IP11_PRI50_4_POS))
#define INT_IP11_PRI50_5                ((uint32_t)1<<(INT_IP11_PRI50_5_POS))
#define INT_IP11_PRI50_6                ((uint32_t)1<<(INT_IP11_PRI50_6_POS))
#define INT_IP11_PRI50_7                ((uint32_t)1<<(INT_IP11_PRI50_7_POS))
#define INT_IP11_PRI51_4                ((uint32_t)1<<(INT_IP11_PRI51_4_POS))
#define INT_IP11_PRI51_5                ((uint32_t)1<<(INT_IP11_PRI51_5_POS))
#define INT_IP11_PRI51_6                ((uint32_t)1<<(INT_IP11_PRI51_6_POS))
#define INT_IP11_PRI51_7                ((uint32_t)1<<(INT_IP11_PRI51_7_POS))

/* INT_IP12 λ�� */
#define INT_IP12_PRI52_4_POS            (4)
#define INT_IP12_PRI52_5_POS            (5)
#define INT_IP12_PRI52_6_POS            (6)
#define INT_IP12_PRI52_7_POS            (7)
#define INT_IP12_PRI53_4_POS            (12)
#define INT_IP12_PRI53_5_POS            (13)
#define INT_IP12_PRI53_6_POS            (14)
#define INT_IP12_PRI53_7_POS            (15)
#define INT_IP12_PRI54_4_POS            (20)
#define INT_IP12_PRI54_5_POS            (21)
#define INT_IP12_PRI54_6_POS            (22)
#define INT_IP12_PRI54_7_POS            (23)
#define INT_IP12_PRI55_4_POS            (28)
#define INT_IP12_PRI55_5_POS            (29)
#define INT_IP12_PRI55_6_POS            (30)
#define INT_IP12_PRI55_7_POS            (31)
#define INT_IP12_PRI52_4                ((uint32_t)1<<(INT_IP12_PRI52_4_POS))
#define INT_IP12_PRI52_5                ((uint32_t)1<<(INT_IP12_PRI52_5_POS))
#define INT_IP12_PRI52_6                ((uint32_t)1<<(INT_IP12_PRI52_6_POS))
#define INT_IP12_PRI52_7                ((uint32_t)1<<(INT_IP12_PRI52_7_POS))
#define INT_IP12_PRI53_4                ((uint32_t)1<<(INT_IP12_PRI53_4_POS))
#define INT_IP12_PRI53_5                ((uint32_t)1<<(INT_IP12_PRI53_5_POS))
#define INT_IP12_PRI53_6                ((uint32_t)1<<(INT_IP12_PRI53_6_POS))
#define INT_IP12_PRI53_7                ((uint32_t)1<<(INT_IP12_PRI53_7_POS))
#define INT_IP12_PRI54_4                ((uint32_t)1<<(INT_IP12_PRI54_4_POS))
#define INT_IP12_PRI54_5                ((uint32_t)1<<(INT_IP12_PRI54_5_POS))
#define INT_IP12_PRI54_6                ((uint32_t)1<<(INT_IP12_PRI54_6_POS))
#define INT_IP12_PRI54_7                ((uint32_t)1<<(INT_IP12_PRI54_7_POS))
#define INT_IP12_PRI55_4                ((uint32_t)1<<(INT_IP12_PRI55_4_POS))
#define INT_IP12_PRI55_5                ((uint32_t)1<<(INT_IP12_PRI55_5_POS))
#define INT_IP12_PRI55_6                ((uint32_t)1<<(INT_IP12_PRI55_6_POS))
#define INT_IP12_PRI55_7                ((uint32_t)1<<(INT_IP12_PRI55_7_POS))

/* INT_IP13 λ�� */
#define INT_IP13_PRI56_4_POS            (4)
#define INT_IP13_PRI56_5_POS            (5)
#define INT_IP13_PRI56_6_POS            (6)
#define INT_IP13_PRI56_7_POS            (7)
#define INT_IP13_PRI57_4_POS            (12)
#define INT_IP13_PRI57_5_POS            (13)
#define INT_IP13_PRI57_6_POS            (14)
#define INT_IP13_PRI57_7_POS            (15)
#define INT_IP13_PRI58_4_POS            (20)
#define INT_IP13_PRI58_5_POS            (21)
#define INT_IP13_PRI58_6_POS            (22)
#define INT_IP13_PRI58_7_POS            (23)
#define INT_IP13_PRI59_4_POS            (28)
#define INT_IP13_PRI59_5_POS            (29)
#define INT_IP13_PRI59_6_POS            (30)
#define INT_IP13_PRI59_7_POS            (31)
#define INT_IP13_PRI56_4                ((uint32_t)1<<(INT_IP13_PRI56_4_POS))
#define INT_IP13_PRI56_5                ((uint32_t)1<<(INT_IP13_PRI56_5_POS))
#define INT_IP13_PRI56_6                ((uint32_t)1<<(INT_IP13_PRI56_6_POS))
#define INT_IP13_PRI56_7                ((uint32_t)1<<(INT_IP13_PRI56_7_POS))
#define INT_IP13_PRI57_4                ((uint32_t)1<<(INT_IP13_PRI57_4_POS))
#define INT_IP13_PRI57_5                ((uint32_t)1<<(INT_IP13_PRI57_5_POS))
#define INT_IP13_PRI57_6                ((uint32_t)1<<(INT_IP13_PRI57_6_POS))
#define INT_IP13_PRI57_7                ((uint32_t)1<<(INT_IP13_PRI57_7_POS))
#define INT_IP13_PRI58_4                ((uint32_t)1<<(INT_IP13_PRI58_4_POS))
#define INT_IP13_PRI58_5                ((uint32_t)1<<(INT_IP13_PRI58_5_POS))
#define INT_IP13_PRI58_6                ((uint32_t)1<<(INT_IP13_PRI58_6_POS))
#define INT_IP13_PRI58_7                ((uint32_t)1<<(INT_IP13_PRI58_7_POS))
#define INT_IP13_PRI59_4                ((uint32_t)1<<(INT_IP13_PRI59_4_POS))
#define INT_IP13_PRI59_5                ((uint32_t)1<<(INT_IP13_PRI59_5_POS))
#define INT_IP13_PRI59_6                ((uint32_t)1<<(INT_IP13_PRI59_6_POS))
#define INT_IP13_PRI59_7                ((uint32_t)1<<(INT_IP13_PRI59_7_POS))

/* INT_IP14 λ�� */
#define INT_IP14_PRI60_4_POS            (4)
#define INT_IP14_PRI60_5_POS            (5)
#define INT_IP14_PRI60_6_POS            (6)
#define INT_IP14_PRI60_7_POS            (7)
#define INT_IP14_PRI61_4_POS            (12)
#define INT_IP14_PRI61_5_POS            (13)
#define INT_IP14_PRI61_6_POS            (14)
#define INT_IP14_PRI61_7_POS            (15)
#define INT_IP14_PRI62_4_POS            (20)
#define INT_IP14_PRI62_5_POS            (21)
#define INT_IP14_PRI62_6_POS            (22)
#define INT_IP14_PRI62_7_POS            (23)
#define INT_IP14_PRI63_4_POS            (28)
#define INT_IP14_PRI63_5_POS            (29)
#define INT_IP14_PRI63_6_POS            (30)
#define INT_IP14_PRI63_7_POS            (31)
#define INT_IP14_PRI60_4                ((uint32_t)1<<(INT_IP14_PRI60_4_POS))
#define INT_IP14_PRI60_5                ((uint32_t)1<<(INT_IP14_PRI60_5_POS))
#define INT_IP14_PRI60_6                ((uint32_t)1<<(INT_IP14_PRI60_6_POS))
#define INT_IP14_PRI60_7                ((uint32_t)1<<(INT_IP14_PRI60_7_POS))
#define INT_IP14_PRI61_4                ((uint32_t)1<<(INT_IP14_PRI61_4_POS))
#define INT_IP14_PRI61_5                ((uint32_t)1<<(INT_IP14_PRI61_5_POS))
#define INT_IP14_PRI61_6                ((uint32_t)1<<(INT_IP14_PRI61_6_POS))
#define INT_IP14_PRI61_7                ((uint32_t)1<<(INT_IP14_PRI61_7_POS))
#define INT_IP14_PRI62_4                ((uint32_t)1<<(INT_IP14_PRI62_4_POS))
#define INT_IP14_PRI62_5                ((uint32_t)1<<(INT_IP14_PRI62_5_POS))
#define INT_IP14_PRI62_6                ((uint32_t)1<<(INT_IP14_PRI62_6_POS))
#define INT_IP14_PRI62_7                ((uint32_t)1<<(INT_IP14_PRI62_7_POS))
#define INT_IP14_PRI63_4                ((uint32_t)1<<(INT_IP14_PRI63_4_POS))
#define INT_IP14_PRI63_5                ((uint32_t)1<<(INT_IP14_PRI63_5_POS))
#define INT_IP14_PRI63_6                ((uint32_t)1<<(INT_IP14_PRI63_6_POS))
#define INT_IP14_PRI63_7                ((uint32_t)1<<(INT_IP14_PRI63_7_POS))

/* INT_IP15 λ�� */
#define INT_IP15_PRI64_4_POS            (4)
#define INT_IP15_PRI64_5_POS            (5)
#define INT_IP15_PRI64_6_POS            (6)
#define INT_IP15_PRI64_7_POS            (7)
#define INT_IP15_PRI65_4_POS            (12)
#define INT_IP15_PRI65_5_POS            (13)
#define INT_IP15_PRI65_6_POS            (14)
#define INT_IP15_PRI65_7_POS            (15)
#define INT_IP15_PRI66_4_POS            (20)
#define INT_IP15_PRI66_5_POS            (21)
#define INT_IP15_PRI66_6_POS            (22)
#define INT_IP15_PRI66_7_POS            (23)
#define INT_IP15_PRI67_4_POS            (28)
#define INT_IP15_PRI67_5_POS            (29)
#define INT_IP15_PRI67_6_POS            (30)
#define INT_IP15_PRI67_7_POS            (31)
#define INT_IP15_PRI64_4                ((uint32_t)1<<(INT_IP15_PRI64_4_POS))
#define INT_IP15_PRI64_5                ((uint32_t)1<<(INT_IP15_PRI64_5_POS))
#define INT_IP15_PRI64_6                ((uint32_t)1<<(INT_IP15_PRI64_6_POS))
#define INT_IP15_PRI64_7                ((uint32_t)1<<(INT_IP15_PRI64_7_POS))
#define INT_IP15_PRI65_4                ((uint32_t)1<<(INT_IP15_PRI65_4_POS))
#define INT_IP15_PRI65_5                ((uint32_t)1<<(INT_IP15_PRI65_5_POS))
#define INT_IP15_PRI65_6                ((uint32_t)1<<(INT_IP15_PRI65_6_POS))
#define INT_IP15_PRI65_7                ((uint32_t)1<<(INT_IP15_PRI65_7_POS))
#define INT_IP15_PRI66_4                ((uint32_t)1<<(INT_IP15_PRI66_4_POS))
#define INT_IP15_PRI66_5                ((uint32_t)1<<(INT_IP15_PRI66_5_POS))
#define INT_IP15_PRI66_6                ((uint32_t)1<<(INT_IP15_PRI66_6_POS))
#define INT_IP15_PRI66_7                ((uint32_t)1<<(INT_IP15_PRI66_7_POS))
#define INT_IP15_PRI67_4                ((uint32_t)1<<(INT_IP15_PRI67_4_POS))
#define INT_IP15_PRI67_5                ((uint32_t)1<<(INT_IP15_PRI67_5_POS))
#define INT_IP15_PRI67_6                ((uint32_t)1<<(INT_IP15_PRI67_6_POS))
#define INT_IP15_PRI67_7                ((uint32_t)1<<(INT_IP15_PRI67_7_POS))

/* INT_IP16 λ�� */
#define INT_IP16_PRI68_4_POS            (4)
#define INT_IP16_PRI68_5_POS            (5)
#define INT_IP16_PRI68_6_POS            (6)
#define INT_IP16_PRI68_7_POS            (7)
#define INT_IP16_PRI69_4_POS            (12)
#define INT_IP16_PRI69_5_POS            (13)
#define INT_IP16_PRI69_6_POS            (14)
#define INT_IP16_PRI69_7_POS            (15)
#define INT_IP16_PRI70_4_POS            (20)
#define INT_IP16_PRI70_5_POS            (21)
#define INT_IP16_PRI70_6_POS            (22)
#define INT_IP16_PRI70_7_POS            (23)
#define INT_IP16_PRI71_4_POS            (28)
#define INT_IP16_PRI71_5_POS            (29)
#define INT_IP16_PRI71_6_POS            (30)
#define INT_IP16_PRI71_7_POS            (31)
#define INT_IP16_PRI68_4                ((uint32_t)1<<(INT_IP16_PRI68_4_POS))
#define INT_IP16_PRI68_5                ((uint32_t)1<<(INT_IP16_PRI68_5_POS))
#define INT_IP16_PRI68_6                ((uint32_t)1<<(INT_IP16_PRI68_6_POS))
#define INT_IP16_PRI68_7                ((uint32_t)1<<(INT_IP16_PRI68_7_POS))
#define INT_IP16_PRI69_4                ((uint32_t)1<<(INT_IP16_PRI69_4_POS))
#define INT_IP16_PRI69_5                ((uint32_t)1<<(INT_IP16_PRI69_5_POS))
#define INT_IP16_PRI69_6                ((uint32_t)1<<(INT_IP16_PRI69_6_POS))
#define INT_IP16_PRI69_7                ((uint32_t)1<<(INT_IP16_PRI69_7_POS))
#define INT_IP16_PRI70_4                ((uint32_t)1<<(INT_IP16_PRI70_4_POS))
#define INT_IP16_PRI70_5                ((uint32_t)1<<(INT_IP16_PRI70_5_POS))
#define INT_IP16_PRI70_6                ((uint32_t)1<<(INT_IP16_PRI70_6_POS))
#define INT_IP16_PRI70_7                ((uint32_t)1<<(INT_IP16_PRI70_7_POS))
#define INT_IP16_PRI71_4                ((uint32_t)1<<(INT_IP16_PRI71_4_POS))
#define INT_IP16_PRI71_5                ((uint32_t)1<<(INT_IP16_PRI71_5_POS))
#define INT_IP16_PRI71_6                ((uint32_t)1<<(INT_IP16_PRI71_6_POS))
#define INT_IP16_PRI71_7                ((uint32_t)1<<(INT_IP16_PRI71_7_POS))

/* INT_IP17 λ�� */
#define INT_IP17_PRI72_4_POS            (4)
#define INT_IP17_PRI72_5_POS            (5)
#define INT_IP17_PRI72_6_POS            (6)
#define INT_IP17_PRI72_7_POS            (7)
#define INT_IP17_PRI73_4_POS            (12)
#define INT_IP17_PRI73_5_POS            (13)
#define INT_IP17_PRI73_6_POS            (14)
#define INT_IP17_PRI73_7_POS            (15)
#define INT_IP17_PRI74_4_POS            (20)
#define INT_IP17_PRI74_5_POS            (21)
#define INT_IP17_PRI74_6_POS            (22)
#define INT_IP17_PRI74_7_POS            (23)
#define INT_IP17_PRI75_4_POS            (28)
#define INT_IP17_PRI75_5_POS            (29)
#define INT_IP17_PRI75_6_POS            (30)
#define INT_IP17_PRI75_7_POS            (31)
#define INT_IP17_PRI72_4                ((uint32_t)1<<(INT_IP17_PRI72_4_POS))
#define INT_IP17_PRI72_5                ((uint32_t)1<<(INT_IP17_PRI72_5_POS))
#define INT_IP17_PRI72_6                ((uint32_t)1<<(INT_IP17_PRI72_6_POS))
#define INT_IP17_PRI72_7                ((uint32_t)1<<(INT_IP17_PRI72_7_POS))
#define INT_IP17_PRI73_4                ((uint32_t)1<<(INT_IP17_PRI73_4_POS))
#define INT_IP17_PRI73_5                ((uint32_t)1<<(INT_IP17_PRI73_5_POS))
#define INT_IP17_PRI73_6                ((uint32_t)1<<(INT_IP17_PRI73_6_POS))
#define INT_IP17_PRI73_7                ((uint32_t)1<<(INT_IP17_PRI73_7_POS))
#define INT_IP17_PRI74_4                ((uint32_t)1<<(INT_IP17_PRI74_4_POS))
#define INT_IP17_PRI74_5                ((uint32_t)1<<(INT_IP17_PRI74_5_POS))
#define INT_IP17_PRI74_6                ((uint32_t)1<<(INT_IP17_PRI74_6_POS))
#define INT_IP17_PRI74_7                ((uint32_t)1<<(INT_IP17_PRI74_7_POS))
#define INT_IP17_PRI75_4                ((uint32_t)1<<(INT_IP17_PRI75_4_POS))
#define INT_IP17_PRI75_5                ((uint32_t)1<<(INT_IP17_PRI75_5_POS))
#define INT_IP17_PRI75_6                ((uint32_t)1<<(INT_IP17_PRI75_6_POS))
#define INT_IP17_PRI75_7                ((uint32_t)1<<(INT_IP17_PRI75_7_POS))

/* INT_IP18 λ�� */
#define INT_IP18_PRI76_4_POS            (4)
#define INT_IP18_PRI76_5_POS            (5)
#define INT_IP18_PRI76_6_POS            (6)
#define INT_IP18_PRI76_7_POS            (7)
#define INT_IP18_PRI77_4_POS            (12)
#define INT_IP18_PRI77_5_POS            (13)
#define INT_IP18_PRI77_6_POS            (14)
#define INT_IP18_PRI77_7_POS            (15)
#define INT_IP18_PRI78_4_POS            (20)
#define INT_IP18_PRI78_5_POS            (21)
#define INT_IP18_PRI78_6_POS            (22)
#define INT_IP18_PRI78_7_POS            (23)
#define INT_IP18_PRI79_4_POS            (28)
#define INT_IP18_PRI79_5_POS            (29)
#define INT_IP18_PRI79_6_POS            (30)
#define INT_IP18_PRI79_7_POS            (31)
#define INT_IP18_PRI76_4                ((uint32_t)1<<(INT_IP18_PRI76_4_POS))
#define INT_IP18_PRI76_5                ((uint32_t)1<<(INT_IP18_PRI76_5_POS))
#define INT_IP18_PRI76_6                ((uint32_t)1<<(INT_IP18_PRI76_6_POS))
#define INT_IP18_PRI76_7                ((uint32_t)1<<(INT_IP18_PRI76_7_POS))
#define INT_IP18_PRI77_4                ((uint32_t)1<<(INT_IP18_PRI77_4_POS))
#define INT_IP18_PRI77_5                ((uint32_t)1<<(INT_IP18_PRI77_5_POS))
#define INT_IP18_PRI77_6                ((uint32_t)1<<(INT_IP18_PRI77_6_POS))
#define INT_IP18_PRI77_7                ((uint32_t)1<<(INT_IP18_PRI77_7_POS))
#define INT_IP18_PRI78_4                ((uint32_t)1<<(INT_IP18_PRI78_4_POS))
#define INT_IP18_PRI78_5                ((uint32_t)1<<(INT_IP18_PRI78_5_POS))
#define INT_IP18_PRI78_6                ((uint32_t)1<<(INT_IP18_PRI78_6_POS))
#define INT_IP18_PRI78_7                ((uint32_t)1<<(INT_IP18_PRI78_7_POS))
#define INT_IP18_PRI79_4                ((uint32_t)1<<(INT_IP18_PRI79_4_POS))
#define INT_IP18_PRI79_5                ((uint32_t)1<<(INT_IP18_PRI79_5_POS))
#define INT_IP18_PRI79_6                ((uint32_t)1<<(INT_IP18_PRI79_6_POS))
#define INT_IP18_PRI79_7                ((uint32_t)1<<(INT_IP18_PRI79_7_POS))

/* INT_EINTMASK λ�� */
#define INT_EINTMASK_EINTM0_POS         (0)
#define INT_EINTMASK_EINTM1_POS         (1)
#define INT_EINTMASK_EINTM2_POS         (2)
#define INT_EINTMASK_EINTM3_POS         (3)
#define INT_EINTMASK_EINTM4_POS         (4)
#define INT_EINTMASK_EINTM5_POS         (5)
#define INT_EINTMASK_EINTM6_POS         (6)
#define INT_EINTMASK_EINTM7_POS         (7)
#define INT_EINTMASK_EINTM8_POS         (8)
#define INT_EINTMASK_EINTM9_POS         (9)
#define INT_EINTMASK_EINTM10_POS        (10)
#define INT_EINTMASK_EINTM11_POS        (11)
#define INT_EINTMASK_EINTM12_POS        (12)
#define INT_EINTMASK_EINTM13_POS        (13)
#define INT_EINTMASK_EINTM14_POS        (14)
#define INT_EINTMASK_EINTM15_POS        (15)
#define INT_EINTMASK_EINTM16_POS        (16)
#define INT_EINTMASK_EINTM17_POS        (17)
#define INT_EINTMASK_EINTM18_POS        (18)
#define INT_EINTMASK_EINTM19_POS        (19)
#define INT_EINTMASK_EINTM20_POS        (20)
#define INT_EINTMASK_EINTM21_POS        (21)
#define INT_EINTMASK_EINTM22_POS        (22)
#define INT_EINTMASK_EINTM23_POS        (23)
#define INT_EINTMASK_EINTM24_POS        (24)
#define INT_EINTMASK_EINTM25_POS        (25)
#define INT_EINTMASK_EINTM26_POS        (26)
#define INT_EINTMASK_EINTM27_POS        (27)
#define INT_EINTMASK_EINTM28_POS        (28)
#define INT_EINTMASK_EINTM29_POS        (29)
#define INT_EINTMASK_EINTM30_POS        (30)
#define INT_EINTMASK_EINTM31_POS        (31)
#define INT_EINTMASK_EINTM0             ((uint32_t)1<<(INT_EINTMASK_EINTM0_POS))
#define INT_EINTMASK_EINTM1             ((uint32_t)1<<(INT_EINTMASK_EINTM1_POS))
#define INT_EINTMASK_EINTM2             ((uint32_t)1<<(INT_EINTMASK_EINTM2_POS))
#define INT_EINTMASK_EINTM3             ((uint32_t)1<<(INT_EINTMASK_EINTM3_POS))
#define INT_EINTMASK_EINTM4             ((uint32_t)1<<(INT_EINTMASK_EINTM4_POS))
#define INT_EINTMASK_EINTM5             ((uint32_t)1<<(INT_EINTMASK_EINTM5_POS))
#define INT_EINTMASK_EINTM6             ((uint32_t)1<<(INT_EINTMASK_EINTM6_POS))
#define INT_EINTMASK_EINTM7             ((uint32_t)1<<(INT_EINTMASK_EINTM7_POS))
#define INT_EINTMASK_EINTM8             ((uint32_t)1<<(INT_EINTMASK_EINTM8_POS))
#define INT_EINTMASK_EINTM9             ((uint32_t)1<<(INT_EINTMASK_EINTM9_POS))
#define INT_EINTMASK_EINTM10            ((uint32_t)1<<(INT_EINTMASK_EINTM10_POS))
#define INT_EINTMASK_EINTM11            ((uint32_t)1<<(INT_EINTMASK_EINTM11_POS))
#define INT_EINTMASK_EINTM12            ((uint32_t)1<<(INT_EINTMASK_EINTM12_POS))
#define INT_EINTMASK_EINTM13            ((uint32_t)1<<(INT_EINTMASK_EINTM13_POS))
#define INT_EINTMASK_EINTM14            ((uint32_t)1<<(INT_EINTMASK_EINTM14_POS))
#define INT_EINTMASK_EINTM15            ((uint32_t)1<<(INT_EINTMASK_EINTM15_POS))
#define INT_EINTMASK_EINTM16            ((uint32_t)1<<(INT_EINTMASK_EINTM16_POS))
#define INT_EINTMASK_EINTM17            ((uint32_t)1<<(INT_EINTMASK_EINTM17_POS))
#define INT_EINTMASK_EINTM18            ((uint32_t)1<<(INT_EINTMASK_EINTM18_POS))
#define INT_EINTMASK_EINTM19            ((uint32_t)1<<(INT_EINTMASK_EINTM19_POS))
#define INT_EINTMASK_EINTM20            ((uint32_t)1<<(INT_EINTMASK_EINTM20_POS))
#define INT_EINTMASK_EINTM21            ((uint32_t)1<<(INT_EINTMASK_EINTM21_POS))
#define INT_EINTMASK_EINTM22            ((uint32_t)1<<(INT_EINTMASK_EINTM22_POS))
#define INT_EINTMASK_EINTM23            ((uint32_t)1<<(INT_EINTMASK_EINTM23_POS))
#define INT_EINTMASK_EINTM24            ((uint32_t)1<<(INT_EINTMASK_EINTM24_POS))
#define INT_EINTMASK_EINTM25            ((uint32_t)1<<(INT_EINTMASK_EINTM25_POS))
#define INT_EINTMASK_EINTM26            ((uint32_t)1<<(INT_EINTMASK_EINTM26_POS))
#define INT_EINTMASK_EINTM27            ((uint32_t)1<<(INT_EINTMASK_EINTM27_POS))
#define INT_EINTMASK_EINTM28            ((uint32_t)1<<(INT_EINTMASK_EINTM28_POS))
#define INT_EINTMASK_EINTM29            ((uint32_t)1<<(INT_EINTMASK_EINTM29_POS))
#define INT_EINTMASK_EINTM30            ((uint32_t)1<<(INT_EINTMASK_EINTM30_POS))
#define INT_EINTMASK_EINTM31            ((uint32_t)1<<(INT_EINTMASK_EINTM31_POS))

/* INT_EINTRISE λ�� */
#define INT_EINTRISE_EINTRI0_POS        (0)
#define INT_EINTRISE_EINTRI1_POS        (1)
#define INT_EINTRISE_EINTRI2_POS        (2)
#define INT_EINTRISE_EINTRI3_POS        (3)
#define INT_EINTRISE_EINTRI4_POS        (4)
#define INT_EINTRISE_EINTRI5_POS        (5)
#define INT_EINTRISE_EINTRI6_POS        (6)
#define INT_EINTRISE_EINTRI7_POS        (7)
#define INT_EINTRISE_EINTRI8_POS        (8)
#define INT_EINTRISE_EINTRI9_POS        (9)
#define INT_EINTRISE_EINTRI10_POS       (10)
#define INT_EINTRISE_EINTRI11_POS       (11)
#define INT_EINTRISE_EINTRI12_POS       (12)
#define INT_EINTRISE_EINTRI13_POS       (13)
#define INT_EINTRISE_EINTRI14_POS       (14)
#define INT_EINTRISE_EINTRI15_POS       (15)
#define INT_EINTRISE_EINTRI16_POS       (16)
#define INT_EINTRISE_EINTRI17_POS       (17)
#define INT_EINTRISE_EINTRI18_POS       (18)
#define INT_EINTRISE_EINTRI19_POS       (19)
#define INT_EINTRISE_EINTRI20_POS       (20)
#define INT_EINTRISE_EINTRI21_POS       (21)
#define INT_EINTRISE_EINTRI22_POS       (22)
#define INT_EINTRISE_EINTRI23_POS       (23)
#define INT_EINTRISE_EINTRI24_POS       (24)
#define INT_EINTRISE_EINTRI25_POS       (25)
#define INT_EINTRISE_EINTRI26_POS       (26)
#define INT_EINTRISE_EINTRI27_POS       (27)
#define INT_EINTRISE_EINTRI28_POS       (28)
#define INT_EINTRISE_EINTRI29_POS       (29)
#define INT_EINTRISE_EINTRI30_POS       (30)
#define INT_EINTRISE_EINTRI31_POS       (31)
#define INT_EINTRISE_EINTRI0            ((uint32_t)1<<(INT_EINTRISE_EINTRI0_POS))
#define INT_EINTRISE_EINTRI1            ((uint32_t)1<<(INT_EINTRISE_EINTRI1_POS))
#define INT_EINTRISE_EINTRI2            ((uint32_t)1<<(INT_EINTRISE_EINTRI2_POS))
#define INT_EINTRISE_EINTRI3            ((uint32_t)1<<(INT_EINTRISE_EINTRI3_POS))
#define INT_EINTRISE_EINTRI4            ((uint32_t)1<<(INT_EINTRISE_EINTRI4_POS))
#define INT_EINTRISE_EINTRI5            ((uint32_t)1<<(INT_EINTRISE_EINTRI5_POS))
#define INT_EINTRISE_EINTRI6            ((uint32_t)1<<(INT_EINTRISE_EINTRI6_POS))
#define INT_EINTRISE_EINTRI7            ((uint32_t)1<<(INT_EINTRISE_EINTRI7_POS))
#define INT_EINTRISE_EINTRI8            ((uint32_t)1<<(INT_EINTRISE_EINTRI8_POS))
#define INT_EINTRISE_EINTRI9            ((uint32_t)1<<(INT_EINTRISE_EINTRI9_POS))
#define INT_EINTRISE_EINTRI10           ((uint32_t)1<<(INT_EINTRISE_EINTRI10_POS))
#define INT_EINTRISE_EINTRI11           ((uint32_t)1<<(INT_EINTRISE_EINTRI11_POS))
#define INT_EINTRISE_EINTRI12           ((uint32_t)1<<(INT_EINTRISE_EINTRI12_POS))
#define INT_EINTRISE_EINTRI13           ((uint32_t)1<<(INT_EINTRISE_EINTRI13_POS))
#define INT_EINTRISE_EINTRI14           ((uint32_t)1<<(INT_EINTRISE_EINTRI14_POS))
#define INT_EINTRISE_EINTRI15           ((uint32_t)1<<(INT_EINTRISE_EINTRI15_POS))
#define INT_EINTRISE_EINTRI16           ((uint32_t)1<<(INT_EINTRISE_EINTRI16_POS))
#define INT_EINTRISE_EINTRI17           ((uint32_t)1<<(INT_EINTRISE_EINTRI17_POS))
#define INT_EINTRISE_EINTRI18           ((uint32_t)1<<(INT_EINTRISE_EINTRI18_POS))
#define INT_EINTRISE_EINTRI19           ((uint32_t)1<<(INT_EINTRISE_EINTRI19_POS))
#define INT_EINTRISE_EINTRI20           ((uint32_t)1<<(INT_EINTRISE_EINTRI20_POS))
#define INT_EINTRISE_EINTRI21           ((uint32_t)1<<(INT_EINTRISE_EINTRI21_POS))
#define INT_EINTRISE_EINTRI22           ((uint32_t)1<<(INT_EINTRISE_EINTRI22_POS))
#define INT_EINTRISE_EINTRI23           ((uint32_t)1<<(INT_EINTRISE_EINTRI23_POS))
#define INT_EINTRISE_EINTRI24           ((uint32_t)1<<(INT_EINTRISE_EINTRI24_POS))
#define INT_EINTRISE_EINTRI25           ((uint32_t)1<<(INT_EINTRISE_EINTRI25_POS))
#define INT_EINTRISE_EINTRI26           ((uint32_t)1<<(INT_EINTRISE_EINTRI26_POS))
#define INT_EINTRISE_EINTRI27           ((uint32_t)1<<(INT_EINTRISE_EINTRI27_POS))
#define INT_EINTRISE_EINTRI28           ((uint32_t)1<<(INT_EINTRISE_EINTRI28_POS))
#define INT_EINTRISE_EINTRI29           ((uint32_t)1<<(INT_EINTRISE_EINTRI29_POS))
#define INT_EINTRISE_EINTRI30           ((uint32_t)1<<(INT_EINTRISE_EINTRI30_POS))
#define INT_EINTRISE_EINTRI31           ((uint32_t)1<<(INT_EINTRISE_EINTRI31_POS))

/* INT_EINTFALL λ�� */
#define INT_EINTFALL_EINTFA0_POS        (0)
#define INT_EINTFALL_EINTFA1_POS        (1)
#define INT_EINTFALL_EINTFA2_POS        (2)
#define INT_EINTFALL_EINTFA3_POS        (3)
#define INT_EINTFALL_EINTFA4_POS        (4)
#define INT_EINTFALL_EINTFA5_POS        (5)
#define INT_EINTFALL_EINTFA6_POS        (6)
#define INT_EINTFALL_EINTFA7_POS        (7)
#define INT_EINTFALL_EINTFA8_POS        (8)
#define INT_EINTFALL_EINTFA9_POS        (9)
#define INT_EINTFALL_EINTFA10_POS       (10)
#define INT_EINTFALL_EINTFA11_POS       (11)
#define INT_EINTFALL_EINTFA12_POS       (12)
#define INT_EINTFALL_EINTFA13_POS       (13)
#define INT_EINTFALL_EINTFA14_POS       (14)
#define INT_EINTFALL_EINTFA15_POS       (15)
#define INT_EINTFALL_EINTFA16_POS       (16)
#define INT_EINTFALL_EINTFA17_POS       (17)
#define INT_EINTFALL_EINTFA18_POS       (18)
#define INT_EINTFALL_EINTFA19_POS       (19)
#define INT_EINTFALL_EINTFA20_POS       (20)
#define INT_EINTFALL_EINTFA21_POS       (21)
#define INT_EINTFALL_EINTFA22_POS       (22)
#define INT_EINTFALL_EINTFA23_POS       (23)
#define INT_EINTFALL_EINTFA24_POS       (24)
#define INT_EINTFALL_EINTFA25_POS       (25)
#define INT_EINTFALL_EINTFA26_POS       (26)
#define INT_EINTFALL_EINTFA27_POS       (27)
#define INT_EINTFALL_EINTFA28_POS       (28)
#define INT_EINTFALL_EINTFA29_POS       (29)
#define INT_EINTFALL_EINTFA30_POS       (30)
#define INT_EINTFALL_EINTFA31_POS       (31)
#define INT_EINTFALL_EINTFA0            ((uint32_t)1<<(INT_EINTFALL_EINTFA0_POS))
#define INT_EINTFALL_EINTFA1            ((uint32_t)1<<(INT_EINTFALL_EINTFA1_POS))
#define INT_EINTFALL_EINTFA2            ((uint32_t)1<<(INT_EINTFALL_EINTFA2_POS))
#define INT_EINTFALL_EINTFA3            ((uint32_t)1<<(INT_EINTFALL_EINTFA3_POS))
#define INT_EINTFALL_EINTFA4            ((uint32_t)1<<(INT_EINTFALL_EINTFA4_POS))
#define INT_EINTFALL_EINTFA5            ((uint32_t)1<<(INT_EINTFALL_EINTFA5_POS))
#define INT_EINTFALL_EINTFA6            ((uint32_t)1<<(INT_EINTFALL_EINTFA6_POS))
#define INT_EINTFALL_EINTFA7            ((uint32_t)1<<(INT_EINTFALL_EINTFA7_POS))
#define INT_EINTFALL_EINTFA8            ((uint32_t)1<<(INT_EINTFALL_EINTFA8_POS))
#define INT_EINTFALL_EINTFA9            ((uint32_t)1<<(INT_EINTFALL_EINTFA9_POS))
#define INT_EINTFALL_EINTFA10           ((uint32_t)1<<(INT_EINTFALL_EINTFA10_POS))
#define INT_EINTFALL_EINTFA11           ((uint32_t)1<<(INT_EINTFALL_EINTFA11_POS))
#define INT_EINTFALL_EINTFA12           ((uint32_t)1<<(INT_EINTFALL_EINTFA12_POS))
#define INT_EINTFALL_EINTFA13           ((uint32_t)1<<(INT_EINTFALL_EINTFA13_POS))
#define INT_EINTFALL_EINTFA14           ((uint32_t)1<<(INT_EINTFALL_EINTFA14_POS))
#define INT_EINTFALL_EINTFA15           ((uint32_t)1<<(INT_EINTFALL_EINTFA15_POS))
#define INT_EINTFALL_EINTFA16           ((uint32_t)1<<(INT_EINTFALL_EINTFA16_POS))
#define INT_EINTFALL_EINTFA17           ((uint32_t)1<<(INT_EINTFALL_EINTFA17_POS))
#define INT_EINTFALL_EINTFA18           ((uint32_t)1<<(INT_EINTFALL_EINTFA18_POS))
#define INT_EINTFALL_EINTFA19           ((uint32_t)1<<(INT_EINTFALL_EINTFA19_POS))
#define INT_EINTFALL_EINTFA20           ((uint32_t)1<<(INT_EINTFALL_EINTFA20_POS))
#define INT_EINTFALL_EINTFA21           ((uint32_t)1<<(INT_EINTFALL_EINTFA21_POS))
#define INT_EINTFALL_EINTFA22           ((uint32_t)1<<(INT_EINTFALL_EINTFA22_POS))
#define INT_EINTFALL_EINTFA23           ((uint32_t)1<<(INT_EINTFALL_EINTFA23_POS))
#define INT_EINTFALL_EINTFA24           ((uint32_t)1<<(INT_EINTFALL_EINTFA24_POS))
#define INT_EINTFALL_EINTFA25           ((uint32_t)1<<(INT_EINTFALL_EINTFA25_POS))
#define INT_EINTFALL_EINTFA26           ((uint32_t)1<<(INT_EINTFALL_EINTFA26_POS))
#define INT_EINTFALL_EINTFA27           ((uint32_t)1<<(INT_EINTFALL_EINTFA27_POS))
#define INT_EINTFALL_EINTFA28           ((uint32_t)1<<(INT_EINTFALL_EINTFA28_POS))
#define INT_EINTFALL_EINTFA29           ((uint32_t)1<<(INT_EINTFALL_EINTFA29_POS))
#define INT_EINTFALL_EINTFA30           ((uint32_t)1<<(INT_EINTFALL_EINTFA30_POS))
#define INT_EINTFALL_EINTFA31           ((uint32_t)1<<(INT_EINTFALL_EINTFA31_POS))

/* INT_EINTF λ�� */
#define INT_EINTF_EINTIF0_POS           (0)
#define INT_EINTF_EINTIF1_POS           (1)
#define INT_EINTF_EINTIF2_POS           (2)
#define INT_EINTF_EINTIF3_POS           (3)
#define INT_EINTF_EINTIF4_POS           (4)
#define INT_EINTF_EINTIF5_POS           (5)
#define INT_EINTF_EINTIF6_POS           (6)
#define INT_EINTF_EINTIF7_POS           (7)
#define INT_EINTF_EINTIF8_POS           (8)
#define INT_EINTF_EINTIF9_POS           (9)
#define INT_EINTF_EINTIF10_POS          (10)
#define INT_EINTF_EINTIF11_POS          (11)
#define INT_EINTF_EINTIF12_POS          (12)
#define INT_EINTF_EINTIF13_POS          (13)
#define INT_EINTF_EINTIF14_POS          (14)
#define INT_EINTF_EINTIF15_POS          (15)
#define INT_EINTF_EINTIF16_POS          (16)
#define INT_EINTF_EINTIF17_POS          (17)
#define INT_EINTF_EINTIF18_POS          (18)
#define INT_EINTF_EINTIF19_POS          (19)
#define INT_EINTF_EINTIF20_POS          (20)
#define INT_EINTF_EINTIF21_POS          (21)
#define INT_EINTF_EINTIF22_POS          (22)
#define INT_EINTF_EINTIF23_POS          (23)
#define INT_EINTF_EINTIF24_POS          (24)
#define INT_EINTF_EINTIF25_POS          (25)
#define INT_EINTF_EINTIF26_POS          (26)
#define INT_EINTF_EINTIF27_POS          (27)
#define INT_EINTF_EINTIF28_POS          (28)
#define INT_EINTF_EINTIF29_POS          (29)
#define INT_EINTF_EINTIF30_POS          (30)
#define INT_EINTF_EINTIF31_POS          (31)
#define INT_EINTF_EINTIF0               ((uint32_t)1<<(INT_EINTF_EINTIF0_POS))
#define INT_EINTF_EINTIF1               ((uint32_t)1<<(INT_EINTF_EINTIF1_POS))
#define INT_EINTF_EINTIF2               ((uint32_t)1<<(INT_EINTF_EINTIF2_POS))
#define INT_EINTF_EINTIF3               ((uint32_t)1<<(INT_EINTF_EINTIF3_POS))
#define INT_EINTF_EINTIF4               ((uint32_t)1<<(INT_EINTF_EINTIF4_POS))
#define INT_EINTF_EINTIF5               ((uint32_t)1<<(INT_EINTF_EINTIF5_POS))
#define INT_EINTF_EINTIF6               ((uint32_t)1<<(INT_EINTF_EINTIF6_POS))
#define INT_EINTF_EINTIF7               ((uint32_t)1<<(INT_EINTF_EINTIF7_POS))
#define INT_EINTF_EINTIF8               ((uint32_t)1<<(INT_EINTF_EINTIF8_POS))
#define INT_EINTF_EINTIF9               ((uint32_t)1<<(INT_EINTF_EINTIF9_POS))
#define INT_EINTF_EINTIF10              ((uint32_t)1<<(INT_EINTF_EINTIF10_POS))
#define INT_EINTF_EINTIF11              ((uint32_t)1<<(INT_EINTF_EINTIF11_POS))
#define INT_EINTF_EINTIF12              ((uint32_t)1<<(INT_EINTF_EINTIF12_POS))
#define INT_EINTF_EINTIF13              ((uint32_t)1<<(INT_EINTF_EINTIF13_POS))
#define INT_EINTF_EINTIF14              ((uint32_t)1<<(INT_EINTF_EINTIF14_POS))
#define INT_EINTF_EINTIF15              ((uint32_t)1<<(INT_EINTF_EINTIF15_POS))
#define INT_EINTF_EINTIF16              ((uint32_t)1<<(INT_EINTF_EINTIF16_POS))
#define INT_EINTF_EINTIF17              ((uint32_t)1<<(INT_EINTF_EINTIF17_POS))
#define INT_EINTF_EINTIF18              ((uint32_t)1<<(INT_EINTF_EINTIF18_POS))
#define INT_EINTF_EINTIF19              ((uint32_t)1<<(INT_EINTF_EINTIF19_POS))
#define INT_EINTF_EINTIF20              ((uint32_t)1<<(INT_EINTF_EINTIF20_POS))
#define INT_EINTF_EINTIF21              ((uint32_t)1<<(INT_EINTF_EINTIF21_POS))
#define INT_EINTF_EINTIF22              ((uint32_t)1<<(INT_EINTF_EINTIF22_POS))
#define INT_EINTF_EINTIF23              ((uint32_t)1<<(INT_EINTF_EINTIF23_POS))
#define INT_EINTF_EINTIF24              ((uint32_t)1<<(INT_EINTF_EINTIF24_POS))
#define INT_EINTF_EINTIF25              ((uint32_t)1<<(INT_EINTF_EINTIF25_POS))
#define INT_EINTF_EINTIF26              ((uint32_t)1<<(INT_EINTF_EINTIF26_POS))
#define INT_EINTF_EINTIF27              ((uint32_t)1<<(INT_EINTF_EINTIF27_POS))
#define INT_EINTF_EINTIF28              ((uint32_t)1<<(INT_EINTF_EINTIF28_POS))
#define INT_EINTF_EINTIF29              ((uint32_t)1<<(INT_EINTF_EINTIF29_POS))
#define INT_EINTF_EINTIF30              ((uint32_t)1<<(INT_EINTF_EINTIF30_POS))
#define INT_EINTF_EINTIF31              ((uint32_t)1<<(INT_EINTF_EINTIF31_POS))

/* INT_EINTSS0 λ�� */
#define INT_EINTSS0_EINTSOU0_0_POS      (0)
#define INT_EINTSS0_EINTSOU0_1_POS      (1)
#define INT_EINTSS0_EINTSOU0_2_POS      (2)
#define INT_EINTSS0_EINTSOU0_3_POS      (3)
#define INT_EINTSS0_EINTSOU1_0_POS      (4)
#define INT_EINTSS0_EINTSOU1_1_POS      (5)
#define INT_EINTSS0_EINTSOU1_2_POS      (6)
#define INT_EINTSS0_EINTSOU1_3_POS      (7)
#define INT_EINTSS0_EINTSOU2_0_POS      (8)
#define INT_EINTSS0_EINTSOU2_1_POS      (9)
#define INT_EINTSS0_EINTSOU2_2_POS      (10)
#define INT_EINTSS0_EINTSOU2_3_POS      (11)
#define INT_EINTSS0_EINTSOU3_0_POS      (12)
#define INT_EINTSS0_EINTSOU3_1_POS      (13)
#define INT_EINTSS0_EINTSOU3_2_POS      (14)
#define INT_EINTSS0_EINTSOU3_3_POS      (15)
#define INT_EINTSS0_EINTSOU4_0_POS      (16)
#define INT_EINTSS0_EINTSOU4_1_POS      (17)
#define INT_EINTSS0_EINTSOU4_2_POS      (18)
#define INT_EINTSS0_EINTSOU4_3_POS      (19)
#define INT_EINTSS0_EINTSOU5_0_POS      (20)
#define INT_EINTSS0_EINTSOU5_1_POS      (21)
#define INT_EINTSS0_EINTSOU5_2_POS      (22)
#define INT_EINTSS0_EINTSOU5_3_POS      (23)
#define INT_EINTSS0_EINTSOU6_0_POS      (24)
#define INT_EINTSS0_EINTSOU6_1_POS      (25)
#define INT_EINTSS0_EINTSOU6_2_POS      (26)
#define INT_EINTSS0_EINTSOU6_3_POS      (27)
#define INT_EINTSS0_EINTSOU7_0_POS      (28)
#define INT_EINTSS0_EINTSOU7_1_POS      (29)
#define INT_EINTSS0_EINTSOU7_2_POS      (30)
#define INT_EINTSS0_EINTSOU7_3_POS      (31)
#define INT_EINTSS0_EINTSOU0            ((uint32_t)0xf<<(INT_EINTSS0_EINTSOU0_0_POS))
#define INT_EINTSS0_EINTSOU0_0          ((uint32_t)1<<(INT_EINTSS0_EINTSOU0_0_POS))
#define INT_EINTSS0_EINTSOU0_1          ((uint32_t)1<<(INT_EINTSS0_EINTSOU0_1_POS))
#define INT_EINTSS0_EINTSOU0_2          ((uint32_t)1<<(INT_EINTSS0_EINTSOU0_2_POS))
#define INT_EINTSS0_EINTSOU0_3          ((uint32_t)1<<(INT_EINTSS0_EINTSOU0_3_POS))
#define INT_EINTSS0_EINTSOU1            ((uint32_t)0xf<<(INT_EINTSS0_EINTSOU1_0_POS))
#define INT_EINTSS0_EINTSOU1_0          ((uint32_t)1<<(INT_EINTSS0_EINTSOU1_0_POS))
#define INT_EINTSS0_EINTSOU1_1          ((uint32_t)1<<(INT_EINTSS0_EINTSOU1_1_POS))
#define INT_EINTSS0_EINTSOU1_2          ((uint32_t)1<<(INT_EINTSS0_EINTSOU1_2_POS))
#define INT_EINTSS0_EINTSOU1_3          ((uint32_t)1<<(INT_EINTSS0_EINTSOU1_3_POS))
#define INT_EINTSS0_EINTSOU2            ((uint32_t)0xf<<(INT_EINTSS0_EINTSOU2_0_POS))
#define INT_EINTSS0_EINTSOU2_0          ((uint32_t)1<<(INT_EINTSS0_EINTSOU2_0_POS))
#define INT_EINTSS0_EINTSOU2_1          ((uint32_t)1<<(INT_EINTSS0_EINTSOU2_1_POS))
#define INT_EINTSS0_EINTSOU2_2          ((uint32_t)1<<(INT_EINTSS0_EINTSOU2_2_POS))
#define INT_EINTSS0_EINTSOU2_3          ((uint32_t)1<<(INT_EINTSS0_EINTSOU2_3_POS))
#define INT_EINTSS0_EINTSOU3            ((uint32_t)0xf<<(INT_EINTSS0_EINTSOU3_0_POS))
#define INT_EINTSS0_EINTSOU3_0          ((uint32_t)1<<(INT_EINTSS0_EINTSOU3_0_POS))
#define INT_EINTSS0_EINTSOU3_1          ((uint32_t)1<<(INT_EINTSS0_EINTSOU3_1_POS))
#define INT_EINTSS0_EINTSOU3_2          ((uint32_t)1<<(INT_EINTSS0_EINTSOU3_2_POS))
#define INT_EINTSS0_EINTSOU3_3          ((uint32_t)1<<(INT_EINTSS0_EINTSOU3_3_POS))
#define INT_EINTSS0_EINTSOU4            ((uint32_t)0xf<<(INT_EINTSS0_EINTSOU4_0_POS))
#define INT_EINTSS0_EINTSOU4_0          ((uint32_t)1<<(INT_EINTSS0_EINTSOU4_0_POS))
#define INT_EINTSS0_EINTSOU4_1          ((uint32_t)1<<(INT_EINTSS0_EINTSOU4_1_POS))
#define INT_EINTSS0_EINTSOU4_2          ((uint32_t)1<<(INT_EINTSS0_EINTSOU4_2_POS))
#define INT_EINTSS0_EINTSOU4_3          ((uint32_t)1<<(INT_EINTSS0_EINTSOU4_3_POS))
#define INT_EINTSS0_EINTSOU5            ((uint32_t)0xf<<(INT_EINTSS0_EINTSOU5_0_POS))
#define INT_EINTSS0_EINTSOU5_0          ((uint32_t)1<<(INT_EINTSS0_EINTSOU5_0_POS))
#define INT_EINTSS0_EINTSOU5_1          ((uint32_t)1<<(INT_EINTSS0_EINTSOU5_1_POS))
#define INT_EINTSS0_EINTSOU5_2          ((uint32_t)1<<(INT_EINTSS0_EINTSOU5_2_POS))
#define INT_EINTSS0_EINTSOU5_3          ((uint32_t)1<<(INT_EINTSS0_EINTSOU5_3_POS))
#define INT_EINTSS0_EINTSOU6            ((uint32_t)0xf<<(INT_EINTSS0_EINTSOU6_0_POS))
#define INT_EINTSS0_EINTSOU6_0          ((uint32_t)1<<(INT_EINTSS0_EINTSOU6_0_POS))
#define INT_EINTSS0_EINTSOU6_1          ((uint32_t)1<<(INT_EINTSS0_EINTSOU6_1_POS))
#define INT_EINTSS0_EINTSOU6_2          ((uint32_t)1<<(INT_EINTSS0_EINTSOU6_2_POS))
#define INT_EINTSS0_EINTSOU6_3          ((uint32_t)1<<(INT_EINTSS0_EINTSOU6_3_POS))
#define INT_EINTSS0_EINTSOU7            ((uint32_t)0xf<<(INT_EINTSS0_EINTSOU7_0_POS))
#define INT_EINTSS0_EINTSOU7_0          ((uint32_t)1<<(INT_EINTSS0_EINTSOU7_0_POS))
#define INT_EINTSS0_EINTSOU7_1          ((uint32_t)1<<(INT_EINTSS0_EINTSOU7_1_POS))
#define INT_EINTSS0_EINTSOU7_2          ((uint32_t)1<<(INT_EINTSS0_EINTSOU7_2_POS))
#define INT_EINTSS0_EINTSOU7_3          ((uint32_t)1<<(INT_EINTSS0_EINTSOU7_3_POS))

/* INT_EINTSS1 λ�� */
#define INT_EINTSS1_EINTSOU8_0_POS      (0)
#define INT_EINTSS1_EINTSOU8_1_POS      (1)
#define INT_EINTSS1_EINTSOU8_2_POS      (2)
#define INT_EINTSS1_EINTSOU8_3_POS      (3)
#define INT_EINTSS1_EINTSOU9_0_POS      (4)
#define INT_EINTSS1_EINTSOU9_1_POS      (5)
#define INT_EINTSS1_EINTSOU9_2_POS      (6)
#define INT_EINTSS1_EINTSOU9_3_POS      (7)
#define INT_EINTSS1_EINTSOU10_0_POS     (8)
#define INT_EINTSS1_EINTSOU10_1_POS     (9)
#define INT_EINTSS1_EINTSOU10_2_POS     (10)
#define INT_EINTSS1_EINTSOU10_3_POS     (11)
#define INT_EINTSS1_EINTSOU11_0_POS     (12)
#define INT_EINTSS1_EINTSOU11_1_POS     (13)
#define INT_EINTSS1_EINTSOU11_2_POS     (14)
#define INT_EINTSS1_EINTSOU11_3_POS     (15)
#define INT_EINTSS1_EINTSOU12_0_POS     (16)
#define INT_EINTSS1_EINTSOU12_1_POS     (17)
#define INT_EINTSS1_EINTSOU12_2_POS     (18)
#define INT_EINTSS1_EINTSOU12_3_POS     (19)
#define INT_EINTSS1_EINTSOU13_0_POS     (20)
#define INT_EINTSS1_EINTSOU13_1_POS     (21)
#define INT_EINTSS1_EINTSOU13_2_POS     (22)
#define INT_EINTSS1_EINTSOU13_3_POS     (23)
#define INT_EINTSS1_EINTSOU14_0_POS     (24)
#define INT_EINTSS1_EINTSOU14_1_POS     (25)
#define INT_EINTSS1_EINTSOU14_2_POS     (26)
#define INT_EINTSS1_EINTSOU14_3_POS     (27)
#define INT_EINTSS1_EINTSOU15_0_POS     (28)
#define INT_EINTSS1_EINTSOU15_1_POS     (29)
#define INT_EINTSS1_EINTSOU15_2_POS     (30)
#define INT_EINTSS1_EINTSOU15_3_POS     (31)
#define INT_EINTSS1_EINTSOU0            ((uint32_t)0xf<<(INT_EINTSS1_EINTSOU8_0_POS))
#define INT_EINTSS1_EINTSOU0_0          ((uint32_t)1<<(INT_EINTSS1_EINTSOU8_0_POS))
#define INT_EINTSS1_EINTSOU0_1          ((uint32_t)1<<(INT_EINTSS1_EINTSOU8_1_POS))
#define INT_EINTSS1_EINTSOU0_2          ((uint32_t)1<<(INT_EINTSS1_EINTSOU8_2_POS))
#define INT_EINTSS1_EINTSOU0_3          ((uint32_t)1<<(INT_EINTSS1_EINTSOU8_3_POS))
#define INT_EINTSS1_EINTSOU1            ((uint32_t)0xf<<(INT_EINTSS1_EINTSOU9_0_POS))
#define INT_EINTSS1_EINTSOU1_0          ((uint32_t)1<<(INT_EINTSS1_EINTSOU9_0_POS))
#define INT_EINTSS1_EINTSOU1_1          ((uint32_t)1<<(INT_EINTSS1_EINTSOU9_1_POS))
#define INT_EINTSS1_EINTSOU1_2          ((uint32_t)1<<(INT_EINTSS1_EINTSOU9_2_POS))
#define INT_EINTSS1_EINTSOU1_3          ((uint32_t)1<<(INT_EINTSS1_EINTSOU9_3_POS))
#define INT_EINTSS1_EINTSOU2            ((uint32_t)0xf<<(INT_EINTSS1_EINTSOU10_0_POS))
#define INT_EINTSS1_EINTSOU2_0          ((uint32_t)1<<(INT_EINTSS1_EINTSOU10_0_POS))
#define INT_EINTSS1_EINTSOU2_1          ((uint32_t)1<<(INT_EINTSS1_EINTSOU10_1_POS))
#define INT_EINTSS1_EINTSOU2_2          ((uint32_t)1<<(INT_EINTSS1_EINTSOU10_2_POS))
#define INT_EINTSS1_EINTSOU2_3          ((uint32_t)1<<(INT_EINTSS1_EINTSOU10_3_POS))
#define INT_EINTSS1_EINTSOU3            ((uint32_t)0xf<<(INT_EINTSS1_EINTSOU11_0_POS))
#define INT_EINTSS1_EINTSOU3_0          ((uint32_t)1<<(INT_EINTSS1_EINTSOU11_0_POS))
#define INT_EINTSS1_EINTSOU3_1          ((uint32_t)1<<(INT_EINTSS1_EINTSOU11_1_POS))
#define INT_EINTSS1_EINTSOU3_2          ((uint32_t)1<<(INT_EINTSS1_EINTSOU11_2_POS))
#define INT_EINTSS1_EINTSOU3_3          ((uint32_t)1<<(INT_EINTSS1_EINTSOU11_3_POS))
#define INT_EINTSS1_EINTSOU4            ((uint32_t)0xf<<(INT_EINTSS1_EINTSOU12_0_POS))
#define INT_EINTSS1_EINTSOU4_0          ((uint32_t)1<<(INT_EINTSS1_EINTSOU12_0_POS))
#define INT_EINTSS1_EINTSOU4_1          ((uint32_t)1<<(INT_EINTSS1_EINTSOU12_1_POS))
#define INT_EINTSS1_EINTSOU4_2          ((uint32_t)1<<(INT_EINTSS1_EINTSOU12_2_POS))
#define INT_EINTSS1_EINTSOU4_3          ((uint32_t)1<<(INT_EINTSS1_EINTSOU12_3_POS))
#define INT_EINTSS1_EINTSOU5            ((uint32_t)0xf<<(INT_EINTSS1_EINTSOU13_0_POS))
#define INT_EINTSS1_EINTSOU5_0          ((uint32_t)1<<(INT_EINTSS1_EINTSOU13_0_POS))
#define INT_EINTSS1_EINTSOU5_1          ((uint32_t)1<<(INT_EINTSS1_EINTSOU13_1_POS))
#define INT_EINTSS1_EINTSOU5_2          ((uint32_t)1<<(INT_EINTSS1_EINTSOU13_2_POS))
#define INT_EINTSS1_EINTSOU5_3          ((uint32_t)1<<(INT_EINTSS1_EINTSOU13_3_POS))
#define INT_EINTSS1_EINTSOU6            ((uint32_t)0xf<<(INT_EINTSS1_EINTSOU14_0_POS))
#define INT_EINTSS1_EINTSOU6_0          ((uint32_t)1<<(INT_EINTSS1_EINTSOU14_0_POS))
#define INT_EINTSS1_EINTSOU6_1          ((uint32_t)1<<(INT_EINTSS1_EINTSOU14_1_POS))
#define INT_EINTSS1_EINTSOU6_2          ((uint32_t)1<<(INT_EINTSS1_EINTSOU14_2_POS))
#define INT_EINTSS1_EINTSOU6_3          ((uint32_t)1<<(INT_EINTSS1_EINTSOU14_3_POS))
#define INT_EINTSS1_EINTSOU7            ((uint32_t)0xf<<(INT_EINTSS1_EINTSOU15_0_POS))
#define INT_EINTSS1_EINTSOU7_0          ((uint32_t)1<<(INT_EINTSS1_EINTSOU15_0_POS))
#define INT_EINTSS1_EINTSOU7_1          ((uint32_t)1<<(INT_EINTSS1_EINTSOU15_1_POS))
#define INT_EINTSS1_EINTSOU7_2          ((uint32_t)1<<(INT_EINTSS1_EINTSOU15_2_POS))
#define INT_EINTSS1_EINTSOU7_3          ((uint32_t)1<<(INT_EINTSS1_EINTSOU15_3_POS))

/* INT_CTL1 λ�� */
#define INT_CTL1_INTDELY0_POS           (0)
#define INT_CTL1_INTDELY                ((uint32_t)0xFF<<(INT_CTL1_INTDELY0_POS))
/* �ж϶������ */


/* ----------------------------------------------------------------------------
   -- ϵͳ����(SYSCTL)
   ---------------------------------------------------------------------------- */
/* SYSCTL - �ڴ�ṹ */
typedef struct SYSCTL_MemMap {
    volatile       uint32_t PSW;        /* ����״̬�Ĵ���, ƫ��:0x00 */
    volatile       uint32_t MCTL;       /* ϵͳģʽ���ƼĴ���, ƫ��:0x04 */
    volatile       uint32_t ARCTL;      /* Ӧ�ø�λ����, ƫ��:0x08 */
    volatile       uint32_t VECTOFF;    /* �ж���������ӳ����ƼĴ���, ƫ��:0x0C */
    			   uint32_t RESEVRVE1;	/* ����, ƫ��:0x10 */
    volatile       uint32_t RAMSPA;     /* RAM�ռ�ָʾ�Ĵ���, ƫ��:0x14 */
    volatile       uint32_t MEMCTL;     /* ����ռ���ƼĴ���, ƫ��:0x18 */
}SYSCTL_SFRmap;

/* ----------------------------------------------------------------------------
   -- SYSCTL - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* SYSCTL - �Ĵ�����ڵ�ַ */
#define SYSCTL_ADDR                     ((uint32_t)0x402000B0)
#define SYS_CORETP0_ADDR                ((uint32_t)0x40200200)
#define SYS_CORETP1_ADDR                ((uint32_t)0x40200204)
#define SYS_CORETP2_ADDR                ((uint32_t)0x40200208)
#define SYS_CORETP3_ADDR                ((uint32_t)0x4020020C)
#define SYSCTL_SFR                      ((SYSCTL_SFRmap *) SYSCTL_ADDR)

/* SYSCTL - �Ĵ������ */
#define SYS_PSW                         (SYSCTL_SFR->PSW)
#define SYS_MCTL                        (SYSCTL_SFR->MCTL)
#define SYS_ARCTL                       (SYSCTL_SFR->ARCTL)
#define SYS_VECTOFF                     (SYSCTL_SFR->VECTOFF)
#define SYS_RAMSPA                      (SYSCTL_SFR->RAMSPA)
#define SYS_MEMCTL                      (SYSCTL_SFR->MEMCTL)

/* SYS_PSW λ�� */
#define SYS_PSW_V_POS                   (28)
#define SYS_PSW_C_POS                   (29)
#define SYS_PSW_Z_POS                   (30)
#define SYS_PSW_N_POS                   (31)
#define SYS_PSW_V                       ((uint32_t)1<<(SYS_PSW_V_POS))
#define SYS_PSW_C                       ((uint32_t)1<<(SYS_PSW_C_POS))
#define SYS_PSW_Z                       ((uint32_t)1<<(SYS_PSW_Z_POS))
#define SYS_PSW_N                       ((uint32_t)1<<(SYS_PSW_N_POS))

/* SYS_MCTL λ�� */
#define SYS_MCTL_SLEEPONEXIT_POS        (1)
#define SYS_MCTL_SLEEPDEEP_POS          (2)
#define SYS_MCTL_SLPONMOD_POS           (4)
#define SYS_MCTL_STACKALIGN_POS         (9)
#define SYS_MCTL_SUSTA_POS              (15)
#define SYS_MCTL_SPSEL_POS              (16)
#define SYS_MCTL_SLEEPONEXIT            ((uint32_t)1<<(SYS_MCTL_SLEEPONEXIT_POS))
#define SYS_MCTL_SLEEPDEEP              ((uint32_t)1<<(SYS_MCTL_SLEEPDEEP_POS))
#define SYS_MCTL_SLPONMOD               ((uint32_t)1<<(SYS_MCTL_SLPONMOD_POS))
#define SYS_MCTL_STACKALIGN             ((uint32_t)1<<(SYS_MCTL_STACKALIGN_POS))
#define SYS_MCTL_SUSTA                  ((uint32_t)1<<(SYS_MCTL_SUSTA_POS))
#define SYS_MCTL_SPSEL                  ((uint32_t)1<<(SYS_MCTL_SPSEL_POS))

/* SYS_ARCTL λ�� */
#define SYS_ARCTL_VECTRST_POS           (1)
#define SYS_ARCTL_SYSTEMRST_POS         (2)
#define SYS_ARCTL_IDC_POS               (3)
#define SYS_ARCTL_CDMAR_POS             (4)
#define SYS_ARCTL_CDMAAM_POS            (5)
#define SYS_ARCTL_ARKEY_POS             (16)
#define SYS_ARCTL_VECTRST               ((uint32_t)1<<(SYS_ARCTL_VECTRST_POS))
#define SYS_ARCTL_SYSTEMRST             ((uint32_t)1<<(SYS_ARCTL_SYSTEMRST_POS))
#define SYS_ARCTL_IDC                   ((uint32_t)1<<(SYS_ARCTL_IDC_POS))
#define SYS_ARCTL_CDMAR                 ((uint32_t)1<<(SYS_ARCTL_CDMAR_POS))
#define SYS_ARCTL_CDMAAM                ((uint32_t)1<<(SYS_ARCTL_CDMAAM_POS))
#define SYS_ARCTL_ARKEY                 ((uint32_t)0xFFFF<<(SYS_ARCTL_ARKEY_POS))

/* SYS_VECTOFF λ�� */
#define SYS_VECTOFF_TBLOFF0_POS         (0)
#define SYS_VECTOFF_TBLOFF              ((uint32_t)0xFFFFFFFF<<(SYS_VECTOFF_TBLOFF0_POS))

/* SYS_RAMSPA λ�� */
#define SYS_RAMSPA_RAMSPA0_POS          (0)
#define SYS_RAMSPA_RAMSPA               ((uint32_t)0x3FFFFFF<<(SYS_RAMSPA_RAMSPA0_POS))

/* SYS_MEMCTL λ�� */
#define SYS_MEMCTL_MEMM0_POS            (0)
#define SYS_MEMCTL_MEMM1_POS            (1)
#define SYS_MEMCTL_MEMM                 ((uint32_t)3<<(SYS_MEMCTL_MEMM0_POS))


/* ϵͳ����(SYSCTL)������� */


/* ----------------------------------------------------------------------------
   -- ģ��ת��(ADC)
   ---------------------------------------------------------------------------- */

/* ADC - ����Ĵ����ڴ�ṹ */
typedef struct ADC_MemMap {
    volatile       uint32_t CTL0;       /* ADC���ƼĴ���0, ƫ��:0x00 */
    volatile       uint32_t CTL1;       /* ADC���ƼĴ���1, ƫ��:0x04 */
    volatile       uint32_t SCANSQ0;    /* ADC����ͨ��ɨ���������üĴ���0, ƫ��:0x08 */
    volatile       uint32_t SCANSQ1;    /* ADC����ͨ��ɨ���������üĴ���1, ƫ��:0x0C */
    volatile       uint32_t SCANSQ2;    /* ADC����ͨ��ɨ���������üĴ���2, ƫ��:0x10 */
    volatile       uint32_t HSCANSQ;    /* ADC�����ȼ�ͨ��ɨ���������üĴ���, ƫ��:0x14 */
    volatile       uint32_t WDH;        /* ADCģ�⿴�Ź�����ֵ�Ĵ���, ƫ��:0x18 */
    volatile       uint32_t WDL;        /* ADCģ�⿴�Ź�����ֵ�Ĵ���, ƫ��:0x1C */
    volatile const uint32_t DATA;       /* ADC����ͨ�����ݼĴ���, ƫ��:0x20 */
    volatile const uint32_t HPDATA0;    /* ADC�����ȼ�ͨ�����ݼĴ���0, ƫ��:0x24 */
    volatile const uint32_t HPDATA1;    /* ADC�����ȼ�ͨ�����ݼĴ���1, ƫ��:0x28 */
    volatile const uint32_t HPDATA2;    /* ADC�����ȼ�ͨ�����ݼĴ���2, ƫ��:0x2C */
    volatile const uint32_t HPDATA3;    /* ADC�����ȼ�ͨ�����ݼĴ���3, ƫ��:0x30 */
    volatile       uint32_t HPOFF0;     /* ADC�����ȼ�ͨ������ƫ�ƼĴ���0, ƫ��:0x34 */
    volatile       uint32_t HPOFF1;     /* ADC�����ȼ�ͨ������ƫ�ƼĴ���1, ƫ��:0x38 */
    volatile       uint32_t HPOFF2;     /* ADC�����ȼ�ͨ������ƫ�ƼĴ���2, ƫ��:0x3C */
    volatile       uint32_t HPOFF3;     /* ADC�����ȼ�ͨ������ƫ�ƼĴ���3, ƫ��:0x40 */
    volatile       uint32_t SCANSQ3;    /* ADC����ͨ��ɨ���������üĴ���3, ƫ��:0x44 */
                   uint32_t RESERVED[2];/* ������ַ, ƫ��:0x48 */
    volatile       uint32_t STATE;      /* ADC״̬�Ĵ���, ƫ��:0x50 */
    volatile       uint32_t DELAY;      /* ADC״̬�Ĵ���, ƫ��:0x54 */
}ADC_SFRmap;

typedef struct ADC_Delay_MemMap
{
    volatile uint32_t DELAY;            /* ADC0����������ʱ�Ĵ���, addr:0x4000 05D4 */
}ADC_DELAY_SFRmap;
/* ----------------------------------------------------------------------------
   -- ADC - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* ADC - �Ĵ�����ڵ�ַ */
#ifdef  KF32F_Periph_adc0
#define ADC0_ADDR                       ((uint32_t)0x40000580)
#define ADC0_SFR                        ((ADC_SFRmap *) ADC0_ADDR)
#endif
#ifdef  KF32F_Periph_adc1
#define ADC1_ADDR                       ((uint32_t)0x40000600)
#define ADC1_SFR                        ((ADC_SFRmap *) ADC1_ADDR)
#endif
#ifdef  KF32F_Periph_adc2
#define ADC2_ADDR                       ((uint32_t)0x40000680)
#define ADC2_SFR                        ((ADC_SFRmap *) ADC2_ADDR)
#endif

#ifdef  KF32F_Periph_adc0
#define ADC0_DELAY_ADDR                 ((uint32_t)0x400005D4)
#define ADC0_DELAY_SFR                  ((ADC_DELAY_SFRmap *) ADC0_DELAY_ADDR)
/* ADC - �Ĵ������ */
#define ADC0_CTL0                       (ADC0_SFR->CTL0)
#define ADC0_CTL1                       (ADC0_SFR->CTL1)
#define ADC0_SCANSQ0                    (ADC0_SFR->SCANSQ0)
#define ADC0_SCANSQ1                    (ADC0_SFR->SCANSQ1)
#define ADC0_SCANSQ2                    (ADC0_SFR->SCANSQ2)
#define ADC0_HSCANSQ                    (ADC0_SFR->HSCANSQ)
#define ADC0_WDH                        (ADC0_SFR->WDH)
#define ADC0_WDL                        (ADC0_SFR->WDL)
#define ADC0_DATA                       (ADC0_SFR->DATA)
#define ADC0_HPDATA0                    (ADC0_SFR->HPDATA0)
#define ADC0_HPDATA1                    (ADC0_SFR->HPDATA1)
#define ADC0_HPDATA2                    (ADC0_SFR->HPDATA2)
#define ADC0_HPDATA3                    (ADC0_SFR->HPDATA3)
#define ADC0_HPOFF0                     (ADC0_SFR->HPOFF0)
#define ADC0_HPOFF1                     (ADC0_SFR->HPOFF1)
#define ADC0_HPOFF2                     (ADC0_SFR->HPOFF2)
#define ADC0_HPOFF3                     (ADC0_SFR->HPOFF3)
#define ADC0_STATE                      (ADC0_SFR->STATE)

#define ADC0_DELAY                      (ADC0_DELAY_SFR->DELAY)
#endif

#ifdef  KF32F_Periph_adc1
#define ADC1_CTL0                       (ADC1_SFR->CTL0)
#define ADC1_CTL1                       (ADC1_SFR->CTL1)
#define ADC1_SCANSQ0                    (ADC1_SFR->SCANSQ0)
#define ADC1_SCANSQ1                    (ADC1_SFR->SCANSQ1)
#define ADC1_SCANSQ2                    (ADC1_SFR->SCANSQ2)
#define ADC1_HSCANSQ                    (ADC1_SFR->HSCANSQ)
#define ADC1_WDH                        (ADC1_SFR->WDH)
#define ADC1_WDL                        (ADC1_SFR->WDL)
#define ADC1_DATA                       (ADC1_SFR->DATA)
#define ADC1_HPDATA0                    (ADC1_SFR->HPDATA0)
#define ADC1_HPDATA1                    (ADC1_SFR->HPDATA1)
#define ADC1_HPDATA2                    (ADC1_SFR->HPDATA2)
#define ADC1_HPDATA3                    (ADC1_SFR->HPDATA3)
#define ADC1_HPOFF0                     (ADC1_SFR->HPOFF0)
#define ADC1_HPOFF1                     (ADC1_SFR->HPOFF1)
#define ADC1_HPOFF2                     (ADC1_SFR->HPOFF2)
#define ADC1_HPOFF3                     (ADC1_SFR->HPOFF3)
#define ADC1_STATE                      (ADC1_SFR->STATE)
#endif

#ifdef  KF32F_Periph_adc2
#define ADC2_CTL0                       (ADC2_SFR->CTL0)
#define ADC2_CTL1                       (ADC2_SFR->CTL1)
#define ADC2_SCANSQ0                    (ADC2_SFR->SCANSQ0)
#define ADC2_SCANSQ1                    (ADC2_SFR->SCANSQ1)
#define ADC2_SCANSQ2                    (ADC2_SFR->SCANSQ2)
#define ADC2_HSCANSQ                    (ADC2_SFR->HSCANSQ)
#define ADC2_WDH                        (ADC2_SFR->WDH)
#define ADC2_WDL                        (ADC2_SFR->WDL)
#define ADC2_DATA                       (ADC2_SFR->DATA)
#define ADC2_HPDATA0                    (ADC2_SFR->HPDATA0)
#define ADC2_HPDATA1                    (ADC2_SFR->HPDATA1)
#define ADC2_HPDATA2                    (ADC2_SFR->HPDATA2)
#define ADC2_HPDATA3                    (ADC2_SFR->HPDATA3)
#define ADC2_HPOFF0                     (ADC2_SFR->HPOFF0)
#define ADC2_HPOFF1                     (ADC2_SFR->HPOFF1)
#define ADC2_HPOFF2                     (ADC2_SFR->HPOFF2)
#define ADC2_HPOFF3                     (ADC2_SFR->HPOFF3)
#define ADC2_STATE                      (ADC2_SFR->STATE)
#endif

/* ADC_CTL0 λ�� */
#define ADC_CTL0_EN_POS                 (0)
#define ADC_CTL0_CLKS0_POS              (1)
#define ADC_CTL0_CLKS1_POS              (2)
#define ADC_CTL0_LR_POS                 (3)
#define ADC_CTL0_TP0_POS                (4)
#define ADC_CTL0_TP1_POS                (5)
#define ADC_CTL0_TP2_POS                (6)
#define ADC_CTL0_TPEN_POS               (7)
#define ADC_CTL0_ADCCLKS0_POS           (8)
#define ADC_CTL0_ADCCLKS1_POS           (9)
#define ADC_CTL0_ADCCLKS2_POS           (10)
#define ADC_CTL0_DMAEN_POS              (13)
#define ADC_CTL0_TRIMIBIAS_POS          (14)
#define ADC_CTL0_BOSSSEL_POS            (15)
#define ADC_CTL0_BOSSSELCOMP_POS        (16)
#define ADC_CTL0_SCANEN_POS             (17)
#define ADC_CTL0_CONT_POS               (18)
#define ADC_CTL0_HPAUTO_POS             (19)
#define ADC_CTL0_DSEN_POS               (20)
#define ADC_CTL0_HPDSEN_POS             (21)
#define ADC_CTL0_DSNUM0_POS             (26)
#define ADC_CTL0_DSNUM1_POS             (27)
#define ADC_CTL0_DSNUM2_POS             (28)
#define ADC_CTL0_WDEN_POS               (29)
#define ADC_CTL0_HPWDEN_POS             (30)
#define ADC_CTL0_WDSCH_POS              (31)
#define ADC_CTL0_EN                     ((uint32_t)1<<(ADC_CTL0_EN_POS))
#define ADC_CTL0_CLKS                   ((uint32_t)3<<(ADC_CTL0_CLKS0_POS))
#define ADC_CTL0_CLKS0                  ((uint32_t)1<<(ADC_CTL0_CLKS0_POS))
#define ADC_CTL0_CLKS1                  ((uint32_t)1<<(ADC_CTL0_CLKS1_POS))
#define ADC_CTL0_LR                     ((uint32_t)1<<(ADC_CTL0_LR_POS))
#define ADC_CTL0_TP0                    ((uint32_t)1<<(ADC_CTL0_TP0_POS))
#define ADC_CTL0_TP1                    ((uint32_t)1<<(ADC_CTL0_TP1_POS))
#define ADC_CTL0_TP2                    ((uint32_t)1<<(ADC_CTL0_TP2_POS))
#define ADC_CTL0_TPEN                   ((uint32_t)1<<(ADC_CTL0_TPEN_POS))
#define ADC_CTL0_ADCCLKS                ((uint32_t)7<<(ADC_CTL0_ADCCLKS0_POS))
#define ADC_CTL0_ADCCLKS0               ((uint32_t)1<<(ADC_CTL0_ADCCLKS0_POS))
#define ADC_CTL0_ADCCLKS1               ((uint32_t)1<<(ADC_CTL0_ADCCLKS1_POS))
#define ADC_CTL0_ADCCLKS2               ((uint32_t)1<<(ADC_CTL0_ADCCLKS2_POS))
#define ADC_CTL0_DMAEN                  ((uint32_t)1<<(ADC_CTL0_DMAEN_POS))
#define ADC_CTL0_TRIMIBIAS              ((uint32_t)1<<(ADC_CTL0_TRIMIBIAS_POS))
#define ADC_CTL0_BOSSSEL                ((uint32_t)1<<(ADC_CTL0_BOSSSEL_POS))
#define ADC_CTL0_BOSSSELCOMP            ((uint32_t)1<<(ADC_CTL0_BOSSSELCOMP_POS))
#define ADC_CTL0_SCANEN                 ((uint32_t)1<<(ADC_CTL0_SCANEN_POS))
#define ADC_CTL0_CONT                   ((uint32_t)1<<(ADC_CTL0_CONT_POS))
#define ADC_CTL0_HPAUTO                 ((uint32_t)1<<(ADC_CTL0_HPAUTO_POS))
#define ADC_CTL0_DSEN                   ((uint32_t)1<<(ADC_CTL0_DSEN_POS))
#define ADC_CTL0_HPDSEN                 ((uint32_t)1<<(ADC_CTL0_HPDSEN_POS))
#define ADC_CTL0_DSNUM                  ((uint32_t)7<<(ADC_CTL0_DSNUM0_POS))
#define ADC_CTL0_DSNUM0                 ((uint32_t)1<<(ADC_CTL0_DSNUM0_POS))
#define ADC_CTL0_DSNUM1                 ((uint32_t)1<<(ADC_CTL0_DSNUM1_POS))
#define ADC_CTL0_DSNUM2                 ((uint32_t)1<<(ADC_CTL0_DSNUM2_POS))
#define ADC_CTL0_WDEN                   ((uint32_t)1<<(ADC_CTL0_WDEN_POS))
#define ADC_CTL0_HPWDEN                 ((uint32_t)1<<(ADC_CTL0_HPWDEN_POS))
#define ADC_CTL0_WDSCH                  ((uint32_t)1<<(ADC_CTL0_WDSCH_POS))

/* ADC_CTL1 λ�� */
#define ADC_CTL1_START_POS              (2)
#define ADC_CTL1_HPSTART_POS            (3)
#define ADC_CTL1_NCH0_POS               (4)
#define ADC_CTL1_NCH1_POS               (5)
#define ADC_CTL1_NCH2_POS               (6)
#define ADC_CTL1_NCH3_POS               (7)
#define ADC_CTL1_NCH4_POS               (8)
#define ADC_CTL1_NCH5_POS               (9)
#define ADC_CTL1_NCH6_POS               (10)
#define ADC_CTL1_EXTEN_POS              (11)
#define ADC_CTL1_REF0_POS               (17)
#define ADC_CTL1_REF1_POS               (18)
#define ADC_CTL1_REF2_POS               (19)
#define ADC_CTL1_HCH0_POS               (20)
#define ADC_CTL1_HCH1_POS               (21)
#define ADC_CTL1_HCH2_POS               (22)
#define ADC_CTL1_HCH3_POS               (23)
#define ADC_CTL1_HCH4_POS               (24)
#define ADC_CTL1_HCH5_POS               (25)
#define ADC_CTL1_HCH6_POS               (26)
#define ADC_CTL1_HPEXTEN_POS            (27)
#define ADC_CTL1_DOUMOD0_POS            (28)
#define ADC_CTL1_DOUMOD1_POS            (29)
#define ADC_CTL1_DOUMOD2_POS            (30)
#define ADC_CTL1_DOUMOD3_POS            (31)
#define ADC_CTL1_START                  ((uint32_t)1<<(ADC_CTL1_START_POS))
#define ADC_CTL1_HPSTART                ((uint32_t)1<<(ADC_CTL1_HPSTART_POS))
#define ADC_CTL1_NCH                    ((uint32_t)0x7F<<(ADC_CTL1_NCH0_POS))
#define ADC_CTL1_NCH0                   ((uint32_t)1<<(ADC_CTL1_NCH0_POS))
#define ADC_CTL1_NCH1                   ((uint32_t)1<<(ADC_CTL1_NCH1_POS))
#define ADC_CTL1_NCH2                   ((uint32_t)1<<(ADC_CTL1_NCH2_POS))
#define ADC_CTL1_NCH3                   ((uint32_t)1<<(ADC_CTL1_NCH3_POS))
#define ADC_CTL1_NCH4                   ((uint32_t)1<<(ADC_CTL1_NCH4_POS))
#define ADC_CTL1_NCH5                   ((uint32_t)1<<(ADC_CTL1_NCH5_POS))
#define ADC_CTL1_NCH6                   ((uint32_t)1<<(ADC_CTL1_NCH6_POS))
#define ADC_CTL1_EXTEN                  ((uint32_t)1<<(ADC_CTL1_EXTEN_POS))
#define ADC_CTL1_REF                    ((uint32_t)7<<(ADC_CTL1_REF0_POS))
#define ADC_CTL1_REF0                   ((uint32_t)1<<(ADC_CTL1_REF0_POS))
#define ADC_CTL1_REF1                   ((uint32_t)1<<(ADC_CTL1_REF1_POS))
#define ADC_CTL1_REF2                   ((uint32_t)1<<(ADC_CTL1_REF2_POS))
#define ADC_CTL1_HCH                    ((uint32_t)0x7F<<(ADC_CTL1_HCH0_POS))
#define ADC_CTL1_HCH0                   ((uint32_t)1<<(ADC_CTL1_HCH0_POS))
#define ADC_CTL1_HCH1                   ((uint32_t)1<<(ADC_CTL1_HCH1_POS))
#define ADC_CTL1_HCH2                   ((uint32_t)1<<(ADC_CTL1_HCH2_POS))
#define ADC_CTL1_HCH3                   ((uint32_t)1<<(ADC_CTL1_HCH3_POS))
#define ADC_CTL1_HCH4                   ((uint32_t)1<<(ADC_CTL1_HCH4_POS))
#define ADC_CTL1_HCH5                   ((uint32_t)1<<(ADC_CTL1_HCH5_POS))
#define ADC_CTL1_HCH6                   ((uint32_t)1<<(ADC_CTL1_HCH6_POS))
#define ADC_CTL1_HPEXTEN                ((uint32_t)1<<(ADC_CTL1_HPEXTEN_POS))
#define ADC_CTL1_DOUMOD                 ((uint32_t)0xF<<(ADC_CTL1_DOUMOD0_POS))
#define ADC_CTL1_DOUMOD0                ((uint32_t)1<<(ADC_CTL1_DOUMOD0_POS))
#define ADC_CTL1_DOUMOD1                ((uint32_t)1<<(ADC_CTL1_DOUMOD1_POS))
#define ADC_CTL1_DOUMOD2                ((uint32_t)1<<(ADC_CTL1_DOUMOD2_POS))
#define ADC_CTL1_DOUMOD3                ((uint32_t)1<<(ADC_CTL1_DOUMOD3_POS))

/* ADC_SCANSQ0 λ�� */
#define ADC_SCANSQ0_SSQ0_0_POS          (0)
#define ADC_SCANSQ0_SSQ0_1_POS          (1)
#define ADC_SCANSQ0_SSQ0_2_POS          (2)
#define ADC_SCANSQ0_SSQ0_3_POS          (3)
#define ADC_SCANSQ0_SSQ0_4_POS          (4)
#define ADC_SCANSQ0_SSQ0_5_POS          (5)
#define ADC_SCANSQ0_SSQ1_0_POS          (6)
#define ADC_SCANSQ0_SSQ1_1_POS          (7)
#define ADC_SCANSQ0_SSQ1_2_POS          (8)
#define ADC_SCANSQ0_SSQ1_3_POS          (9)
#define ADC_SCANSQ0_SSQ1_4_POS          (10)
#define ADC_SCANSQ0_SSQ1_5_POS          (11)
#define ADC_SCANSQ0_SSQ2_0_POS          (12)
#define ADC_SCANSQ0_SSQ2_1_POS          (13)
#define ADC_SCANSQ0_SSQ2_2_POS          (14)
#define ADC_SCANSQ0_SSQ2_3_POS          (15)
#define ADC_SCANSQ0_SSQ2_4_POS          (16)
#define ADC_SCANSQ0_SSQ2_5_POS          (17)
#define ADC_SCANSQ0_SSQ3_0_POS          (18)
#define ADC_SCANSQ0_SSQ3_1_POS          (19)
#define ADC_SCANSQ0_SSQ3_2_POS          (20)
#define ADC_SCANSQ0_SSQ3_3_POS          (21)
#define ADC_SCANSQ0_SSQ3_4_POS          (22)
#define ADC_SCANSQ0_SSQ3_5_POS          (23)
#define ADC_SCANSQ0_SSQ4_0_POS          (24)
#define ADC_SCANSQ0_SSQ4_1_POS          (25)
#define ADC_SCANSQ0_SSQ4_2_POS          (26)
#define ADC_SCANSQ0_SSQ4_3_POS          (27)
#define ADC_SCANSQ0_SSQ4_4_POS          (28)
#define ADC_SCANSQ0_SSQ4_5_POS          (29)

#define ADC_SCANSQ0_SSQ0                ((uint32_t)0x3F<<(ADC_SCANSQ0_SSQ0_0_POS))
#define ADC_SCANSQ0_SSQ0_0              ((uint32_t)1<<(ADC_SCANSQ0_SSQ0_0_POS))
#define ADC_SCANSQ0_SSQ0_1              ((uint32_t)1<<(ADC_SCANSQ0_SSQ0_1_POS))
#define ADC_SCANSQ0_SSQ0_2              ((uint32_t)1<<(ADC_SCANSQ0_SSQ0_2_POS))
#define ADC_SCANSQ0_SSQ0_3              ((uint32_t)1<<(ADC_SCANSQ0_SSQ0_3_POS))
#define ADC_SCANSQ0_SSQ0_4              ((uint32_t)1<<(ADC_SCANSQ0_SSQ0_4_POS))
#define ADC_SCANSQ0_SSQ0_5              ((uint32_t)1<<(ADC_SCANSQ0_SSQ0_5_POS))
#define ADC_SCANSQ0_SSQ1                ((uint32_t)0x3F<<(ADC_SCANSQ0_SSQ1_0_POS))
#define ADC_SCANSQ0_SSQ1_0              ((uint32_t)1<<(ADC_SCANSQ0_SSQ1_0_POS))
#define ADC_SCANSQ0_SSQ1_1              ((uint32_t)1<<(ADC_SCANSQ0_SSQ1_1_POS))
#define ADC_SCANSQ0_SSQ1_2              ((uint32_t)1<<(ADC_SCANSQ0_SSQ1_2_POS))
#define ADC_SCANSQ0_SSQ1_3              ((uint32_t)1<<(ADC_SCANSQ0_SSQ1_3_POS))
#define ADC_SCANSQ0_SSQ1_4              ((uint32_t)1<<(ADC_SCANSQ0_SSQ1_4_POS))
#define ADC_SCANSQ0_SSQ1_5              ((uint32_t)1<<(ADC_SCANSQ0_SSQ1_5_POS))
#define ADC_SCANSQ0_SSQ2                ((uint32_t)0x3F<<(ADC_SCANSQ0_SSQ2_0_POS))
#define ADC_SCANSQ0_SSQ2_0              ((uint32_t)1<<(ADC_SCANSQ0_SSQ2_0_POS))
#define ADC_SCANSQ0_SSQ2_1              ((uint32_t)1<<(ADC_SCANSQ0_SSQ2_1_POS))
#define ADC_SCANSQ0_SSQ2_2              ((uint32_t)1<<(ADC_SCANSQ0_SSQ2_2_POS))
#define ADC_SCANSQ0_SSQ2_3              ((uint32_t)1<<(ADC_SCANSQ0_SSQ2_3_POS))
#define ADC_SCANSQ0_SSQ2_4              ((uint32_t)1<<(ADC_SCANSQ0_SSQ2_4_POS))
#define ADC_SCANSQ0_SSQ2_5              ((uint32_t)1<<(ADC_SCANSQ0_SSQ2_5_POS))
#define ADC_SCANSQ0_SSQ3                ((uint32_t)0x3F<<(ADC_SCANSQ0_SSQ3_0_POS))
#define ADC_SCANSQ0_SSQ3_0              ((uint32_t)1<<(ADC_SCANSQ0_SSQ3_0_POS))
#define ADC_SCANSQ0_SSQ3_1              ((uint32_t)1<<(ADC_SCANSQ0_SSQ3_1_POS))
#define ADC_SCANSQ0_SSQ3_2              ((uint32_t)1<<(ADC_SCANSQ0_SSQ3_2_POS))
#define ADC_SCANSQ0_SSQ3_3              ((uint32_t)1<<(ADC_SCANSQ0_SSQ3_3_POS))
#define ADC_SCANSQ0_SSQ3_4              ((uint32_t)1<<(ADC_SCANSQ0_SSQ3_4_POS))
#define ADC_SCANSQ0_SSQ3_5              ((uint32_t)1<<(ADC_SCANSQ0_SSQ3_5_POS))
#define ADC_SCANSQ0_SSQ4                ((uint32_t)0x3F<<(ADC_SCANSQ0_SSQ4_0_POS))
#define ADC_SCANSQ0_SSQ4_0              ((uint32_t)1<<(ADC_SCANSQ0_SSQ4_0_POS))
#define ADC_SCANSQ0_SSQ4_1              ((uint32_t)1<<(ADC_SCANSQ0_SSQ4_1_POS))
#define ADC_SCANSQ0_SSQ4_2              ((uint32_t)1<<(ADC_SCANSQ0_SSQ4_2_POS))
#define ADC_SCANSQ0_SSQ4_3              ((uint32_t)1<<(ADC_SCANSQ0_SSQ4_3_POS))
#define ADC_SCANSQ0_SSQ4_4              ((uint32_t)1<<(ADC_SCANSQ0_SSQ4_4_POS))
#define ADC_SCANSQ0_SSQ4_5              ((uint32_t)1<<(ADC_SCANSQ0_SSQ4_5_POS))

/* ADC_SCANSQ1 λ�� */
#define ADC_SCANSQ1_SSQ5_0_POS          (0)
#define ADC_SCANSQ1_SSQ5_1_POS          (1)
#define ADC_SCANSQ1_SSQ5_2_POS          (2)
#define ADC_SCANSQ1_SSQ5_3_POS          (3)
#define ADC_SCANSQ1_SSQ5_4_POS          (4)
#define ADC_SCANSQ1_SSQ5_5_POS          (5)
#define ADC_SCANSQ1_SSQ6_0_POS          (6)
#define ADC_SCANSQ1_SSQ6_1_POS          (7)
#define ADC_SCANSQ1_SSQ6_2_POS          (8)
#define ADC_SCANSQ1_SSQ6_3_POS          (9)
#define ADC_SCANSQ1_SSQ6_4_POS          (10)
#define ADC_SCANSQ1_SSQ6_5_POS          (11)
#define ADC_SCANSQ1_SSQ7_0_POS          (12)
#define ADC_SCANSQ1_SSQ7_1_POS          (13)
#define ADC_SCANSQ1_SSQ7_2_POS          (14)
#define ADC_SCANSQ1_SSQ7_3_POS          (15)
#define ADC_SCANSQ1_SSQ7_4_POS          (16)
#define ADC_SCANSQ1_SSQ7_5_POS          (17)
#define ADC_SCANSQ1_SSQ8_0_POS          (18)
#define ADC_SCANSQ1_SSQ8_1_POS          (19)
#define ADC_SCANSQ1_SSQ8_2_POS          (20)
#define ADC_SCANSQ1_SSQ8_3_POS          (21)
#define ADC_SCANSQ1_SSQ8_4_POS          (22)
#define ADC_SCANSQ1_SSQ8_5_POS          (23)
#define ADC_SCANSQ1_SSQ9_0_POS          (24)
#define ADC_SCANSQ1_SSQ9_1_POS          (25)
#define ADC_SCANSQ1_SSQ9_2_POS          (26)
#define ADC_SCANSQ1_SSQ9_3_POS          (27)
#define ADC_SCANSQ1_SSQ9_4_POS          (28)
#define ADC_SCANSQ1_SSQ9_5_POS          (29)

#define ADC_SCANSQ1_SSQ5                ((uint32_t)0x3F<<(ADC_SCANSQ1_SSQ5_0_POS))
#define ADC_SCANSQ1_SSQ5_0              ((uint32_t)1<<(ADC_SCANSQ1_SSQ5_0_POS))
#define ADC_SCANSQ1_SSQ5_1              ((uint32_t)1<<(ADC_SCANSQ1_SSQ5_1_POS))
#define ADC_SCANSQ1_SSQ5_2              ((uint32_t)1<<(ADC_SCANSQ1_SSQ5_2_POS))
#define ADC_SCANSQ1_SSQ5_3              ((uint32_t)1<<(ADC_SCANSQ1_SSQ5_3_POS))
#define ADC_SCANSQ1_SSQ5_4              ((uint32_t)1<<(ADC_SCANSQ1_SSQ5_4_POS))
#define ADC_SCANSQ1_SSQ5_5              ((uint32_t)1<<(ADC_SCANSQ1_SSQ5_5_POS))
#define ADC_SCANSQ1_SSQ6                ((uint32_t)0x3F<<(ADC_SCANSQ1_SSQ6_0_POS))
#define ADC_SCANSQ1_SSQ6_0              ((uint32_t)1<<(ADC_SCANSQ1_SSQ6_0_POS))
#define ADC_SCANSQ1_SSQ6_1              ((uint32_t)1<<(ADC_SCANSQ1_SSQ6_1_POS))
#define ADC_SCANSQ1_SSQ6_2              ((uint32_t)1<<(ADC_SCANSQ1_SSQ6_2_POS))
#define ADC_SCANSQ1_SSQ6_3              ((uint32_t)1<<(ADC_SCANSQ1_SSQ6_3_POS))
#define ADC_SCANSQ1_SSQ6_4              ((uint32_t)1<<(ADC_SCANSQ1_SSQ6_4_POS))
#define ADC_SCANSQ1_SSQ6_5              ((uint32_t)1<<(ADC_SCANSQ1_SSQ6_5_POS))
#define ADC_SCANSQ1_SSQ7                ((uint32_t)0x3F<<(ADC_SCANSQ1_SSQ7_0_POS))
#define ADC_SCANSQ1_SSQ7_0              ((uint32_t)1<<(ADC_SCANSQ1_SSQ7_0_POS))
#define ADC_SCANSQ1_SSQ7_1              ((uint32_t)1<<(ADC_SCANSQ1_SSQ7_1_POS))
#define ADC_SCANSQ1_SSQ7_2              ((uint32_t)1<<(ADC_SCANSQ1_SSQ7_2_POS))
#define ADC_SCANSQ1_SSQ7_3              ((uint32_t)1<<(ADC_SCANSQ1_SSQ7_3_POS))
#define ADC_SCANSQ1_SSQ7_4              ((uint32_t)1<<(ADC_SCANSQ1_SSQ7_4_POS))
#define ADC_SCANSQ1_SSQ7_5              ((uint32_t)1<<(ADC_SCANSQ1_SSQ7_5_POS))
#define ADC_SCANSQ1_SSQ8                ((uint32_t)0x3F<<(ADC_SCANSQ1_SSQ8_0_POS))
#define ADC_SCANSQ1_SSQ8_0              ((uint32_t)1<<(ADC_SCANSQ1_SSQ8_0_POS))
#define ADC_SCANSQ1_SSQ8_1              ((uint32_t)1<<(ADC_SCANSQ1_SSQ8_1_POS))
#define ADC_SCANSQ1_SSQ8_2              ((uint32_t)1<<(ADC_SCANSQ1_SSQ8_2_POS))
#define ADC_SCANSQ1_SSQ8_3              ((uint32_t)1<<(ADC_SCANSQ1_SSQ8_3_POS))
#define ADC_SCANSQ1_SSQ8_4              ((uint32_t)1<<(ADC_SCANSQ1_SSQ8_4_POS))
#define ADC_SCANSQ1_SSQ8_5              ((uint32_t)1<<(ADC_SCANSQ1_SSQ8_5_POS))
#define ADC_SCANSQ1_SSQ9                ((uint32_t)0x3F<<(ADC_SCANSQ1_SSQ9_0_POS))
#define ADC_SCANSQ1_SSQ9_0              ((uint32_t)1<<(ADC_SCANSQ1_SSQ9_0_POS))
#define ADC_SCANSQ1_SSQ9_1              ((uint32_t)1<<(ADC_SCANSQ1_SSQ9_1_POS))
#define ADC_SCANSQ1_SSQ9_2              ((uint32_t)1<<(ADC_SCANSQ1_SSQ9_2_POS))
#define ADC_SCANSQ1_SSQ9_3              ((uint32_t)1<<(ADC_SCANSQ1_SSQ9_3_POS))
#define ADC_SCANSQ1_SSQ9_4              ((uint32_t)1<<(ADC_SCANSQ1_SSQ9_4_POS))
#define ADC_SCANSQ1_SSQ9_5              ((uint32_t)1<<(ADC_SCANSQ1_SSQ9_5_POS))

/* ADC_SCANSQ2 λ�� */
#define ADC_SCANSQ2_SSQ10_0_POS         (0)
#define ADC_SCANSQ2_SSQ10_1_POS         (1)
#define ADC_SCANSQ2_SSQ10_2_POS         (2)
#define ADC_SCANSQ2_SSQ10_3_POS         (3)
#define ADC_SCANSQ2_SSQ10_4_POS         (4)
#define ADC_SCANSQ2_SSQ10_5_POS         (5)
#define ADC_SCANSQ2_SSQ11_0_POS         (6)
#define ADC_SCANSQ2_SSQ11_1_POS         (7)
#define ADC_SCANSQ2_SSQ11_2_POS         (8)
#define ADC_SCANSQ2_SSQ11_3_POS         (9)
#define ADC_SCANSQ2_SSQ11_4_POS         (10)
#define ADC_SCANSQ2_SSQ11_5_POS         (11)
#define ADC_SCANSQ2_SSQ12_0_POS         (12)
#define ADC_SCANSQ2_SSQ12_1_POS         (13)
#define ADC_SCANSQ2_SSQ12_2_POS         (14)
#define ADC_SCANSQ2_SSQ12_3_POS         (15)
#define ADC_SCANSQ2_SSQ12_4_POS         (16)
#define ADC_SCANSQ2_SSQ12_5_POS         (17)
#define ADC_SCANSQ2_SSQ13_0_POS         (18)
#define ADC_SCANSQ2_SSQ13_1_POS         (19)
#define ADC_SCANSQ2_SSQ13_2_POS         (20)
#define ADC_SCANSQ2_SSQ13_3_POS         (21)
#define ADC_SCANSQ2_SSQ13_4_POS         (22)
#define ADC_SCANSQ2_SSQ13_5_POS         (23)
#define ADC_SCANSQ2_SSQ14_0_POS         (24)
#define ADC_SCANSQ2_SSQ14_1_POS         (25)
#define ADC_SCANSQ2_SSQ14_2_POS         (26)
#define ADC_SCANSQ2_SSQ14_3_POS         (27)
#define ADC_SCANSQ2_SSQ14_4_POS         (28)
#define ADC_SCANSQ2_SSQ14_5_POS         (29)
#define ADC_SCANSQ2_SSQ10               ((uint32_t)0x3F<<(ADC_SCANSQ2_SSQ10_0_POS))
#define ADC_SCANSQ2_SSQ10_0             ((uint32_t)1<<(ADC_SCANSQ2_SSQ10_0_POS))
#define ADC_SCANSQ2_SSQ10_1             ((uint32_t)1<<(ADC_SCANSQ2_SSQ10_1_POS))
#define ADC_SCANSQ2_SSQ10_2             ((uint32_t)1<<(ADC_SCANSQ2_SSQ10_2_POS))
#define ADC_SCANSQ2_SSQ10_3             ((uint32_t)1<<(ADC_SCANSQ2_SSQ10_3_POS))
#define ADC_SCANSQ2_SSQ10_4             ((uint32_t)1<<(ADC_SCANSQ2_SSQ10_4_POS))
#define ADC_SCANSQ2_SSQ10_5             ((uint32_t)1<<(ADC_SCANSQ2_SSQ10_5_POS))
#define ADC_SCANSQ2_SSQ11               ((uint32_t)0x3F<<(ADC_SCANSQ2_SSQ11_0_POS))
#define ADC_SCANSQ2_SSQ11_0             ((uint32_t)1<<(ADC_SCANSQ2_SSQ11_0_POS))
#define ADC_SCANSQ2_SSQ11_1             ((uint32_t)1<<(ADC_SCANSQ2_SSQ11_1_POS))
#define ADC_SCANSQ2_SSQ11_2             ((uint32_t)1<<(ADC_SCANSQ2_SSQ11_2_POS))
#define ADC_SCANSQ2_SSQ11_3             ((uint32_t)1<<(ADC_SCANSQ2_SSQ11_3_POS))
#define ADC_SCANSQ2_SSQ11_4             ((uint32_t)1<<(ADC_SCANSQ2_SSQ11_4_POS))
#define ADC_SCANSQ2_SSQ11_5             ((uint32_t)1<<(ADC_SCANSQ2_SSQ11_5_POS))
#define ADC_SCANSQ2_SSQ12               ((uint32_t)0x3F<<(ADC_SCANSQ2_SSQ12_0_POS))
#define ADC_SCANSQ2_SSQ12_0             ((uint32_t)1<<(ADC_SCANSQ2_SSQ12_0_POS))
#define ADC_SCANSQ2_SSQ12_1             ((uint32_t)1<<(ADC_SCANSQ2_SSQ12_1_POS))
#define ADC_SCANSQ2_SSQ12_2             ((uint32_t)1<<(ADC_SCANSQ2_SSQ12_2_POS))
#define ADC_SCANSQ2_SSQ12_3             ((uint32_t)1<<(ADC_SCANSQ2_SSQ12_3_POS))
#define ADC_SCANSQ2_SSQ12_4             ((uint32_t)1<<(ADC_SCANSQ2_SSQ12_4_POS))
#define ADC_SCANSQ2_SSQ12_5             ((uint32_t)1<<(ADC_SCANSQ2_SSQ12_5_POS))
#define ADC_SCANSQ2_SSQ13               ((uint32_t)0x3F<<(ADC_SCANSQ2_SSQ13_0_POS))
#define ADC_SCANSQ2_SSQ13_0             ((uint32_t)1<<(ADC_SCANSQ2_SSQ13_0_POS))
#define ADC_SCANSQ2_SSQ13_1             ((uint32_t)1<<(ADC_SCANSQ2_SSQ13_1_POS))
#define ADC_SCANSQ2_SSQ13_2             ((uint32_t)1<<(ADC_SCANSQ2_SSQ13_2_POS))
#define ADC_SCANSQ2_SSQ13_3             ((uint32_t)1<<(ADC_SCANSQ2_SSQ13_3_POS))
#define ADC_SCANSQ2_SSQ13_4             ((uint32_t)1<<(ADC_SCANSQ2_SSQ13_4_POS))
#define ADC_SCANSQ2_SSQ13_5             ((uint32_t)1<<(ADC_SCANSQ2_SSQ13_5_POS))
#define ADC_SCANSQ2_SSQ14               ((uint32_t)0x3F<<(ADC_SCANSQ2_SSQ14_0_POS))
#define ADC_SCANSQ2_SSQ14_0             ((uint32_t)1<<(ADC_SCANSQ2_SSQ14_0_POS))
#define ADC_SCANSQ2_SSQ14_1             ((uint32_t)1<<(ADC_SCANSQ2_SSQ14_1_POS))
#define ADC_SCANSQ2_SSQ14_2             ((uint32_t)1<<(ADC_SCANSQ2_SSQ14_2_POS))
#define ADC_SCANSQ2_SSQ14_3             ((uint32_t)1<<(ADC_SCANSQ2_SSQ14_3_POS))
#define ADC_SCANSQ2_SSQ14_4             ((uint32_t)1<<(ADC_SCANSQ2_SSQ14_4_POS))
#define ADC_SCANSQ2_SSQ14_5             ((uint32_t)1<<(ADC_SCANSQ2_SSQ14_5_POS))

/* ADC_SCANSQ3 λ�� */
#define ADC_SCANSQ3_SSQ15_0_POS         (0)
#define ADC_SCANSQ3_SSQ15_1_POS         (1)
#define ADC_SCANSQ3_SSQ15_2_POS         (2)
#define ADC_SCANSQ3_SSQ15_3_POS         (3)
#define ADC_SCANSQ3_SSQ15_4_POS         (4)
#define ADC_SCANSQ3_SSQ15_5_POS         (5)
#define ADC_SCANSQ3_WDCH_0_POS          (20)
#define ADC_SCANSQ3_WDCH_1_POS          (21)
#define ADC_SCANSQ3_WDCH_2_POS          (22)
#define ADC_SCANSQ3_WDCH_3_POS          (23)
#define ADC_SCANSQ3_WDCH_4_POS          (24)
#define ADC_SCANSQ3_WDCH_5_POS          (25)
#define ADC_SCANSQ3_SLEN_0_POS          (28)
#define ADC_SCANSQ3_SLEN_1_POS          (29)
#define ADC_SCANSQ3_SLEN_2_POS          (30)
#define ADC_SCANSQ3_SLEN_3_POS          (31)
#define ADC_SCANSQ3_SSQ15               ((uint32_t)0x3F<<(ADC_SCANSQ3_SSQ15_0_POS))
#define ADC_SCANSQ3_SSQ15_0             ((uint32_t)1<<(ADC_SCANSQ3_SSQ15_0_POS))
#define ADC_SCANSQ3_SSQ15_1             ((uint32_t)1<<(ADC_SCANSQ3_SSQ15_1_POS))
#define ADC_SCANSQ3_SSQ15_2             ((uint32_t)1<<(ADC_SCANSQ3_SSQ15_2_POS))
#define ADC_SCANSQ3_SSQ15_3             ((uint32_t)1<<(ADC_SCANSQ3_SSQ15_3_POS))
#define ADC_SCANSQ3_SSQ15_4             ((uint32_t)1<<(ADC_SCANSQ3_SSQ15_4_POS))
#define ADC_SCANSQ3_SSQ15_5             ((uint32_t)1<<(ADC_SCANSQ3_SSQ15_5_POS))
#define ADC_SCANSQ3_WDCH                ((uint32_t)0x3F<<(ADC_SCANSQ3_WDCH_0_POS))
#define ADC_SCANSQ3_WDCH_0              ((uint32_t)1<<(ADC_SCANSQ3_WDCH_0_POS))
#define ADC_SCANSQ3_WDCH_1              ((uint32_t)1<<(ADC_SCANSQ3_WDCH_1_POS))
#define ADC_SCANSQ3_WDCH_2              ((uint32_t)1<<(ADC_SCANSQ3_WDCH_2_POS))
#define ADC_SCANSQ3_WDCH_3              ((uint32_t)1<<(ADC_SCANSQ3_WDCH_3_POS))
#define ADC_SCANSQ3_WDCH_4              ((uint32_t)1<<(ADC_SCANSQ3_WDCH_4_POS))
#define ADC_SCANSQ3_WDCH_5              ((uint32_t)1<<(ADC_SCANSQ3_WDCH_5_POS))
#define ADC_SCANSQ3_SLEN                ((uint32_t)0xF<<(ADC_SCANSQ3_SLEN_0_POS))
#define ADC_SCANSQ3_SLEN_0              ((uint32_t)1<<(ADC_SCANSQ3_SLEN_0_POS))
#define ADC_SCANSQ3_SLEN_1              ((uint32_t)1<<(ADC_SCANSQ3_SLEN_1_POS))
#define ADC_SCANSQ3_SLEN_2              ((uint32_t)1<<(ADC_SCANSQ3_SLEN_2_POS))
#define ADC_SCANSQ3_SLEN_3              ((uint32_t)1<<(ADC_SCANSQ3_SLEN_3_POS))

/* ADC_HSCANSQ λ�� */
#define ADC_HSCANSQ_SSQ1_0_POS          (0)
#define ADC_HSCANSQ_SSQ1_1_POS          (1)
#define ADC_HSCANSQ_SSQ1_2_POS          (2)
#define ADC_HSCANSQ_SSQ1_3_POS          (3)
#define ADC_HSCANSQ_SSQ1_4_POS          (4)
#define ADC_HSCANSQ_SSQ1_5_POS          (5)
#define ADC_HSCANSQ_SSQ2_0_POS          (6)
#define ADC_HSCANSQ_SSQ2_1_POS          (7)
#define ADC_HSCANSQ_SSQ2_2_POS          (8)
#define ADC_HSCANSQ_SSQ2_3_POS          (9)
#define ADC_HSCANSQ_SSQ2_4_POS          (10)
#define ADC_HSCANSQ_SSQ2_5_POS          (11)
#define ADC_HSCANSQ_SSQ3_0_POS          (12)
#define ADC_HSCANSQ_SSQ3_1_POS          (13)
#define ADC_HSCANSQ_SSQ3_2_POS          (14)
#define ADC_HSCANSQ_SSQ3_3_POS          (15)
#define ADC_HSCANSQ_SSQ3_4_POS          (16)
#define ADC_HSCANSQ_SSQ3_5_POS          (17)
#define ADC_HSCANSQ_SSQ4_0_POS          (18)
#define ADC_HSCANSQ_SSQ4_1_POS          (19)
#define ADC_HSCANSQ_SSQ4_2_POS          (20)
#define ADC_HSCANSQ_SSQ4_3_POS          (21)
#define ADC_HSCANSQ_SSQ4_4_POS          (22)
#define ADC_HSCANSQ_SSQ4_5_POS          (23)
#define ADC_HSCANSQ_HSLEN_0_POS         (28)
#define ADC_HSCANSQ_HSLEN_1_POS         (29)
#define ADC_HSCANSQ_SSQ1                ((uint32_t)0x3F<<(ADC_HSCANSQ_SSQ1_0_POS))
#define ADC_HSCANSQ_SSQ1_0              ((uint32_t)1<<(ADC_HSCANSQ_SSQ1_0_POS))
#define ADC_HSCANSQ_SSQ1_1              ((uint32_t)1<<(ADC_HSCANSQ_SSQ1_1_POS))
#define ADC_HSCANSQ_SSQ1_2              ((uint32_t)1<<(ADC_HSCANSQ_SSQ1_2_POS))
#define ADC_HSCANSQ_SSQ1_3              ((uint32_t)1<<(ADC_HSCANSQ_SSQ1_3_POS))
#define ADC_HSCANSQ_SSQ1_4              ((uint32_t)1<<(ADC_HSCANSQ_SSQ1_4_POS))
#define ADC_HSCANSQ_SSQ1_5              ((uint32_t)1<<(ADC_HSCANSQ_SSQ1_5_POS))
#define ADC_HSCANSQ_SSQ2                ((uint32_t)0x3F<<(ADC_HSCANSQ_SSQ2_0_POS))
#define ADC_HSCANSQ_SSQ2_0              ((uint32_t)1<<(ADC_HSCANSQ_SSQ2_0_POS))
#define ADC_HSCANSQ_SSQ2_1              ((uint32_t)1<<(ADC_HSCANSQ_SSQ2_1_POS))
#define ADC_HSCANSQ_SSQ2_2              ((uint32_t)1<<(ADC_HSCANSQ_SSQ2_2_POS))
#define ADC_HSCANSQ_SSQ2_3              ((uint32_t)1<<(ADC_HSCANSQ_SSQ2_3_POS))
#define ADC_HSCANSQ_SSQ2_4              ((uint32_t)1<<(ADC_HSCANSQ_SSQ2_4_POS))
#define ADC_HSCANSQ_SSQ2_5              ((uint32_t)1<<(ADC_HSCANSQ_SSQ2_5_POS))
#define ADC_HSCANSQ_SSQ3                ((uint32_t)0x3F<<(ADC_HSCANSQ_SSQ3_0_POS))
#define ADC_HSCANSQ_SSQ3_0              ((uint32_t)1<<(ADC_HSCANSQ_SSQ3_0_POS))
#define ADC_HSCANSQ_SSQ3_1              ((uint32_t)1<<(ADC_HSCANSQ_SSQ3_1_POS))
#define ADC_HSCANSQ_SSQ3_2              ((uint32_t)1<<(ADC_HSCANSQ_SSQ3_2_POS))
#define ADC_HSCANSQ_SSQ3_3              ((uint32_t)1<<(ADC_HSCANSQ_SSQ3_3_POS))
#define ADC_HSCANSQ_SSQ3_4              ((uint32_t)1<<(ADC_HSCANSQ_SSQ3_4_POS))
#define ADC_HSCANSQ_SSQ3_5              ((uint32_t)1<<(ADC_HSCANSQ_SSQ3_5_POS))
#define ADC_HSCANSQ_SSQ4                ((uint32_t)0x3F<<(ADC_HSCANSQ_SSQ4_0_POS))
#define ADC_HSCANSQ_SSQ4_0              ((uint32_t)1<<(ADC_HSCANSQ_SSQ4_0_POS))
#define ADC_HSCANSQ_SSQ4_1              ((uint32_t)1<<(ADC_HSCANSQ_SSQ4_1_POS))
#define ADC_HSCANSQ_SSQ4_2              ((uint32_t)1<<(ADC_HSCANSQ_SSQ4_2_POS))
#define ADC_HSCANSQ_SSQ4_3              ((uint32_t)1<<(ADC_HSCANSQ_SSQ4_3_POS))
#define ADC_HSCANSQ_SSQ4_4              ((uint32_t)1<<(ADC_HSCANSQ_SSQ4_4_POS))
#define ADC_HSCANSQ_SSQ4_5              ((uint32_t)1<<(ADC_HSCANSQ_SSQ4_5_POS))
#define ADC_HSCANSQ_HSLEN               ((uint32_t)0x3<<(ADC_HSCANSQ_HSLEN_0_POS))
#define ADC_HSCANSQ_HSLEN_0             ((uint32_t)1<<(ADC_HSCANSQ_HSLEN_0_POS))
#define ADC_HSCANSQ_HSLEN_1             ((uint32_t)1<<(ADC_HSCANSQ_HSLEN_1_POS))

/* ADC_WDH λ�� */
#define ADC_WDH_WDH0_POS                (0)
#define ADC_WDH_WDH                     ((uint32_t)0xFFF<<(ADC_WDH_WDH0_POS))

/* ADC_WDL λ�� */
#define ADC_WDL_WDL0_POS                (0)
#define ADC_WDL_WDL                     ((uint32_t)0xFFF<<(ADC_WDL_WDL0_POS))

/* ADC_DATA λ�� */
#define ADC_DATA_DATA0_POS              (0)
#define ADC_DATA_DATA                   ((uint32_t)0xFFFF<<(ADC_DATA_DATA0_POS))

/* ADC_HPDATA λ�� */
#define ADC_HPDATA_HPDATA0_POS          (0)
#define ADC_HPDATA_HPDATA               ((uint32_t)0xFFFF<<(ADC_HPDATA_HPDATA0_POS))

/* ADC_HPDOFF λ�� */
#define ADC_HPDOFF_HPDOFF0_POS          (0)
#define ADC_HPDOFF_HPDOFF               ((uint32_t)0xFFFF<<(ADC_HPDOFF_HPDOFF0_POS))

/* ADC_STATE λ�� */
#define ADC_STATE_STARTIF_POS           (0)
#define ADC_STATE_HPSTARTIF_POS         (1)
#define ADC_STATE_ENDIF_POS             (2)
#define ADC_STATE_HPENDIF_POS           (3)
#define ADC_STATE_WDIF_POS              (4)
#define ADC_STATE_ENDIC_POS             (5)
#define ADC_STATE_HPENDIC_POS           (6)
#define ADC_STATE_WDIC_POS              (7)
#define ADC_STATE_ENDIE_POS             (8)
#define ADC_STATE_HPENDIE_POS           (9)
#define ADC_STATE_WDIE_POS              (10)
#define ADC_STATE_EOCIF_POS             (11)
#define ADC_STATE_EOCIC_POS             (12)
#define ADC_STATE_EOCIE_POS             (13)
#define ADC_STATE_CCR0N_POS             (14)
#define ADC_STATE_CCR0H_POS             (15)
#define ADC_STATE_CCR1N_POS             (16)
#define ADC_STATE_CCR1H_POS             (17)
#define ADC_STATE_CCR2N_POS             (18)
#define ADC_STATE_CCR2H_POS             (19)
#define ADC_STATE_CCR3N_POS             (20)
#define ADC_STATE_CCR3H_POS             (21)
#define ADC_STATE_CCR4N_POS             (22)
#define ADC_STATE_CCR4H_POS             (23)
#define ADC_STATE_CCR5N_POS             (24)
#define ADC_STATE_CCR5H_POS             (25)
#define ADC_STATE_TSSELTOADCIS0_POS     (26)
#define ADC_STATE_TRIMIBIASOPA_POS      (27)
#define ADC_STATE_TSSELTOADCIS1_POS     (28)
#define ADC_STATE_TSSELTOADCIS2_POS     (29)
#define ADC_STATE_TRIMERROR0_POS        (30)
#define ADC_STATE_TRIMERROR1_POS        (31)
#define ADC_STATE_STARTIF               ((uint32_t)1<<(ADC_STATE_STARTIF_POS))
#define ADC_STATE_HPSTARTIF             ((uint32_t)1<<(ADC_STATE_HPSTARTIF_POS))
#define ADC_STATE_ENDIF                 ((uint32_t)1<<(ADC_STATE_ENDIF_POS))
#define ADC_STATE_HPENDIF               ((uint32_t)1<<(ADC_STATE_HPENDIF_POS))
#define ADC_STATE_WDIF                  ((uint32_t)1<<(ADC_STATE_WDIF_POS))
#define ADC_STATE_ENDIC                 ((uint32_t)1<<(ADC_STATE_ENDIC_POS))
#define ADC_STATE_HPENDIC               ((uint32_t)1<<(ADC_STATE_HPENDIC_POS))
#define ADC_STATE_WDIC                  ((uint32_t)1<<(ADC_STATE_WDIC_POS))
#define ADC_STATE_ENDIE                 ((uint32_t)1<<(ADC_STATE_ENDIE_POS))
#define ADC_STATE_HPENDIE               ((uint32_t)1<<(ADC_STATE_HPENDIE_POS))
#define ADC_STATE_WDIE                  ((uint32_t)1<<(ADC_STATE_WDIE_POS))
#define ADC_STATE_EOCIF                 ((uint32_t)1<<(ADC_STATE_EOCIF_POS))
#define ADC_STATE_EOCIC                 ((uint32_t)1<<(ADC_STATE_EOCIC_POS))
#define ADC_STATE_EOCIE                 ((uint32_t)1<<(ADC_STATE_EOCIE_POS))
#define ADC_STATE_CCR0N                 ((uint32_t)1<<(ADC_STATE_CCR0N_POS))
#define ADC_STATE_CCR0H                 ((uint32_t)1<<(ADC_STATE_CCR0H_POS))
#define ADC_STATE_CCR1N                 ((uint32_t)1<<(ADC_STATE_CCR1N_POS))
#define ADC_STATE_CCR1H                 ((uint32_t)1<<(ADC_STATE_CCR1H_POS))
#define ADC_STATE_CCR2N                 ((uint32_t)1<<(ADC_STATE_CCR2N_POS))
#define ADC_STATE_CCR2H                 ((uint32_t)1<<(ADC_STATE_CCR2H_POS))
#define ADC_STATE_CCR3N                 ((uint32_t)1<<(ADC_STATE_CCR3N_POS))
#define ADC_STATE_CCR3H                 ((uint32_t)1<<(ADC_STATE_CCR3H_POS))
#define ADC_STATE_CCR4N                 ((uint32_t)1<<(ADC_STATE_CCR4N_POS))
#define ADC_STATE_CCR4H                 ((uint32_t)1<<(ADC_STATE_CCR4H_POS))
#define ADC_STATE_CCR5N                 ((uint32_t)1<<(ADC_STATE_CCR5N_POS))
#define ADC_STATE_CCR5H                 ((uint32_t)1<<(ADC_STATE_CCR5H_POS))
#define ADC_STATE_TSSELTOADCIS          ((uint32_t)0xD<<(ADC_STATE_TSSELTOADCIS0_POS))
#define ADC_STATE_TSSELTOADCIS0         ((uint32_t)1<<(ADC_STATE_TSSELTOADCIS0_POS))
#define ADC_STATE_TRIMIBIASOPA          ((uint32_t)1<<(ADC_STATE_TRIMIBIASOPA_POS))
#define ADC_STATE_TSSELTOADCIS1         ((uint32_t)1<<(ADC_STATE_TSSELTOADCIS1_POS))
#define ADC_STATE_TSSELTOADCIS2         ((uint32_t)1<<(ADC_STATE_TSSELTOADCIS2_POS))
#define ADC_STATE_TRIMERROR             ((uint32_t)3<<(ADC_STATE_TRIMERROR0_POS))
#define ADC_STATE_TRIMERROR0            ((uint32_t)1<<(ADC_STATE_TRIMERROR0_POS))
#define ADC_STATE_TRIMERROR1            ((uint32_t)1<<(ADC_STATE_TRIMERROR1_POS))

/* ADC0_DELAY λ�� */
#define ADC0_DELAY_FDELAY0_POS          (0)
#define ADC0_DELAY_FDELAY1_POS          (1)
#define ADC0_DELAY_FDELAY2_POS          (2)
#define ADC0_DELAY_FDELAY3_POS          (3)
#define ADC0_DELAY_FDELAY4_POS          (4)
#define ADC0_DELAY_FDELAY5_POS          (5)
#define ADC0_DELAY_SDELAY0_POS          (16)
#define ADC0_DELAY_SDELAY1_POS          (17)
#define ADC0_DELAY_SDELAY2_POS          (18)
#define ADC0_DELAY_SDELAY3_POS          (19)
#define ADC0_DELAY_SDELAY4_POS          (20)
#define ADC0_DELAY_SDELAY5_POS          (21)
#define ADC0_DELAY_FDELAY               ((uint32_t)0x3F<<(ADC0_DELAY_FDELAY0_POS))
#define ADC0_DELAY_FDELAY0              ((uint32_t)1<<(ADC0_DELAY_FDELAY0_POS))
#define ADC0_DELAY_FDELAY1              ((uint32_t)1<<(ADC0_DELAY_FDELAY1_POS))
#define ADC0_DELAY_FDELAY2              ((uint32_t)1<<(ADC0_DELAY_FDELAY2_POS))
#define ADC0_DELAY_FDELAY3              ((uint32_t)1<<(ADC0_DELAY_FDELAY3_POS))
#define ADC0_DELAY_FDELAY4              ((uint32_t)1<<(ADC0_DELAY_FDELAY4_POS))
#define ADC0_DELAY_FDELAY5              ((uint32_t)1<<(ADC0_DELAY_FDELAY5_POS))
#define ADC0_DELAY_SDELAY               ((uint32_t)0x3F<<(ADC0_DELAY_SDELAY0_POS))
#define ADC0_DELAY_SDELAY0              ((uint32_t)1<<(ADC0_DELAY_SDELAY0_POS))
#define ADC0_DELAY_SDELAY1              ((uint32_t)1<<(ADC0_DELAY_SDELAY1_POS))
#define ADC0_DELAY_SDELAY2              ((uint32_t)1<<(ADC0_DELAY_SDELAY2_POS))
#define ADC0_DELAY_SDELAY3              ((uint32_t)1<<(ADC0_DELAY_SDELAY3_POS))
#define ADC0_DELAY_SDELAY4              ((uint32_t)1<<(ADC0_DELAY_SDELAY4_POS))
#define ADC0_DELAY_SDELAY5              ((uint32_t)1<<(ADC0_DELAY_SDELAY5_POS))

/* ģ��ת��(ADC)������� */


/* ----------------------------------------------------------------------------
   -- ֱ���ڴ��ȡģ��(DMA)
   ---------------------------------------------------------------------------- */

/* DMA - ����Ĵ����ڴ�ṹ */
typedef struct DMA_MemMap {
    union {
        struct
        {
            volatile       uint32_t CTLR1;      /* DMAͨ��1���ƼĴ���, ƫ��:0x00 */
            volatile       uint32_t CTLR2;      /* DMAͨ��2���ƼĴ���, ƫ��:0x04 */
            volatile       uint32_t CTLR3;      /* DMAͨ��3���ƼĴ���, ƫ��:0x08 */
            volatile       uint32_t CTLR4;      /* DMAͨ��4���ƼĴ���, ƫ��:0x0C */
            volatile       uint32_t CTLR5;      /* DMAͨ��5���ƼĴ���, ƫ��:0x10 */
            volatile       uint32_t CTLR6;      /* DMAͨ��6���ƼĴ���, ƫ��:0x14 */
            volatile       uint32_t CTLR7;      /* DMAͨ��7���ƼĴ���, ƫ��:0x18 */
        };
        volatile       uint32_t CTLR[7];        /* DMAͨ��1~7���ƼĴ�����, ƫ��:0x00 */
    };
                   uint32_t RESERVED1;          /* ������ַ, ƫ��:0x1C */
    union {
        struct
        {
            volatile       uint32_t PADDR1;     /* DMAͨ��1�����ַ�Ĵ���, ƫ��:0x20 */
            volatile       uint32_t PADDR2;     /* DMAͨ��2�����ַ�Ĵ���, ƫ��:0x24 */
            volatile       uint32_t PADDR3;     /* DMAͨ��3�����ַ�Ĵ���, ƫ��:0x28 */
            volatile       uint32_t PADDR4;     /* DMAͨ��4�����ַ�Ĵ���, ƫ��:0x2C */
            volatile       uint32_t PADDR5;     /* DMAͨ��5�����ַ�Ĵ���, ƫ��:0x30 */
            volatile       uint32_t PADDR6;     /* DMAͨ��6�����ַ�Ĵ���, ƫ��:0x34 */
            volatile       uint32_t PADDR7;     /* DMAͨ��7�����ַ�Ĵ���, ƫ��:0x38 */
        };
        volatile       uint32_t PADDR[7];       /* DMAͨ��1~7�����ַ�Ĵ�����, ƫ��:0x20 */
    };
                   uint32_t RESERVED2;          /* ������ַ, ƫ��:0x3C */
    union {
        struct
        {
            volatile       uint32_t MADDR1;     /* DMAͨ��1�洢����ַ�Ĵ���, ƫ��:0x40 */
            volatile       uint32_t MADDR2;     /* DMAͨ��2�洢����ַ�Ĵ���, ƫ��:0x44 */
            volatile       uint32_t MADDR3;     /* DMAͨ��3�洢����ַ�Ĵ���, ƫ��:0x48 */
            volatile       uint32_t MADDR4;     /* DMAͨ��4�洢����ַ�Ĵ���, ƫ��:0x4C */
            volatile       uint32_t MADDR5;     /* DMAͨ��5�洢����ַ�Ĵ���, ƫ��:0x50 */
            volatile       uint32_t MADDR6;     /* DMAͨ��6�洢����ַ�Ĵ���, ƫ��:0x54 */
            volatile       uint32_t MADDR7;     /* DMAͨ��7�洢����ַ�Ĵ���, ƫ��:0x58 */
        };
        volatile       uint32_t MADDR[7];       /* DMAͨ��1~7�洢����ַ�Ĵ�����, ƫ��:0x40 */
    };
                   uint32_t RESERVED3;          /* ������ַ, ƫ��:0x5C */
    union {
        struct
        {
            volatile const uint32_t CPAR1;      /* DMAͨ��1��ǰ�����ַ�Ĵ���, ƫ��:0x60 */
            volatile const uint32_t CPAR2;      /* DMAͨ��2��ǰ�����ַ�Ĵ���, ƫ��:0x64 */
            volatile const uint32_t CPAR3;      /* DMAͨ��3��ǰ�����ַ�Ĵ���, ƫ��:0x68 */
            volatile const uint32_t CPAR4;      /* DMAͨ��4��ǰ�����ַ�Ĵ���, ƫ��:0x6C */
            volatile const uint32_t CPAR5;      /* DMAͨ��5��ǰ�����ַ�Ĵ���, ƫ��:0x70 */
            volatile const uint32_t CPAR6;      /* DMAͨ��6��ǰ�����ַ�Ĵ���, ƫ��:0x74 */
            volatile const uint32_t CPAR7;      /* DMAͨ��7��ǰ�����ַ�Ĵ���, ƫ��:0x78 */
        };
        volatile const uint32_t CPAR[7];        /* DMAͨ��1~7��ǰ�����ַ�Ĵ�����, ƫ��:0x60 */
    };
                   uint32_t RESERVED4;          /* ������ַ, ƫ��:0x7C */
    union {
        struct
        {
            volatile const uint32_t CMAR1;      /* DMAͨ��1��ǰ�洢����ַ�Ĵ���, ƫ��:0x80 */
            volatile const uint32_t CMAR2;      /* DMAͨ��2��ǰ�洢����ַ�Ĵ���, ƫ��:0x84 */
            volatile const uint32_t CMAR3;      /* DMAͨ��3��ǰ�洢����ַ�Ĵ���, ƫ��:0x88 */
            volatile const uint32_t CMAR4;      /* DMAͨ��4��ǰ�洢����ַ�Ĵ���, ƫ��:0x8C */
            volatile const uint32_t CMAR5;      /* DMAͨ��5��ǰ�洢����ַ�Ĵ���, ƫ��:0x90 */
            volatile const uint32_t CMAR6;      /* DMAͨ��6��ǰ�洢����ַ�Ĵ���, ƫ��:0x94 */
            volatile const uint32_t CMAR7;      /* DMAͨ��7��ǰ�洢����ַ�Ĵ���, ƫ��:0x98 */
        };
        volatile const uint32_t CMAR[7];        /* DMAͨ��1~7��ǰ�洢����ַ�Ĵ�����, ƫ��:0x80 */
    };
                   uint32_t RESERVED5;          /* ������ַ, ƫ��:0x9C */
    union {
        struct
        {
            volatile const uint32_t NCT1;       /* DMAͨ��1��ǰʣ�����ݼĴ���, ƫ��:0xA0 */
            volatile const uint32_t NCT2;       /* DMAͨ��2��ǰʣ�����ݼĴ���, ƫ��:0xA4 */
            volatile const uint32_t NCT3;       /* DMAͨ��3��ǰʣ�����ݼĴ���, ƫ��:0xA8 */
            volatile const uint32_t NCT4;       /* DMAͨ��4��ǰʣ�����ݼĴ���, ƫ��:0xAC */
            volatile const uint32_t NCT5;       /* DMAͨ��5��ǰʣ�����ݼĴ���, ƫ��:0xB0 */
            volatile const uint32_t NCT6;       /* DMAͨ��6��ǰʣ�����ݼĴ���, ƫ��:0xB4 */
            volatile const uint32_t NCT7;       /* DMAͨ��7��ǰʣ�����ݼĴ���, ƫ��:0xB8 */
        };
        volatile const uint32_t NCT[7];         /* DMAͨ��1~7��ǰʣ�����ݼĴ�����, ƫ��:0xA0 */
    };
                   uint32_t RESERVED6;          /* ������ַ, ƫ��:0xBC */
    volatile       uint32_t LIFR;               /* DMA�жϱ�־�Ĵ���, ƫ��:0xC0 */
    volatile       uint32_t LIER;               /* DMA�ж�ʹ�ܼĴ���, ƫ��:0xC4 */
}DMA_SFRmap;

/* ----------------------------------------------------------------------------
   -- DMA - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* DMA - �Ĵ�����ڵ�ַ */
#ifdef KF32F_Periph_dma0
#define DMA0_ADDR                       ((uint32_t)0x40001600)
#define DMA0_SFR                        ((DMA_SFRmap *) DMA0_ADDR)
#endif
#ifdef KF32F_Periph_dma1
#define DMA1_ADDR                       ((uint32_t)0x40001700)
#define DMA1_SFR                        ((DMA_SFRmap *) DMA1_ADDR)
#endif
/* DMA - �Ĵ������ */
#define DMA0_CTLR1                      (DMA0_SFR->CTLR1)
#define DMA0_CTLR2                      (DMA0_SFR->CTLR2)
#define DMA0_CTLR3                      (DMA0_SFR->CTLR3)
#define DMA0_CTLR4                      (DMA0_SFR->CTLR4)
#define DMA0_CTLR5                      (DMA0_SFR->CTLR5)
#define DMA0_CTLR6                      (DMA0_SFR->CTLR6)
#define DMA0_CTLR7                      (DMA0_SFR->CTLR7)
#define DMA0_PADDR1                     (DMA0_SFR->PADDR1)
#define DMA0_PADDR2                     (DMA0_SFR->PADDR2)
#define DMA0_PADDR3                     (DMA0_SFR->PADDR3)
#define DMA0_PADDR4                     (DMA0_SFR->PADDR4)
#define DMA0_PADDR5                     (DMA0_SFR->PADDR5)
#define DMA0_PADDR6                     (DMA0_SFR->PADDR6)
#define DMA0_PADDR7                     (DMA0_SFR->PADDR7)
#define DMA0_MADDR1                     (DMA0_SFR->MADDR1)
#define DMA0_MADDR2                     (DMA0_SFR->MADDR2)
#define DMA0_MADDR3                     (DMA0_SFR->MADDR3)
#define DMA0_MADDR4                     (DMA0_SFR->MADDR4)
#define DMA0_MADDR5                     (DMA0_SFR->MADDR5)
#define DMA0_MADDR6                     (DMA0_SFR->MADDR6)
#define DMA0_MADDR7                     (DMA0_SFR->MADDR7)
#define DMA0_CPAR1                      (DMA0_SFR->CPAR1)
#define DMA0_CPAR2                      (DMA0_SFR->CPAR2)
#define DMA0_CPAR3                      (DMA0_SFR->CPAR3)
#define DMA0_CPAR4                      (DMA0_SFR->CPAR4)
#define DMA0_CPAR5                      (DMA0_SFR->CPAR5)
#define DMA0_CPAR6                      (DMA0_SFR->CPAR6)
#define DMA0_CPAR7                      (DMA0_SFR->CPAR7)
#define DMA0_CMAR1                      (DMA0_SFR->CMAR1)
#define DMA0_CMAR2                      (DMA0_SFR->CMAR2)
#define DMA0_CMAR3                      (DMA0_SFR->CMAR3)
#define DMA0_CMAR4                      (DMA0_SFR->CMAR4)
#define DMA0_CMAR5                      (DMA0_SFR->CMAR5)
#define DMA0_CMAR6                      (DMA0_SFR->CMAR6)
#define DMA0_CMAR7                      (DMA0_SFR->CMAR7)
#define DMA0_NCT1                       (DMA0_SFR->NCT1)
#define DMA0_NCT2                       (DMA0_SFR->NCT2)
#define DMA0_NCT3                       (DMA0_SFR->NCT3)
#define DMA0_NCT4                       (DMA0_SFR->NCT4)
#define DMA0_NCT5                       (DMA0_SFR->NCT5)
#define DMA0_NCT6                       (DMA0_SFR->NCT6)
#define DMA0_NCT7                       (DMA0_SFR->NCT7)
#define DMA0_LIFR                       (DMA0_SFR->LIFR)
#define DMA0_LIER                       (DMA0_SFR->LIER)

#define DMA1_CTLR1                      (DMA1_SFR->CTLR1)
#define DMA1_CTLR2                      (DMA1_SFR->CTLR2)
#define DMA1_CTLR3                      (DMA1_SFR->CTLR3)
#define DMA1_CTLR4                      (DMA1_SFR->CTLR4)
#define DMA1_CTLR5                      (DMA1_SFR->CTLR5)
#define DMA1_CTLR6                      (DMA1_SFR->CTLR6)
#define DMA1_CTLR7                      (DMA1_SFR->CTLR7)
#define DMA1_PADDR1                     (DMA1_SFR->PADDR1)
#define DMA1_PADDR2                     (DMA1_SFR->PADDR2)
#define DMA1_PADDR3                     (DMA1_SFR->PADDR3)
#define DMA1_PADDR4                     (DMA1_SFR->PADDR4)
#define DMA1_PADDR5                     (DMA1_SFR->PADDR5)
#define DMA1_PADDR6                     (DMA1_SFR->PADDR6)
#define DMA1_PADDR7                     (DMA1_SFR->PADDR7)
#define DMA1_MADDR1                     (DMA1_SFR->MADDR1)
#define DMA1_MADDR2                     (DMA1_SFR->MADDR2)
#define DMA1_MADDR3                     (DMA1_SFR->MADDR3)
#define DMA1_MADDR4                     (DMA1_SFR->MADDR4)
#define DMA1_MADDR5                     (DMA1_SFR->MADDR5)
#define DMA1_MADDR6                     (DMA1_SFR->MADDR6)
#define DMA1_MADDR7                     (DMA1_SFR->MADDR7)
#define DMA1_CPAR1                      (DMA1_SFR->CPAR1)
#define DMA1_CPAR2                      (DMA1_SFR->CPAR2)
#define DMA1_CPAR3                      (DMA1_SFR->CPAR3)
#define DMA1_CPAR4                      (DMA1_SFR->CPAR4)
#define DMA1_CPAR5                      (DMA1_SFR->CPAR5)
#define DMA1_CPAR6                      (DMA1_SFR->CPAR6)
#define DMA1_CPAR7                      (DMA1_SFR->CPAR7)
#define DMA1_CMAR1                      (DMA1_SFR->CMAR1)
#define DMA1_CMAR2                      (DMA1_SFR->CMAR2)
#define DMA1_CMAR3                      (DMA1_SFR->CMAR3)
#define DMA1_CMAR4                      (DMA1_SFR->CMAR4)
#define DMA1_CMAR5                      (DMA1_SFR->CMAR5)
#define DMA1_CMAR6                      (DMA1_SFR->CMAR6)
#define DMA1_CMAR7                      (DMA1_SFR->CMAR7)
#define DMA1_NCT1                       (DMA1_SFR->NCT1)
#define DMA1_NCT2                       (DMA1_SFR->NCT2)
#define DMA1_NCT3                       (DMA1_SFR->NCT3)
#define DMA1_NCT4                       (DMA1_SFR->NCT4)
#define DMA1_NCT5                       (DMA1_SFR->NCT5)
#define DMA1_NCT6                       (DMA1_SFR->NCT6)
#define DMA1_NCT7                       (DMA1_SFR->NCT7)
#define DMA1_LIFR                       (DMA1_SFR->LIFR)
#define DMA1_LIER                       (DMA1_SFR->LIER)

/* DMA_CTLRy λ�� */
#define DMA_CTLR_DMAEN_POS              (0)
#define DMA_CTLR_BLKM_POS               (3)
#define DMA_CTLR_DDIR_POS               (4)
#define DMA_CTLR_LPM_POS                (5)
#define DMA_CTLR_MINC_POS               (6)
#define DMA_CTLR_PINC_POS               (7)
#define DMA_CTLR_MDS0_POS               (8)
#define DMA_CTLR_MDS1_POS               (9)
#define DMA_CTLR_PDS0_POS               (10)
#define DMA_CTLR_PDS1_POS               (11)
#define DMA_CTLR_CPL0_POS               (13)
#define DMA_CTLR_CPL1_POS               (14)
#define DMA_CTLR_M2M_POS                (15)
#define DMA_CTLR_NUMODT0_POS            (16)
#define DMA_CTLR_NUMODT1_POS            (17)
#define DMA_CTLR_NUMODT2_POS            (18)
#define DMA_CTLR_NUMODT3_POS            (19)
#define DMA_CTLR_NUMODT4_POS            (20)
#define DMA_CTLR_NUMODT5_POS            (21)
#define DMA_CTLR_NUMODT6_POS            (22)
#define DMA_CTLR_NUMODT7_POS            (23)
#define DMA_CTLR_NUMODT8_POS            (24)
#define DMA_CTLR_NUMODT9_POS            (25)
#define DMA_CTLR_NUMODT10_POS           (26)
#define DMA_CTLR_NUMODT11_POS           (27)
#define DMA_CTLR_NUMODT12_POS           (28)
#define DMA_CTLR_NUMODT13_POS           (29)
#define DMA_CTLR_NUMODT14_POS           (30)
#define DMA_CTLR_NUMODT15_POS           (31)
#define DMA_CTLR_DMAEN                  ((uint32_t)1<<(DMA_CTLR_DMAEN_POS))
#define DMA_CTLR_BLKM                   ((uint32_t)1<<(DMA_CTLR_BLKM_POS))
#define DMA_CTLR_DDIR                   ((uint32_t)1<<(DMA_CTLR_DDIR_POS))
#define DMA_CTLR_LPM                    ((uint32_t)1<<(DMA_CTLR_LPM_POS))
#define DMA_CTLR_MINC                   ((uint32_t)1<<(DMA_CTLR_MINC_POS))
#define DMA_CTLR_PINC                   ((uint32_t)1<<(DMA_CTLR_PINC_POS))
#define DMA_CTLR_MDS                    ((uint32_t)3<<(DMA_CTLR_MDS0_POS))
#define DMA_CTLR_MDS0                   ((uint32_t)1<<(DMA_CTLR_MDS0_POS))
#define DMA_CTLR_MDS1                   ((uint32_t)1<<(DMA_CTLR_MDS1_POS))
#define DMA_CTLR_PDS                    ((uint32_t)3<<(DMA_CTLR_PDS0_POS))
#define DMA_CTLR_PDS0                   ((uint32_t)1<<(DMA_CTLR_PDS0_POS))
#define DMA_CTLR_PDS1                   ((uint32_t)1<<(DMA_CTLR_PDS1_POS))
#define DMA_CTLR_CPL                    ((uint32_t)3<<(DMA_CTLR_CPL0_POS))
#define DMA_CTLR_CPL0                   ((uint32_t)1<<(DMA_CTLR_CPL0_POS))
#define DMA_CTLR_CPL1                   ((uint32_t)1<<(DMA_CTLR_CPL1_POS))
#define DMA_CTLR_M2M                    ((uint32_t)1<<(DMA_CTLR_M2M_POS))
#define DMA_CTLR_NUMODT                 ((uint32_t)0xFFFF<<(DMA_CTLR_NUMODT0_POS))
#define DMA_CTLR_NUMODT0                ((uint32_t)1<<(DMA_CTLR_NUMODT0_POS))
#define DMA_CTLR_NUMODT1                ((uint32_t)1<<(DMA_CTLR_NUMODT1_POS))
#define DMA_CTLR_NUMODT2                ((uint32_t)1<<(DMA_CTLR_NUMODT2_POS))
#define DMA_CTLR_NUMODT3                ((uint32_t)1<<(DMA_CTLR_NUMODT3_POS))
#define DMA_CTLR_NUMODT4                ((uint32_t)1<<(DMA_CTLR_NUMODT4_POS))
#define DMA_CTLR_NUMODT5                ((uint32_t)1<<(DMA_CTLR_NUMODT5_POS))
#define DMA_CTLR_NUMODT6                ((uint32_t)1<<(DMA_CTLR_NUMODT6_POS))
#define DMA_CTLR_NUMODT7                ((uint32_t)1<<(DMA_CTLR_NUMODT7_POS))
#define DMA_CTLR_NUMODT8                ((uint32_t)1<<(DMA_CTLR_NUMODT8_POS))
#define DMA_CTLR_NUMODT9                ((uint32_t)1<<(DMA_CTLR_NUMODT9_POS))
#define DMA_CTLR_NUMODT10               ((uint32_t)1<<(DMA_CTLR_NUMODT10_POS))
#define DMA_CTLR_NUMODT11               ((uint32_t)1<<(DMA_CTLR_NUMODT11_POS))
#define DMA_CTLR_NUMODT12               ((uint32_t)1<<(DMA_CTLR_NUMODT12_POS))
#define DMA_CTLR_NUMODT13               ((uint32_t)1<<(DMA_CTLR_NUMODT13_POS))
#define DMA_CTLR_NUMODT14               ((uint32_t)1<<(DMA_CTLR_NUMODT14_POS))
#define DMA_CTLR_NUMODT15               ((uint32_t)1<<(DMA_CTLR_NUMODT15_POS))

/* DMA_PADDR λ�� */
#define DMA_PADDR_PADDR0_POS            (0)
#define DMA_PADDR_PADDR1_POS            (1)
#define DMA_PADDR_PADDR2_POS            (2)
#define DMA_PADDR_PADDR3_POS            (3)
#define DMA_PADDR_PADDR4_POS            (4)
#define DMA_PADDR_PADDR5_POS            (5)
#define DMA_PADDR_PADDR6_POS            (6)
#define DMA_PADDR_PADDR7_POS            (7)
#define DMA_PADDR_PADDR8_POS            (8)
#define DMA_PADDR_PADDR9_POS            (9)
#define DMA_PADDR_PADDR10_POS           (10)
#define DMA_PADDR_PADDR11_POS           (11)
#define DMA_PADDR_PADDR12_POS           (12)
#define DMA_PADDR_PADDR13_POS           (13)
#define DMA_PADDR_PADDR14_POS           (14)
#define DMA_PADDR_PADDR15_POS           (15)
#define DMA_PADDR_PADDR16_POS           (16)
#define DMA_PADDR_PADDR17_POS           (17)
#define DMA_PADDR_PADDR18_POS           (18)
#define DMA_PADDR_PADDR19_POS           (19)
#define DMA_PADDR_PADDR20_POS           (20)
#define DMA_PADDR_PADDR21_POS           (21)
#define DMA_PADDR_PADDR22_POS           (22)
#define DMA_PADDR_PADDR23_POS           (23)
#define DMA_PADDR_PADDR24_POS           (24)
#define DMA_PADDR_PADDR25_POS           (25)
#define DMA_PADDR_PADDR26_POS           (26)
#define DMA_PADDR_PADDR27_POS           (27)
#define DMA_PADDR_PADDR28_POS           (28)
#define DMA_PADDR_PADDR29_POS           (29)
#define DMA_PADDR_PADDR30_POS           (30)
#define DMA_PADDR_PADDR31_POS           (31)
#define DMA_PADDR_PADDR                 ((uint32_t)0xFFFFFFFF)
#define DMA_PADDR_PADDR0                ((uint32_t)1<<(DMA_PADDR_PADDR0_POS))
#define DMA_PADDR_PADDR1                ((uint32_t)1<<(DMA_PADDR_PADDR1_POS))
#define DMA_PADDR_PADDR2                ((uint32_t)1<<(DMA_PADDR_PADDR2_POS))
#define DMA_PADDR_PADDR3                ((uint32_t)1<<(DMA_PADDR_PADDR3_POS))
#define DMA_PADDR_PADDR4                ((uint32_t)1<<(DMA_PADDR_PADDR4_POS))
#define DMA_PADDR_PADDR5                ((uint32_t)1<<(DMA_PADDR_PADDR5_POS))
#define DMA_PADDR_PADDR6                ((uint32_t)1<<(DMA_PADDR_PADDR6_POS))
#define DMA_PADDR_PADDR7                ((uint32_t)1<<(DMA_PADDR_PADDR7_POS))
#define DMA_PADDR_PADDR8                ((uint32_t)1<<(DMA_PADDR_PADDR8_POS))
#define DMA_PADDR_PADDR9                ((uint32_t)1<<(DMA_PADDR_PADDR9_POS))
#define DMA_PADDR_PADDR10               ((uint32_t)1<<(DMA_PADDR_PADDR10_POS))
#define DMA_PADDR_PADDR11               ((uint32_t)1<<(DMA_PADDR_PADDR11_POS))
#define DMA_PADDR_PADDR12               ((uint32_t)1<<(DMA_PADDR_PADDR12_POS))
#define DMA_PADDR_PADDR13               ((uint32_t)1<<(DMA_PADDR_PADDR13_POS))
#define DMA_PADDR_PADDR14               ((uint32_t)1<<(DMA_PADDR_PADDR14_POS))
#define DMA_PADDR_PADDR15               ((uint32_t)1<<(DMA_PADDR_PADDR15_POS))
#define DMA_PADDR_PADDR16               ((uint32_t)1<<(DMA_PADDR_PADDR16_POS))
#define DMA_PADDR_PADDR17               ((uint32_t)1<<(DMA_PADDR_PADDR17_POS))
#define DMA_PADDR_PADDR18               ((uint32_t)1<<(DMA_PADDR_PADDR18_POS))
#define DMA_PADDR_PADDR19               ((uint32_t)1<<(DMA_PADDR_PADDR19_POS))
#define DMA_PADDR_PADDR20               ((uint32_t)1<<(DMA_PADDR_PADDR20_POS))
#define DMA_PADDR_PADDR21               ((uint32_t)1<<(DMA_PADDR_PADDR21_POS))
#define DMA_PADDR_PADDR22               ((uint32_t)1<<(DMA_PADDR_PADDR22_POS))
#define DMA_PADDR_PADDR23               ((uint32_t)1<<(DMA_PADDR_PADDR23_POS))
#define DMA_PADDR_PADDR24               ((uint32_t)1<<(DMA_PADDR_PADDR24_POS))
#define DMA_PADDR_PADDR25               ((uint32_t)1<<(DMA_PADDR_PADDR25_POS))
#define DMA_PADDR_PADDR26               ((uint32_t)1<<(DMA_PADDR_PADDR26_POS))
#define DMA_PADDR_PADDR27               ((uint32_t)1<<(DMA_PADDR_PADDR27_POS))
#define DMA_PADDR_PADDR28               ((uint32_t)1<<(DMA_PADDR_PADDR28_POS))
#define DMA_PADDR_PADDR29               ((uint32_t)1<<(DMA_PADDR_PADDR29_POS))
#define DMA_PADDR_PADDR30               ((uint32_t)1<<(DMA_PADDR_PADDR30_POS))
#define DMA_PADDR_PADDR31               ((uint32_t)1<<(DMA_PADDR_PADDR31_POS))

/* DMA_MADDRy λ�� */
#define DMA_MADDR_MADDR0_POS            (0)
#define DMA_MADDR_MADDR1_POS            (1)
#define DMA_MADDR_MADDR2_POS            (2)
#define DMA_MADDR_MADDR3_POS            (3)
#define DMA_MADDR_MADDR4_POS            (4)
#define DMA_MADDR_MADDR5_POS            (5)
#define DMA_MADDR_MADDR6_POS            (6)
#define DMA_MADDR_MADDR7_POS            (7)
#define DMA_MADDR_MADDR8_POS            (8)
#define DMA_MADDR_MADDR9_POS            (9)
#define DMA_MADDR_MADDR10_POS           (10)
#define DMA_MADDR_MADDR11_POS           (11)
#define DMA_MADDR_MADDR12_POS           (12)
#define DMA_MADDR_MADDR13_POS           (13)
#define DMA_MADDR_MADDR14_POS           (14)
#define DMA_MADDR_MADDR15_POS           (15)
#define DMA_MADDR_MADDR16_POS           (16)
#define DMA_MADDR_MADDR17_POS           (17)
#define DMA_MADDR_MADDR18_POS           (18)
#define DMA_MADDR_MADDR19_POS           (19)
#define DMA_MADDR_MADDR20_POS           (20)
#define DMA_MADDR_MADDR21_POS           (21)
#define DMA_MADDR_MADDR22_POS           (22)
#define DMA_MADDR_MADDR23_POS           (23)
#define DMA_MADDR_MADDR24_POS           (24)
#define DMA_MADDR_MADDR25_POS           (25)
#define DMA_MADDR_MADDR26_POS           (26)
#define DMA_MADDR_MADDR27_POS           (27)
#define DMA_MADDR_MADDR28_POS           (28)
#define DMA_MADDR_MADDR29_POS           (29)
#define DMA_MADDR_MADDR30_POS           (30)
#define DMA_MADDR_MADDR31_POS           (31)
#define DMA_MADDR_MADDR                 ((uint32_t)0xFFFFFFFF)
#define DMA_MADDR_MADDR0                ((uint32_t)1<<(DMA_MADDR_MADDR0_POS))
#define DMA_MADDR_MADDR1                ((uint32_t)1<<(DMA_MADDR_MADDR1_POS))
#define DMA_MADDR_MADDR2                ((uint32_t)1<<(DMA_MADDR_MADDR2_POS))
#define DMA_MADDR_MADDR3                ((uint32_t)1<<(DMA_MADDR_MADDR3_POS))
#define DMA_MADDR_MADDR4                ((uint32_t)1<<(DMA_MADDR_MADDR4_POS))
#define DMA_MADDR_MADDR5                ((uint32_t)1<<(DMA_MADDR_MADDR5_POS))
#define DMA_MADDR_MADDR6                ((uint32_t)1<<(DMA_MADDR_MADDR6_POS))
#define DMA_MADDR_MADDR7                ((uint32_t)1<<(DMA_MADDR_MADDR7_POS))
#define DMA_MADDR_MADDR8                ((uint32_t)1<<(DMA_MADDR_MADDR8_POS))
#define DMA_MADDR_MADDR9                ((uint32_t)1<<(DMA_MADDR_MADDR9_POS))
#define DMA_MADDR_MADDR10               ((uint32_t)1<<(DMA_MADDR_MADDR10_POS))
#define DMA_MADDR_MADDR11               ((uint32_t)1<<(DMA_MADDR_MADDR11_POS))
#define DMA_MADDR_MADDR12               ((uint32_t)1<<(DMA_MADDR_MADDR12_POS))
#define DMA_MADDR_MADDR13               ((uint32_t)1<<(DMA_MADDR_MADDR13_POS))
#define DMA_MADDR_MADDR14               ((uint32_t)1<<(DMA_MADDR_MADDR14_POS))
#define DMA_MADDR_MADDR15               ((uint32_t)1<<(DMA_MADDR_MADDR15_POS))
#define DMA_MADDR_MADDR16               ((uint32_t)1<<(DMA_MADDR_MADDR16_POS))
#define DMA_MADDR_MADDR17               ((uint32_t)1<<(DMA_MADDR_MADDR17_POS))
#define DMA_MADDR_MADDR18               ((uint32_t)1<<(DMA_MADDR_MADDR18_POS))
#define DMA_MADDR_MADDR19               ((uint32_t)1<<(DMA_MADDR_MADDR19_POS))
#define DMA_MADDR_MADDR20               ((uint32_t)1<<(DMA_MADDR_MADDR20_POS))
#define DMA_MADDR_MADDR21               ((uint32_t)1<<(DMA_MADDR_MADDR21_POS))
#define DMA_MADDR_MADDR22               ((uint32_t)1<<(DMA_MADDR_MADDR22_POS))
#define DMA_MADDR_MADDR23               ((uint32_t)1<<(DMA_MADDR_MADDR23_POS))
#define DMA_MADDR_MADDR24               ((uint32_t)1<<(DMA_MADDR_MADDR24_POS))
#define DMA_MADDR_MADDR25               ((uint32_t)1<<(DMA_MADDR_MADDR25_POS))
#define DMA_MADDR_MADDR26               ((uint32_t)1<<(DMA_MADDR_MADDR26_POS))
#define DMA_MADDR_MADDR27               ((uint32_t)1<<(DMA_MADDR_MADDR27_POS))
#define DMA_MADDR_MADDR28               ((uint32_t)1<<(DMA_MADDR_MADDR28_POS))
#define DMA_MADDR_MADDR29               ((uint32_t)1<<(DMA_MADDR_MADDR29_POS))
#define DMA_MADDR_MADDR30               ((uint32_t)1<<(DMA_MADDR_MADDR30_POS))
#define DMA_MADDR_MADDR31               ((uint32_t)1<<(DMA_MADDR_MADDR31_POS))

/* DMA_CPARy λ�� */
#define DMA_CPAR_CPAR0_POS              (0)
#define DMA_CPAR_CPAR1_POS              (1)
#define DMA_CPAR_CPAR2_POS              (2)
#define DMA_CPAR_CPAR3_POS              (3)
#define DMA_CPAR_CPAR4_POS              (4)
#define DMA_CPAR_CPAR5_POS              (5)
#define DMA_CPAR_CPAR6_POS              (6)
#define DMA_CPAR_CPAR7_POS              (7)
#define DMA_CPAR_CPAR8_POS              (8)
#define DMA_CPAR_CPAR9_POS              (9)
#define DMA_CPAR_CPAR10_POS             (10)
#define DMA_CPAR_CPAR11_POS             (11)
#define DMA_CPAR_CPAR12_POS             (12)
#define DMA_CPAR_CPAR13_POS             (13)
#define DMA_CPAR_CPAR14_POS             (14)
#define DMA_CPAR_CPAR15_POS             (15)
#define DMA_CPAR_CPAR16_POS             (16)
#define DMA_CPAR_CPAR17_POS             (17)
#define DMA_CPAR_CPAR18_POS             (18)
#define DMA_CPAR_CPAR19_POS             (19)
#define DMA_CPAR_CPAR20_POS             (20)
#define DMA_CPAR_CPAR21_POS             (21)
#define DMA_CPAR_CPAR22_POS             (22)
#define DMA_CPAR_CPAR23_POS             (23)
#define DMA_CPAR_CPAR24_POS             (24)
#define DMA_CPAR_CPAR25_POS             (25)
#define DMA_CPAR_CPAR26_POS             (26)
#define DMA_CPAR_CPAR27_POS             (27)
#define DMA_CPAR_CPAR28_POS             (28)
#define DMA_CPAR_CPAR29_POS             (29)
#define DMA_CPAR_CPAR30_POS             (30)
#define DMA_CPAR_CPAR31_POS             (31)
#define DMA_CPAR_CPAR                   ((uint32_t)0xFFFFFFFF)
#define DMA_CPAR_CPAR0                  ((uint32_t)1<<(DMA_CPAR_CPAR0_POS))
#define DMA_CPAR_CPAR1                  ((uint32_t)1<<(DMA_CPAR_CPAR1_POS))
#define DMA_CPAR_CPAR2                  ((uint32_t)1<<(DMA_CPAR_CPAR2_POS))
#define DMA_CPAR_CPAR3                  ((uint32_t)1<<(DMA_CPAR_CPAR3_POS))
#define DMA_CPAR_CPAR4                  ((uint32_t)1<<(DMA_CPAR_CPAR4_POS))
#define DMA_CPAR_CPAR5                  ((uint32_t)1<<(DMA_CPAR_CPAR5_POS))
#define DMA_CPAR_CPAR6                  ((uint32_t)1<<(DMA_CPAR_CPAR6_POS))
#define DMA_CPAR_CPAR7                  ((uint32_t)1<<(DMA_CPAR_CPAR7_POS))
#define DMA_CPAR_CPAR8                  ((uint32_t)1<<(DMA_CPAR_CPAR8_POS))
#define DMA_CPAR_CPAR9                  ((uint32_t)1<<(DMA_CPAR_CPAR9_POS))
#define DMA_CPAR_CPAR10                 ((uint32_t)1<<(DMA_CPAR_CPAR10_POS))
#define DMA_CPAR_CPAR11                 ((uint32_t)1<<(DMA_CPAR_CPAR11_POS))
#define DMA_CPAR_CPAR12                 ((uint32_t)1<<(DMA_CPAR_CPAR12_POS))
#define DMA_CPAR_CPAR13                 ((uint32_t)1<<(DMA_CPAR_CPAR13_POS))
#define DMA_CPAR_CPAR14                 ((uint32_t)1<<(DMA_CPAR_CPAR14_POS))
#define DMA_CPAR_CPAR15                 ((uint32_t)1<<(DMA_CPAR_CPAR15_POS))
#define DMA_CPAR_CPAR16                 ((uint32_t)1<<(DMA_CPAR_CPAR16_POS))
#define DMA_CPAR_CPAR17                 ((uint32_t)1<<(DMA_CPAR_CPAR17_POS))
#define DMA_CPAR_CPAR18                 ((uint32_t)1<<(DMA_CPAR_CPAR18_POS))
#define DMA_CPAR_CPAR19                 ((uint32_t)1<<(DMA_CPAR_CPAR19_POS))
#define DMA_CPAR_CPAR20                 ((uint32_t)1<<(DMA_CPAR_CPAR20_POS))
#define DMA_CPAR_CPAR21                 ((uint32_t)1<<(DMA_CPAR_CPAR21_POS))
#define DMA_CPAR_CPAR22                 ((uint32_t)1<<(DMA_CPAR_CPAR22_POS))
#define DMA_CPAR_CPAR23                 ((uint32_t)1<<(DMA_CPAR_CPAR23_POS))
#define DMA_CPAR_CPAR24                 ((uint32_t)1<<(DMA_CPAR_CPAR24_POS))
#define DMA_CPAR_CPAR25                 ((uint32_t)1<<(DMA_CPAR_CPAR25_POS))
#define DMA_CPAR_CPAR26                 ((uint32_t)1<<(DMA_CPAR_CPAR26_POS))
#define DMA_CPAR_CPAR27                 ((uint32_t)1<<(DMA_CPAR_CPAR27_POS))
#define DMA_CPAR_CPAR28                 ((uint32_t)1<<(DMA_CPAR_CPAR28_POS))
#define DMA_CPAR_CPAR29                 ((uint32_t)1<<(DMA_CPAR_CPAR29_POS))
#define DMA_CPAR_CPAR30                 ((uint32_t)1<<(DMA_CPAR_CPAR30_POS))
#define DMA_CPAR_CPAR31                 ((uint32_t)1<<(DMA_CPAR_CPAR31_POS))

/* DMA_CMARy λ�� */
#define DMA_CMAR_CMAR0_POS              (0)
#define DMA_CMAR_CMAR1_POS              (1)
#define DMA_CMAR_CMAR2_POS              (2)
#define DMA_CMAR_CMAR3_POS              (3)
#define DMA_CMAR_CMAR4_POS              (4)
#define DMA_CMAR_CMAR5_POS              (5)
#define DMA_CMAR_CMAR6_POS              (6)
#define DMA_CMAR_CMAR7_POS              (7)
#define DMA_CMAR_CMAR8_POS              (8)
#define DMA_CMAR_CMAR9_POS              (9)
#define DMA_CMAR_CMAR10_POS             (10)
#define DMA_CMAR_CMAR11_POS             (11)
#define DMA_CMAR_CMAR12_POS             (12)
#define DMA_CMAR_CMAR13_POS             (13)
#define DMA_CMAR_CMAR14_POS             (14)
#define DMA_CMAR_CMAR15_POS             (15)
#define DMA_CMAR_CMAR16_POS             (16)
#define DMA_CMAR_CMAR17_POS             (17)
#define DMA_CMAR_CMAR18_POS             (18)
#define DMA_CMAR_CMAR19_POS             (19)
#define DMA_CMAR_CMAR20_POS             (20)
#define DMA_CMAR_CMAR21_POS             (21)
#define DMA_CMAR_CMAR22_POS             (22)
#define DMA_CMAR_CMAR23_POS             (23)
#define DMA_CMAR_CMAR24_POS             (24)
#define DMA_CMAR_CMAR25_POS             (25)
#define DMA_CMAR_CMAR26_POS             (26)
#define DMA_CMAR_CMAR27_POS             (27)
#define DMA_CMAR_CMAR28_POS             (28)
#define DMA_CMAR_CMAR29_POS             (29)
#define DMA_CMAR_CMAR30_POS             (30)
#define DMA_CMAR_CMAR31_POS             (31)
#define DMA_CMAR_CMAR                   ((uint32_t)0xFFFFFFFF)
#define DMA_CMAR_CMAR0                  ((uint32_t)1<<(DMA_CMAR_CMAR0_POS))
#define DMA_CMAR_CMAR1                  ((uint32_t)1<<(DMA_CMAR_CMAR1_POS))
#define DMA_CMAR_CMAR2                  ((uint32_t)1<<(DMA_CMAR_CMAR2_POS))
#define DMA_CMAR_CMAR3                  ((uint32_t)1<<(DMA_CMAR_CMAR3_POS))
#define DMA_CMAR_CMAR4                  ((uint32_t)1<<(DMA_CMAR_CMAR4_POS))
#define DMA_CMAR_CMAR5                  ((uint32_t)1<<(DMA_CMAR_CMAR5_POS))
#define DMA_CMAR_CMAR6                  ((uint32_t)1<<(DMA_CMAR_CMAR6_POS))
#define DMA_CMAR_CMAR7                  ((uint32_t)1<<(DMA_CMAR_CMAR7_POS))
#define DMA_CMAR_CMAR8                  ((uint32_t)1<<(DMA_CMAR_CMAR8_POS))
#define DMA_CMAR_CMAR9                  ((uint32_t)1<<(DMA_CMAR_CMAR9_POS))
#define DMA_CMAR_CMAR10                 ((uint32_t)1<<(DMA_CMAR_CMAR10_POS))
#define DMA_CMAR_CMAR11                 ((uint32_t)1<<(DMA_CMAR_CMAR11_POS))
#define DMA_CMAR_CMAR12                 ((uint32_t)1<<(DMA_CMAR_CMAR12_POS))
#define DMA_CMAR_CMAR13                 ((uint32_t)1<<(DMA_CMAR_CMAR13_POS))
#define DMA_CMAR_CMAR14                 ((uint32_t)1<<(DMA_CMAR_CMAR14_POS))
#define DMA_CMAR_CMAR15                 ((uint32_t)1<<(DMA_CMAR_CMAR15_POS))
#define DMA_CMAR_CMAR16                 ((uint32_t)1<<(DMA_CMAR_CMAR16_POS))
#define DMA_CMAR_CMAR17                 ((uint32_t)1<<(DMA_CMAR_CMAR17_POS))
#define DMA_CMAR_CMAR18                 ((uint32_t)1<<(DMA_CMAR_CMAR18_POS))
#define DMA_CMAR_CMAR19                 ((uint32_t)1<<(DMA_CMAR_CMAR19_POS))
#define DMA_CMAR_CMAR20                 ((uint32_t)1<<(DMA_CMAR_CMAR20_POS))
#define DMA_CMAR_CMAR21                 ((uint32_t)1<<(DMA_CMAR_CMAR21_POS))
#define DMA_CMAR_CMAR22                 ((uint32_t)1<<(DMA_CMAR_CMAR22_POS))
#define DMA_CMAR_CMAR23                 ((uint32_t)1<<(DMA_CMAR_CMAR23_POS))
#define DMA_CMAR_CMAR24                 ((uint32_t)1<<(DMA_CMAR_CMAR24_POS))
#define DMA_CMAR_CMAR25                 ((uint32_t)1<<(DMA_CMAR_CMAR25_POS))
#define DMA_CMAR_CMAR26                 ((uint32_t)1<<(DMA_CMAR_CMAR26_POS))
#define DMA_CMAR_CMAR27                 ((uint32_t)1<<(DMA_CMAR_CMAR27_POS))
#define DMA_CMAR_CMAR28                 ((uint32_t)1<<(DMA_CMAR_CMAR28_POS))
#define DMA_CMAR_CMAR29                 ((uint32_t)1<<(DMA_CMAR_CMAR29_POS))
#define DMA_CMAR_CMAR30                 ((uint32_t)1<<(DMA_CMAR_CMAR30_POS))
#define DMA_CMAR_CMAR31                 ((uint32_t)1<<(DMA_CMAR_CMAR31_POS))

/* DMA_NCTy λ�� */
#define DMA_NCT_NCT16_POS               (16)
#define DMA_NCT_NCT17_POS               (17)
#define DMA_NCT_NCT18_POS               (18)
#define DMA_NCT_NCT19_POS               (19)
#define DMA_NCT_NCT20_POS               (20)
#define DMA_NCT_NCT21_POS               (21)
#define DMA_NCT_NCT22_POS               (22)
#define DMA_NCT_NCT23_POS               (23)
#define DMA_NCT_NCT24_POS               (24)
#define DMA_NCT_NCT25_POS               (25)
#define DMA_NCT_NCT26_POS               (26)
#define DMA_NCT_NCT27_POS               (27)
#define DMA_NCT_NCT28_POS               (28)
#define DMA_NCT_NCT29_POS               (29)
#define DMA_NCT_NCT30_POS               (30)
#define DMA_NCT_NCT31_POS               (31)
#define DMA_NCT_NCT                     ((uint32_t)0xFFFF<<(DMA_NCT_NCT16_POS))
#define DMA_NCT_NCT16                   ((uint32_t)1<<(DMA_NCT_NCT16_POS))
#define DMA_NCT_NCT17                   ((uint32_t)1<<(DMA_NCT_NCT17_POS))
#define DMA_NCT_NCT18                   ((uint32_t)1<<(DMA_NCT_NCT18_POS))
#define DMA_NCT_NCT19                   ((uint32_t)1<<(DMA_NCT_NCT19_POS))
#define DMA_NCT_NCT20                   ((uint32_t)1<<(DMA_NCT_NCT20_POS))
#define DMA_NCT_NCT21                   ((uint32_t)1<<(DMA_NCT_NCT21_POS))
#define DMA_NCT_NCT22                   ((uint32_t)1<<(DMA_NCT_NCT22_POS))
#define DMA_NCT_NCT23                   ((uint32_t)1<<(DMA_NCT_NCT23_POS))
#define DMA_NCT_NCT24                   ((uint32_t)1<<(DMA_NCT_NCT24_POS))
#define DMA_NCT_NCT25                   ((uint32_t)1<<(DMA_NCT_NCT25_POS))
#define DMA_NCT_NCT26                   ((uint32_t)1<<(DMA_NCT_NCT26_POS))
#define DMA_NCT_NCT27                   ((uint32_t)1<<(DMA_NCT_NCT27_POS))
#define DMA_NCT_NCT28                   ((uint32_t)1<<(DMA_NCT_NCT28_POS))
#define DMA_NCT_NCT29                   ((uint32_t)1<<(DMA_NCT_NCT29_POS))
#define DMA_NCT_NCT30                   ((uint32_t)1<<(DMA_NCT_NCT30_POS))
#define DMA_NCT_NCT31                   ((uint32_t)1<<(DMA_NCT_NCT31_POS))

/* DMA_LIFR λ�� */
#define DMA_LIFR_FTIF1_POS              (0)
#define DMA_LIFR_HTIF1_POS              (1)
#define DMA_LIFR_ETIF1_POS              (2)
#define DMA_LIFR_FTIF2_POS              (3)
#define DMA_LIFR_HTIF2_POS              (4)
#define DMA_LIFR_ETIF2_POS              (5)
#define DMA_LIFR_FTIF3_POS              (6)
#define DMA_LIFR_HTIF3_POS              (7)
#define DMA_LIFR_ETIF3_POS              (8)
#define DMA_LIFR_FTIF4_POS              (9)
#define DMA_LIFR_HTIF4_POS              (10)
#define DMA_LIFR_ETIF4_POS              (11)
#define DMA_LIFR_FTIF5_POS              (12)
#define DMA_LIFR_HTIF5_POS              (13)
#define DMA_LIFR_ETIF5_POS              (14)
#define DMA_LIFR_FTIF6_POS              (15)
#define DMA_LIFR_HTIF6_POS              (16)
#define DMA_LIFR_ETIF6_POS              (17)
#define DMA_LIFR_FTIF7_POS              (18)
#define DMA_LIFR_HTIF7_POS              (19)
#define DMA_LIFR_ETIF7_POS              (20)
#define DMA_LIFR_FTIF1                  ((uint32_t)1<<(DMA_LIFR_FTIF1_POS))
#define DMA_LIFR_HTIF1                  ((uint32_t)1<<(DMA_LIFR_HTIF1_POS))
#define DMA_LIFR_ETIF1                  ((uint32_t)1<<(DMA_LIFR_ETIF1_POS))
#define DMA_LIFR_FTIF2                  ((uint32_t)1<<(DMA_LIFR_FTIF2_POS))
#define DMA_LIFR_HTIF2                  ((uint32_t)1<<(DMA_LIFR_HTIF2_POS))
#define DMA_LIFR_ETIF2                  ((uint32_t)1<<(DMA_LIFR_ETIF2_POS))
#define DMA_LIFR_FTIF3                  ((uint32_t)1<<(DMA_LIFR_FTIF3_POS))
#define DMA_LIFR_HTIF3                  ((uint32_t)1<<(DMA_LIFR_HTIF3_POS))
#define DMA_LIFR_ETIF3                  ((uint32_t)1<<(DMA_LIFR_ETIF3_POS))
#define DMA_LIFR_FTIF4                  ((uint32_t)1<<(DMA_LIFR_FTIF4_POS))
#define DMA_LIFR_HTIF4                  ((uint32_t)1<<(DMA_LIFR_HTIF4_POS))
#define DMA_LIFR_ETIF4                  ((uint32_t)1<<(DMA_LIFR_ETIF4_POS))
#define DMA_LIFR_FTIF5                  ((uint32_t)1<<(DMA_LIFR_FTIF5_POS))
#define DMA_LIFR_HTIF5                  ((uint32_t)1<<(DMA_LIFR_HTIF5_POS))
#define DMA_LIFR_ETIF5                  ((uint32_t)1<<(DMA_LIFR_ETIF5_POS))
#define DMA_LIFR_FTIF6                  ((uint32_t)1<<(DMA_LIFR_FTIF6_POS))
#define DMA_LIFR_HTIF6                  ((uint32_t)1<<(DMA_LIFR_HTIF6_POS))
#define DMA_LIFR_ETIF6                  ((uint32_t)1<<(DMA_LIFR_ETIF6_POS))
#define DMA_LIFR_FTIF7                  ((uint32_t)1<<(DMA_LIFR_FTIF7_POS))
#define DMA_LIFR_HTIF7                  ((uint32_t)1<<(DMA_LIFR_HTIF7_POS))
#define DMA_LIFR_ETIF7                  ((uint32_t)1<<(DMA_LIFR_ETIF7_POS))

/* DMA_LIER λ�� */
#define DMA_LIER_FTIE1_POS              (0)
#define DMA_LIER_HTIE1_POS              (1)
#define DMA_LIER_ETIE1_POS              (2)
#define DMA_LIER_FTIE2_POS              (3)
#define DMA_LIER_HTIE2_POS              (4)
#define DMA_LIER_ETIE2_POS              (5)
#define DMA_LIER_FTIE3_POS              (6)
#define DMA_LIER_HTIE3_POS              (7)
#define DMA_LIER_ETIE3_POS              (8)
#define DMA_LIER_FTIE4_POS              (9)
#define DMA_LIER_HTIE4_POS              (10)
#define DMA_LIER_ETIE4_POS              (11)
#define DMA_LIER_FTIE5_POS              (12)
#define DMA_LIER_HTIE5_POS              (13)
#define DMA_LIER_ETIE5_POS              (14)
#define DMA_LIER_FTIE6_POS              (15)
#define DMA_LIER_HTIE6_POS              (16)
#define DMA_LIER_ETIE6_POS              (17)
#define DMA_LIER_FTIE7_POS              (18)
#define DMA_LIER_HTIE7_POS              (19)
#define DMA_LIER_ETIE7_POS              (20)
#define DMA_LIER_FTIE1                  ((uint32_t)1<<(DMA_LIER_FTIE1_POS))
#define DMA_LIER_HTIE1                  ((uint32_t)1<<(DMA_LIER_HTIE1_POS))
#define DMA_LIER_ETIE1                  ((uint32_t)1<<(DMA_LIER_ETIE1_POS))
#define DMA_LIER_FTIE2                  ((uint32_t)1<<(DMA_LIER_FTIE2_POS))
#define DMA_LIER_HTIE2                  ((uint32_t)1<<(DMA_LIER_HTIE2_POS))
#define DMA_LIER_ETIE2                  ((uint32_t)1<<(DMA_LIER_ETIE2_POS))
#define DMA_LIER_FTIE3                  ((uint32_t)1<<(DMA_LIER_FTIE3_POS))
#define DMA_LIER_HTIE3                  ((uint32_t)1<<(DMA_LIER_HTIE3_POS))
#define DMA_LIER_ETIE3                  ((uint32_t)1<<(DMA_LIER_ETIE3_POS))
#define DMA_LIER_FTIE4                  ((uint32_t)1<<(DMA_LIER_FTIE4_POS))
#define DMA_LIER_HTIE4                  ((uint32_t)1<<(DMA_LIER_HTIE4_POS))
#define DMA_LIER_ETIE4                  ((uint32_t)1<<(DMA_LIER_ETIE4_POS))
#define DMA_LIER_FTIE5                  ((uint32_t)1<<(DMA_LIER_FTIE5_POS))
#define DMA_LIER_HTIE5                  ((uint32_t)1<<(DMA_LIER_HTIE5_POS))
#define DMA_LIER_ETIE5                  ((uint32_t)1<<(DMA_LIER_ETIE5_POS))
#define DMA_LIER_FTIE6                  ((uint32_t)1<<(DMA_LIER_FTIE6_POS))
#define DMA_LIER_HTIE6                  ((uint32_t)1<<(DMA_LIER_HTIE6_POS))
#define DMA_LIER_ETIE6                  ((uint32_t)1<<(DMA_LIER_ETIE6_POS))
#define DMA_LIER_FTIE7                  ((uint32_t)1<<(DMA_LIER_FTIE7_POS))
#define DMA_LIER_HTIE7                  ((uint32_t)1<<(DMA_LIER_HTIE7_POS))
#define DMA_LIER_ETIE7                  ((uint32_t)1<<(DMA_LIER_ETIE7_POS))
/* ֱ���ڴ��ȡģ��(DMA)������� */


/* ----------------------------------------------------------------------------
   -- ���Ķ�ʱ��(SYSTICK)
   ---------------------------------------------------------------------------- */

/* SYSTICK - ����Ĵ����ڴ�ṹ */
typedef struct SYSTICK_MemMap {
    volatile uint32_t CTL;            /* ϵͳ���Ķ�ʱ�����ƺ�״̬�Ĵ���, ƫ��:0x00 */
    volatile uint32_t RELOAD;         /* ϵͳ���Ķ�ʱ������ֵ�Ĵ���, ƫ��:0x04 */
    volatile uint32_t CV;             /* ϵͳ���Ķ�ʱ����ǰֵ�Ĵ���, ƫ��:0x08 */
    volatile uint32_t CALI;           /* ϵͳ���Ķ�ʱ��У��Ĵ���, ƫ��:0x0C */
}SYSTICK_SFRmap;

/* ----------------------------------------------------------------------------
   -- SYSTICK - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* SYSTICK - �Ĵ�����ڵ�ַ */
#define SYSTICK_ADDR                    ((uint32_t)0x402000A0)
#define SYSTICK_SFR                     ((SYSTICK_SFRmap *) SYSTICK_ADDR)

/* SYSTICK - �Ĵ������ */
#define ST_CTL                          (SYSTICK_SFR->CTL)
#define ST_RELOAD                       (SYSTICK_SFR->RELOAD)
#define ST_CV                           (SYSTICK_SFR->CV)
#define ST_CALI                         (SYSTICK_SFR->CALI)

/* ST_CTL λ�� */
#define ST_CTL_STEN_POS                 (0)
#define ST_CTL_TICKINTEN_POS            (1)
#define ST_CTL_STCLKS_POS               (2)
#define ST_CTL_COUNTZERO_POS            (16)
#define ST_CTL_STEN                     ((uint32_t)1<<(ST_CTL_STEN_POS))
#define ST_CTL_TICKINTEN                ((uint32_t)1<<(ST_CTL_TICKINTEN_POS))
#define ST_CTL_STCLKS                   ((uint32_t)1<<(ST_CTL_STCLKS_POS))
#define ST_CTL_COUNTZERO                ((uint32_t)1<<(ST_CTL_COUNTZERO_POS))

/* ST_RELOAD λ�� */
#define ST_RELOAD_STRELOAD0_POS         (0)
#define ST_RELOAD_STRELOAD              ((uint32_t)0x00FFFFFF<<(ST_RELOAD_STRELOAD0_POS))

/* STCV λ�� */
#define ST_CV_STCV0_POS                 (0)
#define ST_CV_STCV                      ((uint32_t)0x00FFFFFF<<(ST_CV_STCV0_POS))

/* STCALIB λ�� */
#define ST_CALII_STCALIB0_POS           (0)
#define ST_CALII_SKEW_POS               (30)
#define ST_CALII_STCLKREF_POS           (31)
#define ST_CALII_STCALIB                ((uint32_t)0x00FFFFFF<<(ST_CALII_STCALIB0_POS))
#define ST_CALII_SKEW                   ((uint32_t)1<<(ST_CALII_SKEW_POS))
#define ST_CALII_STCLKREF               ((uint32_t)1<<(ST_CALII_STCLKREF_POS))

/* ���Ķ�ʱ��(SYSTICK)������� */


/* ----------------------------------------------------------------------------
   -- ������ʱ������(BTIM)
   ---------------------------------------------------------------------------- */

/* Basic Timer - ����Ĵ����ڴ�ṹ */
typedef struct BTIM_MemMap {
    volatile       uint32_t CNT;      /* TxCNT�Ĵ���, ƫ��:0x00 */
    volatile       uint32_t CTL1;     /* Tx���ƼĴ���1, ƫ��:0x04 */
    volatile       uint32_t CTL2;     /* Tx���ƼĴ���2, ƫ��:0x08 */
    volatile       uint32_t PRSC;     /* TxԤ��Ƶ�Ĵ���, ƫ��:0x0C */
    volatile       uint32_t PPX;      /* PPx���ڼĴ���, ƫ��:0x10 */
    volatile       uint32_t DIER;     /* Tx�ж�ʹ�ܿ��ƼĴ���, ƫ��:0x14 */
    volatile const uint32_t SR;       /* Tx�ж�״̬�Ĵ���, ƫ��:0x18 */
    volatile       uint32_t SRIC;     /* Tx�ж�״̬����Ĵ���, ƫ��:0x1C */
}BTIM_SFRmap;/* T14 / T15 */

/* ----------------------------------------------------------------------------
   -- Basic Timer - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* Basic Timer - �Ĵ�����ڵ�ַ */
#ifdef  KF32F_Periph_btime14
#define T14_ADDR                        ((uint32_t)0x40001800)
#define T14_SFR                         ((BTIM_SFRmap *) T14_ADDR)
#endif

#ifdef  KF32F_Periph_btime15
#define T15_ADDR                        ((uint32_t)0x40001880)
#define T15_SFR                         ((BTIM_SFRmap *) T15_ADDR)
#endif

/* Basic Timer - �Ĵ������ */
#ifdef  KF32F_Periph_btime14
#define T14_CNT                         (T14_SFR->CNT)
#define T14_CTL1                        (T14_SFR->CTL1)
#define T14_CTL2                        (T14_SFR->CTL2)
#define T14_PRSC                        (T14_SFR->PRSC)
#define T14_PPX                         (T14_SFR->PPX)
#define T14_DIER                        (T14_SFR->DIER)
#define T14_SR                          (T14_SFR->SR)
#define T14_SRIC                        (T14_SFR->SRIC)
#endif

#ifdef  KF32F_Periph_btime15
#define T15_CNT                         (T15_SFR->CNT)
#define T15_CTL1                        (T15_SFR->CTL1)
#define T15_CTL2                        (T15_SFR->CTL2)
#define T15_PRSC                        (T15_SFR->PRSC)
#define T15_PPX                         (T15_SFR->PPX)
#define T15_DIER                        (T15_SFR->DIER)
#define T15_SR                          (T15_SFR->SR)
#define T15_SRIC                        (T15_SFR->SRIC)
#endif
/* Tx_CNT λ�� */
#define BTIM_CNT_TXCNT0_POS             (0)
#define BTIM_CNT_TXCNT                  ((uint32_t)0xFFFF<<(BTIM_CNT_TXCNT0_POS))

/* Tx_PPX λ�� */
#define BTIM_PPX_PPX0_POS               (0)
#define BTIM_PPX_PPX                    ((uint32_t)0xFFFF<<(BTIM_PPX_PPX0_POS))

/* Tx_CTL1 λ�� */
#define BTIM_CTL1_TXEN_POS              (0)
#define BTIM_CTL1_TXCS_POS              (1)
#define BTIM_CTL1_TXSY_POS              (2)
#define BTIM_CTL1_TXCLK0_POS            (3)
#define BTIM_CTL1_TXCLK1_POS            (4)
#define BTIM_CTL1_TXDIR_POS             (5)
#define BTIM_CTL1_TXCMS0_POS            (6)
#define BTIM_CTL1_TXCMS1_POS            (7)
#define BTIM_CTL1_TXCMS2_POS            (8)
#define BTIM_CTL1_TXEN                  ((uint32_t)1<<(BTIM_CTL1_TXEN_POS))
#define BTIM_CTL1_TXCS                  ((uint32_t)1<<(BTIM_CTL1_TXCS_POS))
#define BTIM_CTL1_TXSY                  ((uint32_t)1<<(BTIM_CTL1_TXSY_POS))
#define BTIM_CTL1_TXCLK                 ((uint32_t)3<<(BTIM_CTL1_TXCLK0_POS))
#define BTIM_CTL1_TXCLK0                ((uint32_t)1<<(BTIM_CTL1_TXCLK0_POS))
#define BTIM_CTL1_TXCLK1                ((uint32_t)1<<(BTIM_CTL1_TXCLK1_POS))
#define BTIM_CTL1_TXDIR                 ((uint32_t)1<<(BTIM_CTL1_TXDIR_POS))
#define BTIM_CTL1_TXCMS                 ((uint32_t)7<<(BTIM_CTL1_TXCMS0_POS))
#define BTIM_CTL1_TXCMS0                ((uint32_t)1<<(BTIM_CTL1_TXCMS0_POS))
#define BTIM_CTL1_TXCMS1                ((uint32_t)1<<(BTIM_CTL1_TXCMS1_POS))
#define BTIM_CTL1_TXCMS2                ((uint32_t)1<<(BTIM_CTL1_TXCMS2_POS))

/* TxCTL2 λ�� */
#define BTIM_CTL2_TXUDEN_POS            (0)
#define BTIM_CTL2_TXUDEVT_POS           (1)
#define BTIM_CTL2_TXMMS0_POS            (2)
#define BTIM_CTL2_TXMMS1_POS            (3)
#define BTIM_CTL2_TXSMS0_POS            (4)
#define BTIM_CTL2_TXSMS1_POS            (5)
#define BTIM_CTL2_TXSMS2_POS            (6)
#define BTIM_CTL2_TXTS0_POS             (7)
#define BTIM_CTL2_TXTS1_POS             (8)
#define BTIM_CTL2_TXTS2_POS             (9)
#define BTIM_CTL2_TXTS3_POS             (10)
#define BTIM_CTL2_TXMSSYNC_POS          (11)
#define BTIM_CTL2_TXUR_POS              (12)
#define BTIM_CTL2_PXSPMST_POS           (13)
#define BTIM_CTL2_PXSPM_POS             (14)
#define BTIM_CTL2_TXTRG_POS             (15)
#define BTIM_CTL2_TXUDEN                ((uint32_t)1<<(BTIM_CTL2_TXUDEN_POS))
#define BTIM_CTL2_TXUDEVT               ((uint32_t)1<<(BTIM_CTL2_TXUDEVT_POS))
#define BTIM_CTL2_TXMMS                 ((uint32_t)3<<(BTIM_CTL2_TXMMS0_POS))
#define BTIM_CTL2_TXMMS0                ((uint32_t)1<<(BTIM_CTL2_TXMMS0_POS))
#define BTIM_CTL2_TXMMS1                ((uint32_t)1<<(BTIM_CTL2_TXMMS1_POS))
#define BTIM_CTL2_TXSMS                 ((uint32_t)7<<(BTIM_CTL2_TXSMS0_POS))
#define BTIM_CTL2_TXSMS0                ((uint32_t)1<<(BTIM_CTL2_TXSMS0_POS))
#define BTIM_CTL2_TXSMS1                ((uint32_t)1<<(BTIM_CTL2_TXSMS1_POS))
#define BTIM_CTL2_TXSMS2                ((uint32_t)1<<(BTIM_CTL2_TXSMS2_POS))
#define BTIM_CTL2_TXTS                  ((uint32_t)0xF<<(BTIM_CTL2_TXTS0_POS))
#define BTIM_CTL2_TXTS0                 ((uint32_t)1<<(BTIM_CTL2_TXTS0_POS))
#define BTIM_CTL2_TXTS1                 ((uint32_t)1<<(BTIM_CTL2_TXTS1_POS))
#define BTIM_CTL2_TXTS2                 ((uint32_t)1<<(BTIM_CTL2_TXTS2_POS))
#define BTIM_CTL2_TXTS3                 ((uint32_t)1<<(BTIM_CTL2_TXTS3_POS))
#define BTIM_CTL2_TXMSSYNC              ((uint32_t)1<<(BTIM_CTL2_TXMSSYNC_POS))
#define BTIM_CTL2_TXUR                  ((uint32_t)1<<(BTIM_CTL2_TXUR_POS))
#define BTIM_CTL2_PXSPMST               ((uint32_t)1<<(BTIM_CTL2_PXSPMST_POS))
#define BTIM_CTL2_PXSPM                 ((uint32_t)1<<(BTIM_CTL2_PXSPM_POS))
#define BTIM_CTL2_TXTRG                 ((uint32_t)1<<(BTIM_CTL2_TXTRG_POS))

/* TxDIER λ�� */
#define BTIM_DIER_TXUIE_POS             (0)
#define BTIM_DIER_TXTIE_POS             (1)
#define BTIM_DIER_TXIE_POS              (2)
#define BTIM_DIER_TXUDE_POS             (3)
#define BTIM_DIER_TXTDE_POS             (4)
#define BTIM_DIER_TXUIE                 ((uint32_t)1<<(BTIM_DIER_TXUIE_POS))
#define BTIM_DIER_TXTIE                 ((uint32_t)1<<(BTIM_DIER_TXTIE_POS))
#define BTIM_DIER_TXIE                  ((uint32_t)1<<(BTIM_DIER_TXIE_POS))
#define BTIM_DIER_TXUDE                 ((uint32_t)1<<(BTIM_DIER_TXUDE_POS))
#define BTIM_DIER_TXTDE                 ((uint32_t)1<<(BTIM_DIER_TXTDE_POS))

/* TxSR λ�� */
#define BTIM_SR_TXUIF_POS               (0)
#define BTIM_SR_TXTIF_POS               (1)
#define BTIM_SR_TXIF_POS                (2)
#define BTIM_SR_TXUDF_POS               (3)
#define BTIM_SR_TXTDF_POS               (4)
#define BTIM_SR_TXUIF                   ((uint32_t)1<<(BTIM_SR_TXUIF_POS))
#define BTIM_SR_TXTIF                   ((uint32_t)1<<(BTIM_SR_TXTIF_POS))
#define BTIM_SR_TXIF                    ((uint32_t)1<<(BTIM_SR_TXIF_POS))
#define BTIM_SR_TXUDF                   ((uint32_t)1<<(BTIM_SR_TXUDF_POS))
#define BTIM_SR_TXTDF                   ((uint32_t)1<<(BTIM_SR_TXTDF_POS))

/* TxSRIC λ�� */
#define BTIM_SRIC_TXUIC_POS             (0)
#define BTIM_SRIC_TXTIC_POS             (1)
#define BTIM_SRIC_TXIC_POS              (2)
#define BTIM_SRIC_TXUIC                 ((uint32_t)1<<(BTIM_SRIC_TXUIC_POS))
#define BTIM_SRIC_TXTIC                 ((uint32_t)1<<(BTIM_SRIC_TXTIC_POS))
#define BTIM_SRIC_TXIC                  ((uint32_t)1<<(BTIM_SRIC_TXIC_POS))

/* TxPRSC λ�� */
#define BTIM_PRSC_TXCKS0_POS            (0)
#define BTIM_PRSC_TXCKS1_POS            (1)
#define BTIM_PRSC_TXCKS2_POS            (2)
#define BTIM_PRSC_TXCKS3_POS            (3)
#define BTIM_PRSC_TXCKS4_POS            (4)
#define BTIM_PRSC_TXCKS5_POS            (5)
#define BTIM_PRSC_TXCKS6_POS            (6)
#define BTIM_PRSC_TXCKS7_POS            (7)
#define BTIM_PRSC_TXCKS8_POS            (8)
#define BTIM_PRSC_TXCKS9_POS            (9)
#define BTIM_PRSC_TXCKS10_POS           (10)
#define BTIM_PRSC_TXCKS11_POS           (11)
#define BTIM_PRSC_TXCKS12_POS           (12)
#define BTIM_PRSC_TXCKS13_POS           (13)
#define BTIM_PRSC_TXCKS14_POS           (14)
#define BTIM_PRSC_TXCKS15_POS           (15)
#define BTIM_PRSC_TXCKS                 ((uint32_t)0xFFFF<<(BTIM_PRSC_TXCKS0_POS))
#define BTIM_PRSC_TXCKS0                ((uint32_t)1<<(BTIM_PRSC_TXCKS0_POS))
#define BTIM_PRSC_TXCKS1                ((uint32_t)1<<(BTIM_PRSC_TXCKS1_POS))
#define BTIM_PRSC_TXCKS2                ((uint32_t)1<<(BTIM_PRSC_TXCKS2_POS))
#define BTIM_PRSC_TXCKS3                ((uint32_t)1<<(BTIM_PRSC_TXCKS3_POS))
#define BTIM_PRSC_TXCKS4                ((uint32_t)1<<(BTIM_PRSC_TXCKS4_POS))
#define BTIM_PRSC_TXCKS5                ((uint32_t)1<<(BTIM_PRSC_TXCKS5_POS))
#define BTIM_PRSC_TXCKS6                ((uint32_t)1<<(BTIM_PRSC_TXCKS6_POS))
#define BTIM_PRSC_TXCKS7                ((uint32_t)1<<(BTIM_PRSC_TXCKS7_POS))
#define BTIM_PRSC_TXCKS8                ((uint32_t)1<<(BTIM_PRSC_TXCKS8_POS))
#define BTIM_PRSC_TXCKS9                ((uint32_t)1<<(BTIM_PRSC_TXCKS9_POS))
#define BTIM_PRSC_TXCKS10               ((uint32_t)1<<(BTIM_PRSC_TXCKS10_POS))
#define BTIM_PRSC_TXCKS11               ((uint32_t)1<<(BTIM_PRSC_TXCKS11_POS))
#define BTIM_PRSC_TXCKS12               ((uint32_t)1<<(BTIM_PRSC_TXCKS12_POS))
#define BTIM_PRSC_TXCKS13               ((uint32_t)1<<(BTIM_PRSC_TXCKS13_POS))
#define BTIM_PRSC_TXCKS14               ((uint32_t)1<<(BTIM_PRSC_TXCKS14_POS))
#define BTIM_PRSC_TXCKS15               ((uint32_t)1<<(BTIM_PRSC_TXCKS15_POS))
/* ������ʱ������(BTIM)������� */


/* ----------------------------------------------------------------------------
   -- ͨ�ö�ʱ������(GPTIM)
   ---------------------------------------------------------------------------- */

/* GPTIM - ����Ĵ����ڴ�ṹ */
typedef struct GPTIM_MemMap {
    volatile       uint32_t CNT;          /* TxCNT�Ĵ���, ƫ��:0x00 */
    volatile       uint32_t CTL1;         /* ���ƼĴ���1, ƫ��:0x04 */
    volatile       uint32_t CTL2;         /* ���ƼĴ���2, ƫ��:0x08 */
    volatile       uint32_t PRSC;         /* TxԤ��Ƶ�Ĵ���, ƫ��:0x0C */
    volatile       uint32_t PPX;          /* Tx_PPx���ڼĴ���, ƫ��:0x10 */
    volatile       uint32_t UDTIM;        /* ���¼�����, ƫ��:0x14 */
                   uint32_t RESERVED1[2]; /* ������ַ, ƫ��:0x18 */
    volatile const uint32_t CCPXC1;       /* CCP��׽�Ĵ���1, ƫ��:0x20 */
    volatile const uint32_t CCPXC2;       /* CCP��׽�Ĵ���2, ƫ��:0x24 */
    volatile const uint32_t CCPXC3;       /* CCP��׽�Ĵ���3, ƫ��:0x28 */
    volatile const uint32_t CCPXC4;       /* CCP��׽�Ĵ���4, ƫ��:0x2C */
    volatile       uint32_t CCPXSRIC;     /* CCP�жϱ�־����Ĵ���, ƫ��:0x30 */
    volatile const uint32_t CCPXDF;       /* CCP����DMA�жϱ�־�Ĵ���, ƫ��:0x34 */
                   uint32_t RESERVED2[2]; /* ������ַ, ƫ��:0x3C */
    volatile       uint32_t CCPXCTL1;     /* CCP���ƼĴ���1, ƫ��:0x40 */
    volatile       uint32_t CCPXR1;       /* CCP�Ƚ�/PWMռ�ձȼĴ���1, ƫ��:0x44 */
    volatile       uint32_t CCPXR2;       /* CCP�Ƚ�/PWMռ�ձȼĴ���2, ƫ��:0x48 */
    volatile       uint32_t CCPXR3;       /* CCP�Ƚ�/PWMռ�ձȼĴ���3, ƫ��:0x4C */
    volatile       uint32_t CCPXR4;       /* CCP�Ƚ�/PWMռ�ձȼĴ���4, ƫ��:0x50 */
    volatile       uint32_t CCPXCTL2;     /* CCP���ƼĴ���2, ƫ��:0x54 */
    volatile       uint32_t CCPXCTL3;     /* CCP���ƼĴ���3, ƫ��:0x58 */
    volatile       uint32_t CCPXEGIF;     /* CCPx�ж�״̬/�¼������Ĵ���, ƫ��:0x5C */
}GPTIM_SFRmap, CCP_SFRmap;/* T0 / T1 / T2 / T3 / T4 / T18 / T19 / T20 / T21 */

/* ----------------------------------------------------------------------------
   -- GPTIM - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* GPTIM - �Ĵ�����ڵ�ַ */
#ifdef  KF32F_Periph_gptime0
#define T0_ADDR                         ((uint32_t)0x40000880)
#define T0_SFR                          ((GPTIM_SFRmap *) T0_ADDR)
#define CCP0_ADDR                       T0_ADDR
#define CCP0_SFR                        ((CCP_SFRmap *) CCP0_ADDR)
#endif

#ifdef  KF32F_Periph_gptime1
#define T1_ADDR                         ((uint32_t)0x40000100)
#define T1_SFR                          ((GPTIM_SFRmap *) T1_ADDR)
#define CCP1_ADDR                       T1_ADDR
#define CCP1_SFR                        ((CCP_SFRmap *) CCP1_ADDR)
#endif

#ifdef  KF32F_Periph_gptime2
#define T2_ADDR                         ((uint32_t)0x40000180)
#define T2_SFR                          ((GPTIM_SFRmap *) T2_ADDR)
#define CCP2_ADDR                       T2_ADDR
#define CCP2_SFR                        ((CCP_SFRmap *) CCP2_ADDR)
#endif

#ifdef  KF32F_Periph_gptime3
#define T3_ADDR                         ((uint32_t)0x40000200)
#define T3_SFR                          ((GPTIM_SFRmap *) T3_ADDR)
#define CCP3_ADDR                       T3_ADDR
#define CCP3_SFR                        ((CCP_SFRmap *) CCP3_ADDR)
#endif

#ifdef  KF32F_Periph_gptime4
#define T4_ADDR                         ((uint32_t)0x40000280)
#define T4_SFR                          ((GPTIM_SFRmap *) T4_ADDR)
#define CCP4_ADDR                       T4_ADDR
#define CCP4_SFR                        ((CCP_SFRmap *) CCP4_ADDR)
#endif

#ifdef  KF32F_Periph_gptime18
#define T18_ADDR                        ((uint32_t)0x40001A80)
#define T18_SFR                         ((GPTIM_SFRmap *) T18_ADDR)
#define CCP18_ADDR                      T18_ADDR
#define CCP18_SFR                       ((CCP_SFRmap *) CCP18_ADDR)
#endif

#ifdef  KF32F_Periph_gptime19
#define T19_ADDR                        ((uint32_t)0x40001B00)
#define T19_SFR                         ((GPTIM_SFRmap *) T19_ADDR)
#define CCP19_ADDR                      T19_ADDR
#define CCP19_SFR                       ((CCP_SFRmap *) CCP19_ADDR)
#endif

//#ifdef  KF32F_Periph_gptime20
#define T20_ADDR                        ((uint32_t)0x40001B80)
#define T20_SFR                         ((GPTIM_SFRmap *) T20_ADDR)
#define CCP20_ADDR                      T20_ADDR
#define CCP20_SFR                       ((CCP_SFRmap *) CCP20_ADDR)
//#endif

//#ifdef  KF32F_Periph_gptime21
#define T21_ADDR                        ((uint32_t)0x40001C00)
#define T21_SFR                         ((GPTIM_SFRmap *) T21_ADDR)
#define CCP21_ADDR                      T21_ADDR
#define CCP21_SFR                       ((CCP_SFRmap *) CCP21_ADDR)
//#endif


#ifdef  KF32F_Periph_gptime22
#define T22_ADDR                        ((uint32_t)0x40001C80)
#define T22_SFR                         ((GPTIM_SFRmap *) T22_ADDR)
#define CCP22_ADDR                      T22_ADDR
#define CCP22_SFR                       ((CCP_SFRmap *) CCP22_ADDR)
#endif

#ifdef  KF32F_Periph_gptime23
#define T23_ADDR                        ((uint32_t)0x40001D00)
#define T23_SFR                         ((GPTIM_SFRmap *) T23_ADDR)
#define CCP23_ADDR                      T23_ADDR
#define CCP23_SFR                       ((CCP_SFRmap *) CCP23_ADDR)
#endif


/* GPTIM - �Ĵ������ */
#ifdef  KF32F_Periph_gptime0
#define T0_CNT                          (T0_SFR->CNT)
#define T0_CTL1                         (T0_SFR->CTL1)
#define T0_CTL2                         (T0_SFR->CTL2)
#define T0_PRSC                         (T0_SFR->PRSC)
#define T0_PPX                          (T0_SFR->PPX)
#define T0_UDTIM                        (T0_SFR->UDTIM)
#define CCP0_C1                         (CCP0_SFR->CCPXC1)
#define CCP0_C2                         (CCP0_SFR->CCPXC2)
#define CCP0_C3                         (CCP0_SFR->CCPXC3)
#define CCP0_C4                         (CCP0_SFR->CCPXC4)
#define CCP0_SRIC                       (CCP0_SFR->CCPXSRIC)
#define CCP0_DF                         (CCP0_SFR->CCPXDF)
#define CCP0_CTL1                       (CCP0_SFR->CCPXCTL1)
#define CCP0_R1                         (CCP0_SFR->CCPXR1)
#define CCP0_R2                         (CCP0_SFR->CCPXR2)
#define CCP0_R3                         (CCP0_SFR->CCPXR3)
#define CCP0_R4                         (CCP0_SFR->CCPXR4)
#define CCP0_CTL2                       (CCP0_SFR->CCPXCTL2)
#define CCP0_CTL3                       (CCP0_SFR->CCPXCTL3)
#define CCP0_EGIF                       (CCP0_SFR->CCPXEGIF)
#endif

#ifdef  KF32F_Periph_gptime1
#define T1_CNT                          (T1_SFR->CNT)
#define T1_CTL1                         (T1_SFR->CTL1)
#define T1_CTL2                         (T1_SFR->CTL2)
#define T1_PRSC                         (T1_SFR->PRSC)
#define T1_PPX                          (T1_SFR->PPX)
#define T1_UDTIM                        (T1_SFR->UDTIM)
#define CCP1_C1                         (CCP1_SFR->CCPXC1)
#define CCP1_C2                         (CCP1_SFR->CCPXC2)
#define CCP1_C3                         (CCP1_SFR->CCPXC3)
#define CCP1_C4                         (CCP1_SFR->CCPXC4)
#define CCP1_SRIC                       (CCP1_SFR->CCPXSRIC)
#define CCP1_DF                         (CCP1_SFR->CCPXDF)
#define CCP1_CTL1                       (CCP1_SFR->CCPXCTL1)
#define CCP1_R1                         (CCP1_SFR->CCPXR1)
#define CCP1_R2                         (CCP1_SFR->CCPXR2)
#define CCP1_R3                         (CCP1_SFR->CCPXR3)
#define CCP1_R4                         (CCP1_SFR->CCPXR4)
#define CCP1_CTL2                       (CCP1_SFR->CCPXCTL2)
#define CCP1_CTL3                       (CCP1_SFR->CCPXCTL3)
#define CCP1_EGIF                       (CCP1_SFR->CCPXEGIF)
#endif

#ifdef  KF32F_Periph_gptime2
#define T2_CNT                          (T2_SFR->CNT)
#define T2_CTL1                         (T2_SFR->CTL1)
#define T2_CTL2                         (T2_SFR->CTL2)
#define T2_PRSC                         (T2_SFR->PRSC)
#define T2_PPX                          (T2_SFR->PPX)
#define T2_UDTIM                        (T2_SFR->UDTIM)
#define CCP2_C1                         (CCP2_SFR->CCPXC1)
#define CCP2_C2                         (CCP2_SFR->CCPXC2)
#define CCP2_C3                         (CCP2_SFR->CCPXC3)
#define CCP2_C4                         (CCP2_SFR->CCPXC4)
#define CCP2_SRIC                       (CCP2_SFR->CCPXSRIC)
#define CCP2_DF                         (CCP2_SFR->CCPXDF)
#define CCP2_CTL1                       (CCP2_SFR->CCPXCTL1)
#define CCP2_R1                         (CCP2_SFR->CCPXR1)
#define CCP2_R2                         (CCP2_SFR->CCPXR2)
#define CCP2_R3                         (CCP2_SFR->CCPXR3)
#define CCP2_R4                         (CCP2_SFR->CCPXR4)
#define CCP2_CTL2                       (CCP2_SFR->CCPXCTL2)
#define CCP2_CTL3                       (CCP2_SFR->CCPXCTL3)
#define CCP2_EGIF                       (CCP2_SFR->CCPXEGIF)
#endif

#ifdef  KF32F_Periph_gptime3
#define T3_CNT                          (T3_SFR->CNT)
#define T3_CTL1                         (T3_SFR->CTL1)
#define T3_CTL2                         (T3_SFR->CTL2)
#define T3_PRSC                         (T3_SFR->PRSC)
#define T3_PPX                          (T3_SFR->PPX)
#define T3_UDTIM                        (T3_SFR->UDTIM)
#define CCP3_C1                         (CCP3_SFR->CCPXC1)
#define CCP3_C2                         (CCP3_SFR->CCPXC2)
#define CCP3_C3                         (CCP3_SFR->CCPXC3)
#define CCP3_C4                         (CCP3_SFR->CCPXC4)
#define CCP3_SRIC                       (CCP3_SFR->CCPXSRIC)
#define CCP3_DF                         (CCP3_SFR->CCPXDF)
#define CCP3_CTL1                       (CCP3_SFR->CCPXCTL1)
#define CCP3_R1                         (CCP3_SFR->CCPXR1)
#define CCP3_R2                         (CCP3_SFR->CCPXR2)
#define CCP3_R3                         (CCP3_SFR->CCPXR3)
#define CCP3_R4                         (CCP3_SFR->CCPXR4)
#define CCP3_CTL2                       (CCP3_SFR->CCPXCTL2)
#define CCP3_CTL3                       (CCP3_SFR->CCPXCTL3)
#define CCP3_EGIF                       (CCP3_SFR->CCPXEGIF)
#endif

#ifdef  KF32F_Periph_gptime4
#define T4_CNT                          (T4_SFR->CNT)
#define T4_CTL1                         (T4_SFR->CTL1)
#define T4_CTL2                         (T4_SFR->CTL2)
#define T4_PRSC                         (T4_SFR->PRSC)
#define T4_PPX                          (T4_SFR->PPX)
#define T4_UDTIM                        (T4_SFR->UDTIM)
#define CCP4_C1                         (CCP4_SFR->CCPXC1)
#define CCP4_C2                         (CCP4_SFR->CCPXC2)
#define CCP4_C3                         (CCP4_SFR->CCPXC3)
#define CCP4_C4                         (CCP4_SFR->CCPXC4)
#define CCP4_SRIC                       (CCP4_SFR->CCPXSRIC)
#define CCP4_DF                         (CCP4_SFR->CCPXDF)
#define CCP4_CTL1                       (CCP4_SFR->CCPXCTL1)
#define CCP4_R1                         (CCP4_SFR->CCPXR1)
#define CCP4_R2                         (CCP4_SFR->CCPXR2)
#define CCP4_R3                         (CCP4_SFR->CCPXR3)
#define CCP4_R4                         (CCP4_SFR->CCPXR4)
#define CCP4_CTL2                       (CCP4_SFR->CCPXCTL2)
#define CCP4_CTL3                       (CCP4_SFR->CCPXCTL3)
#define CCP4_EGIF                       (CCP4_SFR->CCPXEGIF)
#endif

#ifdef  KF32F_Periph_gptime18
#define T18_CNT                         (T18_SFR->CNT)
#define T18_CTL1                        (T18_SFR->CTL1)
#define T18_CTL2                        (T18_SFR->CTL2)
#define T18_PRSC                        (T18_SFR->PRSC)
#define T18_PPX                         (T18_SFR->PPX)
#define T18_UDTIM                       (T18_SFR->UDTIM)
#define CCP18_C1                        (CCP18_SFR->CCPXC1)
#define CCP18_C2                        (CCP18_SFR->CCPXC2)
#define CCP18_C3                        (CCP18_SFR->CCPXC3)
#define CCP18_C4                        (CCP18_SFR->CCPXC4)
#define CCP18_SRIC                      (CCP18_SFR->CCPXSRIC)
#define CCP18_DF                        (CCP18_SFR->CCPXDF)
#define CCP18_CTL1                      (CCP18_SFR->CCPXCTL1)
#define CCP18_R1                        (CCP18_SFR->CCPXR1)
#define CCP18_R2                        (CCP18_SFR->CCPXR2)
#define CCP18_R3                        (CCP18_SFR->CCPXR3)
#define CCP18_R4                        (CCP18_SFR->CCPXR4)
#define CCP18_CTL2                      (CCP18_SFR->CCPXCTL2)
#define CCP18_CTL3                      (CCP18_SFR->CCPXCTL3)
#define CCP18_EGIF                      (CCP18_SFR->CCPXEGIF)
#endif

#ifdef  KF32F_Periph_gptime19
#define T19_CNT                         (T19_SFR->CNT)
#define T19_CTL1                        (T19_SFR->CTL1)
#define T19_CTL2                        (T19_SFR->CTL2)
#define T19_PRSC                        (T19_SFR->PRSC)
#define T19_PPX                         (T19_SFR->PPX)
#define T19_UDTIM                       (T19_SFR->UDTIM)
#define CCP19_C1                        (CCP19_SFR->CCPXC1)
#define CCP19_C2                        (CCP19_SFR->CCPXC2)
#define CCP19_C3                        (CCP19_SFR->CCPXC3)
#define CCP19_C4                        (CCP19_SFR->CCPXC4)
#define CCP19_SRIC                      (CCP19_SFR->CCPXSRIC)
#define CCP19_DF                        (CCP19_SFR->CCPXDF)
#define CCP19_CTL1                      (CCP19_SFR->CCPXCTL1)
#define CCP19_R1                        (CCP19_SFR->CCPXR1)
#define CCP19_R2                        (CCP19_SFR->CCPXR2)
#define CCP19_R3                        (CCP19_SFR->CCPXR3)
#define CCP19_R4                        (CCP19_SFR->CCPXR4)
#define CCP19_CTL2                      (CCP19_SFR->CCPXCTL2)
#define CCP19_CTL3                      (CCP19_SFR->CCPXCTL3)
#define CCP19_EGIF                      (CCP19_SFR->CCPXEGIF)
#endif

#ifdef  KF32F_Periph_gptime20
#define T20_CNT                         (T20_SFR->CNT)
#define T20_CTL1                        (T20_SFR->CTL1)
#define T20_CTL2                        (T20_SFR->CTL2)
#define T20_PRSC                        (T20_SFR->PRSC)
#define T20_PPX                         (T20_SFR->PPX)
#define T20_UDTIM                       (T20_SFR->UDTIM)
#define CCP20_C1                        (CCP20_SFR->CCPXC1)
#define CCP20_C2                        (CCP20_SFR->CCPXC2)
#define CCP20_C3                        (CCP20_SFR->CCPXC3)
#define CCP20_C4                        (CCP20_SFR->CCPXC4)
#define CCP20_SRIC                      (CCP20_SFR->CCPXSRIC)
#define CCP20_DF                        (CCP20_SFR->CCPXDF)
#define CCP20_CTL1                      (CCP20_SFR->CCPXCTL1)
#define CCP20_R1                        (CCP20_SFR->CCPXR1)
#define CCP20_R2                        (CCP20_SFR->CCPXR2)
#define CCP20_R3                        (CCP20_SFR->CCPXR3)
#define CCP20_R4                        (CCP20_SFR->CCPXR4)
#define CCP20_CTL2                      (CCP20_SFR->CCPXCTL2)
#define CCP20_CTL3                      (CCP20_SFR->CCPXCTL3)
#define CCP20_EGIF                      (CCP20_SFR->CCPXEGIF)
#endif

#ifdef  KF32F_Periph_gptime21
#define T21_CNT                         (T21_SFR->CNT)
#define T21_CTL1                        (T21_SFR->CTL1)
#define T21_CTL2                        (T21_SFR->CTL2)
#define T21_PRSC                        (T21_SFR->PRSC)
#define T21_PPX                         (T21_SFR->PPX)
#define T21_UDTIM                       (T21_SFR->UDTIM)
#define CCP21_C1                        (CCP21_SFR->CCPXC1)
#define CCP21_C2                        (CCP21_SFR->CCPXC2)
#define CCP21_C3                        (CCP21_SFR->CCPXC3)
#define CCP21_C4                        (CCP21_SFR->CCPXC4)
#define CCP21_SRIC                      (CCP21_SFR->CCPXSRIC)
#define CCP21_DF                        (CCP21_SFR->CCPXDF)
#define CCP21_CTL1                      (CCP21_SFR->CCPXCTL1)
#define CCP21_R1                        (CCP21_SFR->CCPXR1)
#define CCP21_R2                        (CCP21_SFR->CCPXR2)
#define CCP21_R3                        (CCP21_SFR->CCPXR3)
#define CCP21_R4                        (CCP21_SFR->CCPXR4)
#define CCP21_CTL2                      (CCP21_SFR->CCPXCTL2)
#define CCP21_CTL3                      (CCP21_SFR->CCPXCTL3)
#define CCP21_EGIF                      (CCP21_SFR->CCPXEGIF)
#endif

#ifdef  KF32F_Periph_gptime22
#define T22_CNT                         (T22_SFR->CNT)
#define T22_CTL1                        (T22_SFR->CTL1)
#define T22_CTL2                        (T22_SFR->CTL2)
#define T22_PRSC                        (T22_SFR->PRSC)
#define T22_PPX                         (T22_SFR->PPX)
#define T22_UDTIM                       (T22_SFR->UDTIM)
#define CCP22_C1                        (CCP22_SFR->CCPXC1)
#define CCP22_C2                        (CCP22_SFR->CCPXC2)
#define CCP22_C3                        (CCP22_SFR->CCPXC3)
#define CCP22_C4                        (CCP22_SFR->CCPXC4)
#define CCP22_SRIC                      (CCP22_SFR->CCPXSRIC)
#define CCP22_DF                        (CCP22_SFR->CCPXDF)
#define CCP22_CTL1                      (CCP22_SFR->CCPXCTL1)
#define CCP22_R1                        (CCP22_SFR->CCPXR1)
#define CCP22_R2                        (CCP22_SFR->CCPXR2)
#define CCP22_R3                        (CCP22_SFR->CCPXR3)
#define CCP22_R4                        (CCP22_SFR->CCPXR4)
#define CCP22_CTL2                      (CCP22_SFR->CCPXCTL2)
#define CCP22_CTL3                      (CCP22_SFR->CCPXCTL3)
#define CCP22_EGIF                      (CCP22_SFR->CCPXEGIF)
#endif

#ifdef  KF32F_Periph_gptime23
#define T23_CNT                         (T23_SFR->CNT)
#define T23_CTL1                        (T23_SFR->CTL1)
#define T23_CTL2                        (T23_SFR->CTL2)
#define T23_PRSC                        (T23_SFR->PRSC)
#define T23_PPX                         (T23_SFR->PPX)
#define T23_UDTIM                       (T23_SFR->UDTIM)
#define CCP23_C1                        (CCP23_SFR->CCPXC1)
#define CCP23_C2                        (CCP23_SFR->CCPXC2)
#define CCP23_C3                        (CCP23_SFR->CCPXC3)
#define CCP23_C4                        (CCP23_SFR->CCPXC4)
#define CCP23_SRIC                      (CCP23_SFR->CCPXSRIC)
#define CCP23_DF                        (CCP23_SFR->CCPXDF)
#define CCP23_CTL1                      (CCP23_SFR->CCPXCTL1)
#define CCP23_R1                        (CCP23_SFR->CCPXR1)
#define CCP23_R2                        (CCP23_SFR->CCPXR2)
#define CCP23_R3                        (CCP23_SFR->CCPXR3)
#define CCP23_R4                        (CCP23_SFR->CCPXR4)
#define CCP23_CTL2                      (CCP23_SFR->CCPXCTL2)
#define CCP23_CTL3                      (CCP23_SFR->CCPXCTL3)
#define CCP23_EGIF                      (CCP23_SFR->CCPXEGIF)
#endif

/* TX_CTL1 λ�� */
#define GPTIM_CTL1_TXEN_POS             (0)
#define GPTIM_CTL1_TXCS_POS             (1)
#define GPTIM_CTL1_TXSY_POS             (3)
#define GPTIM_CTL1_TXCLK0_POS           (5)
#define GPTIM_CTL1_TXCLK1_POS           (6)
#define GPTIM_CTL1_TXDIR_POS            (7)
#define GPTIM_CTL1_TXCMS0_POS           (8)
#define GPTIM_CTL1_TXCMS1_POS           (9)
#define GPTIM_CTL1_TXCMS2_POS           (10)
#define GPTIM_CTL1_TXIE_POS             (12)
#define GPTIM_CTL1_TXIF_POS             (13)
#define GPTIM_CTL1_TXEN                 ((uint32_t)1<<(GPTIM_CTL1_TXEN_POS))
#define GPTIM_CTL1_TXCS                 ((uint32_t)1<<(GPTIM_CTL1_TXCS_POS))
#define GPTIM_CTL1_TXSY                 ((uint32_t)1<<(GPTIM_CTL1_TXSY_POS))
#define GPTIM_CTL1_TXCLK                ((uint32_t)3<<(GPTIM_CTL1_TXCLK0_POS))
#define GPTIM_CTL1_TXCLK0               ((uint32_t)1<<(GPTIM_CTL1_TXCLK0_POS))
#define GPTIM_CTL1_TXCLK1               ((uint32_t)1<<(GPTIM_CTL1_TXCLK1_POS))
#define GPTIM_CTL1_TXDIR                ((uint32_t)1<<(GPTIM_CTL1_TXDIR_POS))
#define GPTIM_CTL1_TXCMS                ((uint32_t)7<<(GPTIM_CTL1_TXCMS0_POS))
#define GPTIM_CTL1_TXCMS0               ((uint32_t)1<<(GPTIM_CTL1_TXCMS0_POS))
#define GPTIM_CTL1_TXCMS1               ((uint32_t)1<<(GPTIM_CTL1_TXCMS1_POS))
#define GPTIM_CTL1_TXCMS2               ((uint32_t)1<<(GPTIM_CTL1_TXCMS2_POS))
#define GPTIM_CTL1_TXIE                 ((uint32_t)1<<(GPTIM_CTL1_TXIE_POS))
#define GPTIM_CTL1_TXIF                 ((uint32_t)1<<(GPTIM_CTL1_TXIF_POS))

/* TX_CTL2 λ�� */
#define GPTIM_CTL2_TXUDEN_POS           (0)
#define GPTIM_CTL2_TXUDEVT_POS          (1)
#define GPTIM_CTL2_TXMMS0_POS           (2)
#define GPTIM_CTL2_TXMMS1_POS           (3)
#define GPTIM_CTL2_TXMMS2_POS           (4)
#define GPTIM_CTL2_TXSMS0_POS           (5)
#define GPTIM_CTL2_TXSMS1_POS           (6)
#define GPTIM_CTL2_TXSMS2_POS           (7)
#define GPTIM_CTL2_TXTS0_POS            (8)
#define GPTIM_CTL2_TXTS1_POS            (9)
#define GPTIM_CTL2_TXTS2_POS            (10)
#define GPTIM_CTL2_TXTS3_POS            (11)
#define GPTIM_CTL2_TXMSSYNC_POS         (12)
#define GPTIM_CTL2_TXUR_POS             (13)
#define GPTIM_CTL2_TXUDEN               ((uint32_t)1<<(GPTIM_CTL2_TXUDEN_POS))
#define GPTIM_CTL2_TXUDEVT              ((uint32_t)1<<(GPTIM_CTL2_TXUDEVT_POS))
#define GPTIM_CTL2_TXMMS                ((uint32_t)7<<(GPTIM_CTL2_TXMMS0_POS))
#define GPTIM_CTL2_TXMMS0               ((uint32_t)1<<(GPTIM_CTL2_TXMMS0_POS))
#define GPTIM_CTL2_TXMMS1               ((uint32_t)1<<(GPTIM_CTL2_TXMMS1_POS))
#define GPTIM_CTL2_TXMMS2               ((uint32_t)1<<(GPTIM_CTL2_TXMMS2_POS))
#define GPTIM_CTL2_TXSMS                ((uint32_t)7<<(GPTIM_CTL2_TXSMS0_POS))
#define GPTIM_CTL2_TXSMS0               ((uint32_t)1<<(GPTIM_CTL2_TXSMS0_POS))
#define GPTIM_CTL2_TXSMS1               ((uint32_t)1<<(GPTIM_CTL2_TXSMS1_POS))
#define GPTIM_CTL2_TXSMS2               ((uint32_t)1<<(GPTIM_CTL2_TXSMS2_POS))
#define GPTIM_CTL2_TXTS                 ((uint32_t)0xF<<(GPTIM_CTL2_TXTS0_POS))
#define GPTIM_CTL2_TXTS0                ((uint32_t)1<<(GPTIM_CTL2_TXTS0_POS))
#define GPTIM_CTL2_TXTS1                ((uint32_t)1<<(GPTIM_CTL2_TXTS1_POS))
#define GPTIM_CTL2_TXTS2                ((uint32_t)1<<(GPTIM_CTL2_TXTS2_POS))
#define GPTIM_CTL2_TXTS3                ((uint32_t)1<<(GPTIM_CTL2_TXTS3_POS))
#define GPTIM_CTL2_TXMSSYNC             ((uint32_t)1<<(GPTIM_CTL2_TXMSSYNC_POS))
#define GPTIM_CTL2_TXUR                 ((uint32_t)1<<(GPTIM_CTL2_TXUR_POS))

/* TX_UDTIMx λ�� */
#define GPTIM_UDTIM_TXUD0_POS           (0)
#define GPTIM_UDTIM_TXUD1_POS           (1)
#define GPTIM_UDTIM_TXUD2_POS           (2)
#define GPTIM_UDTIM_TXUD3_POS           (3)
#define GPTIM_UDTIM_TXUD4_POS           (4)
#define GPTIM_UDTIM_TXUD5_POS           (5)
#define GPTIM_UDTIM_TXUD6_POS           (6)
#define GPTIM_UDTIM_TXUD7_POS           (7)
#define GPTIM_UDTIM_TXUD                ((uint32_t)0xFF<<(GPTIM_UDTIM_TXUD0_POS))
#define GPTIM_UDTIM_TXUD0               ((uint32_t)1<<(GPTIM_UDTIM_TXUD0_POS))
#define GPTIM_UDTIM_TXUD1               ((uint32_t)1<<(GPTIM_UDTIM_TXUD1_POS))
#define GPTIM_UDTIM_TXUD2               ((uint32_t)1<<(GPTIM_UDTIM_TXUD2_POS))
#define GPTIM_UDTIM_TXUD3               ((uint32_t)1<<(GPTIM_UDTIM_TXUD3_POS))
#define GPTIM_UDTIM_TXUD4               ((uint32_t)1<<(GPTIM_UDTIM_TXUD4_POS))
#define GPTIM_UDTIM_TXUD5               ((uint32_t)1<<(GPTIM_UDTIM_TXUD5_POS))
#define GPTIM_UDTIM_TXUD6               ((uint32_t)1<<(GPTIM_UDTIM_TXUD6_POS))
#define GPTIM_UDTIM_TXUD7               ((uint32_t)1<<(GPTIM_UDTIM_TXUD7_POS))

/* CCPXCTL1 λ�� */
#define CCP_CTL1_CH1M0_POS              (0)
#define CCP_CTL1_CH1M1_POS              (1)
#define CCP_CTL1_CH1M2_POS              (2)
#define CCP_CTL1_CH1M3_POS              (3)
#define CCP_CTL1_CH2M0_POS              (4)
#define CCP_CTL1_CH2M1_POS              (5)
#define CCP_CTL1_CH2M2_POS              (6)
#define CCP_CTL1_CH2M3_POS              (7)
#define CCP_CTL1_CH3M0_POS              (8)
#define CCP_CTL1_CH3M1_POS              (9)
#define CCP_CTL1_CH3M2_POS              (10)
#define CCP_CTL1_CH3M3_POS              (11)
#define CCP_CTL1_CH4M0_POS              (12)
#define CCP_CTL1_CH4M1_POS              (13)
#define CCP_CTL1_CH4M2_POS              (14)
#define CCP_CTL1_CH4M3_POS              (15)
#define CCP_CTL1_CH1M                   ((uint32_t)0xF<<(CCP_CTL1_CH1M0_POS))
#define CCP_CTL1_CH1M0                  ((uint32_t)1<<(CCP_CTL1_CH1M0_POS))
#define CCP_CTL1_CH1M1                  ((uint32_t)1<<(CCP_CTL1_CH1M1_POS))
#define CCP_CTL1_CH1M2                  ((uint32_t)1<<(CCP_CTL1_CH1M2_POS))
#define CCP_CTL1_CH1M3                  ((uint32_t)1<<(CCP_CTL1_CH1M3_POS))
#define CCP_CTL1_CH2M                   ((uint32_t)0xF<<(CCP_CTL1_CH2M0_POS))
#define CCP_CTL1_CH2M0                  ((uint32_t)1<<(CCP_CTL1_CH2M0_POS))
#define CCP_CTL1_CH2M1                  ((uint32_t)1<<(CCP_CTL1_CH2M1_POS))
#define CCP_CTL1_CH2M2                  ((uint32_t)1<<(CCP_CTL1_CH2M2_POS))
#define CCP_CTL1_CH2M3                  ((uint32_t)1<<(CCP_CTL1_CH2M3_POS))
#define CCP_CTL1_CH3M                   ((uint32_t)0xF<<(CCP_CTL1_CH3M0_POS))
#define CCP_CTL1_CH3M0                  ((uint32_t)1<<(CCP_CTL1_CH3M0_POS))
#define CCP_CTL1_CH3M1                  ((uint32_t)1<<(CCP_CTL1_CH3M1_POS))
#define CCP_CTL1_CH3M2                  ((uint32_t)1<<(CCP_CTL1_CH3M2_POS))
#define CCP_CTL1_CH3M3                  ((uint32_t)1<<(CCP_CTL1_CH3M3_POS))
#define CCP_CTL1_CH4M                   ((uint32_t)0xF<<(CCP_CTL1_CH4M0_POS))
#define CCP_CTL1_CH4M0                  ((uint32_t)1<<(CCP_CTL1_CH4M0_POS))
#define CCP_CTL1_CH4M1                  ((uint32_t)1<<(CCP_CTL1_CH4M1_POS))
#define CCP_CTL1_CH4M2                  ((uint32_t)1<<(CCP_CTL1_CH4M2_POS))
#define CCP_CTL1_CH4M3                  ((uint32_t)1<<(CCP_CTL1_CH4M3_POS))

/* CCPXCTL2 λ�� */
#define CCP_CTL2_PXOC1_0_POS            (0)
#define CCP_CTL2_PXOC1_1_POS            (1)
#define CCP_CTL2_PXOC2_0_POS            (2)
#define CCP_CTL2_PXOC2_1_POS            (3)
#define CCP_CTL2_PXOC3_0_POS            (4)
#define CCP_CTL2_PXOC3_1_POS            (5)
#define CCP_CTL2_PXOC4_0_POS            (6)
#define CCP_CTL2_PXOC4_1_POS            (7)
#define CCP_CTL2_PXASS0_POS             (10)
#define CCP_CTL2_PXASS1_POS             (11)
#define CCP_CTL2_PXOC1CE_POS            (12)
#define CCP_CTL2_PXOC2CE_POS            (13)
#define CCP_CTL2_PXOC3CE_POS            (14)
#define CCP_CTL2_PXOC4CE_POS            (15)
#define CCP_CTL2_PXOC1                  ((uint32_t)3<<(CCP_CTL2_PXOC1_0_POS))
#define CCP_CTL2_PXOC1_0                ((uint32_t)1<<(CCP_CTL2_PXOC1_0_POS))
#define CCP_CTL2_PXOC1_1                ((uint32_t)1<<(CCP_CTL2_PXOC1_1_POS))
#define CCP_CTL2_PXOC2                  ((uint32_t)3<<(CCP_CTL2_PXOC2_0_POS))
#define CCP_CTL2_PXOC2_0                ((uint32_t)1<<(CCP_CTL2_PXOC2_0_POS))
#define CCP_CTL2_PXOC2_1                ((uint32_t)1<<(CCP_CTL2_PXOC2_1_POS))
#define CCP_CTL2_PXOC3                  ((uint32_t)3<<(CCP_CTL2_PXOC3_0_POS))
#define CCP_CTL2_PXOC3_0                ((uint32_t)1<<(CCP_CTL2_PXOC3_0_POS))
#define CCP_CTL2_PXOC3_1                ((uint32_t)1<<(CCP_CTL2_PXOC3_1_POS))
#define CCP_CTL2_PXOC4                  ((uint32_t)3<<(CCP_CTL2_PXOC4_0_POS))
#define CCP_CTL2_PXOC4_0                ((uint32_t)1<<(CCP_CTL2_PXOC4_0_POS))
#define CCP_CTL2_PXOC4_1                ((uint32_t)1<<(CCP_CTL2_PXOC4_1_POS))
#define CCP_CTL2_PXASS                  ((uint32_t)3<<(CCP_CTL2_PXASS0_POS))
#define CCP_CTL2_PXASS0                 ((uint32_t)1<<(CCP_CTL2_PXASS0_POS))
#define CCP_CTL2_PXASS1                 ((uint32_t)1<<(CCP_CTL2_PXASS1_POS))
#define CCP_CTL2_PXOC1CE                ((uint32_t)1<<(CCP_CTL2_PXOC1CE_POS))
#define CCP_CTL2_PXOC2CE                ((uint32_t)1<<(CCP_CTL2_PXOC2CE_POS))
#define CCP_CTL2_PXOC3CE                ((uint32_t)1<<(CCP_CTL2_PXOC3CE_POS))
#define CCP_CTL2_PXOC4CE                ((uint32_t)1<<(CCP_CTL2_PXOC4CE_POS))

/* CCPXCTL3 λ�� */
#define CCP_CTL3_CC1IE_POS              (0)
#define CCP_CTL3_CC2IE_POS              (1)
#define CCP_CTL3_CC3IE_POS              (2)
#define CCP_CTL3_CC4IE_POS              (3)
#define CCP_CTL3_TXTIE_POS              (4)
#define CCP_CTL3_TXUIE_POS              (5)
#define CCP_CTL3_TXUDE_POS              (6)
#define CCP_CTL3_CC1DE_POS              (7)
#define CCP_CTL3_CC2DE_POS              (8)
#define CCP_CTL3_CC3DE_POS              (9)
#define CCP_CTL3_CC4DE_POS              (10)
#define CCP_CTL3_TXTDE_POS              (11)
#define CCP_CTL3_PXSPM_POS              (12)
#define CCP_CTL3_PXXORM_POS             (13)
#define CCP_CTL3_PXPWMI_POS             (14)
#define CCP_CTL3_PXSPMST_POS            (15)
#define CCP_CTL3_CC1IE                  ((uint32_t)1<<(CCP_CTL3_CC1IE_POS))
#define CCP_CTL3_CC2IE                  ((uint32_t)1<<(CCP_CTL3_CC2IE_POS))
#define CCP_CTL3_CC3IE                  ((uint32_t)1<<(CCP_CTL3_CC3IE_POS))
#define CCP_CTL3_CC4IE                  ((uint32_t)1<<(CCP_CTL3_CC4IE_POS))
#define CCP_CTL3_TXTIE                  ((uint32_t)1<<(CCP_CTL3_TXTIE_POS))
#define CCP_CTL3_TXUIE                  ((uint32_t)1<<(CCP_CTL3_TXUIE_POS))
#define CCP_CTL3_TXUDE                  ((uint32_t)1<<(CCP_CTL3_TXUDE_POS))
#define CCP_CTL3_CC1DE                  ((uint32_t)1<<(CCP_CTL3_CC1DE_POS))
#define CCP_CTL3_CC2DE                  ((uint32_t)1<<(CCP_CTL3_CC2DE_POS))
#define CCP_CTL3_CC3DE                  ((uint32_t)1<<(CCP_CTL3_CC3DE_POS))
#define CCP_CTL3_CC4DE                  ((uint32_t)1<<(CCP_CTL3_CC4DE_POS))
#define CCP_CTL3_TXTDE                  ((uint32_t)1<<(CCP_CTL3_TXTDE_POS))
#define CCP_CTL3_PXSPM                  ((uint32_t)1<<(CCP_CTL3_PXSPM_POS))
#define CCP_CTL3_PXXORM                 ((uint32_t)1<<(CCP_CTL3_PXXORM_POS))
#define CCP_CTL3_PXPWMI                 ((uint32_t)1<<(CCP_CTL3_PXPWMI_POS))
#define CCP_CTL3_PXSPMST                ((uint32_t)1<<(CCP_CTL3_PXSPMST_POS))

/* CCPXEGIF λ�� */
#define CCP_EGIF_UARTRXEN_POS           (0)
#define CCP_EGIF_CC1G_POS               (1)
#define CCP_EGIF_CC2G_POS               (2)
#define CCP_EGIF_CC3G_POS               (3)
#define CCP_EGIF_CC4G_POS               (4)
#define CCP_EGIF_TXTRG_POS              (5)
#define CCP_EGIF_CC1IF_POS              (6)
#define CCP_EGIF_CC2IF_POS              (7)
#define CCP_EGIF_CC3IF_POS              (8)
#define CCP_EGIF_CC4IF_POS              (9)
#define CCP_EGIF_TXTIF_POS              (10)
#define CCP_EGIF_TXUIF_POS              (11)
#define CCP_EGIF_UARTRXEN               ((uint32_t)1<<(CCP_EGIF_UARTRXEN_POS))
#define CCP_EGIF_CC1G                   ((uint32_t)1<<(CCP_EGIF_CC1G_POS))
#define CCP_EGIF_CC2G                   ((uint32_t)1<<(CCP_EGIF_CC2G_POS))
#define CCP_EGIF_CC3G                   ((uint32_t)1<<(CCP_EGIF_CC3G_POS))
#define CCP_EGIF_CC4G                   ((uint32_t)1<<(CCP_EGIF_CC4G_POS))
#define CCP_EGIF_TXTRG                  ((uint32_t)1<<(CCP_EGIF_TXTRG_POS))
#define CCP_EGIF_CC1IF                  ((uint32_t)1<<(CCP_EGIF_CC1IF_POS))
#define CCP_EGIF_CC2IF                  ((uint32_t)1<<(CCP_EGIF_CC2IF_POS))
#define CCP_EGIF_CC3IF                  ((uint32_t)1<<(CCP_EGIF_CC3IF_POS))
#define CCP_EGIF_CC4IF                  ((uint32_t)1<<(CCP_EGIF_CC4IF_POS))
#define CCP_EGIF_TXTIF                  ((uint32_t)1<<(CCP_EGIF_TXTIF_POS))
#define CCP_EGIF_TXUIF                  ((uint32_t)1<<(CCP_EGIF_TXUIF_POS))

/* CCPXDF λ�� */
#define CCP_DF_CC1DF_POS                (0)
#define CCP_DF_CC2DF_POS                (1)
#define CCP_DF_CC3DF_POS                (2)
#define CCP_DF_CC4DF_POS                (3)
#define CCP_DF_TXTDF_POS                (4)
#define CCP_DF_TXUDF_POS                (5)
#define CCP_DF_CC1DF                    ((uint32_t)1<<(CCP_DF_CC1DF_POS))
#define CCP_DF_CC2DF                    ((uint32_t)1<<(CCP_DF_CC2DF_POS))
#define CCP_DF_CC3DF                    ((uint32_t)1<<(CCP_DF_CC3DF_POS))
#define CCP_DF_CC4DF                    ((uint32_t)1<<(CCP_DF_CC4DF_POS))
#define CCP_DF_TXTDF                    ((uint32_t)1<<(CCP_DF_TXTDF_POS))
#define CCP_DF_TXUDF                    ((uint32_t)1<<(CCP_DF_TXUDF_POS))

/* CCPXSRIC λ�� */
#define CCP_SRIC_CC1IC_POS              (0)
#define CCP_SRIC_CC2IC_POS              (1)
#define CCP_SRIC_CC3IC_POS              (2)
#define CCP_SRIC_CC4IC_POS              (3)
#define CCP_SRIC_TXTIC_POS              (4)
#define CCP_SRIC_TXUIC_POS              (5)
#define CCP_SRIC_TXIC_POS               (6)
#define CCP_SRIC_CC1IC                  ((uint32_t)1<<(CCP_SRIC_CC1IC_POS))
#define CCP_SRIC_CC2IC                  ((uint32_t)1<<(CCP_SRIC_CC2IC_POS))
#define CCP_SRIC_CC3IC                  ((uint32_t)1<<(CCP_SRIC_CC3IC_POS))
#define CCP_SRIC_CC4IC                  ((uint32_t)1<<(CCP_SRIC_CC4IC_POS))
#define CCP_SRIC_TXTIC                  ((uint32_t)1<<(CCP_SRIC_TXTIC_POS))
#define CCP_SRIC_TXUIC                  ((uint32_t)1<<(CCP_SRIC_TXUIC_POS))
#define CCP_SRIC_TXIC                   ((uint32_t)1<<(CCP_SRIC_TXIC_POS))

/* ͨ�ö�ʱ������(GPTIM)������� */


/* ----------------------------------------------------------------------------
   -- �߼���ʱ������(ATIM)
   ---------------------------------------------------------------------------- */
/* ATIM - ����Ĵ����ڴ�ṹ */
typedef struct ATIM_MemMap {
    volatile       uint32_t TXCNT;      /* Tx_CNT�Ĵ���, ƫ��:0x00 */
    volatile       uint32_t TZCNT;      /* Tz_CNT�Ĵ���, ƫ��:0x04 */
    volatile       uint32_t TXPPX;      /* Tx_PPx���ڼĴ���, ƫ��:0x08 */
    volatile       uint32_t TZPPZ;      /* Tz_PPz���ڼĴ���, ƫ��:0x0C */
    volatile       uint32_t TXPRSC;     /* TxԤ��Ƶ���üĴ���, ƫ��:0x10 */
    volatile       uint32_t TZPRSC;     /* TzԤ��Ƶ���üĴ���, ƫ��:0x14 */
    volatile       uint32_t TXCCR0;     /* Tx����ADC���üĴ���0, ƫ��:0x18 */
    volatile       uint32_t TXCCR1;     /* Tx����ADC���üĴ���1, ƫ��:0x1C */
    volatile       uint32_t TZCCR0;     /* Tz����ADC���üĴ���0, ƫ��:0x20 */
    volatile       uint32_t TXCTL;      /* Tx���ƼĴ���, ƫ��:0x24 */
    volatile       uint32_t TZCTL;      /* Tz���ƼĴ���, ƫ��:0x28 */
    volatile       uint32_t PXPDCTL;    /* λ�ü����ƼĴ���, ƫ��:0x2C */
    volatile       uint32_t PXASCTL;    /* �ضϿ��ƼĴ���, ƫ��:0x30 */
    			   uint32_t RESERVED1[19]; /* ������ַ, ƫ��:0x34 */
    volatile       uint32_t ECCPXCTL1;  /* ECCP���ƼĴ���1, ƫ��:0x80 */
    volatile       uint32_t ECCPXR1;    /* ECCP�Ƚ�/PWM�Ĵ���1, ƫ��:0x84 */
    volatile       uint32_t ECCPXR2;    /* ECCP�Ƚ�/PWM�Ĵ���2, ƫ��:0x88 */
    volatile       uint32_t ECCPXR3;    /* ECCP�Ƚ�/PWM�Ĵ���3, ƫ��:0x8C */
    volatile       uint32_t ECCPXR4;    /* ECCP�Ƚ�/PWM�Ĵ���4, ƫ��:0x90 */
    volatile       uint32_t PXUDCTL;    /* ECCP���¿��ƼĴ���, ƫ��:0x94 */
    volatile       uint32_t ECCPXCTL2;  /* ECCP���ƼĴ���2, ƫ��:0x98 */
    volatile       uint32_t PXDTCTL;    /* ECCP�������ƼĴ���, ƫ��:0x9C */
    volatile       uint32_t PWMXOC;     /* ECCP PWMx������ƼĴ���, ƫ��:0xA0 */
    volatile       uint32_t PXATRCTL;   /* ECCP PWMx������üĴ���, ƫ��:0xA4 */
    volatile       uint32_t PXASCTL0;   /* ECCP PWMx�ضϿ��ƼĴ���0, ƫ��:0xA8 */
    volatile       uint32_t PXASCTL1;   /* ECCP PWMx�ضϿ��ƼĴ���1, ƫ��:0xAC */
    volatile       uint32_t ZPDCTL0;    /* ECCP�������ƼĴ���0, ƫ��:0xB0 */
    volatile       uint32_t ZPDCTL1;    /* ECCP�������ƼĴ���1, ƫ��:0xB4 */
    volatile       uint32_t ZPDPORT;    /* ECCP�����˿ڿ��ƼĴ���, ƫ��:0xB8 */
    volatile       uint32_t ECCPXIE;    /* ECCP�ж�ʹ�ܼĴ���, ƫ��:0xBC */
    volatile       uint32_t ECCPXEGIF;  /* ECCP�ж�״̬�Ĵ���, ƫ��:0xC0 */
    volatile       uint32_t TXUDTIM;    /* Tx���¼�����, ƫ��:0xC4 */
    volatile       uint32_t TZUDTIM;    /* Tz���¼�����, ƫ��:0xC8 */
    volatile const uint32_t ECCPXDF;    /* ����DMA�жϱ�־�Ĵ���, ƫ��:0xCC */
    volatile const uint32_t ECCPXC1;    /* ��׽�Ĵ���1, ƫ��:0xD0 */
    volatile const uint32_t ECCPXC2;    /* ��׽�Ĵ���2, ƫ��:0xD4 */
    volatile const uint32_t ECCPXC3;    /* ��׽�Ĵ���3, ƫ��:0xD8 */
    volatile const uint32_t ECCPXC4;    /* ��׽�Ĵ���4, ƫ��:0xDC */
                   uint32_t RESERVED2;  /* ������ַ, ƫ��:0xE0 */
    volatile       uint32_t ECCPXDE;    /* ����DMA�ж�ʹ�ܼĴ���, ƫ��:0xE4 */
    volatile       uint32_t ECCPXSRIC;  /* ECCP�ж�����Ĵ���, ƫ��:0xE8 */
    volatile       uint32_t ECCPXCTL3;  /* ECCP���ƼĴ���3, ƫ��:0xEC */
}ATIM_SFRmap, ECCP_SFRmap; /* T5/T6 / T9/T10 */

/* ----------------------------------------------------------------------------
   -- ATIM - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* ATIM - �Ĵ�����ڵ�ַ */
#ifdef  KF32F_Periph_atime5
#define T5_ADDR                         ((uint32_t)0x40000300)
#define T5_SFR                          ((ATIM_SFRmap *) T5_ADDR)
#define ECCP5_ADDR                      T5_ADDR
#define ECCP5_SFR                       ((ECCP_SFRmap *) ECCP5_ADDR)
#endif

#ifdef  KF32F_Periph_atime6
#define T6_ADDR                         ((uint32_t)0x40000300)
#define T6_SFR                          ((ATIM_SFRmap *) T6_ADDR)
#define ECCP6_ADDR                      T6_ADDR
#define ECCP6_SFR                       ((ECCP_SFRmap *) ECCP6_ADDR)
#endif

#ifdef  KF32F_Periph_atime9
#define T9_ADDR                         ((uint32_t)0x40000400)
#define T9_SFR                          ((ATIM_SFRmap *) T9_ADDR)
#define ECCP9_ADDR                      T9_ADDR
#define ECCP9_SFR                       ((ECCP_SFRmap *) ECCP9_ADDR)
#endif

#ifdef  KF32F_Periph_atime10
#define T10_ADDR                        ((uint32_t)0x40000400)
#define T10_SFR                         ((ATIM_SFRmap *) T10_ADDR)
#define ECCP10_ADDR                     T10_ADDR
#define ECCP10_SFR                      ((ECCP_SFRmap *) ECCP10_ADDR)
#endif

/* ATIM - �Ĵ������ */
#ifdef  KF32F_Periph_atime5
#define T5_CNT                          (T5_SFR->TXCNT)
#define T5_PPX                          (T5_SFR->TXPPX)
#define T5_PRSC                         (T5_SFR->TXPRSC)
#define T5_CCR0                         (T5_SFR->TXCCR0)
#define T5_CCR1                         (T5_SFR->TXCCR1)
#define T5_CTL                          (T5_SFR->TXCTL)
#define ECCP5_PDCTL						(T5_SFR->PXPDCTL)
#define ECCP5_PXASCTL					(T5_SFR->PXASCTL)
#define ECCP5_CTL1                      (T5_SFR->ECCPXCTL1)
#define ECCP5_R1                        (T5_SFR->ECCPXR1)
#define ECCP5_R2                        (T5_SFR->ECCPXR2)
#define ECCP5_R3                        (T5_SFR->ECCPXR3)
#define ECCP5_R4                        (T5_SFR->ECCPXR4)
#define ECCP5_PXUDCTL                   (T5_SFR->PXUDCTL)
#define ECCP5_CTL2                      (T5_SFR->ECCPXCTL2)
#define ECCP5_PXDTCTL                   (T5_SFR->PXDTCTL)
#define ECCP5_PWMXOC                    (T5_SFR->PWMXOC)
#define ECCP5_PXATRCTL                  (T5_SFR->PXATRCTL)
#define ECCP5_PXASCTL0                  (T5_SFR->PXASCTL0)
#define ECCP5_PXASCTL1                  (T5_SFR->PXASCTL1)
#define ECCP5_ZPDCTL0                   (T5_SFR->ZPDCTL0)
#define ECCP5_ZPDCTL1                   (T5_SFR->ZPDCTL1)
#define ECCP5_ZPDPORT                   (T5_SFR->ZPDPORT)
#define ECCP5_IE                        (T5_SFR->ECCPXIE)
#define ECCP5_EGIF                      (T5_SFR->ECCPXEGIF)
#define T5_UDTIM                        (T5_SFR->TXUDTIM)
#define ECCP5_DF                        (T5_SFR->ECCPXDF)
#define ECCP5_C1                        (T5_SFR->ECCPXC1)
#define ECCP5_C2                        (T5_SFR->ECCPXC2)
#define ECCP5_C3                        (T5_SFR->ECCPXC3)
#define ECCP5_C4                        (T5_SFR->ECCPXC4)
#define ECCP5_DE                        (T5_SFR->ECCPXDE)
#define ECCP5_SRIC                      (T5_SFR->ECCPXSRIC)
#define ECCP5_CTL3                      (T5_SFR->ECCPXCTL3)
#endif

#ifdef  KF32F_Periph_atime6
#define T6_CNT                          (T6_SFR->TZCNT)
#define T6_PPZ                          (T6_SFR->TZPPZ)
#define T6_PRSC                         (T6_SFR->TZPRSC)
#define T6_CCR0                         (T6_SFR->TZCCR0)
#define T6_CTL                          (T6_SFR->TZCTL)
#define T6_UDTIM                        (T6_SFR->TZUDTIM)
#endif

#ifdef  KF32F_Periph_atime9
#define T9_CNT                          (T9_SFR->TXCNT)
#define T9_PPX                          (T9_SFR->TXPPX)
#define T9_PRSC                         (T9_SFR->TXPRSC)
#define T9_CCR0                         (T9_SFR->TXCCR0)
#define T9_CCR1                         (T9_SFR->TXCCR1)
#define T9_CTL                          (T9_SFR->TXCTL)
#define ECCP9_PDCTL						(T9_SFR->PXPDCTL)
#define ECCP9_PXASCTL					(T9_SFR->PXASCTL)
#define ECCP9_CTL1                      (T9_SFR->ECCPXCTL1)
#define ECCP9_R1                        (T9_SFR->ECCPXR1)
#define ECCP9_R2                        (T9_SFR->ECCPXR2)
#define ECCP9_R3                        (T9_SFR->ECCPXR3)
#define ECCP9_R4                        (T9_SFR->ECCPXR4)
#define ECCP9_PXUDCTL                   (T9_SFR->PXUDCTL)
#define ECCP9_CTL2                      (T9_SFR->ECCPXCTL2)
#define ECCP9_PXDTCTL                   (T9_SFR->PXDTCTL)
#define ECCP9_PWMXOC                    (T9_SFR->PWMXOC)
#define ECCP9_PXATRCTL                  (T9_SFR->PXATRCTL)
#define ECCP9_PXASCTL0                  (T9_SFR->PXASCTL0)
#define ECCP9_PXASCTL1                  (T9_SFR->PXASCTL1)
#define ECCP9_ZPDCTL0                   (T9_SFR->ZPDCTL0)
#define ECCP9_ZPDCTL1                   (T9_SFR->ZPDCTL1)
#define ECCP9_ZPDPORT                   (T9_SFR->ZPDPORT)
#define ECCP9_IE                        (T9_SFR->ECCPXIE)
#define ECCP9_EGIF                      (T9_SFR->ECCPXEGIF)
#define T9_UDTIM                        (T9_SFR->TXUDTIM)
#define ECCP9_DF                        (T9_SFR->ECCPXDF)
#define ECCP9_C1                        (T9_SFR->ECCPXC1)
#define ECCP9_C2                        (T9_SFR->ECCPXC2)
#define ECCP9_C3                        (T9_SFR->ECCPXC3)
#define ECCP9_C4                        (T9_SFR->ECCPXC4)
#define ECCP9_DE                        (T9_SFR->ECCPXDE)
#define ECCP9_SRIC                      (T9_SFR->ECCPXSRIC)
#define ECCP9_CTL3                      (T9_SFR->ECCPXCTL3)
#endif

#ifdef  KF32F_Periph_atime10
#define T10_CNT                         (T10_SFR->TZCNT)
#define T10_PPZ                         (T10_SFR->TZPPZ)
#define T10_PRSC                        (T10_SFR->TZPRSC)
#define T10_CCR0                        (T10_SFR->TZCCR0)
#define T10_CTL                         (T10_SFR->TZCTL)
#define T10_UDTIM                       (T10_SFR->TZUDTIM)
#endif

/* TX_CNT λ�� */
#define ATIM_TXCNT_TXCNT0_POS           (0)
#define ATIM_TXCNT_TXCNT                ((uint32_t)0xFFFF<<(ATIM_TXCNT_TXCNT0_POS))

/* TZ_CNT λ�� */
#define ATIM_TZCNT_TZCNT0_POS           (0)
#define ATIM_TZCNT_TZCNT                ((uint32_t)0xFFFF<<(ATIM_TZCNT_TZCNT0_POS))

/* TX_PPX λ�� */
#define ATIM_TXPPX_TXPPX0_POS           (0)
#define ATIM_TXPPX_TXPPX                ((uint32_t)0xFFFF<<(ATIM_TXPPX_TXPPX0_POS))

/* TZ_PPX λ�� */
#define ATIM_TZPPZ_TZPPZ0_POS           (0)
#define ATIM_TZPPZ_TZPPZ                ((uint32_t)0xFFFF<<(ATIM_TZPPZ_TZPPZ0_POS))

/* TX_CTL λ�� */
#define ATIM_TXCTL_TXCS_POS             (0)
#define ATIM_TXCTL_TXSY_POS             (1)
#define ATIM_TXCTL_TXEN_POS             (2)
#define ATIM_TXCTL_TXCKBS0_POS          (3)
#define ATIM_TXCTL_TXCKBS1_POS          (4)
#define ATIM_TXCTL_TXCKBS2_POS          (5)
#define ATIM_TXCTL_TXCKBS3_POS          (6)
#define ATIM_TXCTL_TXDIR_POS            (7)
#define ATIM_TXCTL_TXCLK0_POS           (8)
#define ATIM_TXCTL_TXCLK1_POS           (9)
#define ATIM_TXCTL_TXADAUTO_POS         (10)
#define ATIM_TXCTL_TXOFS0_POS           (11)
#define ATIM_TXCTL_TXOFS1_POS           (12)
#define ATIM_TXCTL_TXCMS0_POS           (13)
#define ATIM_TXCTL_TXCMS1_POS           (14)
#define ATIM_TXCTL_TXCMS2_POS           (15)
#define ATIM_TXCTL_TXCS                 ((uint32_t)1<<(ATIM_TXCTL_TXCS_POS))
#define ATIM_TXCTL_TXSY                 ((uint32_t)1<<(ATIM_TXCTL_TXSY_POS))
#define ATIM_TXCTL_TXEN                 ((uint32_t)1<<(ATIM_TXCTL_TXEN_POS))
#define ATIM_TXCTL_TXCKBS               ((uint32_t)0xF<<(ATIM_TXCTL_TXCKBS0_POS))
#define ATIM_TXCTL_TXCKBS0              ((uint32_t)1<<(ATIM_TXCTL_TXCKBS0_POS))
#define ATIM_TXCTL_TXCKBS1              ((uint32_t)1<<(ATIM_TXCTL_TXCKBS1_POS))
#define ATIM_TXCTL_TXCKBS2              ((uint32_t)1<<(ATIM_TXCTL_TXCKBS2_POS))
#define ATIM_TXCTL_TXCKBS3              ((uint32_t)1<<(ATIM_TXCTL_TXCKBS3_POS))
#define ATIM_TXCTL_TXDIR                ((uint32_t)1<<(ATIM_TXCTL_TXDIR_POS))
#define ATIM_TXCTL_TXCLK                ((uint32_t)3<<(ATIM_TXCTL_TXCLK0_POS))
#define ATIM_TXCTL_TXCLK0               ((uint32_t)1<<(ATIM_TXCTL_TXCLK0_POS))
#define ATIM_TXCTL_TXCLK1               ((uint32_t)1<<(ATIM_TXCTL_TXCLK1_POS))
#define ATIM_TXCTL_TXADAUTO             ((uint32_t)1<<(ATIM_TXCTL_TXADAUTO_POS))
#define ATIM_TXCTL_TXOFS                ((uint32_t)3<<(ATIM_TXCTL_TXOFS0_POS))
#define ATIM_TXCTL_TXOFS0               ((uint32_t)1<<(ATIM_TXCTL_TXOFS0_POS))
#define ATIM_TXCTL_TXOFS1               ((uint32_t)1<<(ATIM_TXCTL_TXOFS1_POS))
#define ATIM_TXCTL_TXCMS                ((uint32_t)7<<(ATIM_TXCTL_TXCMS0_POS))
#define ATIM_TXCTL_TXCMS0               ((uint32_t)1<<(ATIM_TXCTL_TXCMS0_POS))
#define ATIM_TXCTL_TXCMS1               ((uint32_t)1<<(ATIM_TXCTL_TXCMS1_POS))
#define ATIM_TXCTL_TXCMS2               ((uint32_t)1<<(ATIM_TXCTL_TXCMS2_POS))

/* TZ_CTL λ�� */
#define ATIM_TZCTL_TZCS_POS             (0)
#define ATIM_TZCTL_TZSY_POS             (1)
#define ATIM_TZCTL_TZEN_POS             (2)
#define ATIM_TZCTL_TZCKBS0_POS          (3)
#define ATIM_TZCTL_TZCKBS1_POS          (4)
#define ATIM_TZCTL_TZCKBS2_POS          (5)
#define ATIM_TZCTL_TZCKBS3_POS          (6)
#define ATIM_TZCTL_TZDIR_POS            (7)
#define ATIM_TZCTL_TZCLK0_POS           (8)
#define ATIM_TZCTL_TZCLK1_POS           (9)
#define ATIM_TZCTL_TZADAUTO_POS         (10)
#define ATIM_TZCTL_TZOFS0_POS           (11)
#define ATIM_TZCTL_TZOFS1_POS           (12)
#define ATIM_TZCTL_TZCMS0_POS           (13)
#define ATIM_TZCTL_TZCMS1_POS           (14)
#define ATIM_TZCTL_TZCMS2_POS           (15)
#define ATIM_TZCTL_TZCS                 ((uint32_t)1<<(ATIM_TZCTL_TZCS_POS))
#define ATIM_TZCTL_TZSY                 ((uint32_t)1<<(ATIM_TZCTL_TZSY_POS))
#define ATIM_TZCTL_TZEN                 ((uint32_t)1<<(ATIM_TZCTL_TZEN_POS))
#define ATIM_TZCTL_TZCKBS               ((uint32_t)0xF<<(ATIM_TZCTL_TZCKBS0_POS))
#define ATIM_TZCTL_TZCKBS0              ((uint32_t)1<<(ATIM_TZCTL_TZCKBS0_POS))
#define ATIM_TZCTL_TZCKBS1              ((uint32_t)1<<(ATIM_TZCTL_TZCKBS1_POS))
#define ATIM_TZCTL_TZCKBS2              ((uint32_t)1<<(ATIM_TZCTL_TZCKBS2_POS))
#define ATIM_TZCTL_TZCKBS3              ((uint32_t)1<<(ATIM_TZCTL_TZCKBS3_POS))
#define ATIM_TZCTL_TZDIR                ((uint32_t)1<<(ATIM_TZCTL_TZDIR_POS))
#define ATIM_TZCTL_TZCLK                ((uint32_t)3<<(ATIM_TZCTL_TZCLK0_POS))
#define ATIM_TZCTL_TZCLK0               ((uint32_t)1<<(ATIM_TZCTL_TZCLK0_POS))
#define ATIM_TZCTL_TZCLK1               ((uint32_t)1<<(ATIM_TZCTL_TZCLK1_POS))
#define ATIM_TZCTL_TZADAUTO             ((uint32_t)1<<(ATIM_TZCTL_TZADAUTO_POS))
#define ATIM_TZCTL_TZOFS                ((uint32_t)3<<(ATIM_TZCTL_TZOFS0_POS))
#define ATIM_TZCTL_TZOFS0               ((uint32_t)1<<(ATIM_TZCTL_TZOFS0_POS))
#define ATIM_TZCTL_TZOFS1               ((uint32_t)1<<(ATIM_TZCTL_TZOFS1_POS))
#define ATIM_TZCTL_TZCMS                ((uint32_t)7<<(ATIM_TZCTL_TZCMS0_POS))
#define ATIM_TZCTL_TZCMS0               ((uint32_t)1<<(ATIM_TZCTL_TZCMS0_POS))
#define ATIM_TZCTL_TZCMS1               ((uint32_t)1<<(ATIM_TZCTL_TZCMS1_POS))
#define ATIM_TZCTL_TZCMS2               ((uint32_t)1<<(ATIM_TZCTL_TZCMS2_POS))

/* TX_PRSC λ�� */
#define ATIM_TXPRSC_TXCKS0_POS          (0)
#define ATIM_TXPRSC_TXCKS               ((uint32_t)0xFFFF<<(ATIM_TXPRSC_TXCKS0_POS))

/* TZ_PRSC λ�� */
#define ATIM_TZPRSC_TZCKS0_POS          (0)
#define ATIM_TZPRSC_TZCKS               ((uint32_t)0xFFFF<<(ATIM_TZPRSC_TZCKS0_POS))

/* TX_CCR0 λ�� */
#define ATIM_TXCCR0_TXCCR0_0_POS        (0)
#define ATIM_TXCCR0_TXCCR0              ((uint32_t)0xFFFF<<(ATIM_TXCCR0_TXCCR0_0_POS))

/* TX_CCR1 λ�� */
#define ATIM_TXCCR1_TXCCR1_0_POS        (0)
#define ATIM_TXCCR1_TXCCR1              ((uint32_t)0xFFFF<<(ATIM_TXCCR1_TXCCR1_0_POS))

/* TZ_CCR0 λ�� */
#define ATIM_TZCCR0_TZCCR0_0_POS        (0)
#define ATIM_TZCCR0_TZCCR0              ((uint32_t)0xFFFF<<(ATIM_TZCCR0_TZCCR0_0_POS))

/* ECCPX_CTL1 λ�� */
#define ECCP_CTL1_CH1M0_POS             (0)
#define ECCP_CTL1_CH1M1_POS             (1)
#define ECCP_CTL1_CH1M2_POS             (2)
#define ECCP_CTL1_CH1M3_POS             (3)
#define ECCP_CTL1_CH2M0_POS             (4)
#define ECCP_CTL1_CH2M1_POS             (5)
#define ECCP_CTL1_CH2M2_POS             (6)
#define ECCP_CTL1_CH2M3_POS             (7)
#define ECCP_CTL1_CH3M0_POS             (8)
#define ECCP_CTL1_CH3M1_POS             (9)
#define ECCP_CTL1_CH3M2_POS             (10)
#define ECCP_CTL1_CH3M3_POS             (11)
#define ECCP_CTL1_CH4M0_POS             (12)
#define ECCP_CTL1_CH4M1_POS             (13)
#define ECCP_CTL1_CH4M2_POS             (14)
#define ECCP_CTL1_CH4M3_POS             (15)
#define ECCP_CTL1_CH1M                  ((uint32_t)0xF<<(ECCP_CTL1_CH1M0_POS))
#define ECCP_CTL1_CH1M0                 ((uint32_t)1<<(ECCP_CTL1_CH1M0_POS))
#define ECCP_CTL1_CH1M1                 ((uint32_t)1<<(ECCP_CTL1_CH1M1_POS))
#define ECCP_CTL1_CH1M2                 ((uint32_t)1<<(ECCP_CTL1_CH1M2_POS))
#define ECCP_CTL1_CH1M3                 ((uint32_t)1<<(ECCP_CTL1_CH1M3_POS))
#define ECCP_CTL1_CH2M                  ((uint32_t)0xF<<(ECCP_CTL1_CH2M0_POS))
#define ECCP_CTL1_CH2M0                 ((uint32_t)1<<(ECCP_CTL1_CH2M0_POS))
#define ECCP_CTL1_CH2M1                 ((uint32_t)1<<(ECCP_CTL1_CH2M1_POS))
#define ECCP_CTL1_CH2M2                 ((uint32_t)1<<(ECCP_CTL1_CH2M2_POS))
#define ECCP_CTL1_CH2M3                 ((uint32_t)1<<(ECCP_CTL1_CH2M3_POS))
#define ECCP_CTL1_CH3M                  ((uint32_t)0xF<<(ECCP_CTL1_CH3M0_POS))
#define ECCP_CTL1_CH3M0                 ((uint32_t)1<<(ECCP_CTL1_CH3M0_POS))
#define ECCP_CTL1_CH3M1                 ((uint32_t)1<<(ECCP_CTL1_CH3M1_POS))
#define ECCP_CTL1_CH3M2                 ((uint32_t)1<<(ECCP_CTL1_CH3M2_POS))
#define ECCP_CTL1_CH3M3                 ((uint32_t)1<<(ECCP_CTL1_CH3M3_POS))
#define ECCP_CTL1_CH4M                  ((uint32_t)0xF<<(ECCP_CTL1_CH4M0_POS))
#define ECCP_CTL1_CH4M0                 ((uint32_t)1<<(ECCP_CTL1_CH4M0_POS))
#define ECCP_CTL1_CH4M1                 ((uint32_t)1<<(ECCP_CTL1_CH4M1_POS))
#define ECCP_CTL1_CH4M2                 ((uint32_t)1<<(ECCP_CTL1_CH4M2_POS))
#define ECCP_CTL1_CH4M3                 ((uint32_t)1<<(ECCP_CTL1_CH4M3_POS))

/* ECCPX_Cy λ�� */
#define ECCP_C0_ECCPXC0_0_POS           (0)
#define ECCP_C0_ECCPXC0                 ((uint32_t)0xFFFF<<(ECCP_C0_ECCPXC0_0_POS))

/* ECCPX_Ry λ�� */
#define ECCP_R0_ECCPXR0_0_POS           (0)
#define ECCP_R0_ECCPXR0                 ((uint32_t)0xFFFF<<(ECCP_R0_ECCPXR0_0_POS))

/* ECCPX_IE λ�� */
#define ECCP_IE_CC1IE_POS               (0)
#define ECCP_IE_CC2IE_POS               (1)
#define ECCP_IE_CC3IE_POS               (2)
#define ECCP_IE_CC4IE_POS               (3)
#define ECCP_IE_TXTIE_POS               (4)
#define ECCP_IE_TZIE_POS                (5)
#define ECCP_IE_TXIE_POS                (6)
#define ECCP_IE_TZUIE_POS               (7)
#define ECCP_IE_TXUIE_POS               (8)
#define ECCP_IE_CPIE_POS                (9)
#define ECCP_IE_PDIE_POS                (10)
#define ECCP_IE_CC1IE                   ((uint32_t)1<<(ECCP_IE_CC1IE_POS))
#define ECCP_IE_CC2IE                   ((uint32_t)1<<(ECCP_IE_CC2IE_POS))
#define ECCP_IE_CC3IE                   ((uint32_t)1<<(ECCP_IE_CC3IE_POS))
#define ECCP_IE_CC4IE                   ((uint32_t)1<<(ECCP_IE_CC4IE_POS))
#define ECCP_IE_TXTIE                   ((uint32_t)1<<(ECCP_IE_TXTIE_POS))
#define ECCP_IE_TZIE                    ((uint32_t)1<<(ECCP_IE_TZIE_POS))
#define ECCP_IE_TXIE                    ((uint32_t)1<<(ECCP_IE_TXIE_POS))
#define ECCP_IE_TZUIE                   ((uint32_t)1<<(ECCP_IE_TZUIE_POS))
#define ECCP_IE_TXUIE                   ((uint32_t)1<<(ECCP_IE_TXUIE_POS))
#define ECCP_IE_CPIE                    ((uint32_t)1<<(ECCP_IE_CPIE_POS))
#define ECCP_IE_PDIE                    ((uint32_t)1<<(ECCP_IE_PDIE_POS))
/* ECCPX_DE λ�� */
#define ECCP_DE_CH1DE_POS               (0)
#define ECCP_DE_CH2DE_POS               (1)
#define ECCP_DE_CH3DE_POS               (2)
#define ECCP_DE_CH4DE_POS               (3)
#define ECCP_DE_CLSDE_POS               (4)
#define ECCP_DE_TXTDE_POS               (5)
#define ECCP_DE_TZUDE_POS               (6)
#define ECCP_DE_TXUDE_POS               (7)
#define ECCP_DE_CH1DE                   ((uint32_t)1<<(ECCP_DE_CH1DE_POS))
#define ECCP_DE_CH2DE                   ((uint32_t)1<<(ECCP_DE_CH2DE_POS))
#define ECCP_DE_CH3DE                   ((uint32_t)1<<(ECCP_DE_CH3DE_POS))
#define ECCP_DE_CH4DE                   ((uint32_t)1<<(ECCP_DE_CH4DE_POS))
#define ECCP_DE_CLSDE                   ((uint32_t)1<<(ECCP_DE_CLSDE_POS))
#define ECCP_DE_TXTDE                   ((uint32_t)1<<(ECCP_DE_TXTDE_POS))
#define ECCP_DE_TZDE                    ((uint32_t)1<<(ECCP_DE_TZUDE_POS))
#define ECCP_DE_TXDE                    ((uint32_t)1<<(ECCP_DE_TXUDE_POS))

/* ECCPX_EGIF λ�� */
#define ECCP_EGIF_CPIF_POS              (0)
#define ECCP_EGIF_CC1G_POS              (1)
#define ECCP_EGIF_CC2G_POS              (2)
#define ECCP_EGIF_CC3G_POS              (3)
#define ECCP_EGIF_CC4G_POS              (4)
#define ECCP_EGIF_TXTRG_POS             (5)
#define ECCP_EGIF_CC1IF_POS             (6)
#define ECCP_EGIF_CC2IF_POS             (7)
#define ECCP_EGIF_CC3IF_POS             (8)
#define ECCP_EGIF_CC4IF_POS             (9)
#define ECCP_EGIF_TXTIF_POS             (10)
#define ECCP_EGIF_TZIF_POS              (11)
#define ECCP_EGIF_TXIF_POS              (12)
#define ECCP_EGIF_TZUIF_POS             (13)
#define ECCP_EGIF_TXUIF_POS             (14)
#define ECCP_EGIF_PDIF_POS              (15)
#define ECCP_EGIF_CPIF                  ((uint32_t)1<<(ECCP_EGIF_CPIF_POS))
#define ECCP_EGIF_CC1G                  ((uint32_t)1<<(ECCP_EGIF_CC1G_POS))
#define ECCP_EGIF_CC2G                  ((uint32_t)1<<(ECCP_EGIF_CC2G_POS))
#define ECCP_EGIF_CC3G                  ((uint32_t)1<<(ECCP_EGIF_CC3G_POS))
#define ECCP_EGIF_CC4G                  ((uint32_t)1<<(ECCP_EGIF_CC4G_POS))
#define ECCP_EGIF_TXTRG                 ((uint32_t)1<<(ECCP_EGIF_TXTRG_POS))
#define ECCP_EGIF_CC1IF                 ((uint32_t)1<<(ECCP_EGIF_CC1IF_POS))
#define ECCP_EGIF_CC2IF                 ((uint32_t)1<<(ECCP_EGIF_CC2IF_POS))
#define ECCP_EGIF_CC3IF                 ((uint32_t)1<<(ECCP_EGIF_CC3IF_POS))
#define ECCP_EGIF_CC4IF                 ((uint32_t)1<<(ECCP_EGIF_CC4IF_POS))
#define ECCP_EGIF_TXTIF                 ((uint32_t)1<<(ECCP_EGIF_TXTIF_POS))
#define ECCP_EGIF_TZIF                  ((uint32_t)1<<(ECCP_EGIF_TZIF_POS))
#define ECCP_EGIF_TXIF                  ((uint32_t)1<<(ECCP_EGIF_TXIF_POS))
#define ECCP_EGIF_TZUIF                 ((uint32_t)1<<(ECCP_EGIF_TZUIF_POS))
#define ECCP_EGIF_TXUIF                 ((uint32_t)1<<(ECCP_EGIF_TXUIF_POS))
#define ECCP_EGIF_PDIF                  ((uint32_t)1<<(ECCP_EGIF_PDIF_POS))

/* ECCPX_DF λ�� */
#define ECCP_DF_CH1DF_POS               (0)
#define ECCP_DF_CH2DF_POS               (1)
#define ECCP_DF_CH3DF_POS               (2)
#define ECCP_DF_CH4DF_POS               (3)
#define ECCP_DF_CLSDF_POS               (4)
#define ECCP_DF_TRIGDF_POS              (5)
#define ECCP_DF_TZUDF_POS               (6)
#define ECCP_DF_TXUDF_POS               (7)
#define ECCP_DF_CH1DF                   ((uint32_t)1<<(ECCP_DF_CH1DF_POS))
#define ECCP_DF_CH2DF                   ((uint32_t)1<<(ECCP_DF_CH2DF_POS))
#define ECCP_DF_CH3DF                   ((uint32_t)1<<(ECCP_DF_CH3DF_POS))
#define ECCP_DF_CH4DF                   ((uint32_t)1<<(ECCP_DF_CH4DF_POS))
#define ECCP_DF_CLSDF                   ((uint32_t)1<<(ECCP_DF_CLSDF_POS))
#define ECCP_DF_TRIGDF                  ((uint32_t)1<<(ECCP_DF_TRIGDF_POS))
#define ECCP_DF_TZUDF                   ((uint32_t)1<<(ECCP_DF_TZUDF_POS))
#define ECCP_DF_TXUDF                   ((uint32_t)1<<(ECCP_DF_TXUDF_POS))

/* ECCPX_SRIC λ�� */
#define ECCP_SRIC_CC1IC_POS             (0)
#define ECCP_SRIC_CC2IC_POS             (1)
#define ECCP_SRIC_CC3IC_POS             (2)
#define ECCP_SRIC_CC4IC_POS             (3)
#define ECCP_SRIC_TXTIC_POS             (4)
#define ECCP_SRIC_TZIC_POS              (5)
#define ECCP_SRIC_TXIC_POS              (6)
#define ECCP_SRIC_TZUIC_POS             (7)
#define ECCP_SRIC_TXUIC_POS             (8)
#define ECCP_SRIC_CPIC_POS              (9)
#define ECCP_SRIC_PDIC_POS              (10)
#define ECCP_SRIC_CC1IC                 ((uint32_t)1<<(ECCP_SRIC_CC1IC_POS))
#define ECCP_SRIC_CC2IC                 ((uint32_t)1<<(ECCP_SRIC_CC2IC_POS))
#define ECCP_SRIC_CC3IC                 ((uint32_t)1<<(ECCP_SRIC_CC3IC_POS))
#define ECCP_SRIC_CC4IC                 ((uint32_t)1<<(ECCP_SRIC_CC4IC_POS))
#define ECCP_SRIC_TXTIC                 ((uint32_t)1<<(ECCP_SRIC_TXTIC_POS))
#define ECCP_SRIC_TZIC                  ((uint32_t)1<<(ECCP_SRIC_TZIC_POS))
#define ECCP_SRIC_TXIC                  ((uint32_t)1<<(ECCP_SRIC_TXIC_POS))
#define ECCP_SRIC_TZUIC                 ((uint32_t)1<<(ECCP_SRIC_TZUIC_POS))
#define ECCP_SRIC_TXUIC                 ((uint32_t)1<<(ECCP_SRIC_TXUIC_POS))
#define ECCP_SRIC_CPIC                  ((uint32_t)1<<(ECCP_SRIC_CPIC_POS))
#define ECCP_SRIC_PDIC                  ((uint32_t)1<<(ECCP_SRIC_PDIC_POS))

/* ECCPX_PXUDCTL λ�� */
#define ECCP_PXUDCTL_PXUDEN0_POS        (0)
#define ECCP_PXUDCTL_PXUDEN1_POS        (1)
#define ECCP_PXUDCTL_PXUDEVT0_POS       (2)
#define ECCP_PXUDCTL_PXUDEVT1_POS       (3)
#define ECCP_PXUDCTL_PXUDEVT2_POS       (4)
#define ECCP_PXUDCTL_PXUDEVT3_POS       (5)
#define ECCP_PXUDCTL_PXMPEN_POS         (6)
#define ECCP_PXUDCTL_PXUDEN             ((uint32_t)3<<(ECCP_PXUDCTL_PXUDEN0_POS))
#define ECCP_PXUDCTL_PXUDEN0            ((uint32_t)1<<(ECCP_PXUDCTL_PXUDEN0_POS))
#define ECCP_PXUDCTL_PXUDEN1            ((uint32_t)1<<(ECCP_PXUDCTL_PXUDEN1_POS))
#define ECCP_PXUDCTL_PXUDEVT            ((uint32_t)0xF<<(ECCP_PXUDCTL_PXUDEVT0_POS))
#define ECCP_PXUDCTL_PXUDEVT0           ((uint32_t)1<<(ECCP_PXUDCTL_PXUDEVT0_POS))
#define ECCP_PXUDCTL_PXUDEVT1           ((uint32_t)1<<(ECCP_PXUDCTL_PXUDEVT1_POS))
#define ECCP_PXUDCTL_PXUDEVT2           ((uint32_t)1<<(ECCP_PXUDCTL_PXUDEVT2_POS))
#define ECCP_PXUDCTL_PXUDEVT3           ((uint32_t)1<<(ECCP_PXUDCTL_PXUDEVT3_POS))
#define ECCP_PXUDCTL_PXMPEN             ((uint32_t)1<<(ECCP_PXUDCTL_PXMPEN_POS))

/* TX_UDTIMX λ�� */
#define ATIM_UDTIMX_UDCNT0_POS          (0)
#define ATIM_UDTIMX_UDCNT               ((uint32_t)0xFFFF<<(ATIM_UDTIMX_UDCNT0_POS))

/* TZ_UDTIMZ λ�� */
#define ATIM_UDTIMZ_UDCNT0_POS          (0)
#define ATIM_UDTIMZ_UDCNT               ((uint32_t)0xFFFF<<(ATIM_UDTIMZ_UDCNT0_POS))

/* ECCPX_CTL2 λ�� */
#define ECCP_CTL2_TXMMS0_POS            (0)
#define ECCP_CTL2_TXMMS1_POS            (1)
#define ECCP_CTL2_TXMMS2_POS            (2)
#define ECCP_CTL2_TXSMS0_POS            (3)
#define ECCP_CTL2_TXSMS1_POS            (4)
#define ECCP_CTL2_TXSMS2_POS            (5)
#define ECCP_CTL2_TXTS0_POS             (6)
#define ECCP_CTL2_TXTS1_POS             (7)
#define ECCP_CTL2_TXTS2_POS             (8)
#define ECCP_CTL2_TXMSSYNC_POS          (9)
#define ECCP_CTL2_PXSPM_POS             (10)
#define ECCP_CTL2_PXXORM_POS            (11)
#define ECCP_CTL2_PXPWMI_POS            (12)
#define ECCP_CTL2_TZSMS0_POS            (13)
#define ECCP_CTL2_TZSMS1_POS            (14)
#define ECCP_CTL2_TZSMS2_POS            (15)
#define ECCP_CTL2_TXMMS                 ((uint32_t)7<<(ECCP_CTL2_TXMMS0_POS))
#define ECCP_CTL2_TXMMS0                ((uint32_t)1<<(ECCP_CTL2_TXMMS0_POS))
#define ECCP_CTL2_TXMMS1                ((uint32_t)1<<(ECCP_CTL2_TXMMS1_POS))
#define ECCP_CTL2_TXMMS2                ((uint32_t)1<<(ECCP_CTL2_TXMMS2_POS))
#define ECCP_CTL2_TXSMS                 ((uint32_t)7<<(ECCP_CTL2_TXSMS0_POS))
#define ECCP_CTL2_TXSMS0                ((uint32_t)1<<(ECCP_CTL2_TXSMS0_POS))
#define ECCP_CTL2_TXSMS1                ((uint32_t)1<<(ECCP_CTL2_TXSMS1_POS))
#define ECCP_CTL2_TXSMS2                ((uint32_t)1<<(ECCP_CTL2_TXSMS2_POS))
#define ECCP_CTL2_TXTS                  ((uint32_t)7<<(ECCP_CTL2_TXTS0_POS))
#define ECCP_CTL2_TXTS0                 ((uint32_t)1<<(ECCP_CTL2_TXTS0_POS))
#define ECCP_CTL2_TXTS1                 ((uint32_t)1<<(ECCP_CTL2_TXTS1_POS))
#define ECCP_CTL2_TXTS2                 ((uint32_t)1<<(ECCP_CTL2_TXTS2_POS))
#define ECCP_CTL2_TXMSSYNC              ((uint32_t)1<<(ECCP_CTL2_TXMSSYNC_POS))
#define ECCP_CTL2_PXSPM                 ((uint32_t)1<<(ECCP_CTL2_PXSPM_POS))
#define ECCP_CTL2_PXXORM                ((uint32_t)1<<(ECCP_CTL2_PXXORM_POS))
#define ECCP_CTL2_PXPWMI                ((uint32_t)1<<(ECCP_CTL2_PXPWMI_POS))
#define ECCP_CTL2_TZSMS                 ((uint32_t)7<<(ECCP_CTL2_TZSMS0_POS))
#define ECCP_CTL2_TZSMS0                ((uint32_t)1<<(ECCP_CTL2_TZSMS0_POS))
#define ECCP_CTL2_TZSMS1                ((uint32_t)1<<(ECCP_CTL2_TZSMS1_POS))
#define ECCP_CTL2_TZSMS2                ((uint32_t)1<<(ECCP_CTL2_TZSMS2_POS))

/* ECCPX_CTL3 λ�� */
#define ECCP_CTL3_PXSPMST_POS           (0)
#define ECCP_CTL3_TUNITE_POS            (1)
#define ECCP_CTL3_PXRSEN_POS            (2)
#define ECCP_CTL3_PXSPMST               ((uint32_t)1<<(ECCP_CTL3_PXSPMST_POS))
#define ECCP_CTL3_TUNITE                ((uint32_t)1<<(ECCP_CTL3_TUNITE_POS))
#define ECCP_CTL3_PXRSEN                ((uint32_t)1<<(ECCP_CTL3_PXRSEN_POS))

/* ECCPX_PXDTCTL λ�� */
#define ECCP_PXDTCTL_PXDC0_POS          (0)
#define ECCP_PXDTCTL_PZDC0_POS          (8)
#define ECCP_PXDTCTL_PXDC               ((uint32_t)0xFF<<(ECCP_PXDTCTL_PXDC0_POS))
#define ECCP_PXDTCTL_PZDC               ((uint32_t)0xFF<<(ECCP_PXDTCTL_PZDC0_POS))

/* ECCPX_PWMXOC λ�� */
#define ECCP_PWMXOC_PXOC1L0_POS         (0)
#define ECCP_PWMXOC_PXOC1L1_POS         (1)
#define ECCP_PWMXOC_PXOC1H0_POS         (2)
#define ECCP_PWMXOC_PXOC1H1_POS         (3)
#define ECCP_PWMXOC_PXOC2L0_POS         (4)
#define ECCP_PWMXOC_PXOC2L1_POS         (5)
#define ECCP_PWMXOC_PXOC2H0_POS         (6)
#define ECCP_PWMXOC_PXOC2H1_POS         (7)
#define ECCP_PWMXOC_PXOC3L0_POS         (8)
#define ECCP_PWMXOC_PXOC3L1_POS         (9)
#define ECCP_PWMXOC_PXOC3H0_POS         (10)
#define ECCP_PWMXOC_PXOC3H1_POS         (11)
#define ECCP_PWMXOC_PXOC4L0_POS         (12)
#define ECCP_PWMXOC_PXOC4L1_POS         (13)
#define ECCP_PWMXOC_PXOC4H0_POS         (14)
#define ECCP_PWMXOC_PXOC4H1_POS         (15)
#define ECCP_PWMXOC_PXOC1L              ((uint32_t)3<<(ECCP_PWMXOC_PXOC1L0_POS))
#define ECCP_PWMXOC_PXOC1L0             ((uint32_t)1<<(ECCP_PWMXOC_PXOC1L0_POS))
#define ECCP_PWMXOC_PXOC1L1             ((uint32_t)1<<(ECCP_PWMXOC_PXOC1L1_POS))
#define ECCP_PWMXOC_PXOC1H              ((uint32_t)3<<(ECCP_PWMXOC_PXOC1H0_POS))
#define ECCP_PWMXOC_PXOC1H0             ((uint32_t)1<<(ECCP_PWMXOC_PXOC1H0_POS))
#define ECCP_PWMXOC_PXOC1H1             ((uint32_t)1<<(ECCP_PWMXOC_PXOC1H1_POS))
#define ECCP_PWMXOC_PXOC2L              ((uint32_t)3<<(ECCP_PWMXOC_PXOC2L0_POS))
#define ECCP_PWMXOC_PXOC2L0             ((uint32_t)1<<(ECCP_PWMXOC_PXOC2L0_POS))
#define ECCP_PWMXOC_PXOC2L1             ((uint32_t)1<<(ECCP_PWMXOC_PXOC2L1_POS))
#define ECCP_PWMXOC_PXOC2H              ((uint32_t)3<<(ECCP_PWMXOC_PXOC2H0_POS))
#define ECCP_PWMXOC_PXOC2H0             ((uint32_t)1<<(ECCP_PWMXOC_PXOC2H0_POS))
#define ECCP_PWMXOC_PXOC2H1             ((uint32_t)1<<(ECCP_PWMXOC_PXOC2H1_POS))
#define ECCP_PWMXOC_PXOC3L              ((uint32_t)3<<(ECCP_PWMXOC_PXOC3L0_POS))
#define ECCP_PWMXOC_PXOC3L0             ((uint32_t)1<<(ECCP_PWMXOC_PXOC3L0_POS))
#define ECCP_PWMXOC_PXOC3L1             ((uint32_t)1<<(ECCP_PWMXOC_PXOC3L1_POS))
#define ECCP_PWMXOC_PXOC3H              ((uint32_t)3<<(ECCP_PWMXOC_PXOC3H0_POS))
#define ECCP_PWMXOC_PXOC3H0             ((uint32_t)1<<(ECCP_PWMXOC_PXOC3H0_POS))
#define ECCP_PWMXOC_PXOC3H1             ((uint32_t)1<<(ECCP_PWMXOC_PXOC3H1_POS))
#define ECCP_PWMXOC_PXOC4L              ((uint32_t)3<<(ECCP_PWMXOC_PXOC4L0_POS))
#define ECCP_PWMXOC_PXOC4L0             ((uint32_t)1<<(ECCP_PWMXOC_PXOC4L0_POS))
#define ECCP_PWMXOC_PXOC4L1             ((uint32_t)1<<(ECCP_PWMXOC_PXOC4L1_POS))
#define ECCP_PWMXOC_PXOC4H              ((uint32_t)3<<(ECCP_PWMXOC_PXOC4H0_POS))
#define ECCP_PWMXOC_PXOC4H0             ((uint32_t)1<<(ECCP_PWMXOC_PXOC4H0_POS))
#define ECCP_PWMXOC_PXOC4H1             ((uint32_t)1<<(ECCP_PWMXOC_PXOC4H1_POS))

/* ECCPX_PXATRCTL λ�� */
#define ECCP_PXATRCTL_PXCH1MOD_POS      (8)
#define ECCP_PXATRCTL_PXCH2MOD_POS      (9)
#define ECCP_PXATRCTL_PXCH3MOD_POS      (10)
#define ECCP_PXATRCTL_PXCH4MOD_POS      (11)
#define ECCP_PXATRCTL_PXCH1MOD          ((uint32_t)1<<(ECCP_PXATRCTL_PXCH1MOD_POS))
#define ECCP_PXATRCTL_PXCH2MOD          ((uint32_t)1<<(ECCP_PXATRCTL_PXCH2MOD_POS))
#define ECCP_PXATRCTL_PXCH3MOD          ((uint32_t)1<<(ECCP_PXATRCTL_PXCH3MOD_POS))
#define ECCP_PXATRCTL_PXCH4MOD          ((uint32_t)1<<(ECCP_PXATRCTL_PXCH4MOD_POS))

/* ECCPX_PXASCTL λ�� */
#define ECCP_PXASCTL_PXASS_POS          (0)
#define ECCP_PXASCTL_PXASS              ((uint32_t)1<<(ECCP_PXASCTL_PXASS_POS))



/* ECCPX_PXASCTL0 λ�� */
#define ECCP_PXASCTL0_PXASS1_0_POS      (0)
#define ECCP_PXASCTL0_PXASS1_1_POS      (1)
#define ECCP_PXASCTL0_PXASS2_0_POS      (2)
#define ECCP_PXASCTL0_PXASS2_1_POS      (3)
#define ECCP_PXASCTL0_PXASS3_0_POS      (4)
#define ECCP_PXASCTL0_PXASS3_1_POS      (5)
#define ECCP_PXASCTL0_PXASS4_0_POS      (6)
#define ECCP_PXASCTL0_PXASS4_1_POS      (7)
#define ECCP_PXASCTL0_PXASE1_POS        (8)
#define ECCP_PXASCTL0_PXASE2_POS        (9)
#define ECCP_PXASCTL0_PXASE3_POS        (10)
#define ECCP_PXASCTL0_PXASE4_POS        (11)
#define ECCP_PXASCTL0_PXASS1            ((uint32_t)3<<(ECCP_PXASCTL0_PXASS1_0_POS))
#define ECCP_PXASCTL0_PXASS1_0          ((uint32_t)1<<(ECCP_PXASCTL0_PXASS1_0_POS))
#define ECCP_PXASCTL0_PXASS1_1          ((uint32_t)1<<(ECCP_PXASCTL0_PXASS1_1_POS))
#define ECCP_PXASCTL0_PXASS2            ((uint32_t)3<<(ECCP_PXASCTL0_PXASS2_0_POS))
#define ECCP_PXASCTL0_PXASS2_0          ((uint32_t)1<<(ECCP_PXASCTL0_PXASS2_0_POS))
#define ECCP_PXASCTL0_PXASS2_1          ((uint32_t)1<<(ECCP_PXASCTL0_PXASS2_1_POS))
#define ECCP_PXASCTL0_PXASS3            ((uint32_t)3<<(ECCP_PXASCTL0_PXASS3_0_POS))
#define ECCP_PXASCTL0_PXASS3_0          ((uint32_t)1<<(ECCP_PXASCTL0_PXASS3_0_POS))
#define ECCP_PXASCTL0_PXASS3_1          ((uint32_t)1<<(ECCP_PXASCTL0_PXASS3_1_POS))
#define ECCP_PXASCTL0_PXASS4            ((uint32_t)3<<(ECCP_PXASCTL0_PXASS4_0_POS))
#define ECCP_PXASCTL0_PXASS4_0          ((uint32_t)1<<(ECCP_PXASCTL0_PXASS4_0_POS))
#define ECCP_PXASCTL0_PXASS4_1          ((uint32_t)1<<(ECCP_PXASCTL0_PXASS4_1_POS))
#define ECCP_PXASCTL0_PXASE1            ((uint32_t)1<<(ECCP_PXASCTL0_PXASE1_POS))
#define ECCP_PXASCTL0_PXASE2            ((uint32_t)1<<(ECCP_PXASCTL0_PXASE2_POS))
#define ECCP_PXASCTL0_PXASE3            ((uint32_t)1<<(ECCP_PXASCTL0_PXASE3_POS))
#define ECCP_PXASCTL0_PXASE4            ((uint32_t)1<<(ECCP_PXASCTL0_PXASE4_POS))

/* ECCPX_PXASCTL1 λ�� */
#define ECCP_PXASCTL1_PXSS1L0_POS       (0)
#define ECCP_PXASCTL1_PXSS1L1_POS       (1)
#define ECCP_PXASCTL1_PXSS1H0_POS       (2)
#define ECCP_PXASCTL1_PXSS1H1_POS       (3)
#define ECCP_PXASCTL1_PXSS2L0_POS       (4)
#define ECCP_PXASCTL1_PXSS2L1_POS       (5)
#define ECCP_PXASCTL1_PXSS2H0_POS       (6)
#define ECCP_PXASCTL1_PXSS2H1_POS       (7)
#define ECCP_PXASCTL1_PXSS3L0_POS       (8)
#define ECCP_PXASCTL1_PXSS3L1_POS       (9)
#define ECCP_PXASCTL1_PXSS3H0_POS       (10)
#define ECCP_PXASCTL1_PXSS3H1_POS       (11)
#define ECCP_PXASCTL1_PXSS4L0_POS       (12)
#define ECCP_PXASCTL1_PXSS4L1_POS       (13)
#define ECCP_PXASCTL1_PXSS4H0_POS       (14)
#define ECCP_PXASCTL1_PXSS4H1_POS       (15)
#define ECCP_PXASCTL1_PXSS1L            ((uint32_t)3<<(ECCP_PXASCTL1_PXSS1L0_POS))
#define ECCP_PXASCTL1_PXSS1L0           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS1L0_POS))
#define ECCP_PXASCTL1_PXSS1L1           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS1L1_POS))
#define ECCP_PXASCTL1_PXSS1H            ((uint32_t)3<<(ECCP_PXASCTL1_PXSS1H0_POS))
#define ECCP_PXASCTL1_PXSS1H0           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS1H0_POS))
#define ECCP_PXASCTL1_PXSS1H1           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS1H1_POS))
#define ECCP_PXASCTL1_PXSS2L            ((uint32_t)3<<(ECCP_PXASCTL1_PXSS2L0_POS))
#define ECCP_PXASCTL1_PXSS2L0           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS2L0_POS))
#define ECCP_PXASCTL1_PXSS2L1           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS2L1_POS))
#define ECCP_PXASCTL1_PXSS2H            ((uint32_t)3<<(ECCP_PXASCTL1_PXSS2H0_POS))
#define ECCP_PXASCTL1_PXSS2H0           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS2H0_POS))
#define ECCP_PXASCTL1_PXSS2H1           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS2H1_POS))
#define ECCP_PXASCTL1_PXSS3L            ((uint32_t)3<<(ECCP_PXASCTL1_PXSS3L0_POS))
#define ECCP_PXASCTL1_PXSS3L0           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS3L0_POS))
#define ECCP_PXASCTL1_PXSS3L1           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS3L1_POS))
#define ECCP_PXASCTL1_PXSS3H            ((uint32_t)3<<(ECCP_PXASCTL1_PXSS3H0_POS))
#define ECCP_PXASCTL1_PXSS3H0           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS3H0_POS))
#define ECCP_PXASCTL1_PXSS3H1           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS3H1_POS))
#define ECCP_PXASCTL1_PXSS4L            ((uint32_t)3<<(ECCP_PXASCTL1_PXSS4L0_POS))
#define ECCP_PXASCTL1_PXSS4L0           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS4L0_POS))
#define ECCP_PXASCTL1_PXSS4L1           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS4L1_POS))
#define ECCP_PXASCTL1_PXSS4H            ((uint32_t)3<<(ECCP_PXASCTL1_PXSS4H0_POS))
#define ECCP_PXASCTL1_PXSS4H0           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS4H0_POS))
#define ECCP_PXASCTL1_PXSS4H1           ((uint32_t)1<<(ECCP_PXASCTL1_PXSS4H1_POS))

/* ECCPX_ZPDCTL0 λ�� */
#define ECCP_ZPDCTL0_ZPD1FLAG_POS       (0)
#define ECCP_ZPDCTL0_ZPD2FLAG_POS       (1)
#define ECCP_ZPDCTL0_ZPD3FLAG_POS       (2)
#define ECCP_ZPDCTL0_ZPD4FLAG_POS       (3)
#define ECCP_ZPDCTL0_ZPD1TWIN_POS       (4)
#define ECCP_ZPDCTL0_ZPD2TWIN_POS       (5)
#define ECCP_ZPDCTL0_ZPD3TWIN_POS       (6)
#define ECCP_ZPDCTL0_ZPD4TWIN_POS       (7)
#define ECCP_ZPDCTL0_ZCLK0_POS          (8)
#define ECCP_ZPDCTL0_ZCLK1_POS          (9)
#define ECCP_ZPDCTL0_ZCLK2_POS          (10)
#define ECCP_ZPDCTL0_ZCLK3_POS          (11)
#define ECCP_ZPDCTL0_ZPD1FLAG           ((uint32_t)1<<(ECCP_ZPDCTL0_ZPD1FLAG_POS))
#define ECCP_ZPDCTL0_ZPD2FLAG           ((uint32_t)1<<(ECCP_ZPDCTL0_ZPD2FLAG_POS))
#define ECCP_ZPDCTL0_ZPD3FLAG           ((uint32_t)1<<(ECCP_ZPDCTL0_ZPD3FLAG_POS))
#define ECCP_ZPDCTL0_ZPD4FLAG           ((uint32_t)1<<(ECCP_ZPDCTL0_ZPD4FLAG_POS))
#define ECCP_ZPDCTL0_ZPD1TWIN           ((uint32_t)1<<(ECCP_ZPDCTL0_ZPD1TWIN_POS))
#define ECCP_ZPDCTL0_ZPD2TWIN           ((uint32_t)1<<(ECCP_ZPDCTL0_ZPD2TWIN_POS))
#define ECCP_ZPDCTL0_ZPD3TWIN           ((uint32_t)1<<(ECCP_ZPDCTL0_ZPD3TWIN_POS))
#define ECCP_ZPDCTL0_ZPD4TWIN           ((uint32_t)1<<(ECCP_ZPDCTL0_ZPD4TWIN_POS))
#define ECCP_ZPDCTL0_ZCLK               ((uint32_t)0xF<<(ECCP_ZPDCTL0_ZCLK0_POS))
#define ECCP_ZPDCTL0_ZCLK0              ((uint32_t)1<<(ECCP_ZPDCTL0_ZCLK0_POS))
#define ECCP_ZPDCTL0_ZCLK1              ((uint32_t)1<<(ECCP_ZPDCTL0_ZCLK1_POS))
#define ECCP_ZPDCTL0_ZCLK2              ((uint32_t)1<<(ECCP_ZPDCTL0_ZCLK2_POS))
#define ECCP_ZPDCTL0_ZCLK3              ((uint32_t)1<<(ECCP_ZPDCTL0_ZCLK3_POS))

/* ECCPX_ZPDCTL1 λ�� */
#define ECCP_ZPDCTL1_ZPD1S0_POS         (0)
#define ECCP_ZPDCTL1_ZPD1S1_POS         (1)
#define ECCP_ZPDCTL1_ZPD1S2_POS         (2)
#define ECCP_ZPDCTL1_ZPD2S0_POS         (3)
#define ECCP_ZPDCTL1_ZPD2S1_POS         (4)
#define ECCP_ZPDCTL1_ZPD2S2_POS         (5)
#define ECCP_ZPDCTL1_ZPD3S0_POS         (6)
#define ECCP_ZPDCTL1_ZPD3S1_POS         (7)
#define ECCP_ZPDCTL1_ZPD3S2_POS         (8)
#define ECCP_ZPDCTL1_ZPD4S0_POS         (9)
#define ECCP_ZPDCTL1_ZPD4S1_POS         (10)
#define ECCP_ZPDCTL1_ZPD4S2_POS         (11)
#define ECCP_ZPDCTL1_ZPD1EN_POS         (12)
#define ECCP_ZPDCTL1_ZPD2EN_POS         (13)
#define ECCP_ZPDCTL1_ZPD3EN_POS         (14)
#define ECCP_ZPDCTL1_ZPD4EN_POS         (15)
#define ECCP_ZPDCTL1_ZPD1S              ((uint32_t)7<<(ECCP_ZPDCTL1_ZPD1S0_POS))
#define ECCP_ZPDCTL1_ZPD1S0             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD1S0_POS))
#define ECCP_ZPDCTL1_ZPD1S1             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD1S1_POS))
#define ECCP_ZPDCTL1_ZPD1S2             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD1S2_POS))
#define ECCP_ZPDCTL1_ZPD2S              ((uint32_t)7<<(ECCP_ZPDCTL1_ZPD2S0_POS))
#define ECCP_ZPDCTL1_ZPD2S0             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD2S0_POS))
#define ECCP_ZPDCTL1_ZPD2S1             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD2S1_POS))
#define ECCP_ZPDCTL1_ZPD2S2             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD2S2_POS))
#define ECCP_ZPDCTL1_ZPD3S              ((uint32_t)7<<(ECCP_ZPDCTL1_ZPD3S0_POS))
#define ECCP_ZPDCTL1_ZPD3S0             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD3S0_POS))
#define ECCP_ZPDCTL1_ZPD3S1             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD3S1_POS))
#define ECCP_ZPDCTL1_ZPD3S2             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD3S2_POS))
#define ECCP_ZPDCTL1_ZPD4S              ((uint32_t)7<<(ECCP_ZPDCTL1_ZPD4S0_POS))
#define ECCP_ZPDCTL1_ZPD4S0             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD4S0_POS))
#define ECCP_ZPDCTL1_ZPD4S1             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD4S1_POS))
#define ECCP_ZPDCTL1_ZPD4S2             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD4S2_POS))
#define ECCP_ZPDCTL1_ZPD1EN             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD1EN_POS))
#define ECCP_ZPDCTL1_ZPD2EN             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD2EN_POS))
#define ECCP_ZPDCTL1_ZPD3EN             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD3EN_POS))
#define ECCP_ZPDCTL1_ZPD4EN             ((uint32_t)1<<(ECCP_ZPDCTL1_ZPD4EN_POS))

/* ECCPX_ZPDPORT λ�� */
#define ECCP_ZPDPORT_ZPORT0_POS         (0)
#define ECCP_ZPDPORT_ZPORT              ((uint32_t)0xFF<<(ECCP_ZPDPORT_ZPORT0_POS))
/* �߼���ʱ������(ATIM)������� */


/* ----------------------------------------------------------------------------
   -- �������������· (QEI)
   ---------------------------------------------------------------------------- */

/* QEI - ����Ĵ����ڴ�ṹ */
typedef struct QEI_MemMap {
    volatile uint32_t CTL0;             /* QEI���ƼĴ���, ƫ��:0x0 */
    volatile uint32_t CTL1;             /* QEI�����˲����ƼĴ���, ƫ��:0x4 */
    volatile uint32_t CNT;              /* QEI Tx�Ĵ���, ƫ��:0x8 */
    volatile uint32_t PPX;              /* QEI Tx���ڼĴ���, ƫ��:0xC */
    volatile uint32_t PRSC;             /* QEI TxԤ��Ƶ��, ƫ��:0x10 */
    volatile uint32_t DIER;             /* QEI�жϿ��ƼĴ���, ƫ��:0x14 */
}QEI_SFRmap;

/* ----------------------------------------------------------------------------
   -- QEI - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* QEI - �Ĵ�����ڵ�ַ */
#ifdef  KF32F_Periph_qei
#ifdef  KF32F_Periph_qei0
#define QEI0_ADDR                       ((uint32_t)0x40000500)
#define QEI0_SFR                        ((QEI_SFRmap *) QEI0_ADDR)
#define T7_ADDR                         ((uint32_t)0x40000500)
#define T7_SFR                          QEI0_SFR
#endif
#ifdef  KF32F_Periph_qei1
#define QEI1_ADDR                       ((uint32_t)0x40000080)
#define QEI1_SFR                        ((QEI_SFRmap *) QEI1_ADDR)
#define T8_ADDR                         ((uint32_t)0x40000080)
#define T8_SFR                          QEI1_SFR
#endif
/* QEI - �Ĵ������ */
#define QEI0_CTL0                       (QEI0_SFR->CTL0)
#define QEI0_CTL1                       (QEI0_SFR->CTL1)
#define T7_CNT                          (QEI0_SFR->CNT)
#define T7_PPX                          (QEI0_SFR->PPX)
#define T7_PRSC                         (QEI0_SFR->PRSC)
#define QEI0_DIER                       (QEI0_SFR->DIER)
#define QEI1_CTL0                       (QEI1_SFR->CTL0)
#define QEI1_CTL1                       (QEI1_SFR->CTL1)
#define T8_CNT                          (QEI1_SFR->CNT)
#define T8_PPX                          (QEI1_SFR->PPX)
#define T8_PRSC                         (QEI1_SFR->PRSC)
#define QEI1_DIER                       (QEI1_SFR->DIER)

/* QEIy_CTL0 λ�� */
#define QEI_CTL0_TXDIR_POS              (0)
#define QEI_CTL0_TXDIROUT_POS           (1)
#define QEI_CTL0_INDEX_POS              (2)
#define QEI_CTL0_TXCS_POS               (3)
#define QEI_CTL0_INDRES_POS             (4)
#define QEI_CTL0_QEIMOD0_POS            (5)
#define QEI_CTL0_QEIMOD1_POS            (6)
#define QEI_CTL0_QEIMOD2_POS            (7)
#define QEI_CTL0_CNTERRIF_POS           (8)
#define QEI_CTL0_PHEIF_POS              (9)
#define QEI_CTL0_TXIF_POS               (10)
#define QEI_CTL0_TXDIR                  ((uint32_t)1<<(QEI_CTL0_TXDIR_POS))
#define QEI_CTL0_TXDIROUT               ((uint32_t)1<<(QEI_CTL0_TXDIROUT_POS))
#define QEI_CTL0_INDEX                  ((uint32_t)1<<(QEI_CTL0_INDEX_POS))
#define QEI_CTL0_TXCS                   ((uint32_t)1<<(QEI_CTL0_TXCS_POS))
#define QEI_CTL0_INDRES                 ((uint32_t)1<<(QEI_CTL0_INDRES_POS))
#define QEI_CTL0_QEIMOD                 ((uint32_t)7<<(QEI_CTL0_QEIMOD0_POS))
#define QEI_CTL0_QEIMOD0                ((uint32_t)1<<(QEI_CTL0_QEIMOD0_POS))
#define QEI_CTL0_QEIMOD1                ((uint32_t)1<<(QEI_CTL0_QEIMOD1_POS))
#define QEI_CTL0_QEIMOD2                ((uint32_t)1<<(QEI_CTL0_QEIMOD2_POS))
#define QEI_CTL0_CNTERRIF               ((uint32_t)1<<(QEI_CTL0_CNTERRIF_POS))
#define QEI_CTL0_PHEIF                  ((uint32_t)1<<(QEI_CTL0_PHEIF_POS))
#define QEI_CTL0_TXIF                   ((uint32_t)1<<(QEI_CTL0_TXIF_POS))

/* QEIy_CTL1 λ�� */
#define QEI_CTL1_SWPAB_POS              (0)
#define QEI_CTL1_QEICK0_POS             (1)
#define QEI_CTL1_QEICK1_POS             (2)
#define QEI_CTL1_QEICK2_POS             (3)
#define QEI_CTL1_QEIOUT_POS             (4)
#define QEI_CTL1_QEICLK0_POS            (5)
#define QEI_CTL1_QEICLK1_POS            (6)
#define QEI_CTL1_SWPAB                  ((uint32_t)1<<(QEI_CTL1_SWPAB_POS))
#define QEI_CTL1_QEICK                  ((uint32_t)7<<(QEI_CTL1_QEICK0_POS))
#define QEI_CTL1_QEICK0                 ((uint32_t)1<<(QEI_CTL1_QEICK0_POS))
#define QEI_CTL1_QEICK1                 ((uint32_t)1<<(QEI_CTL1_QEICK1_POS))
#define QEI_CTL1_QEICK2                 ((uint32_t)1<<(QEI_CTL1_QEICK2_POS))
#define QEI_CTL1_QEIOUT                 ((uint32_t)1<<(QEI_CTL1_QEIOUT_POS))
#define QEI_CTL1_QEICLK                 ((uint32_t)3<<(QEI_CTL1_QEICLK0_POS))
#define QEI_CTL1_QEICLK0                ((uint32_t)1<<(QEI_CTL1_QEICLK0_POS))
#define QEI_CTL1_QEICLK1                ((uint32_t)1<<(QEI_CTL1_QEICLK1_POS))

/* Tx_CNT λ�� */
#define QEI_TXCNT_TXCNT0_POS            (0)
#define QEI_TXCNT_TXCNT                 ((uint32_t)0xFFFF<<(QEI_TXCNT_TXCNT0_POS))

/* Tx_PPX λ�� */
#define QEI_PPX_PPX0_POS                (0)
#define QEI_PPX_PPX                     ((uint32_t)0xFFFF<<(QEI_PPX_PPX0_POS))

/* Tx_PRSC λ�� */
#define QEI_TXPRSC_TXPRSC0_POS          (0)
#define QEI_TXPRSC_TXPRSC               ((uint32_t)0xFFFF<<(QEI_TXPRSC_TXPRSC0_POS))

/* QEIy_DIER λ�� */
#define QEI_DIER_CNTERRIE_POS           (0)
#define QEI_DIER_PHEIE_POS              (1)
#define QEI_DIER_TXIE_POS               (2)
#define QEI_DIER_CNTERRIC_POS           (3)
#define QEI_DIER_PHEIC_POS              (4)
#define QEI_DIER_TXIC_POS               (5)
#define QEI_DIER_CNTERRIE               ((uint32_t)0xFFFF<<(QEI_DIER_CNTERRIE_POS))
#define QEI_DIER_PHEIE                  ((uint32_t)0xFFFF<<(QEI_DIER_PHEIE_POS))
#define QEI_DIER_TXIE                   ((uint32_t)0xFFFF<<(QEI_DIER_TXIE_POS))
#define QEI_DIER_CNTERRIC               ((uint32_t)0xFFFF<<(QEI_DIER_CNTERRIC_POS))
#define QEI_DIER_PHEIC                  ((uint32_t)0xFFFF<<(QEI_DIER_PHEIC_POS))
#define QEI_DIER_TXIC                   ((uint32_t)0xFFFF<<(QEI_DIER_TXIC_POS))

#endif //KF32F_Periph_qei
/* �������������·(QEI)���� */


/* ----------------------------------------------------------------------------
   -- ��ģת��ģ�� (DAC)
   ---------------------------------------------------------------------------- */

/* DAC - ����Ĵ����ڴ�ṹ */
typedef struct DAC_MemMap {
    volatile       uint32_t CTL;        /* DAC���ƼĴ���, ƫ��:0x0 */
    volatile       uint32_t DAHD;       /* DAC���ݱ��ּĴ���, ƫ��:0x4 */
    volatile const uint32_t DATA;       /* DAC������ݼĴ���, ƫ��:0x8 */
    volatile       uint32_t CTL1;       /* DAC���ƼĴ���1, ƫ��:0xC */
                   uint32_t RESERVED;   /* ������ַ, ƫ��:0x10 */
    volatile       uint32_t CAL;        /* DACУ��Ĵ���, ƫ��:0x14 */
}DAC_SFRmap;

/* ----------------------------------------------------------------------------
   -- DAC - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* DAC - �Ĵ�����ڵ�ַ */
#ifdef  KF32F_Periph_dac0
#define DAC0_ADDR                       ((uint32_t)0x40000700)
#define DAC0_SFR                        ((DAC_SFRmap *) DAC0_ADDR)
#endif
#ifdef  KF32F_Periph_dac1
#define DAC1_ADDR                       ((uint32_t)0x40000780)
#define DAC1_SFR                        ((DAC_SFRmap *) DAC1_ADDR)
#endif
/* DAC - �Ĵ������ */
#define DAC0_CTL                        (DAC0_SFR->CTL)
#define DAC0_DAHD                       (DAC0_SFR->DAHD)
#define DAC0_DATA                       (DAC0_SFR->DATA)
#define DAC0_CTL1                       (DAC0_SFR->CTL1)
#define DAC0_CAL                        (DAC0_SFR->CAL)
#define DAC1_CTL                        (DAC1_SFR->CTL)
#define DAC1_DAHD                       (DAC1_SFR->DAHD)
#define DAC1_DATA                       (DAC1_SFR->DATA)
#define DAC1_CTL1                       (DAC1_SFR->CTL1)
#define DAC1_CAL                        (DAC1_SFR->CAL)

/* DACx_CTL λ�� */
#define DAC_CTL_EN_POS                  (0)
#define DAC_CTL_DE_POS                  (1)
#define DAC_CTL_TRIGEN_POS              (3)
#define DAC_CTL_TREVT0_POS              (4)
#define DAC_CTL_TREVT1_POS              (5)
#define DAC_CTL_TREVT2_POS              (6)
#define DAC_CTL_TREVT3_POS              (7)
#define DAC_CTL_WAVE0_POS               (8)
#define DAC_CTL_WAVE1_POS               (9)
#define DAC_CTL_MAS0_POS                (10)
#define DAC_CTL_MAS1_POS                (11)
#define DAC_CTL_MAS2_POS                (12)
#define DAC_CTL_MAS3_POS                (13)
#define DAC_CTL_SWTRIG_POS              (14)
#define DAC_CTL_DF_POS                  (15)
#define DAC_CTL_EN                      ((uint32_t)1<<(DAC_CTL_EN_POS))
#define DAC_CTL_DE                      ((uint32_t)1<<(DAC_CTL_DE_POS))
#define DAC_CTL_TRIGEN                  ((uint32_t)1<<(DAC_CTL_TRIGEN_POS))
#define DAC_CTL_TREVT                   ((uint32_t)0xF<<(DAC_CTL_TREVT0_POS))
#define DAC_CTL_TREVT0                  ((uint32_t)1<<(DAC_CTL_TREVT0_POS))
#define DAC_CTL_TREVT1                  ((uint32_t)1<<(DAC_CTL_TREVT1_POS))
#define DAC_CTL_TREVT2                  ((uint32_t)1<<(DAC_CTL_TREVT2_POS))
#define DAC_CTL_TREVT3                  ((uint32_t)1<<(DAC_CTL_TREVT3_POS))
#define DAC_CTL_WAVE                    ((uint32_t)3<<(DAC_CTL_WAVE0_POS))
#define DAC_CTL_WAVE0                   ((uint32_t)1<<(DAC_CTL_WAVE0_POS))
#define DAC_CTL_WAVE1                   ((uint32_t)1<<(DAC_CTL_WAVE1_POS))
#define DAC_CTL_MAS                     ((uint32_t)0xF<<(DAC_CTL_MAS0_POS))
#define DAC_CTL_MAS0                    ((uint32_t)1<<(DAC_CTL_MAS0_POS))
#define DAC_CTL_MAS1                    ((uint32_t)1<<(DAC_CTL_MAS1_POS))
#define DAC_CTL_MAS2                    ((uint32_t)1<<(DAC_CTL_MAS2_POS))
#define DAC_CTL_MAS3                    ((uint32_t)1<<(DAC_CTL_MAS3_POS))
#define DAC_CTL_SWTRIG                  ((uint32_t)1<<(DAC_CTL_SWTRIG_POS))
#define DAC_CTL_DF                      ((uint32_t)1<<(DAC_CTL_DF_POS))

/* DACx_DAHD λ�� */
#define DAC_DAHD_DAHD0_POS              (0)
#define DAC_DAHD_DAHD                   ((uint32_t)0xFFF<<(DAC_DAHD_DAHD0_POS))

/* DACx_DATA λ�� */
#define DAC_DATA_DATA0_POS              (0)
#define DAC_DATA_DATA                   ((uint32_t)0xFFF<<(DAC_DATA_DATA0_POS))

/* DACx_CTL1 λ�� */
#define DAC_CTL1_SEL_POS                (0)
#define DAC_CTL1_RFS0_POS               (1)
#define DAC_CTL1_RFS1_POS               (2)
#define DAC_CTL1_CLK0_POS               (4)
#define DAC_CTL1_CLK1_POS               (5)
#define DAC_CTL1_BUFEN_POS              (6)
#define DAC_CTL1_SEL                    ((uint32_t)1<<(DAC_CTL1_SEL_POS))
#define DAC_CTL1_RFS                    ((uint32_t)1<<(DAC_CTL1_RFS0_POS))
#define DAC_CTL1_RFS0                   ((uint32_t)1<<(DAC_CTL1_RFS0_POS))
#define DAC_CTL1_RFS1                   ((uint32_t)1<<(DAC_CTL1_RFS1_POS))
#define DAC_CTL1_CLK                    ((uint32_t)1<<(DAC_CTL1_CLK0_POS))
#define DAC_CTL1_CLK0                   ((uint32_t)1<<(DAC_CTL1_CLK0_POS))
#define DAC_CTL1_CLK1                   ((uint32_t)1<<(DAC_CTL1_CLK1_POS))
#define DAC_CTL1_BUFEN                  ((uint32_t)1<<(DAC_CTL1_BUFEN_POS))

/* DACx_CAL λ�� */
#define DAC_CAL_TPEN_POS                (0)
#define DAC_CAL_TP0_POS                 (1)
#define DAC_CAL_TP1_POS                 (2)
#define DAC_CAL_BUFTRIM_POS             (15)
#define DAC_CAL_NNEGATRIM0_POS          (16)
#define DAC_CAL_NNEGATRIM1_POS          (17)
#define DAC_CAL_NNEGATRIM2_POS          (18)
#define DAC_CAL_NNEGATRIM3_POS          (19)
#define DAC_CAL_NPOSITRIM0_POS          (20)
#define DAC_CAL_NPOSITRIM1_POS          (21)
#define DAC_CAL_NPOSITRIM2_POS          (22)
#define DAC_CAL_NPOSITRIM3_POS          (23)
#define DAC_CAL_PNEGATRIM0_POS          (24)
#define DAC_CAL_PNEGATRIM1_POS          (25)
#define DAC_CAL_PNEGATRIM2_POS          (26)
#define DAC_CAL_PNEGATRIM3_POS          (27)
#define DAC_CAL_PPOSITRIM0_POS          (28)
#define DAC_CAL_PPOSITRIM1_POS          (29)
#define DAC_CAL_PPOSITRIM2_POS          (30)
#define DAC_CAL_PPOSITRIM3_POS          (31)
#define DAC_CAL_TPEN                    ((uint32_t)1<<(DAC_CAL_TPEN_POS))
#define DAC_CAL_BUFTRIM                 ((uint32_t)1<<(DAC_CAL_BUFTRIM_POS))
#define DAC_CAL_TP                      ((uint32_t)0x3<<(DAC_CAL_TP0_POS))
#define DAC_CAL_TP0                     ((uint32_t)1<<(DAC_CAL_TP0_POS))
#define DAC_CAL_TP1                     ((uint32_t)1<<(DAC_CAL_TP1_POS))
#define DAC_CAL_NNEGATRIM               ((uint32_t)0xF<<(DAC_CAL_NNEGATRIM0_POS))
#define DAC_CAL_NNEGATRIM0              ((uint32_t)1<<(DAC_CAL_NNEGATRIM0_POS))
#define DAC_CAL_NNEGATRIM1              ((uint32_t)1<<(DAC_CAL_NNEGATRIM1_POS))
#define DAC_CAL_NNEGATRIM2              ((uint32_t)1<<(DAC_CAL_NNEGATRIM2_POS))
#define DAC_CAL_NNEGATRIM3              ((uint32_t)1<<(DAC_CAL_NNEGATRIM3_POS))
#define DAC_CAL_NPOSITRIM               ((uint32_t)0xF<<(DAC_CAL_NPOSITRIM0_POS))
#define DAC_CAL_NPOSITRIM0              ((uint32_t)1<<(DAC_CAL_NPOSITRIM0_POS))
#define DAC_CAL_NPOSITRIM1              ((uint32_t)1<<(DAC_CAL_NPOSITRIM1_POS))
#define DAC_CAL_NPOSITRIM2              ((uint32_t)1<<(DAC_CAL_NPOSITRIM2_POS))
#define DAC_CAL_NPOSITRIM3              ((uint32_t)1<<(DAC_CAL_NPOSITRIM3_POS))
#define DAC_CAL_PNEGATRIM               ((uint32_t)0xF<<(DAC_CAL_PNEGATRIM0_POS))
#define DAC_CAL_PNEGATRIM0              ((uint32_t)1<<(DAC_CAL_PNEGATRIM0_POS))
#define DAC_CAL_PNEGATRIM1              ((uint32_t)1<<(DAC_CAL_PNEGATRIM1_POS))
#define DAC_CAL_PNEGATRIM2              ((uint32_t)1<<(DAC_CAL_PNEGATRIM2_POS))
#define DAC_CAL_PNEGATRIM3              ((uint32_t)1<<(DAC_CAL_PNEGATRIM3_POS))
#define DAC_CAL_PPOSITRIM               ((uint32_t)0xF<<(DAC_CAL_PPOSITRIM0_POS))
#define DAC_CAL_PPOSITRIM0              ((uint32_t)1<<(DAC_CAL_PPOSITRIM0_POS))
#define DAC_CAL_PPOSITRIM1              ((uint32_t)1<<(DAC_CAL_PPOSITRIM1_POS))
#define DAC_CAL_PPOSITRIM2              ((uint32_t)1<<(DAC_CAL_PPOSITRIM2_POS))
#define DAC_CAL_PPOSITRIM3              ((uint32_t)1<<(DAC_CAL_PPOSITRIM3_POS))
/* ��ģת��ģ�� (DAC)������� */


/* ----------------------------------------------------------------------------
   -- �Ƚ���ģ�� (CMP)
   ---------------------------------------------------------------------------- */
#ifdef KF32F_Periph_cmp
/* CMP - ����Ĵ����ڴ�ṹ */
typedef struct CMP_MemMap {
    volatile       uint32_t CTL;        /* CMP���ƼĴ���0, ƫ��:0x0 */
//    volatile       uint32_t CTL1;       /* CMP���ƼĴ���1, ƫ��:0x4 */
//    volatile 	   uint32_t CTL2;       /* CMP���ƼĴ���2, ƫ��:0x8 */
//    volatile       uint32_t CTL3;       /* CMP���ƼĴ���3, ƫ��:0xC */
//    volatile       uint32_t CTL4;   	/*CMP���ƼĴ���4, ƫ��:0x10 */

}CMP_SFRmap;
/* ----------------------------------------------------------------------------
   -- CMP - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* CMP - �Ĵ�����ڵ�ַ */
#define CMP_ADDR                        ((uint32_t)0x40000800)
#define CMP0_ADDR                       ((uint32_t)0x40000800)
#define CMP1_ADDR                       ((uint32_t)0x40000804)
#define CMP2_ADDR                       ((uint32_t)0x40000808)
#define CMP3_ADDR                       ((uint32_t)0x4000080C)
#define CMP1234_ADDR                    ((uint32_t)0x40000810)

#define CMP_SFR                         ((CMP_SFRmap *) CMP_ADDR)
#define CMP0_SFR                        ((CMP_SFRmap *) CMP0_ADDR)
#define CMP1_SFR                        ((CMP_SFRmap *) CMP1_ADDR)
#define CMP2_SFR                        ((CMP_SFRmap *) CMP2_ADDR)
#define CMP3_SFR                        ((CMP_SFRmap *) CMP3_ADDR)
#define CMPCTL4_SFR                     ((CMP_SFRmap *) CMP1234_ADDR)
/* CMP - �Ĵ������ */
#define CMP_CTL0                        (CMP0_SFR->CTL)
#define CMP_CTL1                        (CMP1_SFR->CTL)
#define CMP_CTL2                        (CMP2_SFR->CTL)
#define CMP_CTL3                        (CMP3_SFR->CTL)
#define CMP_CTL4                        (CMPCTL4_SFR->CTL)

/* CMP_CTL0 λ�� */
#define CMP_CTL0_POL_POS                (1)
#define CMP_CTL0_WINEN_POS              (2)
#define CMP_CTL0_FLTEN_POS              (3)
#define CMP_CTL0_FLTCNT0_POS            (4)
#define CMP_CTL0_FLTCNT1_POS            (5)
#define CMP_CTL0_FLTCNT2_POS            (6)
#define CMP_CTL0_FDIV0_POS              (8)
#define CMP_CTL0_FDIV1_POS              (9)
#define CMP_CTL0_FDIV2_POS              (10)
#define CMP_CTL0_FDIV3_POS              (11)
#define CMP_CTL0_FDIV4_POS              (12)
#define CMP_CTL0_FDIV5_POS              (13)
#define CMP_CTL0_FDIV6_POS              (14)
#define CMP_CTL0_FDIV7_POS              (15)
#define CMP_CTL0_FLTCS0_POS             (16)
#define CMP_CTL0_FLTCS1_POS             (17)
#define CMP_CTL0_IFREN_POS              (18)
#define CMP_CTL0_IFFEN_POS              (19)
#define CMP_CTL0_HYS0_POS               (20)
#define CMP_CTL0_HYS1_POS               (21)
#define CMP_CTL0_HYS2_POS               (22)
#define CMP_CTL0_NMOD0_POS              (24)
#define CMP_CTL0_NMOD1_POS              (25)
#define CMP_CTL0_NMOD2_POS              (26)
#define CMP_CTL0_PMOD0_POS              (28)
#define CMP_CTL0_PMOD1_POS              (29)
#define CMP_CTL0_PMOD2_POS              (30)
#define CMP_CTL0_POL                    ((uint32_t)1<<(CMP_CTL0_POL_POS))
#define CMP_CTL0_WINEN                  ((uint32_t)1<<(CMP_CTL0_WINEN_POS))
#define CMP_CTL0_FLTEN                  ((uint32_t)1<<(CMP_CTL0_FLTEN_POS))
#define CMP_CTL0_FLTCNT                 ((uint32_t)0x7<<(CMP_CTL0_FLTCNT0_POS))
#define CMP_CTL0_FLTCNT0                ((uint32_t)1<<(CMP_CTL0_FLTCNT0_POS))
#define CMP_CTL0_FLTCNT1                ((uint32_t)1<<(CMP_CTL0_FLTCNT1_POS))
#define CMP_CTL0_FLTCNT2                ((uint32_t)1<<(CMP_CTL0_FLTCNT2_POS))
#define CMP_CTL0_FDIV                   ((uint32_t)0xFF<<(CMP_CTL0_FDIV0_POS))
#define CMP_CTL0_FDIV0                  ((uint32_t)1<<(CMP_CTL0_FDIV0_POS))
#define CMP_CTL0_FDIV1                  ((uint32_t)1<<(CMP_CTL0_FDIV1_POS))
#define CMP_CTL0_FDIV2                  ((uint32_t)1<<(CMP_CTL0_FDIV2_POS))
#define CMP_CTL0_FDIV3                  ((uint32_t)1<<(CMP_CTL0_FDIV3_POS))
#define CMP_CTL0_FDIV4                  ((uint32_t)1<<(CMP_CTL0_FDIV4_POS))
#define CMP_CTL0_FDIV5                  ((uint32_t)1<<(CMP_CTL0_FDIV5_POS))
#define CMP_CTL0_FDIV6                  ((uint32_t)1<<(CMP_CTL0_FDIV6_POS))
#define CMP_CTL0_FDIV7                  ((uint32_t)1<<(CMP_CTL0_FDIV7_POS))
#define CMP_CTL0_FLTCS                  ((uint32_t)0x3<<(CMP_CTL0_FLTCS0_POS))
#define CMP_CTL0_FLTCS0                 ((uint32_t)1<<(CMP_CTL0_FLTCS0_POS))
#define CMP_CTL0_FLTCS1                 ((uint32_t)1<<(CMP_CTL0_FLTCS1_POS))
#define CMP_CTL0_IFREN                  ((uint32_t)1<<(CMP_CTL0_IFREN_POS))
#define CMP_CTL0_IFFEN                  ((uint32_t)1<<(CMP_CTL0_IFFEN_POS))
#define CMP_CTL0_HYS                    ((uint32_t)0x7<<(CMP_CTL0_HYS0_POS))
#define CMP_CTL0_HYS0                   ((uint32_t)1<<(CMP_CTL0_HYS0_POS))
#define CMP_CTL0_HYS1                   ((uint32_t)1<<(CMP_CTL0_HYS1_POS))
#define CMP_CTL0_HYS2                   ((uint32_t)1<<(CMP_CTL0_HYS2_POS))
#define CMP_CTL0_NMOD                   ((uint32_t)0x7<<(CMP_CTL0_NMOD0_POS))
#define CMP_CTL0_NMOD0                  ((uint32_t)1<<(CMP_CTL0_NMOD0_POS))
#define CMP_CTL0_NMOD1                  ((uint32_t)1<<(CMP_CTL0_NMOD1_POS))
#define CMP_CTL0_NMOD2                  ((uint32_t)1<<(CMP_CTL0_NMOD2_POS))
#define CMP_CTL0_PMOD                   ((uint32_t)0x7<<(CMP_CTL0_PMOD0_POS))
#define CMP_CTL0_PMOD0                  ((uint32_t)1<<(CMP_CTL0_PMOD0_POS))
#define CMP_CTL0_PMOD1                  ((uint32_t)1<<(CMP_CTL0_PMOD1_POS))
#define CMP_CTL0_PMOD2                  ((uint32_t)1<<(CMP_CTL0_PMOD2_POS))
/* CMP_CTL1 λ�� */
#define CMP_CTL1_POL_POS                (1)
#define CMP_CTL1_WINEN_POS              (2)
#define CMP_CTL1_FLTEN_POS              (3)
#define CMP_CTL1_FLTCNT0_POS            (4)
#define CMP_CTL1_FLTCNT1_POS            (5)
#define CMP_CTL1_FLTCNT2_POS            (6)
#define CMP_CTL1_FDIV0_POS              (8)
#define CMP_CTL1_FDIV1_POS              (9)
#define CMP_CTL1_FDIV2_POS              (10)
#define CMP_CTL1_FDIV3_POS              (11)
#define CMP_CTL1_FDIV4_POS              (12)
#define CMP_CTL1_FDIV5_POS              (13)
#define CMP_CTL1_FDIV6_POS              (14)
#define CMP_CTL1_FDIV7_POS              (15)
#define CMP_CTL1_FLTCS0_POS             (16)
#define CMP_CTL1_FLTCS1_POS             (17)
#define CMP_CTL1_IFREN_POS              (18)
#define CMP_CTL1_IFFEN_POS              (19)
#define CMP_CTL1_HYS0_POS               (20)
#define CMP_CTL1_HYS1_POS               (21)
#define CMP_CTL1_HYS2_POS               (22)
#define CMP_CTL1_NMOD0_POS              (24)
#define CMP_CTL1_NMOD1_POS              (25)
#define CMP_CTL1_NMOD2_POS              (26)
#define CMP_CTL1_PMOD0_POS              (28)
#define CMP_CTL1_PMOD1_POS              (29)
#define CMP_CTL1_PMOD2_POS              (30)
#define CMP_CTL1_POL                    ((uint32_t)1<<(CMP_CTL1_POL_POS))
#define CMP_CTL1_WINEN                  ((uint32_t)1<<(CMP_CTL1_WINEN_POS))
#define CMP_CTL1_FLTEN                  ((uint32_t)1<<(CMP_CTL1_FLTEN_POS))
#define CMP_CTL1_FLTCNT                 ((uint32_t)0x7<<(CMP_CTL1_FLTCNT0_POS))
#define CMP_CTL1_FLTCNT0                ((uint32_t)1<<(CMP_CTL1_FLTCNT0_POS))
#define CMP_CTL1_FLTCNT1                ((uint32_t)1<<(CMP_CTL1_FLTCNT1_POS))
#define CMP_CTL1_FLTCNT2                ((uint32_t)1<<(CMP_CTL1_FLTCNT2_POS))
#define CMP_CTL1_FDIV                   ((uint32_t)0xFF<<(CMP_CTL1_FDIV0_POS))
#define CMP_CTL1_FDIV0                  ((uint32_t)1<<(CMP_CTL1_FDIV0_POS))
#define CMP_CTL1_FDIV1                  ((uint32_t)1<<(CMP_CTL1_FDIV1_POS))
#define CMP_CTL1_FDIV2                  ((uint32_t)1<<(CMP_CTL1_FDIV2_POS))
#define CMP_CTL1_FDIV3                  ((uint32_t)1<<(CMP_CTL1_FDIV3_POS))
#define CMP_CTL1_FDIV4                  ((uint32_t)1<<(CMP_CTL1_FDIV4_POS))
#define CMP_CTL1_FDIV5                  ((uint32_t)1<<(CMP_CTL1_FDIV5_POS))
#define CMP_CTL1_FDIV6                  ((uint32_t)1<<(CMP_CTL1_FDIV6_POS))
#define CMP_CTL1_FDIV7                  ((uint32_t)1<<(CMP_CTL1_FDIV7_POS))
#define CMP_CTL1_FLTCS                  ((uint32_t)0x3<<(CMP_CTL1_FLTCS0_POS))
#define CMP_CTL1_FLTCS0                 ((uint32_t)1<<(CMP_CTL1_FLTCS0_POS))
#define CMP_CTL1_FLTCS1                 ((uint32_t)1<<(CMP_CTL1_FLTCS1_POS))
#define CMP_CTL1_IFREN                  ((uint32_t)1<<(CMP_CTL1_IFREN_POS))
#define CMP_CTL1_IFFEN                  ((uint32_t)1<<(CMP_CTL1_IFFEN_POS))
#define CMP_CTL1_HYS                    ((uint32_t)0x7<<(CMP_CTL1_HYS0_POS))
#define CMP_CTL1_HYS0                   ((uint32_t)1<<(CMP_CTL1_HYS0_POS))
#define CMP_CTL1_HYS1                   ((uint32_t)1<<(CMP_CTL1_HYS1_POS))
#define CMP_CTL1_HYS2                   ((uint32_t)1<<(CMP_CTL1_HYS2_POS))
#define CMP_CTL1_NMOD                   ((uint32_t)0x7<<(CMP_CTL1_NMOD0_POS))
#define CMP_CTL1_NMOD0                  ((uint32_t)1<<(CMP_CTL1_NMOD0_POS))
#define CMP_CTL1_NMOD1                  ((uint32_t)1<<(CMP_CTL1_NMOD1_POS))
#define CMP_CTL1_NMOD2                  ((uint32_t)1<<(CMP_CTL1_NMOD2_POS))
#define CMP_CTL1_PMOD                   ((uint32_t)0x7<<(CMP_CTL1_PMOD0_POS))
#define CMP_CTL1_PMOD0                  ((uint32_t)1<<(CMP_CTL1_PMOD0_POS))
#define CMP_CTL1_PMOD1                  ((uint32_t)1<<(CMP_CTL1_PMOD1_POS))
#define CMP_CTL1_PMOD2                  ((uint32_t)1<<(CMP_CTL1_PMOD2_POS))

/* CMP_CTL2 λ�� */
#define CMP_CTL2_POL_POS                (1)
#define CMP_CTL2_WINEN_POS              (2)
#define CMP_CTL2_FLTEN_POS              (3)
#define CMP_CTL2_FLTCNT0_POS            (4)
#define CMP_CTL2_FLTCNT1_POS            (5)
#define CMP_CTL2_FLTCNT2_POS            (6)
#define CMP_CTL2_FDIV0_POS              (8)
#define CMP_CTL2_FDIV1_POS              (9)
#define CMP_CTL2_FDIV2_POS              (10)
#define CMP_CTL2_FDIV3_POS              (11)
#define CMP_CTL2_FDIV4_POS              (12)
#define CMP_CTL2_FDIV5_POS              (13)
#define CMP_CTL2_FDIV6_POS              (14)
#define CMP_CTL2_FDIV7_POS              (15)
#define CMP_CTL2_FLTCS0_POS             (16)
#define CMP_CTL2_FLTCS1_POS             (17)
#define CMP_CTL2_IFREN_POS              (18)
#define CMP_CTL2_IFFEN_POS              (19)
#define CMP_CTL2_HYS0_POS               (20)
#define CMP_CTL2_HYS1_POS               (21)
#define CMP_CTL2_HYS2_POS               (22)
#define CMP_CTL2_NMOD0_POS              (24)
#define CMP_CTL2_NMOD1_POS              (25)
#define CMP_CTL2_NMOD2_POS              (26)
#define CMP_CTL2_PMOD0_POS              (28)
#define CMP_CTL2_PMOD1_POS              (29)
#define CMP_CTL2_PMOD2_POS              (30)
#define CMP_CTL2_POL                    ((uint32_t)1<<(CMP_CTL2_POL_POS))
#define CMP_CTL2_WINEN                  ((uint32_t)1<<(CMP_CTL2_WINEN_POS))
#define CMP_CTL2_FLTEN                  ((uint32_t)1<<(CMP_CTL2_FLTEN_POS))
#define CMP_CTL2_FLTCNT                 ((uint32_t)0x7<<(CMP_CTL2_FLTCNT0_POS))
#define CMP_CTL2_FLTCNT0                ((uint32_t)1<<(CMP_CTL2_FLTCNT0_POS))
#define CMP_CTL2_FLTCNT1                ((uint32_t)1<<(CMP_CTL2_FLTCNT1_POS))
#define CMP_CTL2_FLTCNT2                ((uint32_t)1<<(CMP_CTL2_FLTCNT2_POS))
#define CMP_CTL2_FDIV                   ((uint32_t)0xFF<<(CMP_CTL2_FDIV0_POS))
#define CMP_CTL2_FDIV0                  ((uint32_t)1<<(CMP_CTL2_FDIV0_POS))
#define CMP_CTL2_FDIV1                  ((uint32_t)1<<(CMP_CTL2_FDIV1_POS))
#define CMP_CTL2_FDIV2                  ((uint32_t)1<<(CMP_CTL2_FDIV2_POS))
#define CMP_CTL2_FDIV3                  ((uint32_t)1<<(CMP_CTL2_FDIV3_POS))
#define CMP_CTL2_FDIV4                  ((uint32_t)1<<(CMP_CTL2_FDIV4_POS))
#define CMP_CTL2_FDIV5                  ((uint32_t)1<<(CMP_CTL2_FDIV5_POS))
#define CMP_CTL2_FDIV6                  ((uint32_t)1<<(CMP_CTL2_FDIV6_POS))
#define CMP_CTL2_FDIV7                  ((uint32_t)1<<(CMP_CTL2_FDIV7_POS))
#define CMP_CTL2_FLTCS                  ((uint32_t)0x3<<(CMP_CTL2_FLTCS0_POS))
#define CMP_CTL2_FLTCS0                 ((uint32_t)1<<(CMP_CTL2_FLTCS0_POS))
#define CMP_CTL2_FLTCS1                 ((uint32_t)1<<(CMP_CTL2_FLTCS1_POS))
#define CMP_CTL2_IFREN                  ((uint32_t)1<<(CMP_CTL2_IFREN_POS))
#define CMP_CTL2_IFFEN                  ((uint32_t)1<<(CMP_CTL2_IFFEN_POS))
#define CMP_CTL2_HYS                    ((uint32_t)0x7<<(CMP_CTL2_HYS0_POS))
#define CMP_CTL2_HYS0                   ((uint32_t)1<<(CMP_CTL2_HYS0_POS))
#define CMP_CTL2_HYS1                   ((uint32_t)1<<(CMP_CTL2_HYS1_POS))
#define CMP_CTL2_HYS2                   ((uint32_t)1<<(CMP_CTL2_HYS2_POS))
#define CMP_CTL2_NMOD                   ((uint32_t)0x7<<(CMP_CTL2_NMOD0_POS))
#define CMP_CTL2_NMOD0                  ((uint32_t)1<<(CMP_CTL2_NMOD0_POS))
#define CMP_CTL2_NMOD1                  ((uint32_t)1<<(CMP_CTL2_NMOD1_POS))
#define CMP_CTL2_NMOD2                  ((uint32_t)1<<(CMP_CTL2_NMOD2_POS))
#define CMP_CTL2_PMOD                   ((uint32_t)0x7<<(CMP_CTL2_PMOD0_POS))
#define CMP_CTL2_PMOD0                  ((uint32_t)1<<(CMP_CTL2_PMOD0_POS))
#define CMP_CTL2_PMOD1                  ((uint32_t)1<<(CMP_CTL2_PMOD1_POS))
#define CMP_CTL2_PMOD2                  ((uint32_t)1<<(CMP_CTL2_PMOD2_POS))

/* CMP_CTL3 λ�� */
#define CMP_CTL3_C3EN_POS               (0)
#define CMP_CTL3_POL_POS                (1)
#define CMP_CTL3_WINEN_POS              (2)
#define CMP_CTL3_FLTEN_POS              (3)
#define CMP_CTL3_FLTCNT0_POS            (4)
#define CMP_CTL3_FLTCNT1_POS            (5)
#define CMP_CTL3_FLTCNT2_POS            (6)
#define CMP_CTL3_FDIV0_POS              (8)
#define CMP_CTL3_FDIV1_POS              (9)
#define CMP_CTL3_FDIV2_POS              (10)
#define CMP_CTL3_FDIV3_POS              (11)
#define CMP_CTL3_FDIV4_POS              (12)
#define CMP_CTL3_FDIV5_POS              (13)
#define CMP_CTL3_FDIV6_POS              (14)
#define CMP_CTL3_FDIV7_POS              (15)
#define CMP_CTL3_FLTCS0_POS             (16)
#define CMP_CTL3_FLTCS1_POS             (17)
#define CMP_CTL3_HYS0_POS               (20)
#define CMP_CTL3_HYS1_POS               (21)
#define CMP_CTL3_HYS2_POS               (22)
#define CMP_CTL3_NMOD0_POS              (24)
#define CMP_CTL3_NMOD1_POS              (25)
#define CMP_CTL3_NMOD2_POS              (26)
#define CMP_CTL3_PMOD0_POS              (28)
#define CMP_CTL3_PMOD1_POS              (29)
#define CMP_CTL3_PMOD2_POS              (30)
#define CMP_CTL3_C3EN                   ((uint32_t)1<<(CMP_CTL3_C3EN_POS))
#define CMP_CTL3_POL                    ((uint32_t)1<<(CMP_CTL3_POL_POS))
#define CMP_CTL3_WINEN                  ((uint32_t)1<<(CMP_CTL3_WINEN_POS))
#define CMP_CTL3_FLTEN                  ((uint32_t)1<<(CMP_CTL3_FLTEN_POS))
#define CMP_CTL3_FLTCNT                 ((uint32_t)0x7<<(CMP_CTL3_FLTCNT0_POS))
#define CMP_CTL3_FLTCNT0                ((uint32_t)1<<(CMP_CTL3_FLTCNT0_POS))
#define CMP_CTL3_FLTCNT1                ((uint32_t)1<<(CMP_CTL3_FLTCNT1_POS))
#define CMP_CTL3_FLTCNT2                ((uint32_t)1<<(CMP_CTL3_FLTCNT2_POS))
#define CMP_CTL3_FDIV                   ((uint32_t)0xFF<<(CMP_CTL3_FDIV0_POS))
#define CMP_CTL3_FDIV0                  ((uint32_t)1<<(CMP_CTL3_FDIV0_POS))
#define CMP_CTL3_FDIV1                  ((uint32_t)1<<(CMP_CTL3_FDIV1_POS))
#define CMP_CTL3_FDIV2                  ((uint32_t)1<<(CMP_CTL3_FDIV2_POS))
#define CMP_CTL3_FDIV3                  ((uint32_t)1<<(CMP_CTL3_FDIV3_POS))
#define CMP_CTL3_FDIV4                  ((uint32_t)1<<(CMP_CTL3_FDIV4_POS))
#define CMP_CTL3_FDIV5                  ((uint32_t)1<<(CMP_CTL3_FDIV5_POS))
#define CMP_CTL3_FDIV6                  ((uint32_t)1<<(CMP_CTL3_FDIV6_POS))
#define CMP_CTL3_FDIV7                  ((uint32_t)1<<(CMP_CTL3_FDIV7_POS))
#define CMP_CTL3_FLTCS                  ((uint32_t)0x3<<(CMP_CTL3_FLTCS0_POS))
#define CMP_CTL3_FLTCS0                 ((uint32_t)1<<(CMP_CTL3_FLTCS0_POS))
#define CMP_CTL3_FLTCS1                 ((uint32_t)1<<(CMP_CTL3_FLTCS1_POS))
#define CMP_CTL3_HYS                    ((uint32_t)0x7<<(CMP_CTL3_HYS0_POS))
#define CMP_CTL3_HYS0                   ((uint32_t)1<<(CMP_CTL3_HYS0_POS))
#define CMP_CTL3_HYS1                   ((uint32_t)1<<(CMP_CTL3_HYS1_POS))
#define CMP_CTL3_HYS2                   ((uint32_t)1<<(CMP_CTL3_HYS2_POS))
#define CMP_CTL3_NMOD                   ((uint32_t)0x7<<(CMP_CTL3_NMOD0_POS))
#define CMP_CTL3_NMOD0                  ((uint32_t)1<<(CMP_CTL3_NMOD0_POS))
#define CMP_CTL3_NMOD1                  ((uint32_t)1<<(CMP_CTL3_NMOD1_POS))
#define CMP_CTL3_NMOD2                  ((uint32_t)1<<(CMP_CTL3_NMOD2_POS))
#define CMP_CTL3_PMOD                   ((uint32_t)0x7<<(CMP_CTL3_PMOD0_POS))
#define CMP_CTL3_PMOD0                  ((uint32_t)1<<(CMP_CTL3_PMOD0_POS))
#define CMP_CTL3_PMOD1                  ((uint32_t)1<<(CMP_CTL3_PMOD1_POS))
#define CMP_CTL3_PMOD2                  ((uint32_t)1<<(CMP_CTL3_PMOD2_POS))

/* CMP_CTL4 λ�� */
#define CMP_CTL4_C0EN_POS               (0)
#define CMP_CTL4_C1EN_POS               (1)
#define CMP_CTL4_C2EN_POS               (2)
#define CMP_CTL4_FLTINSEL_POS           (3)
#define CMP_CTL4_BEMFEN_POS             (4)
#define CMP_CTL4_HALSEL_POS             (5)
#define CMP_CTL4_TRIM0_POS              (6)
#define CMP_CTL4_TRIM1_POS              (7)
#define CMP_CTL4_C3IFREN_POS            (10)
#define CMP_CTL4_C3IFFEN_POS            (11)
#define CMP_CTL4_C0IE_POS               (12)
#define CMP_CTL4_C1IE_POS               (13)
#define CMP_CTL4_C2IE_POS               (14)
#define CMP_CTL4_C3IE_POS               (15)
#define CMP_CTL4_C0IC_POS               (16)
#define CMP_CTL4_C1IC_POS               (17)
#define CMP_CTL4_C2IC_POS               (18)
#define CMP_CTL4_C3IC_POS               (19)
#define CMP_CTL4_CIFMS_POS              (23)
#define CMP_CTL4_C0IF_POS               (24)
#define CMP_CTL4_C1IF_POS               (25)
#define CMP_CTL4_C2IF_POS               (26)
#define CMP_CTL4_C3IF_POS               (27)
#define CMP_CTL4_C0OUT_POS              (28)
#define CMP_CTL4_C1OUT_POS              (29)
#define CMP_CTL4_C2OUT_POS              (30)
#define CMP_CTL4_C3OUT_POS              (31)
#define CMP_CTL4_C0EN                   ((uint32_t)1<<(CMP_CTL4_C0EN_POS))
#define CMP_CTL4_C1EN                   ((uint32_t)1<<(CMP_CTL4_C1EN_POS))
#define CMP_CTL4_C2EN                   ((uint32_t)1<<(CMP_CTL4_C2EN_POS))
#define CMP_CTL4_FLTINSEL               ((uint32_t)1<<(CMP_CTL4_FLTINSEL_POS))
#define CMP_CTL4_BEMFEN                 ((uint32_t)1<<(CMP_CTL4_BEMFEN_POS))
#define CMP_CTL4_HALSEL                 ((uint32_t)1<<(CMP_CTL4_HALSEL_POS))
#define CMP_CTL4_TRIM                   ((uint32_t)0x3<<(CMP_CTL4_TRIM0_POS))
#define CMP_CTL4_TRIM0                  ((uint32_t)1<<(CMP_CTL4_TRIM0_POS))
#define CMP_CTL4_TRIM1                  ((uint32_t)1<<(CMP_CTL4_TRIM1_POS))
#define CMP_CTL4_C3IFREN                ((uint32_t)1<<(CMP_CTL4_C3IFREN_POS))
#define CMP_CTL4_C3IFFEN                ((uint32_t)1<<(CMP_CTL4_C3IFFEN_POS))
#define CMP_CTL4_C0IE                   ((uint32_t)1<<(CMP_CTL4_C0IE_POS))
#define CMP_CTL4_C1IE                   ((uint32_t)1<<(CMP_CTL4_C1IE_POS))
#define CMP_CTL4_C2IE                   ((uint32_t)1<<(CMP_CTL4_C2IE_POS))
#define CMP_CTL4_C3IE                   ((uint32_t)1<<(CMP_CTL4_C3IE_POS))
#define CMP_CTL4_C0IC                   ((uint32_t)1<<(CMP_CTL4_C0IC_POS))
#define CMP_CTL4_C1IC                   ((uint32_t)1<<(CMP_CTL4_C1IC_POS))
#define CMP_CTL4_C2IC                   ((uint32_t)1<<(CMP_CTL4_C2IC_POS))
#define CMP_CTL4_C3IC                   ((uint32_t)1<<(CMP_CTL4_C3IC_POS))
#define CMP_CTL4_CIFMS                  ((uint32_t)1<<(CMP_CTL4_CIFMS_POS))
#define CMP_CTL4_C0IF                   ((uint32_t)1<<(CMP_CTL4_C0IF_POS))
#define CMP_CTL4_C1IF                   ((uint32_t)1<<(CMP_CTL4_C1IF_POS))
#define CMP_CTL4_C2IF                   ((uint32_t)1<<(CMP_CTL4_C2IF_POS))
#define CMP_CTL4_C3IF                   ((uint32_t)1<<(CMP_CTL4_C3IF_POS))
#define CMP_CTL4_C0OUT                  ((uint32_t)1<<(CMP_CTL4_C0OUT_POS))
#define CMP_CTL4_C1OUT                  ((uint32_t)1<<(CMP_CTL4_C1OUT_POS))
#define CMP_CTL4_C2OUT                  ((uint32_t)1<<(CMP_CTL4_C2OUT_POS))
#define CMP_CTL4_C3OUT                  ((uint32_t)1<<(CMP_CTL4_C3OUT_POS))

#endif //KF32F_Periph_cmp
/* ��ģת��ģ�� (CMP)������� */


/* ----------------------------------------------------------------------------
   -- Һ����ʾ (LCD)
   ---------------------------------------------------------------------------- */
#ifdef KF32F_Periph_lcd
/* LCD - ����Ĵ����ڴ�ṹ */
typedef struct LCD_MemMap {
    volatile uint32_t CTL;              /* PCLK���ƼĴ���0, ƫ��:0x00 */
    volatile uint32_t PTL;              /* PCLK���ƼĴ���1, ƫ��:0x04 */
    volatile uint32_t INTCTL;           /* PCLK���ƼĴ���2, ƫ��:0x08 */
    volatile uint32_t SEL0;             /* PCLK���ƼĴ���3, ƫ��:0x0C */
    volatile uint32_t SEL1;             /* PCLK���ƼĴ���3, ƫ��:0x10 */
    volatile uint32_t SEG0;             /* PCLK���ƼĴ���3, ƫ��:0x14 */
    volatile uint32_t SEG1;             /* PCLK���ƼĴ���3, ƫ��:0x18 */
             uint32_t RESERVED[9];      /* ������ַ, ƫ��:0x1C */
    volatile uint32_t DATA[12];         /* PCLK���ƼĴ���3, ƫ��:0x40 */
}LCD_SFRmap;

/* ----------------------------------------------------------------------------
   -- LCD - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* LCD - �Ĵ�����ڵ�ַ */
#define LCD_ADDR                        ((uint32_t)0x40000E80)
#define LCD_SFR                         ((LCD_SFRmap *) LCD_ADDR)

/* LCD - �Ĵ������ */
#define LCD_CTL                         (LCD_SFR->CTL)
#define LCD_PTL                         (LCD_SFR->PTL)
#define LCD_INTCTL                      (LCD_SFR->INTCTL)
#define LCD_SEL0                        (LCD_SFR->SEL0)
#define LCD_SEL1                        (LCD_SFR->SEL1)
#define LCD_SEG0                        (LCD_SFR->SEG0)
#define LCD_SEG1                        (LCD_SFR->SEG1)
#define LCD_DATA0                       (LCD_SFR->DATA[0])
#define LCD_DATA1                       (LCD_SFR->DATA[1])
#define LCD_DATA2                       (LCD_SFR->DATA[2])
#define LCD_DATA3                       (LCD_SFR->DATA[3])
#define LCD_DATA4                       (LCD_SFR->DATA[4])
#define LCD_DATA5                       (LCD_SFR->DATA[5])
#define LCD_DATA6                       (LCD_SFR->DATA[6])
#define LCD_DATA7                       (LCD_SFR->DATA[7])
#define LCD_DATA8                       (LCD_SFR->DATA[8])
#define LCD_DATA9                       (LCD_SFR->DATA[9])
#define LCD_DATA10                      (LCD_SFR->DATA[10])
#define LCD_DATA11                      (LCD_SFR->DATA[11])

/* LCD_CTL λ�� */
#define LCD_CTL_LP0_POS                 (0)
#define LCD_CTL_LP1_POS                 (1)
#define LCD_CTL_LP2_POS                 (2)
#define LCD_CTL_LP3_POS                 (3)
#define LCD_CTL_LCDA_POS                (5)
#define LCD_CTL_BIASMD_POS              (6)
#define LCD_CTL_WFT_POS                 (7)
#define LCD_CTL_CS0_POS                 (10)
#define LCD_CTL_CS1_POS                 (11)
#define LCD_CTL_PUMPEN_POS              (12)
#define LCD_CTL_VLCDMD_POS              (13)
#define LCD_CTL_VLCDS_POS               (15)
#define LCD_CTL_FR0_POS                 (17)
#define LCD_CTL_FR1_POS                 (18)
#define LCD_CTL_FR2_POS                 (19)
#define LCD_CTL_FR3_POS                 (20)
#define LCD_CTL_LMUX0_POS               (21)
#define LCD_CTL_LMUX1_POS               (22)
#define LCD_CTL_LMUX2_POS               (23)
#define LCD_CTL_TRIMCPVOL0_POS          (24)
#define LCD_CTL_TRIMCPVOL1_POS          (25)
#define LCD_CTL_TRIMCPVOL2_POS          (26)
#define LCD_CTL_VLCDPEN_POS             (27)
#define LCD_CTL_IOEN_POS                (28)
#define LCD_CTL_LCDENANALOG_POS         (30)
#define LCD_CTL_LCDEN_POS               (31)
#define LCD_CTL_LP                      ((uint32_t)0xF<<(LCD_CTL_LP0_POS))
#define LCD_CTL_LP0                     ((uint32_t)1<<(LCD_CTL_LP0_POS))
#define LCD_CTL_LP1                     ((uint32_t)1<<(LCD_CTL_LP1_POS))
#define LCD_CTL_LP2                     ((uint32_t)1<<(LCD_CTL_LP2_POS))
#define LCD_CTL_LP3                     ((uint32_t)1<<(LCD_CTL_LP3_POS))
#define LCD_CTL_LCDA                    ((uint32_t)1<<(LCD_CTL_LCDA_POS))
#define LCD_CTL_BIASMD                  ((uint32_t)1<<(LCD_CTL_BIASMD_POS))
#define LCD_CTL_WFT                     ((uint32_t)1<<(LCD_CTL_WFT_POS))
#define LCD_CTL_CS                      ((uint32_t)3<<(LCD_CTL_CS0_POS))
#define LCD_CTL_CS0                     ((uint32_t)1<<(LCD_CTL_CS0_POS))
#define LCD_CTL_CS1                     ((uint32_t)1<<(LCD_CTL_CS1_POS))
#define LCD_CTL_PUMPEN                  ((uint32_t)1<<(LCD_CTL_PUMPEN_POS))
#define LCD_CTL_VLCDMD                  ((uint32_t)1<<(LCD_CTL_VLCDMD_POS))
#define LCD_CTL_VLCDS                   ((uint32_t)1<<(LCD_CTL_VLCDS_POS))
#define LCD_CTL_FR                      ((uint32_t)0xF<<(LCD_CTL_FR0_POS))
#define LCD_CTL_FR0                     ((uint32_t)1<<(LCD_CTL_FR0_POS))
#define LCD_CTL_FR1                     ((uint32_t)1<<(LCD_CTL_FR1_POS))
#define LCD_CTL_FR2                     ((uint32_t)1<<(LCD_CTL_FR2_POS))
#define LCD_CTL_FR3                     ((uint32_t)1<<(LCD_CTL_FR3_POS))
#define LCD_CTL_LMUX                    ((uint32_t)7<<(LCD_CTL_LMUX0_POS))
#define LCD_CTL_LMUX0                   ((uint32_t)1<<(LCD_CTL_LMUX0_POS))
#define LCD_CTL_LMUX1                   ((uint32_t)1<<(LCD_CTL_LMUX1_POS))
#define LCD_CTL_LMUX2                   ((uint32_t)1<<(LCD_CTL_LMUX2_POS))
#define LCD_CTL_TRIMCPVOL               ((uint32_t)7<<(LCD_CTL_TRIMCPVOL0_POS))
#define LCD_CTL_TRIMCPVOL0              ((uint32_t)1<<(LCD_CTL_TRIMCPVOL0_POS))
#define LCD_CTL_TRIMCPVOL1              ((uint32_t)1<<(LCD_CTL_TRIMCPVOL1_POS))
#define LCD_CTL_TRIMCPVOL2              ((uint32_t)1<<(LCD_CTL_TRIMCPVOL2_POS))
#define LCD_CTL_VLCDPEN                 ((uint32_t)1<<(LCD_CTL_VLCDPEN_POS))
#define LCD_CTL_IOEN                    ((uint32_t)1<<(LCD_CTL_IOEN_POS))
#define LCD_CTL_LCDENANALOG             ((uint32_t)1<<(LCD_CTL_LCDENANALOG_POS))
#define LCD_CTL_LCDEN                   ((uint32_t)1<<(LCD_CTL_LCDEN_POS))

/* LCD_PTL λ�� */
#define LCD_PTL_ATIC0_POS               (0)
#define LCD_PTL_ATIC1_POS               (1)
#define LCD_PTL_ATIC2_POS               (2)
#define LCD_PTL_BPC0_POS                (3)
#define LCD_PTL_BPC1_POS                (4)
#define LCD_PTL_APC0_POS                (5)
#define LCD_PTL_APC1_POS                (6)
#define LCD_PTL_IF0_POS                 (7)
#define LCD_PTL_IF1_POS                 (8)
#define LCD_PTL_IF2_POS                 (9)
#define LCD_PTL_TS0_POS                 (10)
#define LCD_PTL_TS1_POS                 (11)
#define LCD_PTL_TS2_POS                 (12)
#define LCD_PTL_SPEN_POS                (13)
#define LCD_PTL_FLKSTU_POS              (14)
#define LCD_PTL_FLKEN_POS               (15)
#define LCD_PTL_FOFF0_POS               (16)
#define LCD_PTL_FOFF1_POS               (17)
#define LCD_PTL_FOFF2_POS               (18)
#define LCD_PTL_FOFF3_POS               (19)
#define LCD_PTL_FOFF4_POS               (20)
#define LCD_PTL_FOFF5_POS               (21)
#define LCD_PTL_FOFF6_POS               (22)
#define LCD_PTL_FOFF7_POS               (23)
#define LCD_PTL_FON0_POS                (24)
#define LCD_PTL_FON1_POS                (25)
#define LCD_PTL_FON2_POS                (26)
#define LCD_PTL_FON3_POS                (27)
#define LCD_PTL_FON4_POS                (28)
#define LCD_PTL_FON5_POS                (29)
#define LCD_PTL_FON6_POS                (30)
#define LCD_PTL_FON7_POS                (31)
#define LCD_PTL_ATIC                    ((uint32_t)7<<(LCD_PTL_ATIC0_POS))
#define LCD_PTL_ATIC0                   ((uint32_t)1<<(LCD_PTL_ATIC0_POS))
#define LCD_PTL_ATIC1                   ((uint32_t)1<<(LCD_PTL_ATIC1_POS))
#define LCD_PTL_ATIC2                   ((uint32_t)1<<(LCD_PTL_ATIC2_POS))
#define LCD_PTL_BPC                     ((uint32_t)3<<(LCD_PTL_BPC0_POS))
#define LCD_PTL_BPC0                    ((uint32_t)1<<(LCD_PTL_BPC0_POS))
#define LCD_PTL_BPC1                    ((uint32_t)1<<(LCD_PTL_BPC1_POS))
#define LCD_PTL_APC                     ((uint32_t)3<<(LCD_PTL_APC0_POS))
#define LCD_PTL_APC0                    ((uint32_t)1<<(LCD_PTL_APC0_POS))
#define LCD_PTL_APC1                    ((uint32_t)1<<(LCD_PTL_APC1_POS))
#define LCD_PTL_IF                      ((uint32_t)7<<(LCD_PTL_IF0_POS))
#define LCD_PTL_IF0                     ((uint32_t)1<<(LCD_PTL_IF0_POS))
#define LCD_PTL_IF1                     ((uint32_t)1<<(LCD_PTL_IF1_POS))
#define LCD_PTL_IF2                     ((uint32_t)1<<(LCD_PTL_IF2_POS))
#define LCD_PTL_TS                      ((uint32_t)7<<(LCD_PTL_TS0_POS))
#define LCD_PTL_TS0                     ((uint32_t)1<<(LCD_PTL_TS0_POS))
#define LCD_PTL_TS1                     ((uint32_t)1<<(LCD_PTL_TS1_POS))
#define LCD_PTL_TS2                     ((uint32_t)1<<(LCD_PTL_TS2_POS))
#define LCD_PTL_SPEN                    ((uint32_t)1<<(LCD_PTL_SPEN_POS))
#define LCD_PTL_FLKSTU                  ((uint32_t)1<<(LCD_PTL_FLKSTU_POS))
#define LCD_PTL_FLKEN                   ((uint32_t)1<<(LCD_PTL_FLKEN_POS))
#define LCD_PTL_FOFF                    ((uint32_t)0xFF<<(LCD_PTL_FOFF0_POS))
#define LCD_PTL_FOFF0                   ((uint32_t)1<<(LCD_PTL_FOFF0_POS))
#define LCD_PTL_FOFF1                   ((uint32_t)1<<(LCD_PTL_FOFF1_POS))
#define LCD_PTL_FOFF2                   ((uint32_t)1<<(LCD_PTL_FOFF2_POS))
#define LCD_PTL_FOFF3                   ((uint32_t)1<<(LCD_PTL_FOFF3_POS))
#define LCD_PTL_FOFF4                   ((uint32_t)1<<(LCD_PTL_FOFF4_POS))
#define LCD_PTL_FOFF5                   ((uint32_t)1<<(LCD_PTL_FOFF5_POS))
#define LCD_PTL_FOFF6                   ((uint32_t)1<<(LCD_PTL_FOFF6_POS))
#define LCD_PTL_FOFF7                   ((uint32_t)1<<(LCD_PTL_FOFF7_POS))
#define LCD_PTL_FON                     ((uint32_t)0xFF<<(LCD_PTL_FON0_POS))
#define LCD_PTL_FON0                    ((uint32_t)1<<(LCD_PTL_FON0_POS))
#define LCD_PTL_FON1                    ((uint32_t)1<<(LCD_PTL_FON1_POS))
#define LCD_PTL_FON2                    ((uint32_t)1<<(LCD_PTL_FON2_POS))
#define LCD_PTL_FON3                    ((uint32_t)1<<(LCD_PTL_FON3_POS))
#define LCD_PTL_FON4                    ((uint32_t)1<<(LCD_PTL_FON4_POS))
#define LCD_PTL_FON5                    ((uint32_t)1<<(LCD_PTL_FON5_POS))
#define LCD_PTL_FON6                    ((uint32_t)1<<(LCD_PTL_FON6_POS))
#define LCD_PTL_FON7                    ((uint32_t)1<<(LCD_PTL_FON7_POS))

/* LCD_INTCTL λ�� */
#define LCD_INTCTL_FRAMIE_POS           (0)
#define LCD_INTCTL_FCKOFFIE_POS         (1)
#define LCD_INTCTL_FCKONIE_POS          (2)
#define LCD_INTCTL_UDDIE_POS            (3)
#define LCD_INTCTL_FRAMIF_POS           (4)
#define LCD_INTCTL_FCKOFFIF_POS         (5)
#define LCD_INTCTL_FCKONIF_POS          (6)
#define LCD_INTCTL_LCDDEAD_POS          (10)
#define LCD_INTCTL_UDR_POS              (11)
#define LCD_INTCTL_UDDIF_POS            (12)
#define LCD_INTCTL_FRAMIE               ((uint32_t)1<<(LCD_INTCTL_FRAMIE_POS))
#define LCD_INTCTL_FCKOFFIE             ((uint32_t)1<<(LCD_INTCTL_FCKOFFIE_POS))
#define LCD_INTCTL_FCKONIE              ((uint32_t)1<<(LCD_INTCTL_FCKONIE_POS))
#define LCD_INTCTL_UDDIE                ((uint32_t)1<<(LCD_INTCTL_UDDIE_POS))
#define LCD_INTCTL_FRAMIF               ((uint32_t)1<<(LCD_INTCTL_FRAMIF_POS))
#define LCD_INTCTL_FCKOFFIF             ((uint32_t)1<<(LCD_INTCTL_FCKOFFIF_POS))
#define LCD_INTCTL_FCKONIF              ((uint32_t)1<<(LCD_INTCTL_FCKONIF_POS))
#define LCD_INTCTL_LCDDEAD              ((uint32_t)1<<(LCD_INTCTL_LCDDEAD_POS))
#define LCD_INTCTL_UDR                  ((uint32_t)1<<(LCD_INTCTL_UDR_POS))
#define LCD_INTCTL_UDDIF                ((uint32_t)1<<(LCD_INTCTL_UDDIF_POS))

/* LCD_SEL0 λ�� */
#define LCD_SEL_SEG0_POS                (0)
#define LCD_SEL_SEG1_POS                (1)
#define LCD_SEL_SEG2_POS                (2)
#define LCD_SEL_SEG3_POS                (3)
#define LCD_SEL_SEG4_POS                (4)
#define LCD_SEL_SEG5_POS                (5)
#define LCD_SEL_SEG6_POS                (6)
#define LCD_SEL_SEG7_POS                (7)
#define LCD_SEL_SEG8_POS                (8)
#define LCD_SEL_SEG9_POS                (9)
#define LCD_SEL_SEG10_POS               (10)
#define LCD_SEL_SEG11_POS               (11)
#define LCD_SEL_SEG12_POS               (12)
#define LCD_SEL_SEG13_POS               (13)
#define LCD_SEL_SEG14_POS               (14)
#define LCD_SEL_SEG15_POS               (15)
#define LCD_SEL_SEG16_POS               (16)
#define LCD_SEL_SEG17_POS               (17)
#define LCD_SEL_SEG18_POS               (18)
#define LCD_SEL_SEG19_POS               (19)
#define LCD_SEL_SEG20_POS               (20)
#define LCD_SEL_SEG21_POS               (21)
#define LCD_SEL_SEG22_POS               (22)
#define LCD_SEL_SEG23_POS               (23)
#define LCD_SEL_SEG24_POS               (24)
#define LCD_SEL_SEG25_POS               (25)
#define LCD_SEL_SEG26_POS               (26)
#define LCD_SEL_SEG27_POS               (27)
#define LCD_SEL_SEG28_POS               (28)
#define LCD_SEL_SEG29_POS               (29)
#define LCD_SEL_SEG30_POS               (30)
#define LCD_SEL_SEG31_POS               (31)
#define LCD_SEL_SEG0                    ((uint32_t)1<<(LCD_SEL_SEL0_POS))
#define LCD_SEL_SEG1                    ((uint32_t)1<<(LCD_SEL_SEL1_POS))
#define LCD_SEL_SEG2                    ((uint32_t)1<<(LCD_SEL_SEL2_POS))
#define LCD_SEL_SEG3                    ((uint32_t)1<<(LCD_SEL_SEL3_POS))
#define LCD_SEL_SEG4                    ((uint32_t)1<<(LCD_SEL_SEL4_POS))
#define LCD_SEL_SEG5                    ((uint32_t)1<<(LCD_SEL_SEL5_POS))
#define LCD_SEL_SEG6                    ((uint32_t)1<<(LCD_SEL_SEL6_POS))
#define LCD_SEL_SEG7                    ((uint32_t)1<<(LCD_SEL_SEL7_POS))
#define LCD_SEL_SEG8                    ((uint32_t)1<<(LCD_SEL_SEL8_POS))
#define LCD_SEL_SEG9                    ((uint32_t)1<<(LCD_SEL_SEL9_POS))
#define LCD_SEL_SEG10                   ((uint32_t)1<<(LCD_SEL_SEL10_POS))
#define LCD_SEL_SEG11                   ((uint32_t)1<<(LCD_SEL_SEL11_POS))
#define LCD_SEL_SEG12                   ((uint32_t)1<<(LCD_SEL_SEL12_POS))
#define LCD_SEL_SEG13                   ((uint32_t)1<<(LCD_SEL_SEL13_POS))
#define LCD_SEL_SEG14                   ((uint32_t)1<<(LCD_SEL_SEL14_POS))
#define LCD_SEL_SEG15                   ((uint32_t)1<<(LCD_SEL_SEL15_POS))
#define LCD_SEL_SEG16                   ((uint32_t)1<<(LCD_SEL_SEL16_POS))
#define LCD_SEL_SEG17                   ((uint32_t)1<<(LCD_SEL_SEL17_POS))
#define LCD_SEL_SEG18                   ((uint32_t)1<<(LCD_SEL_SEL18_POS))
#define LCD_SEL_SEG19                   ((uint32_t)1<<(LCD_SEL_SEL19_POS))
#define LCD_SEL_SEG20                   ((uint32_t)1<<(LCD_SEL_SEL20_POS))
#define LCD_SEL_SEG21                   ((uint32_t)1<<(LCD_SEL_SEL21_POS))
#define LCD_SEL_SEG22                   ((uint32_t)1<<(LCD_SEL_SEL22_POS))
#define LCD_SEL_SEG23                   ((uint32_t)1<<(LCD_SEL_SEL23_POS))
#define LCD_SEL_SEG24                   ((uint32_t)1<<(LCD_SEL_SEL24_POS))
#define LCD_SEL_SEG25                   ((uint32_t)1<<(LCD_SEL_SEL25_POS))
#define LCD_SEL_SEG26                   ((uint32_t)1<<(LCD_SEL_SEL26_POS))
#define LCD_SEL_SEG27                   ((uint32_t)1<<(LCD_SEL_SEL27_POS))
#define LCD_SEL_SEG28                   ((uint32_t)1<<(LCD_SEL_SEL28_POS))
#define LCD_SEL_SEG29                   ((uint32_t)1<<(LCD_SEL_SEL29_POS))
#define LCD_SEL_SEG30                   ((uint32_t)1<<(LCD_SEL_SEL30_POS))
#define LCD_SEL_SEG31                   ((uint32_t)1<<(LCD_SEL_SEL31_POS))

/* LCD_SEL1 λ�� */
#define LCD_SEL_SEG32_POS               (0)
#define LCD_SEL_SEG33_POS               (1)
#define LCD_SEL_SEG34_POS               (2)
#define LCD_SEL_SEG35_POS               (3)
#define LCD_SEL_SEG36_POS               (4)
#define LCD_SEL_SEG37_POS               (5)
#define LCD_SEL_SEG38_POS               (6)
#define LCD_SEL_SEG39_POS               (7)
#define LCD_SEL_SEG40_POS               (8)
#define LCD_SEL_SEG41_POS               (9)
#define LCD_SEL_SEG42_POS               (10)
#define LCD_SEL_SEG43_POS               (11)
#define LCD_SEL_SEG44_POS               (12)
#define LCD_SEL_SEG45_POS               (13)
#define LCD_SEL_SEG46_POS               (14)
#define LCD_SEL_SEG47_POS               (15)
#define LCD_SEL_SEG47_POS               (15)
#define LCD_SEL_COM0_POS                (16)
#define LCD_SEL_COM1_POS                (17)
#define LCD_SEL_COM2_POS                (18)
#define LCD_SEL_COM3_POS                (19)
#define LCD_SEL_COM4_POS                (20)
#define LCD_SEL_COM5_POS                (21)
#define LCD_SEL_COM6_POS                (22)
#define LCD_SEL_COM7_POS                (23)

#define LCD_SEL_SEG32                   ((uint32_t)1<<(LCD_SEL_SEL32_POS))
#define LCD_SEL_SEG33                   ((uint32_t)1<<(LCD_SEL_SEL33_POS))
#define LCD_SEL_SEG34                   ((uint32_t)1<<(LCD_SEL_SEL34_POS))
#define LCD_SEL_SEG35                   ((uint32_t)1<<(LCD_SEL_SEL35_POS))
#define LCD_SEL_SEG36                   ((uint32_t)1<<(LCD_SEL_SEL36_POS))
#define LCD_SEL_SEG37                   ((uint32_t)1<<(LCD_SEL_SEL37_POS))
#define LCD_SEL_SEG38                   ((uint32_t)1<<(LCD_SEL_SEL38_POS))
#define LCD_SEL_SEG39                   ((uint32_t)1<<(LCD_SEL_SEL39_POS))
#define LCD_SEL_SEG40                   ((uint32_t)1<<(LCD_SEL_SEL40_POS))
#define LCD_SEL_SEG41                   ((uint32_t)1<<(LCD_SEL_SEL41_POS))
#define LCD_SEL_SEG42                   ((uint32_t)1<<(LCD_SEL_SEL42_POS))
#define LCD_SEL_SEG43                   ((uint32_t)1<<(LCD_SEL_SEL43_POS))
#define LCD_SEL_SEG44                   ((uint32_t)1<<(LCD_SEL_SEL44_POS))
#define LCD_SEL_SEG45                   ((uint32_t)1<<(LCD_SEL_SEL45_POS))
#define LCD_SEL_SEG46                   ((uint32_t)1<<(LCD_SEL_SEL46_POS))
#define LCD_SEL_SEG47                   ((uint32_t)1<<(LCD_SEL_SEL47_POS))
#define LCD_SEL_COM0                    ((uint32_t)1<<(LCD_SEL_COM0_POS))
#define LCD_SEL_COM1                    ((uint32_t)1<<(LCD_SEL_COM1_POS))
#define LCD_SEL_COM2                    ((uint32_t)1<<(LCD_SEL_COM2_POS))
#define LCD_SEL_COM3                    ((uint32_t)1<<(LCD_SEL_COM3_POS))
#define LCD_SEL_COM4                    ((uint32_t)1<<(LCD_SEL_COM4_POS))
#define LCD_SEL_COM5                    ((uint32_t)1<<(LCD_SEL_COM5_POS))
#define LCD_SEL_COM6                    ((uint32_t)1<<(LCD_SEL_COM6_POS))
#define LCD_SEL_COM7                    ((uint32_t)1<<(LCD_SEL_COM7_POS))

/* LCD_DATA0 λ�� */
#define LCD_DATA_COM0SEG0_POS           (0)
#define LCD_DATA_COM0SEG1_POS           (1)
#define LCD_DATA_COM0SEG2_POS           (2)
#define LCD_DATA_COM0SEG3_POS           (3)
#define LCD_DATA_COM0SEG4_POS           (4)
#define LCD_DATA_COM0SEG5_POS           (5)
#define LCD_DATA_COM0SEG6_POS           (6)
#define LCD_DATA_COM0SEG7_POS           (7)
#define LCD_DATA_COM0SEG8_POS           (8)
#define LCD_DATA_COM0SEG9_POS           (9)
#define LCD_DATA_COM0SEG10_POS          (10)
#define LCD_DATA_COM0SEG11_POS          (11)
#define LCD_DATA_COM0SEG12_POS          (12)
#define LCD_DATA_COM0SEG13_POS          (13)
#define LCD_DATA_COM0SEG14_POS          (14)
#define LCD_DATA_COM0SEG15_POS          (15)
#define LCD_DATA_COM0SEG16_POS          (16)
#define LCD_DATA_COM0SEG17_POS          (17)
#define LCD_DATA_COM0SEG18_POS          (18)
#define LCD_DATA_COM0SEG19_POS          (19)
#define LCD_DATA_COM0SEG20_POS          (20)
#define LCD_DATA_COM0SEG21_POS          (21)
#define LCD_DATA_COM0SEG22_POS          (22)
#define LCD_DATA_COM0SEG23_POS          (23)
#define LCD_DATA_COM0SEG24_POS          (24)
#define LCD_DATA_COM0SEG25_POS          (25)
#define LCD_DATA_COM0SEG26_POS          (26)
#define LCD_DATA_COM0SEG27_POS          (27)
#define LCD_DATA_COM0SEG28_POS          (28)
#define LCD_DATA_COM0SEG29_POS          (29)
#define LCD_DATA_COM0SEG30_POS          (30)
#define LCD_DATA_COM0SEG31_POS          (31)
#define LCD_DATA_COM0SEG0               ((uint32_t)1<<(LCD_DATA_COM0SEG0_POS))
#define LCD_DATA_COM0SEG1               ((uint32_t)1<<(LCD_DATA_COM0SEG1_POS))
#define LCD_DATA_COM0SEG2               ((uint32_t)1<<(LCD_DATA_COM0SEG2_POS))
#define LCD_DATA_COM0SEG3               ((uint32_t)1<<(LCD_DATA_COM0SEG3_POS))
#define LCD_DATA_COM0SEG4               ((uint32_t)1<<(LCD_DATA_COM0SEG4_POS))
#define LCD_DATA_COM0SEG5               ((uint32_t)1<<(LCD_DATA_COM0SEG5_POS))
#define LCD_DATA_COM0SEG6               ((uint32_t)1<<(LCD_DATA_COM0SEG6_POS))
#define LCD_DATA_COM0SEG7               ((uint32_t)1<<(LCD_DATA_COM0SEG7_POS))
#define LCD_DATA_COM0SEG8               ((uint32_t)1<<(LCD_DATA_COM0SEG8_POS))
#define LCD_DATA_COM0SEG9               ((uint32_t)1<<(LCD_DATA_COM0SEG9_POS))
#define LCD_DATA_COM0SEG10              ((uint32_t)1<<(LCD_DATA_COM0SEG10_POS))
#define LCD_DATA_COM0SEG11              ((uint32_t)1<<(LCD_DATA_COM0SEG11_POS))
#define LCD_DATA_COM0SEG12              ((uint32_t)1<<(LCD_DATA_COM0SEG12_POS))
#define LCD_DATA_COM0SEG13              ((uint32_t)1<<(LCD_DATA_COM0SEG13_POS))
#define LCD_DATA_COM0SEG14              ((uint32_t)1<<(LCD_DATA_COM0SEG14_POS))
#define LCD_DATA_COM0SEG15              ((uint32_t)1<<(LCD_DATA_COM0SEG15_POS))
#define LCD_DATA_COM0SEG16              ((uint32_t)1<<(LCD_DATA_COM0SEG16_POS))
#define LCD_DATA_COM0SEG17              ((uint32_t)1<<(LCD_DATA_COM0SEG17_POS))
#define LCD_DATA_COM0SEG18              ((uint32_t)1<<(LCD_DATA_COM0SEG18_POS))
#define LCD_DATA_COM0SEG19              ((uint32_t)1<<(LCD_DATA_COM0SEG19_POS))
#define LCD_DATA_COM0SEG20              ((uint32_t)1<<(LCD_DATA_COM0SEG20_POS))
#define LCD_DATA_COM0SEG21              ((uint32_t)1<<(LCD_DATA_COM0SEG21_POS))
#define LCD_DATA_COM0SEG22              ((uint32_t)1<<(LCD_DATA_COM0SEG22_POS))
#define LCD_DATA_COM0SEG23              ((uint32_t)1<<(LCD_DATA_COM0SEG23_POS))
#define LCD_DATA_COM0SEG24              ((uint32_t)1<<(LCD_DATA_COM0SEG24_POS))
#define LCD_DATA_COM0SEG25              ((uint32_t)1<<(LCD_DATA_COM0SEG25_POS))
#define LCD_DATA_COM0SEG26              ((uint32_t)1<<(LCD_DATA_COM0SEG26_POS))
#define LCD_DATA_COM0SEG27              ((uint32_t)1<<(LCD_DATA_COM0SEG27_POS))
#define LCD_DATA_COM0SEG28              ((uint32_t)1<<(LCD_DATA_COM0SEG28_POS))
#define LCD_DATA_COM0SEG29              ((uint32_t)1<<(LCD_DATA_COM0SEG29_POS))
#define LCD_DATA_COM0SEG30              ((uint32_t)1<<(LCD_DATA_COM0SEG30_POS))
#define LCD_DATA_COM0SEG31              ((uint32_t)1<<(LCD_DATA_COM0SEG31_POS))

/* LCD_DATA1 λ�� */
#define LCD_DATA_COM1SEG0_POS           (0)
#define LCD_DATA_COM1SEG1_POS           (1)
#define LCD_DATA_COM1SEG2_POS           (2)
#define LCD_DATA_COM1SEG3_POS           (3)
#define LCD_DATA_COM1SEG4_POS           (4)
#define LCD_DATA_COM1SEG5_POS           (5)
#define LCD_DATA_COM1SEG6_POS           (6)
#define LCD_DATA_COM1SEG7_POS           (7)
#define LCD_DATA_COM1SEG8_POS           (8)
#define LCD_DATA_COM1SEG9_POS           (9)
#define LCD_DATA_COM1SEG10_POS          (10)
#define LCD_DATA_COM1SEG11_POS          (11)
#define LCD_DATA_COM1SEG12_POS          (12)
#define LCD_DATA_COM1SEG13_POS          (13)
#define LCD_DATA_COM1SEG14_POS          (14)
#define LCD_DATA_COM1SEG15_POS          (15)
#define LCD_DATA_COM1SEG16_POS          (16)
#define LCD_DATA_COM1SEG17_POS          (17)
#define LCD_DATA_COM1SEG18_POS          (18)
#define LCD_DATA_COM1SEG19_POS          (19)
#define LCD_DATA_COM1SEG20_POS          (20)
#define LCD_DATA_COM1SEG21_POS          (21)
#define LCD_DATA_COM1SEG22_POS          (22)
#define LCD_DATA_COM1SEG23_POS          (23)
#define LCD_DATA_COM1SEG24_POS          (24)
#define LCD_DATA_COM1SEG25_POS          (25)
#define LCD_DATA_COM1SEG26_POS          (26)
#define LCD_DATA_COM1SEG27_POS          (27)
#define LCD_DATA_COM1SEG28_POS          (28)
#define LCD_DATA_COM1SEG29_POS          (29)
#define LCD_DATA_COM1SEG30_POS          (30)
#define LCD_DATA_COM1SEG31_POS          (31)
#define LCD_DATA_COM1SEG0               ((uint32_t)1<<(LCD_DATA_COM1SEG0_POS))
#define LCD_DATA_COM1SEG1               ((uint32_t)1<<(LCD_DATA_COM1SEG1_POS))
#define LCD_DATA_COM1SEG2               ((uint32_t)1<<(LCD_DATA_COM1SEG2_POS))
#define LCD_DATA_COM1SEG3               ((uint32_t)1<<(LCD_DATA_COM1SEG3_POS))
#define LCD_DATA_COM1SEG4               ((uint32_t)1<<(LCD_DATA_COM1SEG4_POS))
#define LCD_DATA_COM1SEG5               ((uint32_t)1<<(LCD_DATA_COM1SEG5_POS))
#define LCD_DATA_COM1SEG6               ((uint32_t)1<<(LCD_DATA_COM1SEG6_POS))
#define LCD_DATA_COM1SEG7               ((uint32_t)1<<(LCD_DATA_COM1SEG7_POS))
#define LCD_DATA_COM1SEG8               ((uint32_t)1<<(LCD_DATA_COM1SEG8_POS))
#define LCD_DATA_COM1SEG9               ((uint32_t)1<<(LCD_DATA_COM1SEG9_POS))
#define LCD_DATA_COM1SEG10              ((uint32_t)1<<(LCD_DATA_COM1SEG10_POS))
#define LCD_DATA_COM1SEG11              ((uint32_t)1<<(LCD_DATA_COM1SEG11_POS))
#define LCD_DATA_COM1SEG12              ((uint32_t)1<<(LCD_DATA_COM1SEG12_POS))
#define LCD_DATA_COM1SEG13              ((uint32_t)1<<(LCD_DATA_COM1SEG13_POS))
#define LCD_DATA_COM1SEG14              ((uint32_t)1<<(LCD_DATA_COM1SEG14_POS))
#define LCD_DATA_COM1SEG15              ((uint32_t)1<<(LCD_DATA_COM1SEG15_POS))
#define LCD_DATA_COM1SEG16              ((uint32_t)1<<(LCD_DATA_COM1SEG16_POS))
#define LCD_DATA_COM1SEG17              ((uint32_t)1<<(LCD_DATA_COM1SEG17_POS))
#define LCD_DATA_COM1SEG18              ((uint32_t)1<<(LCD_DATA_COM1SEG18_POS))
#define LCD_DATA_COM1SEG19              ((uint32_t)1<<(LCD_DATA_COM1SEG19_POS))
#define LCD_DATA_COM1SEG20              ((uint32_t)1<<(LCD_DATA_COM1SEG20_POS))
#define LCD_DATA_COM1SEG21              ((uint32_t)1<<(LCD_DATA_COM1SEG21_POS))
#define LCD_DATA_COM1SEG22              ((uint32_t)1<<(LCD_DATA_COM1SEG22_POS))
#define LCD_DATA_COM1SEG23              ((uint32_t)1<<(LCD_DATA_COM1SEG23_POS))
#define LCD_DATA_COM1SEG24              ((uint32_t)1<<(LCD_DATA_COM1SEG24_POS))
#define LCD_DATA_COM1SEG25              ((uint32_t)1<<(LCD_DATA_COM1SEG25_POS))
#define LCD_DATA_COM1SEG26              ((uint32_t)1<<(LCD_DATA_COM1SEG26_POS))
#define LCD_DATA_COM1SEG27              ((uint32_t)1<<(LCD_DATA_COM1SEG27_POS))
#define LCD_DATA_COM1SEG28              ((uint32_t)1<<(LCD_DATA_COM1SEG28_POS))
#define LCD_DATA_COM1SEG29              ((uint32_t)1<<(LCD_DATA_COM1SEG29_POS))
#define LCD_DATA_COM1SEG30              ((uint32_t)1<<(LCD_DATA_COM1SEG30_POS))
#define LCD_DATA_COM1SEG31              ((uint32_t)1<<(LCD_DATA_COM1SEG31_POS))

/* LCD_DATA2 λ�� */
#define LCD_DATA_COM2SEG0_POS           (0)
#define LCD_DATA_COM2SEG1_POS           (1)
#define LCD_DATA_COM2SEG2_POS           (2)
#define LCD_DATA_COM2SEG3_POS           (3)
#define LCD_DATA_COM2SEG4_POS           (4)
#define LCD_DATA_COM2SEG5_POS           (5)
#define LCD_DATA_COM2SEG6_POS           (6)
#define LCD_DATA_COM2SEG7_POS           (7)
#define LCD_DATA_COM2SEG8_POS           (8)
#define LCD_DATA_COM2SEG9_POS           (9)
#define LCD_DATA_COM2SEG10_POS          (10)
#define LCD_DATA_COM2SEG11_POS          (11)
#define LCD_DATA_COM2SEG12_POS          (12)
#define LCD_DATA_COM2SEG13_POS          (13)
#define LCD_DATA_COM2SEG14_POS          (14)
#define LCD_DATA_COM2SEG15_POS          (15)
#define LCD_DATA_COM2SEG16_POS          (16)
#define LCD_DATA_COM2SEG17_POS          (17)
#define LCD_DATA_COM2SEG18_POS          (18)
#define LCD_DATA_COM2SEG19_POS          (19)
#define LCD_DATA_COM2SEG20_POS          (20)
#define LCD_DATA_COM2SEG21_POS          (21)
#define LCD_DATA_COM2SEG22_POS          (22)
#define LCD_DATA_COM2SEG23_POS          (23)
#define LCD_DATA_COM2SEG24_POS          (24)
#define LCD_DATA_COM2SEG25_POS          (25)
#define LCD_DATA_COM2SEG26_POS          (26)
#define LCD_DATA_COM2SEG27_POS          (27)
#define LCD_DATA_COM2SEG28_POS          (28)
#define LCD_DATA_COM2SEG29_POS          (29)
#define LCD_DATA_COM2SEG30_POS          (30)
#define LCD_DATA_COM2SEG31_POS          (31)
#define LCD_DATA_COM2SEG0               ((uint32_t)1<<(LCD_DATA_COM2SEG0_POS))
#define LCD_DATA_COM2SEG1               ((uint32_t)1<<(LCD_DATA_COM2SEG1_POS))
#define LCD_DATA_COM2SEG2               ((uint32_t)1<<(LCD_DATA_COM2SEG2_POS))
#define LCD_DATA_COM2SEG3               ((uint32_t)1<<(LCD_DATA_COM2SEG3_POS))
#define LCD_DATA_COM2SEG4               ((uint32_t)1<<(LCD_DATA_COM2SEG4_POS))
#define LCD_DATA_COM2SEG5               ((uint32_t)1<<(LCD_DATA_COM2SEG5_POS))
#define LCD_DATA_COM2SEG6               ((uint32_t)1<<(LCD_DATA_COM2SEG6_POS))
#define LCD_DATA_COM2SEG7               ((uint32_t)1<<(LCD_DATA_COM2SEG7_POS))
#define LCD_DATA_COM2SEG8               ((uint32_t)1<<(LCD_DATA_COM2SEG8_POS))
#define LCD_DATA_COM2SEG9               ((uint32_t)1<<(LCD_DATA_COM2SEG9_POS))
#define LCD_DATA_COM2SEG10              ((uint32_t)1<<(LCD_DATA_COM2SEG10_POS))
#define LCD_DATA_COM2SEG11              ((uint32_t)1<<(LCD_DATA_COM2SEG11_POS))
#define LCD_DATA_COM2SEG12              ((uint32_t)1<<(LCD_DATA_COM2SEG12_POS))
#define LCD_DATA_COM2SEG13              ((uint32_t)1<<(LCD_DATA_COM2SEG13_POS))
#define LCD_DATA_COM2SEG14              ((uint32_t)1<<(LCD_DATA_COM2SEG14_POS))
#define LCD_DATA_COM2SEG15              ((uint32_t)1<<(LCD_DATA_COM2SEG15_POS))
#define LCD_DATA_COM2SEG16              ((uint32_t)1<<(LCD_DATA_COM2SEG16_POS))
#define LCD_DATA_COM2SEG17              ((uint32_t)1<<(LCD_DATA_COM2SEG17_POS))
#define LCD_DATA_COM2SEG18              ((uint32_t)1<<(LCD_DATA_COM2SEG18_POS))
#define LCD_DATA_COM2SEG19              ((uint32_t)1<<(LCD_DATA_COM2SEG19_POS))
#define LCD_DATA_COM2SEG20              ((uint32_t)1<<(LCD_DATA_COM2SEG20_POS))
#define LCD_DATA_COM2SEG21              ((uint32_t)1<<(LCD_DATA_COM2SEG21_POS))
#define LCD_DATA_COM2SEG22              ((uint32_t)1<<(LCD_DATA_COM2SEG22_POS))
#define LCD_DATA_COM2SEG23              ((uint32_t)1<<(LCD_DATA_COM2SEG23_POS))
#define LCD_DATA_COM2SEG24              ((uint32_t)1<<(LCD_DATA_COM2SEG24_POS))
#define LCD_DATA_COM2SEG25              ((uint32_t)1<<(LCD_DATA_COM2SEG25_POS))
#define LCD_DATA_COM2SEG26              ((uint32_t)1<<(LCD_DATA_COM2SEG26_POS))
#define LCD_DATA_COM2SEG27              ((uint32_t)1<<(LCD_DATA_COM2SEG27_POS))
#define LCD_DATA_COM2SEG28              ((uint32_t)1<<(LCD_DATA_COM2SEG28_POS))
#define LCD_DATA_COM2SEG29              ((uint32_t)1<<(LCD_DATA_COM2SEG29_POS))
#define LCD_DATA_COM2SEG30              ((uint32_t)1<<(LCD_DATA_COM2SEG30_POS))
#define LCD_DATA_COM2SEG31              ((uint32_t)1<<(LCD_DATA_COM2SEG31_POS))

/* LCD_DATA3 λ�� */
#define LCD_DATA_COM3SEG0_POS           (0)
#define LCD_DATA_COM3SEG1_POS           (1)
#define LCD_DATA_COM3SEG2_POS           (2)
#define LCD_DATA_COM3SEG3_POS           (3)
#define LCD_DATA_COM3SEG4_POS           (4)
#define LCD_DATA_COM3SEG5_POS           (5)
#define LCD_DATA_COM3SEG6_POS           (6)
#define LCD_DATA_COM3SEG7_POS           (7)
#define LCD_DATA_COM3SEG8_POS           (8)
#define LCD_DATA_COM3SEG9_POS           (9)
#define LCD_DATA_COM3SEG10_POS          (10)
#define LCD_DATA_COM3SEG11_POS          (11)
#define LCD_DATA_COM3SEG12_POS          (12)
#define LCD_DATA_COM3SEG13_POS          (13)
#define LCD_DATA_COM3SEG14_POS          (14)
#define LCD_DATA_COM3SEG15_POS          (15)
#define LCD_DATA_COM3SEG16_POS          (16)
#define LCD_DATA_COM3SEG17_POS          (17)
#define LCD_DATA_COM3SEG18_POS          (18)
#define LCD_DATA_COM3SEG19_POS          (19)
#define LCD_DATA_COM3SEG20_POS          (20)
#define LCD_DATA_COM3SEG21_POS          (21)
#define LCD_DATA_COM3SEG22_POS          (22)
#define LCD_DATA_COM3SEG23_POS          (23)
#define LCD_DATA_COM3SEG24_POS          (24)
#define LCD_DATA_COM3SEG25_POS          (25)
#define LCD_DATA_COM3SEG26_POS          (26)
#define LCD_DATA_COM3SEG27_POS          (27)
#define LCD_DATA_COM3SEG28_POS          (28)
#define LCD_DATA_COM3SEG29_POS          (29)
#define LCD_DATA_COM3SEG30_POS          (30)
#define LCD_DATA_COM3SEG31_POS          (31)
#define LCD_DATA_COM3SEG0               ((uint32_t)1<<(LCD_DATA_COM3SEG0_POS))
#define LCD_DATA_COM3SEG1               ((uint32_t)1<<(LCD_DATA_COM3SEG1_POS))
#define LCD_DATA_COM3SEG2               ((uint32_t)1<<(LCD_DATA_COM3SEG2_POS))
#define LCD_DATA_COM3SEG3               ((uint32_t)1<<(LCD_DATA_COM3SEG3_POS))
#define LCD_DATA_COM3SEG4               ((uint32_t)1<<(LCD_DATA_COM3SEG4_POS))
#define LCD_DATA_COM3SEG5               ((uint32_t)1<<(LCD_DATA_COM3SEG5_POS))
#define LCD_DATA_COM3SEG6               ((uint32_t)1<<(LCD_DATA_COM3SEG6_POS))
#define LCD_DATA_COM3SEG7               ((uint32_t)1<<(LCD_DATA_COM3SEG7_POS))
#define LCD_DATA_COM3SEG8               ((uint32_t)1<<(LCD_DATA_COM3SEG8_POS))
#define LCD_DATA_COM3SEG9               ((uint32_t)1<<(LCD_DATA_COM3SEG9_POS))
#define LCD_DATA_COM3SEG10              ((uint32_t)1<<(LCD_DATA_COM3SEG10_POS))
#define LCD_DATA_COM3SEG11              ((uint32_t)1<<(LCD_DATA_COM3SEG11_POS))
#define LCD_DATA_COM3SEG12              ((uint32_t)1<<(LCD_DATA_COM3SEG12_POS))
#define LCD_DATA_COM3SEG13              ((uint32_t)1<<(LCD_DATA_COM3SEG13_POS))
#define LCD_DATA_COM3SEG14              ((uint32_t)1<<(LCD_DATA_COM3SEG14_POS))
#define LCD_DATA_COM3SEG15              ((uint32_t)1<<(LCD_DATA_COM3SEG15_POS))
#define LCD_DATA_COM3SEG16              ((uint32_t)1<<(LCD_DATA_COM3SEG16_POS))
#define LCD_DATA_COM3SEG17              ((uint32_t)1<<(LCD_DATA_COM3SEG17_POS))
#define LCD_DATA_COM3SEG18              ((uint32_t)1<<(LCD_DATA_COM3SEG18_POS))
#define LCD_DATA_COM3SEG19              ((uint32_t)1<<(LCD_DATA_COM3SEG19_POS))
#define LCD_DATA_COM3SEG20              ((uint32_t)1<<(LCD_DATA_COM3SEG20_POS))
#define LCD_DATA_COM3SEG21              ((uint32_t)1<<(LCD_DATA_COM3SEG21_POS))
#define LCD_DATA_COM3SEG22              ((uint32_t)1<<(LCD_DATA_COM3SEG22_POS))
#define LCD_DATA_COM3SEG23              ((uint32_t)1<<(LCD_DATA_COM3SEG23_POS))
#define LCD_DATA_COM3SEG24              ((uint32_t)1<<(LCD_DATA_COM3SEG24_POS))
#define LCD_DATA_COM3SEG25              ((uint32_t)1<<(LCD_DATA_COM3SEG25_POS))
#define LCD_DATA_COM3SEG26              ((uint32_t)1<<(LCD_DATA_COM3SEG26_POS))
#define LCD_DATA_COM3SEG27              ((uint32_t)1<<(LCD_DATA_COM3SEG27_POS))
#define LCD_DATA_COM3SEG28              ((uint32_t)1<<(LCD_DATA_COM3SEG28_POS))
#define LCD_DATA_COM3SEG29              ((uint32_t)1<<(LCD_DATA_COM3SEG29_POS))
#define LCD_DATA_COM3SEG30              ((uint32_t)1<<(LCD_DATA_COM3SEG30_POS))
#define LCD_DATA_COM3SEG31              ((uint32_t)1<<(LCD_DATA_COM3SEG31_POS))

/* LCD_DATA4 λ�� */
#define LCD_DATA_COM4SEG0_POS           (0)
#define LCD_DATA_COM4SEG1_POS           (1)
#define LCD_DATA_COM4SEG2_POS           (2)
#define LCD_DATA_COM4SEG3_POS           (3)
#define LCD_DATA_COM4SEG4_POS           (4)
#define LCD_DATA_COM4SEG5_POS           (5)
#define LCD_DATA_COM4SEG6_POS           (6)
#define LCD_DATA_COM4SEG7_POS           (7)
#define LCD_DATA_COM4SEG8_POS           (8)
#define LCD_DATA_COM4SEG9_POS           (9)
#define LCD_DATA_COM4SEG10_POS          (10)
#define LCD_DATA_COM4SEG11_POS          (11)
#define LCD_DATA_COM4SEG12_POS          (12)
#define LCD_DATA_COM4SEG13_POS          (13)
#define LCD_DATA_COM4SEG14_POS          (14)
#define LCD_DATA_COM4SEG15_POS          (15)
#define LCD_DATA_COM4SEG16_POS          (16)
#define LCD_DATA_COM4SEG17_POS          (17)
#define LCD_DATA_COM4SEG18_POS          (18)
#define LCD_DATA_COM4SEG19_POS          (19)
#define LCD_DATA_COM4SEG20_POS          (20)
#define LCD_DATA_COM4SEG21_POS          (21)
#define LCD_DATA_COM4SEG22_POS          (22)
#define LCD_DATA_COM4SEG23_POS          (23)
#define LCD_DATA_COM4SEG24_POS          (24)
#define LCD_DATA_COM4SEG25_POS          (25)
#define LCD_DATA_COM4SEG26_POS          (26)
#define LCD_DATA_COM4SEG27_POS          (27)
#define LCD_DATA_COM4SEG28_POS          (28)
#define LCD_DATA_COM4SEG29_POS          (29)
#define LCD_DATA_COM4SEG30_POS          (30)
#define LCD_DATA_COM4SEG31_POS          (31)
#define LCD_DATA_COM4SEG0               ((uint32_t)1<<(LCD_DATA_COM4SEG0_POS))
#define LCD_DATA_COM4SEG1               ((uint32_t)1<<(LCD_DATA_COM4SEG1_POS))
#define LCD_DATA_COM4SEG2               ((uint32_t)1<<(LCD_DATA_COM4SEG2_POS))
#define LCD_DATA_COM4SEG3               ((uint32_t)1<<(LCD_DATA_COM4SEG3_POS))
#define LCD_DATA_COM4SEG4               ((uint32_t)1<<(LCD_DATA_COM4SEG4_POS))
#define LCD_DATA_COM4SEG5               ((uint32_t)1<<(LCD_DATA_COM4SEG5_POS))
#define LCD_DATA_COM4SEG6               ((uint32_t)1<<(LCD_DATA_COM4SEG6_POS))
#define LCD_DATA_COM4SEG7               ((uint32_t)1<<(LCD_DATA_COM4SEG7_POS))
#define LCD_DATA_COM4SEG8               ((uint32_t)1<<(LCD_DATA_COM4SEG8_POS))
#define LCD_DATA_COM4SEG9               ((uint32_t)1<<(LCD_DATA_COM4SEG9_POS))
#define LCD_DATA_COM4SEG10              ((uint32_t)1<<(LCD_DATA_COM4SEG10_POS))
#define LCD_DATA_COM4SEG11              ((uint32_t)1<<(LCD_DATA_COM4SEG11_POS))
#define LCD_DATA_COM4SEG12              ((uint32_t)1<<(LCD_DATA_COM4SEG12_POS))
#define LCD_DATA_COM4SEG13              ((uint32_t)1<<(LCD_DATA_COM4SEG13_POS))
#define LCD_DATA_COM4SEG14              ((uint32_t)1<<(LCD_DATA_COM4SEG14_POS))
#define LCD_DATA_COM4SEG15              ((uint32_t)1<<(LCD_DATA_COM4SEG15_POS))
#define LCD_DATA_COM4SEG16              ((uint32_t)1<<(LCD_DATA_COM4SEG16_POS))
#define LCD_DATA_COM4SEG17              ((uint32_t)1<<(LCD_DATA_COM4SEG17_POS))
#define LCD_DATA_COM4SEG18              ((uint32_t)1<<(LCD_DATA_COM4SEG18_POS))
#define LCD_DATA_COM4SEG19              ((uint32_t)1<<(LCD_DATA_COM4SEG19_POS))
#define LCD_DATA_COM4SEG20              ((uint32_t)1<<(LCD_DATA_COM4SEG20_POS))
#define LCD_DATA_COM4SEG21              ((uint32_t)1<<(LCD_DATA_COM4SEG21_POS))
#define LCD_DATA_COM4SEG22              ((uint32_t)1<<(LCD_DATA_COM4SEG22_POS))
#define LCD_DATA_COM4SEG23              ((uint32_t)1<<(LCD_DATA_COM4SEG23_POS))
#define LCD_DATA_COM4SEG24              ((uint32_t)1<<(LCD_DATA_COM4SEG24_POS))
#define LCD_DATA_COM4SEG25              ((uint32_t)1<<(LCD_DATA_COM4SEG25_POS))
#define LCD_DATA_COM4SEG26              ((uint32_t)1<<(LCD_DATA_COM4SEG26_POS))
#define LCD_DATA_COM4SEG27              ((uint32_t)1<<(LCD_DATA_COM4SEG27_POS))
#define LCD_DATA_COM4SEG28              ((uint32_t)1<<(LCD_DATA_COM4SEG28_POS))
#define LCD_DATA_COM4SEG29              ((uint32_t)1<<(LCD_DATA_COM4SEG29_POS))
#define LCD_DATA_COM4SEG30              ((uint32_t)1<<(LCD_DATA_COM4SEG30_POS))
#define LCD_DATA_COM4SEG31              ((uint32_t)1<<(LCD_DATA_COM4SEG31_POS))

/* LCD_DATA5 λ�� */
#define LCD_DATA_COM5SEG0_POS           (0)
#define LCD_DATA_COM5SEG1_POS           (1)
#define LCD_DATA_COM5SEG2_POS           (2)
#define LCD_DATA_COM5SEG3_POS           (3)
#define LCD_DATA_COM5SEG4_POS           (4)
#define LCD_DATA_COM5SEG5_POS           (5)
#define LCD_DATA_COM5SEG6_POS           (6)
#define LCD_DATA_COM5SEG7_POS           (7)
#define LCD_DATA_COM5SEG8_POS           (8)
#define LCD_DATA_COM5SEG9_POS           (9)
#define LCD_DATA_COM5SEG10_POS          (10)
#define LCD_DATA_COM5SEG11_POS          (11)
#define LCD_DATA_COM5SEG12_POS          (12)
#define LCD_DATA_COM5SEG13_POS          (13)
#define LCD_DATA_COM5SEG14_POS          (14)
#define LCD_DATA_COM5SEG15_POS          (15)
#define LCD_DATA_COM5SEG16_POS          (16)
#define LCD_DATA_COM5SEG17_POS          (17)
#define LCD_DATA_COM5SEG18_POS          (18)
#define LCD_DATA_COM5SEG19_POS          (19)
#define LCD_DATA_COM5SEG20_POS          (20)
#define LCD_DATA_COM5SEG21_POS          (21)
#define LCD_DATA_COM5SEG22_POS          (22)
#define LCD_DATA_COM5SEG23_POS          (23)
#define LCD_DATA_COM5SEG24_POS          (24)
#define LCD_DATA_COM5SEG25_POS          (25)
#define LCD_DATA_COM5SEG26_POS          (26)
#define LCD_DATA_COM5SEG27_POS          (27)
#define LCD_DATA_COM5SEG28_POS          (28)
#define LCD_DATA_COM5SEG29_POS          (29)
#define LCD_DATA_COM5SEG30_POS          (30)
#define LCD_DATA_COM5SEG31_POS          (31)
#define LCD_DATA_COM5SEG0               ((uint32_t)1<<(LCD_DATA_COM5SEG0_POS))
#define LCD_DATA_COM5SEG1               ((uint32_t)1<<(LCD_DATA_COM5SEG1_POS))
#define LCD_DATA_COM5SEG2               ((uint32_t)1<<(LCD_DATA_COM5SEG2_POS))
#define LCD_DATA_COM5SEG3               ((uint32_t)1<<(LCD_DATA_COM5SEG3_POS))
#define LCD_DATA_COM5SEG4               ((uint32_t)1<<(LCD_DATA_COM5SEG4_POS))
#define LCD_DATA_COM5SEG5               ((uint32_t)1<<(LCD_DATA_COM5SEG5_POS))
#define LCD_DATA_COM5SEG6               ((uint32_t)1<<(LCD_DATA_COM5SEG6_POS))
#define LCD_DATA_COM5SEG7               ((uint32_t)1<<(LCD_DATA_COM5SEG7_POS))
#define LCD_DATA_COM5SEG8               ((uint32_t)1<<(LCD_DATA_COM5SEG8_POS))
#define LCD_DATA_COM5SEG9               ((uint32_t)1<<(LCD_DATA_COM5SEG9_POS))
#define LCD_DATA_COM5SEG10              ((uint32_t)1<<(LCD_DATA_COM5SEG10_POS))
#define LCD_DATA_COM5SEG11              ((uint32_t)1<<(LCD_DATA_COM5SEG11_POS))
#define LCD_DATA_COM5SEG12              ((uint32_t)1<<(LCD_DATA_COM5SEG12_POS))
#define LCD_DATA_COM5SEG13              ((uint32_t)1<<(LCD_DATA_COM5SEG13_POS))
#define LCD_DATA_COM5SEG14              ((uint32_t)1<<(LCD_DATA_COM5SEG14_POS))
#define LCD_DATA_COM5SEG15              ((uint32_t)1<<(LCD_DATA_COM5SEG15_POS))
#define LCD_DATA_COM5SEG16              ((uint32_t)1<<(LCD_DATA_COM5SEG16_POS))
#define LCD_DATA_COM5SEG17              ((uint32_t)1<<(LCD_DATA_COM5SEG17_POS))
#define LCD_DATA_COM5SEG18              ((uint32_t)1<<(LCD_DATA_COM5SEG18_POS))
#define LCD_DATA_COM5SEG19              ((uint32_t)1<<(LCD_DATA_COM5SEG19_POS))
#define LCD_DATA_COM5SEG20              ((uint32_t)1<<(LCD_DATA_COM5SEG20_POS))
#define LCD_DATA_COM5SEG21              ((uint32_t)1<<(LCD_DATA_COM5SEG21_POS))
#define LCD_DATA_COM5SEG22              ((uint32_t)1<<(LCD_DATA_COM5SEG22_POS))
#define LCD_DATA_COM5SEG23              ((uint32_t)1<<(LCD_DATA_COM5SEG23_POS))
#define LCD_DATA_COM5SEG24              ((uint32_t)1<<(LCD_DATA_COM5SEG24_POS))
#define LCD_DATA_COM5SEG25              ((uint32_t)1<<(LCD_DATA_COM5SEG25_POS))
#define LCD_DATA_COM5SEG26              ((uint32_t)1<<(LCD_DATA_COM5SEG26_POS))
#define LCD_DATA_COM5SEG27              ((uint32_t)1<<(LCD_DATA_COM5SEG27_POS))
#define LCD_DATA_COM5SEG28              ((uint32_t)1<<(LCD_DATA_COM5SEG28_POS))
#define LCD_DATA_COM5SEG29              ((uint32_t)1<<(LCD_DATA_COM5SEG29_POS))
#define LCD_DATA_COM5SEG30              ((uint32_t)1<<(LCD_DATA_COM5SEG30_POS))
#define LCD_DATA_COM5SEG31              ((uint32_t)1<<(LCD_DATA_COM5SEG31_POS))

/* LCD_DATA6 λ�� */
#define LCD_DATA_COM6SEG0_POS           (0)
#define LCD_DATA_COM6SEG1_POS           (1)
#define LCD_DATA_COM6SEG2_POS           (2)
#define LCD_DATA_COM6SEG3_POS           (3)
#define LCD_DATA_COM6SEG4_POS           (4)
#define LCD_DATA_COM6SEG5_POS           (5)
#define LCD_DATA_COM6SEG6_POS           (6)
#define LCD_DATA_COM6SEG7_POS           (7)
#define LCD_DATA_COM6SEG8_POS           (8)
#define LCD_DATA_COM6SEG9_POS           (9)
#define LCD_DATA_COM6SEG10_POS          (10)
#define LCD_DATA_COM6SEG11_POS          (11)
#define LCD_DATA_COM6SEG12_POS          (12)
#define LCD_DATA_COM6SEG13_POS          (13)
#define LCD_DATA_COM6SEG14_POS          (14)
#define LCD_DATA_COM6SEG15_POS          (15)
#define LCD_DATA_COM6SEG16_POS          (16)
#define LCD_DATA_COM6SEG17_POS          (17)
#define LCD_DATA_COM6SEG18_POS          (18)
#define LCD_DATA_COM6SEG19_POS          (19)
#define LCD_DATA_COM6SEG20_POS          (20)
#define LCD_DATA_COM6SEG21_POS          (21)
#define LCD_DATA_COM6SEG22_POS          (22)
#define LCD_DATA_COM6SEG23_POS          (23)
#define LCD_DATA_COM6SEG24_POS          (24)
#define LCD_DATA_COM6SEG25_POS          (25)
#define LCD_DATA_COM6SEG26_POS          (26)
#define LCD_DATA_COM6SEG27_POS          (27)
#define LCD_DATA_COM6SEG28_POS          (28)
#define LCD_DATA_COM6SEG29_POS          (29)
#define LCD_DATA_COM6SEG30_POS          (30)
#define LCD_DATA_COM6SEG31_POS          (31)
#define LCD_DATA_COM6SEG0               ((uint32_t)1<<(LCD_DATA_COM6SEG0_POS))
#define LCD_DATA_COM6SEG1               ((uint32_t)1<<(LCD_DATA_COM6SEG1_POS))
#define LCD_DATA_COM6SEG2               ((uint32_t)1<<(LCD_DATA_COM6SEG2_POS))
#define LCD_DATA_COM6SEG3               ((uint32_t)1<<(LCD_DATA_COM6SEG3_POS))
#define LCD_DATA_COM6SEG4               ((uint32_t)1<<(LCD_DATA_COM6SEG4_POS))
#define LCD_DATA_COM6SEG5               ((uint32_t)1<<(LCD_DATA_COM6SEG5_POS))
#define LCD_DATA_COM6SEG6               ((uint32_t)1<<(LCD_DATA_COM6SEG6_POS))
#define LCD_DATA_COM6SEG7               ((uint32_t)1<<(LCD_DATA_COM6SEG7_POS))
#define LCD_DATA_COM6SEG8               ((uint32_t)1<<(LCD_DATA_COM6SEG8_POS))
#define LCD_DATA_COM6SEG9               ((uint32_t)1<<(LCD_DATA_COM6SEG9_POS))
#define LCD_DATA_COM6SEG10              ((uint32_t)1<<(LCD_DATA_COM6SEG10_POS))
#define LCD_DATA_COM6SEG11              ((uint32_t)1<<(LCD_DATA_COM6SEG11_POS))
#define LCD_DATA_COM6SEG12              ((uint32_t)1<<(LCD_DATA_COM6SEG12_POS))
#define LCD_DATA_COM6SEG13              ((uint32_t)1<<(LCD_DATA_COM6SEG13_POS))
#define LCD_DATA_COM6SEG14              ((uint32_t)1<<(LCD_DATA_COM6SEG14_POS))
#define LCD_DATA_COM6SEG15              ((uint32_t)1<<(LCD_DATA_COM6SEG15_POS))
#define LCD_DATA_COM6SEG16              ((uint32_t)1<<(LCD_DATA_COM6SEG16_POS))
#define LCD_DATA_COM6SEG17              ((uint32_t)1<<(LCD_DATA_COM6SEG17_POS))
#define LCD_DATA_COM6SEG18              ((uint32_t)1<<(LCD_DATA_COM6SEG18_POS))
#define LCD_DATA_COM6SEG19              ((uint32_t)1<<(LCD_DATA_COM6SEG19_POS))
#define LCD_DATA_COM6SEG20              ((uint32_t)1<<(LCD_DATA_COM6SEG20_POS))
#define LCD_DATA_COM6SEG21              ((uint32_t)1<<(LCD_DATA_COM6SEG21_POS))
#define LCD_DATA_COM6SEG22              ((uint32_t)1<<(LCD_DATA_COM6SEG22_POS))
#define LCD_DATA_COM6SEG23              ((uint32_t)1<<(LCD_DATA_COM6SEG23_POS))
#define LCD_DATA_COM6SEG24              ((uint32_t)1<<(LCD_DATA_COM6SEG24_POS))
#define LCD_DATA_COM6SEG25              ((uint32_t)1<<(LCD_DATA_COM6SEG25_POS))
#define LCD_DATA_COM6SEG26              ((uint32_t)1<<(LCD_DATA_COM6SEG26_POS))
#define LCD_DATA_COM6SEG27              ((uint32_t)1<<(LCD_DATA_COM6SEG27_POS))
#define LCD_DATA_COM6SEG28              ((uint32_t)1<<(LCD_DATA_COM6SEG28_POS))
#define LCD_DATA_COM6SEG29              ((uint32_t)1<<(LCD_DATA_COM6SEG29_POS))
#define LCD_DATA_COM6SEG30              ((uint32_t)1<<(LCD_DATA_COM6SEG30_POS))
#define LCD_DATA_COM6SEG31              ((uint32_t)1<<(LCD_DATA_COM6SEG31_POS))

/* LCD_DATA7 λ�� */
#define LCD_DATA_COM7SEG0_POS           (0)
#define LCD_DATA_COM7SEG1_POS           (1)
#define LCD_DATA_COM7SEG2_POS           (2)
#define LCD_DATA_COM7SEG3_POS           (3)
#define LCD_DATA_COM7SEG4_POS           (4)
#define LCD_DATA_COM7SEG5_POS           (5)
#define LCD_DATA_COM7SEG6_POS           (6)
#define LCD_DATA_COM7SEG7_POS           (7)
#define LCD_DATA_COM7SEG8_POS           (8)
#define LCD_DATA_COM7SEG9_POS           (9)
#define LCD_DATA_COM7SEG10_POS          (10)
#define LCD_DATA_COM7SEG11_POS          (11)
#define LCD_DATA_COM7SEG12_POS          (12)
#define LCD_DATA_COM7SEG13_POS          (13)
#define LCD_DATA_COM7SEG14_POS          (14)
#define LCD_DATA_COM7SEG15_POS          (15)
#define LCD_DATA_COM7SEG16_POS          (16)
#define LCD_DATA_COM7SEG17_POS          (17)
#define LCD_DATA_COM7SEG18_POS          (18)
#define LCD_DATA_COM7SEG19_POS          (19)
#define LCD_DATA_COM7SEG20_POS          (20)
#define LCD_DATA_COM7SEG21_POS          (21)
#define LCD_DATA_COM7SEG22_POS          (22)
#define LCD_DATA_COM7SEG23_POS          (23)
#define LCD_DATA_COM7SEG24_POS          (24)
#define LCD_DATA_COM7SEG25_POS          (25)
#define LCD_DATA_COM7SEG26_POS          (26)
#define LCD_DATA_COM7SEG27_POS          (27)
#define LCD_DATA_COM7SEG28_POS          (28)
#define LCD_DATA_COM7SEG29_POS          (29)
#define LCD_DATA_COM7SEG30_POS          (30)
#define LCD_DATA_COM7SEG31_POS          (31)
#define LCD_DATA_COM7SEG0               ((uint32_t)1<<(LCD_DATA_COM7SEG0_POS))
#define LCD_DATA_COM7SEG1               ((uint32_t)1<<(LCD_DATA_COM7SEG1_POS))
#define LCD_DATA_COM7SEG2               ((uint32_t)1<<(LCD_DATA_COM7SEG2_POS))
#define LCD_DATA_COM7SEG3               ((uint32_t)1<<(LCD_DATA_COM7SEG3_POS))
#define LCD_DATA_COM7SEG4               ((uint32_t)1<<(LCD_DATA_COM7SEG4_POS))
#define LCD_DATA_COM7SEG5               ((uint32_t)1<<(LCD_DATA_COM7SEG5_POS))
#define LCD_DATA_COM7SEG6               ((uint32_t)1<<(LCD_DATA_COM7SEG6_POS))
#define LCD_DATA_COM7SEG7               ((uint32_t)1<<(LCD_DATA_COM7SEG7_POS))
#define LCD_DATA_COM7SEG8               ((uint32_t)1<<(LCD_DATA_COM7SEG8_POS))
#define LCD_DATA_COM7SEG9               ((uint32_t)1<<(LCD_DATA_COM7SEG9_POS))
#define LCD_DATA_COM7SEG10              ((uint32_t)1<<(LCD_DATA_COM7SEG10_POS))
#define LCD_DATA_COM7SEG11              ((uint32_t)1<<(LCD_DATA_COM7SEG11_POS))
#define LCD_DATA_COM7SEG12              ((uint32_t)1<<(LCD_DATA_COM7SEG12_POS))
#define LCD_DATA_COM7SEG13              ((uint32_t)1<<(LCD_DATA_COM7SEG13_POS))
#define LCD_DATA_COM7SEG14              ((uint32_t)1<<(LCD_DATA_COM7SEG14_POS))
#define LCD_DATA_COM7SEG15              ((uint32_t)1<<(LCD_DATA_COM7SEG15_POS))
#define LCD_DATA_COM7SEG16              ((uint32_t)1<<(LCD_DATA_COM7SEG16_POS))
#define LCD_DATA_COM7SEG17              ((uint32_t)1<<(LCD_DATA_COM7SEG17_POS))
#define LCD_DATA_COM7SEG18              ((uint32_t)1<<(LCD_DATA_COM7SEG18_POS))
#define LCD_DATA_COM7SEG19              ((uint32_t)1<<(LCD_DATA_COM7SEG19_POS))
#define LCD_DATA_COM7SEG20              ((uint32_t)1<<(LCD_DATA_COM7SEG20_POS))
#define LCD_DATA_COM7SEG21              ((uint32_t)1<<(LCD_DATA_COM7SEG21_POS))
#define LCD_DATA_COM7SEG22              ((uint32_t)1<<(LCD_DATA_COM7SEG22_POS))
#define LCD_DATA_COM7SEG23              ((uint32_t)1<<(LCD_DATA_COM7SEG23_POS))
#define LCD_DATA_COM7SEG24              ((uint32_t)1<<(LCD_DATA_COM7SEG24_POS))
#define LCD_DATA_COM7SEG25              ((uint32_t)1<<(LCD_DATA_COM7SEG25_POS))
#define LCD_DATA_COM7SEG26              ((uint32_t)1<<(LCD_DATA_COM7SEG26_POS))
#define LCD_DATA_COM7SEG27              ((uint32_t)1<<(LCD_DATA_COM7SEG27_POS))
#define LCD_DATA_COM7SEG28              ((uint32_t)1<<(LCD_DATA_COM7SEG28_POS))
#define LCD_DATA_COM7SEG29              ((uint32_t)1<<(LCD_DATA_COM7SEG29_POS))
#define LCD_DATA_COM7SEG30              ((uint32_t)1<<(LCD_DATA_COM7SEG30_POS))
#define LCD_DATA_COM7SEG31              ((uint32_t)1<<(LCD_DATA_COM7SEG31_POS))

/* LCD_DATA8 λ�� */
#define LCD_DATA_COM0SEG32_POS          (0)
#define LCD_DATA_COM0SEG33_POS          (1)
#define LCD_DATA_COM0SEG34_POS          (2)
#define LCD_DATA_COM0SEG35_POS          (3)
#define LCD_DATA_COM0SEG36_POS          (4)
#define LCD_DATA_COM0SEG37_POS          (5)
#define LCD_DATA_COM0SEG38_POS          (6)
#define LCD_DATA_COM0SEG39_POS          (7)
#define LCD_DATA_COM1SEG32_POS          (8)
#define LCD_DATA_COM1SEG33_POS          (9)
#define LCD_DATA_COM1SEG34_POS          (10)
#define LCD_DATA_COM1SEG35_POS          (11)
#define LCD_DATA_COM1SEG36_POS          (12)
#define LCD_DATA_COM1SEG37_POS          (13)
#define LCD_DATA_COM1SEG38_POS          (14)
#define LCD_DATA_COM1SEG39_POS          (15)
#define LCD_DATA_COM2SEG32_POS          (16)
#define LCD_DATA_COM2SEG33_POS          (17)
#define LCD_DATA_COM2SEG34_POS          (18)
#define LCD_DATA_COM2SEG35_POS          (19)
#define LCD_DATA_COM2SEG36_POS          (20)
#define LCD_DATA_COM2SEG37_POS          (21)
#define LCD_DATA_COM2SEG38_POS          (22)
#define LCD_DATA_COM2SEG39_POS          (23)
#define LCD_DATA_COM3SEG32_POS          (24)
#define LCD_DATA_COM3SEG33_POS          (25)
#define LCD_DATA_COM3SEG34_POS          (26)
#define LCD_DATA_COM3SEG35_POS          (27)
#define LCD_DATA_COM3SEG36_POS          (28)
#define LCD_DATA_COM3SEG37_POS          (29)
#define LCD_DATA_COM3SEG38_POS          (30)
#define LCD_DATA_COM3SEG39_POS          (31)
#define LCD_DATA_COM0SEG32              ((uint32_t)1<<(LCD_DATA_COM0SEG32_POS))
#define LCD_DATA_COM0SEG33              ((uint32_t)1<<(LCD_DATA_COM0SEG33_POS))
#define LCD_DATA_COM0SEG34              ((uint32_t)1<<(LCD_DATA_COM0SEG34_POS))
#define LCD_DATA_COM0SEG35              ((uint32_t)1<<(LCD_DATA_COM0SEG35_POS))
#define LCD_DATA_COM0SEG36              ((uint32_t)1<<(LCD_DATA_COM0SEG36_POS))
#define LCD_DATA_COM0SEG37              ((uint32_t)1<<(LCD_DATA_COM0SEG37_POS))
#define LCD_DATA_COM0SEG38              ((uint32_t)1<<(LCD_DATA_COM0SEG38_POS))
#define LCD_DATA_COM0SEG39              ((uint32_t)1<<(LCD_DATA_COM0SEG39_POS))
#define LCD_DATA_COM1SEG32              ((uint32_t)1<<(LCD_DATA_COM1SEG32_POS))
#define LCD_DATA_COM1SEG33              ((uint32_t)1<<(LCD_DATA_COM1SEG33_POS))
#define LCD_DATA_COM1SEG34              ((uint32_t)1<<(LCD_DATA_COM1SEG34_POS))
#define LCD_DATA_COM1SEG35              ((uint32_t)1<<(LCD_DATA_COM1SEG35_POS))
#define LCD_DATA_COM1SEG36              ((uint32_t)1<<(LCD_DATA_COM1SEG36_POS))
#define LCD_DATA_COM1SEG37              ((uint32_t)1<<(LCD_DATA_COM1SEG37_POS))
#define LCD_DATA_COM1SEG38              ((uint32_t)1<<(LCD_DATA_COM1SEG38_POS))
#define LCD_DATA_COM1SEG39              ((uint32_t)1<<(LCD_DATA_COM1SEG39_POS))
#define LCD_DATA_COM2SEG32              ((uint32_t)1<<(LCD_DATA_COM2SEG32_POS))
#define LCD_DATA_COM2SEG33              ((uint32_t)1<<(LCD_DATA_COM2SEG33_POS))
#define LCD_DATA_COM2SEG34              ((uint32_t)1<<(LCD_DATA_COM2SEG34_POS))
#define LCD_DATA_COM2SEG35              ((uint32_t)1<<(LCD_DATA_COM2SEG35_POS))
#define LCD_DATA_COM2SEG36              ((uint32_t)1<<(LCD_DATA_COM2SEG36_POS))
#define LCD_DATA_COM2SEG37              ((uint32_t)1<<(LCD_DATA_COM2SEG37_POS))
#define LCD_DATA_COM2SEG38              ((uint32_t)1<<(LCD_DATA_COM2SEG38_POS))
#define LCD_DATA_COM2SEG39              ((uint32_t)1<<(LCD_DATA_COM2SEG39_POS))
#define LCD_DATA_COM3SEG32              ((uint32_t)1<<(LCD_DATA_COM3SEG32_POS))
#define LCD_DATA_COM3SEG33              ((uint32_t)1<<(LCD_DATA_COM3SEG33_POS))
#define LCD_DATA_COM3SEG34              ((uint32_t)1<<(LCD_DATA_COM3SEG34_POS))
#define LCD_DATA_COM3SEG35              ((uint32_t)1<<(LCD_DATA_COM3SEG35_POS))
#define LCD_DATA_COM3SEG36              ((uint32_t)1<<(LCD_DATA_COM3SEG36_POS))
#define LCD_DATA_COM3SEG37              ((uint32_t)1<<(LCD_DATA_COM3SEG37_POS))
#define LCD_DATA_COM3SEG38              ((uint32_t)1<<(LCD_DATA_COM3SEG38_POS))
#define LCD_DATA_COM3SEG39              ((uint32_t)1<<(LCD_DATA_COM3SEG39_POS))

/* LCD_DATA9 λ�� */
#define LCD_DATA_COM4SEG32_POS          (0)
#define LCD_DATA_COM4SEG33_POS          (1)
#define LCD_DATA_COM4SEG34_POS          (2)
#define LCD_DATA_COM4SEG35_POS          (3)
#define LCD_DATA_COM4SEG36_POS          (4)
#define LCD_DATA_COM4SEG37_POS          (5)
#define LCD_DATA_COM4SEG38_POS          (6)
#define LCD_DATA_COM4SEG39_POS          (7)
#define LCD_DATA_COM5SEG32_POS          (8)
#define LCD_DATA_COM5SEG33_POS          (9)
#define LCD_DATA_COM5SEG34_POS          (10)
#define LCD_DATA_COM5SEG35_POS          (11)
#define LCD_DATA_COM5SEG36_POS          (12)
#define LCD_DATA_COM5SEG37_POS          (13)
#define LCD_DATA_COM5SEG38_POS          (14)
#define LCD_DATA_COM5SEG39_POS          (15)
#define LCD_DATA_COM6SEG32_POS          (16)
#define LCD_DATA_COM6SEG33_POS          (17)
#define LCD_DATA_COM6SEG34_POS          (18)
#define LCD_DATA_COM6SEG35_POS          (19)
#define LCD_DATA_COM6SEG36_POS          (20)
#define LCD_DATA_COM6SEG37_POS          (21)
#define LCD_DATA_COM6SEG38_POS          (22)
#define LCD_DATA_COM6SEG39_POS          (23)
#define LCD_DATA_COM7SEG32_POS          (24)
#define LCD_DATA_COM7SEG33_POS          (25)
#define LCD_DATA_COM7SEG34_POS          (26)
#define LCD_DATA_COM7SEG35_POS          (27)
#define LCD_DATA_COM7SEG36_POS          (28)
#define LCD_DATA_COM7SEG37_POS          (29)
#define LCD_DATA_COM7SEG38_POS          (30)
#define LCD_DATA_COM7SEG39_POS          (31)
#define LCD_DATA_COM4SEG32              ((uint32_t)1<<(LCD_DATA_COM4SEG32_POS))
#define LCD_DATA_COM4SEG33              ((uint32_t)1<<(LCD_DATA_COM4SEG33_POS))
#define LCD_DATA_COM4SEG34              ((uint32_t)1<<(LCD_DATA_COM4SEG34_POS))
#define LCD_DATA_COM4SEG35              ((uint32_t)1<<(LCD_DATA_COM4SEG35_POS))
#define LCD_DATA_COM4SEG36              ((uint32_t)1<<(LCD_DATA_COM4SEG36_POS))
#define LCD_DATA_COM4SEG37              ((uint32_t)1<<(LCD_DATA_COM4SEG37_POS))
#define LCD_DATA_COM4SEG38              ((uint32_t)1<<(LCD_DATA_COM4SEG38_POS))
#define LCD_DATA_COM4SEG39              ((uint32_t)1<<(LCD_DATA_COM4SEG39_POS))
#define LCD_DATA_COM5SEG32              ((uint32_t)1<<(LCD_DATA_COM5SEG32_POS))
#define LCD_DATA_COM5SEG33              ((uint32_t)1<<(LCD_DATA_COM5SEG33_POS))
#define LCD_DATA_COM5SEG34              ((uint32_t)1<<(LCD_DATA_COM5SEG34_POS))
#define LCD_DATA_COM5SEG35              ((uint32_t)1<<(LCD_DATA_COM5SEG35_POS))
#define LCD_DATA_COM5SEG36              ((uint32_t)1<<(LCD_DATA_COM5SEG36_POS))
#define LCD_DATA_COM5SEG37              ((uint32_t)1<<(LCD_DATA_COM5SEG37_POS))
#define LCD_DATA_COM5SEG38              ((uint32_t)1<<(LCD_DATA_COM5SEG38_POS))
#define LCD_DATA_COM5SEG39              ((uint32_t)1<<(LCD_DATA_COM5SEG39_POS))
#define LCD_DATA_COM6SEG32              ((uint32_t)1<<(LCD_DATA_COM6SEG32_POS))
#define LCD_DATA_COM6SEG33              ((uint32_t)1<<(LCD_DATA_COM6SEG33_POS))
#define LCD_DATA_COM6SEG34              ((uint32_t)1<<(LCD_DATA_COM6SEG34_POS))
#define LCD_DATA_COM6SEG35              ((uint32_t)1<<(LCD_DATA_COM6SEG35_POS))
#define LCD_DATA_COM6SEG36              ((uint32_t)1<<(LCD_DATA_COM6SEG36_POS))
#define LCD_DATA_COM6SEG37              ((uint32_t)1<<(LCD_DATA_COM6SEG37_POS))
#define LCD_DATA_COM6SEG38              ((uint32_t)1<<(LCD_DATA_COM6SEG38_POS))
#define LCD_DATA_COM6SEG39              ((uint32_t)1<<(LCD_DATA_COM6SEG39_POS))
#define LCD_DATA_COM7SEG32              ((uint32_t)1<<(LCD_DATA_COM7SEG32_POS))
#define LCD_DATA_COM7SEG33              ((uint32_t)1<<(LCD_DATA_COM7SEG33_POS))
#define LCD_DATA_COM7SEG34              ((uint32_t)1<<(LCD_DATA_COM7SEG34_POS))
#define LCD_DATA_COM7SEG35              ((uint32_t)1<<(LCD_DATA_COM7SEG35_POS))
#define LCD_DATA_COM7SEG36              ((uint32_t)1<<(LCD_DATA_COM7SEG36_POS))
#define LCD_DATA_COM7SEG37              ((uint32_t)1<<(LCD_DATA_COM7SEG37_POS))
#define LCD_DATA_COM7SEG38              ((uint32_t)1<<(LCD_DATA_COM7SEG38_POS))
#define LCD_DATA_COM7SEG39              ((uint32_t)1<<(LCD_DATA_COM7SEG39_POS))

/* LCD_DATA10 λ�� */
#define LCD_DATA_COM0SEG40_POS          (0)
#define LCD_DATA_COM0SEG41_POS          (1)
#define LCD_DATA_COM0SEG42_POS          (2)
#define LCD_DATA_COM0SEG43_POS          (3)
#define LCD_DATA_COM0SEG44_POS          (4)
#define LCD_DATA_COM0SEG45_POS          (5)
#define LCD_DATA_COM0SEG46_POS          (6)
#define LCD_DATA_COM0SEG47_POS          (7)
#define LCD_DATA_COM1SEG40_POS          (8)
#define LCD_DATA_COM1SEG41_POS          (9)
#define LCD_DATA_COM1SEG42_POS          (10)
#define LCD_DATA_COM1SEG43_POS          (11)
#define LCD_DATA_COM1SEG44_POS          (12)
#define LCD_DATA_COM1SEG45_POS          (13)
#define LCD_DATA_COM1SEG46_POS          (14)
#define LCD_DATA_COM1SEG47_POS          (15)
#define LCD_DATA_COM2SEG40_POS          (16)
#define LCD_DATA_COM2SEG41_POS          (17)
#define LCD_DATA_COM2SEG42_POS          (18)
#define LCD_DATA_COM2SEG43_POS          (19)
#define LCD_DATA_COM2SEG44_POS          (20)
#define LCD_DATA_COM2SEG45_POS          (21)
#define LCD_DATA_COM2SEG46_POS          (22)
#define LCD_DATA_COM2SEG47_POS          (23)
#define LCD_DATA_COM3SEG40_POS          (24)
#define LCD_DATA_COM3SEG41_POS          (25)
#define LCD_DATA_COM3SEG42_POS          (26)
#define LCD_DATA_COM3SEG43_POS          (27)
#define LCD_DATA_COM3SEG44_POS          (28)
#define LCD_DATA_COM3SEG45_POS          (29)
#define LCD_DATA_COM3SEG46_POS          (30)
#define LCD_DATA_COM3SEG47_POS          (31)
#define LCD_DATA_COM0SEG40              ((uint32_t)1<<(LCD_DATA_COM0SEG40_POS))
#define LCD_DATA_COM0SEG41              ((uint32_t)1<<(LCD_DATA_COM0SEG41_POS))
#define LCD_DATA_COM0SEG42              ((uint32_t)1<<(LCD_DATA_COM0SEG42_POS))
#define LCD_DATA_COM0SEG43              ((uint32_t)1<<(LCD_DATA_COM0SEG43_POS))
#define LCD_DATA_COM0SEG44              ((uint32_t)1<<(LCD_DATA_COM0SEG44_POS))
#define LCD_DATA_COM0SEG45              ((uint32_t)1<<(LCD_DATA_COM0SEG45_POS))
#define LCD_DATA_COM0SEG46              ((uint32_t)1<<(LCD_DATA_COM0SEG46_POS))
#define LCD_DATA_COM0SEG47              ((uint32_t)1<<(LCD_DATA_COM0SEG47_POS))
#define LCD_DATA_COM1SEG40              ((uint32_t)1<<(LCD_DATA_COM1SEG40_POS))
#define LCD_DATA_COM1SEG41              ((uint32_t)1<<(LCD_DATA_COM1SEG41_POS))
#define LCD_DATA_COM1SEG42              ((uint32_t)1<<(LCD_DATA_COM1SEG42_POS))
#define LCD_DATA_COM1SEG43              ((uint32_t)1<<(LCD_DATA_COM1SEG43_POS))
#define LCD_DATA_COM1SEG44              ((uint32_t)1<<(LCD_DATA_COM1SEG44_POS))
#define LCD_DATA_COM1SEG45              ((uint32_t)1<<(LCD_DATA_COM1SEG45_POS))
#define LCD_DATA_COM1SEG46              ((uint32_t)1<<(LCD_DATA_COM1SEG46_POS))
#define LCD_DATA_COM1SEG47              ((uint32_t)1<<(LCD_DATA_COM1SEG47_POS))
#define LCD_DATA_COM2SEG40              ((uint32_t)1<<(LCD_DATA_COM2SEG40_POS))
#define LCD_DATA_COM2SEG41              ((uint32_t)1<<(LCD_DATA_COM2SEG41_POS))
#define LCD_DATA_COM2SEG42              ((uint32_t)1<<(LCD_DATA_COM2SEG42_POS))
#define LCD_DATA_COM2SEG43              ((uint32_t)1<<(LCD_DATA_COM2SEG43_POS))
#define LCD_DATA_COM2SEG44              ((uint32_t)1<<(LCD_DATA_COM2SEG44_POS))
#define LCD_DATA_COM2SEG45              ((uint32_t)1<<(LCD_DATA_COM2SEG45_POS))
#define LCD_DATA_COM2SEG46              ((uint32_t)1<<(LCD_DATA_COM2SEG46_POS))
#define LCD_DATA_COM2SEG47              ((uint32_t)1<<(LCD_DATA_COM2SEG47_POS))
#define LCD_DATA_COM3SEG40              ((uint32_t)1<<(LCD_DATA_COM3SEG40_POS))
#define LCD_DATA_COM3SEG41              ((uint32_t)1<<(LCD_DATA_COM3SEG41_POS))
#define LCD_DATA_COM3SEG42              ((uint32_t)1<<(LCD_DATA_COM3SEG42_POS))
#define LCD_DATA_COM3SEG43              ((uint32_t)1<<(LCD_DATA_COM3SEG43_POS))
#define LCD_DATA_COM3SEG44              ((uint32_t)1<<(LCD_DATA_COM3SEG44_POS))
#define LCD_DATA_COM3SEG45              ((uint32_t)1<<(LCD_DATA_COM3SEG45_POS))
#define LCD_DATA_COM3SEG46              ((uint32_t)1<<(LCD_DATA_COM3SEG46_POS))
#define LCD_DATA_COM3SEG47              ((uint32_t)1<<(LCD_DATA_COM3SEG47_POS))

/* LCD_DATA11 λ�� */
#define LCD_DATA_COM4SEG40_POS          (0)
#define LCD_DATA_COM4SEG41_POS          (1)
#define LCD_DATA_COM4SEG42_POS          (2)
#define LCD_DATA_COM4SEG43_POS          (3)
#define LCD_DATA_COM4SEG44_POS          (4)
#define LCD_DATA_COM4SEG45_POS          (5)
#define LCD_DATA_COM4SEG46_POS          (6)
#define LCD_DATA_COM4SEG47_POS          (7)
#define LCD_DATA_COM5SEG40_POS          (8)
#define LCD_DATA_COM5SEG41_POS          (9)
#define LCD_DATA_COM5SEG42_POS          (10)
#define LCD_DATA_COM5SEG43_POS          (11)
#define LCD_DATA_COM5SEG44_POS          (12)
#define LCD_DATA_COM5SEG45_POS          (13)
#define LCD_DATA_COM5SEG46_POS          (14)
#define LCD_DATA_COM5SEG47_POS          (15)
#define LCD_DATA_COM6SEG40_POS          (16)
#define LCD_DATA_COM6SEG41_POS          (17)
#define LCD_DATA_COM6SEG42_POS          (18)
#define LCD_DATA_COM6SEG43_POS          (19)
#define LCD_DATA_COM6SEG44_POS          (20)
#define LCD_DATA_COM6SEG45_POS          (21)
#define LCD_DATA_COM6SEG46_POS          (22)
#define LCD_DATA_COM6SEG47_POS          (23)
#define LCD_DATA_COM7SEG40_POS          (24)
#define LCD_DATA_COM7SEG41_POS          (25)
#define LCD_DATA_COM7SEG42_POS          (26)
#define LCD_DATA_COM7SEG43_POS          (27)
#define LCD_DATA_COM7SEG44_POS          (28)
#define LCD_DATA_COM7SEG45_POS          (29)
#define LCD_DATA_COM7SEG46_POS          (30)
#define LCD_DATA_COM7SEG47_POS          (31)
#define LCD_DATA_COM4SEG40              ((uint32_t)1<<(LCD_DATA_COM4SEG40_POS))
#define LCD_DATA_COM4SEG41              ((uint32_t)1<<(LCD_DATA_COM4SEG41_POS))
#define LCD_DATA_COM4SEG42              ((uint32_t)1<<(LCD_DATA_COM4SEG42_POS))
#define LCD_DATA_COM4SEG43              ((uint32_t)1<<(LCD_DATA_COM4SEG43_POS))
#define LCD_DATA_COM4SEG44              ((uint32_t)1<<(LCD_DATA_COM4SEG44_POS))
#define LCD_DATA_COM4SEG45              ((uint32_t)1<<(LCD_DATA_COM4SEG45_POS))
#define LCD_DATA_COM4SEG46              ((uint32_t)1<<(LCD_DATA_COM4SEG46_POS))
#define LCD_DATA_COM4SEG47              ((uint32_t)1<<(LCD_DATA_COM4SEG47_POS))
#define LCD_DATA_COM5SEG40              ((uint32_t)1<<(LCD_DATA_COM5SEG40_POS))
#define LCD_DATA_COM5SEG41              ((uint32_t)1<<(LCD_DATA_COM5SEG41_POS))
#define LCD_DATA_COM5SEG42              ((uint32_t)1<<(LCD_DATA_COM5SEG42_POS))
#define LCD_DATA_COM5SEG43              ((uint32_t)1<<(LCD_DATA_COM5SEG43_POS))
#define LCD_DATA_COM5SEG44              ((uint32_t)1<<(LCD_DATA_COM5SEG44_POS))
#define LCD_DATA_COM5SEG45              ((uint32_t)1<<(LCD_DATA_COM5SEG45_POS))
#define LCD_DATA_COM5SEG46              ((uint32_t)1<<(LCD_DATA_COM5SEG46_POS))
#define LCD_DATA_COM5SEG47              ((uint32_t)1<<(LCD_DATA_COM5SEG47_POS))
#define LCD_DATA_COM6SEG40              ((uint32_t)1<<(LCD_DATA_COM6SEG40_POS))
#define LCD_DATA_COM6SEG41              ((uint32_t)1<<(LCD_DATA_COM6SEG41_POS))
#define LCD_DATA_COM6SEG42              ((uint32_t)1<<(LCD_DATA_COM6SEG42_POS))
#define LCD_DATA_COM6SEG43              ((uint32_t)1<<(LCD_DATA_COM6SEG43_POS))
#define LCD_DATA_COM6SEG44              ((uint32_t)1<<(LCD_DATA_COM6SEG44_POS))
#define LCD_DATA_COM6SEG45              ((uint32_t)1<<(LCD_DATA_COM6SEG45_POS))
#define LCD_DATA_COM6SEG46              ((uint32_t)1<<(LCD_DATA_COM6SEG46_POS))
#define LCD_DATA_COM6SEG47              ((uint32_t)1<<(LCD_DATA_COM6SEG47_POS))
#define LCD_DATA_COM7SEG40              ((uint32_t)1<<(LCD_DATA_COM7SEG40_POS))
#define LCD_DATA_COM7SEG41              ((uint32_t)1<<(LCD_DATA_COM7SEG41_POS))
#define LCD_DATA_COM7SEG42              ((uint32_t)1<<(LCD_DATA_COM7SEG42_POS))
#define LCD_DATA_COM7SEG43              ((uint32_t)1<<(LCD_DATA_COM7SEG43_POS))
#define LCD_DATA_COM7SEG44              ((uint32_t)1<<(LCD_DATA_COM7SEG44_POS))
#define LCD_DATA_COM7SEG45              ((uint32_t)1<<(LCD_DATA_COM7SEG45_POS))
#define LCD_DATA_COM7SEG46              ((uint32_t)1<<(LCD_DATA_COM7SEG46_POS))
#define LCD_DATA_COM7SEG47              ((uint32_t)1<<(LCD_DATA_COM7SEG47_POS))

/* LCD_SEG0 λ�� */
#define LCD_SEG0_SEG0_POS               (0)
#define LCD_SEG0_SEG1_POS               (1)
#define LCD_SEG0_SEG2_POS               (2)
#define LCD_SEG0_SEG3_POS               (3)
#define LCD_SEG0_SEG4_POS               (4)
#define LCD_SEG0_SEG5_POS               (5)
#define LCD_SEG0_SEG6_POS               (6)
#define LCD_SEG0_SEG7_POS               (7)
#define LCD_SEG0_SEG8_POS               (8)
#define LCD_SEG0_SEG9_POS               (9)
#define LCD_SEG0_SEG10_POS              (10)
#define LCD_SEG0_SEG11_POS              (11)
#define LCD_SEG0_SEG12_POS              (12)
#define LCD_SEG0_SEG13_POS              (13)
#define LCD_SEG0_SEG14_POS              (14)
#define LCD_SEG0_SEG15_POS              (15)
#define LCD_SEG0_SEG16_POS              (16)
#define LCD_SEG0_SEG17_POS              (17)
#define LCD_SEG0_SEG18_POS              (18)
#define LCD_SEG0_SEG19_POS              (19)
#define LCD_SEG0_SEG20_POS              (20)
#define LCD_SEG0_SEG21_POS              (21)
#define LCD_SEG0_SEG22_POS              (22)
#define LCD_SEG0_SEG23_POS              (23)
#define LCD_SEG0_SEG24_POS              (24)
#define LCD_SEG0_SEG25_POS              (25)
#define LCD_SEG0_SEG26_POS              (26)
#define LCD_SEG0_SEG27_POS              (27)
#define LCD_SEG0_SEG28_POS              (28)
#define LCD_SEG0_SEG29_POS              (29)
#define LCD_SEG0_SEG30_POS              (30)
#define LCD_SEG0_SEG31_POS              (31)
#define LCD_SEG0_SEG0                   ((uint32_t)1<<(LCD_SEG0_SEG0_POS))
#define LCD_SEG0_SEG1                   ((uint32_t)1<<(LCD_SEG0_SEG1_POS))
#define LCD_SEG0_SEG2                   ((uint32_t)1<<(LCD_SEG0_SEG2_POS))
#define LCD_SEG0_SEG3                   ((uint32_t)1<<(LCD_SEG0_SEG3_POS))
#define LCD_SEG0_SEG4                   ((uint32_t)1<<(LCD_SEG0_SEG4_POS))
#define LCD_SEG0_SEG5                   ((uint32_t)1<<(LCD_SEG0_SEG5_POS))
#define LCD_SEG0_SEG6                   ((uint32_t)1<<(LCD_SEG0_SEG6_POS))
#define LCD_SEG0_SEG7                   ((uint32_t)1<<(LCD_SEG0_SEG7_POS))
#define LCD_SEG0_SEG8                   ((uint32_t)1<<(LCD_SEG0_SEG8_POS))
#define LCD_SEG0_SEG9                   ((uint32_t)1<<(LCD_SEG0_SEG9_POS))
#define LCD_SEG0_SEG10                  ((uint32_t)1<<(LCD_SEG0_SEG10_POS))
#define LCD_SEG0_SEG11                  ((uint32_t)1<<(LCD_SEG0_SEG11_POS))
#define LCD_SEG0_SEG12                  ((uint32_t)1<<(LCD_SEG0_SEG12_POS))
#define LCD_SEG0_SEG13                  ((uint32_t)1<<(LCD_SEG0_SEG13_POS))
#define LCD_SEG0_SEG14                  ((uint32_t)1<<(LCD_SEG0_SEG14_POS))
#define LCD_SEG0_SEG15                  ((uint32_t)1<<(LCD_SEG0_SEG15_POS))
#define LCD_SEG0_SEG16                  ((uint32_t)1<<(LCD_SEG0_SEG16_POS))
#define LCD_SEG0_SEG17                  ((uint32_t)1<<(LCD_SEG0_SEG17_POS))
#define LCD_SEG0_SEG18                  ((uint32_t)1<<(LCD_SEG0_SEG18_POS))
#define LCD_SEG0_SEG19                  ((uint32_t)1<<(LCD_SEG0_SEG19_POS))
#define LCD_SEG0_SEG20                  ((uint32_t)1<<(LCD_SEG0_SEG20_POS))
#define LCD_SEG0_SEG21                  ((uint32_t)1<<(LCD_SEG0_SEG21_POS))
#define LCD_SEG0_SEG22                  ((uint32_t)1<<(LCD_SEG0_SEG22_POS))
#define LCD_SEG0_SEG23                  ((uint32_t)1<<(LCD_SEG0_SEG23_POS))
#define LCD_SEG0_SEG24                  ((uint32_t)1<<(LCD_SEG0_SEG24_POS))
#define LCD_SEG0_SEG25                  ((uint32_t)1<<(LCD_SEG0_SEG25_POS))
#define LCD_SEG0_SEG26                  ((uint32_t)1<<(LCD_SEG0_SEG26_POS))
#define LCD_SEG0_SEG27                  ((uint32_t)1<<(LCD_SEG0_SEG27_POS))
#define LCD_SEG0_SEG28                  ((uint32_t)1<<(LCD_SEG0_SEG28_POS))
#define LCD_SEG0_SEG29                  ((uint32_t)1<<(LCD_SEG0_SEG29_POS))
#define LCD_SEG0_SEG30                  ((uint32_t)1<<(LCD_SEG0_SEG30_POS))
#define LCD_SEG0_SEG31                  ((uint32_t)1<<(LCD_SEG0_SEG31_POS))

/* LCD_SEG1 λ�� */
#define LCD_SEG1_SEG32_POS              (0)
#define LCD_SEG1_SEG33_POS              (1)
#define LCD_SEG1_SEG34_POS              (2)
#define LCD_SEG1_SEG35_POS              (3)
#define LCD_SEG1_SEG36_POS              (4)
#define LCD_SEG1_SEG37_POS              (5)
#define LCD_SEG1_SEG38_POS              (6)
#define LCD_SEG1_SEG39_POS              (7)
#define LCD_SEG1_SEG40_POS              (8)
#define LCD_SEG1_SEG41_POS              (9)
#define LCD_SEG1_SEG42_POS              (10)
#define LCD_SEG1_SEG43_POS              (11)
#define LCD_SEG1_SEG44_POS              (12)
#define LCD_SEG1_SEG45_POS              (13)
#define LCD_SEG1_SEG46_POS              (14)
#define LCD_SEG1_SEG47_POS              (15)
#define LCD_SEG1_SEG32                  ((uint32_t)1<<(LCD_SEG1_SEG32_POS))
#define LCD_SEG1_SEG33                  ((uint32_t)1<<(LCD_SEG1_SEG33_POS))
#define LCD_SEG1_SEG34                  ((uint32_t)1<<(LCD_SEG1_SEG34_POS))
#define LCD_SEG1_SEG35                  ((uint32_t)1<<(LCD_SEG1_SEG35_POS))
#define LCD_SEG1_SEG36                  ((uint32_t)1<<(LCD_SEG1_SEG36_POS))
#define LCD_SEG1_SEG37                  ((uint32_t)1<<(LCD_SEG1_SEG37_POS))
#define LCD_SEG1_SEG38                  ((uint32_t)1<<(LCD_SEG1_SEG38_POS))
#define LCD_SEG1_SEG39                  ((uint32_t)1<<(LCD_SEG1_SEG39_POS))
#define LCD_SEG1_SEG40                  ((uint32_t)1<<(LCD_SEG1_SEG40_POS))
#define LCD_SEG1_SEG41                  ((uint32_t)1<<(LCD_SEG1_SEG41_POS))
#define LCD_SEG1_SEG42                  ((uint32_t)1<<(LCD_SEG1_SEG42_POS))
#define LCD_SEG1_SEG43                  ((uint32_t)1<<(LCD_SEG1_SEG43_POS))
#define LCD_SEG1_SEG44                  ((uint32_t)1<<(LCD_SEG1_SEG44_POS))
#define LCD_SEG1_SEG45                  ((uint32_t)1<<(LCD_SEG1_SEG45_POS))
#define LCD_SEG1_SEG46                  ((uint32_t)1<<(LCD_SEG1_SEG46_POS))
#define LCD_SEG1_SEG47                  ((uint32_t)1<<(LCD_SEG1_SEG47_POS))

#endif  //KF32F_Periph_lcd
/* Һ����ʾ (LCD)������� */


/* ----------------------------------------------------------------------------
   -- ʵʱʱ�� (RTC)
   ---------------------------------------------------------------------------- */

/* RTC - ����Ĵ����ڴ�ṹ */
typedef struct RTC_MemMap {
    volatile uint32_t CR;               /* RTC���ƼĴ���, ƫ��:0x0 */
    volatile uint32_t ALRA;             /* RTC����A���ƼĴ���, ƫ��:0x4 */
    volatile uint32_t TMR;              /* RTCʱ��Ĵ���, ƫ��:0x8 */
    volatile uint32_t DTR;              /* RTC���ڼĴ���, ƫ��:0xC */
    volatile uint32_t ALRB;             /* RTC����B���ƼĴ���, ƫ��:0x10 */
    volatile uint32_t TMER;             /* RTC��ʱ���Ĵ���, ƫ��:0x14 */
    volatile uint32_t TCR;              /* RTC��ʱ�����ƼĴ���, ƫ��:0x18 */
    volatile uint32_t IER;              /* RTC�ж�ʹ�ܼĴ���, ƫ��:0x1C */
    volatile uint32_t IFR;              /* RTC�жϱ�־�Ĵ���, ƫ��:0x20 */
    volatile uint32_t TMBR;             /* RTCʱ�䱸�ݼĴ���, ƫ��:0x24 */
    volatile uint32_t DTBR;             /* RTC���ڱ��ݼĴ���, ƫ��:0x28 */
}RTC_SFRmap;

/* ----------------------------------------------------------------------------
   -- RTC - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* RTC - �Ĵ�����ڵ�ַ */
#define RTC_ADDR                        ((uint32_t)0x40000F00)
#define RTC_SFR                         ((RTC_SFRmap *) RTC_ADDR)

/* RTC - �Ĵ������ */
#define RTC_CR                          (RTC_SFR->CR)
#define RTC_ALRA                        (RTC_SFR->ALRA)
#define RTC_TMR                         (RTC_SFR->TMR)
#define RTC_DTR                         (RTC_SFR->DTR)
#define RTC_ALRB                        (RTC_SFR->ALRB)
#define RTC_TMER                        (RTC_SFR->TMER)
#define RTC_TCR                         (RTC_SFR->TCR)
#define RTC_IER                         (RTC_SFR->IER)
#define RTC_IFR                         (RTC_SFR->IFR)
#define RTC_TMBR                        (RTC_SFR->TMBR)
#define RTC_DTBR                        (RTC_SFR->DTBR)

/* RTC_CR λ�� */
#define RTC_CR_RTCEN_POS                (0)
#define RTC_CR_RTCLD_POS                (1)
#define RTC_CR_RTOFF_POS                (2)
#define RTC_CR_CNF_POS                  (3)
#define RTC_CR_HT_POS                   (4)
#define RTC_CR_LIF_POS                  (5)
#define RTC_CR_RESET_POS                (6)
#define RTC_CR_RTCSRT0_POS              (8)
#define RTC_CR_RTCSRT1_POS              (9)
#define RTC_CR_RTCSRT2_POS              (10)
#define RTC_CR_RTCSRT3_POS              (11)
#define RTC_CR_RTCSRT4_POS              (12)
#define RTC_CR_RTCSRT5_POS              (13)
#define RTC_CR_RTCSRT6_POS              (14)
#define RTC_CR_RTCSRT7_POS              (15)
#define RTC_CR_RTCTT0_POS               (16)
#define RTC_CR_RTCTT1_POS               (17)
#define RTC_CR_RTCTT2_POS               (18)
#define RTC_CR_SUB1H_POS                (19)
#define RTC_CR_ADD1H_POS                (20)
#define RTC_CR_TSEN_POS                 (21)
#define RTC_CR_TSEDGE_POS               (22)
#define RTC_CR_TTOE_POS                 (23)
#define RTC_CR_RTCCAL0_POS              (24)
#define RTC_CR_RTCCAL1_POS              (25)
#define RTC_CR_RTCCAL2_POS              (26)
#define RTC_CR_RTCCAL3_POS              (27)
#define RTC_CR_RTCCAL4_POS              (28)
#define RTC_CR_RTCCAL5_POS              (29)
#define RTC_CR_RTCCAL6_POS              (30)
#define RTC_CR_RTCCAL7_POS              (31)
#define RTC_CR_RTCEN                    ((uint32_t)1<<(RTC_CR_RTCEN_POS))
#define RTC_CR_RTCLD                    ((uint32_t)1<<(RTC_CR_RTCLD_POS))
#define RTC_CR_RTOFF                    ((uint32_t)1<<(RTC_CR_RTOFF_POS))
#define RTC_CR_CNF                      ((uint32_t)1<<(RTC_CR_CNF_POS))
#define RTC_CR_HT                       ((uint32_t)1<<(RTC_CR_HT_POS))
#define RTC_CR_LIF                      ((uint32_t)1<<(RTC_CR_LIF_POS))
#define RTC_CR_RESET                    ((uint32_t)1<<(RTC_CR_RESET_POS))
#define RTC_CR_RTCSRT                   ((uint32_t)0xFF<<(RTC_CR_RTCSRT0_POS))
#define RTC_CR_RTCSRT0                  ((uint32_t)1<<(RTC_CR_RTCSRT0_POS))
#define RTC_CR_RTCSRT1                  ((uint32_t)1<<(RTC_CR_RTCSRT1_POS))
#define RTC_CR_RTCSRT2                  ((uint32_t)1<<(RTC_CR_RTCSRT2_POS))
#define RTC_CR_RTCSRT3                  ((uint32_t)1<<(RTC_CR_RTCSRT3_POS))
#define RTC_CR_RTCSRT4                  ((uint32_t)1<<(RTC_CR_RTCSRT4_POS))
#define RTC_CR_RTCSRT5                  ((uint32_t)1<<(RTC_CR_RTCSRT5_POS))
#define RTC_CR_RTCSRT6                  ((uint32_t)1<<(RTC_CR_RTCSRT6_POS))
#define RTC_CR_RTCSRT7                  ((uint32_t)1<<(RTC_CR_RTCSRT7_POS))
#define RTC_CR_RTCTT                    ((uint32_t)7<<(RTC_CR_RTCTT0_POS))
#define RTC_CR_RTCTT0                   ((uint32_t)1<<(RTC_CR_RTCTT0_POS))
#define RTC_CR_RTCTT1                   ((uint32_t)1<<(RTC_CR_RTCTT1_POS))
#define RTC_CR_RTCTT2                   ((uint32_t)1<<(RTC_CR_RTCTT2_POS))
#define RTC_CR_SUB1H                    ((uint32_t)1<<(RTC_CR_SUB1H_POS))
#define RTC_CR_ADD1H                    ((uint32_t)1<<(RTC_CR_ADD1H_POS))
#define RTC_CR_TSEN                     ((uint32_t)1<<(RTC_CR_TSEN_POS))
#define RTC_CR_TSEDGE                   ((uint32_t)1<<(RTC_CR_TSEDGE_POS))
#define RTC_CR_TTOE                     ((uint32_t)1<<(RTC_CR_TTOE_POS))
#define RTC_CR_RTCCAL                   ((uint32_t)0xFF<<(RTC_CR_RTCCAL0_POS))
#define RTC_CR_RTCCAL0                  ((uint32_t)1<<(RTC_CR_RTCCAL0_POS))
#define RTC_CR_RTCCAL1                  ((uint32_t)1<<(RTC_CR_RTCCAL1_POS))
#define RTC_CR_RTCCAL2                  ((uint32_t)1<<(RTC_CR_RTCCAL2_POS))
#define RTC_CR_RTCCAL3                  ((uint32_t)1<<(RTC_CR_RTCCAL3_POS))
#define RTC_CR_RTCCAL4                  ((uint32_t)1<<(RTC_CR_RTCCAL4_POS))
#define RTC_CR_RTCCAL5                  ((uint32_t)1<<(RTC_CR_RTCCAL5_POS))
#define RTC_CR_RTCCAL6                  ((uint32_t)1<<(RTC_CR_RTCCAL6_POS))
#define RTC_CR_RTCCAL7                  ((uint32_t)1<<(RTC_CR_RTCCAL7_POS))

/* RTC_ALRA λ�� */
#define RTC_ALRA_ALRSA0_POS             (0)
#define RTC_ALRA_ALRSA1_POS             (1)
#define RTC_ALRA_ALRSA2_POS             (2)
#define RTC_ALRA_ALRSA3_POS             (3)
#define RTC_ALRA_ALRSA4_POS             (4)
#define RTC_ALRA_ALRSA5_POS             (5)
#define RTC_ALRA_ALRSA6_POS             (6)
#define RTC_ALRA_ASENA_POS              (7)
#define RTC_ALRA_ALRMA0_POS             (8)
#define RTC_ALRA_ALRMA1_POS             (9)
#define RTC_ALRA_ALRMA2_POS             (10)
#define RTC_ALRA_ALRMA3_POS             (11)
#define RTC_ALRA_ALRMA4_POS             (12)
#define RTC_ALRA_ALRMA5_POS             (13)
#define RTC_ALRA_ALRMA6_POS             (14)
#define RTC_ALRA_AMENA_POS              (15)
#define RTC_ALRA_ALRHA0_POS             (16)
#define RTC_ALRA_ALRHA1_POS             (17)
#define RTC_ALRA_ALRHA2_POS             (18)
#define RTC_ALRA_ALRHA3_POS             (19)
#define RTC_ALRA_ALRHA4_POS             (20)
#define RTC_ALRA_ALRHA5_POS             (21)
#define RTC_ALRA_AMPMA_POS              (22)
#define RTC_ALRA_AHENA_POS              (23)
#define RTC_ALRA_ALRWA0_POS             (24)
#define RTC_ALRA_ALRWA1_POS             (25)
#define RTC_ALRA_ALRWA2_POS             (26)
#define RTC_ALRA_AWENA_POS              (27)
#define RTC_ALRA_ALRENA_POS             (31)
#define RTC_ALRA_ALRSA                  ((uint32_t)0x7F<<(RTC_ALRA_ALRSA0_POS))
#define RTC_ALRA_ALRSA0                 ((uint32_t)1<<(RTC_ALRA_ALRSA0_POS))
#define RTC_ALRA_ALRSA1                 ((uint32_t)1<<(RTC_ALRA_ALRSA1_POS))
#define RTC_ALRA_ALRSA2                 ((uint32_t)1<<(RTC_ALRA_ALRSA2_POS))
#define RTC_ALRA_ALRSA3                 ((uint32_t)1<<(RTC_ALRA_ALRSA3_POS))
#define RTC_ALRA_ALRSA4                 ((uint32_t)1<<(RTC_ALRA_ALRSA4_POS))
#define RTC_ALRA_ALRSA5                 ((uint32_t)1<<(RTC_ALRA_ALRSA5_POS))
#define RTC_ALRA_ALRSA6                 ((uint32_t)1<<(RTC_ALRA_ALRSA6_POS))
#define RTC_ALRA_ASENA                  ((uint32_t)1<<(RTC_ALRA_ASENA_POS))
#define RTC_ALRA_ALRMA                  ((uint32_t)0x7F<<(RTC_ALRA_ALRMA0_POS))
#define RTC_ALRA_ALRMA0                 ((uint32_t)1<<(RTC_ALRA_ALRMA0_POS))
#define RTC_ALRA_ALRMA1                 ((uint32_t)1<<(RTC_ALRA_ALRMA1_POS))
#define RTC_ALRA_ALRMA2                 ((uint32_t)1<<(RTC_ALRA_ALRMA2_POS))
#define RTC_ALRA_ALRMA3                 ((uint32_t)1<<(RTC_ALRA_ALRMA3_POS))
#define RTC_ALRA_ALRMA4                 ((uint32_t)1<<(RTC_ALRA_ALRMA4_POS))
#define RTC_ALRA_ALRMA5                 ((uint32_t)1<<(RTC_ALRA_ALRMA5_POS))
#define RTC_ALRA_ALRMA6                 ((uint32_t)1<<(RTC_ALRA_ALRMA6_POS))
#define RTC_ALRA_AMENA                  ((uint32_t)1<<(RTC_ALRA_AMENA_POS))
#define RTC_ALRA_ALRHA                  ((uint32_t)0x3F<<(RTC_ALRA_ALRHA0_POS))
#define RTC_ALRA_ALRHA0                 ((uint32_t)1<<(RTC_ALRA_ALRHA0_POS))
#define RTC_ALRA_ALRHA1                 ((uint32_t)1<<(RTC_ALRA_ALRHA1_POS))
#define RTC_ALRA_ALRHA2                 ((uint32_t)1<<(RTC_ALRA_ALRHA2_POS))
#define RTC_ALRA_ALRHA3                 ((uint32_t)1<<(RTC_ALRA_ALRHA3_POS))
#define RTC_ALRA_ALRHA4                 ((uint32_t)1<<(RTC_ALRA_ALRHA4_POS))
#define RTC_ALRA_ALRHA5                 ((uint32_t)1<<(RTC_ALRA_ALRHA5_POS))
#define RTC_ALRA_AMPMA                  ((uint32_t)1<<(RTC_ALRA_AMPMA_POS))
#define RTC_ALRA_AHENA                  ((uint32_t)1<<(RTC_ALRA_AHENA_POS))
#define RTC_ALRA_ALRWA                  ((uint32_t)7<<(RTC_ALRA_ALRWA0_POS))
#define RTC_ALRA_ALRWA0                 ((uint32_t)1<<(RTC_ALRA_ALRWA0_POS))
#define RTC_ALRA_ALRWA1                 ((uint32_t)1<<(RTC_ALRA_ALRWA1_POS))
#define RTC_ALRA_ALRWA2                 ((uint32_t)1<<(RTC_ALRA_ALRWA2_POS))
#define RTC_ALRA_AWENA                  ((uint32_t)1<<(RTC_ALRA_AWENA_POS))
#define RTC_ALRA_ALRENA                 ((uint32_t)1<<(RTC_ALRA_ALRENA_POS))

/* RTC_ALRB λ�� */
#define RTC_ALRB_ALRSB0_POS             (0)
#define RTC_ALRB_ALRSB1_POS             (1)
#define RTC_ALRB_ALRSB2_POS             (2)
#define RTC_ALRB_ALRSB3_POS             (3)
#define RTC_ALRB_ALRSB4_POS             (4)
#define RTC_ALRB_ALRSB5_POS             (5)
#define RTC_ALRB_ALRSB6_POS             (6)
#define RTC_ALRB_ASENB_POS              (7)
#define RTC_ALRB_ALRMB0_POS             (8)
#define RTC_ALRB_ALRMB1_POS             (9)
#define RTC_ALRB_ALRMB2_POS             (10)
#define RTC_ALRB_ALRMB3_POS             (11)
#define RTC_ALRB_ALRMB4_POS             (12)
#define RTC_ALRB_ALRMB5_POS             (13)
#define RTC_ALRB_ALRMB6_POS             (14)
#define RTC_ALRB_AMENB_POS              (15)
#define RTC_ALRB_ALRHB0_POS             (16)
#define RTC_ALRB_ALRHB1_POS             (17)
#define RTC_ALRB_ALRHB2_POS             (18)
#define RTC_ALRB_ALRHB3_POS             (19)
#define RTC_ALRB_ALRHB4_POS             (20)
#define RTC_ALRB_ALRHB5_POS             (21)
#define RTC_ALRB_AMPMB_POS              (22)
#define RTC_ALRB_AHENB_POS              (23)
#define RTC_ALRB_ALRWB0_POS             (24)
#define RTC_ALRB_ALRWB1_POS             (25)
#define RTC_ALRB_ALRWB2_POS             (26)
#define RTC_ALRB_AWENB_POS              (27)
#define RTC_ALRB_ALRENB_POS             (31)
#define RTC_ALRB_ALRSB                  ((uint32_t)0x7F<<(RTC_ALRB_ALRSB0_POS))
#define RTC_ALRB_ALRSB0                 ((uint32_t)1<<(RTC_ALRB_ALRSB0_POS))
#define RTC_ALRB_ALRSB1                 ((uint32_t)1<<(RTC_ALRB_ALRSB1_POS))
#define RTC_ALRB_ALRSB2                 ((uint32_t)1<<(RTC_ALRB_ALRSB2_POS))
#define RTC_ALRB_ALRSB3                 ((uint32_t)1<<(RTC_ALRB_ALRSB3_POS))
#define RTC_ALRB_ALRSB4                 ((uint32_t)1<<(RTC_ALRB_ALRSB4_POS))
#define RTC_ALRB_ALRSB5                 ((uint32_t)1<<(RTC_ALRB_ALRSB5_POS))
#define RTC_ALRB_ALRSB6                 ((uint32_t)1<<(RTC_ALRB_ALRSB6_POS))
#define RTC_ALRB_ASENB                  ((uint32_t)1<<(RTC_ALRB_ASENB_POS))
#define RTC_ALRB_ALRMB                  ((uint32_t)0x7F<<(RTC_ALRB_ALRMB0_POS))
#define RTC_ALRB_ALRMB0                 ((uint32_t)1<<(RTC_ALRB_ALRMB0_POS))
#define RTC_ALRB_ALRMB1                 ((uint32_t)1<<(RTC_ALRB_ALRMB1_POS))
#define RTC_ALRB_ALRMB2                 ((uint32_t)1<<(RTC_ALRB_ALRMB2_POS))
#define RTC_ALRB_ALRMB3                 ((uint32_t)1<<(RTC_ALRB_ALRMB3_POS))
#define RTC_ALRB_ALRMB4                 ((uint32_t)1<<(RTC_ALRB_ALRMB4_POS))
#define RTC_ALRB_ALRMB5                 ((uint32_t)1<<(RTC_ALRB_ALRMB5_POS))
#define RTC_ALRB_ALRMB6                 ((uint32_t)1<<(RTC_ALRB_ALRMB6_POS))
#define RTC_ALRB_AMENB                  ((uint32_t)1<<(RTC_ALRB_AMENB_POS))
#define RTC_ALRB_ALRHB                  ((uint32_t)0x3F<<(RTC_ALRB_ALRHB0_POS))
#define RTC_ALRB_ALRHB0                 ((uint32_t)1<<(RTC_ALRB_ALRHB0_POS))
#define RTC_ALRB_ALRHB1                 ((uint32_t)1<<(RTC_ALRB_ALRHB1_POS))
#define RTC_ALRB_ALRHB2                 ((uint32_t)1<<(RTC_ALRB_ALRHB2_POS))
#define RTC_ALRB_ALRHB3                 ((uint32_t)1<<(RTC_ALRB_ALRHB3_POS))
#define RTC_ALRB_ALRHB4                 ((uint32_t)1<<(RTC_ALRB_ALRHB4_POS))
#define RTC_ALRB_ALRHB5                 ((uint32_t)1<<(RTC_ALRB_ALRHB5_POS))
#define RTC_ALRB_AMPMB                  ((uint32_t)1<<(RTC_ALRB_AMPMB_POS))
#define RTC_ALRB_AHENB                  ((uint32_t)1<<(RTC_ALRB_AHENB_POS))
#define RTC_ALRB_ALRWB                  ((uint32_t)7<<(RTC_ALRB_ALRWB0_POS))
#define RTC_ALRB_ALRWB0                 ((uint32_t)1<<(RTC_ALRB_ALRWB0_POS))
#define RTC_ALRB_ALRWB1                 ((uint32_t)1<<(RTC_ALRB_ALRWB1_POS))
#define RTC_ALRB_ALRWB2                 ((uint32_t)1<<(RTC_ALRB_ALRWB2_POS))
#define RTC_ALRB_AWENB                  ((uint32_t)1<<(RTC_ALRB_AWENB_POS))
#define RTC_ALRB_ALRENB                 ((uint32_t)1<<(RTC_ALRB_ALRENB_POS))

/* RTC_TMR λ�� */
#define RTC_TMR_SEC0_POS                (0)
#define RTC_TMR_SEC1_POS                (1)
#define RTC_TMR_SEC2_POS                (2)
#define RTC_TMR_SEC3_POS                (3)
#define RTC_TMR_SEC4_POS                (4)
#define RTC_TMR_SEC5_POS                (5)
#define RTC_TMR_SEC6_POS                (6)
#define RTC_TMR_MIN0_POS                (8)
#define RTC_TMR_MIN1_POS                (9)
#define RTC_TMR_MIN2_POS                (10)
#define RTC_TMR_MIN3_POS                (11)
#define RTC_TMR_MIN4_POS                (12)
#define RTC_TMR_MIN5_POS                (13)
#define RTC_TMR_MIN6_POS                (14)
#define RTC_TMR_HOUR0_POS               (16)
#define RTC_TMR_HOUR1_POS               (17)
#define RTC_TMR_HOUR2_POS               (18)
#define RTC_TMR_HOUR3_POS               (19)
#define RTC_TMR_HOUR4_POS               (20)
#define RTC_TMR_HOUR5_POS               (21)
#define RTC_TMR_AMPM_POS                (22)
#define RTC_TMR_WEK0_POS                (24)
#define RTC_TMR_WEK1_POS                (25)
#define RTC_TMR_WEK2_POS                (26)
#define RTC_TMR_SEC                     ((uint32_t)0x7F<<(RTC_TMR_SEC0_POS))
#define RTC_TMR_SEC0                    ((uint32_t)1<<(RTC_TMR_SEC0_POS))
#define RTC_TMR_SEC1                    ((uint32_t)1<<(RTC_TMR_SEC1_POS))
#define RTC_TMR_SEC2                    ((uint32_t)1<<(RTC_TMR_SEC2_POS))
#define RTC_TMR_SEC3                    ((uint32_t)1<<(RTC_TMR_SEC3_POS))
#define RTC_TMR_SEC4                    ((uint32_t)1<<(RTC_TMR_SEC4_POS))
#define RTC_TMR_SEC5                    ((uint32_t)1<<(RTC_TMR_SEC5_POS))
#define RTC_TMR_SEC6                    ((uint32_t)1<<(RTC_TMR_SEC6_POS))
#define RTC_TMR_MIN                     ((uint32_t)0x7F<<(RTC_TMR_MIN0_POS))
#define RTC_TMR_MIN0                    ((uint32_t)1<<(RTC_TMR_MIN0_POS))
#define RTC_TMR_MIN1                    ((uint32_t)1<<(RTC_TMR_MIN1_POS))
#define RTC_TMR_MIN2                    ((uint32_t)1<<(RTC_TMR_MIN2_POS))
#define RTC_TMR_MIN3                    ((uint32_t)1<<(RTC_TMR_MIN3_POS))
#define RTC_TMR_MIN4                    ((uint32_t)1<<(RTC_TMR_MIN4_POS))
#define RTC_TMR_MIN5                    ((uint32_t)1<<(RTC_TMR_MIN5_POS))
#define RTC_TMR_MIN6                    ((uint32_t)1<<(RTC_TMR_MIN6_POS))
#define RTC_TMR_HOUR                    ((uint32_t)0x3F<<(RTC_TMR_HOUR0_POS))
#define RTC_TMR_HOUR0                   ((uint32_t)1<<(RTC_TMR_HOUR0_POS))
#define RTC_TMR_HOUR1                   ((uint32_t)1<<(RTC_TMR_HOUR1_POS))
#define RTC_TMR_HOUR2                   ((uint32_t)1<<(RTC_TMR_HOUR2_POS))
#define RTC_TMR_HOUR3                   ((uint32_t)1<<(RTC_TMR_HOUR3_POS))
#define RTC_TMR_HOUR4                   ((uint32_t)1<<(RTC_TMR_HOUR4_POS))
#define RTC_TMR_HOUR5                   ((uint32_t)1<<(RTC_TMR_HOUR5_POS))
#define RTC_TMR_AMPM                    ((uint32_t)1<<(RTC_TMR_AMPM_POS))
#define RTC_TMR_WEK                     ((uint32_t)7<<(RTC_TMR_WEK0_POS))
#define RTC_TMR_WEK0                    ((uint32_t)1<<(RTC_TMR_WEK0_POS))
#define RTC_TMR_WEK1                    ((uint32_t)1<<(RTC_TMR_WEK1_POS))
#define RTC_TMR_WEK2                    ((uint32_t)1<<(RTC_TMR_WEK2_POS))

/* RTC_DTR λ�� */
#define RTC_DTR_DAY0_POS                (0)
#define RTC_DTR_DAY1_POS                (1)
#define RTC_DTR_DAY2_POS                (2)
#define RTC_DTR_DAY3_POS                (3)
#define RTC_DTR_DAY4_POS                (4)
#define RTC_DTR_DAY5_POS                (5)
#define RTC_DTR_MTH0_POS                (8)
#define RTC_DTR_MTH1_POS                (9)
#define RTC_DTR_MTH2_POS                (10)
#define RTC_DTR_MTH3_POS                (11)
#define RTC_DTR_MTH4_POS                (12)
#define RTC_DTR_YEAR0_POS               (16)
#define RTC_DTR_YEAR1_POS               (17)
#define RTC_DTR_YEAR2_POS               (18)
#define RTC_DTR_YEAR3_POS               (19)
#define RTC_DTR_YEAR4_POS               (20)
#define RTC_DTR_YEAR5_POS               (21)
#define RTC_DTR_YEAR6_POS               (22)
#define RTC_DTR_YEAR7_POS               (23)
#define RTC_DTR_DAY                     ((uint32_t)0x7F<<(RTC_DTR_DAY0_POS))
#define RTC_DTR_DAY0                    ((uint32_t)1<<(RTC_DTR_DAY0_POS))
#define RTC_DTR_DAY1                    ((uint32_t)1<<(RTC_DTR_DAY1_POS))
#define RTC_DTR_DAY2                    ((uint32_t)1<<(RTC_DTR_DAY2_POS))
#define RTC_DTR_DAY3                    ((uint32_t)1<<(RTC_DTR_DAY3_POS))
#define RTC_DTR_DAY4                    ((uint32_t)1<<(RTC_DTR_DAY4_POS))
#define RTC_DTR_DAY5                    ((uint32_t)1<<(RTC_DTR_DAY5_POS))
#define RTC_DTR_MTH                     ((uint32_t)0x7F<<(RTC_DTR_MTH0_POS))
#define RTC_DTR_MTH0                    ((uint32_t)1<<(RTC_DTR_MTH0_POS))
#define RTC_DTR_MTH1                    ((uint32_t)1<<(RTC_DTR_MTH1_POS))
#define RTC_DTR_MTH2                    ((uint32_t)1<<(RTC_DTR_MTH2_POS))
#define RTC_DTR_MTH3                    ((uint32_t)1<<(RTC_DTR_MTH3_POS))
#define RTC_DTR_MTH4                    ((uint32_t)1<<(RTC_DTR_MTH4_POS))
#define RTC_DTR_YEAR                    ((uint32_t)0x3F<<(RTC_DTR_YEAR0_POS))
#define RTC_DTR_YEAR0                   ((uint32_t)1<<(RTC_DTR_YEAR0_POS))
#define RTC_DTR_YEAR1                   ((uint32_t)1<<(RTC_DTR_YEAR1_POS))
#define RTC_DTR_YEAR2                   ((uint32_t)1<<(RTC_DTR_YEAR2_POS))
#define RTC_DTR_YEAR3                   ((uint32_t)1<<(RTC_DTR_YEAR3_POS))
#define RTC_DTR_YEAR4                   ((uint32_t)1<<(RTC_DTR_YEAR4_POS))
#define RTC_DTR_YEAR5                   ((uint32_t)1<<(RTC_DTR_YEAR5_POS))
#define RTC_DTR_YEAR6                   ((uint32_t)1<<(RTC_DTR_YEAR6_POS))
#define RTC_DTR_YEAR7                   ((uint32_t)1<<(RTC_DTR_YEAR7_POS))

/* RTC_TMER λ�� */
#define RTC_TMER_TMR0_0_POS             (0)
#define RTC_TMER_TMR1_0_POS             (16)
#define RTC_TMER_TMR0                   ((uint32_t)0xFFFF<<(RTC_TMER_TMR0_0_POS))
#define RTC_TMER_TMR1                   ((uint32_t)0xFFFF<<(RTC_TMER_TMR1_0_POS))

/* RTC_TCR λ�� */
#define RTC_TCR_TMR0C0_POS              (0)
#define RTC_TCR_TMR0C1_POS              (1)
#define RTC_TCR_TMR0C2_POS              (2)
#define RTC_TCR_TMR0C3_POS              (3)
#define RTC_TCR_TMR1C0_POS              (4)
#define RTC_TCR_TMR1C1_POS              (5)
#define RTC_TCR_TMR1C2_POS              (6)
#define RTC_TCR_TMR1C3_POS              (7)
#define RTC_TCR_TMR0EN_POS              (8)
#define RTC_TCR_TMR1EN_POS              (9)
#define RTC_TCR_TMR0C                   ((uint32_t)0xF<<(RTC_TCR_TMR0C0_POS))
#define RTC_TCR_TMR0C0                  ((uint32_t)1<<(RTC_TCR_TMR0C0_POS))
#define RTC_TCR_TMR0C1                  ((uint32_t)1<<(RTC_TCR_TMR0C1_POS))
#define RTC_TCR_TMR0C2                  ((uint32_t)1<<(RTC_TCR_TMR0C2_POS))
#define RTC_TCR_TMR0C3                  ((uint32_t)1<<(RTC_TCR_TMR0C3_POS))
#define RTC_TCR_TMR1C                   ((uint32_t)0xF<<(RTC_TCR_TMR1C0_POS))
#define RTC_TCR_TMR1C0                  ((uint32_t)1<<(RTC_TCR_TMR1C0_POS))
#define RTC_TCR_TMR1C1                  ((uint32_t)1<<(RTC_TCR_TMR1C1_POS))
#define RTC_TCR_TMR1C2                  ((uint32_t)1<<(RTC_TCR_TMR1C2_POS))
#define RTC_TCR_TMR1C3                  ((uint32_t)1<<(RTC_TCR_TMR1C3_POS))
#define RTC_TCR_TMR0EN                  ((uint32_t)1<<(RTC_TCR_TMR0EN_POS))
#define RTC_TCR_TMR1EN                  ((uint32_t)1<<(RTC_TCR_TMR1EN_POS))

/* RTC_TMBR λ�� */
#define RTC_TMBR_SECB0_POS              (0)
#define RTC_TMBR_SECB1_POS              (1)
#define RTC_TMBR_SECB2_POS              (2)
#define RTC_TMBR_SECB3_POS              (3)
#define RTC_TMBR_SECB4_POS              (4)
#define RTC_TMBR_SECB5_POS              (5)
#define RTC_TMBR_SECB6_POS              (6)
#define RTC_TMBR_MINB0_POS              (8)
#define RTC_TMBR_MINB1_POS              (9)
#define RTC_TMBR_MINB2_POS              (10)
#define RTC_TMBR_MINB3_POS              (11)
#define RTC_TMBR_MINB4_POS              (12)
#define RTC_TMBR_MINB5_POS              (13)
#define RTC_TMBR_MINB6_POS              (14)
#define RTC_TMBR_HOURB0_POS             (16)
#define RTC_TMBR_HOURB1_POS             (17)
#define RTC_TMBR_HOURB2_POS             (18)
#define RTC_TMBR_HOURB3_POS             (19)
#define RTC_TMBR_HOURB4_POS             (20)
#define RTC_TMBR_HOURB5_POS             (21)
#define RTC_TMBR_AMPMB_POS              (22)
#define RTC_TMBR_WEKB0_POS              (24)
#define RTC_TMBR_WEKB1_POS              (25)
#define RTC_TMBR_WEKB2_POS              (26)
#define RTC_TMBR_SECB                   ((uint32_t)0x7F<<(RTC_TMBR_SECB0_POS))
#define RTC_TMBR_SECB0                  ((uint32_t)1<<(RTC_TMBR_SECB0_POS))
#define RTC_TMBR_SECB1                  ((uint32_t)1<<(RTC_TMBR_SECB1_POS))
#define RTC_TMBR_SECB2                  ((uint32_t)1<<(RTC_TMBR_SECB2_POS))
#define RTC_TMBR_SECB3                  ((uint32_t)1<<(RTC_TMBR_SECB3_POS))
#define RTC_TMBR_SECB4                  ((uint32_t)1<<(RTC_TMBR_SECB4_POS))
#define RTC_TMBR_SECB5                  ((uint32_t)1<<(RTC_TMBR_SECB5_POS))
#define RTC_TMBR_SECB6                  ((uint32_t)1<<(RTC_TMBR_SECB6_POS))
#define RTC_TMBR_MINB                   ((uint32_t)0x7F<<(RTC_TMBR_MINB0_POS))
#define RTC_TMBR_MINB0                  ((uint32_t)1<<(RTC_TMBR_MINB0_POS))
#define RTC_TMBR_MINB1                  ((uint32_t)1<<(RTC_TMBR_MINB1_POS))
#define RTC_TMBR_MINB2                  ((uint32_t)1<<(RTC_TMBR_MINB2_POS))
#define RTC_TMBR_MINB3                  ((uint32_t)1<<(RTC_TMBR_MINB3_POS))
#define RTC_TMBR_MINB4                  ((uint32_t)1<<(RTC_TMBR_MINB4_POS))
#define RTC_TMBR_MINB5                  ((uint32_t)1<<(RTC_TMBR_MINB5_POS))
#define RTC_TMBR_MINB6                  ((uint32_t)1<<(RTC_TMBR_MINB6_POS))
#define RTC_TMBR_HOURB                  ((uint32_t)0x3F<<(RTC_TMBR_HOURB0_POS))
#define RTC_TMBR_HOURB0                 ((uint32_t)1<<(RTC_TMBR_HOURB0_POS))
#define RTC_TMBR_HOURB1                 ((uint32_t)1<<(RTC_TMBR_HOURB1_POS))
#define RTC_TMBR_HOURB2                 ((uint32_t)1<<(RTC_TMBR_HOURB2_POS))
#define RTC_TMBR_HOURB3                 ((uint32_t)1<<(RTC_TMBR_HOURB3_POS))
#define RTC_TMBR_HOURB4                 ((uint32_t)1<<(RTC_TMBR_HOURB4_POS))
#define RTC_TMBR_HOURB5                 ((uint32_t)1<<(RTC_TMBR_HOURB5_POS))
#define RTC_TMBR_AMPMB                  ((uint32_t)1<<(RTC_TMBR_AMPMB_POS))
#define RTC_TMBR_WEKB                   ((uint32_t)7<<(RTC_TMBR_WEKB0_POS))
#define RTC_TMBR_WEKB0                  ((uint32_t)1<<(RTC_TMBR_WEKB0_POS))
#define RTC_TMBR_WEKB1                  ((uint32_t)1<<(RTC_TMBR_WEKB1_POS))
#define RTC_TMBR_WEKB2                  ((uint32_t)1<<(RTC_TMBR_WEKB2_POS))

/* RTC_DTBR λ�� */
#define RTC_DTBR_DAYB0_POS              (0)
#define RTC_DTBR_DAYB1_POS              (1)
#define RTC_DTBR_DAYB2_POS              (2)
#define RTC_DTBR_DAYB3_POS              (3)
#define RTC_DTBR_DAYB4_POS              (4)
#define RTC_DTBR_DAYB5_POS              (5)
#define RTC_DTBR_MTHB0_POS              (8)
#define RTC_DTBR_MTHB1_POS              (9)
#define RTC_DTBR_MTHB2_POS              (10)
#define RTC_DTBR_MTHB3_POS              (11)
#define RTC_DTBR_MTHB4_POS              (12)
#define RTC_DTBR_YEARB0_POS             (16)
#define RTC_DTBR_YEARB1_POS             (17)
#define RTC_DTBR_YEARB2_POS             (18)
#define RTC_DTBR_YEARB3_POS             (19)
#define RTC_DTBR_YEARB4_POS             (20)
#define RTC_DTBR_YEARB5_POS             (21)
#define RTC_DTBR_YEARB6_POS             (22)
#define RTC_DTBR_YEARB7_POS             (23)
#define RTC_DTBR_DAYB                   ((uint32_t)0x7F<<(RTC_DTBR_DAYB0_POS))
#define RTC_DTBR_DAYB0                  ((uint32_t)1<<(RTC_DTBR_DAYB0_POS))
#define RTC_DTBR_DAYB1                  ((uint32_t)1<<(RTC_DTBR_DAYB1_POS))
#define RTC_DTBR_DAYB2                  ((uint32_t)1<<(RTC_DTBR_DAYB2_POS))
#define RTC_DTBR_DAYB3                  ((uint32_t)1<<(RTC_DTBR_DAYB3_POS))
#define RTC_DTBR_DAYB4                  ((uint32_t)1<<(RTC_DTBR_DAYB4_POS))
#define RTC_DTBR_DAYB5                  ((uint32_t)1<<(RTC_DTBR_DAYB5_POS))
#define RTC_DTBR_MTHB                   ((uint32_t)0x7F<<(RTC_DTBR_MTHB0_POS))
#define RTC_DTBR_MTHB0                  ((uint32_t)1<<(RTC_DTBR_MTHB0_POS))
#define RTC_DTBR_MTHB1                  ((uint32_t)1<<(RTC_DTBR_MTHB1_POS))
#define RTC_DTBR_MTHB2                  ((uint32_t)1<<(RTC_DTBR_MTHB2_POS))
#define RTC_DTBR_MTHB3                  ((uint32_t)1<<(RTC_DTBR_MTHB3_POS))
#define RTC_DTBR_MTHB4                  ((uint32_t)1<<(RTC_DTBR_MTHB4_POS))
#define RTC_DTBR_YEARB                  ((uint32_t)0x3F<<(RTC_DTBR_YEARB0_POS))
#define RTC_DTBR_YEARB0                 ((uint32_t)1<<(RTC_DTBR_YEARB0_POS))
#define RTC_DTBR_YEARB1                 ((uint32_t)1<<(RTC_DTBR_YEARB1_POS))
#define RTC_DTBR_YEARB2                 ((uint32_t)1<<(RTC_DTBR_YEARB2_POS))
#define RTC_DTBR_YEARB3                 ((uint32_t)1<<(RTC_DTBR_YEARB3_POS))
#define RTC_DTBR_YEARB4                 ((uint32_t)1<<(RTC_DTBR_YEARB4_POS))
#define RTC_DTBR_YEARB5                 ((uint32_t)1<<(RTC_DTBR_YEARB5_POS))
#define RTC_DTBR_YEARB6                 ((uint32_t)1<<(RTC_DTBR_YEARB6_POS))
#define RTC_DTBR_YEARB7                 ((uint32_t)1<<(RTC_DTBR_YEARB7_POS))

/* RTC_IER λ�� */
#define RTC_IER_SECIE_POS               (0)
#define RTC_IER_MINIE_POS               (1)
#define RTC_IER_HOURIE_POS              (2)
#define RTC_IER_DAYIE_POS               (3)
#define RTC_IER_ALRAIE_POS              (4)
#define RTC_IER_ALRBIE_POS              (5)
#define RTC_IER_TTIE_POS                (6)
#define RTC_IER_RTCT0IE_POS             (8)
#define RTC_IER_RTCT1IE_POS             (9)
#define RTC_IER_TSOVFIE_POS             (10)
#define RTC_IER_TSIE_POS                (11)
#define RTC_IER_TP0S0_POS               (16)
#define RTC_IER_TP0S1_POS               (17)
#define RTC_IER_TP0S2_POS               (18)
#define RTC_IER_TP1S0_POS               (19)
#define RTC_IER_TP1S1_POS               (20)
#define RTC_IER_TP1S2_POS               (21)
#define RTC_IER_TPEN_POS                (22)
#define RTC_IER_SECIE                   ((uint32_t)1<<(RTC_IER_SECIE_POS))
#define RTC_IER_MINIE                   ((uint32_t)1<<(RTC_IER_MINIE_POS))
#define RTC_IER_HOURIE                  ((uint32_t)1<<(RTC_IER_HOURIE_POS))
#define RTC_IER_DAYIE                   ((uint32_t)1<<(RTC_IER_DAYIE_POS))
#define RTC_IER_ALRAIE                  ((uint32_t)1<<(RTC_IER_ALRAIE_POS))
#define RTC_IER_ALRBIE                  ((uint32_t)1<<(RTC_IER_ALRBIE_POS))
#define RTC_IER_TTIE                    ((uint32_t)1<<(RTC_IER_TTIE_POS))
#define RTC_IER_RTCT0IE                 ((uint32_t)1<<(RTC_IER_RTCT0IE_POS))
#define RTC_IER_RTCT1IE                 ((uint32_t)1<<(RTC_IER_RTCT1IE_POS))
#define RTC_IER_TSOVFIE                 ((uint32_t)1<<(RTC_IER_TSOVFIE_POS))
#define RTC_IER_TSIE                    ((uint32_t)1<<(RTC_IER_TSIE_POS))
#define RTC_IER_TP0S                    ((uint32_t)0x7<<(RTC_IER_TP0S0_POS))
#define RTC_IER_TP0S0                   ((uint32_t)1<<(RTC_IER_TP0S0_POS))
#define RTC_IER_TP0S1                   ((uint32_t)1<<(RTC_IER_TP0S1_POS))
#define RTC_IER_TP0S2                   ((uint32_t)1<<(RTC_IER_TP0S2_POS))
#define RTC_IER_TP1S                    ((uint32_t)0x7<<(RTC_IER_TP1S0_POS))
#define RTC_IER_TP1S0                   ((uint32_t)1<<(RTC_IER_TP1S0_POS))
#define RTC_IER_TP1S1                   ((uint32_t)1<<(RTC_IER_TP1S1_POS))
#define RTC_IER_TP1S2                   ((uint32_t)1<<(RTC_IER_TP1S2_POS))
#define RTC_IER_TPEN                    ((uint32_t)1<<(RTC_IER_TPEN_POS))

/* RTC_IFR λ�� */
#define RTC_IFR_SECIF_POS               (0)
#define RTC_IFR_MINIF_POS               (1)
#define RTC_IFR_HOURIF_POS              (2)
#define RTC_IFR_DAYIF_POS               (3)
#define RTC_IFR_ALRAIF_POS              (4)
#define RTC_IFR_ALRBIF_POS              (5)
#define RTC_IFR_TTIF_POS                (6)
#define RTC_IFR_RTCT0IF_POS             (8)
#define RTC_IFR_RTCT1IF_POS             (9)
#define RTC_IFR_TSOVFIF_POS             (10)
#define RTC_IFR_TSIF_POS                (11)
#define RTC_IFR_SECIC_POS               (16)
#define RTC_IFR_MINIC_POS               (17)
#define RTC_IFR_HOURIC_POS              (18)
#define RTC_IFR_DAYIC_POS               (19)
#define RTC_IFR_ALRAIC_POS              (20)
#define RTC_IFR_ALRBIC_POS              (21)
#define RTC_IFR_TTIC_POS                (22)
#define RTC_IFR_RTCT0IC_POS             (24)
#define RTC_IFR_RTCT1IC_POS             (25)
#define RTC_IFR_TSOVFIC_POS             (26)
#define RTC_IFR_TSIC_POS                (27)
#define RTC_IFR_SECIF                   ((uint32_t)1<<(RTC_IFR_SECIF_POS))
#define RTC_IFR_MINIF                   ((uint32_t)1<<(RTC_IFR_MINIF_POS))
#define RTC_IFR_HOURIF                  ((uint32_t)1<<(RTC_IFR_HOURIF_POS))
#define RTC_IFR_DAYIF                   ((uint32_t)1<<(RTC_IFR_DAYIF_POS))
#define RTC_IFR_ALRAIF                  ((uint32_t)1<<(RTC_IFR_ALRAIF_POS))
#define RTC_IFR_ALRBIF                  ((uint32_t)1<<(RTC_IFR_ALRBIF_POS))
#define RTC_IFR_TTIF                    ((uint32_t)1<<(RTC_IFR_TTIF_POS))
#define RTC_IFR_RTCT0IF                 ((uint32_t)1<<(RTC_IFR_RTCT0IF_POS))
#define RTC_IFR_RTCT1IF                 ((uint32_t)1<<(RTC_IFR_RTCT1IF_POS))
#define RTC_IFR_TSOVFIF                 ((uint32_t)1<<(RTC_IFR_TSOVFIF_POS))
#define RTC_IFR_TSIF                    ((uint32_t)1<<(RTC_IFR_TSIF_POS))
#define RTC_IFR_SECIC                   ((uint32_t)1<<(RTC_IFR_SECIC_POS))
#define RTC_IFR_MINIC                   ((uint32_t)1<<(RTC_IFR_MINIC_POS))
#define RTC_IFR_HOURIC                  ((uint32_t)1<<(RTC_IFR_HOURIC_POS))
#define RTC_IFR_DAYIC                   ((uint32_t)1<<(RTC_IFR_DAYIC_POS))
#define RTC_IFR_ALRAIC                  ((uint32_t)1<<(RTC_IFR_ALRAIC_POS))
#define RTC_IFR_ALRBIC                  ((uint32_t)1<<(RTC_IFR_ALRBIC_POS))
#define RTC_IFR_TTIC                    ((uint32_t)1<<(RTC_IFR_TTIC_POS))
#define RTC_IFR_RTCT0IC                 ((uint32_t)1<<(RTC_IFR_RTCT0IC_POS))
#define RTC_IFR_RTCT1IC                 ((uint32_t)1<<(RTC_IFR_RTCT1IC_POS))
#define RTC_IFR_TSOVFIC                 ((uint32_t)1<<(RTC_IFR_TSOVFIC_POS))
#define RTC_IFR_TSIC                    ((uint32_t)1<<(RTC_IFR_TSIC_POS))
/* ʵʱʱ�� (RTC)������� */


/* ----------------------------------------------------------------------------
   -- �������Ź�(IWDT)
   ---------------------------------------------------------------------------- */

/* IWDT - ����Ĵ����ڴ�ṹ */
typedef struct IWDT_MemMap {
    volatile uint32_t CTL;              /* �������Ź����ƼĴ���, ƫ��:0x00 */
    volatile uint32_t FD;               /* �������Ź�ι���Ĵ���, ƫ��:0x04 */
}IWDT_SFRmap;

/* ----------------------------------------------------------------------------
   -- IWDT - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* IWDT - �Ĵ�����ڵ�ַ */
#define IWDT_ADDR                       ((uint32_t)0x40001200)
#define IWDT_SFR                        ((IWDT_SFRmap *) IWDT_ADDR)

/* IWDT - �Ĵ������ */
#define IWDT_CTL                        (IWDT_SFR->CTL)
#define IWDT_FD                         (IWDT_SFR->FD)

/* IWDT_CTL λ�� */
#define IWDT_CTL_IWDTPS0_POS            (0)
#define IWDT_CTL_IWDTOVF0_POS           (4)
#define IWDT_CTL_TPEN_POS               (30)
#define IWDT_CTL_IWDTEN_POS             (31)
#define IWDT_CTL_IWDTPS                 ((uint32_t)0xF<<(IWDT_CTL_IWDTPS0_POS))
#define IWDT_CTL_IWDTOVF                ((uint32_t)0xFFF<<(IWDT_CTL_IWDTOVF0_POS))
#define IWDT_CTL_TPEN                   ((uint32_t)1<<(IWDT_CTL_TPEN_POS))
#define IWDT_CTL_IWDTEN                 ((uint32_t)1<<(IWDT_CTL_IWDTEN_POS))
/* �������Ź�(IWDT)������� */


/* ----------------------------------------------------------------------------
   -- ���ڿ��Ź�(WWDT)
   ---------------------------------------------------------------------------- */

/* WWDT - ����Ĵ����ڴ�ṹ */
typedef struct WWDT_MemMap {
    volatile uint32_t CTL;              /* �������Ź����ƼĴ���, ƫ��:0x00 */
    volatile uint32_t CNT;              /* �������Ź������Ĵ���, ƫ��:0x04 */
}WWDT_SFRmap;

/* ----------------------------------------------------------------------------
   -- WWDT - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* WWDT - �Ĵ�����ڵ�ַ */
#define WWDT_ADDR                       ((uint32_t)0x40001280)
#define WWDT_SFR                        ((WWDT_SFRmap *) WWDT_ADDR)

/* WWDT - �Ĵ������ */
#define WWDT_CTL                        (WWDT_SFR->CTL)
#define WWDT_CNT                        (WWDT_SFR->CNT)

/* WWDT_CTL λ�� */
#define WWDT_CTL_WWDTEN_POS             (0)
#define WWDT_CTL_WWDTIE_POS             (1)
#define WWDT_CTL_WWDTIF_POS             (2)
#define WWDT_CTL_WPS0_POS               (3)
#define WWDT_CTL_WW0_POS                (8)
#define WWDT_CTL_WWDTIC_POS             (15)
#define WWDT_CTL_WWDTEN                 ((uint32_t)1<<(WWDT_CTL_WWDTEN_POS))
#define WWDT_CTL_WWDTIE                 ((uint32_t)1<<(WWDT_CTL_WWDTIE_POS))
#define WWDT_CTL_WWDTIF                 ((uint32_t)1<<(WWDT_CTL_WWDTIF_POS))
#define WWDT_CTL_WPS                    ((uint32_t)0x1F<<(WWDT_CTL_WPS0_POS))
#define WWDT_CTL_WW                     ((uint32_t)0x7F<<(WWDT_CTL_WW0_POS))
#define WWDT_CTL_WWDTIC                 ((uint32_t)1<<(WWDT_CTL_WWDTIC_POS))

/* WWDT_CNT λ�� */
#define WWDT_CNT_WT_POS                 (0)
#define WWDT_CNT_WT                     ((uint32_t)0x7F<<(WWDT_CNT_WT_POS))
/* �������Ź�(WWDT)������� */

/* ----------------------------------------------------------------------------
   -- ��λ(RST)
   ---------------------------------------------------------------------------- */

/* RST - ����Ĵ����ڴ�ṹ */
typedef struct RST_MemMap {
    volatile uint32_t CTL0;             /* ��λ���ƼĴ���0, ƫ��:0x0 */
    volatile uint32_t CTL1;             /* ��λ���ƼĴ���1, ƫ��:0x4 */
    volatile uint32_t CTL2;             /* ��λ���ƼĴ���2, ƫ��:0x8 */
    volatile uint32_t CTL3;             /* ��λ���ƼĴ���3, ƫ��:0xC */
}RST_SFRmap;

/* ----------------------------------------------------------------------------
   -- RST - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* RST - �Ĵ�����ڵ�ַ */
#define RST_ADDR                        ((uint32_t)0x40001500)
#define RST_SFR                         ((RST_SFRmap *) RST_ADDR)

/* RST_SFR - �Ĵ������ */
#define RST_CTL0                        (RST_SFR->CTL0)
#define RST_CTL1                        (RST_SFR->CTL1)
#define RST_CTL2                        (RST_SFR->CTL2)
#define RST_CTL3                        (RST_SFR->CTL3)

/* RST_CTL0 λ�� */
#define RST_CTL0_GPIOARST_POS           (0)
#define RST_CTL0_GPIOBRST_POS           (1)
#define RST_CTL0_GPIOCRST_POS           (2)
#define RST_CTL0_GPIODRST_POS           (3)
#define RST_CTL0_GPIOERST_POS           (4)
#define RST_CTL0_GPIOFRST_POS           (5)
#define RST_CTL0_GPIOGRST_POS           (6)
#define RST_CTL0_GPIOHRST_POS           (7)
#define RST_CTL0_GPIOARST               ((uint32_t)1<<(RST_CTL0_GPIOARST_POS))
#define RST_CTL0_GPIOBRST               ((uint32_t)1<<(RST_CTL0_GPIOBRST_POS))
#define RST_CTL0_GPIOCRST               ((uint32_t)1<<(RST_CTL0_GPIOCRST_POS))
#define RST_CTL0_GPIODRST               ((uint32_t)1<<(RST_CTL0_GPIODRST_POS))
#define RST_CTL0_GPIOERST               ((uint32_t)1<<(RST_CTL0_GPIOERST_POS))
#define RST_CTL0_GPIOFRST               ((uint32_t)1<<(RST_CTL0_GPIOFRST_POS))
#define RST_CTL0_GPIOGRST               ((uint32_t)1<<(RST_CTL0_GPIOGRST_POS))
#define RST_CTL0_GPIOHRST               ((uint32_t)1<<(RST_CTL0_GPIOHRST_POS))

/* RST_CTL1 λ�� */
#define RST_CTL1_QEI1RST_POS            (1)
#ifdef  KF32F_Periph_gptime1
#define RST_CTL1_T1RST_POS              (2)
#endif
#ifdef  KF32F_Periph_gptime2
#define RST_CTL1_T2RST_POS              (3)
#endif
#ifdef  KF32F_Periph_gptime3
#define RST_CTL1_T3RST_POS              (4)
#endif
#ifdef  KF32F_Periph_gptime4
#define RST_CTL1_T4RST_POS              (5)
#endif
#ifdef  KF32F_Periph_atime5_time6
#define RST_CTL1_T5T6RST_POS            (6)
#endif
#ifdef  KF32F_Periph_atime9_time10
#define RST_CTL1_T9T10RST_POS           (8)
#endif
#define RST_CTL1_QEI0RST_POS            (10)
#ifdef  KF32F_Periph_adc0
#define RST_CTL1_ADC0RST_POS            (11)
#endif
#ifdef  KF32F_Periph_adc1
#define RST_CTL1_ADC1RST_POS            (12)
#endif
#ifdef  KF32F_Periph_adc2
#define RST_CTL1_ADC2RST_POS            (13)
#endif
#ifdef  KF32F_Periph_dac0
#define RST_CTL1_DAC0RST_POS            (14)
#endif
#ifdef  KF32F_Periph_dac1
#define RST_CTL1_DAC1RST_POS            (15)
#endif
#ifdef KF32F_Periph_cmp
#define RST_CTL1_CMPRST_POS             (16)
#endif
#ifdef 	KF32F_Periph_gptime0
#define RST_CTL1_T0RST_POS              (17)
#endif
//#define RST_CTL1_CTOUCHRST_POS          (18)
#ifdef  KF32F_Periph_usart0
#define RST_CTL1_USART0RST_POS          (19)
#endif
#ifdef  KF32F_Periph_usart1
#define RST_CTL1_USART1RST_POS          (20)
#endif
#ifdef  KF32F_Periph_usart2
#define RST_CTL1_USART2RST_POS          (21)
#endif
#ifdef  KF32F_Periph_usart3
#define RST_CTL1_USART3RST_POS          (22)
#endif
#ifdef  KF32F_Periph_usart4
#define RST_CTL1_USART4RST_POS          (23)
#endif
#ifdef  KF32F_Periph_spi0
#define RST_CTL1_SPI0RST_POS            (24)
#endif
#ifdef  KF32F_Periph_spi1
#define RST_CTL1_SPI1RST_POS            (25)
#endif
#ifdef  KF32F_Periph_i2c0
#define RST_CTL1_I2C0RST_POS            (26)
#endif
#ifdef  KF32F_Periph_i2c1
#define RST_CTL1_I2C1RST_POS            (27)
#endif
#ifdef  KF32F_Periph_i2c2
#define RST_CTL1_I2C2RST_POS            (28)
#endif
#ifdef  KF32F_Periph_lcd
#define RST_CTL1_LCDRST_POS             (29)
#endif
#ifdef  KF32F_Periph_usb
#define RST_CTL1_USBRST_POS             (31)
#endif
#define RST_CTL1_QEI1RST                ((uint32_t)1<<(RST_CTL1_QEI1RST_POS))
#ifdef  KF32F_Periph_gptime1
#define RST_CTL1_T1RST                  ((uint32_t)1<<(RST_CTL1_T1RST_POS))
#endif
#ifdef  KF32F_Periph_gptime2
#define RST_CTL1_T2RST                  ((uint32_t)1<<(RST_CTL1_T2RST_POS))
#endif
#ifdef  KF32F_Periph_gptime3
#define RST_CTL1_T3RST                  ((uint32_t)1<<(RST_CTL1_T3RST_POS))
#endif
#ifdef  KF32F_Periph_gptime4
#define RST_CTL1_T4RST                  ((uint32_t)1<<(RST_CTL1_T4RST_POS))
#endif
#ifdef  KF32F_Periph_atime5_time6
#define RST_CTL1_T5T6RST                ((uint32_t)1<<(RST_CTL1_T5T6RST_POS))
#endif
#ifdef  KF32F_Periph_atime9_time10
#define RST_CTL1_T9T10RST               ((uint32_t)1<<(RST_CTL1_T9T10RST_POS))
#endif
#define RST_CTL1_QEI0RST                ((uint32_t)1<<(RST_CTL1_QEI0RST_POS))
#ifdef  KF32F_Periph_adc0
#define RST_CTL1_ADC0RST                ((uint32_t)1<<(RST_CTL1_ADC0RST_POS))
#endif
#ifdef  KF32F_Periph_adc1
#define RST_CTL1_ADC1RST                ((uint32_t)1<<(RST_CTL1_ADC1RST_POS))
#endif
#ifdef  KF32F_Periph_adc2
#define RST_CTL1_ADC2RST                ((uint32_t)1<<(RST_CTL1_ADC2RST_POS))
#endif
#ifdef  KF32F_Periph_dac0
#define RST_CTL1_DAC0RST                ((uint32_t)1<<(RST_CTL1_DAC0RST_POS))
#endif
#ifdef  KF32F_Periph_dac1
#define RST_CTL1_DAC1RST                ((uint32_t)1<<(RST_CTL1_DAC1RST_POS))
#endif
#ifdef  KF32F_Periph_cmp
#define RST_CTL1_CMPRST                 ((uint32_t)1<<(RST_CTL1_CMPRST_POS))
#endif
#ifdef 	KF32F_Periph_gptime0
#define RST_CTL1_T0RST                  ((uint32_t)1<<(RST_CTL1_T0RST_POS))
#endif
//#define RST_CTL1_CTOUCHRST              ((uint32_t)1<<(RST_CTL1_CTOUCHRST_POS))
#ifdef  KF32F_Periph_usart0
#define RST_CTL1_USART0RST              ((uint32_t)1<<(RST_CTL1_USART0RST_POS))
#endif
#ifdef  KF32F_Periph_usart1
#define RST_CTL1_USART1RST              ((uint32_t)1<<(RST_CTL1_USART1RST_POS))
#endif
#ifdef  KF32F_Periph_usart2
#define RST_CTL1_USART2RST              ((uint32_t)1<<(RST_CTL1_USART2RST_POS))
#endif
#ifdef  KF32F_Periph_usart3
#define RST_CTL1_USART3RST              ((uint32_t)1<<(RST_CTL1_USART3RST_POS))
#endif
#ifdef  KF32F_Periph_usart4
#define RST_CTL1_USART4RST              ((uint32_t)1<<(RST_CTL1_USART4RST_POS))
#endif
#ifdef  KF32F_Periph_spi0
#define RST_CTL1_SPI0RST                ((uint32_t)1<<(RST_CTL1_SPI0RST_POS))
#endif
#ifdef  KF32F_Periph_spi1
#define RST_CTL1_SPI1RST                ((uint32_t)1<<(RST_CTL1_SPI1RST_POS))
#endif
#ifdef  KF32F_Periph_i2c0
#define RST_CTL1_I2C0RST                ((uint32_t)1<<(RST_CTL1_I2C0RST_POS))
#endif
#ifdef  KF32F_Periph_i2c1
#define RST_CTL1_I2C1RST                ((uint32_t)1<<(RST_CTL1_I2C1RST_POS))
#endif
#ifdef  KF32F_Periph_i2c2
#define RST_CTL1_I2C2RST                ((uint32_t)1<<(RST_CTL1_I2C2RST_POS))
#endif
#ifdef  KF32F_Periph_lcd
#define RST_CTL1_LCDRST                 ((uint32_t)1<<(RST_CTL1_LCDRST_POS))
#endif
#ifdef  KF32F_Periph_usb
#define RST_CTL1_USBRST                 ((uint32_t)1<<(RST_CTL1_USBRST_POS))
#endif
/* RST_CTL2 λ�� */
#ifdef  KF32F_Periph_can0
#define RST_CTL2_CAN0RST_POS            (2)
#endif
#ifdef  KF32F_Periph_can1
#define RST_CTL2_CAN1RST_POS            (3)
#endif
#define RST_CTL2_WWDTRST_POS            (5)
#ifdef KF32F_Periph_dma0
#define RST_CTL2_DMA0RST_POS            (12)
#endif
#ifdef KF32F_Periph_dma1
#define RST_CTL2_DMA1RST_POS            (14)
#endif
#ifdef  KF32F_Periph_btime14
#define RST_CTL2_T14RST_POS             (16)
#endif
#ifdef  KF32F_Periph_btime15
#define RST_CTL2_T15RST_POS             (17)
#endif
#ifdef  KF32F_Periph_can2
#define RST_CTL2_CAN2RST_POS            (18)
#endif
#ifdef  KF32F_Periph_can3
#define RST_CTL2_CAN3RST_POS            (19)
#endif
#ifdef  KF32F_Periph_gptime18
#define RST_CTL2_T18RST_POS             (21)
#endif
#ifdef  KF32F_Periph_gptime19
#define RST_CTL2_T19RST_POS             (22)
#endif
#ifdef  KF32F_Periph_gptime20
#define RST_CTL2_T20RST_POS             (23)
#endif
#ifdef  KF32F_Periph_gptime21
#define RST_CTL2_T21RST_POS             (24)
#endif
#ifdef  KF32F_Periph_gptime22
#define RST_CTL2_T22RST_POS             (25)
#endif
#ifdef  KF32F_Periph_gptime23
#define RST_CTL2_T23RST_POS             (26)
#endif
#ifdef  KF32F_Periph_usart5
#define RST_CTL2_USART5RST_POS          (29)
#endif
#ifdef  KF32F_Periph_usart6
#define RST_CTL2_USART6RST_POS          (30)
#endif
#ifdef  KF32F_Periph_usart7
#define RST_CTL2_USART7RST_POS          (31)
#endif
#ifdef  KF32F_Periph_can0
#define RST_CTL2_CAN0RST                ((uint32_t)1<<(RST_CTL2_CAN0RST_POS))
#endif
#ifdef  KF32F_Periph_can1
#define RST_CTL2_CAN1RST                ((uint32_t)1<<(RST_CTL2_CAN1RST_POS))
#endif
#define RST_CTL2_WWDTRST                ((uint32_t)1<<(RST_CTL2_WWDTRST_POS))
#ifdef KF32F_Periph_dma0
#define RST_CTL2_DMA0RST                ((uint32_t)1<<(RST_CTL2_DMA0RST_POS))
#endif
#ifdef KF32F_Periph_dma1
#define RST_CTL2_DMA1RST                ((uint32_t)1<<(RST_CTL2_DMA1RST_POS))
#endif
#ifdef  KF32F_Periph_btime14
#define RST_CTL2_T14RST                 ((uint32_t)1<<(RST_CTL2_T14RST_POS))
#endif
#ifdef  KF32F_Periph_btime15
#define RST_CTL2_T15RST                 ((uint32_t)1<<(RST_CTL2_T15RST_POS))
#endif
#ifdef  KF32F_Periph_can2
#define RST_CTL2_CAN2RST                ((uint32_t)1<<(RST_CTL2_CAN2RST_POS))
#endif
#ifdef  KF32F_Periph_can3
#define RST_CTL2_CAN3RST                ((uint32_t)1<<(RST_CTL2_CAN3RST_POS))
#endif
#ifdef  KF32F_Periph_gptime18
#define RST_CTL2_T18RST                 ((uint32_t)1<<(RST_CTL2_T18RST_POS))
#endif
#ifdef  KF32F_Periph_gptime19
#define RST_CTL2_T19RST                 ((uint32_t)1<<(RST_CTL2_T19RST_POS))
#endif
#ifdef  KF32F_Periph_gptime20
#define RST_CTL2_T20RST                 ((uint32_t)1<<(RST_CTL2_T20RST_POS))
#endif
#ifdef  KF32F_Periph_gptime21
#define RST_CTL2_T21RST                 ((uint32_t)1<<(RST_CTL2_T21RST_POS))
#endif
#ifdef  KF32F_Periph_gptime22
#define RST_CTL2_T22RST                 ((uint32_t)1<<(RST_CTL2_T22RST_POS))
#endif
#ifdef  KF32F_Periph_gptime23
#define RST_CTL2_T23RST                 ((uint32_t)1<<(RST_CTL2_T23RST_POS))
#endif
#ifdef  KF32F_Periph_usart5
#define RST_CTL2_USART5RST              ((uint32_t)1<<(RST_CTL2_USART5RST_POS))
#endif
#ifdef  KF32F_Periph_usart6
#define RST_CTL2_USART6RST              ((uint32_t)1<<(RST_CTL2_USART6RST_POS))
#endif
#ifdef  KF32F_Periph_usart7
#define RST_CTL2_USART7RST              ((uint32_t)1<<(RST_CTL2_USART7RST_POS))
#endif

/* RST_CTL3 λ�� */
#ifdef  KF32F_Periph_spi2
#define RST_CTL3_SPI2RST_POS            (1)
#endif
#ifdef  KF32F_Periph_spi3
#define RST_CTL3_SPI3RST_POS            (2)
#endif
#ifdef  KF32F_Periph_i2c3
#define RST_CTL3_I2C3RST_POS            (7)
#endif
#ifdef  KF32F_Periph_crc
#define RST_CTL3_CRCRST_POS             (13)
#endif
#ifdef  KF32F_Periph_aes
#define RST_CTL3_AESRST_POS             (14)
#endif
#ifdef  KF32F_Periph_led
#define RST_CTL3_LEDRST_POS             (15)
#endif
#ifdef  KF32F_Periph_exic
#define RST_CTL3_EXICRST_POS            (16)
#endif
#ifdef  KF32F_Periph_can4
#define RST_CTL3_CAN4RST_POS            (17)
#endif
#ifdef  KF32F_Periph_can5
#define RST_CTL3_CAN5RST_POS            (18)
#endif
#ifdef  KF32F_Periph_cfgl
#define RST_CTL3_CFGLRST_POS            (19)
#endif
#ifdef  KF32F_Periph_op
#define RST_CTL3_OPRST_POS              (20)
#endif
#ifdef  KF32F_Periph_spi2
#define RST_CTL3_SPI2RST                ((uint32_t)1<<(RST_CTL3_SPI2RST_POS))
#endif
#ifdef  KF32F_Periph_spi3
#define RST_CTL3_SPI3RST                ((uint32_t)1<<(RST_CTL3_SPI3RST_POS))
#endif
#ifdef  KF32F_Periph_i2c3
#define RST_CTL3_I2C3RST                ((uint32_t)1<<(RST_CTL3_I2C3RST_POS))
#endif
#ifdef  KF32F_Periph_crc
#define RST_CTL3_CRCRST                 ((uint32_t)1<<(RST_CTL3_CRCRST_POS))
#endif
#ifdef  KF32F_Periph_aes
#define RST_CTL3_AESRST                 ((uint32_t)1<<(RST_CTL3_AESRST_POS))
#endif
#ifdef  KF32F_Periph_led
#define RST_CTL3_LEDRST                 ((uint32_t)1<<(RST_CTL3_LEDRST_POS))
#endif
#ifdef  KF32F_Periph_exic
#define RST_CTL3_EXICRST                ((uint32_t)1<<(RST_CTL3_EXICRST_POS))
#endif
#ifdef  KF32F_Periph_can4
#define RST_CTL3_CAN4RST                ((uint32_t)1<<(RST_CTL3_CAN4RST_POS))
#endif
#ifdef  KF32F_Periph_can5
#define RST_CTL3_CAN5RST                ((uint32_t)1<<(RST_CTL3_CAN5RST_POS))
#endif
#ifdef  KF32F_Periph_cfgl
#define RST_CTL3_CFGLRST                ((uint32_t)1<<(RST_CTL3_CFGLRST_POS))
#endif
#ifdef  KF32F_Periph_op
#define RST_CTL3_OPRST                  ((uint32_t)1<<(RST_CTL3_OPRST_POS))
#endif
/* ��λ(RST)������� */


/* ----------------------------------------------------------------------------
   -- ����ģ��ʱ��ʹ��ģ��(PCLK)
   ---------------------------------------------------------------------------- */

/* PCLK - ����Ĵ����ڴ�ṹ */
typedef struct PCLK_MemMap {
    volatile uint32_t CTL0;             /* PCLK���ƼĴ���0, ƫ��:0x00 */
    volatile uint32_t CTL1;             /* PCLK���ƼĴ���1, ƫ��:0x04 */
    volatile uint32_t CTL2;             /* PCLK���ƼĴ���2, ƫ��:0x08 */
    volatile uint32_t CTL3;             /* PCLK���ƼĴ���3, ƫ��:0x0C */
}PCLK_SFRmap;

/* ----------------------------------------------------------------------------
   -- PCLK - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* PCLK - �Ĵ�����ڵ�ַ */
#define PCLK_ADDR                       ((uint32_t)0x40002640)
#define PCLK_SFR                        ((PCLK_SFRmap *) PCLK_ADDR)

/* PCLK - �Ĵ������ */
#define PCLK_CTL0                       (PCLK_SFR->CTL0)
#define PCLK_CTL1                       (PCLK_SFR->CTL1)
#define PCLK_CTL2                       (PCLK_SFR->CTL2)
#define PCLK_CTL3                       (PCLK_SFR->CTL3)

/* PCLK_CTL0 λ�� */
#define PCLK_CTL0_GPIOACLKEN_POS        (0x0)
#define PCLK_CTL0_GPIOBCLKEN_POS        (0x1)
#define PCLK_CTL0_GPIOCCLKEN_POS        (0x2)
#define PCLK_CTL0_GPIODCLKEN_POS        (0x3)
#define PCLK_CTL0_GPIOECLKEN_POS        (0x4)
#define PCLK_CTL0_GPIOFCLKEN_POS        (0x5)
#define PCLK_CTL0_GPIOGCLKEN_POS        (0x6)
#define PCLK_CTL0_GPIOHCLKEN_POS        (0x7)
#define PCLK_CTL0_GPIOACLKEN            ((uint32_t)1<<(PCLK_CTL0_GPIOACLKEN_POS))
#define PCLK_CTL0_GPIOBCLKEN            ((uint32_t)1<<(PCLK_CTL0_GPIOBCLKEN_POS))
#define PCLK_CTL0_GPIOCCLKEN            ((uint32_t)1<<(PCLK_CTL0_GPIOCCLKEN_POS))
#define PCLK_CTL0_GPIODCLKEN            ((uint32_t)1<<(PCLK_CTL0_GPIODCLKEN_POS))
#define PCLK_CTL0_GPIOECLKEN            ((uint32_t)1<<(PCLK_CTL0_GPIOECLKEN_POS))
#define PCLK_CTL0_GPIOFCLKEN            ((uint32_t)1<<(PCLK_CTL0_GPIOFCLKEN_POS))
#define PCLK_CTL0_GPIOGCLKEN            ((uint32_t)1<<(PCLK_CTL0_GPIOGCLKEN_POS))
#define PCLK_CTL0_GPIOHCLKEN            ((uint32_t)1<<(PCLK_CTL0_GPIOHCLKEN_POS))

/* PCLK_CTL1 λ�� */
#define PCLK_CTL1_QEI1CLKEN_POS         (1)
#ifdef  KF32F_Periph_gptime1
#define PCLK_CTL1_T1CLKEN_POS           (2)
#endif
#ifdef  KF32F_Periph_gptime2
#define PCLK_CTL1_T2CLKEN_POS           (3)
#endif
#ifdef  KF32F_Periph_gptime3
#define PCLK_CTL1_T3CLKEN_POS           (4)
#endif
#ifdef  KF32F_Periph_gptime4
#define PCLK_CTL1_T4CLKEN_POS           (5)
#endif
#ifdef  KF32F_Periph_atime5_time6
#define PCLK_CTL1_T5T6CLKEN_POS         (6)
#endif
#ifdef  KF32F_Periph_atime9_time10
#define PCLK_CTL1_T9T10CLKEN_POS        (8)
#endif
#define PCLK_CTL1_QEI0CLKEN_POS         (10)
#ifdef  KF32F_Periph_adc0
#define PCLK_CTL1_ADC0CLKEN_POS         (11)
#endif
#ifdef  KF32F_Periph_adc1
#define PCLK_CTL1_ADC1CLKEN_POS         (12)
#endif
#ifdef  KF32F_Periph_adc2
#define PCLK_CTL1_ADC2CLKEN_POS         (13)
#endif
#ifdef KF32F_Periph_dac0
#define PCLK_CTL1_DAC0CLKEN_POS         (14)
#endif
#ifdef  KF32F_Periph_dac1
#define PCLK_CTL1_DAC1CLKEN_POS         (15)
#endif
#ifdef  KF32F_Periph_cmp
#define PCLK_CTL1_CMPCLKEN_POS          (16)
#endif
#ifdef 	KF32F_Periph_gptime0
#define PCLK_CTL1_T0CLKEN_POS           (17)
#endif
//#define PCLK_CTL1_CTOUCHCLKEN_POS       (18)
#ifdef  KF32F_Periph_usart0
#define PCLK_CTL1_USART0CLKEN_POS       (19)
#endif
#ifdef  KF32F_Periph_usart1
#define PCLK_CTL1_USART1CLKEN_POS       (20)
#endif
#ifdef  KF32F_Periph_usart2
#define PCLK_CTL1_USART2CLKEN_POS       (21)
#endif
#ifdef  KF32F_Periph_usart3
#define PCLK_CTL1_USART3CLKEN_POS       (22)
#endif
#ifdef  KF32F_Periph_usart4
#define PCLK_CTL1_USART4CLKEN_POS       (23)
#endif
#ifdef  KF32F_Periph_spi0
#define PCLK_CTL1_SPI0CLKEN_POS         (24)
#endif
#ifdef  KF32F_Periph_spi1
#define PCLK_CTL1_SPI1CLKEN_POS         (25)
#endif
#ifdef  KF32F_Periph_i2c0
#define PCLK_CTL1_I2C0CLKEN_POS         (26)
#endif
#ifdef  KF32F_Periph_i2c1
#define PCLK_CTL1_I2C1CLKEN_POS         (27)
#endif
#ifdef  KF32F_Periph_i2c2
#define PCLK_CTL1_I2C2CLKEN_POS         (28)
#endif
#ifdef  KF32F_Periph_lcd
#define PCLK_CTL1_LCDCLKEN_POS          (29)
#endif
#ifdef  KF32F_Periph_usb
#define PCLK_CTL1_USBCLKEN_POS          (31)
#endif
#define PCLK_CTL1_QEI1CLKEN             ((uint32_t)1<<(PCLK_CTL1_QEI1CLKEN_POS))
#ifdef  KF32F_Periph_gptime1
#define PCLK_CTL1_T1CLKEN               ((uint32_t)1<<(PCLK_CTL1_T1CLKEN_POS))
#endif
#ifdef  KF32F_Periph_gptime2
#define PCLK_CTL1_T2CLKEN               ((uint32_t)1<<(PCLK_CTL1_T2CLKEN_POS))
#endif
#ifdef  KF32F_Periph_gptime3
#define PCLK_CTL1_T3CLKEN               ((uint32_t)1<<(PCLK_CTL1_T3CLKEN_POS))
#endif
#ifdef  KF32F_Periph_gptime4
#define PCLK_CTL1_T4CLKEN               ((uint32_t)1<<(PCLK_CTL1_T4CLKEN_POS))
#endif
#ifdef  KF32F_Periph_atime5_time6
#define PCLK_CTL1_T5T6CLKEN             ((uint32_t)1<<(PCLK_CTL1_T5T6CLKEN_POS))
#endif
#ifdef  KF32F_Periph_atime9_time10
#define PCLK_CTL1_T9T10CLKEN            ((uint32_t)1<<(PCLK_CTL1_T9T10CLKEN_POS))
#endif
#define PCLK_CTL1_QEI0CLKEN             ((uint32_t)1<<(PCLK_CTL1_QEI0CLKEN_POS))
#ifdef  KF32F_Periph_adc0
#define PCLK_CTL1_ADC0CLKEN             ((uint32_t)1<<(PCLK_CTL1_ADC0CLKEN_POS))
#endif
#ifdef  KF32F_Periph_adc1
#define PCLK_CTL1_ADC1CLKEN             ((uint32_t)1<<(PCLK_CTL1_ADC1CLKEN_POS))
#endif
#ifdef  KF32F_Periph_adc2
#define PCLK_CTL1_ADC2CLKEN             ((uint32_t)1<<(PCLK_CTL1_ADC2CLKEN_POS))
#endif
#ifdef  KF32F_Periph_dac0
#define PCLK_CTL1_DAC0CLKEN             ((uint32_t)1<<(PCLK_CTL1_DAC0CLKEN_POS))
#endif
#ifdef  KF32F_Periph_dac1
#define PCLK_CTL1_DAC1CLKEN             ((uint32_t)1<<(PCLK_CTL1_DAC1CLKEN_POS))
#endif
#ifdef  KF32F_Periph_cmp
#define PCLK_CTL1_CMPCLKEN              ((uint32_t)1<<(PCLK_CTL1_CMPCLKEN_POS))
#endif
#ifdef 	KF32F_Periph_gptime0
#define PCLK_CTL1_T0CLKEN               ((uint32_t)1<<(PCLK_CTL1_T0CLKEN_POS))
#endif
//#define PCLK_CTL1_CTOUCHCLKEN           ((uint32_t)1<<(PCLK_CTL1_CTOUCHCLKEN_POS))
#ifdef  KF32F_Periph_usart0
#define PCLK_CTL1_USART0CLKEN           ((uint32_t)1<<(PCLK_CTL1_USART0CLKEN_POS))
#endif
#ifdef  KF32F_Periph_usart1
#define PCLK_CTL1_USART1CLKEN           ((uint32_t)1<<(PCLK_CTL1_USART1CLKEN_POS))
#endif
#ifdef  KF32F_Periph_usart2
#define PCLK_CTL1_USART2CLKEN           ((uint32_t)1<<(PCLK_CTL1_USART2CLKEN_POS))
#endif
#ifdef  KF32F_Periph_usart3
#define PCLK_CTL1_USART3CLKEN           ((uint32_t)1<<(PCLK_CTL1_USART3CLKEN_POS))
#endif
#ifdef  KF32F_Periph_usart4
#define PCLK_CTL1_USART4CLKEN           ((uint32_t)1<<(PCLK_CTL1_USART4CLKEN_POS))
#endif
#ifdef  KF32F_Periph_spi0
#define PCLK_CTL1_SPI0CLKEN             ((uint32_t)1<<(PCLK_CTL1_SPI0CLKEN_POS))
#endif
#ifdef  KF32F_Periph_spi1
#define PCLK_CTL1_SPI1CLKEN             ((uint32_t)1<<(PCLK_CTL1_SPI1CLKEN_POS))
#endif
#ifdef  KF32F_Periph_i2c0
#define PCLK_CTL1_I2C0CLKEN             ((uint32_t)1<<(PCLK_CTL1_I2C0CLKEN_POS))
#endif
#ifdef  KF32F_Periph_i2c1
#define PCLK_CTL1_I2C1CLKEN             ((uint32_t)1<<(PCLK_CTL1_I2C1CLKEN_POS))
#endif
#ifdef  KF32F_Periph_i2c2
#define PCLK_CTL1_I2C2CLKEN             ((uint32_t)1<<(PCLK_CTL1_I2C2CLKEN_POS))
#endif
#ifdef  KF32F_Periph_lcd
#define PCLK_CTL1_LCDCLKEN              ((uint32_t)1<<(PCLK_CTL1_LCDCLKEN_POS))
#endif
#ifdef  KF32F_Periph_usb
#define PCLK_CTL1_USBCLKEN              ((uint32_t)1<<(PCLK_CTL1_USBCLKEN_POS))
#endif
/* PCLK_CTL2 λ�� */
#ifdef  KF32F_Periph_can0
#define PCLK_CTL2_CAN0CLKEN_POS         (2)
#endif
#ifdef  KF32F_Periph_can1
#define PCLK_CTL2_CAN1CLKEN_POS         (3)
#endif
#define PCLK_CTL2_WWDTCLKEN_POS         (5)
#ifdef KF32F_Periph_dma0
#define PCLK_CTL2_DMA0CLKEN_POS         (12)
#endif
#ifdef KF32F_Periph_dma1
#define PCLK_CTL2_DMA1CLKEN_POS         (14)
#endif
#ifdef  KF32F_Periph_btime14
#define PCLK_CTL2_T14CLKEN_POS          (16)
#endif
#ifdef  KF32F_Periph_btime15
#define PCLK_CTL2_T15CLKEN_POS          (17)
#endif
#ifdef  KF32F_Periph_can2
#define PCLK_CTL2_CAN2CLKEN_POS         (18)
#endif
#ifdef  KF32F_Periph_can3
#define PCLK_CTL2_CAN3CLKEN_POS         (19)
#endif
#ifdef  KF32F_Periph_gptime18
#define PCLK_CTL2_T18CLKEN_POS          (21)
#endif
#ifdef  KF32F_Periph_gptime19
#define PCLK_CTL2_T19CLKEN_POS          (22)
#endif
#ifdef  KF32F_Periph_gptime20
#define PCLK_CTL2_T20CLKEN_POS          (23)
#endif
#ifdef  KF32F_Periph_gptime21
#define PCLK_CTL2_T21CLKEN_POS          (24)
#endif
#ifdef  KF32F_Periph_gptime22
#define PCLK_CTL2_T22CLKEN_POS          (25)
#endif
#ifdef  KF32F_Periph_gptime23
#define PCLK_CTL2_T23CLKEN_POS          (26)
#endif
#ifdef  KF32F_Periph_usart5
#define PCLK_CTL2_USART5CLKEN_POS       (29)
#endif
#ifdef  KF32F_Periph_usart6
#define PCLK_CTL2_USART6CLKEN_POS       (30)
#endif
#ifdef  KF32F_Periph_usart7
#define PCLK_CTL2_USART7CLKEN_POS       (31)
#endif
#ifdef  KF32F_Periph_can0
#define PCLK_CTL2_CAN0CLKEN             ((uint32_t)1<<(PCLK_CTL2_CAN0CLKEN_POS))
#endif
#ifdef  KF32F_Periph_can1
#define PCLK_CTL2_CAN1CLKEN             ((uint32_t)1<<(PCLK_CTL2_CAN1CLKEN_POS))
#endif
#define PCLK_CTL2_WWDTCLKEN             ((uint32_t)1<<(PCLK_CTL2_WWDTCLKEN_POS))
#ifdef KF32F_Periph_dma0
#define PCLK_CTL2_DMA0CLKEN             ((uint32_t)1<<(PCLK_CTL2_DMA0CLKEN_POS))
#endif
#ifdef KF32F_Periph_dma1
#define PCLK_CTL2_DMA1CLKEN             ((uint32_t)1<<(PCLK_CTL2_DMA1CLKEN_POS))
#endif
#ifdef  KF32F_Periph_btime14
#define PCLK_CTL2_T14CLKEN              ((uint32_t)1<<(PCLK_CTL2_T14CLKEN_POS))
#endif
#ifdef  KF32F_Periph_btime15
#define PCLK_CTL2_T15CLKEN              ((uint32_t)1<<(PCLK_CTL2_T15CLKEN_POS))
#endif
#ifdef  KF32F_Periph_can2
#define PCLK_CTL2_CAN2CLKEN             ((uint32_t)1<<(PCLK_CTL2_CAN2CLKEN_POS))
#endif
#ifdef  KF32F_Periph_can3
#define PCLK_CTL2_CAN3CLKEN             ((uint32_t)1<<(PCLK_CTL2_CAN3CLKEN_POS))
#endif
#ifdef  KF32F_Periph_gptime18
#define PCLK_CTL2_T18CLKEN              ((uint32_t)1<<(PCLK_CTL2_T18CLKEN_POS))
#endif
#ifdef  KF32F_Periph_gptime19
#define PCLK_CTL2_T19CLKEN              ((uint32_t)1<<(PCLK_CTL2_T19CLKEN_POS))
#endif
#ifdef  KF32F_Periph_gptime20
#define PCLK_CTL2_T20CLKEN              ((uint32_t)1<<(PCLK_CTL2_T20CLKEN_POS))
#endif
#ifdef  KF32F_Periph_gptime21
#define PCLK_CTL2_T21CLKEN              ((uint32_t)1<<(PCLK_CTL2_T21CLKEN_POS))
#endif
#ifdef  KF32F_Periph_gptime22
#define PCLK_CTL2_T22CLKEN              ((uint32_t)1<<(PCLK_CTL2_T22CLKEN_POS))
#endif
#ifdef  KF32F_Periph_gptime23
#define PCLK_CTL2_T23CLKEN              ((uint32_t)1<<(PCLK_CTL2_T23CLKEN_POS))
#endif
#ifdef  KF32F_Periph_usart5
#define PCLK_CTL2_USART5CLKEN           ((uint32_t)1<<(PCLK_CTL2_USART5CLKEN_POS))
#endif
#ifdef  KF32F_Periph_usart6
#define PCLK_CTL2_USART6CLKEN           ((uint32_t)1<<(PCLK_CTL2_USART6CLKEN_POS))
#endif
#ifdef  KF32F_Periph_usart7
#define PCLK_CTL2_USART7CLKEN           ((uint32_t)1<<(PCLK_CTL2_USART7CLKEN_POS))
#endif

/* PCLK_CTL3 λ�� */
#ifdef  KF32F_Periph_spi2
#define PCLK_CTL3_SPI2CLKEN_POS         (1)
#endif
#ifdef  KF32F_Periph_spi3
#define PCLK_CTL3_SPI3CLKEN_POS         (2)
#endif
#ifdef  KF32F_Periph_i2c3
#define PCLK_CTL3_I2C3CLKEN_POS         (7)
#endif
#ifdef  KF32F_Periph_crc
#define PCLK_CTL3_CRCCLKEN_POS          (13)
#endif
#ifdef  KF32F_Periph_aes
#define PCLK_CTL3_AESCLKEN_POS          (14)
#endif
#ifdef  KF32F_Periph_led
#define PCLK_CTL3_LEDCLKEN_POS          (15)
#endif
#ifdef  KF32F_Periph_exic
#define PCLK_CTL3_EXICCLKEN_POS         (16)
#endif
#ifdef  KF32F_Periph_can4
#define PCLK_CTL3_CAN4CLKEN_POS         (17)
#endif
#ifdef  KF32F_Periph_can5
#define PCLK_CTL3_CAN5CLKEN_POS         (18)
#endif
#ifdef  KF32F_Periph_cfgl
#define PCLK_CTL3_CFGLCLKEN_POS         (19)
#endif
#ifdef  KF32F_Periph_op
#define PCLK_CTL3_OPCLKEN_POS           (20)
#endif
#ifdef  KF32F_Periph_spi2
#define PCLK_CTL3_SPI2CLKEN             ((uint32_t)1<<(PCLK_CTL3_SPI2CLKEN_POS))
#endif
#ifdef  KF32F_Periph_spi3
#define PCLK_CTL3_SPI3CLKEN             ((uint32_t)1<<(PCLK_CTL3_SPI3CLKEN_POS))
#endif
#ifdef  KF32F_Periph_i2c3
#define PCLK_CTL3_I2C3CLKEN             ((uint32_t)1<<(PCLK_CTL3_I2C3CLKEN_POS))
#endif
#ifdef  KF32F_Periph_crc
#define PCLK_CTL3_CRCCLKEN              ((uint32_t)1<<(PCLK_CTL3_CRCCLKEN_POS))
#endif
#ifdef  KF32F_Periph_aes
#define PCLK_CTL3_AESCLKEN              ((uint32_t)1<<(PCLK_CTL3_AESCLKEN_POS))
#endif
#ifdef  KF32F_Periph_led
#define PCLK_CTL3_LEDCLKEN              ((uint32_t)1<<(PCLK_CTL3_LEDCLKEN_POS))
#endif
#ifdef  KF32F_Periph_exic
#define PCLK_CTL3_EXICCLKEN             ((uint32_t)1<<(PCLK_CTL3_EXICCLKEN_POS))
#endif
#ifdef  KF32F_Periph_can4
#define PCLK_CTL3_CAN4CLKEN             ((uint32_t)1<<(PCLK_CTL3_CAN4CLKEN_POS))
#endif
#ifdef  KF32F_Periph_can5
#define PCLK_CTL3_CAN5CLKEN             ((uint32_t)1<<(PCLK_CTL3_CAN5CLKEN_POS))
#endif
#ifdef  KF32F_Periph_cfgl
#define PCLK_CTL3_CFGLCLKEN             ((uint32_t)1<<(PCLK_CTL3_CFGLCLKEN_POS))
#endif
#ifdef  KF32F_Periph_op
#define PCLK_CTL3_OPCLKEN               ((uint32_t)1<<(PCLK_CTL3_OPCLKEN_POS))
#endif
/* ����ģ��ʱ��ʹ��ģ��(PCLK)������� */


/* ----------------------------------------------------------------------------
   -- ��������ӿ� (SPI)
   ---------------------------------------------------------------------------- */

/* SPI - ����Ĵ����ڴ�ṹ */
typedef struct SPI_MemMap {
    volatile uint32_t BRGR;             /* SPI���ƼĴ���, ƫ��:0x0 */
    volatile uint32_t CTLR;             /* SPI�����ʼĴ���, ƫ��:0x4 */
    volatile uint32_t BUFR;             /* SPI���ݼĴ���, ƫ��:0x8 */
    volatile uint32_t STR;              /* SPI״̬�Ĵ���, ƫ��:0xC */
}SPI_SFRmap;

/* ----------------------------------------------------------------------------
   -- SPI - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */

/* SPI - �Ĵ�����ڵ�ַ */
#ifdef  KF32F_Periph_spi0
#define SPI0_ADDR                       ((uint32_t)0x40000C00)
#define SPI0_SFR                        ((SPI_SFRmap *) SPI0_ADDR)
#endif
#ifdef  KF32F_Periph_spi1
#define SPI1_ADDR                       ((uint32_t)0x40000C80)
#define SPI1_SFR                        ((SPI_SFRmap *) SPI1_ADDR)
#endif
#ifdef  KF32F_Periph_spi2
#define SPI2_ADDR                       ((uint32_t)0x40002080)
#define SPI2_SFR                        ((SPI_SFRmap *) SPI2_ADDR)
#endif
#ifdef  KF32F_Periph_spi3
#define SPI3_ADDR                       ((uint32_t)0x40002100)
#define SPI3_SFR                        ((SPI_SFRmap *) SPI3_ADDR)
#endif
/* SPI - �Ĵ������ */
#define SPI0_BRGR                       (SPI0_SFR->BRGR)
#define SPI0_CTLR                       (SPI0_SFR->CTLR)
#define SPI0_BUFR                       (SPI0_SFR->BUFR)
#define SPI0_STR                        (SPI0_SFR->STR)
#define SPI1_BRGR                       (SPI1_SFR->BRGR)
#define SPI1_CTLR                       (SPI1_SFR->CTLR)
#define SPI1_BUFR                       (SPI1_SFR->BUFR)
#define SPI1_STR                        (SPI1_SFR->STR)
#define SPI2_BRGR                       (SPI2_SFR->BRGR)
#define SPI2_CTLR                       (SPI2_SFR->CTLR)
#define SPI2_BUFR                       (SPI2_SFR->BUFR)
#define SPI2_STR                        (SPI2_SFR->STR)
#define SPI3_BRGR                       (SPI3_SFR->BRGR)
#define SPI3_CTLR                       (SPI3_SFR->CTLR)
#define SPI3_BUFR                       (SPI3_SFR->BUFR)
#define SPI3_STR                        (SPI3_SFR->STR)

/* SPI_BRGR λ�� */
#define SPI_BRGR_SPIBRG0_POS            (0)
#define SPI_BRGR_I2SDIV0_POS            (16)
#define SPI_BRGR_MCKEN_POS              (24)
#define SPI_BRGR_I2SODD_POS             (25)
#define SPI_BRGR_SPIBRG                 ((uint32_t)0xFFFF<<(SPI_BRGR_SPIBRG0_POS))
#define SPI_BRGR_I2SDIV                 ((uint32_t)0xFF<<(SPI_BRGR_I2SDIV0_POS))
#define SPI_BRGR_MCKEN                  ((uint32_t)1<<(SPI_BRGR_MCKEN_POS))
#define SPI_BRGR_I2SODD                 ((uint32_t)1<<(SPI_BRGR_I2SODD_POS))

/* SPI_CTLR λ�� */
#define SPI_CTLR_SPIEN_POS              (0)
#define SPI_CTLR_SPIMS0_POS             (1)
#define SPI_CTLR_SPIMS1_POS             (2)
#define SPI_CTLR_SPIMS2_POS             (3)
#define SPI_CTLR_SPICKS0_POS            (4)
#define SPI_CTLR_SPICKS1_POS            (5)
#define SPI_CTLR_SPIDS_POS              (6)
#define SPI_CTLR_SPICKP_POS             (8)
#define SPI_CTLR_SPICKE_POS             (9)
#define SPI_CTLR_SPIBS0_POS             (12)
#define SPI_CTLR_SPIBS1_POS             (13)
#define SPI_CTLR_I2SMOD_POS             (16)
#define SPI_CTLR_I2SMC0_POS             (20)
#define SPI_CTLR_I2SMC1_POS             (21)
#define SPI_CTLR_I2SSS0_POS             (22)
#define SPI_CTLR_I2SSS1_POS             (23)
#define SPI_CTLR_PCMS_POS               (24)
#define SPI_CTLR_I2SCKS0_POS            (25)
#define SPI_CTLR_I2SCKS1_POS            (26)
#define SPI_CTLR_PCMCKP_POS             (27)
#define SPI_CTLR_TPOEN_POS              (28)
#define SPI_CTLR_TP0_POS                (29)
#define SPI_CTLR_TP1_POS                (30)
#define SPI_CTLR_TP2_POS                (31)
#define SPI_CTLR_SPIEN                  ((uint32_t)1<<(SPI_CTLR_SPIEN_POS))
#define SPI_CTLR_SPIMS                  ((uint32_t)7<<(SPI_CTLR_SPIMS0_POS))
#define SPI_CTLR_SPIMS0                 ((uint32_t)1<<(SPI_CTLR_SPIMS0_POS))
#define SPI_CTLR_SPIMS1                 ((uint32_t)1<<(SPI_CTLR_SPIMS1_POS))
#define SPI_CTLR_SPIMS2                 ((uint32_t)1<<(SPI_CTLR_SPIMS2_POS))
#define SPI_CTLR_SPICKS                 ((uint32_t)3<<(SPI_CTLR_SPICKS0_POS))
#define SPI_CTLR_SPICKS0                ((uint32_t)1<<(SPI_CTLR_SPICKS0_POS))
#define SPI_CTLR_SPICKS1                ((uint32_t)1<<(SPI_CTLR_SPICKS1_POS))
#define SPI_CTLR_SPIDS                  ((uint32_t)1<<(SPI_CTLR_SPIDS_POS))
#define SPI_CTLR_SPICKP                 ((uint32_t)1<<(SPI_CTLR_SPICKP_POS))
#define SPI_CTLR_SPICKE                 ((uint32_t)1<<(SPI_CTLR_SPICKE_POS))
#define SPI_CTLR_SPIBS                  ((uint32_t)3<<(SPI_CTLR_SPIBS0_POS))
#define SPI_CTLR_SPIBS0                 ((uint32_t)1<<(SPI_CTLR_SPIBS0_POS))
#define SPI_CTLR_SPIBS1                 ((uint32_t)1<<(SPI_CTLR_SPIBS1_POS))
#define SPI_CTLR_I2SMOD                 ((uint32_t)1<<(SPI_CTLR_I2SMOD_POS))
#define SPI_CTLR_I2SMC                  ((uint32_t)3<<(SPI_CTLR_I2SMC0_POS))
#define SPI_CTLR_I2SMC0                 ((uint32_t)1<<(SPI_CTLR_I2SMC0_POS))
#define SPI_CTLR_I2SMC1                 ((uint32_t)1<<(SPI_CTLR_I2SMC1_POS))
#define SPI_CTLR_I2SSS                  ((uint32_t)3<<(SPI_CTLR_I2SSS0_POS))
#define SPI_CTLR_I2SSS0                 ((uint32_t)1<<(SPI_CTLR_I2SSS0_POS))
#define SPI_CTLR_I2SSS1                 ((uint32_t)1<<(SPI_CTLR_I2SSS1_POS))
#define SPI_CTLR_PCMS                   ((uint32_t)1<<(SPI_CTLR_PCMS_POS))
#define SPI_CTLR_I2SCKS                 ((uint32_t)0x3<<(SPI_CTLR_I2SCKS0_POS))
#define SPI_CTLR_I2SCKS0                ((uint32_t)1<<(SPI_CTLR_I2SCKS0_POS))
#define SPI_CTLR_I2SCKS1                ((uint32_t)1<<(SPI_CTLR_I2SCKS1_POS))
#define SPI_CTLR_PCMCKP                 ((uint32_t)1<<(SPI_CTLR_PCMCKP_POS))
#define SPI_CTLR_TPOEN                  ((uint32_t)1<<(SPI_CTLR_TPOEN_POS))
#define SPI_CTLR_TP                     ((uint32_t)7<<(SPI_CTLR_TP0_POS))
#define SPI_CTLR_TP0                    ((uint32_t)1<<(SPI_CTLR_TP0_POS))
#define SPI_CTLR_TP1                    ((uint32_t)1<<(SPI_CTLR_TP1_POS))
#define SPI_CTLR_TP2                    ((uint32_t)1<<(SPI_CTLR_TP2_POS))

/* SPI_BUFR λ��*/
#define SPI_BUFR_SPIBUF0_POS            (0)
#define SPI_BUFR_SPIBUF                 ((uint32_t)0xFFFFFFFF<<(SPI_BUFR_SPIBUF0_POS))

/* SPI_STR λ��*/
#define SPI_STR_SPIBUSY_POS             (0)
#define SPI_STR_RNE_POS                 (1)
#define SPI_STR_TNE_POS                 (2)
#define SPI_STR_CHSIDE_POS              (3)
#define SPI_STR_ROVFIF_POS              (4)
#define SPI_STR_TOVFIF_POS              (5)
#define SPI_STR_UDRIF_POS               (6)
#define SPI_STR_UDRIE_POS               (11)
#define SPI_STR_ROVFIE_POS              (12)
#define SPI_STR_TOVFIE_POS              (13)
#define SPI_STR_RNEIE_POS               (14)
#define SPI_STR_TNEIE_POS               (15)
#define SPI_STR_ROVFIC_POS              (16)
#define SPI_STR_TOVFIC_POS              (17)
#define SPI_STR_UDRIC_POS               (18)
#define SPI_STR_SRCDE_POS               (20)
#define SPI_STR_STXDE_POS               (21)
#define SPI_STR_SPIBUSY                 ((uint32_t)1<<(SPI_STR_SPIBUSY_POS))
#define SPI_STR_RNE                     ((uint32_t)1<<(SPI_STR_RNE_POS))
#define SPI_STR_TNE                     ((uint32_t)1<<(SPI_STR_TNE_POS))
#define SPI_STR_CHSIDE                  ((uint32_t)1<<(SPI_STR_CHSIDE_POS))
#define SPI_STR_ROVFIF                  ((uint32_t)1<<(SPI_STR_ROVFIF_POS))
#define SPI_STR_TOVFIF                  ((uint32_t)1<<(SPI_STR_TOVFIF_POS))
#define SPI_STR_UDRIF                   ((uint32_t)1<<(SPI_STR_UDRIF_POS))
#define SPI_STR_UDRIE                   ((uint32_t)1<<(SPI_STR_UDRIE_POS))
#define SPI_STR_ROVFIE                  ((uint32_t)1<<(SPI_STR_ROVFIE_POS))
#define SPI_STR_TOVFIE                  ((uint32_t)1<<(SPI_STR_TOVFIE_POS))
#define SPI_STR_RNEIE                   ((uint32_t)1<<(SPI_STR_RNEIE_POS))
#define SPI_STR_TNEIE                   ((uint32_t)1<<(SPI_STR_TNEIE_POS))
#define SPI_STR_ROVFIC                  ((uint32_t)1<<(SPI_STR_ROVFIC_POS))
#define SPI_STR_TOVFIC                  ((uint32_t)1<<(SPI_STR_TOVFIC_POS))
#define SPI_STR_UDRIC                   ((uint32_t)1<<(SPI_STR_UDRIC_POS))
#define SPI_STR_SRCDE                   ((uint32_t)1<<(SPI_STR_SRCDE_POS))
#define SPI_STR_STXDE                   ((uint32_t)1<<(SPI_STR_STXDE_POS))
/* ��������ӿ� (SPI)������� */


/* ----------------------------------------------------------------------------
   -- �ڲ����ɵ�·�ӿ� (I2C)
   ---------------------------------------------------------------------------- */

/* I2C - ����Ĵ����ڴ�ṹ */
typedef struct I2C_MemMap {
    volatile uint32_t CTLR;             /* I2C���ƼĴ���, ƫ��:0x0 */
    volatile uint32_t SR;               /* I2C״̬�Ĵ���, ƫ��:0x4 */
    volatile uint32_t BUFR;             /* I2C���ݼĴ���, ƫ��:0x8 */
    volatile uint32_t ADDR0;            /* I2C��ַ�Ĵ���0, ƫ��:0xC */
    volatile uint32_t BRGR;             /* I2C�����ʼĴ���, ƫ��:0x10 */
    volatile uint32_t ADDR1;            /* I2C��ַ�Ĵ���1, ƫ��:0x14 */
    volatile uint32_t ADDR2;            /* I2C��ַ�Ĵ���2, ƫ��:0x18 */
    volatile uint32_t ADDR3;            /* I2C��ַ�Ĵ���3, ƫ��:0x1C */
    volatile uint32_t IER;              /* I2C�ж�ʹ�ܼĴ���, ƫ��:0x20 */
    volatile uint32_t TPSR;             /* I2C��������ѡ��Ĵ���, ƫ��:0x24 */
}I2C_SFRmap;

/* ----------------------------------------------------------------------------
   -- I2C - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */

/* I2C - �Ĵ�����ڵ�ַ */
#ifdef  KF32F_Periph_i2c0
#define I2C0_ADDR                       ((uint32_t)0x40000D00)
#define I2C0_SFR                        ((I2C_SFRmap *) I2C0_ADDR)
#endif
#ifdef  KF32F_Periph_i2c1
#define I2C1_ADDR                       ((uint32_t)0x40000D80)
#define I2C1_SFR                        ((I2C_SFRmap *) I2C1_ADDR)
#endif
#ifdef  KF32F_Periph_i2c2
#define I2C2_ADDR                       ((uint32_t)0x40000E00)
#define I2C2_SFR                        ((I2C_SFRmap *) I2C2_ADDR)
#endif
#ifdef  KF32F_Periph_i2c3
#define I2C3_ADDR                       ((uint32_t)0x40002380)
#define I2C3_SFR                        ((I2C_SFRmap *) I2C3_ADDR)
#endif

/* I2C - �Ĵ������ */
#define I2C0_CTLR                       (I2C0_SFR->CTLR)
#define I2C0_SR                         (I2C0_SFR->SR)
#define I2C0_BUFR                       (I2C0_SFR->BUFR)
#define I2C0_ADDR0                      (I2C0_SFR->ADDR0)
#define I2C0_BRGR                       (I2C0_SFR->BRGR)
#define I2C0_ADDR1                      (I2C0_SFR->ADDR1)
#define I2C0_ADDR2                      (I2C0_SFR->ADDR2)
#define I2C0_ADDR3                      (I2C0_SFR->ADDR3)
#define I2C0_IER                        (I2C0_SFR->IER)
#define I2C0_TPSR                       (I2C0_SFR->TPSR)

#define I2C1_CTLR                       (I2C1_SFR->CTLR)
#define I2C1_SR                         (I2C1_SFR->SR)
#define I2C1_BUFR                       (I2C1_SFR->BUFR)
#define I2C1_ADDR0                      (I2C1_SFR->ADDR0)
#define I2C1_BRGR                       (I2C1_SFR->BRGR)
#define I2C1_ADDR1                      (I2C1_SFR->ADDR1)
#define I2C1_ADDR2                      (I2C1_SFR->ADDR2)
#define I2C1_ADDR3                      (I2C1_SFR->ADDR3)
#define I2C1_IER                        (I2C1_SFR->IER)
#define I2C1_TPSR                       (I2C1_SFR->TPSR)

#define I2C2_CTLR                       (I2C2_SFR->CTLR)
#define I2C2_SR                         (I2C2_SFR->SR)
#define I2C2_BUFR                       (I2C2_SFR->BUFR)
#define I2C2_ADDR0                      (I2C2_SFR->ADDR0)
#define I2C2_BRGR                       (I2C2_SFR->BRGR)
#define I2C2_ADDR1                      (I2C2_SFR->ADDR1)
#define I2C2_ADDR2                      (I2C2_SFR->ADDR2)
#define I2C2_ADDR3                      (I2C2_SFR->ADDR3)
#define I2C2_IER                        (I2C2_SFR->IER)
#define I2C2_TPSR                       (I2C2_SFR->TPSR)

#define I2C3_CTLR                       (I2C3_SFR->CTLR)
#define I2C3_SR                         (I2C3_SFR->SR)
#define I2C3_BUFR                       (I2C3_SFR->BUFR)
#define I2C3_ADDR0                      (I2C3_SFR->ADDR0)
#define I2C3_BRGR                       (I2C3_SFR->BRGR)
#define I2C3_ADDR1                      (I2C3_SFR->ADDR1)
#define I2C3_ADDR2                      (I2C3_SFR->ADDR2)
#define I2C3_ADDR3                      (I2C3_SFR->ADDR3)
#define I2C3_IER                        (I2C3_SFR->IER)
#define I2C3_TPSR                       (I2C3_SFR->TPSR)

/* I2C_CTLR λ�� */
#define I2C_CTLR_I2CEN_POS              (0)
#define I2C_CTLR_BADR10_POS             (1)
#define I2C_CTLR_SEN_POS                (8)
#define I2C_CTLR_PEN_POS                (10)
#define I2C_CTLR_ACKEN_POS              (12)
#define I2C_CTLR_ACKDT_POS              (13)
#define I2C_CTLR_GCEM_POS               (14)
#define I2C_CTLR_I2CCKS0_POS            (16)
#define I2C_CTLR_I2CCKS1_POS            (17)
#define I2C_CTLR_MTHALL_POS             (20)
#define I2C_CTLR_ENASCL_POS             (21)
#define I2C_CTLR_NMENA_POS              (22)
#define I2C_CTLR_SMBUS_POS              (24)
#define I2C_CTLR_SMBT_POS               (25)
#define I2C_CTLR_ARPEN_POS              (26)
#define I2C_CTLR_ALERT_POS              (27)
#define I2C_CTLR_ADRL_POS               (31)
#define I2C_CTLR_I2CEN                  ((uint32_t)1<<(I2C_CTLR_I2CEN_POS))
#define I2C_CTLR_BADR10                 ((uint32_t)1<<(I2C_CTLR_BADR10_POS))
#define I2C_CTLR_SEN                    ((uint32_t)1<<(I2C_CTLR_SEN_POS))
#define I2C_CTLR_PEN                    ((uint32_t)1<<(I2C_CTLR_PEN_POS))
#define I2C_CTLR_ACKEN                  ((uint32_t)1<<(I2C_CTLR_ACKEN_POS))
#define I2C_CTLR_ACKDT                  ((uint32_t)1<<(I2C_CTLR_ACKDT_POS))
#define I2C_CTLR_GCEM                   ((uint32_t)1<<(I2C_CTLR_GCEM_POS))
#define I2C_CTLR_I2CCKS                 ((uint32_t)3<<(I2C_CTLR_I2CCKS0_POS))
#define I2C_CTLR_I2CCKS0                ((uint32_t)1<<(I2C_CTLR_I2CCKS0_POS))
#define I2C_CTLR_I2CCKS1                ((uint32_t)1<<(I2C_CTLR_I2CCKS1_POS))
#define I2C_CTLR_MTHALL                 ((uint32_t)1<<(I2C_CTLR_MTHALL_POS))
#define I2C_CTLR_ENASCL                 ((uint32_t)1<<(I2C_CTLR_ENASCL_POS))
#define I2C_CTLR_NMENA                  ((uint32_t)1<<(I2C_CTLR_NMENA_POS))
#define I2C_CTLR_SMBUS                  ((uint32_t)1<<(I2C_CTLR_SMBUS_POS))
#define I2C_CTLR_SMBT                   ((uint32_t)1<<(I2C_CTLR_SMBT_POS))
#define I2C_CTLR_ARPEN                  ((uint32_t)1<<(I2C_CTLR_ARPEN_POS))
#define I2C_CTLR_ALERT                  ((uint32_t)1<<(I2C_CTLR_ALERT_POS))
#define I2C_CTLR_ADRL                   ((uint32_t)1<<(I2C_CTLR_ADRL_POS))

/* I2C_ADDR λ��*/
#define I2C_ADDR_I2CADD0_POS            (0)
#define I2C_ADDR_I2CADD1_POS            (1)
#define I2C_ADDR_I2CADD2_POS            (2)
#define I2C_ADDR_I2CADD3_POS            (3)
#define I2C_ADDR_I2CADD4_POS            (4)
#define I2C_ADDR_I2CADD5_POS            (5)
#define I2C_ADDR_I2CADD6_POS            (6)
#define I2C_ADDR_I2CADD7_POS            (7)
#define I2C_ADDR_I2CADD8_POS            (8)
#define I2C_ADDR_I2CADD9_POS            (9)
#define I2C_ADDR_I2CMSK0_POS            (16)
#define I2C_ADDR_I2CMSK1_POS            (17)
#define I2C_ADDR_I2CMSK2_POS            (18)
#define I2C_ADDR_I2CMSK3_POS            (19)
#define I2C_ADDR_I2CMSK4_POS            (20)
#define I2C_ADDR_I2CMSK5_POS            (21)
#define I2C_ADDR_I2CMSK6_POS            (22)
#define I2C_ADDR_I2CMSK7_POS            (23)
#define I2C_ADDR_I2CMSK8_POS            (24)
#define I2C_ADDR_I2CMSK9_POS            (25)
#define I2C_ADDR_I2CADD                 ((uint32_t)0x3FF<<(I2C_ADDR_I2CADD0_POS))
#define I2C_ADDR_I2CADD0                ((uint32_t)1<<(I2C_ADDR_I2CADD0_POS))
#define I2C_ADDR_I2CADD1                ((uint32_t)1<<(I2C_ADDR_I2CADD1_POS))
#define I2C_ADDR_I2CADD2                ((uint32_t)1<<(I2C_ADDR_I2CADD2_POS))
#define I2C_ADDR_I2CADD3                ((uint32_t)1<<(I2C_ADDR_I2CADD3_POS))
#define I2C_ADDR_I2CADD4                ((uint32_t)1<<(I2C_ADDR_I2CADD4_POS))
#define I2C_ADDR_I2CADD5                ((uint32_t)1<<(I2C_ADDR_I2CADD5_POS))
#define I2C_ADDR_I2CADD6                ((uint32_t)1<<(I2C_ADDR_I2CADD6_POS))
#define I2C_ADDR_I2CADD7                ((uint32_t)1<<(I2C_ADDR_I2CADD7_POS))
#define I2C_ADDR_I2CADD8                ((uint32_t)1<<(I2C_ADDR_I2CADD8_POS))
#define I2C_ADDR_I2CADD9                ((uint32_t)1<<(I2C_ADDR_I2CADD9_POS))
#define I2C_ADDR_I2CMSK                 ((uint32_t)0x3FF<<(I2C_ADDR_I2CMSK0_POS))
#define I2C_ADDR_I2CMSK0                ((uint32_t)1<<(I2C_ADDR_I2CMSK0_POS))
#define I2C_ADDR_I2CMSK1                ((uint32_t)1<<(I2C_ADDR_I2CMSK1_POS))
#define I2C_ADDR_I2CMSK2                ((uint32_t)1<<(I2C_ADDR_I2CMSK2_POS))
#define I2C_ADDR_I2CMSK3                ((uint32_t)1<<(I2C_ADDR_I2CMSK3_POS))
#define I2C_ADDR_I2CMSK4                ((uint32_t)1<<(I2C_ADDR_I2CMSK4_POS))
#define I2C_ADDR_I2CMSK5                ((uint32_t)1<<(I2C_ADDR_I2CMSK5_POS))
#define I2C_ADDR_I2CMSK6                ((uint32_t)1<<(I2C_ADDR_I2CMSK6_POS))
#define I2C_ADDR_I2CMSK7                ((uint32_t)1<<(I2C_ADDR_I2CMSK7_POS))
#define I2C_ADDR_I2CMSK8                ((uint32_t)1<<(I2C_ADDR_I2CMSK8_POS))
#define I2C_ADDR_I2CMSK9                ((uint32_t)1<<(I2C_ADDR_I2CMSK9_POS))

/* I2C_BRGR λ��*/
#define I2C_BRGR_I2CBRGH0_POS           (0)
#define I2C_BRGR_I2CBRGL0_POS           (16)
#define I2C_BRGR_I2CBRGH                ((uint32_t)0xFFFF<<(I2C_BRGR_I2CBRGH0_POS))
#define I2C_BRGR_I2CBRGL                ((uint32_t)0xFFFF<<(I2C_BRGR_I2CBRGL0_POS))

/* I2C_BUFR λ��*/
#define I2C_BUFR_I2CBUF0_POS            (0)
#define I2C_BUFR_I2CBUF                 ((uint32_t)0x3FF<<(I2C_BUFR_I2CBUF0_POS))

/* I2C_SR λ��*/
#define I2C_SR_SIF_POS                  (0)
#define I2C_SR_PIF_POS                  (1)
#define I2C_SR_ADDR_POS                 (2)
#define I2C_SR_ADD10_POS                (3)
#define I2C_SR_DATA_POS                 (4)
#define I2C_SR_AFIF_POS                 (5)
#define I2C_SR_ARBLIF_POS               (6)
#define I2C_SR_RNW_POS                  (7)
#define I2C_SR_SMBAIF_POS               (8)
#define I2C_SR_SMBHIF_POS               (9)
#define I2C_SR_SMBDIF_POS               (10)
#define I2C_SR_ISIF_POS                 (11)
#define I2C_SR_RCBF_POS                 (12)
#define I2C_SR_TXBE_POS                 (13)
#define I2C_SR_IRCDF_POS                (16)
#define I2C_SR_ITXDF_POS                (17)
#define I2C_SR_SIF                      ((uint32_t)1<<(I2C_SR_SIF_POS))
#define I2C_SR_PIF                      ((uint32_t)1<<(I2C_SR_PIF_POS))
#define I2C_SR_ADDR                     ((uint32_t)1<<(I2C_SR_ADDR_POS))
#define I2C_SR_ADD10                    ((uint32_t)1<<(I2C_SR_ADD10_POS))
#define I2C_SR_DATA                     ((uint32_t)1<<(I2C_SR_DATA_POS))
#define I2C_SR_AFIF                     ((uint32_t)1<<(I2C_SR_AFIF_POS))
#define I2C_SR_ARBLIF                   ((uint32_t)1<<(I2C_SR_ARBLIF_POS))
#define I2C_SR_RNW                      ((uint32_t)1<<(I2C_SR_RNW_POS))
#define I2C_SR_SMBAIF                   ((uint32_t)1<<(I2C_SR_SMBAIF_POS))
#define I2C_SR_SMBHIF                   ((uint32_t)1<<(I2C_SR_SMBHIF_POS))
#define I2C_SR_SMBDIF                   ((uint32_t)1<<(I2C_SR_SMBDIF_POS))
#define I2C_SR_ISIF                     ((uint32_t)1<<(I2C_SR_ISIF_POS))
#define I2C_SR_RCBF                     ((uint32_t)1<<(I2C_SR_RCBF_POS))
#define I2C_SR_TXBE                     ((uint32_t)1<<(I2C_SR_TXBE_POS))
#define I2C_SR_IRCDF                    ((uint32_t)1<<(I2C_SR_IRCDF_POS))
#define I2C_SR_ITXDF                    ((uint32_t)1<<(I2C_SR_ITXDF_POS))

/* I2C_IER  λ��*/
#define I2C_IER_SIE_POS                 (0)
#define I2C_IER_PIE_POS                 (1)
#define I2C_IER_AFIE_POS                (5)
#define I2C_IER_ARBLIE_POS              (6)
#define I2C_IER_SMBAIE_POS              (8)
#define I2C_IER_SMBHIE_POS              (9)
#define I2C_IER_SMBDIE_POS              (10)
#define I2C_IER_ISIE_POS                (11)
#define I2C_IER_IRCDE_POS               (16)
#define I2C_IER_ITXDE_POS               (17)
#define I2C_IER_SIE                     ((uint32_t)1<<(I2C_IER_SIE_POS))
#define I2C_IER_PIE                     ((uint32_t)1<<(I2C_IER_PIE_POS))
#define I2C_IER_AFIE                    ((uint32_t)1<<(I2C_IER_AFIE_POS))
#define I2C_IER_ARBLIE                  ((uint32_t)1<<(I2C_IER_ARBLIE_POS))
#define I2C_IER_SMBAIE                  ((uint32_t)1<<(I2C_IER_SMBAIE_POS))
#define I2C_IER_SMBHIE                  ((uint32_t)1<<(I2C_IER_SMBHIE_POS))
#define I2C_IER_SMBDIE                  ((uint32_t)1<<(I2C_IER_SMBDIE_POS))
#define I2C_IER_ISIE                    ((uint32_t)1<<(I2C_IER_ISIE_POS))
#define I2C_IER_IRCDE                   ((uint32_t)1<<(I2C_IER_IRCDE_POS))
#define I2C_IER_ITXDE                   ((uint32_t)1<<(I2C_IER_ITXDE_POS))

/* I2C_TPSR  λ��*/
#define I2C_TPSR_I2CTPS0_POS            (0)
#define I2C_TPSR_I2CTPS1_POS            (1)
#define I2C_TPSR_I2CTPS2_POS            (2)
#define I2C_TPSR_I2CTPS3_POS            (3)
#define I2C_TPSR_I2CTPS4_POS            (4)
#define I2C_TPSR_I2CTPS5_POS            (5)
#define I2C_TPSR_I2CTPS6_POS            (6)
#define I2C_TPSR_I2CTPS7_POS            (7)
#define I2C_TPSR_I2CTPS8_POS            (8)
#define I2C_TPSR_I2CTPS9_POS            (9)
#define I2C_TPSR_I2CTPS10_POS           (10)
#define I2C_TPSR_I2CTPS11_POS           (11)
#define I2C_TPSR_I2CTPOEN_POS           (12)
#define I2C_TPSR_I2CTPS0                ((uint32_t)1<<(I2C_TPSR_I2CTPS0_POS))
#define I2C_TPSR_I2CTPS1                ((uint32_t)1<<(I2C_TPSR_I2CTPS1_POS))
#define I2C_TPSR_I2CTPS2                ((uint32_t)1<<(I2C_TPSR_I2CTPS2_POS))
#define I2C_TPSR_I2CTPS3                ((uint32_t)1<<(I2C_TPSR_I2CTPS3_POS))
#define I2C_TPSR_I2CTPS4                ((uint32_t)1<<(I2C_TPSR_I2CTPS4_POS))
#define I2C_TPSR_I2CTPS5                ((uint32_t)1<<(I2C_TPSR_I2CTPS5_POS))
#define I2C_TPSR_I2CTPS6                ((uint32_t)1<<(I2C_TPSR_I2CTPS6_POS))
#define I2C_TPSR_I2CTPS7                ((uint32_t)1<<(I2C_TPSR_I2CTPS7_POS))
#define I2C_TPSR_I2CTPS8                ((uint32_t)1<<(I2C_TPSR_I2CTPS8_POS))
#define I2C_TPSR_I2CTPS9                ((uint32_t)1<<(I2C_TPSR_I2CTPS9_POS))
#define I2C_TPSR_I2CTPS10               ((uint32_t)1<<(I2C_TPSR_I2CTPS10_POS))
#define I2C_TPSR_I2CTPS11               ((uint32_t)1<<(I2C_TPSR_I2CTPS11_POS))
#define I2C_TPSR_I2CTPOEN               ((uint32_t)1<<(I2C_TPSR_I2CTPOEN_POS))
/* �ڲ����ɵ�·�ӿ� (I2C)������� */


/* ----------------------------------------------------------------------------
   -- ͨ��ȫ/��˫���շ��� (USART)
   ---------------------------------------------------------------------------- */

/* USART - ����Ĵ����ڴ�ṹ */
typedef struct USART_MemMap {
    volatile uint32_t CTLR;             /* USART���ƼĴ���, ƫ��:0x0 */
    volatile uint32_t BRGR;             /* USART�����ʼĴ���, ƫ��:0x4 */
    volatile uint32_t STR;              /* USART״̬�Ĵ���, ƫ��:0x8 */
    union {
        volatile       uint32_t TBUFR;  /* USART�������ݼĴ���, ƫ��:0xC */
        volatile const uint32_t RBUFR;  /* USART�������ݼĴ���, ƫ��:0xC*/
    };
    volatile uint32_t U7816R;           /* 7816���ƼĴ���, ƫ��:0x10 */
    volatile uint32_t IER;              /* USART�ж�ʹ�ܼĴ���, ƫ��:0x14 */
    volatile uint32_t ADM;              /* ��ַƥ�����üĴ���, ƫ��:0x18  */
}USART_SFRmap;

/* ----------------------------------------------------------------------------
   -- USART - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */

/* USART - �Ĵ�����ڵ�ַ */
#ifdef  KF32F_Periph_usart0
#define USART0_ADDR                     ((uint32_t)0x40000980)
#define USART0_SFR                      ((USART_SFRmap *) USART0_ADDR)
#endif

#ifdef  KF32F_Periph_usart1
#define USART1_ADDR                     ((uint32_t)0x40000A00)
#define USART1_SFR                      ((USART_SFRmap *) USART1_ADDR)
#endif

#ifdef  KF32F_Periph_usart2
#define USART2_ADDR                     ((uint32_t)0x40000A80)
#define USART2_SFR                      ((USART_SFRmap *) USART2_ADDR)
#endif

#ifdef  KF32F_Periph_usart3
#define USART3_ADDR                     ((uint32_t)0x40000B00)
#define USART3_SFR                      ((USART_SFRmap *) USART3_ADDR)
#endif

#ifdef  KF32F_Periph_usart4
#define USART4_ADDR                     ((uint32_t)0x40000B80)
#define USART4_SFR                      ((USART_SFRmap *) USART4_ADDR)
#endif

#ifdef  KF32F_Periph_usart5
#define USART5_ADDR                     ((uint32_t)0x40001E80)
#define USART5_SFR                      ((USART_SFRmap *) USART5_ADDR)
#endif

#ifdef  KF32F_Periph_usart6
#define USART6_ADDR                     ((uint32_t)0x40001F00)
#define USART6_SFR                      ((USART_SFRmap *) USART6_ADDR)
#endif

#ifdef  KF32F_Periph_usart7
#define USART7_ADDR                     ((uint32_t)0x40001F80)
#define USART7_SFR                      ((USART_SFRmap *) USART7_ADDR)
#endif

#ifdef  KF32F_Periph_usart0
/* USART - �Ĵ������ */
#define USART0_CTLR                     (USART0_SFR->CTLR)
#define USART0_BRGR                     (USART0_SFR->BRGR)
#define USART0_STR                      (USART0_SFR->STR)
#define USART0_TBUFR                    (USART0_SFR->TBUFR)
#define USART0_RBUFR                    (USART0_SFR->RBUFR)
#define USART0_U7816R                   (USART0_SFR->U7816R)
#define USART0_IER                      (USART0_SFR->IER)
#define USART0_ADM                      (USART0_SFR->ADM)
#endif

#ifdef  KF32F_Periph_usart1
#define USART1_CTLR                     (USART1_SFR->CTLR)
#define USART1_BRGR                     (USART1_SFR->BRGR)
#define USART1_STR                      (USART1_SFR->STR)
#define USART1_TBUFR                    (USART1_SFR->TBUFR)
#define USART1_RBUFR                    (USART1_SFR->RBUFR)
#define USART1_U7816R                   (USART1_SFR->U7816R)
#define USART1_IER                      (USART1_SFR->IER)
#define USART1_ADM                      (USART1_SFR->ADM)
#endif

#ifdef  KF32F_Periph_usart2
#define USART2_CTLR                     (USART2_SFR->CTLR)
#define USART2_BRGR                     (USART2_SFR->BRGR)
#define USART2_STR                      (USART2_SFR->STR)
#define USART2_TBUFR                    (USART2_SFR->TBUFR)
#define USART2_RBUFR                    (USART2_SFR->RBUFR)
#define USART2_U7816R                   (USART2_SFR->U7816R)
#define USART2_IER                      (USART2_SFR->IER)
#define USART2_ADM                      (USART2_SFR->ADM)
#endif

#ifdef  KF32F_Periph_usart3
#define USART3_CTLR                     (USART3_SFR->CTLR)
#define USART3_BRGR                     (USART3_SFR->BRGR)
#define USART3_STR                      (USART3_SFR->STR)
#define USART3_TBUFR                    (USART3_SFR->TBUFR)
#define USART3_RBUFR                    (USART3_SFR->RBUFR)
#define USART3_U7816R                   (USART3_SFR->U7816R)
#define USART3_IER                      (USART3_SFR->IER)
#define USART3_ADM                      (USART3_SFR->ADM)
#endif

#ifdef  KF32F_Periph_usart4
#define USART4_CTLR                     (USART4_SFR->CTLR)
#define USART4_BRGR                     (USART4_SFR->BRGR)
#define USART4_STR                      (USART4_SFR->STR)
#define USART4_TBUFR                    (USART4_SFR->TBUFR)
#define USART4_RBUFR                    (USART4_SFR->RBUFR)
#define USART4_U7816R                   (USART4_SFR->U7816R)
#define USART4_IER                      (USART4_SFR->IER)
#define USART4_ADM                      (USART4_SFR->ADM)
#endif

#ifdef  KF32F_Periph_usart5
#define USART5_CTLR                     (USART5_SFR->CTLR)
#define USART5_BRGR                     (USART5_SFR->BRGR)
#define USART5_STR                      (USART5_SFR->STR)
#define USART5_TBUFR                    (USART5_SFR->TBUFR)
#define USART5_RBUFR                    (USART5_SFR->RBUFR)
#define USART5_U7816R                   (USART5_SFR->U7816R)
#define USART5_IER                      (USART5_SFR->IER)
#define USART5_ADM                      (USART5_SFR->ADM)
#endif

#ifdef  KF32F_Periph_usart6
#define USART6_CTLR                     (USART6_SFR->CTLR)
#define USART6_BRGR                     (USART6_SFR->BRGR)
#define USART6_STR                      (USART6_SFR->STR)
#define USART6_TBUFR                    (USART6_SFR->TBUFR)
#define USART6_RBUFR                    (USART6_SFR->RBUFR)
#define USART6_U7816R                   (USART6_SFR->U7816R)
#define USART6_IER                      (USART6_SFR->IER)
#define USART6_ADM                      (USART6_SFR->ADM)
#endif

#ifdef  KF32F_Periph_usart7
#define USART7_CTLR                     (USART7_SFR->CTLR)
#define USART7_BRGR                     (USART7_SFR->BRGR)
#define USART7_STR                      (USART7_SFR->STR)
#define USART7_TBUFR                    (USART7_SFR->TBUFR)
#define USART7_RBUFR                    (USART7_SFR->RBUFR)
#define USART7_U7816R                   (USART7_SFR->U7816R)
#define USART7_IER                      (USART7_SFR->IER)
#define USART7_ADM                      (USART7_SFR->ADM)
#endif
/* USART_CTLR λ�� */
#define USART_CTLR_USARTEN_POS          (0)
#define USART_CTLR_BRCKS0_POS           (1)
#define USART_CTLR_BRCKS1_POS           (2)
#define USART_CTLR_SCKPS_POS            (3)
#define USART_CTLR_TCONV_POS            (4)
#define USART_CTLR_RCONV_POS            (5)
#define USART_CTLR_DINV_POS             (6)
#define USART_CTLR_WUEN_POS             (7)
#define USART_CTLR_CSRS_POS             (8)
#define USART_CTLR_ADREN_POS            (9)
#define USART_CTLR_ABRDEN_POS           (11)
#define USART_CTLR_SENDB_POS            (13)
#define USART_CTLR_SYNC_POS             (14)
#define USART_CTLR_TXEN_POS             (15)
#define USART_CTLR_RXEN_POS             (16)
#define USART_CTLR_STPW_POS             (18)
#define USART_CTLR_TX9SEL_POS           (19)
#define USART_CTLR_PARM_POS             (20)
#define USART_CTLR_DT9EN_POS            (21)
#define USART_CTLR_CTSEN_POS            (24)
#define USART_CTLR_RTSEN_POS            (25)
#define USART_CTLR_IRDAEN_POS           (29)
#define USART_CTLR_RESHD_POS            (30)
#define USART_CTLR_SLMEN_POS            (31)
#define USART_CTLR_USARTEN              ((uint32_t)1<<(USART_CTLR_USARTEN_POS))
#define USART_CTLR_BRCKS                ((uint32_t)3<<(USART_CTLR_BRCKS0_POS))
#define USART_CTLR_BRCKS0               ((uint32_t)1<<(USART_CTLR_BRCKS0_POS))
#define USART_CTLR_BRCKS1               ((uint32_t)1<<(USART_CTLR_BRCKS1_POS))
#define USART_CTLR_SCKPS                ((uint32_t)1<<(USART_CTLR_SCKPS_POS))
#define USART_CTLR_TCONV                ((uint32_t)1<<(USART_CTLR_TCONV_POS))
#define USART_CTLR_RCONV                ((uint32_t)1<<(USART_CTLR_RCONV_POS))
#define USART_CTLR_DINV                 ((uint32_t)1<<(USART_CTLR_DINV_POS))
#define USART_CTLR_WUEN                 ((uint32_t)1<<(USART_CTLR_WUEN_POS))
#define USART_CTLR_CSRS                 ((uint32_t)1<<(USART_CTLR_CSRS_POS))
#define USART_CTLR_ADREN                ((uint32_t)1<<(USART_CTLR_ADREN_POS))
#define USART_CTLR_ABRDEN               ((uint32_t)1<<(USART_CTLR_ABRDEN_POS))
#define USART_CTLR_SENDB                ((uint32_t)1<<(USART_CTLR_SENDB_POS))
#define USART_CTLR_SYNC                 ((uint32_t)1<<(USART_CTLR_SYNC_POS))
#define USART_CTLR_TXEN                 ((uint32_t)1<<(USART_CTLR_TXEN_POS))
#define USART_CTLR_RXEN                 ((uint32_t)1<<(USART_CTLR_RXEN_POS))
#define USART_CTLR_STPW                 ((uint32_t)1<<(USART_CTLR_STPW_POS))
#define USART_CTLR_TX9SEL               ((uint32_t)1<<(USART_CTLR_TX9SEL_POS))
#define USART_CTLR_PARM                 ((uint32_t)1<<(USART_CTLR_PARM_POS))
#define USART_CTLR_DT9EN                ((uint32_t)1<<(USART_CTLR_DT9EN_POS))
#define USART_CTLR_CTSEN                ((uint32_t)1<<(USART_CTLR_CTSEN_POS))
#define USART_CTLR_RTSEN                ((uint32_t)1<<(USART_CTLR_RTSEN_POS))
#define USART_CTLR_IRDAEN               ((uint32_t)1<<(USART_CTLR_IRDAEN_POS))
#define USART_CTLR_RESHD                ((uint32_t)1<<(USART_CTLR_RESHD_POS))
#define USART_CTLR_SLMEN                ((uint32_t)1<<(USART_CTLR_SLMEN_POS))

/* USART_STR λ��*/
#define USART_STR_OVFEIF_POS            (0)
#define USART_STR_PAREIF_POS            (1)
#define USART_STR_FREIF_POS             (2)
#define USART_STR_BRIF_POS              (3)
#define USART_STR_ABTOIF_POS            (4)
#define USART_STR_WUIF_POS              (5)
#define USART_STR_TEIF_POS              (6)
#define USART_STR_REIF_POS              (7)
#define USART_STR_CTSIF_POS             (8)
#define USART_STR_RCFR_POS              (9)
#define USART_STR_TXFR_POS              (10)
#define USART_STR_RDRIF_POS             (11)
#define USART_STR_TFEIF_POS             (12)
#define USART_STR_TXEIF_POS             (13)
#define USART_STR_UADMIF_POS            (14)
#define USART_STR_OVFEIC_POS            (16)
#define USART_STR_PAREIC_POS            (17)
#define USART_STR_FREIC_POS             (18)
#define USART_STR_BRIC_POS              (19)
#define USART_STR_ABTOIC_POS            (20)
#define USART_STR_WUIC_POS              (21)
#define USART_STR_TEIC_POS              (22)
#define USART_STR_REIC_POS              (23)
#define USART_STR_CTSIC_POS             (24)
#define USART_STR_UADMIC_POS             (25)
#define USART_STR_OVFEIF                ((uint32_t)1<<(USART_STR_OVFEIF_POS))
#define USART_STR_PAREIF                ((uint32_t)1<<(USART_STR_PAREIF_POS))
#define USART_STR_FREIF                 ((uint32_t)1<<(USART_STR_FREIF_POS))
#define USART_STR_BRIF                  ((uint32_t)1<<(USART_STR_BRIF_POS))
#define USART_STR_ABTOIF                ((uint32_t)1<<(USART_STR_ABTOIF_POS))
#define USART_STR_WUIF                  ((uint32_t)1<<(USART_STR_WUIF_POS))
#define USART_STR_TEIF                  ((uint32_t)1<<(USART_STR_TEIF_POS))
#define USART_STR_REIF                  ((uint32_t)1<<(USART_STR_REIF_POS))
#define USART_STR_CTSIF                 ((uint32_t)1<<(USART_STR_CTSIF_POS))
#define USART_STR_RCFR                  ((uint32_t)1<<(USART_STR_RCFR_POS))
#define USART_STR_TXFR                  ((uint32_t)1<<(USART_STR_TXFR_POS))
#define USART_STR_RDRIF                 ((uint32_t)1<<(USART_STR_RDRIF_POS))
#define USART_STR_TFEIF                 ((uint32_t)1<<(USART_STR_TFEIF_POS))
#define USART_STR_TXEIF                 ((uint32_t)1<<(USART_STR_TXEIF_POS))
#define USART_STR_UADMIF                ((uint32_t)1<<(USART_STR_UADMIF_POS))
#define USART_STR_OVFEIC                ((uint32_t)1<<(USART_STR_OVFEIC_POS))
#define USART_STR_PAREIC                ((uint32_t)1<<(USART_STR_PAREIC_POS))
#define USART_STR_FREIC                 ((uint32_t)1<<(USART_STR_FREIC_POS))
#define USART_STR_BRIC                  ((uint32_t)1<<(USART_STR_BRIC_POS))
#define USART_STR_ABTOIC                ((uint32_t)1<<(USART_STR_ABTOIC_POS))
#define USART_STR_WUIC                  ((uint32_t)1<<(USART_STR_WUIC_POS))
#define USART_STR_TEIC                  ((uint32_t)1<<(USART_STR_TEIC_POS))
#define USART_STR_REIC                  ((uint32_t)1<<(USART_STR_REIC_POS))
#define USART_STR_CTSIC                 ((uint32_t)1<<(USART_STR_CTSIC_POS))
#define USART_STR_UADMIC                 ((uint32_t)1<<(USART_STR_UADMIC_POS))

/* USART_U7816R λ��*/
#define USART_U7816R_7816EN_POS         (0)
#define USART_U7816R_CLKOUT_POS         (1)
#define USART_U7816R_ERSW0_POS          (2)
#define USART_U7816R_ERSW1_POS          (3)
#define USART_U7816R_PSEL_POS           (4)
#define USART_U7816R_BGT_POS            (5)
#define USART_U7816R_TREPEN_POS         (8)
#define USART_U7816R_RREPEN_POS         (9)
#define USART_U7816R_TXRE0_POS          (10)
#define USART_U7816R_TXRE1_POS          (11)
#define USART_U7816R_RXRE0_POS          (12)
#define USART_U7816R_RXRE1_POS          (13)
#define USART_U7816R_CLKDIV0_POS        (16)
#define USART_U7816R_CLKDIV1_POS        (17)
#define USART_U7816R_CLKDIV2_POS        (18)
#define USART_U7816R_CLKDIV3_POS        (19)
#define USART_U7816R_CLKDIV4_POS        (20)
#define USART_U7816R_CLKDIV5_POS        (21)
#define USART_U7816R_CLKDIV6_POS        (22)
#define USART_U7816R_CLKDIV7_POS        (23)
#define USART_U7816R_EGT0_POS           (24)
#define USART_U7816R_EGT1_POS           (25)
#define USART_U7816R_EGT2_POS           (26)
#define USART_U7816R_EGT3_POS           (27)
#define USART_U7816R_EGT4_POS           (28)
#define USART_U7816R_EGT5_POS           (29)
#define USART_U7816R_EGT6_POS           (30)
#define USART_U7816R_EGT7_POS           (31)
#define USART_U7816R_7816EN             ((uint32_t)1<<(USART_U7816R_7816EN_POS))
#define USART_U7816R_CLKOUT             ((uint32_t)1<<(USART_U7816R_CLKOUT_POS))
#define USART_U7816R_ERSW               ((uint32_t)3<<(USART_U7816R_ERSW0_POS))
#define USART_U7816R_ERSW0              ((uint32_t)1<<(USART_U7816R_ERSW0_POS))
#define USART_U7816R_ERSW1              ((uint32_t)1<<(USART_U7816R_ERSW1_POS))
#define USART_U7816R_PSEL               ((uint32_t)1<<(USART_U7816R_PSEL_POS))
#define USART_U7816R_BGT                ((uint32_t)1<<(USART_U7816R_BGT_POS))
#define USART_U7816R_TREPEN             ((uint32_t)1<<(USART_U7816R_TREPEN_POS))
#define USART_U7816R_RREPEN             ((uint32_t)1<<(USART_U7816R_RREPEN_POS))
#define USART_U7816R_TXRE               ((uint32_t)3<<(USART_U7816R_TXRE0_POS))
#define USART_U7816R_TXRE0              ((uint32_t)1<<(USART_U7816R_TXRE0_POS))
#define USART_U7816R_TXRE1              ((uint32_t)1<<(USART_U7816R_TXRE1_POS))
#define USART_U7816R_RXRE               ((uint32_t)3<<(USART_U7816R_RXRE0_POS))
#define USART_U7816R_RXRE0              ((uint32_t)1<<(USART_U7816R_RXRE0_POS))
#define USART_U7816R_RXRE1              ((uint32_t)1<<(USART_U7816R_RXRE1_POS))
#define USART_U7816R_CLKDIV             ((uint32_t)0xFF<<(USART_U7816R_CLKDIV0_POS))
#define USART_U7816R_CLKDIV0            ((uint32_t)1<<(USART_U7816R_CLKDIV0_POS))
#define USART_U7816R_CLKDIV1            ((uint32_t)1<<(USART_U7816R_CLKDIV1_POS))
#define USART_U7816R_CLKDIV2            ((uint32_t)1<<(USART_U7816R_CLKDIV2_POS))
#define USART_U7816R_CLKDIV3            ((uint32_t)1<<(USART_U7816R_CLKDIV3_POS))
#define USART_U7816R_CLKDIV4            ((uint32_t)1<<(USART_U7816R_CLKDIV4_POS))
#define USART_U7816R_CLKDIV5            ((uint32_t)1<<(USART_U7816R_CLKDIV5_POS))
#define USART_U7816R_CLKDIV6            ((uint32_t)1<<(USART_U7816R_CLKDIV6_POS))
#define USART_U7816R_CLKDIV7            ((uint32_t)1<<(USART_U7816R_CLKDIV7_POS))
#define USART_U7816R_EGT                ((uint32_t)0xFF<<(USART_U7816R_EGT0_POS))
#define USART_U7816R_EGT0               ((uint32_t)1<<(USART_U7816R_EGT0_POS))
#define USART_U7816R_EGT1               ((uint32_t)1<<(USART_U7816R_EGT1_POS))
#define USART_U7816R_EGT2               ((uint32_t)1<<(USART_U7816R_EGT2_POS))
#define USART_U7816R_EGT3               ((uint32_t)1<<(USART_U7816R_EGT3_POS))
#define USART_U7816R_EGT4               ((uint32_t)1<<(USART_U7816R_EGT4_POS))
#define USART_U7816R_EGT5               ((uint32_t)1<<(USART_U7816R_EGT5_POS))
#define USART_U7816R_EGT6               ((uint32_t)1<<(USART_U7816R_EGT6_POS))
#define USART_U7816R_EGT7               ((uint32_t)1<<(USART_U7816R_EGT7_POS))

/* USART_BRGR λ��*/
#define USART_BRGR_BRGM0_POS            (0)
#define USART_BRGR_BRGF1_0_POS          (16)
#define USART_BRGR_BRGF2_0_POS          (20)
#define USART_BRGR_BRGM                 ((uint32_t)0xFFFF<<(USART_BRGR_BRGM0_POS))
#define USART_BRGR_BRGF1                ((uint32_t)0xF<<(USART_BRGR_BRGF1_0_POS))
#define USART_BRGR_BRGF2                ((uint32_t)0xF<<(USART_BRGR_BRGF2_0_POS))

/* USART_TBUFR λ��*/
#define USART_TBUFR_TBUF0_POS           (0)
#define USART_TBUFR_TBUF                ((uint32_t)0xFF<<(USART_TBUFR_TBUF0_POS))

/* USART_RBUFR λ��*/
#define USART_RBUFR_RBUF0_POS           (0)
#define USART_RBUFR_RBUF                ((uint32_t)0xFF<<(USART_RBUFR_RBUF0_POS))

/* USART_IER λ��*/
#define USART_IER_OVFEIE_POS            (0)
#define USART_IER_PAREIE_POS            (1)
#define USART_IER_FREIE_POS             (2)
#define USART_IER_BRIE_POS              (3)
#define USART_IER_ABTOIE_POS            (4)
#define USART_IER_WUIE_POS              (5)
#define USART_IER_TEIE_POS              (6)
#define USART_IER_REIE_POS              (7)
#define USART_IER_CTSIE_POS             (8)
#define USART_IER_RDRIE_POS             (9)
#define USART_IER_TFEIE_POS             (10)
#define USART_IER_TXEIE_POS             (11)
#define USART_IER_URCDE_POS             (16)
#define USART_IER_UTXDE_POS             (17)
#define USART_IER_TP0_POS               (29)
#define USART_IER_TP1_POS               (30)
#define USART_IER_TP2_POS               (31)
#define USART_IER_OVFEIE                ((uint32_t)1<<(USART_IER_OVFEIE_POS))
#define USART_IER_PAREIE                ((uint32_t)1<<(USART_IER_PAREIE_POS))
#define USART_IER_FREIE                 ((uint32_t)1<<(USART_IER_FREIE_POS))
#define USART_IER_BRIE                  ((uint32_t)1<<(USART_IER_BRIE_POS))
#define USART_IER_ABTOIE                ((uint32_t)1<<(USART_IER_ABTOIE_POS))
#define USART_IER_WUIE                  ((uint32_t)1<<(USART_IER_WUIE_POS))
#define USART_IER_TEIE                  ((uint32_t)1<<(USART_IER_TEIE_POS))
#define USART_IER_REIE                  ((uint32_t)1<<(USART_IER_REIE_POS))
#define USART_IER_CTSIE                 ((uint32_t)1<<(USART_IER_CTSIE_POS))
#define USART_IER_RDRIE                 ((uint32_t)1<<(USART_IER_RDRIE_POS))
#define USART_IER_TFEIE                 ((uint32_t)1<<(USART_IER_TFEIE_POS))
#define USART_IER_TXEIE                 ((uint32_t)1<<(USART_IER_TXEIE_POS))
#define USART_IER_URCDE                 ((uint32_t)1<<(USART_IER_URCDE_POS))
#define USART_IER_UTXDE                 ((uint32_t)1<<(USART_IER_UTXDE_POS))
#define USART_IER_TP                    ((uint32_t)7<<(USART_IER_TP0_POS))
#define USART_IER_TP0                   ((uint32_t)1<<(USART_IER_TP0_POS))
#define USART_IER_TP1                   ((uint32_t)1<<(USART_IER_TP1_POS))
#define USART_IER_TP2                   ((uint32_t)1<<(USART_IER_TP2_POS))

/* USART_ADM λ��*/
#define USART_ADM_ADM0_POS              (0)
#define USART_ADM_ADM1_POS              (1)
#define USART_ADM_ADM2_POS              (2)
#define USART_ADM_ADM3_POS              (3)
#define USART_ADM_ADM4_POS              (4)
#define USART_ADM_ADM5_POS              (5)
#define USART_ADM_ADM6_POS              (6)
#define USART_ADM_ADM7_POS              (7)
#define USART_ADM_ADM                   ((uint32_t)0xFF<<(USART_ADM_ADM0_POS))
#define USART_ADM_ADM0                  ((uint32_t)1<<(USART_ADM_ADM0_POS))
#define USART_ADM_ADM1                  ((uint32_t)1<<(USART_ADM_ADM1_POS))
#define USART_ADM_ADM2                  ((uint32_t)1<<(USART_ADM_ADM2_POS))
#define USART_ADM_ADM3                  ((uint32_t)1<<(USART_ADM_ADM3_POS))
#define USART_ADM_ADM4                  ((uint32_t)1<<(USART_ADM_ADM4_POS))
#define USART_ADM_ADM5                  ((uint32_t)1<<(USART_ADM_ADM5_POS))
#define USART_ADM_ADM6                  ((uint32_t)1<<(USART_ADM_ADM6_POS))
#define USART_ADM_ADM7                  ((uint32_t)1<<(USART_ADM_ADM7_POS))
/* ͨ��ȫ/��˫���շ��� (USART)������� */

/* ----------------------------------------------------------------------------
   -- ͨ�ô������� (USB)
   ---------------------------------------------------------------------------- */
#ifdef KF32F_Periph_usb
/* USB - ����Ĵ����ڴ�ṹ */
typedef struct USB_MemMap {
    volatile       uint32_t UCON;       /* USB���ƼĴ���, ƫ��:0x0 */
    volatile const uint32_t USTAT;      /* USB״̬�Ĵ���, ƫ��:0x4 */
    volatile       uint32_t UADDR;      /* USB��ַ�Ĵ���, ƫ��:0x8 */
    volatile       uint32_t UFRM;       /* USB֡�żĴ���, ƫ��:0xC */
    volatile       uint32_t UIR;        /* USB�жϱ�־�Ĵ���, ƫ��:0x10 */
    volatile       uint32_t UIE;        /* USB�ж�ʹ�ܼĴ���, ƫ��:0x14 */
    volatile       uint32_t UEP[8];     /* USB�˵���ƼĴ���, ƫ��:0x18 */
    volatile       uint32_t UDB;        /* USB Debug���ƼĴ���, ƫ��:0x38 */
}USB_SFRmap;

/* ----------------------------------------------------------------------------
   -- USB - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */

/* USB - �Ĵ�����ڵ�ַ */
#define USB_ADDR                        ((uint32_t)0x40000F80)
#define USB_SFR                         ((USB_SFRmap *) USB_ADDR)

/* USB - �Ĵ������ */
#define USB_UCON                        (USB_SFR->UCON)
#define USB_USTAT                       (USB_SFR->USTAT)
#define USB_UADDR                       (USB_SFR->UADDR)
#define USB_UFRM                        (USB_SFR->UFRM)
#define USB_UIR                         (USB_SFR->UIR)
#define USB_UIE                         (USB_SFR->UIE)
#define USB_UEP0                        (USB_SFR->UEP[0])
#define USB_UEP1                        (USB_SFR->UEP[1])
#define USB_UEP2                        (USB_SFR->UEP[2])
#define USB_UEP3                        (USB_SFR->UEP[3])
#define USB_UEP4                        (USB_SFR->UEP[4])
#define USB_UEP5                        (USB_SFR->UEP[5])
#define USB_UEP6                        (USB_SFR->UEP[6])
#define USB_UEP7                        (USB_SFR->UEP[7])
#define USB_UDB                         (USB_SFR->UDB)

/* USB_UCON λ�� */
#define USB_UCON_DB0_POS                (0)
#define USB_UCON_DB1_POS                (1)
#define USB_UCON_UPUEN_POS              (2)
#define USB_UCON_SPEEDEN_POS            (4)
#define USB_UCON_EYETEST_POS            (7)
#define USB_UCON_USBEN_POS              (9)
#define USB_UCON_RESUME_POS             (10)
#define USB_UCON_SUSPND_POS             (11)
#define USB_UCON_PKTDIS_POS             (12)
#define USB_UCON_SE0_POS                (13)
#define USB_UCON_DBRST_POS              (14)
#define USB_UCON_DB                     ((uint32_t)3<<(USB_UCON_DB0_POS))
#define USB_UCON_DB0                    ((uint32_t)1<<(USB_UCON_DB0_POS))
#define USB_UCON_DB1                    ((uint32_t)1<<(USB_UCON_DB1_POS))
#define USB_UCON_UPUEN                  ((uint32_t)1<<(USB_UCON_UPUEN_POS))
#define USB_UCON_SPEEDEN                ((uint32_t)1<<(USB_UCON_SPEEDEN_POS))
#define USB_UCON_EYETEST                ((uint32_t)1<<(USB_UCON_EYETEST_POS))
#define USB_UCON_USBEN                  ((uint32_t)1<<(USB_UCON_USBEN_POS))
#define USB_UCON_RESUME                 ((uint32_t)1<<(USB_UCON_RESUME_POS))
#define USB_UCON_SUSPND                 ((uint32_t)1<<(USB_UCON_SUSPND_POS))
#define USB_UCON_PKTDIS                 ((uint32_t)1<<(USB_UCON_PKTDIS_POS))
#define USB_UCON_SE0                    ((uint32_t)1<<(USB_UCON_SE0_POS))
#define USB_UCON_DBRST                  ((uint32_t)1<<(USB_UCON_DBRST_POS))

/* USB_USTAT λ�� */
#define USB_USTAT_DBI_POS               (1)
#define USB_USTAT_PDIR_POS              (2)
#define USB_USTAT_PEP0_POS              (3)
#define USB_USTAT_PEP1_POS              (4)
#define USB_USTAT_PEP2_POS              (5)
#define USB_USTAT_PEP3_POS              (6)
#define USB_USTAT_DBI                   ((uint32_t)1<<(USB_USTAT_DBI_POS))
#define USB_USTAT_PDIR                  ((uint32_t)1<<(USB_USTAT_PDIR_POS))
#define USB_USTAT_PEP                   ((uint32_t)0xF<<(USB_USTAT_PEP0_POS))
#define USB_USTAT_PEP0                  ((uint32_t)1<<(USB_USTAT_PEP0_POS))
#define USB_USTAT_PEP1                  ((uint32_t)1<<(USB_USTAT_PEP1_POS))
#define USB_USTAT_PEP2                  ((uint32_t)1<<(USB_USTAT_PEP2_POS))
#define USB_USTAT_PEP3                  ((uint32_t)1<<(USB_USTAT_PEP3_POS))

/* USB_UADDR λ�� */
#define USB_UADDR_UADDR0_POS            (0)
#define USB_UADDR_UADDR1_POS            (1)
#define USB_UADDR_UADDR2_POS            (2)
#define USB_UADDR_UADDR3_POS            (3)
#define USB_UADDR_UADDR4_POS            (4)
#define USB_UADDR_UADDR5_POS            (5)
#define USB_UADDR_UADDR6_POS            (6)
#define USB_UADDR_UADDR                 ((uint32_t)0x7F<<(USB_UADDR_UADDR0_POS))
#define USB_UADDR_UADDR0                ((uint32_t)1<<(USB_UADDR_UADDR0_POS))
#define USB_UADDR_UADDR1                ((uint32_t)1<<(USB_UADDR_UADDR1_POS))
#define USB_UADDR_UADDR2                ((uint32_t)1<<(USB_UADDR_UADDR2_POS))
#define USB_UADDR_UADDR3                ((uint32_t)1<<(USB_UADDR_UADDR3_POS))
#define USB_UADDR_UADDR4                ((uint32_t)1<<(USB_UADDR_UADDR4_POS))
#define USB_UADDR_UADDR5                ((uint32_t)1<<(USB_UADDR_UADDR5_POS))
#define USB_UADDR_UADDR6                ((uint32_t)1<<(USB_UADDR_UADDR6_POS))

/* USB_UFRM λ�� */
#define USB_UFRM_UFRM0_POS              (0)
#define USB_UFRM_UFRM1_POS              (1)
#define USB_UFRM_UFRM2_POS              (2)
#define USB_UFRM_UFRM3_POS              (3)
#define USB_UFRM_UFRM4_POS              (4)
#define USB_UFRM_UFRM5_POS              (5)
#define USB_UFRM_UFRM6_POS              (6)
#define USB_UFRM_UFRM7_POS              (7)
#define USB_UFRM_UFRM8_POS              (8)
#define USB_UFRM_UFRM9_POS              (9)
#define USB_UFRM_UFRM10_POS             (10)
#define USB_UFRM_UFRM                   ((uint32_t)0x7FF<<(USB_UFRM_UFRM0_POS))
#define USB_UFRM_UFRM0                  ((uint32_t)1<<(USB_UFRM_UFRM0_POS))
#define USB_UFRM_UFRM1                  ((uint32_t)1<<(USB_UFRM_UFRM1_POS))
#define USB_UFRM_UFRM2                  ((uint32_t)1<<(USB_UFRM_UFRM2_POS))
#define USB_UFRM_UFRM3                  ((uint32_t)1<<(USB_UFRM_UFRM3_POS))
#define USB_UFRM_UFRM4                  ((uint32_t)1<<(USB_UFRM_UFRM4_POS))
#define USB_UFRM_UFRM5                  ((uint32_t)1<<(USB_UFRM_UFRM5_POS))
#define USB_UFRM_UFRM6                  ((uint32_t)1<<(USB_UFRM_UFRM6_POS))
#define USB_UFRM_UFRM7                  ((uint32_t)1<<(USB_UFRM_UFRM7_POS))
#define USB_UFRM_UFRM8                  ((uint32_t)1<<(USB_UFRM_UFRM8_POS))
#define USB_UFRM_UFRM9                  ((uint32_t)1<<(USB_UFRM_UFRM9_POS))
#define USB_UFRM_UFRM10                 ((uint32_t)1<<(USB_UFRM_UFRM10_POS))

/* USB_UIR λ�� */
#define USB_UIR_ERRIF_POS               (0)
#define USB_UIR_RSTIF_POS               (1)
#define USB_UIR_TRNSIF_POS              (2)
#define USB_UIR_ACTVIF_POS              (3)
#define USB_UIR_IDLEIF_POS              (4)
#define USB_UIR_STLIF_POS               (5)
#define USB_UIR_SOFIF_POS               (6)
#define USB_UIR_DFN8EIF_POS             (8)
#define USB_UIR_CRC5EIF_POS             (9)
#define USB_UIR_CRC16EIF_POS            (10)
#define USB_UIR_PIDEIF_POS              (11)
#define USB_UIR_BTOEIF_POS              (12)
#define USB_UIR_BTSEIF_POS              (13)
#define USB_UIR_ERRIF                   ((uint32_t)1<<(USB_UIR_ERRIF_POS))
#define USB_UIR_RSTIF                   ((uint32_t)1<<(USB_UIR_RSTIF_POS))
#define USB_UIR_TRNSIF                  ((uint32_t)1<<(USB_UIR_TRNSIF_POS))
#define USB_UIR_ACTVIF                  ((uint32_t)1<<(USB_UIR_ACTVIF_POS))
#define USB_UIR_IDLEIF                  ((uint32_t)1<<(USB_UIR_IDLEIF_POS))
#define USB_UIR_STLIF                   ((uint32_t)1<<(USB_UIR_STLIF_POS))
#define USB_UIR_SOFIF                   ((uint32_t)1<<(USB_UIR_SOFIF_POS))
#define USB_UIR_DFN8EIF                 ((uint32_t)1<<(USB_UIR_DFN8EIF_POS))
#define USB_UIR_CRC5EIF                 ((uint32_t)1<<(USB_UIR_CRC5EIF_POS))
#define USB_UIR_CRC16EIF                ((uint32_t)1<<(USB_UIR_CRC16EIF_POS))
#define USB_UIR_PIDEIF                  ((uint32_t)1<<(USB_UIR_PIDEIF_POS))
#define USB_UIR_BTOEIF                  ((uint32_t)1<<(USB_UIR_BTOEIF_POS))
#define USB_UIR_BTSEIF                  ((uint32_t)1<<(USB_UIR_BTSEIF_POS))

/* USB_UIE λ�� */
#define USB_UIE_ERRIE_POS               (0)
#define USB_UIE_RSTIE_POS               (1)
#define USB_UIE_TRNSIE_POS              (2)
#define USB_UIE_ACTVIE_POS              (3)
#define USB_UIE_IDLEIE_POS              (4)
#define USB_UIE_STLIE_POS               (5)
#define USB_UIE_SOFIE_POS               (6)
#define USB_UIE_DFN8EIE_POS             (8)
#define USB_UIE_CRC5EIE_POS             (9)
#define USB_UIE_CRC16EIE_POS            (10)
#define USB_UIE_PIDEIE_POS              (11)
#define USB_UIE_BTOEIE_POS              (12)
#define USB_UIE_BTSEIE_POS              (13)
#define USB_UIE_ERRIE                   ((uint32_t)1<<(USB_UIE_ERRIE_POS))
#define USB_UIE_RSTIE                   ((uint32_t)1<<(USB_UIE_RSTIE_POS))
#define USB_UIE_TRNSIE                  ((uint32_t)1<<(USB_UIE_TRNSIE_POS))
#define USB_UIE_ACTVIE                  ((uint32_t)1<<(USB_UIE_ACTVIE_POS))
#define USB_UIE_IDLEIE                  ((uint32_t)1<<(USB_UIE_IDLEIE_POS))
#define USB_UIE_STLIE                   ((uint32_t)1<<(USB_UIE_STLIE_POS))
#define USB_UIE_SOFIE                   ((uint32_t)1<<(USB_UIE_SOFIE_POS))
#define USB_UIE_DFN8EIE                 ((uint32_t)1<<(USB_UIE_DFN8EIE_POS))
#define USB_UIE_CRC5EIE                 ((uint32_t)1<<(USB_UIE_CRC5EIE_POS))
#define USB_UIE_CRC16EIE                ((uint32_t)1<<(USB_UIE_CRC16EIE_POS))
#define USB_UIE_PIDEIE                  ((uint32_t)1<<(USB_UIE_PIDEIE_POS))
#define USB_UIE_BTOEIE                  ((uint32_t)1<<(USB_UIE_BTOEIE_POS))
#define USB_UIE_BTSEIE                  ((uint32_t)1<<(USB_UIE_BTSEIE_POS))

/* USB_UEPn λ�� */
#define USB_UEP_EPSTL_POS               (0)
#define USB_UEP_EPINEN_POS              (1)
#define USB_UEP_EPOUTEN_POS             (2)
#define USB_UEP_EPCONDIS_POS            (3)
#define USB_UEP_EPHSHK_POS              (4)
#define USB_UEP_EPSTL                   ((uint32_t)1<<(USB_UEP_EPSTL_POS))
#define USB_UEP_EPINEN                  ((uint32_t)1<<(USB_UEP_EPINEN_POS))
#define USB_UEP_EPOUTEN                 ((uint32_t)1<<(USB_UEP_EPOUTEN_POS))
#define USB_UEP_EPCONDIS                ((uint32_t)1<<(USB_UEP_EPCONDIS_POS))
#define USB_UEP_EPHSHK                  ((uint32_t)1<<(USB_UEP_EPHSHK_POS))

/* USB_UDB λ�� */
#define USB_UDB_DEBUG0_POS              (0)
#define USB_UDB_DEBUG1_POS              (1)
#define USB_UDB_DEBUG2_POS              (2)
#define USB_UDB_DEBUGEN_POS             (4)
#define USB_UDB_DEBUG                   ((uint32_t)7<<(USB_UDB_DEBUG0_POS))
#define USB_UDB_DEBUG0                  ((uint32_t)1<<(USB_UDB_DEBUG0_POS))
#define USB_UDB_DEBUG1                  ((uint32_t)1<<(USB_UDB_DEBUG1_POS))
#define USB_UDB_DEBUG2                  ((uint32_t)1<<(USB_UDB_DEBUG2_POS))
#define USB_UDB_DEBUGEN                 ((uint32_t)1<<(USB_UDB_DEBUGEN_POS))

/* USB_BDnSTAT λ�� */
#define USB_BDSTAT_BC8_POS              (0)
#define USB_BDSTAT_BC9_POS              (1)
#define USB_BDSTAT_BSTALL_POS           (2)
#define USB_BDSTAT_DTSEN_POS            (3)
#define USB_BDSTAT_PID0_POS             (2)
#define USB_BDSTAT_PID1_POS             (3)
#define USB_BDSTAT_PID2_POS             (4)
#define USB_BDSTAT_PID3_POS             (5)
#define USB_BDSTAT_DTS_POS              (6)
#define USB_BDSTAT_UOWN_POS             (7)
#define USB_BDSTAT_BC0_POS              (8)
#define USB_BDSTAT_BC1_POS              (9)
#define USB_BDSTAT_BC2_POS              (10)
#define USB_BDSTAT_BC3_POS              (11)
#define USB_BDSTAT_BC4_POS              (12)
#define USB_BDSTAT_BC5_POS              (13)
#define USB_BDSTAT_BC6_POS              (14)
#define USB_BDSTAT_BC7_POS              (15)
#define USB_BDSTAT_BADDR0_POS           (16)
#define USB_BDSTAT_BCH                  ((uint32_t)3<<(USB_BDSTAT_BC8_POS))
#define USB_BDSTAT_BC8                  ((uint32_t)1<<(USB_BDSTAT_BC8_POS))
#define USB_BDSTAT_BC9                  ((uint32_t)1<<(USB_BDSTAT_BC9_POS))
#define USB_BDSTAT_BSTALL               ((uint32_t)1<<(USB_BDSTAT_BSTALL_POS))
#define USB_BDSTAT_DTSEN                ((uint32_t)1<<(USB_BDSTAT_DTSEN_POS))
#define USB_BDSTAT_PID                  ((uint32_t)0xF<<(USB_BDSTAT_PID0_POS))
#define USB_BDSTAT_PID0                 ((uint32_t)1<<(USB_BDSTAT_PID0_POS))
#define USB_BDSTAT_PID1                 ((uint32_t)1<<(USB_BDSTAT_PID1_POS))
#define USB_BDSTAT_PID2                 ((uint32_t)1<<(USB_BDSTAT_PID2_POS))
#define USB_BDSTAT_PID3                 ((uint32_t)1<<(USB_BDSTAT_PID3_POS))
#define USB_BDSTAT_DTS                  ((uint32_t)1<<(USB_BDSTAT_DTS_POS))
#define USB_BDSTAT_UOWN                 ((uint32_t)1<<(USB_BDSTAT_UOWN_POS))
#define USB_BDSTAT_BC                   ((USB_BDSTAT_BCL) | (USB_BDSTAT_BCH))
#define USB_BDSTAT_BCL                  ((uint32_t)0xFF<<(USB_BDSTAT_BC0_POS))
#define USB_BDSTAT_BC0                  ((uint32_t)1<<(USB_BDSTAT_BC0_POS))
#define USB_BDSTAT_BC1                  ((uint32_t)1<<(USB_BDSTAT_BC1_POS))
#define USB_BDSTAT_BC2                  ((uint32_t)1<<(USB_BDSTAT_BC2_POS))
#define USB_BDSTAT_BC3                  ((uint32_t)1<<(USB_BDSTAT_BC3_POS))
#define USB_BDSTAT_BC4                  ((uint32_t)1<<(USB_BDSTAT_BC4_POS))
#define USB_BDSTAT_BC5                  ((uint32_t)1<<(USB_BDSTAT_BC5_POS))
#define USB_BDSTAT_BC6                  ((uint32_t)1<<(USB_BDSTAT_BC6_POS))
#define USB_BDSTAT_BC7                  ((uint32_t)1<<(USB_BDSTAT_BC7_POS))
#define USB_BDSTAT_BADDR                ((uint32_t)0xFFFF<<(USB_BDSTAT_BADDR0_POS))
/* ͨ�ô������� (USB)������� */
#endif //KF32F_Periph_usb

/* ----------------------------------------------------------------------------
   -- ���������������� (CAN)
   ---------------------------------------------------------------------------- */
#ifdef KF32F_Periph_can
/* CAN - ����Ĵ����ڴ�ṹ */
typedef struct CAN_MemMap {
    volatile       uint32_t CTLR;       /* CAN���ƼĴ���, ƫ��:0x0 */
    volatile       uint32_t BRGR;       /* CAN�����ʼĴ���, ƫ��:0x4 */
    volatile const uint32_t RCR;        /* CAN��¼�Ĵ���, ƫ��:0x8 */
    volatile       uint32_t EROR;       /* CAN����Ĵ���, ƫ��:0xC */
    volatile       uint32_t ACRR;       /* CAN���մ���Ĵ���, ƫ��:0x10 */
    volatile       uint32_t MSKR;       /* CAN�������μĴ���, ƫ��:0x14 */
    volatile       uint32_t IER;        /* CAN�ж�ʹ�ܼĴ���, ƫ��:0x18 */
    volatile       uint32_t IFR;        /* CAN�жϱ�־�Ĵ���, ƫ��:0x1C */
    volatile       uint32_t INFR;       /* CAN������Ϣ�Ĵ���, ƫ��:0x20 */
    volatile       uint32_t TX0R;       /* CAN���ݼĴ���0, ƫ��:0x24 */
    volatile       uint32_t TX1R;       /* CAN���ݼĴ���1, ƫ��:0x28 */
    volatile       uint32_t TX2R;       /* CAN���ݼĴ���2, ƫ��:0x2C */
}CAN_SFRmap;

/* ----------------------------------------------------------------------------
   -- CAN - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */

/* CAN - �Ĵ�����ڵ�ַ */
#ifdef  KF32F_Periph_can0
#define CAN0_ADDR                       ((uint32_t)0x40001100)
#define CAN0_SFR                        ((CAN_SFRmap *) CAN0_ADDR)
#endif
#ifdef  KF32F_Periph_can1
#define CAN1_ADDR                       ((uint32_t)0x40001180)
#define CAN1_SFR                        ((CAN_SFRmap *) CAN1_ADDR)
#endif
#ifdef  KF32F_Periph_can2
#define CAN2_ADDR                       ((uint32_t)0x40001900)
#define CAN2_SFR                        ((CAN_SFRmap *) CAN2_ADDR)
#endif
#ifdef  KF32F_Periph_can3
#define CAN3_ADDR                       ((uint32_t)0x40001980)
#define CAN3_SFR                        ((CAN_SFRmap *) CAN3_ADDR)
#endif
#ifdef  KF32F_Periph_can4
#define CAN4_ADDR                       ((uint32_t)0x40002880)
#define CAN4_SFR                        ((CAN_SFRmap *) CAN4_ADDR)
#endif
#ifdef  KF32F_Periph_can5
#define CAN5_ADDR                       ((uint32_t)0x40002900)
#define CAN5_SFR                        ((CAN_SFRmap *) CAN5_ADDR)
#endif

/* CAN - �Ĵ������ */
#ifdef  KF32F_Periph_can0
#define CAN0_CTLR                       (CAN0_SFR->CTLR)
#define CAN0_BRGR                       (CAN0_SFR->BRGR)
#define CAN0_RCR                        (CAN0_SFR->RCR)
#define CAN0_EROR                       (CAN0_SFR->EROR)
#define CAN0_ACRR                       (CAN0_SFR->ACRR)
#define CAN0_MSKR                       (CAN0_SFR->MSKR)
#define CAN0_IER                        (CAN0_SFR->IER)
#define CAN0_IFR                        (CAN0_SFR->IFR)
#define CAN0_INFR                       (CAN0_SFR->INFR)
#define CAN0_TX0R                       (CAN0_SFR->TX0R)
#define CAN0_TX1R                       (CAN0_SFR->TX1R)
#define CAN0_TX2R                       (CAN0_SFR->TX2R)
#endif
#ifdef  KF32F_Periph_can1
#define CAN1_CTLR                       (CAN1_SFR->CTLR)
#define CAN1_BRGR                       (CAN1_SFR->BRGR)
#define CAN1_RCR                        (CAN1_SFR->RCR)
#define CAN1_EROR                       (CAN1_SFR->EROR)
#define CAN1_ACRR                       (CAN1_SFR->ACRR)
#define CAN1_MSKR                       (CAN1_SFR->MSKR)
#define CAN1_IER                        (CAN1_SFR->IER)
#define CAN1_IFR                        (CAN1_SFR->IFR)
#define CAN1_INFR                       (CAN1_SFR->INFR)
#define CAN1_TX0R                       (CAN1_SFR->TX0R)
#define CAN1_TX1R                       (CAN1_SFR->TX1R)
#define CAN1_TX2R                       (CAN1_SFR->TX2R)
#endif
#ifdef  KF32F_Periph_can2
#define CAN2_CTLR                       (CAN2_SFR->CTLR)
#define CAN2_BRGR                       (CAN2_SFR->BRGR)
#define CAN2_RCR                        (CAN2_SFR->RCR)
#define CAN2_EROR                       (CAN2_SFR->EROR)
#define CAN2_ACRR                       (CAN2_SFR->ACRR)
#define CAN2_MSKR                       (CAN2_SFR->MSKR)
#define CAN2_IER                        (CAN2_SFR->IER)
#define CAN2_IFR                        (CAN2_SFR->IFR)
#define CAN2_INFR                       (CAN2_SFR->INFR)
#define CAN2_TX0R                       (CAN2_SFR->TX0R)
#define CAN2_TX1R                       (CAN2_SFR->TX1R)
#define CAN2_TX2R                       (CAN2_SFR->TX2R)
#endif
#ifdef  KF32F_Periph_can3
#define CAN3_CTLR                       (CAN3_SFR->CTLR)
#define CAN3_BRGR                       (CAN3_SFR->BRGR)
#define CAN3_RCR                        (CAN3_SFR->RCR)
#define CAN3_EROR                       (CAN3_SFR->EROR)
#define CAN3_ACRR                       (CAN3_SFR->ACRR)
#define CAN3_MSKR                       (CAN3_SFR->MSKR)
#define CAN3_IER                        (CAN3_SFR->IER)
#define CAN3_IFR                        (CAN3_SFR->IFR)
#define CAN3_INFR                       (CAN3_SFR->INFR)
#define CAN3_TX0R                       (CAN3_SFR->TX0R)
#define CAN3_TX1R                       (CAN3_SFR->TX1R)
#define CAN3_TX2R                       (CAN3_SFR->TX2R)
#endif
#ifdef  KF32F_Periph_can4
#define CAN4_CTLR                       (CAN4_SFR->CTLR)
#define CAN4_BRGR                       (CAN4_SFR->BRGR)
#define CAN4_RCR                        (CAN4_SFR->RCR)
#define CAN4_EROR                       (CAN4_SFR->EROR)
#define CAN4_ACRR                       (CAN4_SFR->ACRR)
#define CAN4_MSKR                       (CAN4_SFR->MSKR)
#define CAN4_IER                        (CAN4_SFR->IER)
#define CAN4_IFR                        (CAN4_SFR->IFR)
#define CAN4_INFR                       (CAN4_SFR->INFR)
#define CAN4_TX0R                       (CAN4_SFR->TX0R)
#define CAN4_TX1R                       (CAN4_SFR->TX1R)
#define CAN4_TX2R                       (CAN4_SFR->TX2R)
#endif
#ifdef  KF32F_Periph_can5
#define CAN5_CTLR                       (CAN5_SFR->CTLR)
#define CAN5_BRGR                       (CAN5_SFR->BRGR)
#define CAN5_RCR                        (CAN5_SFR->RCR)
#define CAN5_EROR                       (CAN5_SFR->EROR)
#define CAN5_ACRR                       (CAN5_SFR->ACRR)
#define CAN5_MSKR                       (CAN5_SFR->MSKR)
#define CAN5_IER                        (CAN5_SFR->IER)
#define CAN5_IFR                        (CAN5_SFR->IFR)
#define CAN5_INFR                       (CAN5_SFR->INFR)
#define CAN5_TX0R                       (CAN5_SFR->TX0R)
#define CAN5_TX1R                       (CAN5_SFR->TX1R)
#define CAN5_TX2R                       (CAN5_SFR->TX2R)
#endif
/* CAN_CTLR λ�� */
#define CAN_CTLR_RSMOD_POS              (0)
#define CAN_CTLR_SILENT_POS             (1)
#define CAN_CTLR_LBACK_POS              (2)
#define CAN_CTLR_SLEEP_POS              (3)
#define CAN_CTLR_CANCKS0_POS            (5)
#define CAN_CTLR_CANCKS1_POS            (6)
#define CAN_CTLR_CANEN_POS              (7)
#define CAN_CTLR_TXR_POS                (8)
#define CAN_CTLR_ATX_POS                (9)
#define CAN_CTLR_RELRX_POS              (10)
#define CAN_CTLR_RELF_POS               (11)
#define CAN_CTLR_RXBSTA_POS             (16)
#define CAN_CTLR_DOSTA_POS              (17)
#define CAN_CTLR_TXBSTA_POS             (18)
#define CAN_CTLR_TCSTA_POS              (19)
#define CAN_CTLR_RXSTA_POS              (20)
#define CAN_CTLR_TXSTA_POS              (21)
#define CAN_CTLR_CERROR_POS             (22)
#define CAN_CTLR_BOFF_POS               (23)
#define CAN_CTLR_CANRMC0_POS            (24)
#define CAN_CTLR_CANRMC1_POS            (25)
#define CAN_CTLR_CANRMC2_POS            (26)
#define CAN_CTLR_CANRMC3_POS            (27)
#define CAN_CTLR_CANRMC4_POS            (28)
#define CAN_CTLR_RSMOD                  ((uint32_t)1<<(CAN_CTLR_RSMOD_POS))
#define CAN_CTLR_SILENT                 ((uint32_t)1<<(CAN_CTLR_SILENT_POS))
#define CAN_CTLR_LBACK                  ((uint32_t)1<<(CAN_CTLR_LBACK_POS))
#define CAN_CTLR_SLEEP                  ((uint32_t)1<<(CAN_CTLR_SLEEP_POS))
#define CAN_CTLR_CANCKS                 ((uint32_t)3<<(CAN_CTLR_CANCKS0_POS))
#define CAN_CTLR_CANCKS0                ((uint32_t)1<<(CAN_CTLR_CANCKS0_POS))
#define CAN_CTLR_CANCKS1                ((uint32_t)1<<(CAN_CTLR_CANCKS1_POS))
#define CAN_CTLR_CANEN                  ((uint32_t)1<<(CAN_CTLR_CANEN_POS))
#define CAN_CTLR_TXR                    ((uint32_t)1<<(CAN_CTLR_TXR_POS))
#define CAN_CTLR_ATX                    ((uint32_t)1<<(CAN_CTLR_ATX_POS))
#define CAN_CTLR_RELRX                  ((uint32_t)1<<(CAN_CTLR_RELRX_POS))
#define CAN_CTLR_RELF                   ((uint32_t)1<<(CAN_CTLR_RELF_POS))
#define CAN_CTLR_RXBSTA                 ((uint32_t)1<<(CAN_CTLR_RXBSTA_POS))
#define CAN_CTLR_DOSTA                  ((uint32_t)1<<(CAN_CTLR_DOSTA_POS))
#define CAN_CTLR_TXBSTA                 ((uint32_t)1<<(CAN_CTLR_TXBSTA_POS))
#define CAN_CTLR_TCSTA                  ((uint32_t)1<<(CAN_CTLR_TCSTA_POS))
#define CAN_CTLR_RXSTA                  ((uint32_t)1<<(CAN_CTLR_RXSTA_POS))
#define CAN_CTLR_TXSTA                  ((uint32_t)1<<(CAN_CTLR_TXSTA_POS))
#define CAN_CTLR_CERROR                 ((uint32_t)1<<(CAN_CTLR_CERROR_POS))
#define CAN_CTLR_BOFF                   ((uint32_t)1<<(CAN_CTLR_BOFF_POS))
#define CAN_CTLR_CANRMC                 ((uint32_t)0x1F<<(CAN_CTLR_CANRMC0_POS))
#define CAN_CTLR_CANRMC0                ((uint32_t)1<<(CAN_CTLR_CANRMC0_POS))
#define CAN_CTLR_CANRMC1                ((uint32_t)1<<(CAN_CTLR_CANRMC1_POS))
#define CAN_CTLR_CANRMC2                ((uint32_t)1<<(CAN_CTLR_CANRMC2_POS))
#define CAN_CTLR_CANRMC3                ((uint32_t)1<<(CAN_CTLR_CANRMC3_POS))
#define CAN_CTLR_CANRMC4                ((uint32_t)1<<(CAN_CTLR_CANRMC4_POS))

/* CAN_BRGR λ��*/
#define CAN_BRGR_CANBRP0_POS            (0)
#define CAN_BRGR_CANBRP1_POS            (1)
#define CAN_BRGR_CANBRP2_POS            (2)
#define CAN_BRGR_CANBRP3_POS            (3)
#define CAN_BRGR_CANBRP4_POS            (4)
#define CAN_BRGR_CANBRP5_POS            (5)
#define CAN_BRGR_SJW0_POS               (6)
#define CAN_BRGR_SJW1_POS               (7)
#define CAN_BRGR_TSEG1_0_POS            (8)
#define CAN_BRGR_TSEG1_1_POS            (9)
#define CAN_BRGR_TSEG1_2_POS            (10)
#define CAN_BRGR_TSEG1_3_POS            (11)
#define CAN_BRGR_TSEG2_0_POS            (12)
#define CAN_BRGR_TSEG2_1_POS            (13)
#define CAN_BRGR_TSEG2_2_POS            (14)
#define CAN_BRGR_SAM_POS                (15)
#define CAN_BRGR_CANBRP                 ((uint32_t)0x3F<<(CAN_BRGR_CANBRP0_POS))
#define CAN_BRGR_CANBRP0                ((uint32_t)1<<(CAN_BRGR_CANBRP0_POS))
#define CAN_BRGR_CANBRP1                ((uint32_t)1<<(CAN_BRGR_CANBRP1_POS))
#define CAN_BRGR_CANBRP2                ((uint32_t)1<<(CAN_BRGR_CANBRP2_POS))
#define CAN_BRGR_CANBRP3                ((uint32_t)1<<(CAN_BRGR_CANBRP3_POS))
#define CAN_BRGR_CANBRP4                ((uint32_t)1<<(CAN_BRGR_CANBRP4_POS))
#define CAN_BRGR_CANBRP5                ((uint32_t)1<<(CAN_BRGR_CANBRP5_POS))
#define CAN_BRGR_SJW                    ((uint32_t)3<<(CAN_BRGR_SJW0_POS))
#define CAN_BRGR_SJW0                   ((uint32_t)1<<(CAN_BRGR_SJW0_POS))
#define CAN_BRGR_SJW1                   ((uint32_t)1<<(CAN_BRGR_SJW1_POS))
#define CAN_BRGR_TSEG1                  ((uint32_t)0xF<<(CAN_BRGR_TSEG1_0_POS))
#define CAN_BRGR_TSEG1_0                ((uint32_t)1<<(CAN_BRGR_TSEG1_0_POS))
#define CAN_BRGR_TSEG1_1                ((uint32_t)1<<(CAN_BRGR_TSEG1_1_POS))
#define CAN_BRGR_TSEG1_2                ((uint32_t)1<<(CAN_BRGR_TSEG1_2_POS))
#define CAN_BRGR_TSEG1_3                ((uint32_t)1<<(CAN_BRGR_TSEG1_3_POS))
#define CAN_BRGR_TSEG2                  ((uint32_t)7<<(CAN_BRGR_TSEG2_0_POS))
#define CAN_BRGR_TSEG2_0                ((uint32_t)1<<(CAN_BRGR_TSEG2_0_POS))
#define CAN_BRGR_TSEG2_1                ((uint32_t)1<<(CAN_BRGR_TSEG2_1_POS))
#define CAN_BRGR_TSEG2_2                ((uint32_t)1<<(CAN_BRGR_TSEG2_2_POS))
#define CAN_BRGR_SAM                    ((uint32_t)1<<(CAN_BRGR_SAM_POS))

/* CAN_RCR λ��*/
#define CAN_RCR_CANALC0_POS             (0)
#define CAN_RCR_CANALC1_POS             (1)
#define CAN_RCR_CANALC2_POS             (2)
#define CAN_RCR_CANALC3_POS             (3)
#define CAN_RCR_CANALC4_POS             (4)
#define CAN_RCR_CANSEG0_POS             (8)
#define CAN_RCR_CANSEG1_POS             (9)
#define CAN_RCR_CANSEG2_POS             (10)
#define CAN_RCR_CANSEG3_POS             (11)
#define CAN_RCR_CANSEG4_POS             (12)
#define CAN_RCR_CANDIR_POS              (13)
#define CAN_RCR_CANERRC0_POS            (14)
#define CAN_RCR_CANERRC1_POS            (15)
#define CAN_RCR_CANALC                  ((uint32_t)0x1F<<(CAN_RCR_CANALC0_POS))
#define CAN_RCR_CANALC0                 ((uint32_t)1<<(CAN_RCR_CANALC0_POS))
#define CAN_RCR_CANALC1                 ((uint32_t)1<<(CAN_RCR_CANALC1_POS))
#define CAN_RCR_CANALC2                 ((uint32_t)1<<(CAN_RCR_CANALC2_POS))
#define CAN_RCR_CANALC3                 ((uint32_t)1<<(CAN_RCR_CANALC3_POS))
#define CAN_RCR_CANALC4                 ((uint32_t)1<<(CAN_RCR_CANALC4_POS))
#define CAN_RCR_CANSEG                  ((uint32_t)0x1F<<(CAN_RCR_CANSEG0_POS))
#define CAN_RCR_CANSEG0                 ((uint32_t)1<<(CAN_RCR_CANSEG0_POS))
#define CAN_RCR_CANSEG1                 ((uint32_t)1<<(CAN_RCR_CANSEG1_POS))
#define CAN_RCR_CANSEG2                 ((uint32_t)1<<(CAN_RCR_CANSEG2_POS))
#define CAN_RCR_CANSEG3                 ((uint32_t)1<<(CAN_RCR_CANSEG3_POS))
#define CAN_RCR_CANSEG4                 ((uint32_t)1<<(CAN_RCR_CANSEG4_POS))
#define CAN_RCR_CANDIR                  ((uint32_t)1<<(CAN_RCR_CANDIR_POS))
#define CAN_RCR_CANERRC                 ((uint32_t)3<<(CAN_RCR_CANERRC0_POS))
#define CAN_RCR_CANERRC0                ((uint32_t)1<<(CAN_RCR_CANERRC0_POS))
#define CAN_RCR_CANERRC1                ((uint32_t)1<<(CAN_RCR_CANERRC1_POS))

/* CAN_EROR λ��*/
#define CAN_EROR_CANRXE0_POS            (0)
#define CAN_EROR_CANRXE1_POS            (1)
#define CAN_EROR_CANRXE2_POS            (2)
#define CAN_EROR_CANRXE3_POS            (3)
#define CAN_EROR_CANRXE4_POS            (4)
#define CAN_EROR_CANRXE5_POS            (5)
#define CAN_EROR_CANRXE6_POS            (6)
#define CAN_EROR_CANRXE7_POS            (7)
#define CAN_EROR_CANTXE0_POS            (8)
#define CAN_EROR_CANTXE1_POS            (9)
#define CAN_EROR_CANTXE2_POS            (10)
#define CAN_EROR_CANTXE3_POS            (11)
#define CAN_EROR_CANTXE4_POS            (12)
#define CAN_EROR_CANTXE5_POS            (13)
#define CAN_EROR_CANTXE6_POS            (14)
#define CAN_EROR_CANTXE7_POS            (15)
#define CAN_EROR_CANEWL0_POS            (16)
#define CAN_EROR_CANEWL1_POS            (17)
#define CAN_EROR_CANEWL2_POS            (18)
#define CAN_EROR_CANEWL3_POS            (19)
#define CAN_EROR_CANEWL4_POS            (20)
#define CAN_EROR_CANEWL5_POS            (21)
#define CAN_EROR_CANEWL6_POS            (22)
#define CAN_EROR_CANEWL7_POS            (23)
#define CAN_EROR_CANRXE                 ((uint32_t)0xFF<<(CAN_EROR_CANRXE0_POS))
#define CAN_EROR_CANRXE0                ((uint32_t)1<<(CAN_EROR_CANRXE0_POS))
#define CAN_EROR_CANRXE1                ((uint32_t)1<<(CAN_EROR_CANRXE1_POS))
#define CAN_EROR_CANRXE2                ((uint32_t)1<<(CAN_EROR_CANRXE2_POS))
#define CAN_EROR_CANRXE3                ((uint32_t)1<<(CAN_EROR_CANRXE3_POS))
#define CAN_EROR_CANRXE4                ((uint32_t)1<<(CAN_EROR_CANRXE4_POS))
#define CAN_EROR_CANRXE5                ((uint32_t)1<<(CAN_EROR_CANRXE5_POS))
#define CAN_EROR_CANRXE6                ((uint32_t)1<<(CAN_EROR_CANRXE6_POS))
#define CAN_EROR_CANRXE7                ((uint32_t)1<<(CAN_EROR_CANRXE7_POS))
#define CAN_EROR_CANTXE                 ((uint32_t)0xFF<<(CAN_EROR_CANTXE0_POS))
#define CAN_EROR_CANTXE0                ((uint32_t)1<<(CAN_EROR_CANTXE0_POS))
#define CAN_EROR_CANTXE1                ((uint32_t)1<<(CAN_EROR_CANTXE1_POS))
#define CAN_EROR_CANTXE2                ((uint32_t)1<<(CAN_EROR_CANTXE2_POS))
#define CAN_EROR_CANTXE3                ((uint32_t)1<<(CAN_EROR_CANTXE3_POS))
#define CAN_EROR_CANTXE4                ((uint32_t)1<<(CAN_EROR_CANTXE4_POS))
#define CAN_EROR_CANTXE5                ((uint32_t)1<<(CAN_EROR_CANTXE5_POS))
#define CAN_EROR_CANTXE6                ((uint32_t)1<<(CAN_EROR_CANTXE6_POS))
#define CAN_EROR_CANTXE7                ((uint32_t)1<<(CAN_EROR_CANTXE7_POS))
#define CAN_EROR_CANEWL                 ((uint32_t)0xFF<<(CAN_EROR_CANEWL0_POS))
#define CAN_EROR_CANEWL0                ((uint32_t)1<<(CAN_EROR_CANEWL0_POS))
#define CAN_EROR_CANEWL1                ((uint32_t)1<<(CAN_EROR_CANEWL1_POS))
#define CAN_EROR_CANEWL2                ((uint32_t)1<<(CAN_EROR_CANEWL2_POS))
#define CAN_EROR_CANEWL3                ((uint32_t)1<<(CAN_EROR_CANEWL3_POS))
#define CAN_EROR_CANEWL4                ((uint32_t)1<<(CAN_EROR_CANEWL4_POS))
#define CAN_EROR_CANEWL5                ((uint32_t)1<<(CAN_EROR_CANEWL5_POS))
#define CAN_EROR_CANEWL6                ((uint32_t)1<<(CAN_EROR_CANEWL6_POS))
#define CAN_EROR_CANEWL7                ((uint32_t)1<<(CAN_EROR_CANEWL7_POS))

/* CAN_ACRR λ��*/
#define CAN_ACRR_ACR0_POS               (0)
#define CAN_ACRR_ACR1_POS               (1)
#define CAN_ACRR_ACR2_POS               (2)
#define CAN_ACRR_ACR3_POS               (3)
#define CAN_ACRR_ACR4_POS               (4)
#define CAN_ACRR_ACR5_POS               (5)
#define CAN_ACRR_ACR6_POS               (6)
#define CAN_ACRR_ACR7_POS               (7)
#define CAN_ACRR_ACR8_POS               (8)
#define CAN_ACRR_ACR9_POS               (9)
#define CAN_ACRR_ACR10_POS              (10)
#define CAN_ACRR_ACR11_POS              (11)
#define CAN_ACRR_ACR12_POS              (12)
#define CAN_ACRR_ACR13_POS              (13)
#define CAN_ACRR_ACR14_POS              (14)
#define CAN_ACRR_ACR15_POS              (15)
#define CAN_ACRR_ACR16_POS              (16)
#define CAN_ACRR_ACR17_POS              (17)
#define CAN_ACRR_ACR18_POS              (18)
#define CAN_ACRR_ACR19_POS              (19)
#define CAN_ACRR_ACR20_POS              (20)
#define CAN_ACRR_ACR21_POS              (21)
#define CAN_ACRR_ACR22_POS              (22)
#define CAN_ACRR_ACR23_POS              (23)
#define CAN_ACRR_ACR24_POS              (24)
#define CAN_ACRR_ACR25_POS              (25)
#define CAN_ACRR_ACR26_POS              (26)
#define CAN_ACRR_ACR27_POS              (27)
#define CAN_ACRR_ACR28_POS              (28)
#define CAN_ACRR_ACR29_POS              (29)
#define CAN_ACRR_ACR30_POS              (30)
#define CAN_ACRR_ACR31_POS              (31)
#define CAN_ACRR_ACR                    ((uint32_t)0xFFFFFFFF<<(CAN_ACRR_ACR0_POS))
#define CAN_ACRR_ACR0                   ((uint32_t)1<<(CAN_ACRR_ACR0_POS))
#define CAN_ACRR_ACR1                   ((uint32_t)1<<(CAN_ACRR_ACR1_POS))
#define CAN_ACRR_ACR2                   ((uint32_t)1<<(CAN_ACRR_ACR2_POS))
#define CAN_ACRR_ACR3                   ((uint32_t)1<<(CAN_ACRR_ACR3_POS))
#define CAN_ACRR_ACR4                   ((uint32_t)1<<(CAN_ACRR_ACR4_POS))
#define CAN_ACRR_ACR5                   ((uint32_t)1<<(CAN_ACRR_ACR5_POS))
#define CAN_ACRR_ACR6                   ((uint32_t)1<<(CAN_ACRR_ACR6_POS))
#define CAN_ACRR_ACR7                   ((uint32_t)1<<(CAN_ACRR_ACR7_POS))
#define CAN_ACRR_ACR8                   ((uint32_t)1<<(CAN_ACRR_ACR8_POS))
#define CAN_ACRR_ACR9                   ((uint32_t)1<<(CAN_ACRR_ACR9_POS))
#define CAN_ACRR_ACR10                  ((uint32_t)1<<(CAN_ACRR_ACR10_POS))
#define CAN_ACRR_ACR11                  ((uint32_t)1<<(CAN_ACRR_ACR11_POS))
#define CAN_ACRR_ACR12                  ((uint32_t)1<<(CAN_ACRR_ACR12_POS))
#define CAN_ACRR_ACR13                  ((uint32_t)1<<(CAN_ACRR_ACR13_POS))
#define CAN_ACRR_ACR14                  ((uint32_t)1<<(CAN_ACRR_ACR14_POS))
#define CAN_ACRR_ACR15                  ((uint32_t)1<<(CAN_ACRR_ACR15_POS))
#define CAN_ACRR_ACR16                  ((uint32_t)1<<(CAN_ACRR_ACR16_POS))
#define CAN_ACRR_ACR17                  ((uint32_t)1<<(CAN_ACRR_ACR17_POS))
#define CAN_ACRR_ACR18                  ((uint32_t)1<<(CAN_ACRR_ACR18_POS))
#define CAN_ACRR_ACR19                  ((uint32_t)1<<(CAN_ACRR_ACR19_POS))
#define CAN_ACRR_ACR20                  ((uint32_t)1<<(CAN_ACRR_ACR20_POS))
#define CAN_ACRR_ACR21                  ((uint32_t)1<<(CAN_ACRR_ACR21_POS))
#define CAN_ACRR_ACR22                  ((uint32_t)1<<(CAN_ACRR_ACR22_POS))
#define CAN_ACRR_ACR23                  ((uint32_t)1<<(CAN_ACRR_ACR23_POS))
#define CAN_ACRR_ACR24                  ((uint32_t)1<<(CAN_ACRR_ACR24_POS))
#define CAN_ACRR_ACR25                  ((uint32_t)1<<(CAN_ACRR_ACR25_POS))
#define CAN_ACRR_ACR26                  ((uint32_t)1<<(CAN_ACRR_ACR26_POS))
#define CAN_ACRR_ACR27                  ((uint32_t)1<<(CAN_ACRR_ACR27_POS))
#define CAN_ACRR_ACR28                  ((uint32_t)1<<(CAN_ACRR_ACR28_POS))
#define CAN_ACRR_ACR29                  ((uint32_t)1<<(CAN_ACRR_ACR29_POS))
#define CAN_ACRR_ACR30                  ((uint32_t)1<<(CAN_ACRR_ACR30_POS))
#define CAN_ACRR_ACR31                  ((uint32_t)1<<(CAN_ACRR_ACR31_POS))

/* CAN_MSKR  λ��*/
#define CAN_MSKR_MSK0_POS               (0)
#define CAN_MSKR_MSK1_POS               (1)
#define CAN_MSKR_MSK2_POS               (2)
#define CAN_MSKR_MSK3_POS               (3)
#define CAN_MSKR_MSK4_POS               (4)
#define CAN_MSKR_MSK5_POS               (5)
#define CAN_MSKR_MSK6_POS               (6)
#define CAN_MSKR_MSK7_POS               (7)
#define CAN_MSKR_MSK8_POS               (8)
#define CAN_MSKR_MSK9_POS               (9)
#define CAN_MSKR_MSK10_POS              (10)
#define CAN_MSKR_MSK11_POS              (11)
#define CAN_MSKR_MSK12_POS              (12)
#define CAN_MSKR_MSK13_POS              (13)
#define CAN_MSKR_MSK14_POS              (14)
#define CAN_MSKR_MSK15_POS              (15)
#define CAN_MSKR_MSK16_POS              (16)
#define CAN_MSKR_MSK17_POS              (17)
#define CAN_MSKR_MSK18_POS              (18)
#define CAN_MSKR_MSK19_POS              (19)
#define CAN_MSKR_MSK20_POS              (20)
#define CAN_MSKR_MSK21_POS              (21)
#define CAN_MSKR_MSK22_POS              (22)
#define CAN_MSKR_MSK23_POS              (23)
#define CAN_MSKR_MSK24_POS              (24)
#define CAN_MSKR_MSK25_POS              (25)
#define CAN_MSKR_MSK26_POS              (26)
#define CAN_MSKR_MSK27_POS              (27)
#define CAN_MSKR_MSK28_POS              (28)
#define CAN_MSKR_MSK29_POS              (29)
#define CAN_MSKR_MSK30_POS              (30)
#define CAN_MSKR_MSK31_POS              (31)
#define CAN_MSKR_MSK                    ((uint32_t)0xFFFFFFFF<<(CAN_MSKR_MSK0_POS))
#define CAN_MSKR_MSK0                   ((uint32_t)1<<(CAN_MSKR_MSK0_POS))
#define CAN_MSKR_MSK1                   ((uint32_t)1<<(CAN_MSKR_MSK1_POS))
#define CAN_MSKR_MSK2                   ((uint32_t)1<<(CAN_MSKR_MSK2_POS))
#define CAN_MSKR_MSK3                   ((uint32_t)1<<(CAN_MSKR_MSK3_POS))
#define CAN_MSKR_MSK4                   ((uint32_t)1<<(CAN_MSKR_MSK4_POS))
#define CAN_MSKR_MSK5                   ((uint32_t)1<<(CAN_MSKR_MSK5_POS))
#define CAN_MSKR_MSK6                   ((uint32_t)1<<(CAN_MSKR_MSK6_POS))
#define CAN_MSKR_MSK7                   ((uint32_t)1<<(CAN_MSKR_MSK7_POS))
#define CAN_MSKR_MSK8                   ((uint32_t)1<<(CAN_MSKR_MSK8_POS))
#define CAN_MSKR_MSK9                   ((uint32_t)1<<(CAN_MSKR_MSK9_POS))
#define CAN_MSKR_MSK10                  ((uint32_t)1<<(CAN_MSKR_MSK10_POS))
#define CAN_MSKR_MSK11                  ((uint32_t)1<<(CAN_MSKR_MSK11_POS))
#define CAN_MSKR_MSK12                  ((uint32_t)1<<(CAN_MSKR_MSK12_POS))
#define CAN_MSKR_MSK13                  ((uint32_t)1<<(CAN_MSKR_MSK13_POS))
#define CAN_MSKR_MSK14                  ((uint32_t)1<<(CAN_MSKR_MSK14_POS))
#define CAN_MSKR_MSK15                  ((uint32_t)1<<(CAN_MSKR_MSK15_POS))
#define CAN_MSKR_MSK16                  ((uint32_t)1<<(CAN_MSKR_MSK16_POS))
#define CAN_MSKR_MSK17                  ((uint32_t)1<<(CAN_MSKR_MSK17_POS))
#define CAN_MSKR_MSK18                  ((uint32_t)1<<(CAN_MSKR_MSK18_POS))
#define CAN_MSKR_MSK19                  ((uint32_t)1<<(CAN_MSKR_MSK19_POS))
#define CAN_MSKR_MSK20                  ((uint32_t)1<<(CAN_MSKR_MSK20_POS))
#define CAN_MSKR_MSK21                  ((uint32_t)1<<(CAN_MSKR_MSK21_POS))
#define CAN_MSKR_MSK22                  ((uint32_t)1<<(CAN_MSKR_MSK22_POS))
#define CAN_MSKR_MSK23                  ((uint32_t)1<<(CAN_MSKR_MSK23_POS))
#define CAN_MSKR_MSK24                  ((uint32_t)1<<(CAN_MSKR_MSK24_POS))
#define CAN_MSKR_MSK25                  ((uint32_t)1<<(CAN_MSKR_MSK25_POS))
#define CAN_MSKR_MSK26                  ((uint32_t)1<<(CAN_MSKR_MSK26_POS))
#define CAN_MSKR_MSK27                  ((uint32_t)1<<(CAN_MSKR_MSK27_POS))
#define CAN_MSKR_MSK28                  ((uint32_t)1<<(CAN_MSKR_MSK28_POS))
#define CAN_MSKR_MSK29                  ((uint32_t)1<<(CAN_MSKR_MSK29_POS))
#define CAN_MSKR_MSK30                  ((uint32_t)1<<(CAN_MSKR_MSK30_POS))
#define CAN_MSKR_MSK31                  ((uint32_t)1<<(CAN_MSKR_MSK31_POS))

/* CAN_IER  λ��*/
#define CAN_IER_CANRXIE_POS             (0)
#define CAN_IER_CANTXIE_POS             (1)
#define CAN_IER_EAIE_POS                (2)
#define CAN_IER_DOVFIE_POS              (3)
#define CAN_IER_WUIE_POS                (4)
#define CAN_IER_ENIE_POS                (5)
#define CAN_IER_ALIE_POS                (6)
#define CAN_IER_BEIE_POS                (7)
#define CAN_IER_CANRXIC_POS             (16)
#define CAN_IER_CANTXIC_POS             (17)
#define CAN_IER_EAIC_POS                (18)
#define CAN_IER_DOVFIC_POS              (19)
#define CAN_IER_WUIC_POS                (20)
#define CAN_IER_ENIC_POS                (21)
#define CAN_IER_ALIC_POS                (22)
#define CAN_IER_BEIC_POS                (23)
#define CAN_IER_CANRXIE                 ((uint32_t)1<<(CAN_IER_CANRXIE_POS))
#define CAN_IER_CANTXIE                 ((uint32_t)1<<(CAN_IER_CANTXIE_POS))
#define CAN_IER_EAIE                    ((uint32_t)1<<(CAN_IER_EAIE_POS))
#define CAN_IER_DOVFIE                  ((uint32_t)1<<(CAN_IER_DOVFIE_POS))
#define CAN_IER_WUIE                    ((uint32_t)1<<(CAN_IER_WUIE_POS))
#define CAN_IER_ENIE                    ((uint32_t)1<<(CAN_IER_ENIE_POS))
#define CAN_IER_ALIE                    ((uint32_t)1<<(CAN_IER_ALIE_POS))
#define CAN_IER_BEIE                    ((uint32_t)1<<(CAN_IER_BEIE_POS))
#define CAN_IER_CANRXIC                 ((uint32_t)1<<(CAN_IER_CANRXIC_POS))
#define CAN_IER_CANTXIC                 ((uint32_t)1<<(CAN_IER_CANTXIC_POS))
#define CAN_IER_EAIC                    ((uint32_t)1<<(CAN_IER_EAIC_POS))
#define CAN_IER_DOVFIC                  ((uint32_t)1<<(CAN_IER_DOVFIC_POS))
#define CAN_IER_WUIC                    ((uint32_t)1<<(CAN_IER_WUIC_POS))
#define CAN_IER_ENIC                    ((uint32_t)1<<(CAN_IER_ENIC_POS))
#define CAN_IER_ALIC                    ((uint32_t)1<<(CAN_IER_ALIC_POS))
#define CAN_IER_BEIC                    ((uint32_t)1<<(CAN_IER_BEIC_POS))

/* CAN_IFR  λ��*/
#define CAN_IFR_CANRXIF_POS             (0)
#define CAN_IFR_CANTXIF_POS             (1)
#define CAN_IFR_EAIF_POS                (2)
#define CAN_IFR_DOVFIF_POS              (3)
#define CAN_IFR_WUIF_POS                (4)
#define CAN_IFR_ENIF_POS                (5)
#define CAN_IFR_ALIF_POS                (6)
#define CAN_IFR_BEIF_POS                (7)
#define CAN_IFR_CANRXIF                 ((uint32_t)1<<(CAN_IFR_CANRXIF_POS))
#define CAN_IFR_CANTXIF                 ((uint32_t)1<<(CAN_IFR_CANTXIF_POS))
#define CAN_IFR_EAIF                    ((uint32_t)1<<(CAN_IFR_EAIF_POS))
#define CAN_IFR_DOVFIF                  ((uint32_t)1<<(CAN_IFR_DOVFIF_POS))
#define CAN_IFR_WUIF                    ((uint32_t)1<<(CAN_IFR_WUIF_POS))
#define CAN_IFR_ENIF                    ((uint32_t)1<<(CAN_IFR_ENIF_POS))
#define CAN_IFR_ALIF                    ((uint32_t)1<<(CAN_IFR_ALIF_POS))
#define CAN_IFR_BEIF                    ((uint32_t)1<<(CAN_IFR_BEIF_POS))

/* CAN_INFR  λ��*/
#define CAN_INFR_DLC0_POS               (0)
#define CAN_INFR_DLC1_POS               (1)
#define CAN_INFR_DLC2_POS               (2)
#define CAN_INFR_DLC3_POS               (3)
#define CAN_INFR_RTR_POS                (6)
#define CAN_INFR_IDE_POS                (7)
#define CAN_INFR_DLC                    ((uint32_t)0xF<<(CAN_INFR_DLC0_POS))
#define CAN_INFR_DLC0                   ((uint32_t)1<<(CAN_INFR_DLC0_POS))
#define CAN_INFR_DLC1                   ((uint32_t)1<<(CAN_INFR_DLC1_POS))
#define CAN_INFR_DLC2                   ((uint32_t)1<<(CAN_INFR_DLC2_POS))
#define CAN_INFR_DLC3                   ((uint32_t)1<<(CAN_INFR_DLC3_POS))
#define CAN_INFR_RTR                    ((uint32_t)1<<(CAN_INFR_RTR_POS))
#define CAN_INFR_IDE                    ((uint32_t)1<<(CAN_INFR_IDE_POS))

/* CAN_TX0R  λ��*/
#define CAN_TX0R_SFF_RTR_POS            (20)
#define CAN_TX0R_EFF_RTR_POS            (2)
#define CAN_TX0R_ID0_POS                (3)
#define CAN_TX0R_ID1_POS                (4)
#define CAN_TX0R_ID2_POS                (5)
#define CAN_TX0R_ID3_POS                (6)
#define CAN_TX0R_ID4_POS                (7)
#define CAN_TX0R_ID5_POS                (8)
#define CAN_TX0R_ID6_POS                (9)
#define CAN_TX0R_ID7_POS                (10)
#define CAN_TX0R_ID8_POS                (11)
#define CAN_TX0R_ID9_POS                (12)
#define CAN_TX0R_ID10_POS               (13)
#define CAN_TX0R_ID11_POS               (14)
#define CAN_TX0R_ID12_POS               (15)
#define CAN_TX0R_ID13_POS               (16)
#define CAN_TX0R_ID14_POS               (17)
#define CAN_TX0R_ID15_POS               (18)
#define CAN_TX0R_ID16_POS               (19)
#define CAN_TX0R_ID17_POS               (20)
#define CAN_TX0R_ID18_POS               (21)
#define CAN_TX0R_ID19_POS               (22)
#define CAN_TX0R_ID20_POS               (23)
#define CAN_TX0R_ID21_POS               (24)
#define CAN_TX0R_ID22_POS               (25)
#define CAN_TX0R_ID23_POS               (26)
#define CAN_TX0R_ID24_POS               (27)
#define CAN_TX0R_ID25_POS               (28)
#define CAN_TX0R_ID26_POS               (29)
#define CAN_TX0R_ID27_POS               (30)
#define CAN_TX0R_ID28_POS               (31)
#define CAN_TX0R_SFF_RTR                ((uint32_t)1<<(CAN_TX0R_SFF_RTR_POS))
#define CAN_TX0R_EFF_RTR                ((uint32_t)1<<(CAN_TX0R_EFF_RTR_POS))
#define CAN_TX0R_SFF_ID                 ((uint32_t)0x7FF<<(CAN_TX0R_ID18_POS))
#define CAN_TX0R_EFF_ID                 ((uint32_t)0x1FFFFFFF<<(CAN_TX0R_ID0_POS))
#define CAN_TX0R_ID1                    ((uint32_t)1<<(CAN_TX0R_ID1_POS))
#define CAN_TX0R_ID2                    ((uint32_t)1<<(CAN_TX0R_ID2_POS))
#define CAN_TX0R_ID3                    ((uint32_t)1<<(CAN_TX0R_ID3_POS))
#define CAN_TX0R_ID4                    ((uint32_t)1<<(CAN_TX0R_ID4_POS))
#define CAN_TX0R_ID5                    ((uint32_t)1<<(CAN_TX0R_ID5_POS))
#define CAN_TX0R_ID6                    ((uint32_t)1<<(CAN_TX0R_ID6_POS))
#define CAN_TX0R_ID7                    ((uint32_t)1<<(CAN_TX0R_ID7_POS))
#define CAN_TX0R_ID8                    ((uint32_t)1<<(CAN_TX0R_ID8_POS))
#define CAN_TX0R_ID9                    ((uint32_t)1<<(CAN_TX0R_ID9_POS))
#define CAN_TX0R_ID10                   ((uint32_t)1<<(CAN_TX0R_ID10_POS))
#define CAN_TX0R_ID11                   ((uint32_t)1<<(CAN_TX0R_ID11_POS))
#define CAN_TX0R_ID12                   ((uint32_t)1<<(CAN_TX0R_ID12_POS))
#define CAN_TX0R_ID13                   ((uint32_t)1<<(CAN_TX0R_ID13_POS))
#define CAN_TX0R_ID14                   ((uint32_t)1<<(CAN_TX0R_ID14_POS))
#define CAN_TX0R_ID15                   ((uint32_t)1<<(CAN_TX0R_ID15_POS))
#define CAN_TX0R_ID16                   ((uint32_t)1<<(CAN_TX0R_ID16_POS))
#define CAN_TX0R_ID17                   ((uint32_t)1<<(CAN_TX0R_ID17_POS))
#define CAN_TX0R_ID18                   ((uint32_t)1<<(CAN_TX0R_ID18_POS))
#define CAN_TX0R_ID19                   ((uint32_t)1<<(CAN_TX0R_ID19_POS))
#define CAN_TX0R_ID20                   ((uint32_t)1<<(CAN_TX0R_ID20_POS))
#define CAN_TX0R_ID21                   ((uint32_t)1<<(CAN_TX0R_ID21_POS))
#define CAN_TX0R_ID22                   ((uint32_t)1<<(CAN_TX0R_ID22_POS))
#define CAN_TX0R_ID23                   ((uint32_t)1<<(CAN_TX0R_ID23_POS))
#define CAN_TX0R_ID24                   ((uint32_t)1<<(CAN_TX0R_ID24_POS))
#define CAN_TX0R_ID25                   ((uint32_t)1<<(CAN_TX0R_ID25_POS))
#define CAN_TX0R_ID26                   ((uint32_t)1<<(CAN_TX0R_ID26_POS))
#define CAN_TX0R_ID27                   ((uint32_t)1<<(CAN_TX0R_ID27_POS))
#define CAN_TX0R_ID28                   ((uint32_t)1<<(CAN_TX0R_ID28_POS))

#define CAN_TX0R_CANTX0_0_POS           (0)
#define CAN_TX0R_CANTX0_1_POS           (1)
#define CAN_TX0R_CANTX0_2_POS           (2)
#define CAN_TX0R_CANTX0_3_POS           (3)
#define CAN_TX0R_CANTX0_4_POS           (4)
#define CAN_TX0R_CANTX0_5_POS           (5)
#define CAN_TX0R_CANTX0_6_POS           (6)
#define CAN_TX0R_CANTX0_7_POS           (7)
#define CAN_TX0R_CANTX0_8_POS           (8)
#define CAN_TX0R_CANTX0_9_POS           (9)
#define CAN_TX0R_CANTX0_10_POS          (10)
#define CAN_TX0R_CANTX0_11_POS          (11)
#define CAN_TX0R_CANTX0_12_POS          (12)
#define CAN_TX0R_CANTX0_13_POS          (13)
#define CAN_TX0R_CANTX0_14_POS          (14)
#define CAN_TX0R_CANTX0_15_POS          (15)
#define CAN_TX0R_CANTX0_16_POS          (16)
#define CAN_TX0R_CANTX0_17_POS          (17)
#define CAN_TX0R_CANTX0_18_POS          (18)
#define CAN_TX0R_CANTX0_19_POS          (19)
#define CAN_TX0R_CANTX0_20_POS          (20)
#define CAN_TX0R_CANTX0_21_POS          (21)
#define CAN_TX0R_CANTX0_22_POS          (22)
#define CAN_TX0R_CANTX0_23_POS          (23)
#define CAN_TX0R_CANTX0_24_POS          (24)
#define CAN_TX0R_CANTX0_25_POS          (25)
#define CAN_TX0R_CANTX0_26_POS          (26)
#define CAN_TX0R_CANTX0_27_POS          (27)
#define CAN_TX0R_CANTX0_28_POS          (28)
#define CAN_TX0R_CANTX0_29_POS          (29)
#define CAN_TX0R_CANTX0_30_POS          (30)
#define CAN_TX0R_CANTX0_31_POS          (31)
#define CAN_TX0R_CANTX0                 ((uint32_t)0xFFFFFFFF<<(CAN_TX0R_CANTX0_0_POS))
#define CAN_TX0R_CANTX0_0               ((uint32_t)1<<(CAN_TX0R_CANTX0_0_POS))
#define CAN_TX0R_CANTX0_1               ((uint32_t)1<<(CAN_TX0R_CANTX0_1_POS))
#define CAN_TX0R_CANTX0_2               ((uint32_t)1<<(CAN_TX0R_CANTX0_2_POS))
#define CAN_TX0R_CANTX0_3               ((uint32_t)1<<(CAN_TX0R_CANTX0_3_POS))
#define CAN_TX0R_CANTX0_4               ((uint32_t)1<<(CAN_TX0R_CANTX0_4_POS))
#define CAN_TX0R_CANTX0_5               ((uint32_t)1<<(CAN_TX0R_CANTX0_5_POS))
#define CAN_TX0R_CANTX0_6               ((uint32_t)1<<(CAN_TX0R_CANTX0_6_POS))
#define CAN_TX0R_CANTX0_7               ((uint32_t)1<<(CAN_TX0R_CANTX0_7_POS))
#define CAN_TX0R_CANTX0_8               ((uint32_t)1<<(CAN_TX0R_CANTX0_8_POS))
#define CAN_TX0R_CANTX0_9               ((uint32_t)1<<(CAN_TX0R_CANTX0_9_POS))
#define CAN_TX0R_CANTX0_10              ((uint32_t)1<<(CAN_TX0R_CANTX0_10_POS))
#define CAN_TX0R_CANTX0_11              ((uint32_t)1<<(CAN_TX0R_CANTX0_11_POS))
#define CAN_TX0R_CANTX0_12              ((uint32_t)1<<(CAN_TX0R_CANTX0_12_POS))
#define CAN_TX0R_CANTX0_13              ((uint32_t)1<<(CAN_TX0R_CANTX0_13_POS))
#define CAN_TX0R_CANTX0_14              ((uint32_t)1<<(CAN_TX0R_CANTX0_14_POS))
#define CAN_TX0R_CANTX0_15              ((uint32_t)1<<(CAN_TX0R_CANTX0_15_POS))
#define CAN_TX0R_CANTX0_16              ((uint32_t)1<<(CAN_TX0R_CANTX0_16_POS))
#define CAN_TX0R_CANTX0_17              ((uint32_t)1<<(CAN_TX0R_CANTX0_17_POS))
#define CAN_TX0R_CANTX0_18              ((uint32_t)1<<(CAN_TX0R_CANTX0_18_POS))
#define CAN_TX0R_CANTX0_19              ((uint32_t)1<<(CAN_TX0R_CANTX0_19_POS))
#define CAN_TX0R_CANTX0_20              ((uint32_t)1<<(CAN_TX0R_CANTX0_20_POS))
#define CAN_TX0R_CANTX0_21              ((uint32_t)1<<(CAN_TX0R_CANTX0_21_POS))
#define CAN_TX0R_CANTX0_22              ((uint32_t)1<<(CAN_TX0R_CANTX0_22_POS))
#define CAN_TX0R_CANTX0_23              ((uint32_t)1<<(CAN_TX0R_CANTX0_23_POS))
#define CAN_TX0R_CANTX0_24              ((uint32_t)1<<(CAN_TX0R_CANTX0_24_POS))
#define CAN_TX0R_CANTX0_25              ((uint32_t)1<<(CAN_TX0R_CANTX0_25_POS))
#define CAN_TX0R_CANTX0_26              ((uint32_t)1<<(CAN_TX0R_CANTX0_26_POS))
#define CAN_TX0R_CANTX0_27              ((uint32_t)1<<(CAN_TX0R_CANTX0_27_POS))
#define CAN_TX0R_CANTX0_28              ((uint32_t)1<<(CAN_TX0R_CANTX0_28_POS))
#define CAN_TX0R_CANTX0_29              ((uint32_t)1<<(CAN_TX0R_CANTX0_29_POS))
#define CAN_TX0R_CANTX0_30              ((uint32_t)1<<(CAN_TX0R_CANTX0_30_POS))
#define CAN_TX0R_CANTX0_31              ((uint32_t)1<<(CAN_TX0R_CANTX0_31_POS))

/* CAN_TX1R  λ��*/
#define CAN_TX1R_CANTX1_0_POS           (0)
#define CAN_TX1R_CANTX1_1_POS           (1)
#define CAN_TX1R_CANTX1_2_POS           (2)
#define CAN_TX1R_CANTX1_3_POS           (3)
#define CAN_TX1R_CANTX1_4_POS           (4)
#define CAN_TX1R_CANTX1_5_POS           (5)
#define CAN_TX1R_CANTX1_6_POS           (6)
#define CAN_TX1R_CANTX1_7_POS           (7)
#define CAN_TX1R_CANTX1_8_POS           (8)
#define CAN_TX1R_CANTX1_9_POS           (9)
#define CAN_TX1R_CANTX1_10_POS          (10)
#define CAN_TX1R_CANTX1_11_POS          (11)
#define CAN_TX1R_CANTX1_12_POS          (12)
#define CAN_TX1R_CANTX1_13_POS          (13)
#define CAN_TX1R_CANTX1_14_POS          (14)
#define CAN_TX1R_CANTX1_15_POS          (15)
#define CAN_TX1R_CANTX1_16_POS          (16)
#define CAN_TX1R_CANTX1_17_POS          (17)
#define CAN_TX1R_CANTX1_18_POS          (18)
#define CAN_TX1R_CANTX1_19_POS          (19)
#define CAN_TX1R_CANTX1_20_POS          (20)
#define CAN_TX1R_CANTX1_21_POS          (21)
#define CAN_TX1R_CANTX1_22_POS          (22)
#define CAN_TX1R_CANTX1_23_POS          (23)
#define CAN_TX1R_CANTX1_24_POS          (24)
#define CAN_TX1R_CANTX1_25_POS          (25)
#define CAN_TX1R_CANTX1_26_POS          (26)
#define CAN_TX1R_CANTX1_27_POS          (27)
#define CAN_TX1R_CANTX1_28_POS          (28)
#define CAN_TX1R_CANTX1_29_POS          (29)
#define CAN_TX1R_CANTX1_30_POS          (30)
#define CAN_TX1R_CANTX1_31_POS          (31)
#define CAN_TX1R_CANTX1                 ((uint32_t)0xFFFFFFFF<<(CAN_TX1R_CANTX1_0_POS))
#define CAN_TX1R_CANTX1_0               ((uint32_t)1<<(CAN_TX1R_CANTX1_0_POS))
#define CAN_TX1R_CANTX1_1               ((uint32_t)1<<(CAN_TX1R_CANTX1_1_POS))
#define CAN_TX1R_CANTX1_2               ((uint32_t)1<<(CAN_TX1R_CANTX1_2_POS))
#define CAN_TX1R_CANTX1_3               ((uint32_t)1<<(CAN_TX1R_CANTX1_3_POS))
#define CAN_TX1R_CANTX1_4               ((uint32_t)1<<(CAN_TX1R_CANTX1_4_POS))
#define CAN_TX1R_CANTX1_5               ((uint32_t)1<<(CAN_TX1R_CANTX1_5_POS))
#define CAN_TX1R_CANTX1_6               ((uint32_t)1<<(CAN_TX1R_CANTX1_6_POS))
#define CAN_TX1R_CANTX1_7               ((uint32_t)1<<(CAN_TX1R_CANTX1_7_POS))
#define CAN_TX1R_CANTX1_8               ((uint32_t)1<<(CAN_TX1R_CANTX1_8_POS))
#define CAN_TX1R_CANTX1_9               ((uint32_t)1<<(CAN_TX1R_CANTX1_9_POS))
#define CAN_TX1R_CANTX1_10              ((uint32_t)1<<(CAN_TX1R_CANTX1_10_POS))
#define CAN_TX1R_CANTX1_11              ((uint32_t)1<<(CAN_TX1R_CANTX1_11_POS))
#define CAN_TX1R_CANTX1_12              ((uint32_t)1<<(CAN_TX1R_CANTX1_12_POS))
#define CAN_TX1R_CANTX1_13              ((uint32_t)1<<(CAN_TX1R_CANTX1_13_POS))
#define CAN_TX1R_CANTX1_14              ((uint32_t)1<<(CAN_TX1R_CANTX1_14_POS))
#define CAN_TX1R_CANTX1_15              ((uint32_t)1<<(CAN_TX1R_CANTX1_15_POS))
#define CAN_TX1R_CANTX1_16              ((uint32_t)1<<(CAN_TX1R_CANTX1_16_POS))
#define CAN_TX1R_CANTX1_17              ((uint32_t)1<<(CAN_TX1R_CANTX1_17_POS))
#define CAN_TX1R_CANTX1_18              ((uint32_t)1<<(CAN_TX1R_CANTX1_18_POS))
#define CAN_TX1R_CANTX1_19              ((uint32_t)1<<(CAN_TX1R_CANTX1_19_POS))
#define CAN_TX1R_CANTX1_20              ((uint32_t)1<<(CAN_TX1R_CANTX1_20_POS))
#define CAN_TX1R_CANTX1_21              ((uint32_t)1<<(CAN_TX1R_CANTX1_21_POS))
#define CAN_TX1R_CANTX1_22              ((uint32_t)1<<(CAN_TX1R_CANTX1_22_POS))
#define CAN_TX1R_CANTX1_23              ((uint32_t)1<<(CAN_TX1R_CANTX1_23_POS))
#define CAN_TX1R_CANTX1_24              ((uint32_t)1<<(CAN_TX1R_CANTX1_24_POS))
#define CAN_TX1R_CANTX1_25              ((uint32_t)1<<(CAN_TX1R_CANTX1_25_POS))
#define CAN_TX1R_CANTX1_26              ((uint32_t)1<<(CAN_TX1R_CANTX1_26_POS))
#define CAN_TX1R_CANTX1_27              ((uint32_t)1<<(CAN_TX1R_CANTX1_27_POS))
#define CAN_TX1R_CANTX1_28              ((uint32_t)1<<(CAN_TX1R_CANTX1_28_POS))
#define CAN_TX1R_CANTX1_29              ((uint32_t)1<<(CAN_TX1R_CANTX1_29_POS))
#define CAN_TX1R_CANTX1_30              ((uint32_t)1<<(CAN_TX1R_CANTX1_30_POS))
#define CAN_TX1R_CANTX1_31              ((uint32_t)1<<(CAN_TX1R_CANTX1_31_POS))

/* CAN_TX2R  λ��*/
#define CAN_TX2R_CANTX2_0_POS           (0)
#define CAN_TX2R_CANTX2_1_POS           (1)
#define CAN_TX2R_CANTX2_2_POS           (2)
#define CAN_TX2R_CANTX2_3_POS           (3)
#define CAN_TX2R_CANTX2_4_POS           (4)
#define CAN_TX2R_CANTX2_5_POS           (5)
#define CAN_TX2R_CANTX2_6_POS           (6)
#define CAN_TX2R_CANTX2_7_POS           (7)
#define CAN_TX2R_CANTX2_8_POS           (8)
#define CAN_TX2R_CANTX2_9_POS           (9)
#define CAN_TX2R_CANTX2_10_POS          (10)
#define CAN_TX2R_CANTX2_11_POS          (11)
#define CAN_TX2R_CANTX2_12_POS          (12)
#define CAN_TX2R_CANTX2_13_POS          (13)
#define CAN_TX2R_CANTX2_14_POS          (14)
#define CAN_TX2R_CANTX2_15_POS          (15)
#define CAN_TX2R_CANTX2_16_POS          (16)
#define CAN_TX2R_CANTX2_17_POS          (17)
#define CAN_TX2R_CANTX2_18_POS          (18)
#define CAN_TX2R_CANTX2_19_POS          (19)
#define CAN_TX2R_CANTX2_20_POS          (20)
#define CAN_TX2R_CANTX2_21_POS          (21)
#define CAN_TX2R_CANTX2_22_POS          (22)
#define CAN_TX2R_CANTX2_23_POS          (23)
#define CAN_TX2R_CANTX2_24_POS          (24)
#define CAN_TX2R_CANTX2_25_POS          (25)
#define CAN_TX2R_CANTX2_26_POS          (26)
#define CAN_TX2R_CANTX2_27_POS          (27)
#define CAN_TX2R_CANTX2_28_POS          (28)
#define CAN_TX2R_CANTX2_29_POS          (29)
#define CAN_TX2R_CANTX2_30_POS          (30)
#define CAN_TX2R_CANTX2_31_POS          (31)
#define CAN_TX2R_CANTX2                 ((uint32_t)0xFFFFFFFF<<(CAN_TX2R_CANTX2_0_POS))
#define CAN_TX2R_CANTX2_0               ((uint32_t)1<<(CAN_TX2R_CANTX2_0_POS))
#define CAN_TX2R_CANTX2_1               ((uint32_t)1<<(CAN_TX2R_CANTX2_1_POS))
#define CAN_TX2R_CANTX2_2               ((uint32_t)1<<(CAN_TX2R_CANTX2_2_POS))
#define CAN_TX2R_CANTX2_3               ((uint32_t)1<<(CAN_TX2R_CANTX2_3_POS))
#define CAN_TX2R_CANTX2_4               ((uint32_t)1<<(CAN_TX2R_CANTX2_4_POS))
#define CAN_TX2R_CANTX2_5               ((uint32_t)1<<(CAN_TX2R_CANTX2_5_POS))
#define CAN_TX2R_CANTX2_6               ((uint32_t)1<<(CAN_TX2R_CANTX2_6_POS))
#define CAN_TX2R_CANTX2_7               ((uint32_t)1<<(CAN_TX2R_CANTX2_7_POS))
#define CAN_TX2R_CANTX2_8               ((uint32_t)1<<(CAN_TX2R_CANTX2_8_POS))
#define CAN_TX2R_CANTX2_9               ((uint32_t)1<<(CAN_TX2R_CANTX2_9_POS))
#define CAN_TX2R_CANTX2_10              ((uint32_t)1<<(CAN_TX2R_CANTX2_10_POS))
#define CAN_TX2R_CANTX2_11              ((uint32_t)1<<(CAN_TX2R_CANTX2_11_POS))
#define CAN_TX2R_CANTX2_12              ((uint32_t)1<<(CAN_TX2R_CANTX2_12_POS))
#define CAN_TX2R_CANTX2_13              ((uint32_t)1<<(CAN_TX2R_CANTX2_13_POS))
#define CAN_TX2R_CANTX2_14              ((uint32_t)1<<(CAN_TX2R_CANTX2_14_POS))
#define CAN_TX2R_CANTX2_15              ((uint32_t)1<<(CAN_TX2R_CANTX2_15_POS))
#define CAN_TX2R_CANTX2_16              ((uint32_t)1<<(CAN_TX2R_CANTX2_16_POS))
#define CAN_TX2R_CANTX2_17              ((uint32_t)1<<(CAN_TX2R_CANTX2_17_POS))
#define CAN_TX2R_CANTX2_18              ((uint32_t)1<<(CAN_TX2R_CANTX2_18_POS))
#define CAN_TX2R_CANTX2_19              ((uint32_t)1<<(CAN_TX2R_CANTX2_19_POS))
#define CAN_TX2R_CANTX2_20              ((uint32_t)1<<(CAN_TX2R_CANTX2_20_POS))
#define CAN_TX2R_CANTX2_21              ((uint32_t)1<<(CAN_TX2R_CANTX2_21_POS))
#define CAN_TX2R_CANTX2_22              ((uint32_t)1<<(CAN_TX2R_CANTX2_22_POS))
#define CAN_TX2R_CANTX2_23              ((uint32_t)1<<(CAN_TX2R_CANTX2_23_POS))
#define CAN_TX2R_CANTX2_24              ((uint32_t)1<<(CAN_TX2R_CANTX2_24_POS))
#define CAN_TX2R_CANTX2_25              ((uint32_t)1<<(CAN_TX2R_CANTX2_25_POS))
#define CAN_TX2R_CANTX2_26              ((uint32_t)1<<(CAN_TX2R_CANTX2_26_POS))
#define CAN_TX2R_CANTX2_27              ((uint32_t)1<<(CAN_TX2R_CANTX2_27_POS))
#define CAN_TX2R_CANTX2_28              ((uint32_t)1<<(CAN_TX2R_CANTX2_28_POS))
#define CAN_TX2R_CANTX2_29              ((uint32_t)1<<(CAN_TX2R_CANTX2_29_POS))
#define CAN_TX2R_CANTX2_30              ((uint32_t)1<<(CAN_TX2R_CANTX2_30_POS))
#define CAN_TX2R_CANTX2_31              ((uint32_t)1<<(CAN_TX2R_CANTX2_31_POS))

#endif // KF32F_Periph_can
/* ���������������� (CAN)������� */


/* ----------------------------------------------------------------------------
   -- ��Դ����ģ�� (PM)
   ---------------------------------------------------------------------------- */

/* PM - ����Ĵ����ڴ�ṹ */
typedef struct PM_MemMap {
    volatile       uint32_t CTL0;       /* PM ����ģʽ���ƼĴ���0, ƫ��;0x00 */
    volatile       uint32_t CTL1;       /* PM ����ģʽ���ƼĴ���1, ƫ��;0x04 */
    volatile const uint32_t STA0;       /* PM ����ģʽ״̬�Ĵ���0, ƫ��;0x08 */
    volatile const uint32_t STA1;       /* PM ����ģʽ״̬�Ĵ���1, ƫ��;0x0C */
    volatile       uint32_t STAC;       /* PM ����ģʽ״̬����Ĵ���, ƫ��;0x10 */
    volatile       uint32_t CTL2;       /* PM ����ģʽ���ƼĴ���2, ƫ��;0x14 */
    volatile       uint32_t CAL0;       /* PM У׼�Ĵ���0, ƫ��;0X18 */
    volatile       uint32_t CAL1;       /* PM У׼�Ĵ���1, ƫ��;0X1C */
    volatile       uint32_t CAL2;       /* PM У׼�Ĵ���1, ƫ��;0X20 */
}PM_SFRmap;

/* ----------------------------------------------------------------------------
   -- PM - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* PM - �Ĵ�����ڵ�ַ */
#define PM_ADDR                         ((uint32_t)0x40001580)
#define PM_SFR                          ((PM_SFRmap *) PM_ADDR)

/* PM - �Ĵ������ */
#define PM_CTL0                         (PM_SFR->CTL0)
#define PM_CTL1                         (PM_SFR->CTL1)
#define PM_STA0                         (PM_SFR->STA0)
#define PM_STA1                         (PM_SFR->STA1)
#define PM_STAC                         (PM_SFR->STAC)
#define PM_CTL2                         (PM_SFR->CTL2)
#define PM_CAL0                         (PM_SFR->CAL0)
#define PM_CAL1                         (PM_SFR->CAL1)
#define PM_CAL2                         (PM_SFR->CAL2)

/* PM_CTL0 λ�� */
#define PM_CTL0_LPMS0_POS               (0)
#define PM_CTL0_LPMS1_POS               (1)
#define PM_CTL0_LPMS2_POS               (2)
#define PM_CTL0_MEMSEL_POS              (3)
#define PM_CTL0_NRSTEN_POS              (4)
#define PM_CTL0_LPREN_POS               (5)
#define PM_CTL0_OCAL0LOCK_POS           (6)
#define PM_CTL0_BKPWR_POS               (7)
#define PM_CTL0_HSIEN_POS               (8)
#define PM_CTL0_PDMDELAY0_POS           (9)
#define PM_CTL0_PDMDELAY1_POS           (10)
#define PM_CTL0_PDMSEL_POS              (11)
#define PM_CTL0_PHERIIOSEL_POS          (13)
#define PM_CTL0_BKPPORDELAYSEL_POS      (14)
#define PM_CTL0_PORDELAYSEL_POS         (15)
#define PM_CTL0_IWDTRMSEL_POS           (16)
#define PM_CTL0_LSECONF_POS             (17)
#define PM_CTL0_LP4MEN_POS              (18)
#define PM_CTL0_LPSRAMSEL_POS            (19)
//#define PM_CTL0_SRAMASEL_POS            (20)
#define PM_CTL0_IWDTCLR_POS             (21)
#define PM_CTL0_BKPREGCLR_POS           (22)
#define PM_CTL0_LPBGON_POS              (23)
#define PM_CTL0_LDO18EN_POS             (24)
#define PM_CTL0_MRBGEN_POS              (25)
#define PM_CTL0_LSEEXEN_POS             (27)
#define PM_CTL0_LSEEN_POS               (28)
#define PM_CTL0_LSIEN_POS               (29)
#define PM_CTL0_VDDPORON_POS            (30)
#define PM_CTL0_IOLATCH_POS             (31)
#define PM_CTL0_LPMS                    ((uint32_t)7<<(PM_CTL0_LPMS0_POS))
#define PM_CTL0_LPMS0                   ((uint32_t)1<<(PM_CTL0_LPMS0_POS))
#define PM_CTL0_LPMS1                   ((uint32_t)1<<(PM_CTL0_LPMS1_POS))
#define PM_CTL0_LPMS2                   ((uint32_t)1<<(PM_CTL0_LPMS2_POS))
#define PM_CTL0_MEMSEL                  ((uint32_t)1<<(PM_CTL0_MEMSEL_POS))
#define PM_CTL0_NRSTEN                  ((uint32_t)1<<(PM_CTL0_NRSTEN_POS))
#define PM_CTL0_LPREN                   ((uint32_t)1<<(PM_CTL0_LPREN_POS))
#define PM_CTL0_OCAL0LOCK               ((uint32_t)1<<(PM_CTL0_OCAL0LOCK_POS))
#define PM_CTL0_BKPWR                   ((uint32_t)1<<(PM_CTL0_BKPWR_POS))
#define PM_CTL0_HSIEN                   ((uint32_t)1<<(PM_CTL0_HSIEN_POS))
#define PM_CTL0_PDMDELAY                ((uint32_t)3<<(PM_CTL0_PDMDELAY0_POS))
#define PM_CTL0_PDMDELAY0               ((uint32_t)1<<(PM_CTL0_PDMDELAY0_POS))
#define PM_CTL0_PDMDELAY1               ((uint32_t)1<<(PM_CTL0_PDMDELAY1_POS))
#define PM_CTL0_PDMSEL                  ((uint32_t)1<<(PM_CTL0_PDMSEL_POS))
#define PM_CTL0_PHERIIOSEL              ((uint32_t)1<<(PM_CTL0_PHERIIOSEL_POS))
#define PM_CTL0_PORDELAYSEL             ((uint32_t)1<<(PM_CTL0_PORDELAYSEL_POS))
#define PM_CTL0_BKPPORDELAYSEL          ((uint32_t)1<<(PM_CTL0_BKPPORDELAYSEL_POS))
#define PM_CTL0_IWDTRMSEL               ((uint32_t)1<<(PM_CTL0_IWDTRMSEL_POS))
#define PM_CTL0_LSECONF                 ((uint32_t)1<<(PM_CTL0_LSECONF_POS))
#define PM_CTL0_LP4MEN                  ((uint32_t)1<<(PM_CTL0_LP4MEN_POS))
#define PM_CTL0_LPSRAMSEL               ((uint32_t)1<<(PM_CTL0_LPSRAMSEL_POS))
//#define PM_CTL0_SRAMASEL                ((uint32_t)1<<(PM_CTL0_SRAMASEL_POS))
#define PM_CTL0_IWDTCLR                 ((uint32_t)1<<(PM_CTL0_IWDTCLR_POS))
#define PM_CTL0_BKPREGCLR               ((uint32_t)1<<(PM_CTL0_BKPREGCLR_POS))
#define PM_CTL0_LPBGON                  ((uint32_t)1<<(PM_CTL0_LPBGON_POS))
#define PM_CTL0_LDO18EN                 ((uint32_t)1<<(PM_CTL0_LDO18EN_POS))
#define PM_CTL0_MRBGEN                  ((uint32_t)1<<(PM_CTL0_MRBGEN_POS))
#define PM_CTL0_LSEEXEN                 ((uint32_t)1<<(PM_CTL0_LSEEXEN_POS))
#define PM_CTL0_LSEEN                   ((uint32_t)1<<(PM_CTL0_LSEEN_POS))
#define PM_CTL0_LSIEN                   ((uint32_t)1<<(PM_CTL0_LSIEN_POS))
#define PM_CTL0_VDDPORON                ((uint32_t)1<<(PM_CTL0_VDDPORON_POS))
#define PM_CTL0_IOLATCH                 ((uint32_t)1<<(PM_CTL0_IOLATCH_POS))

/* PM_CTL1 λ�� */
#define PM_CTL1_PVDEN_POS               (0)
#define PM_CTL1_PVDS0_POS               (2)
#define PM_CTL1_PVDS1_POS               (3)
#define PM_CTL1_PVDS2_POS               (4)
#define PM_CTL1_VREFEN_POS              (5)
#define PM_CTL1_VREFSEL0_POS            (6)
#define PM_CTL1_VREFSEL1_POS            (7)
#define PM_CTL1_BATBORSEL0_POS          (12)
#define PM_CTL1_BATBORSEL1_POS          (13)
#define PM_CTL1_BATBORSEL2_POS          (14)
#define PM_CTL1_BATBOREN_POS            (15)
#define PM_CTL1_PLL2LDOOE_POS           (16)
#define PM_CTL1_PLL1LDOOE_POS           (17)
#define PM_CTL1_PLL0LDOOE_POS           (18)
#define PM_CTL1_PLL2OE_POS              (19)
#define PM_CTL1_PLL1OE_POS              (20)
#define PM_CTL1_PLL0OE_POS              (21)
#define PM_CTL1_BUFCLKDIV0_POS          (22)
#define PM_CTL1_BUFCLKDIV1_POS          (23)
#define PM_CTL1_BUFCLKDIV2_POS          (24)
#define PM_CTL1_BUFCLKEN_POS            (25)
#define PM_CTL1_INTBUFEN_POS            (26)
#define PM_CTL1_PI80E_POS               (27)
#define PM_CTL1_TSOE_POS                (28)
#define PM_CTL1_TSEN_POS                (29)
#define PM_CTL1_LPBOREN_POS             (30)
#define PM_CTL1_BOREN_POS               (31)
#define PM_CTL1_PVDEN                   ((uint32_t)1<<(PM_CTL1_PVDEN_POS))
#define PM_CTL1_PVDS                    ((uint32_t)7<<(PM_CTL1_PVDS0_POS))
#define PM_CTL1_PVDS0                   ((uint32_t)1<<(PM_CTL1_PVDS0_POS))
#define PM_CTL1_PVDS1                   ((uint32_t)1<<(PM_CTL1_PVDS1_POS))
#define PM_CTL1_PVDS2                   ((uint32_t)1<<(PM_CTL1_PVDS2_POS))
#define PM_CTL1_VREFEN                  ((uint32_t)1<<(PM_CTL1_VREFEN_POS))
#define PM_CTL1_VREFSEL                 ((uint32_t)0x3<<(PM_CTL1_VREFSEL0_POS))
#define PM_CTL1_VREFSEL0                ((uint32_t)1<<(PM_CTL1_VREFSEL0_POS))
#define PM_CTL1_VREFSEL1                ((uint32_t)1<<(PM_CTL1_VREFSEL1_POS))
#define PM_CTL1_BATBORSEL               ((uint32_t)7<<(PM_CTL1_BATBORSEL0_POS))
#define PM_CTL1_BATBORSEL0              ((uint32_t)1<<(PM_CTL1_BATBORSEL0_POS))
#define PM_CTL1_BATBORSEL1              ((uint32_t)1<<(PM_CTL1_BATBORSEL1_POS))
#define PM_CTL1_BATBORSEL2              ((uint32_t)1<<(PM_CTL1_BATBORSEL2_POS))
#define PM_CTL1_BATBOREN                ((uint32_t)1<<(PM_CTL1_BATBOREN_POS))
#define PM_CTL1_PLL2LDOOE               ((uint32_t)1<<(PM_CTL1_PLL2LDOOE_POS))
#define PM_CTL1_PLL1LDOOE               ((uint32_t)1<<(PM_CTL1_PLL1LDOOE_POS))
#define PM_CTL1_PLL0LDOOE               ((uint32_t)1<<(PM_CTL1_PLL0LDOOE_POS))
#define PM_CTL1_PLL2OE                  ((uint32_t)1<<(PM_CTL1_PLL2OE_POS))
#define PM_CTL1_PLL1OE                  ((uint32_t)1<<(PM_CTL1_PLL1OE_POS))
#define PM_CTL1_PLL0OE                  ((uint32_t)1<<(PM_CTL1_PLL0OE_POS))
#define PM_CTL1_BUFCLKDIV               ((uint32_t)7<<(PM_CTL1_BUFCLKDIV0_POS))
#define PM_CTL1_BUFCLKDIV0              ((uint32_t)1<<(PM_CTL1_BUFCLKDIV0_POS))
#define PM_CTL1_BUFCLKDIV1              ((uint32_t)1<<(PM_CTL1_BUFCLKDIV1_POS))
#define PM_CTL1_BUFCLKDIV2              ((uint32_t)1<<(PM_CTL1_BUFCLKDIV2_POS))
#define PM_CTL1_BUFCLKEN                ((uint32_t)1<<(PM_CTL1_BUFCLKEN_POS))
#define PM_CTL1_INTBUFEN                ((uint32_t)1<<(PM_CTL1_INTBUFEN_POS))
#define PM_CTL1_PI80E                   ((uint32_t)1<<(PM_CTL1_PI80E_POS))
#define PM_CTL1_TSOE                    ((uint32_t)1<<(PM_CTL1_TSOE_POS))
#define PM_CTL1_TSEN                    ((uint32_t)1<<(PM_CTL1_TSEN_POS))
#define PM_CTL1_LPBOREN                 ((uint32_t)1<<(PM_CTL1_LPBOREN_POS))
#define PM_CTL1_BOREN                   ((uint32_t)1<<(PM_CTL1_BOREN_POS))

/* PM_STA0 λ�� */
#define PM_STA0_LPRSTA_POS              (0)
#define PM_STA0_LPRUNF_POS              (1)
#define PM_STA0_WSRSTF_POS              (25)
#define PM_STA0_BORF_POS                (26)
#define PM_STA0_PORF_POS                (27)
#define PM_STA0_WKPPINF_POS             (28)
#define PM_STA0_RTCALRF_POS             (29)
#define PM_STA0_IWDTF_POS               (30)
#define PM_STA0_RSTFC_POS               (31)
#define PM_STA0_LPRSTA                  ((uint32_t)1<<(PM_STA0_LPRSTA_POS))
#define PM_STA0_LPRUNF                  ((uint32_t)1<<(PM_STA0_LPRUNF_POS))
#define PM_STA0_WSRSTF                  ((uint32_t)1<<(PM_STA0_WSRSTF_POS))
#define PM_STA0_BORF                    ((uint32_t)1<<(PM_STA0_BORF_POS))
#define PM_STA0_PORF                    ((uint32_t)1<<(PM_STA0_PORF_POS))
#define PM_STA0_WKPPINF                 ((uint32_t)1<<(PM_STA0_WKPPINF_POS))
#define PM_STA0_RTCALRF                 ((uint32_t)1<<(PM_STA0_RTCALRF_POS))
#define PM_STA0_IWDTF                   ((uint32_t)1<<(PM_STA0_IWDTF_POS))
#define PM_STA0_RSTFC                   ((uint32_t)1<<(PM_STA0_RSTFC_POS))

/* PM_STA1 λ�� */
#define PM_STA1_PVDSTA_POS              (0)
#define PM_STA1_WKP1STA_POS             (27)
#define PM_STA1_WKP2STA_POS             (28)
#define PM_STA1_WKP3STA_POS             (29)
#define PM_STA1_WKP4STA_POS             (30)
#define PM_STA1_WKP5STA_POS             (31)
#define PM_STA1_PVDSTA                  ((uint32_t)1<<(PM_STA1_PVDSTA_POS))
#define PM_STA1_WKP1STA                 ((uint32_t)1<<(PM_STA1_WKP1STA_POS))
#define PM_STA1_WKP2STA                 ((uint32_t)1<<(PM_STA1_WKP2STA_POS))
#define PM_STA1_WKP3STA                 ((uint32_t)1<<(PM_STA1_WKP3STA_POS))
#define PM_STA1_WKP4STA                 ((uint32_t)1<<(PM_STA1_WKP4STA_POS))
#define PM_STA1_WKP5STA                 ((uint32_t)1<<(PM_STA1_WKP5STA_POS))

/* PM_STAC λ�� */
#define PM_STAC_WKP1SC_POS              (27)
#define PM_STAC_WKP2SC_POS              (28)
#define PM_STAC_WKP3SC_POS              (29)
#define PM_STAC_WKP4SC_POS              (30)
#define PM_STAC_WKP5SC_POS              (31)
#define PM_STAC_WKP1SC                  ((uint32_t)1<<(PM_STAC_WKP1SC_POS))
#define PM_STAC_WKP2SC                  ((uint32_t)1<<(PM_STAC_WKP2SC_POS))
#define PM_STAC_WKP3SC                  ((uint32_t)1<<(PM_STAC_WKP3SC_POS))
#define PM_STAC_WKP4SC                  ((uint32_t)1<<(PM_STAC_WKP4SC_POS))
#define PM_STAC_WKP5SC                  ((uint32_t)1<<(PM_STAC_WKP5SC_POS))

/* PM_CTL2 λ�� */
#define PM_CTL2_CAN0LPEN_POS            (0)
#define PM_CTL2_CCP0LPEN_POS            (1)
#define PM_CTL2_LCDLPEN_POS             (2)
#define PM_CTL2_USART0LPEN_POS          (3)
#define PM_CTL2_CAN0CLKLPEN_POS         (4)
#define PM_CTL2_CCP0CLKLPEN_POS         (5)
#define PM_CTL2_LCDCLKLPEN_POS          (6)
#define PM_CTL2_USART0CLKLPEN_POS       (7)
#define PM_CTL2_POR18SHD_POS            (8)
#define PM_CTL2_VF12INF0_POS            (9)
#define PM_CTL2_VF12INF1_POS            (10)
#define PM_CTL2_VF12EN_POS              (11)
#define PM_CTL2_RTCTSEL0_POS            (12)
#define PM_CTL2_RTCTSEL1_POS            (13)
#define PM_CTL2_RTCTPEN_POS             (14)
#define PM_CTL2_RTCTWEN_POS             (15)
#define PM_CTL2_VBKPORSHD_POS           (20)
#define PM_CTL2_VBKPOREN_POS            (21)
#define PM_CTL2_WKP1P_POS               (22)
#define PM_CTL2_WKP2P_POS               (23)
#define PM_CTL2_WKP3P_POS               (24)
#define PM_CTL2_WKP4P_POS               (25)
#define PM_CTL2_WKP5P_POS               (26)
#define PM_CTL2_WKP1EN_POS              (27)
#define PM_CTL2_WKP2EN_POS              (28)
#define PM_CTL2_WKP3EN_POS              (29)
#define PM_CTL2_WKP4EN_POS              (30)
#define PM_CTL2_WKP5EN_POS              (31)
#define PM_CTL2_CAN0LPEN                ((uint32_t)1<<(PM_CTL2_CAN0LPEN_POS))
#define PM_CTL2_CCP0LPEN                ((uint32_t)1<<(PM_CTL2_CCP0LPEN_POS))
#define PM_CTL2_LCDLPEN                 ((uint32_t)1<<(PM_CTL2_LCDLPEN_POS))
#define PM_CTL2_USART0LPEN              ((uint32_t)1<<(PM_CTL2_USART0LPEN_POS))
#define PM_CTL2_CAN0CLKLPEN             ((uint32_t)1<<(PM_CTL2_CAN0CLKLPEN_POS))
#define PM_CTL2_CCP0CLKLPEN             ((uint32_t)1<<(PM_CTL2_CCP0CLKLPEN_POS))
#define PM_CTL2_LCDCLKLPEN              ((uint32_t)1<<(PM_CTL2_LCDCLKLPEN_POS))
#define PM_CTL2_USART0CLKLPEN           ((uint32_t)1<<(PM_CTL2_USART0CLKLPEN_POS))
#define PM_CTL2_POR18SHD                ((uint32_t)1<<(PM_CTL2_POR18SHD_POS))
#define PM_CTL2_VF12INF0                ((uint32_t)1<<(PM_CTL2_VF12INF0_POS))
#define PM_CTL2_VF12INF1                ((uint32_t)1<<(PM_CTL2_VF12INF1_POS))
#define PM_CTL2_VF12EN                  ((uint32_t)1<<(PM_CTL2_VF12EN_POS))
#define PM_CTL2_RTCTSEL0                ((uint32_t)1<<(PM_CTL2_RTCTSEL0_POS))
#define PM_CTL2_RTCTSEL1                ((uint32_t)1<<(PM_CTL2_RTCTSEL1_POS))
#define PM_CTL2_RTCTPEN                 ((uint32_t)1<<(PM_CTL2_RTCTPEN_POS))
#define PM_CTL2_RTCTWEN                 ((uint32_t)1<<(PM_CTL2_RTCTWEN_POS))
#define PM_CTL2_VBKPORSHD               ((uint32_t)1<<(PM_CTL2_VBKPORSHD_POS))
#define PM_CTL2_VBKPOREN                ((uint32_t)1<<(PM_CTL2_VBKPOREN_POS))
#define PM_CTL2_WKP1P                   ((uint32_t)1<<(PM_CTL2_WKP1P_POS))
#define PM_CTL2_WKP2P                   ((uint32_t)1<<(PM_CTL2_WKP2P_POS))
#define PM_CTL2_WKP3P                   ((uint32_t)1<<(PM_CTL2_WKP3P_POS))
#define PM_CTL2_WKP4P                   ((uint32_t)1<<(PM_CTL2_WKP4P_POS))
#define PM_CTL2_WKP5P                   ((uint32_t)1<<(PM_CTL2_WKP5P_POS))
#define PM_CTL2_WKP1EN                  ((uint32_t)1<<(PM_CTL2_WKP1EN_POS))
#define PM_CTL2_WKP2EN                  ((uint32_t)1<<(PM_CTL2_WKP2EN_POS))
#define PM_CTL2_WKP3EN                  ((uint32_t)1<<(PM_CTL2_WKP3EN_POS))
#define PM_CTL2_WKP4EN                  ((uint32_t)1<<(PM_CTL2_WKP4EN_POS))
#define PM_CTL2_WKP5EN                  ((uint32_t)1<<(PM_CTL2_WKP5EN_POS))

/* PM_CAL0 λ�� */
#define PM_CAL0_BGTRIMFLLDO0_POS        (0)
#define PM_CAL0_BGTRIMFLLDO1_POS        (1)
#define PM_CAL0_BGTRIMFLLDO2_POS        (2)
#define PM_CAL0_BGTRIMFLLDO3_POS        (3)
#define PM_CAL0_BGTRIMMRLDO0_POS        (4)
#define PM_CAL0_BGTRIMMRLDO1_POS        (5)
#define PM_CAL0_BGTRIMMRLDO2_POS        (6)
#define PM_CAL0_BGTRIMMRLDO3_POS        (7)
#define PM_CAL0_BGTRIMREBUF0_POS        (8)
#define PM_CAL0_BGTRIMREBUF1_POS        (9)
#define PM_CAL0_BGTRIMREBUF2_POS        (10)
#define PM_CAL0_BGTRIMREBUF3_POS        (11)
#define PM_CAL0_BGTRIMREBUF4_POS        (12)
#define PM_CAL0_MRHVTRIM0_POS           (13)
#define PM_CAL0_MRHVTRIM1_POS           (14)
#define PM_CAL0_MRHVEN_POS              (15)
#define PM_CAL0_MRTRIM0_POS             (16)
#define PM_CAL0_MRTRIM1_POS             (17)
#define PM_CAL0_BORSEL0_POS             (20)
#define PM_CAL0_BORSEL1_POS             (21)
#define PM_CAL0_ZEROTISTRIM0_POS        (24)
#define PM_CAL0_ZEROTISTRIM1_POS        (25)
#define PM_CAL0_LPRSEL_POS              (29)
#define PM_CAL0_MRBGSEL_POS             (30)
#define PM_CAL0_LDO18SEL_POS            (31)
#define PM_CAL0_BGTRIMFLLDO             ((uint32_t)0xF<<(PM_CAL0_BGTRIMFLLDO0_POS))
#define PM_CAL0_BGTRIMFLLDO0            ((uint32_t)1<<(PM_CAL0_BGTRIMFLLDO0_POS))
#define PM_CAL0_BGTRIMFLLDO1            ((uint32_t)1<<(PM_CAL0_BGTRIMFLLDO1_POS))
#define PM_CAL0_BGTRIMFLLDO2            ((uint32_t)1<<(PM_CAL0_BGTRIMFLLDO2_POS))
#define PM_CAL0_BGTRIMFLLDO3            ((uint32_t)1<<(PM_CAL0_BGTRIMFLLDO3_POS))
#define PM_CAL0_BGTRIMMRLDO             ((uint32_t)0xF<<(PM_CAL0_BGTRIMMRLDO0_POS))
#define PM_CAL0_BGTRIMMRLDO0            ((uint32_t)1<<(PM_CAL0_BGTRIMMRLDO0_POS))
#define PM_CAL0_BGTRIMMRLDO1            ((uint32_t)1<<(PM_CAL0_BGTRIMMRLDO1_POS))
#define PM_CAL0_BGTRIMMRLDO2            ((uint32_t)1<<(PM_CAL0_BGTRIMMRLDO2_POS))
#define PM_CAL0_BGTRIMMRLDO3            ((uint32_t)1<<(PM_CAL0_BGTRIMMRLDO3_POS))
#define PM_CAL0_BGTRIMREBUF             ((uint32_t)0x1F<<(PM_CAL0_BGTRIMREBUF0_POS))
#define PM_CAL0_BGTRIMREBUF0            ((uint32_t)1<<(PM_CAL0_BGTRIMREBUF0_POS))
#define PM_CAL0_BGTRIMREBUF1            ((uint32_t)1<<(PM_CAL0_BGTRIMREBUF1_POS))
#define PM_CAL0_BGTRIMREBUF2            ((uint32_t)1<<(PM_CAL0_BGTRIMREBUF2_POS))
#define PM_CAL0_BGTRIMREBUF3            ((uint32_t)1<<(PM_CAL0_BGTRIMREBUF3_POS))
#define PM_CAL0_BGTRIMREBUF4            ((uint32_t)1<<(PM_CAL0_BGTRIMREBUF4_POS))
#define PM_CAL0_MRHVTRIM                ((uint32_t)3<<(PM_CAL0_MRHVTRIM0_POS))
#define PM_CAL0_MRHVTRIM0               ((uint32_t)1<<(PM_CAL0_MRHVTRIM0_POS))
#define PM_CAL0_MRHVTRIM1               ((uint32_t)1<<(PM_CAL0_MRHVTRIM1_POS))
#define PM_CAL0_MRHVEN                  ((uint32_t)1<<(PM_CAL0_MRHVEN_POS))
#define PM_CAL0_MRTRIM                  ((uint32_t)3<<(PM_CAL0_MRTRIM0_POS))
#define PM_CAL0_MRTRIM0                 ((uint32_t)1<<(PM_CAL0_MRTRIM0_POS))
#define PM_CAL0_MRTRIM1                 ((uint32_t)1<<(PM_CAL0_MRTRIM1_POS))
#define PM_CAL0_BORSEL                  ((uint32_t)3<<(PM_CAL0_BORSEL0_POS))
#define PM_CAL0_BORSEL0                 ((uint32_t)1<<(PM_CAL0_BORSEL0_POS))
#define PM_CAL0_BORSEL1                 ((uint32_t)1<<(PM_CAL0_BORSEL1_POS))
#define PM_CAL0_ZEROTISTRIM             ((uint32_t)3<<(PM_CAL0_ZEROTISTRIM0_POS))
#define PM_CAL0_ZEROTISTRIM0            ((uint32_t)1<<(PM_CAL0_ZEROTISTRIM0_POS))
#define PM_CAL0_ZEROTISTRIM1            ((uint32_t)1<<(PM_CAL0_ZEROTISTRIM1_POS))
#define PM_CAL0_LPRSEL                  ((uint32_t)1<<(PM_CAL0_LPRSEL_POS))
#define PM_CAL0_MRBGSEL                 ((uint32_t)1<<(PM_CAL0_MRBGSEL_POS))
#define PM_CAL0_LDO18SEL                ((uint32_t)1<<(PM_CAL0_LDO18SEL_POS))

/* PM_CAL1 λ�� */
#define PM_CAL1_LSETRIMNBIAS0_POS       (0)
#define PM_CAL1_LSETRIMNBIAS1_POS       (1)
#define PM_CAL1_LSETRIMBIAS0_POS        (4)
#define PM_CAL1_LSETRIMBIAS1_POS        (5)
#define PM_CAL1_LSETRIMBIAS2_POS        (6)
#define PM_CAL1_LSETRIMBIAS3_POS        (7)
#define PM_CAL1_HSESEL_POS              (15)
#define PM_CAL1_LPBGTRIMPUMP0_POS       (16)
#define PM_CAL1_LPBGTRIMPUMP1_POS       (17)
#define PM_CAL1_LPBGTRIMPUMP2_POS       (18)
#define PM_CAL1_LSESEL_POS              (19)
#define PM_CAL1_LPTRIMBIAS0_POS         (20)
#define PM_CAL1_LPTRIMBIAS1_POS         (21)
#define PM_CAL1_LPTRIMBIAS2_POS         (22)
#define PM_CAL1_SPCPUR_POS         		(23)
#define PM_CAL1_LSITRIMCAP0_POS         (24)
#define PM_CAL1_LSITRIMCAP1_POS         (25)
#define PM_CAL1_LSITRIMCAP2_POS         (26)
#define PM_CAL1_LSITRIMCAP3_POS         (27)
#define PM_CAL1_LSITRIMCAP4_POS         (28)
#define PM_CAL1_LSITRIMBIAS0_POS        (29)
#define PM_CAL1_LSITRIMBIAS1_POS        (30)
#define PM_CAL1_LSITRIMBIAS2_POS        (31)
#define PM_CAL1_LSETRIMNBIAS            ((uint32_t)3<<(PM_CAL1_LSETRIMNBIAS0_POS))
#define PM_CAL1_LSETRIMNBIAS0           ((uint32_t)1<<(PM_CAL1_LSETRIMNBIAS0_POS))
#define PM_CAL1_LSETRIMNBIAS1           ((uint32_t)1<<(PM_CAL1_LSETRIMNBIAS1_POS))
#define PM_CAL1_LSETRIMBIAS             ((uint32_t)0xF<<(PM_CAL1_LSETRIMBIAS0_POS))
#define PM_CAL1_LSETRIMBIAS0            ((uint32_t)1<<(PM_CAL1_LSETRIMBIAS0_POS))
#define PM_CAL1_LSETRIMBIAS1            ((uint32_t)1<<(PM_CAL1_LSETRIMBIAS1_POS))
#define PM_CAL1_LSETRIMBIAS2            ((uint32_t)1<<(PM_CAL1_LSETRIMBIAS2_POS))
#define PM_CAL1_LSETRIMBIAS3            ((uint32_t)1<<(PM_CAL1_LSETRIMBIAS3_POS))
#define PM_CAL1_HSESE             		((uint32_t)1<<(PM_CAL1_HSESEL_POS))
#define PM_CAL1_LPBGTRIMPUMP            ((uint32_t)0x7<<(PM_CAL1_LPBGTRIMPUMP0_POS))
#define PM_CAL1_LPBGTRIMPUMP0           ((uint32_t)1<<(PM_CAL1_LPBGTRIMPUMP0_POS))
#define PM_CAL1_LPBGTRIMPUMP1           ((uint32_t)1<<(PM_CAL1_LPBGTRIMPUMP1_POS))
#define PM_CAL1_LPBGTRIMPUMP2           ((uint32_t)1<<(PM_CAL1_LPBGTRIMPUMP2_POS))
#define PM_CAL1_LSESEL             		((uint32_t)1<<(PM_CAL1_LSESEL_POS))
#define PM_CAL1_LPTRIMBIAS              ((uint32_t)0x7<<(PM_CAL1_LPTRIMBIAS0_POS))
#define PM_CAL1_LPTRIMBIAS0             ((uint32_t)1<<(PM_CAL1_LPTRIMBIAS0_POS))
#define PM_CAL1_LPTRIMBIAS1             ((uint32_t)1<<(PM_CAL1_LPTRIMBIAS1_POS))
#define PM_CAL1_LPTRIMBIAS2             ((uint32_t)1<<(PM_CAL1_LPTRIMBIAS2_POS))
#define PM_CAL1_SPCPUR                  ((uint32_t)1<<(PM_CAL1_SPCPUR_POS))
#define PM_CAL1_LSITRIMCAP              ((uint32_t)0x1F<<(PM_CAL1_LSITRIMCAP0_POS))
#define PM_CAL1_LSITRIMCAP0             ((uint32_t)1<<(PM_CAL1_LSITRIMCAP0_POS))
#define PM_CAL1_LSITRIMCAP1             ((uint32_t)1<<(PM_CAL1_LSITRIMCAP1_POS))
#define PM_CAL1_LSITRIMCAP2             ((uint32_t)1<<(PM_CAL1_LSITRIMCAP2_POS))
#define PM_CAL1_LSITRIMCAP3             ((uint32_t)1<<(PM_CAL1_LSITRIMCAP3_POS))
#define PM_CAL1_LSITRIMCAP4             ((uint32_t)1<<(PM_CAL1_LSITRIMCAP4_POS))
#define PM_CAL1_LSITRIMBIAS             ((uint32_t)7<<(PM_CAL1_LSITRIMBIAS0_POS))
#define PM_CAL1_LSITRIMBIAS0            ((uint32_t)1<<(PM_CAL1_LSITRIMBIAS0_POS))
#define PM_CAL1_LSITRIMBIAS1            ((uint32_t)1<<(PM_CAL1_LSITRIMBIAS1_POS))
#define PM_CAL1_LSITRIMBIAS2            ((uint32_t)1<<(PM_CAL1_LSITRIMBIAS2_POS))

/* PM_CAL2 λ�� */
#define PM_CAL1_MRDEL0_POS              (0)
#define PM_CAL1_MRDEL1_POS              (1)
#define PM_CAL1_VCOREDEL0_POS           (2)
#define PM_CAL1_VCOREDEL1_POS           (3)
#define PM_CAL1_LPRDEL0_POS             (4)
#define PM_CAL1_LPRDEL1_POS             (5)
#define PM_CAL1_MRDEL                   ((uint32_t)3<<(PM_CAL1_MRDEL0_POS))
#define PM_CAL1_MRDEL0                  ((uint32_t)1<<(PM_CAL1_MRDEL0_POS))
#define PM_CAL1_MRDEL1                  ((uint32_t)1<<(PM_CAL1_MRDEL1_POS))
#define PM_CAL1_VCOREDEL                ((uint32_t)3<<(PM_CAL1_VCOREDEL0_POS))
#define PM_CAL1_VCOREDEL0               ((uint32_t)1<<(PM_CAL1_VCOREDEL0_POS))
#define PM_CAL1_VCOREDEL1               ((uint32_t)1<<(PM_CAL1_VCOREDEL1_POS))
#define PM_CAL1_LPRDEL                  ((uint32_t)3<<(PM_CAL1_LPRDEL0_POS))
#define PM_CAL1_LPRDEL0                 ((uint32_t)1<<(PM_CAL1_LPRDEL0_POS))
#define PM_CAL1_LPRDEL1                 ((uint32_t)1<<(PM_CAL1_LPRDEL1_POS))
/* ��Դ����ģ�� (PM)������� */


/* ----------------------------------------------------------------------------
   -- ������ (BKP)
   ---------------------------------------------------------------------------- */

/* BKP - ����Ĵ����ڴ�ṹ */
typedef struct BKP_MemMap {
    volatile uint32_t CTL;              /* ��������ƼĴ���, ƫ��:0x00 */
    volatile uint32_t INT;              /* �������жϿ��ƼĴ���, ƫ��:0x04 */
             uint32_t RESERVED[14];     /* ������ַ, ƫ��:0x08 */
    volatile uint32_t DATA[32];         /* ���������ݼĴ���(0~31), ƫ��:0x40 */
}BKP_SFRmap;

/* ----------------------------------------------------------------------------
   -- BKP - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
/* BKP - �Ĵ�����ڵ�ַ */
#define BKP_ADDR                        ((uint32_t)0x40001400)
#define BKP_SFR                         ((BKP_SFRmap *) BKP_ADDR)

/* BKP - �Ĵ������ */
#define BKP_CTL                         (BKP_SFR->CTL)
#define BKP_INT                         (BKP_SFR->INT)
#define BKP_DATA0                       (BKP_SFR->DATA[0])
#define BKP_DATA1                       (BKP_SFR->DATA[1])
#define BKP_DATA2                       (BKP_SFR->DATA[2])
#define BKP_DATA3                       (BKP_SFR->DATA[3])
#define BKP_DATA4                       (BKP_SFR->DATA[4])
#define BKP_DATA5                       (BKP_SFR->DATA[5])
#define BKP_DATA6                       (BKP_SFR->DATA[6])
#define BKP_DATA7                       (BKP_SFR->DATA[7])
#define BKP_DATA8                       (BKP_SFR->DATA[8])
#define BKP_DATA9                       (BKP_SFR->DATA[9])
#define BKP_DATA10                      (BKP_SFR->DATA[10])
#define BKP_DATA11                      (BKP_SFR->DATA[11])
#define BKP_DATA12                      (BKP_SFR->DATA[12])
#define BKP_DATA13                      (BKP_SFR->DATA[13])
#define BKP_DATA14                      (BKP_SFR->DATA[14])
#define BKP_DATA15                      (BKP_SFR->DATA[15])
#define BKP_DATA16                      (BKP_SFR->DATA[16])
#define BKP_DATA17                      (BKP_SFR->DATA[17])
#define BKP_DATA18                      (BKP_SFR->DATA[18])
#define BKP_DATA19                      (BKP_SFR->DATA[19])
#define BKP_DATA20                      (BKP_SFR->DATA[20])
#define BKP_DATA21                      (BKP_SFR->DATA[21])
#define BKP_DATA22                      (BKP_SFR->DATA[22])
#define BKP_DATA23                      (BKP_SFR->DATA[23])
#define BKP_DATA24                      (BKP_SFR->DATA[24])
#define BKP_DATA25                      (BKP_SFR->DATA[25])
#define BKP_DATA26                      (BKP_SFR->DATA[26])
#define BKP_DATA27                      (BKP_SFR->DATA[27])
#define BKP_DATA28                      (BKP_SFR->DATA[28])
#define BKP_DATA29                      (BKP_SFR->DATA[29])
#define BKP_DATA30                      (BKP_SFR->DATA[30])
#define BKP_DATA31                      (BKP_SFR->DATA[31])

/* BKP_CTL λ�� */
#define BKP_CTL_EXTHFBYP_POS            (1)
#define BKP_CTL_EXTLFBYP_POS            (2)
#define BKP_CTL_RTCCLKS0_POS            (8)
#define BKP_CTL_RTCCLKS1_POS            (9)
#define BKP_CTL_TAMP1EN_POS             (16)
#define BKP_CTL_TAMP2EN_POS             (17)
#define BKP_CTL_TAMP3EN_POS             (18)
#define BKP_CTL_TAMP1LVL_POS            (20)
#define BKP_CTL_TAMP2LVL_POS            (21)
#define BKP_CTL_TAMP3LVL_POS            (22)
#define BKP_CTL_BKDRST_POS              (31)
#define BKP_CTL_EXTHFBYP                ((uint32_t)1<<(BKP_CTL_EXTHFBYP_POS))
#define BKP_CTL_EXTLFBYP                ((uint32_t)1<<(BKP_CTL_EXTLFBYP_POS))
#define BKP_CTL_RTCCLKS                 ((uint32_t)3<<(BKP_CTL_RTCCLKS0_POS))
#define BKP_CTL_RTCCLKS0                ((uint32_t)1<<(BKP_CTL_RTCCLKS0_POS))
#define BKP_CTL_RTCCLKS1                ((uint32_t)1<<(BKP_CTL_RTCCLKS1_POS))
#define BKP_CTL_TAMP1EN                 ((uint32_t)1<<(BKP_CTL_TAMP1EN_POS))
#define BKP_CTL_TAMP2EN                 ((uint32_t)1<<(BKP_CTL_TAMP2EN_POS))
#define BKP_CTL_TAMP3EN                 ((uint32_t)1<<(BKP_CTL_TAMP3EN_POS))
#define BKP_CTL_TAMP1LVL                ((uint32_t)1<<(BKP_CTL_TAMP1LVL_POS))
#define BKP_CTL_TAMP2LVL                ((uint32_t)1<<(BKP_CTL_TAMP2LVL_POS))
#define BKP_CTL_TAMP3LVL                ((uint32_t)1<<(BKP_CTL_TAMP3LVL_POS))
#define BKP_CTL_BKDRST                  ((uint32_t)1<<(BKP_CTL_BKDRST_POS))

/* BKP_INT λ�� */
#define BKP_INT_TAMP1IC_POS             (0)
#define BKP_INT_TAMP2IC_POS             (1)
#define BKP_INT_TAMP3IC_POS             (2)
#define BKP_INT_TAMP1IE_POS             (8)
#define BKP_INT_TAMP2IE_POS             (9)
#define BKP_INT_TAMP3IE_POS             (10)
#define BKP_INT_TAMP1IF_POS             (16)
#define BKP_INT_TAMP2IF_POS             (17)
#define BKP_INT_TAMP3IF_POS             (18)
#define BKP_INT_TAMP1IC                 ((uint32_t)1<<(BKP_INT_TAMP1IC_POS))
#define BKP_INT_TAMP2IC                 ((uint32_t)1<<(BKP_INT_TAMP2IC_POS))
#define BKP_INT_TAMP3IC                 ((uint32_t)1<<(BKP_INT_TAMP3IC_POS))
#define BKP_INT_TAMP1IE                 ((uint32_t)1<<(BKP_INT_TAMP1IE_POS))
#define BKP_INT_TAMP2IE                 ((uint32_t)1<<(BKP_INT_TAMP2IE_POS))
#define BKP_INT_TAMP3IE                 ((uint32_t)1<<(BKP_INT_TAMP3IE_POS))
#define BKP_INT_TAMP1IF                 ((uint32_t)1<<(BKP_INT_TAMP1IF_POS))
#define BKP_INT_TAMP2IF                 ((uint32_t)1<<(BKP_INT_TAMP2IF_POS))
#define BKP_INT_TAMP3IF                 ((uint32_t)1<<(BKP_INT_TAMP3IF_POS))

/* BKP_DATA λ�� */
#define BKP_DATA_BKPDATA0_POS           (0)
#define BKP_DATA_BKPDATA                ((uint32_t)0xFFFFFFFF<<(BKP_DATA_BKPDATA0_POS))
/* ������ (BKP)������� */


/* ----------------------------------------------------------------------------
   -- FLASH����洢�� (FLASH)
   ---------------------------------------------------------------------------- */

/* FLASH - ����Ĵ����ڴ�ṹ */
typedef struct FLASH_MemMap {
    volatile uint32_t ISPCON0;          /* FLASH ���ƼĴ���, ƫ��:0x00 */
    volatile uint32_t ISPCON1;          /* FLASH ���ƼĴ���, ƫ��:0x04 */
    volatile uint32_t ISPCMD;           /* FLASH ���ƼĴ���, ƫ��:0x08 */
    volatile uint32_t ISPTRG;           /* FLASH ���ƼĴ���, ƫ��:0x0C */
             uint32_t RESERVED1;        /* ������ַ, ƫ��:0x10 */
    volatile uint32_t CFG;              /* FLASH ���ƼĴ���, ƫ��:0x14 */
             uint32_t RESERVED2;        /* ������ַ, ƫ��:0x18 */
    volatile uint32_t ISPADDR;          /* FLASH ��ַ�Ĵ���, ƫ��:0x1C */
    volatile uint32_t STATE;            /* FLASH ״̬�Ĵ���, ƫ��:0x20 */
             uint32_t RESERVED3;        /* ������ַ, ƫ��:0x24 */
    volatile uint32_t NVMUNLOCK;        /* FLASH ����KEY�Ĵ���, ƫ��:0x28 */
    volatile uint32_t PROUNLOCK;        /* FLASH ����KEY�Ĵ���, ƫ��:0x2C */
    volatile uint32_t CFGUNLOCK;        /* FLASH ����KEY�Ĵ���, ƫ��:0x30 */
             uint32_t RESERVED4;        /* ������ַ, ƫ��:0x34 */
    volatile uint32_t CSSTART;          /* FLASH CheckSum�׵�ַ�Ĵ���, ƫ��:0x38 */
    volatile uint32_t CSSTOP;           /* FLASH CheckSumβ��ַ�Ĵ���, ƫ��:0x3C */
    volatile uint32_t CSRES[4];         /* FLASH CheckSum����Ĵ���, ƫ��:0x40 */
}FLASH_SFRmap;

/* ----------------------------------------------------------------------------
   -- FLASH - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */

/* FLASH - �Ĵ�����ڵ�ַ */
#define FLASH_ADDR                      ((uint32_t)0x40200100)
#define FLASH_SFR                       ((FLASH_SFRmap *) FLASH_ADDR)

/* FLASH - �Ĵ������ */
#define FLASH_ISPCON0                   (FLASH_SFR->ISPCON0)
#define FLASH_ISPCON1                   (FLASH_SFR->ISPCON1)
#define FLASH_ISPCMD                    (FLASH_SFR->ISPCMD)
#define FLASH_ISPTRG                    (FLASH_SFR->ISPTRG)
#define FLASH_CFG                       (FLASH_SFR->CFG)
#define FLASH_ISPADDR                   (FLASH_SFR->ISPADDR)
#define FLASH_STATE                     (FLASH_SFR->STATE)
#define FLASH_NVMUNLOCK                 (FLASH_SFR->NVMUNLOCK)
#define FLASH_PROUNLOCK                 (FLASH_SFR->PROUNLOCK)
#define FLASH_CFGUNLOCK                 (FLASH_SFR->CFGUNLOCK)
#define FLASH_CSSTART                   (FLASH_SFR->CSSTART)
#define FLASH_CSSTOP                    (FLASH_SFR->CSSTOP)
#define FLASH_CSRES0                    (FLASH_SFR->CSRES[0])
#define FLASH_CSRES1                    (FLASH_SFR->CSRES[1])
#define FLASH_CSRES2                    (FLASH_SFR->CSRES[2])
#define FLASH_CSRES3                    (FLASH_SFR->CSRES[3])

/* FLASH_ISPCON0 λ�� */
#define FLASH_ISPCON0_NVMLOCK_POS       (0)
#define FLASH_ISPCON0_FLASHLOCK_POS     (1)
#define FLASH_ISPCON0_CFGLOCK_POS       (2)
#define FLASH_ISPCON0_DWEN_POS          (3)
#define FLASH_ISPCON0_IFEN_POS          (4)
#define FLASH_ISPCON0_STANDBY1_POS      (5)
#define FLASH_ISPCON0_STANDBY2_POS      (6)
#define FLASH_ISPCON0_NVMLOCK           ((uint32_t)1<<(FLASH_ISPCON0_NVMLOCK_POS))
#define FLASH_ISPCON0_FLASHLOCK         ((uint32_t)1<<(FLASH_ISPCON0_FLASHLOCK_POS))
#define FLASH_ISPCON0_CFGLOCK           ((uint32_t)1<<(FLASH_ISPCON0_CFGLOCK_POS))
#define FLASH_ISPCON0_DWEN              ((uint32_t)1<<(FLASH_ISPCON0_DWEN_POS))
#define FLASH_ISPCON0_IFEN              ((uint32_t)1<<(FLASH_ISPCON0_IFEN_POS))
#define FLASH_ISPCON0_STANDBY1          ((uint32_t)1<<(FLASH_ISPCON0_STANDBY1_POS))
#define FLASH_ISPCON0_STANDBY2          ((uint32_t)1<<(FLASH_ISPCON0_STANDBY2_POS))

/* FLASH_ISPCON1 λ�� */
#define FLASH_ISPCON1_IPSEL_POS         (0)
#define FLASH_ISPCON1_RECALLEN_POS      (1)
#define FLASH_ISPCON1_CONFEN_POS        (2)
#define FLASH_ISPCON1_CHIPONEN_POS      (15)
#define FLASH_ISPCON1_IPSEL             ((uint32_t)1<(FLASH_ISPCON1_IPSEL_POS))
#define FLASH_ISPCON1_RECALLEN          ((uint32_t)1<(FLASH_ISPCON1_RECALLEN_POS))
#define FLASH_ISPCON1_CONFEN            ((uint32_t)1<(FLASH_ISPCON1_CONFEN_POS))
#define FLASH_ISPCON1_CHIPONEN          ((uint32_t)1<(FLASH_ISPCON1_CHIPONEN_POS))

/* FLASH_ISPCMD λ�� */
#define FLASH_ISPCMD_CMD0_POS           (0)
#define FLASH_ISPCMD_CMD1_POS           (1)
#define FLASH_ISPCMD_CMD2_POS           (2)
#define FLASH_ISPCMD_CMD3_POS           (3)
#define FLASH_ISPCMD_CMD4_POS           (4)
#define FLASH_ISPCMD_WSIZE0_POS         (5)
#define FLASH_ISPCMD_WSIZE1_POS         (6)
#define FLASH_ISPCMD_WSIZE2_POS         (7)
#define FLASH_ISPCMD_WSIZE3_POS         (8)
#define FLASH_ISPCMD_WSIZE4_POS         (9)
#define FLASH_ISPCMD_WSIZE5_POS         (10)
#define FLASH_ISPCMD_CMD                ((uint32_t)0x1F<<(FLASH_ISPCMD_CMD0_POS))
#define FLASH_ISPCMD_CMD0               ((uint32_t)1<<(FLASH_ISPCMD_CMD0_POS))
#define FLASH_ISPCMD_CMD1               ((uint32_t)1<<(FLASH_ISPCMD_CMD1_POS))
#define FLASH_ISPCMD_CMD2               ((uint32_t)1<<(FLASH_ISPCMD_CMD2_POS))
#define FLASH_ISPCMD_CMD3               ((uint32_t)1<<(FLASH_ISPCMD_CMD3_POS))
#define FLASH_ISPCMD_CMD4               ((uint32_t)1<<(FLASH_ISPCMD_CMD4_POS))
#define FLASH_ISPCMD_WSIZE              ((uint32_t)0x3F<<(FLASH_ISPCMD_WSIZE0_POS))
#define FLASH_ISPCMD_WSIZE0             ((uint32_t)1<<(FLASH_ISPCMD_WSIZE0_POS))
#define FLASH_ISPCMD_WSIZE1             ((uint32_t)1<<(FLASH_ISPCMD_WSIZE1_POS))
#define FLASH_ISPCMD_WSIZE2             ((uint32_t)1<<(FLASH_ISPCMD_WSIZE2_POS))
#define FLASH_ISPCMD_WSIZE3             ((uint32_t)1<<(FLASH_ISPCMD_WSIZE3_POS))
#define FLASH_ISPCMD_WSIZE4             ((uint32_t)1<<(FLASH_ISPCMD_WSIZE4_POS))
#define FLASH_ISPCMD_WSIZE5             ((uint32_t)1<<(FLASH_ISPCMD_WSIZE5_POS))

/* FLASH_ISPTRG λ�� */
#define FLASH_ISPTRG_ISPGO_POS          (0)
#define FLASH_ISPTRG_ISPGO              ((uint32_t)1<<(FLASH_ISPTRG_ISPGO_POS))

/* FLASH_CFG λ�� */
#define FLASH_CFG_TCFG0_POS             (0)
#define FLASH_CFG_TCFG1_POS             (1)
#define FLASH_CFG_TCFG2_POS             (2)
#define FLASH_CFG_TCFG3_POS             (3)
#define FLASH_CFG_PREFETCHEN_POS        (6)
#define FLASH_CFG_ECCREADEN_POS         (7)
#define FLASH_CFG_TCFG                  ((uint32_t)0xF<<(FLASH_CFG_TCFG0_POS))
#define FLASH_CFG_TCFG0                 ((uint32_t)1<<(FLASH_CFG_TCFG0_POS))
#define FLASH_CFG_TCFG1                 ((uint32_t)1<<(FLASH_CFG_TCFG1_POS))
#define FLASH_CFG_TCFG2                 ((uint32_t)1<<(FLASH_CFG_TCFG2_POS))
#define FLASH_CFG_TCFG3                 ((uint32_t)1<<(FLASH_CFG_TCFG3_POS))
#define FLASH_CFG_PREFETCHEN            ((uint32_t)1<<(FLASH_CFG_PREFETCHEN_POS))
#define FLASH_CFG_ECCREADEN             ((uint32_t)1<<(FLASH_CFG_ECCREADEN_POS))

/* FLASH_ISPADDR λ�� */
#define FLASH_ISPADDR_SADDR0_POS        (0)
#define FLASH_ISPADDR_SADDR1_POS        (1)
#define FLASH_ISPADDR_SADDR2_POS        (2)
#define FLASH_ISPADDR_SADDR3_POS        (3)
#define FLASH_ISPADDR_SADDR4_POS        (4)
#define FLASH_ISPADDR_SADDR5_POS        (5)
#define FLASH_ISPADDR_SADDR6_POS        (6)
#define FLASH_ISPADDR_SADDR7_POS        (7)
#define FLASH_ISPADDR_SADDR8_POS        (8)
#define FLASH_ISPADDR_SADDR9_POS        (9)
#define FLASH_ISPADDR_SADDR10_POS       (10)
#define FLASH_ISPADDR_SADDR11_POS       (11)
#define FLASH_ISPADDR_SADDR12_POS       (12)
#define FLASH_ISPADDR_SADDR13_POS       (13)
#define FLASH_ISPADDR_SADDR14_POS       (14)
#define FLASH_ISPADDR_SADDR15_POS       (15)
#define FLASH_ISPADDR_SADDR16_POS       (16)
#define FLASH_ISPADDR_SADDR17_POS       (17)
#define FLASH_ISPADDR_SADDR18_POS       (18)
#define FLASH_ISPADDR_SADDR19_POS       (19)
#define FLASH_ISPADDR_SADDR             ((uint32_t)0xFFFFF<<(FLASH_ISPADDR_SADDR0_POS))

/* FLASH_STATE λ�� */
#define FLASH_STATE_CFGERROR_POS        (0)
#define FLASH_STATE_SIGDONE_POS         (1)
#define FLASH_STATE_TBIT_POS            (2)
#define FLASH_STATE_TBUSY_POS           (3)
#define FLASH_STATE_BDBG_POS            (12)
#define FLASH_STATE_BDBGREM_POS         (13)
#define FLASH_STATE_CFGERROR            ((uint32_t)1<<(FLASH_STATE_CFGERROR_POS))
#define FLASH_STATE_SIGDONE             ((uint32_t)1<<(FLASH_STATE_SIGDONE_POS))
#define FLASH_STATE_TBIT                ((uint32_t)1<<(FLASH_STATE_TBIT_POS))
#define FLASH_STATE_TBUSY               ((uint32_t)1<<(FLASH_STATE_TBUSY_POS))
#define FLASH_STATE_BDBG                ((uint32_t)1<<(FLASH_STATE_BDBG_POS))
#define FLASH_STATE_BDBGREM             ((uint32_t)1<<(FLASH_STATE_BDBGREM_POS))

/* FLASH_NVMUNLOCK λ�� */
#define FLASH_NVMUNLOCK_NVMUNLOCK0_POS  (0)
#define FLASH_NVMUNLOCK_NVMUNLOCK       ((uint32_t)0xFFFFFFFF<<(FLASH_NVMUNLOCK_NVMUNLOCK0_POS))

/* FLASH_PROUNLOCK λ�� */
#define FLASH_PROUNLOCK_PROUNLOCK0_POS  (0)
#define FLASH_PROUNLOCK_PROUNLOCK       ((uint32_t)0xFFFFFFFF<<(FLASH_PROUNLOCK_PROUNLOCK0_POS))

/* FLASH_CFGUNLOCK λ�� */
#define FLASH_CFGUNLOCK_CFGUNLOCK0_POS  (0)
#define FLASH_CFGUNLOCK_CFGUNLOCK       ((uint32_t)0xFFFFFFFF<<(FLASH_CFGUNLOCK_CFGUNLOCK0_POS))

/* FLASH_CSSTART λ�� */
#define FLASH_CSSTART_CKSTADDR0_POS     (4)
#define FLASH_CSSTART_CKSTADDR          ((uint32_t)0xFFFF<<(FLASH_CSSTART_CKSTADDR0_POS))

/* FLASH_CSSTOP λ�� */
#define FLASH_CSSTOP_CKSPADDR0_POS      (4)
#define FLASH_CSSTOP_SIGGO_POS          (20)
#define FLASH_CSSTOP_CKSPADDR           ((uint32_t)0xFFFF<<(FLASH_CSSTOP_CKSPADDR0_POS))
#define FLASH_CSSTOP_SIGGO              ((uint32_t)1<<(FLASH_CSSTOP_SIGGO_POS))

/* FLASH_CSRES0 λ�� */
#define FLASH_CSRES0_CKSPRES0_0_POS     (0)
#define FLASH_CSRES0_CKSPRES0           ((uint32_t)0xFFFFFFFF<<(FLASH_CSRES0_CKSPRES0_0_POS))

/* FLASH_CSRES1 λ�� */
#define FLASH_CSRES1_CKSPRES1_0_POS     (0)
#define FLASH_CSRES1_CKSPRES1           ((uint32_t)0xFFFFFFFF<<(FLASH_CSRES1_CKSPRES1_0_POS))

/* FLASH_CSRES2 λ�� */
#define FLASH_CSRES2_CKSPRES2_0_POS     (0)
#define FLASH_CSRES2_CKSPRES2           ((uint32_t)0xFFFFFFFF<<(FLASH_CSRES2_CKSPRES2_0_POS))

/* FLASH_CSRES3 λ�� */
#define FLASH_CSRES3_CKSPRES3_0_POS     (0)
#define FLASH_CSRES3_CKSPRES3           ((uint32_t)0xFFFFFFFF<<(FLASH_CSRES3_CKSPRES3_0_POS))
/* FLASH����洢�� (FLASH)������� */

/* ----------------------------------------------------------------------------
   -- ѭ������У�鵥Ԫ (CRC)
   ---------------------------------------------------------------------------- */

/* CRC - ����Ĵ����ڴ�ṹ */
typedef struct CRC_MemMap {
    volatile uint32_t CTL;             /* CRC ���ƼĴ���, ƫ��:0x00 */
    volatile uint32_t DATA;            /* ƫ��:0x04 */
    volatile uint32_t RSLT;            /* ƫ��:0x08 */
    volatile uint32_t INIT;            /* ƫ��:0x0C */
    volatile uint32_t PLN;             /* ƫ��:0x10 */
    volatile uint32_t RXOR;            /* ƫ��:0x14 */
    volatile uint32_t IDATA;           /* ƫ��:0x18 */
    volatile uint32_t TEMP;            /* ƫ��:0x1C */
}CRC_SFRmap;

/* ----------------------------------------------------------------------------
   -- CRC - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */

/* CRC - �Ĵ�����ڵ�ַ */
#ifdef  KF32F_Periph_crc
#define CRC_ADDR                      ((uint32_t)0x40002680)
#define CRC_SFR                       ((CRC_SFRmap *) CRC_ADDR)
#endif
/* CRC - �Ĵ������ */
#define CRC_CTL                       (CRC_SFR->CTL)
#define CRC_DATA                      (CRC_SFR->DATA)
#define CRC_RSLT                      (CRC_SFR->RSLT)
#define CRC_INIT                      (CRC_SFR->INIT)
#define CRC_CFG                       (CRC_SFR->CFG)
#define CRC_PLN                       (CRC_SFR->PLN)
#define CRC_RXOR                      (CRC_SFR->RXOR)
#define CRC_IDATA                     (CRC_SFR->IDATA)
#define CRC_TEMP                      (CRC_SFR->TEMP)

/* CRC_CTL λ�� */
#define CRC_CTL_RSET_POS       		  (0)
#define CRC_CTL_DATASIZE0_POS         (2)
#define CRC_CTL_DATASIZE1_POS         (3)
#define CRC_CTL_DATAREV_POS           (5)
#define CRC_CTL_RSLTREV_POS      	  (7)
#define CRC_CTL_RSET                  ((uint32_t)1<<(CRC_CTL_RSET_POS))
#define CRC_CTL_DATASIZE              ((uint32_t)0x3<<(CRC_CTL_DATASIZE0_POS))
#define CRC_CTL_DATASIZE0             ((uint32_t)1<<(CRC_CTL_DATASIZE0_POS))
#define CRC_CTL_DATASIZE1             ((uint32_t)1<<(CRC_CTL_DATASIZE1_POS))
#define CRC_CTL_DATAREV               ((uint32_t)1<<(CRC_CTL_DATAREV_POS))
#define CRC_CTL_RSLTREV               ((uint32_t)1<<(CRC_CTL_RSLTREV_POS))

/* CRC ������� */
/* ----------------------------------------------------------------------------
   -- ����ģ�� (AES)
   ---------------------------------------------------------------------------- */

/* AES����ģ��Ĵ����ڴ�ṹ */
typedef struct AES_MemMap {
    volatile uint32_t CTL;             /* AES���ƼĴ���, ƫ��:0x00 */
    		 uint32_t RESERVED1;       /* ������ַ, ƫ��:0x04 */
    		 uint32_t RESERVED2;       /* ������ַ, ƫ��:0x08 */
    		 uint32_t RESERVED3;       /* ������ַ, ƫ��:0x0C */
    volatile uint32_t KEY0;            /* AES��Կ�Ĵ���0, ƫ��:0x10 */
    volatile uint32_t KEY1;            /* AES��Կ�Ĵ���1, ƫ��:0x14 */
    volatile uint32_t KEY2;            /* AES��Կ�Ĵ���2, ƫ��:0x18 */
    volatile uint32_t KEY3;            /* AES��Կ�Ĵ���3, ƫ��:0x1C */
    volatile uint32_t INPUT0;          /* AES��Կ�Ĵ���0, ƫ��:0x20 */
    volatile uint32_t INPUT1;          /* AES��Կ�Ĵ���1, ƫ��:0x24 */
    volatile uint32_t INPUT2;          /* AES��Կ�Ĵ���2, ƫ��:0x28 */
    volatile uint32_t INPUT3;          /* AES��Կ�Ĵ���3, ƫ��:0x2C */
    volatile uint32_t OUTPUT0;         /* AES��Կ�Ĵ���0, ƫ��:0x30 */
    volatile uint32_t OUTPUT1;         /* AES��Կ�Ĵ���1, ƫ��:0x34 */
    volatile uint32_t OUTPUT2;         /* AES��Կ�Ĵ���2, ƫ��:0x38 */
    volatile uint32_t OUTPUT3;         /* AES��Կ�Ĵ���3, ƫ��:0x3C */
}AES_SFRmap;

/* ----------------------------------------------------------------------------
   -- AES - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */

/* AES - �Ĵ�����ڵ�ַ */
#ifdef KF32F_Periph_aes
#define AES_ADDR                      ((uint32_t)0x40002700)
#define AES_SFR                       ((AES_SFRmap *) AES_ADDR)
#endif
/* AES - �Ĵ������ */
#define AES_CTL                       (AES_SFR->CTL)
#define AES_KEY0                      (AES_SFR->KEY0)
#define AES_KEY1                      (AES_SFR->KEY1)
#define AES_KEY2                      (AES_SFR->KEY2)
#define AES_KEY3                      (AES_SFR->KEY3)
#define AES_INPUT0                    (AES_SFR->INPUT0)
#define AES_INPUT1                    (AES_SFR->INPUT1)
#define AES_INPUT2                    (AES_SFR->INPUT2)
#define AES_INPUT3                    (AES_SFR->INPUT3)
#define AES_OUTPUT0                   (AES_SFR->OUTPUT0)
#define AES_OUTPUT1                   (AES_SFR->OUTPUT1)
#define AES_OUTPUT2                   (AES_SFR->OUTPUT2)
#define AES_OUTPUT3                   (AES_SFR->OUTPUT3)

/* AES_CTL λ�� */
#define AES_CTL_OFBEN_POS       	  (0)
#define AES_CTL_AESCS0_POS            (1)
#define AES_CTL_AESCS1_POS            (2)
#define AES_CTL_AESDIV0_POS           (3)
#define AES_CTL_AESDIV1_POS           (4)
#define AES_CTL_AESDIV2_POS           (5)
#define AES_CTL_AESRUN_POS            (7)
#define AES_CTL_AESFIE_POS      	  (15)
#define AES_CTL_AESFIC_POS            (23)
#define AES_CTL_AESFIF_POS            (31)
#define AES_CTL_OFBEN                 ((uint32_t)1<<(AES_CTL_OFBEN_POS))
#define AES_CTL_AESCS                 ((uint32_t)0x3<<(AES_CTL_AESCS0_POS))
#define AES_CTL_AESCS0                ((uint32_t)1<<(AES_CTL_AESCS0_POS))
#define AES_CTL_AESCS1                ((uint32_t)1<<(AES_CTL_AESCS1_POS))
#define AES_CTL_AESDIV                ((uint32_t)0x7<<(AES_CTL_AESDIV0_POS))
#define AES_CTL_AESDIV0               ((uint32_t)1<<(AES_CTL_AESDIV0_POS))
#define AES_CTL_AESDIV1               ((uint32_t)1<<(AES_CTL_AESDIV1_POS))
#define AES_CTL_AESDIV2               ((uint32_t)1<<(AES_CTL_AESDIV2_POS))
#define AES_CTL_AESRUN                ((uint32_t)1<<(AES_CTL_AESRUN_POS))
#define AES_CTL_AESFIE                ((uint32_t)1<<(AES_CTL_AESFIE_POS))
#define AES_CTL_AESFIC                ((uint32_t)1<<(AES_CTL_AESFIC_POS))
#define AES_CTL_AESFIF                ((uint32_t)1<<(AES_CTL_AESFIF_POS))

/* AES ������� */


/* ----------------------------------------------------------------------------
   -- LED����ģ�� (LED)
   ---------------------------------------------------------------------------- */
#ifdef KF32F_Periph_led
/* LED����ģ��Ĵ����ڴ�ṹ */
typedef struct LED_MemMap {
    volatile uint32_t DATA0;        /* LED���ݼĴ���0, ƫ��:0x00 */
    volatile uint32_t DATA1;        /* LED���ݼĴ���1, ƫ��:0x04 */
    volatile uint32_t DATA2;        /* LED���ݼĴ���2, ƫ��:0x08 */
    volatile uint32_t DATA3;        /* LED���ݼĴ���3, ƫ��:0x0C */
    volatile uint32_t DATA4;        /* LED���ݼĴ���4, ƫ��:0x10 */
    volatile uint32_t DATA5;        /* LED���ݼĴ���5, ƫ��:0x14 */
    volatile uint32_t DATA6;        /* LED���ݼĴ���6, ƫ��:0x18 */
    volatile uint32_t DATA7;        /* LED���ݼĴ���7, ƫ��:0x1C */
    volatile uint32_t CTL0;         /* LED���ƼĴ���0, ƫ��:0x20 */
    volatile uint32_t CTL1;         /* LED���ƼĴ���1, ƫ��:0x24 */
}LED_SFRmap;
/* ----------------------------------------------------------------------------
   -- LED - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */

/* LED - �Ĵ�����ڵ�ַ */
#define LED_ADDR                      ((uint32_t)0x40002780)
#define LED_SFR                       ((LED_SFRmap *) LED_ADDR)

/* LED - �Ĵ������ */
#define LED_DATA0                     (LED_SFR->DATA0)
#define LED_DATA1                     (LED_SFR->DATA1)
#define LED_DATA2                     (LED_SFR->DATA2)
#define LED_DATA3                     (LED_SFR->DATA3)
#define LED_DATA4                     (LED_SFR->DATA4)
#define LED_DATA5                     (LED_SFR->DATA5)
#define LED_DATA6                     (LED_SFR->DATA6)
#define LED_DATA7                     (LED_SFR->DATA7)
#define LED_CTL0                      (LED_SFR->CTL0)
#define LED_CTL1                      (LED_SFR->CTL1)

/* LED_DATA0 λ�� */
#define LED_DATA0_COM0SEG0_POS       	(0)
#define LED_DATA0_COM0SEG1_POS          (1)
#define LED_DATA0_COM0SEG2_POS          (2)
#define LED_DATA0_COM0SEG3_POS          (3)
#define LED_DATA0_COM0SEG4_POS          (4)
#define LED_DATA0_COM0SEG5_POS          (5)
#define LED_DATA0_COM0SEG6_POS          (6)
#define LED_DATA0_COM0SEG7_POS      	(7)
#define LED_DATA0_COM0SEG8_POS          (8)
#define LED_DATA0_COM0SEG9_POS          (9)
#define LED_DATA0_COM0SEG10_POS         (10)
#define LED_DATA0_COM0SEG11_POS         (11)
#define LED_DATA0_COM0SEG12_POS      	(12)
#define LED_DATA0_COM0SEG13_POS         (13)
#define LED_DATA0_COM0SEG14_POS         (14)
#define LED_DATA0_COM0SEG15_POS         (15)
#define LED_DATA0_COM0SEG               ((uint32_t)0xffff<<(LED_DATA0_COM0SEG0_POS))
#define LED_DATA0_COM0SEG0              ((uint32_t)1<<(LED_DATA0_COM0SEG0_POS))
#define LED_DATA0_COM0SEG1              ((uint32_t)1<<(LED_DATA0_COM0SEG1_POS))
#define LED_DATA0_COM0SEG2              ((uint32_t)1<<(LED_DATA0_COM0SEG2_POS))
#define LED_DATA0_COM0SEG3              ((uint32_t)1<<(LED_DATA0_COM0SEG3_POS))
#define LED_DATA0_COM0SEG4              ((uint32_t)1<<(LED_DATA0_COM0SEG4_POS))
#define LED_DATA0_COM0SEG5              ((uint32_t)1<<(LED_DATA0_COM0SEG5_POS))
#define LED_DATA0_COM0SEG6              ((uint32_t)1<<(LED_DATA0_COM0SEG6_POS))
#define LED_DATA0_COM0SEG7              ((uint32_t)1<<(LED_DATA0_COM0SEG7_POS))
#define LED_DATA0_COM0SEG8              ((uint32_t)1<<(LED_DATA0_COM0SEG8_POS))
#define LED_DATA0_COM0SEG9              ((uint32_t)1<<(LED_DATA0_COM0SEG9_POS))
#define LED_DATA0_COM0SEG10             ((uint32_t)1<<(LED_DATA0_COM0SEG10_POS))
#define LED_DATA0_COM0SEG11             ((uint32_t)1<<(LED_DATA0_COM0SEG11_POS))
#define LED_DATA0_COM0SEG12             ((uint32_t)1<<(LED_DATA0_COM0SEG12_POS))
#define LED_DATA0_COM0SEG13             ((uint32_t)1<<(LED_DATA0_COM0SEG13_POS))
#define LED_DATA0_COM0SEG14             ((uint32_t)1<<(LED_DATA0_COM0SEG14_POS))
#define LED_DATA0_COM0SEG15             ((uint32_t)1<<(LED_DATA0_COM0SEG15_POS))

/* LED_DATA1 λ�� */
#define LED_DATA1_COM1SEG0_POS       	(0)
#define LED_DATA1_COM1SEG1_POS          (1)
#define LED_DATA1_COM1SEG2_POS          (2)
#define LED_DATA1_COM1SEG3_POS          (3)
#define LED_DATA1_COM1SEG4_POS          (4)
#define LED_DATA1_COM1SEG5_POS          (5)
#define LED_DATA1_COM1SEG6_POS          (6)
#define LED_DATA1_COM1SEG7_POS      	(7)
#define LED_DATA1_COM1SEG8_POS          (8)
#define LED_DATA1_COM1SEG9_POS          (9)
#define LED_DATA1_COM1SEG10_POS         (10)
#define LED_DATA1_COM1SEG11_POS         (11)
#define LED_DATA1_COM1SEG12_POS      	(12)
#define LED_DATA1_COM1SEG13_POS         (13)
#define LED_DATA1_COM1SEG14_POS         (14)
#define LED_DATA1_COM1SEG15_POS         (15)
#define LED_DATA1_COM1SEG               ((uint32_t)0xffff<<(LED_DATA1_COM1SEG0_POS))
#define LED_DATA1_COM1SEG0              ((uint32_t)1<<(LED_DATA1_COM1SEG0_POS))
#define LED_DATA1_COM1SEG1              ((uint32_t)1<<(LED_DATA1_COM1SEG1_POS))
#define LED_DATA1_COM1SEG2              ((uint32_t)1<<(LED_DATA1_COM1SEG2_POS))
#define LED_DATA1_COM1SEG3              ((uint32_t)1<<(LED_DATA1_COM1SEG3_POS))
#define LED_DATA1_COM1SEG4              ((uint32_t)1<<(LED_DATA1_COM1SEG4_POS))
#define LED_DATA1_COM1SEG5              ((uint32_t)1<<(LED_DATA1_COM1SEG5_POS))
#define LED_DATA1_COM1SEG6              ((uint32_t)1<<(LED_DATA1_COM1SEG6_POS))
#define LED_DATA1_COM1SEG7              ((uint32_t)1<<(LED_DATA1_COM1SEG7_POS))
#define LED_DATA1_COM1SEG8              ((uint32_t)1<<(LED_DATA1_COM1SEG8_POS))
#define LED_DATA1_COM1SEG9              ((uint32_t)1<<(LED_DATA1_COM1SEG9_POS))
#define LED_DATA1_COM1SEG10             ((uint32_t)1<<(LED_DATA1_COM1SEG10_POS))
#define LED_DATA1_COM1SEG11             ((uint32_t)1<<(LED_DATA1_COM1SEG11_POS))
#define LED_DATA1_COM1SEG12             ((uint32_t)1<<(LED_DATA1_COM1SEG12_POS))
#define LED_DATA1_COM1SEG13             ((uint32_t)1<<(LED_DATA1_COM1SEG13_POS))
#define LED_DATA1_COM1SEG14             ((uint32_t)1<<(LED_DATA1_COM1SEG14_POS))
#define LED_DATA1_COM1SEG15             ((uint32_t)1<<(LED_DATA1_COM1SEG15_POS))

/* LED_DATA2 λ�� */
#define LED_DATA2_COM2SEG0_POS       	(0)
#define LED_DATA2_COM2SEG1_POS          (1)
#define LED_DATA2_COM2SEG2_POS          (2)
#define LED_DATA2_COM2SEG3_POS          (3)
#define LED_DATA2_COM2SEG4_POS          (4)
#define LED_DATA2_COM2SEG5_POS          (5)
#define LED_DATA2_COM2SEG6_POS          (6)
#define LED_DATA2_COM2SEG7_POS      	(7)
#define LED_DATA2_COM2SEG8_POS          (8)
#define LED_DATA2_COM2SEG9_POS          (9)
#define LED_DATA2_COM2SEG10_POS         (10)
#define LED_DATA2_COM2SEG11_POS         (11)
#define LED_DATA2_COM2SEG12_POS      	(12)
#define LED_DATA2_COM2SEG13_POS         (13)
#define LED_DATA2_COM2SEG14_POS         (14)
#define LED_DATA2_COM2SEG15_POS         (15)
#define LED_DATA2_COM2SEG               ((uint32_t)0xffff<<(LED_DATA2_COM2SEG0_POS))
#define LED_DATA2_COM2SEG0              ((uint32_t)1<<(LED_DATA2_COM2SEG0_POS))
#define LED_DATA2_COM2SEG1              ((uint32_t)1<<(LED_DATA2_COM2SEG1_POS))
#define LED_DATA2_COM2SEG2              ((uint32_t)1<<(LED_DATA2_COM2SEG2_POS))
#define LED_DATA2_COM2SEG3              ((uint32_t)1<<(LED_DATA2_COM2SEG3_POS))
#define LED_DATA2_COM2SEG4              ((uint32_t)1<<(LED_DATA2_COM2SEG4_POS))
#define LED_DATA2_COM2SEG5              ((uint32_t)1<<(LED_DATA2_COM2SEG5_POS))
#define LED_DATA2_COM2SEG6              ((uint32_t)1<<(LED_DATA2_COM2SEG6_POS))
#define LED_DATA2_COM2SEG7              ((uint32_t)1<<(LED_DATA2_COM2SEG7_POS))
#define LED_DATA2_COM2SEG8              ((uint32_t)1<<(LED_DATA2_COM2SEG8_POS))
#define LED_DATA2_COM2SEG9              ((uint32_t)1<<(LED_DATA2_COM2SEG9_POS))
#define LED_DATA2_COM2SEG10             ((uint32_t)1<<(LED_DATA2_COM2SEG10_POS))
#define LED_DATA2_COM2SEG11             ((uint32_t)1<<(LED_DATA2_COM2SEG11_POS))
#define LED_DATA2_COM2SEG12             ((uint32_t)1<<(LED_DATA2_COM2SEG12_POS))
#define LED_DATA2_COM2SEG13             ((uint32_t)1<<(LED_DATA2_COM2SEG13_POS))
#define LED_DATA2_COM2SEG14             ((uint32_t)1<<(LED_DATA2_COM2SEG14_POS))
#define LED_DATA2_COM2SEG15             ((uint32_t)1<<(LED_DATA2_COM2SEG15_POS))

/* LED_DATA3 λ�� */
#define LED_DATA3_COM3SEG0_POS       	(0)
#define LED_DATA3_COM3SEG1_POS          (1)
#define LED_DATA3_COM3SEG2_POS          (2)
#define LED_DATA3_COM3SEG3_POS          (3)
#define LED_DATA3_COM3SEG4_POS          (4)
#define LED_DATA3_COM3SEG5_POS          (5)
#define LED_DATA3_COM3SEG6_POS          (6)
#define LED_DATA3_COM3SEG7_POS      	(7)
#define LED_DATA3_COM3SEG8_POS          (8)
#define LED_DATA3_COM3SEG9_POS          (9)
#define LED_DATA3_COM3SEG10_POS         (10)
#define LED_DATA3_COM3SEG11_POS         (11)
#define LED_DATA3_COM3SEG12_POS      	(12)
#define LED_DATA3_COM3SEG13_POS         (13)
#define LED_DATA3_COM3SEG14_POS         (14)
#define LED_DATA3_COM3SEG15_POS         (15)
#define LED_DATA3_COM3SEG               ((uint32_t)0xffff<<(LED_DATA3_COM3SEG0_POS))
#define LED_DATA3_COM3SEG0              ((uint32_t)1<<(LED_DATA3_COM3SEG0_POS))
#define LED_DATA3_COM3SEG1              ((uint32_t)1<<(LED_DATA3_COM3SEG1_POS))
#define LED_DATA3_COM3SEG2              ((uint32_t)1<<(LED_DATA3_COM3SEG2_POS))
#define LED_DATA3_COM3SEG3              ((uint32_t)1<<(LED_DATA3_COM3SEG3_POS))
#define LED_DATA3_COM3SEG4              ((uint32_t)1<<(LED_DATA3_COM3SEG4_POS))
#define LED_DATA3_COM3SEG5              ((uint32_t)1<<(LED_DATA3_COM3SEG5_POS))
#define LED_DATA3_COM3SEG6              ((uint32_t)1<<(LED_DATA3_COM3SEG6_POS))
#define LED_DATA3_COM3SEG7              ((uint32_t)1<<(LED_DATA3_COM3SEG7_POS))
#define LED_DATA3_COM3SEG8              ((uint32_t)1<<(LED_DATA3_COM3SEG8_POS))
#define LED_DATA3_COM3SEG9              ((uint32_t)1<<(LED_DATA3_COM3SEG9_POS))
#define LED_DATA3_COM3SEG10             ((uint32_t)1<<(LED_DATA3_COM3SEG10_POS))
#define LED_DATA3_COM3SEG11             ((uint32_t)1<<(LED_DATA3_COM3SEG11_POS))
#define LED_DATA3_COM3SEG12             ((uint32_t)1<<(LED_DATA3_COM3SEG12_POS))
#define LED_DATA3_COM3SEG13             ((uint32_t)1<<(LED_DATA3_COM3SEG13_POS))
#define LED_DATA3_COM3SEG14             ((uint32_t)1<<(LED_DATA3_COM3SEG14_POS))
#define LED_DATA3_COM3SEG15             ((uint32_t)1<<(LED_DATA3_COM3SEG15_POS))

/* LED_DATA4 λ�� */
#define LED_DATA4_COM4SEG0_POS       	(0)
#define LED_DATA4_COM4SEG1_POS          (1)
#define LED_DATA4_COM4SEG2_POS          (2)
#define LED_DATA4_COM4SEG3_POS          (3)
#define LED_DATA4_COM4SEG4_POS          (4)
#define LED_DATA4_COM4SEG5_POS          (5)
#define LED_DATA4_COM4SEG6_POS          (6)
#define LED_DATA4_COM4SEG7_POS      	(7)
#define LED_DATA4_COM4SEG8_POS          (8)
#define LED_DATA4_COM4SEG9_POS          (9)
#define LED_DATA4_COM4SEG10_POS         (10)
#define LED_DATA4_COM4SEG11_POS         (11)
#define LED_DATA4_COM4SEG12_POS      	(12)
#define LED_DATA4_COM4SEG13_POS         (13)
#define LED_DATA4_COM4SEG14_POS         (14)
#define LED_DATA4_COM4SEG15_POS         (15)
#define LED_DATA4_COM4SEG               ((uint32_t)0xffff<<(LED_DATA4_COM4SEG0_POS))
#define LED_DATA4_COM4SEG0              ((uint32_t)1<<(LED_DATA4_COM4SEG0_POS))
#define LED_DATA4_COM4SEG1              ((uint32_t)1<<(LED_DATA4_COM4SEG1_POS))
#define LED_DATA4_COM4SEG2              ((uint32_t)1<<(LED_DATA4_COM4SEG2_POS))
#define LED_DATA4_COM4SEG3              ((uint32_t)1<<(LED_DATA4_COM4SEG3_POS))
#define LED_DATA4_COM4SEG4              ((uint32_t)1<<(LED_DATA4_COM4SEG4_POS))
#define LED_DATA4_COM4SEG5              ((uint32_t)1<<(LED_DATA4_COM4SEG5_POS))
#define LED_DATA4_COM4SEG6              ((uint32_t)1<<(LED_DATA4_COM4SEG6_POS))
#define LED_DATA4_COM4SEG7              ((uint32_t)1<<(LED_DATA4_COM4SEG7_POS))
#define LED_DATA4_COM4SEG8              ((uint32_t)1<<(LED_DATA4_COM4SEG8_POS))
#define LED_DATA4_COM4SEG9              ((uint32_t)1<<(LED_DATA4_COM4SEG9_POS))
#define LED_DATA4_COM4SEG10             ((uint32_t)1<<(LED_DATA4_COM4SEG10_POS))
#define LED_DATA4_COM4SEG11             ((uint32_t)1<<(LED_DATA4_COM4SEG11_POS))
#define LED_DATA4_COM4SEG12             ((uint32_t)1<<(LED_DATA4_COM4SEG12_POS))
#define LED_DATA4_COM4SEG13             ((uint32_t)1<<(LED_DATA4_COM4SEG13_POS))
#define LED_DATA4_COM4SEG14             ((uint32_t)1<<(LED_DATA4_COM4SEG14_POS))
#define LED_DATA4_COM4SEG15             ((uint32_t)1<<(LED_DATA4_COM4SEG15_POS))

/* LED_DATA5 λ�� */
#define LED_DATA5_COM5SEG0_POS       	(0)
#define LED_DATA5_COM5SEG1_POS          (1)
#define LED_DATA5_COM5SEG2_POS          (2)
#define LED_DATA5_COM5SEG3_POS          (3)
#define LED_DATA5_COM5SEG4_POS          (4)
#define LED_DATA5_COM5SEG5_POS          (5)
#define LED_DATA5_COM5SEG6_POS          (6)
#define LED_DATA5_COM5SEG7_POS      	(7)
#define LED_DATA5_COM5SEG8_POS          (8)
#define LED_DATA5_COM5SEG9_POS          (9)
#define LED_DATA5_COM5SEG10_POS         (10)
#define LED_DATA5_COM5SEG11_POS         (11)
#define LED_DATA5_COM5SEG12_POS      	(12)
#define LED_DATA5_COM5SEG13_POS         (13)
#define LED_DATA5_COM5SEG14_POS         (14)
#define LED_DATA5_COM5SEG15_POS         (15)
#define LED_DATA5_COM5SEG               ((uint32_t)0xffff<<(LED_DATA5_COM5SEG0_POS))
#define LED_DATA5_COM5SEG0              ((uint32_t)1<<(LED_DATA5_COM5SEG0_POS))
#define LED_DATA5_COM5SEG1              ((uint32_t)1<<(LED_DATA5_COM5SEG1_POS))
#define LED_DATA5_COM5SEG2              ((uint32_t)1<<(LED_DATA5_COM5SEG2_POS))
#define LED_DATA5_COM5SEG3              ((uint32_t)1<<(LED_DATA5_COM5SEG3_POS))
#define LED_DATA5_COM5SEG4              ((uint32_t)1<<(LED_DATA5_COM5SEG4_POS))
#define LED_DATA5_COM5SEG5              ((uint32_t)1<<(LED_DATA5_COM5SEG5_POS))
#define LED_DATA5_COM5SEG6              ((uint32_t)1<<(LED_DATA5_COM5SEG6_POS))
#define LED_DATA5_COM5SEG7              ((uint32_t)1<<(LED_DATA5_COM5SEG7_POS))
#define LED_DATA5_COM5SEG8              ((uint32_t)1<<(LED_DATA5_COM5SEG8_POS))
#define LED_DATA5_COM5SEG9              ((uint32_t)1<<(LED_DATA5_COM5SEG9_POS))
#define LED_DATA5_COM5SEG10             ((uint32_t)1<<(LED_DATA5_COM5SEG10_POS))
#define LED_DATA5_COM5SEG11             ((uint32_t)1<<(LED_DATA5_COM5SEG11_POS))
#define LED_DATA5_COM5SEG12             ((uint32_t)1<<(LED_DATA5_COM5SEG12_POS))
#define LED_DATA5_COM5SEG13             ((uint32_t)1<<(LED_DATA5_COM5SEG13_POS))
#define LED_DATA5_COM5SEG14             ((uint32_t)1<<(LED_DATA5_COM5SEG14_POS))
#define LED_DATA5_COM5SEG15             ((uint32_t)1<<(LED_DATA5_COM5SEG15_POS))

/* LED_DATA6 λ�� */
#define LED_DATA6_COM6SEG0_POS       	(0)
#define LED_DATA6_COM6SEG1_POS          (1)
#define LED_DATA6_COM6SEG2_POS          (2)
#define LED_DATA6_COM6SEG3_POS          (3)
#define LED_DATA6_COM6SEG4_POS          (4)
#define LED_DATA6_COM6SEG5_POS          (5)
#define LED_DATA6_COM6SEG6_POS          (6)
#define LED_DATA6_COM6SEG7_POS      	(7)
#define LED_DATA6_COM6SEG8_POS          (8)
#define LED_DATA6_COM6SEG9_POS          (9)
#define LED_DATA6_COM6SEG10_POS         (10)
#define LED_DATA6_COM6SEG11_POS         (11)
#define LED_DATA6_COM6SEG12_POS      	(12)
#define LED_DATA6_COM6SEG13_POS         (13)
#define LED_DATA6_COM6SEG14_POS         (14)
#define LED_DATA6_COM6SEG15_POS         (15)
#define LED_DATA6_COM6SEG               ((uint32_t)0xffff<<(LED_DATA6_COM6SEG0_POS))
#define LED_DATA6_COM6SEG0              ((uint32_t)1<<(LED_DATA6_COM6SEG0_POS))
#define LED_DATA6_COM6SEG1              ((uint32_t)1<<(LED_DATA6_COM6SEG1_POS))
#define LED_DATA6_COM6SEG2              ((uint32_t)1<<(LED_DATA6_COM6SEG2_POS))
#define LED_DATA6_COM6SEG3              ((uint32_t)1<<(LED_DATA6_COM6SEG3_POS))
#define LED_DATA6_COM6SEG4              ((uint32_t)1<<(LED_DATA6_COM6SEG4_POS))
#define LED_DATA6_COM6SEG5              ((uint32_t)1<<(LED_DATA6_COM6SEG5_POS))
#define LED_DATA6_COM6SEG6              ((uint32_t)1<<(LED_DATA6_COM6SEG6_POS))
#define LED_DATA6_COM6SEG7              ((uint32_t)1<<(LED_DATA6_COM6SEG7_POS))
#define LED_DATA6_COM6SEG8              ((uint32_t)1<<(LED_DATA6_COM6SEG8_POS))
#define LED_DATA6_COM6SEG9              ((uint32_t)1<<(LED_DATA6_COM6SEG9_POS))
#define LED_DATA6_COM6SEG10             ((uint32_t)1<<(LED_DATA6_COM6SEG10_POS))
#define LED_DATA6_COM6SEG11             ((uint32_t)1<<(LED_DATA6_COM6SEG11_POS))
#define LED_DATA6_COM6SEG12             ((uint32_t)1<<(LED_DATA6_COM6SEG12_POS))
#define LED_DATA6_COM6SEG13             ((uint32_t)1<<(LED_DATA6_COM6SEG13_POS))
#define LED_DATA6_COM6SEG14             ((uint32_t)1<<(LED_DATA6_COM6SEG14_POS))
#define LED_DATA6_COM6SEG15             ((uint32_t)1<<(LED_DATA6_COM6SEG15_POS))

/* LED_DATA7 λ�� */
#define LED_DATA7_COM7SEG0_POS       	(0)
#define LED_DATA7_COM7SEG1_POS          (1)
#define LED_DATA7_COM7SEG2_POS          (2)
#define LED_DATA7_COM7SEG3_POS          (3)
#define LED_DATA7_COM7SEG4_POS          (4)
#define LED_DATA7_COM7SEG5_POS          (5)
#define LED_DATA7_COM7SEG6_POS          (6)
#define LED_DATA7_COM7SEG7_POS      	(7)
#define LED_DATA7_COM7SEG8_POS          (8)
#define LED_DATA7_COM7SEG9_POS          (9)
#define LED_DATA7_COM7SEG10_POS         (10)
#define LED_DATA7_COM7SEG11_POS         (11)
#define LED_DATA7_COM7SEG12_POS      	(12)
#define LED_DATA7_COM7SEG13_POS         (13)
#define LED_DATA7_COM7SEG14_POS         (14)
#define LED_DATA7_COM7SEG15_POS         (15)
#define LED_DATA7_COM7SEG               ((uint32_t)0xffff<<(LED_DATA7_COM7SEG0_POS))
#define LED_DATA7_COM7SEG0              ((uint32_t)1<<(LED_DATA7_COM7SEG0_POS))
#define LED_DATA7_COM7SEG1              ((uint32_t)1<<(LED_DATA7_COM7SEG1_POS))
#define LED_DATA7_COM7SEG2              ((uint32_t)1<<(LED_DATA7_COM7SEG2_POS))
#define LED_DATA7_COM7SEG3              ((uint32_t)1<<(LED_DATA7_COM7SEG3_POS))
#define LED_DATA7_COM7SEG4              ((uint32_t)1<<(LED_DATA7_COM7SEG4_POS))
#define LED_DATA7_COM7SEG5              ((uint32_t)1<<(LED_DATA7_COM7SEG5_POS))
#define LED_DATA7_COM7SEG6              ((uint32_t)1<<(LED_DATA7_COM7SEG6_POS))
#define LED_DATA7_COM7SEG7              ((uint32_t)1<<(LED_DATA7_COM7SEG7_POS))
#define LED_DATA7_COM7SEG8              ((uint32_t)1<<(LED_DATA7_COM7SEG8_POS))
#define LED_DATA7_COM7SEG9              ((uint32_t)1<<(LED_DATA7_COM7SEG9_POS))
#define LED_DATA7_COM7SEG10             ((uint32_t)1<<(LED_DATA7_COM7SEG10_POS))
#define LED_DATA7_COM7SEG11             ((uint32_t)1<<(LED_DATA7_COM7SEG11_POS))
#define LED_DATA7_COM7SEG12             ((uint32_t)1<<(LED_DATA7_COM7SEG12_POS))
#define LED_DATA7_COM7SEG13             ((uint32_t)1<<(LED_DATA7_COM7SEG13_POS))
#define LED_DATA7_COM7SEG14             ((uint32_t)1<<(LED_DATA7_COM7SEG14_POS))
#define LED_DATA7_COM7SEG15             ((uint32_t)1<<(LED_DATA7_COM7SEG15_POS))

/* LED_CTL0 λ�� */
#define LED_CTL0_CKS0_0_POS       		(0)
#define LED_CTL0_CKS0_1_POS       		(1)
#define LED_CTL0_CKS0_2_POS       		(2)
#define LED_CTL0_CKS0_3_POS       		(3)
#define LED_CTL0_CKS1_0_POS       		(4)
#define LED_CTL0_CKS1_1_POS       		(5)
#define LED_CTL0_CKS1_2_POS       		(6)
#define LED_CTL0_CKS1_3_POS       		(7)
#define LED_CTL0_CS0_POS       		    (8)
#define LED_CTL0_CS1_POS       		    (9)
#define LED_CTL0_PNS0_POS               (10)
#define LED_CTL0_PNS1_POS               (11)
#define LED_CTL0_LEDBR_POS              (14)
#define LED_CTL0_LEDEN_POS              (15)
#define LED_CTL0_CKS0                   ((uint32_t)0xF<<(LED_CTL0_CKS0_0_POS))
#define LED_CTL0_CKS0_0                 ((uint32_t)1<<(LED_CTL0_CKS0_0_POS))
#define LED_CTL0_CKS0_1                 ((uint32_t)1<<(LED_CTL0_CKS0_1_POS))
#define LED_CTL0_CKS0_2                 ((uint32_t)1<<(LED_CTL0_CKS0_2_POS))
#define LED_CTL0_CKS0_3                 ((uint32_t)1<<(LED_CTL0_CKS0_3_POS))
#define LED_CTL0_CKS1                   ((uint32_t)0xf<<(LED_CTL0_CKS1_0_POS))
#define LED_CTL0_CKS1_0                 ((uint32_t)1<<(LED_CTL0_CKS1_0_POS))
#define LED_CTL0_CKS1_1                 ((uint32_t)1<<(LED_CTL0_CKS1_1_POS))
#define LED_CTL0_CKS1_2                 ((uint32_t)1<<(LED_CTL0_CKS1_2_POS))
#define LED_CTL0_CKS1_3                 ((uint32_t)1<<(LED_CTL0_CKS1_3_POS))
#define LED_CTL0_CS                     ((uint32_t)0x3<<(LED_CTL0_CS0_POS))
#define LED_CTL0_CS0                    ((uint32_t)1<<(LED_CTL0_CS0_POS))
#define LED_CTL0_CS1                    ((uint32_t)1<<(LED_CTL0_CS1_POS))
#define LED_CTL0_PNS                    ((uint32_t)0x3<<(LED_CTL0_PNS0_POS))
#define LED_CTL0_PNS0                   ((uint32_t)1<<(LED_CTL0_PNS0_POS))
#define LED_CTL0_PNS1                   ((uint32_t)1<<(LED_CTL0_PNS1_POS))
#define LED_CTL0_LEDBR                  ((uint32_t)1<<(LED_CTL0_LEDBR_POS))
#define LED_CTL0_LEDEN                  ((uint32_t)1<<(LED_CTL0_LEDEN_POS))

/* LED_CTL1 λ�� */
#define LED_CTL1_FRAMEF_POS       		(0)
#define LED_CTL1_LUM0_POS       		(2)
#define LED_CTL1_LUM1_POS       		(3)
#define LED_CTL1_LUM2_POS       		(4)
#define LED_CTL1_CCOMEN0_POS       		(5)
#define LED_CTL1_CCOMEN1_POS       		(6)
#define LED_CTL1_CCOMEN2_POS       		(7)
#define LED_CTL1_SEG8EN_POS       		(8)
#define LED_CTL1_SEG12EN_POS       		(9)
#define LED_CTL1_SEG16EN_POS            (10)
#define LED_CTL1_FRAMEF                 ((uint32_t)1<<(LED_CTL1_FRAMEF_POS))
#define LED_CTL1_LUM                    ((uint32_t)7<<(LED_CTL1_LUM0_POS))
#define LED_CTL1_LUM0                   ((uint32_t)1<<(LED_CTL1_LUM0_POS))
#define LED_CTL1_LUM1                   ((uint32_t)1<<(LED_CTL1_LUM1_POS))
#define LED_CTL1_LUM2                   ((uint32_t)1<<(LED_CTL1_LUM2_POS))
#define LED_CTL1_CCOMEN                 ((uint32_t)7<<(LED_CTL1_CCOMEN0_POS))
#define LED_CTL1_CCOMEN0                ((uint32_t)1<<(LED_CTL1_CCOMEN0_POS))
#define LED_CTL1_CCOMEN1                ((uint32_t)1<<(LED_CTL1_CCOMEN1_POS))
#define LED_CTL1_CCOMEN2                ((uint32_t)1<<(LED_CTL1_CCOMEN2_POS))
#define LED_CTL1_SEG8EN                 ((uint32_t)1<<(LED_CTL1_SEG8EN_POS))
#define LED_CTL1_SEG12EN                ((uint32_t)1<<(LED_CTL1_SEG12EN_POS))
#define LED_CTL1_SEG16EN                ((uint32_t)1<<(LED_CTL1_SEG16EN_POS))

#endif //KF32F_Periph_led
/* LED ������� */



/* ----------------------------------------------------------------------------
   -- EXIC�ӿ� (EXIC)
   ---------------------------------------------------------------------------- */
/* EXIC����ģ��Ĵ����ڴ�ṹ */
typedef struct EXIC_MemMap {
    volatile uint32_t CTL0;          /* EXIC���ݼĴ���0, ƫ��:0x00 */
    volatile uint32_t CTL1;          /* EXIC���ݼĴ���1, ƫ��:0x04 */
    volatile uint32_t STATE;         /* EXIC���ݼĴ���2, ƫ��:0x08 */
    		 uint32_t RESERVED1;     /* ����, ƫ��:0x0C */
    volatile uint32_t WRITEBUF;      /* EXIC���ݼĴ���3, ƫ��:0x10 */
    volatile uint32_t READBUF;       /* EXIC���ݼĴ���4, ƫ��:0x14 */

}EXIC_SFRmap;
/* ----------------------------------------------------------------------------
   -- EXIC - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */
#ifdef KF32F_Periph_exic
/* EXIC - �Ĵ�����ڵ�ַ */
#define EXIC_ADDR                      ((uint32_t)0x40002800)
#define EXIC_SFR                       ((EXIC_SFRmap *) EXIC_ADDR)
#endif

/* EXIC - �Ĵ������ */
#define EXIC_CTL0                      (EXIC_SFR->CTL0)
#define EXIC_CTL1                      (EXIC_SFR->CTL1)
#define EXIC_STATE                     (EXIC_SFR->STATE)
#define EXIC_WRITEBUF                  (EXIC_SFR->WRITEBUF)
#define EXIC_READBUF                   (EXIC_SFR->READBUF)

/* EXIC_CTL0 λ�� */
#define EXIC_CTL0_EXICEN_POS       		(0)
#define EXIC_CTL0_CSEN_POS              (1)
#define EXIC_CTL0_DCSEL_POS             (2)
#define EXIC_CTL0_WRITEEN_POS           (3)
#define EXIC_CTL0_READEN_POS            (4)
#define EXIC_CTL0_TDMAEN_POS            (8)
#define EXIC_CTL0_RDMAEN_POS            (9)
#define EXIC_CTL0_WENDIE_POS      	    (16)
#define EXIC_CTL0_RENDIE_POS            (17)
#define EXIC_CTL0_WRITE1EN_POS          (28)
#define EXIC_CTL0_READ1EN_POS           (29)
#define EXIC_CTL0_DATATR_POS            (30)
#define EXIC_CTL0_MODESEL_POS      	    (31)
#define EXIC_CTL0_EXICEN                ((uint32_t)1<<(EXIC_CTL0_EXICEN_POS))
#define EXIC_CTL0_CSEN                  ((uint32_t)1<<(EXIC_CTL0_CSEN_POS))
#define EXIC_CTL0_DCSEL                 ((uint32_t)1<<(EXIC_CTL0_DCSEL_POS))
#define EXIC_CTL0_WRITEEN               ((uint32_t)1<<(EXIC_CTL0_WRITEEN_POS))
#define EXIC_CTL0_READEN                ((uint32_t)1<<(EXIC_CTL0_READEN_POS))
#define EXIC_CTL0_TDMAEN                ((uint32_t)1<<(EXIC_CTL0_TDMAEN_POS))
#define EXIC_CTL0_RDMAEN                ((uint32_t)1<<(EXIC_CTL0_RDMAEN_POS))
#define EXIC_CTL0_WENDIN                ((uint32_t)1<<(EXIC_CTL0_WENDIE_POS))
#define EXIC_CTL0_RENDIE                ((uint32_t)1<<(EXIC_CTL0_RENDIE_POS))
#define EXIC_CTL0_WRITE1EN              ((uint32_t)1<<(EXIC_CTL0_WRITE1EN_POS))
#define EXIC_CTL0_READ1EN               ((uint32_t)1<<(EXIC_CTL0_READ1EN_POS))
#define EXIC_CTL0_DATATR                ((uint32_t)1<<(EXIC_CTL0_DATATR_POS))
#define EXIC_CTL0_MODESEL               ((uint32_t)1<<(EXIC_CTL0_MODESEL_POS))

/* EXIC_CTL1 λ�� */
#define EXIC_CTL1_EXICCS0_POS       	(0)
#define EXIC_CTL1_EXICCS1_POS           (1)
#define EXIC_CTL1_PULSEWIDTH0_POS       (4)
#define EXIC_CTL1_PULSEWIDTH1_POS       (5)
#define EXIC_CTL1_PULSEWIDTH2_POS       (6)
#define EXIC_CTL1_PULSEWIDTH3_POS       (7)
#define EXIC_CTL1_EXICCS                ((uint32_t)3<<(EXIC_CTL1_EXICCS0_POS))
#define EXIC_CTL1_EXICCS0               ((uint32_t)1<<(EXIC_CTL1_EXICCS0_POS))
#define EXIC_CTL1_EXICCS1               ((uint32_t)1<<(EXIC_CTL1_EXICCS1_POS))
#define EXIC_CTL1_PULSEWIDTH            ((uint32_t)0xf<<(EXIC_CTL1_PULSEWIDTH0_POS))
#define EXIC_CTL1_PULSEWIDTH0           ((uint32_t)1<<(EXIC_CTL1_PULSEWIDTH0_POS))
#define EXIC_CTL1_PULSEWIDTH1           ((uint32_t)1<<(EXIC_CTL1_PULSEWIDTH1_POS))
#define EXIC_CTL1_PULSEWIDTH2           ((uint32_t)1<<(EXIC_CTL1_PULSEWIDTH2_POS))
#define EXIC_CTL1_PULSEWIDTH3           ((uint32_t)1<<(EXIC_CTL1_PULSEWIDTH3_POS))

/* EXIC_STATE λ�� */
#define EXIC_STATE_WENDIF_POS       	(0)
#define EXIC_STATE_RENDIF_POS           (1)
#define EXIC_STATE_WENDIF               ((uint32_t)1<<(EXIC_STATE_WENDIF_POS))
#define EXIC_STATE_RENDIF               ((uint32_t)1<<(EXIC_STATE_RENDIF_POS))


/* ----------------------------------------------------------------------------
   -- CFGLģ�� (CFGL)
   ---------------------------------------------------------------------------- */
/* CFGL����ģ��Ĵ����ڴ�ṹ */
typedef struct CFGL_MemMap {
    volatile uint32_t CTL0;          /* CFGL���ƼĴ���0, ƫ��:0x00 */
    volatile uint32_t CTL1;          /* CFGL���ƼĴ���1, ƫ��:0x04 */
    volatile uint32_t IFR;           //(0x40002990)
}CFGL_SFRmap;
/* ----------------------------------------------------------------------------
   -- CFGL - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */

/* CFGL - �Ĵ�����ڵ�ַ */
#ifdef KF32F_Periph_cfgl
#define CFGL1_ADDR                      ((uint32_t)0x40002980)
#define CFGL2_ADDR                      ((uint32_t)0x40002988)
#define CFGL1_SFR                       ((CFGL_SFRmap *) CFGL1_ADDR)
#define CFGL2_SFR                       ((CFGL_SFRmap *) CFGL2_ADDR)
#define CFGLIFR_ADDR                    ((uint32_t)0x40002988)
#define CFGLIFR_SFR                     ((CFGL_SFRmap *) CFGLIFR_ADDR)

/* CFGL - �Ĵ������ */
#define CFGL1_CTL0                      (CFGL1_SFR->CTL0)
#define CFGL1_CTL1                      (CFGL1_SFR->CTL1)
#define CFGL2_CTL0                      (CFGL2_SFR->CTL0)
#define CFGL2_CTL1                      (CFGL2_SFR->CTL1)
#define CFGL_IFR                        (CFGLIFR_SFR->IFR)
#endif
/* CFGL_CTL0 λ�� */
#define CFGL_CTL0_TPSEL0_POS       		(0)
#define CFGL_CTL0_TPSEL1_POS            (1)
#define CFGL_CTL0_TPSEL2_POS            (2)
#define CFGL_CTL0_REGIN_POS             (3)
#define CFGL_CTL0_D1S0_POS              (4)
#define CFGL_CTL0_D1S1_POS              (5)
#define CFGL_CTL0_D1S2_POS              (6)
#define CFGL_CTL0_D2S0_POS      	    (8)
#define CFGL_CTL0_D2S1_POS              (9)
#define CFGL_CTL0_D2S2_POS              (10)
#define CFGL_CTL0_D3S0_POS              (12)
#define CFGL_CTL0_D3S1_POS              (13)
#define CFGL_CTL0_D3S2_POS      	    (14)
#define CFGL_CTL0_D4S0_POS              (16)
#define CFGL_CTL0_D4S1_POS              (17)
#define CFGL_CTL0_D4S2_POS      	    (18)
#define CFGL_CTL0_G1POL_POS      	    (20)
#define CFGL_CTL0_G2POL_POS      	    (21)
#define CFGL_CTL0_G3POL_POS      	    (22)
#define CFGL_CTL0_G4POL_POS      	    (23)
#define CFGL_CTL0_POL_POS      	        (24)
#define CFGL_CTL0_MD0_POS      	        (25)
#define CFGL_CTL0_MD1_POS      	        (26)
#define CFGL_CTL0_MD2_POS      	        (27)
#define CFGL_CTL0_INTN_POS      	    (28)
#define CFGL_CTL0_INTP_POS      	    (29)
#define CFGL_CTL0_OE_POS      	        (30)
#define CFGL_CTL0_EN_POS      	        (31)
#define CFGL_CTL0_TPSEL                 ((uint32_t)7<<(CFGL_CTL0_TPSEL0_POS))
#define CFGL_CTL0_TPSEL0                ((uint32_t)1<<(CFGL_CTL0_TPSEL0_POS))
#define CFGL_CTL0_TPSEL1                ((uint32_t)1<<(CFGL_CTL0_TPSEL1_POS))
#define CFGL_CTL0_TPSEL2                ((uint32_t)1<<(CFGL_CTL0_TPSEL2_POS))
#define CFGL_CTL0_REGIN                 ((uint32_t)1<<(CFGL_CTL0_REGIN_POS))
#define CFGL_CTL0_D1S                   ((uint32_t)7<<(CFGL_CTL0_D1S0_POS))
#define CFGL_CTL0_D1S0                  ((uint32_t)1<<(CFGL_CTL0_D1S0_POS))
#define CFGL_CTL0_D1S1                  ((uint32_t)1<<(CFGL_CTL0_D1S1_POS))
#define CFGL_CTL0_D1S2                  ((uint32_t)1<<(CFGL_CTL0_D1S2_POS))
#define CFGL_CTL0_D2S                   ((uint32_t)7<<(CFGL_CTL0_D2S0_POS))
#define CFGL_CTL0_D2S0                  ((uint32_t)1<<(CFGL_CTL0_D2S0_POS))
#define CFGL_CTL0_D2S1                  ((uint32_t)1<<(CFGL_CTL0_D2S1_POS))
#define CFGL_CTL0_D2S2                  ((uint32_t)1<<(CFGL_CTL0_D2S2_POS))
#define CFGL_CTL0_D3S                   ((uint32_t)7<<(CFGL_CTL0_D3S0_POS))
#define CFGL_CTL0_D3S0                  ((uint32_t)1<<(CFGL_CTL0_D3S0_POS))
#define CFGL_CTL0_D3S1                  ((uint32_t)1<<(CFGL_CTL0_D3S1_POS))
#define CFGL_CTL0_D3S2                  ((uint32_t)1<<(CFGL_CTL0_D3S2_POS))
#define CFGL_CTL0_D4S                   ((uint32_t)7<<(CFGL_CTL0_D4S0_POS))
#define CFGL_CTL0_D4S0                  ((uint32_t)1<<(CFGL_CTL0_D4S0_POS))
#define CFGL_CTL0_D4S1                  ((uint32_t)1<<(CFGL_CTL0_D4S1_POS))
#define CFGL_CTL0_D4S2                  ((uint32_t)1<<(CFGL_CTL0_D4S2_POS))
#define CFGL_CTL0_G1POL                 ((uint32_t)1<<(CFGL_CTL0_G1POL_POS))
#define CFGL_CTL0_G2POL                 ((uint32_t)1<<(CFGL_CTL0_G2POL_POS))
#define CFGL_CTL0_G3POL                 ((uint32_t)1<<(CFGL_CTL0_G3POL_POS))
#define CFGL_CTL0_G4POL                 ((uint32_t)1<<(CFGL_CTL0_G4POL_POS))
#define CFGL_CTL0_POL                   ((uint32_t)1<<(CFGL_CTL0_POL_POS))
#define CFGL_CTL0_MD                    ((uint32_t)7<<(CFGL_CTL0_MD0_POS))
#define CFGL_CTL0_MD0                   ((uint32_t)1<<(CFGL_CTL0_MD0_POS))
#define CFGL_CTL0_MD1                   ((uint32_t)1<<(CFGL_CTL0_MD1_POS))
#define CFGL_CTL0_MD2                   ((uint32_t)1<<(CFGL_CTL0_MD2_POS))
#define CFGL_CTL0_INTN                  ((uint32_t)1<<(CFGL_CTL0_INTN_POS))
#define CFGL_CTL0_INTP                  ((uint32_t)1<<(CFGL_CTL0_INTP_POS))
#define CFGL_CTL0_OE                    ((uint32_t)1<<(CFGL_CTL0_OE_POS))
#define CFGL_CTL0_EN                    ((uint32_t)1<<(CFGL_CTL0_EN_POS))

/* CFGL_CTL1 λ�� */
#define CFGL_CTL1_G1D1N_POS       		(0)
#define CFGL_CTL1_G1D1T_POS             (1)
#define CFGL_CTL1_G1D2N_POS             (2)
#define CFGL_CTL1_G1D2T_POS             (3)
#define CFGL_CTL1_G1D3N_POS             (4)
#define CFGL_CTL1_G1D3T_POS             (5)
#define CFGL_CTL1_G1D4N_POS             (6)
#define CFGL_CTL1_G1D4T_POS      	    (7)
#define CFGL_CTL1_G2D1N_POS             (8)
#define CFGL_CTL1_G2D1T_POS             (9)
#define CFGL_CTL1_G2D2N_POS             (10)
#define CFGL_CTL1_G2D2T_POS             (11)
#define CFGL_CTL1_G2D3N_POS      	    (12)
#define CFGL_CTL1_G2D3T_POS             (13)
#define CFGL_CTL1_G2D4N_POS             (14)
#define CFGL_CTL1_G2D4T_POS      	    (15)
#define CFGL_CTL1_G3D1N_POS      	    (16)
#define CFGL_CTL1_G3D1T_POS      	    (17)
#define CFGL_CTL1_G3D2N_POS      	    (18)
#define CFGL_CTL1_G3D2T_POS      	    (19)
#define CFGL_CTL1_G3D3N_POS      	    (20)
#define CFGL_CTL1_G3D3T_POS      	    (21)
#define CFGL_CTL1_G3D4N_POS      	    (22)
#define CFGL_CTL1_G3D4T_POS      	    (23)
#define CFGL_CTL1_G4D1N_POS      	    (24)
#define CFGL_CTL1_G4D1T_POS      	    (25)
#define CFGL_CTL1_G4D2N_POS      	    (26)
#define CFGL_CTL1_G4D2T_POS      	    (27)
#define CFGL_CTL1_G4D3N_POS      	    (28)
#define CFGL_CTL1_G4D3T_POS      	    (29)
#define CFGL_CTL1_G4D4N_POS      	    (30)
#define CFGL_CTL1_G4D4T_POS      	    (31)
#define CFGL_CTL1_G1D1N                 ((uint32_t)1<<(CFGL_CTL1_G1D1N_POS))
#define CFGL_CTL1_G1D1T                 ((uint32_t)1<<(CFGL_CTL1_G1D1T_POS))
#define CFGL_CTL1_G1D2N                 ((uint32_t)1<<(CFGL_CTL1_G1D2N_POS))
#define CFGL_CTL1_G1D2T                 ((uint32_t)1<<(CFGL_CTL1_G1D2T_POS))
#define CFGL_CTL1_G1D3N                 ((uint32_t)1<<(CFGL_CTL1_G1D3N_POS))
#define CFGL_CTL1_G1D3T                 ((uint32_t)1<<(CFGL_CTL1_G1D3T_POS))
#define CFGL_CTL1_G1D4N                 ((uint32_t)1<<(CFGL_CTL1_G1D4N_POS))
#define CFGL_CTL1_G1D4T                 ((uint32_t)1<<(CFGL_CTL1_G1D4T_POS))
#define CFGL_CTL1_G2D1N                 ((uint32_t)1<<(CFGL_CTL1_G2D1N_POS))
#define CFGL_CTL1_G2D1T                 ((uint32_t)1<<(CFGL_CTL1_G2D1T_POS))
#define CFGL_CTL1_G2D2N                 ((uint32_t)1<<(CFGL_CTL1_G2D2N_POS))
#define CFGL_CTL1_G2D2T                 ((uint32_t)1<<(CFGL_CTL1_G2D2T_POS))
#define CFGL_CTL1_G2D3N                 ((uint32_t)1<<(CFGL_CTL1_G2D3N_POS))
#define CFGL_CTL1_G2D3T                 ((uint32_t)1<<(CFGL_CTL1_G2D3T_POS))
#define CFGL_CTL1_G2D4N                 ((uint32_t)1<<(CFGL_CTL1_G2D4N_POS))
#define CFGL_CTL1_G2D4T                 ((uint32_t)1<<(CFGL_CTL1_G2D4T_POS))
#define CFGL_CTL1_G3D1N                 ((uint32_t)1<<(CFGL_CTL1_G3D1N_POS))
#define CFGL_CTL1_G3D1T                 ((uint32_t)1<<(CFGL_CTL1_G3D1T_POS))
#define CFGL_CTL1_G3D2N                 ((uint32_t)1<<(CFGL_CTL1_G3D2N_POS))
#define CFGL_CTL1_G3D2T                 ((uint32_t)1<<(CFGL_CTL1_G3D2T_POS))
#define CFGL_CTL1_G3D3N                 ((uint32_t)1<<(CFGL_CTL1_G3D3N_POS))
#define CFGL_CTL1_G3D3T                 ((uint32_t)1<<(CFGL_CTL1_G3D3T_POS))
#define CFGL_CTL1_G3D4N                 ((uint32_t)1<<(CFGL_CTL1_G3D4N_POS))
#define CFGL_CTL1_G3D4T                 ((uint32_t)1<<(CFGL_CTL1_G3D4T_POS))
#define CFGL_CTL1_G4D1N                 ((uint32_t)1<<(CFGL_CTL1_G4D1N_POS))
#define CFGL_CTL1_G4D1T                 ((uint32_t)1<<(CFGL_CTL1_G4D1T_POS))
#define CFGL_CTL1_G4D2N                 ((uint32_t)1<<(CFGL_CTL1_G4D2N_POS))
#define CFGL_CTL1_G4D2T                 ((uint32_t)1<<(CFGL_CTL1_G4D2T_POS))
#define CFGL_CTL1_G4D3N                 ((uint32_t)1<<(CFGL_CTL1_G4D3N_POS))
#define CFGL_CTL1_G4D3T                 ((uint32_t)1<<(CFGL_CTL1_G4D3T_POS))
#define CFGL_CTL1_G4D4N                 ((uint32_t)1<<(CFGL_CTL1_G4D4N_POS))
#define CFGL_CTL1_G4D4T                 ((uint32_t)1<<(CFGL_CTL1_G4D4T_POS))

/* CFGL_IFR λ�� */
#define CFGL_IFR_CFGL1OUT_POS       	(0)
#define CFGL_IFR_CFGL2OUT_POS           (1)
#define CFGL_IFR_CFGL1IF_POS            (8)
#define CFGL_IFR_CFGL2IF_POS            (9)
#define CFGL_IFR_CFGL1IE_POS            (28)
#define CFGL_IFR_CFGL2IE_POS            (29)
#define CFGL_IFR_CFGL1SYNCEN_POS        (30)
#define CFGL_IFR_CFGL2SYNCEN_POS      	(31)
#define CFGL_IFR_CFGL1OUT               ((uint32_t)1<<(CFGL_IFR_CFGL1OUT_POS))
#define CFGL_IFR_CFGL2OUT               ((uint32_t)1<<(CFGL_IFR_CFGL2OUT_POS))
#define CFGL_IFR_CFGL1IF                ((uint32_t)1<<(CFGL_IFR_CFGL1IF_POS))
#define CFGL_IFR_CFGL2IF                ((uint32_t)1<<(CFGL_IFR_CFGL2IF_POS))
#define CFGL_IFR_CFGL1IE                ((uint32_t)7<<(CFGL_IFR_CFGL1IE_POS))
#define CFGL_IFR_CFGL2IE                ((uint32_t)1<<(CFGL_IFR_CFGL2IE_POS))
#define CFGL_IFR_CFGL1SYNCEN            ((uint32_t)1<<(CFGL_IFR_CFGL1SYNCEN_POS))
#define CFGL_IFR_CFGL2SYNCEN            ((uint32_t)1<<(CFGL_IFR_CFGL2SYNCEN_POS))


/* ----------------------------------------------------------------------------
   -- �˷�ģ�� (OP)
   ---------------------------------------------------------------------------- */
#ifdef KF32F_Periph_op
/* OP����ģ��Ĵ����ڴ�ṹ */
typedef struct OP_MemMap {
    volatile uint32_t CAL;          /* ����Ŵ���У׼�Ĵ���, ƫ��:0x00 */
    volatile uint32_t CTL0;         /* ����Ŵ������ƼĴ���0, ƫ��:0x04 */
    volatile uint32_t CTL1;         /* ����Ŵ������ƼĴ���1, ƫ��:0x08 */
}OP_SFRmap;
/* ----------------------------------------------------------------------------
   -- OP - �Ĵ�����ں�
   ---------------------------------------------------------------------------- */

/* OP - �Ĵ�����ڵ�ַ */
#define OP_ADDR                    ((uint32_t)0x40002A00)
#define OP_SFR                     ((OP_SFRmap *) OP_ADDR)

/* OP - �Ĵ������ */
#define OP_CAL                     (OP_SFR->CAL)
#define OP_CTL0                    (OP_SFR->CTL0)
#define OP_CTL1                    (OP_SFR->CTL1)

/* OP1_CAL λ�� */
#define OP_CAL_OP0CAL0_POS         (0)
#define OP_CAL_OP0CAL1_POS         (1)
#define OP_CAL_OP0CAL2_POS         (2)
#define OP_CAL_OP0CAL3_POS         (3)
#define OP_CAL_OP0CAL4_POS         (4)
#define OP_CAL_OP0CAL5_POS         (5)
#define OP_CAL_OP1CAL0_POS         (8)
#define OP_CAL_OP1CAL1_POS         (9)
#define OP_CAL_OP1CAL2_POS         (10)
#define OP_CAL_OP1CAL3_POS         (11)
#define OP_CAL_OP1CAL4_POS         (12)
#define OP_CAL_OP1CAL5_POS         (13)
#define OP_CAL_OP2CAL0_POS         (16)
#define OP_CAL_OP2CAL1_POS         (17)
#define OP_CAL_OP2CAL2_POS         (18)
#define OP_CAL_OP2CAL3_POS         (19)
#define OP_CAL_OP2CAL4_POS         (20)
#define OP_CAL_OP2CAL5_POS         (21)
#define OP_CAL_OP3CAL0_POS         (24)
#define OP_CAL_OP3CAL1_POS         (25)
#define OP_CAL_OP3CAL2_POS         (26)
#define OP_CAL_OP3CAL3_POS         (27)
#define OP_CAL_OP3CAL4_POS         (28)
#define OP_CAL_OP3CAL5_POS         (29)
#define OP_CAL_OP0CAL              ((uint32_t)0x3f<<(OP_CAL_OP0CAL0_POS))
#define OP_CAL_OP0CAL0             ((uint32_t)1<<(OP_CAL_OP0CAL0_POS))
#define OP_CAL_OP0CAL1             ((uint32_t)1<<(OP_CAL_OP0CAL1_POS))
#define OP_CAL_OP0CAL2             ((uint32_t)1<<(OP_CAL_OP0CAL2_POS))
#define OP_CAL_OP0CAL3             ((uint32_t)1<<(OP_CAL_OP0CAL3_POS))
#define OP_CAL_OP0CAL4             ((uint32_t)1<<(OP_CAL_OP0CAL4_POS))
#define OP_CAL_OP0CAL5			   ((uint32_t)1<<(OP_CAL_OP0CAL5_POS))
#define OP_CAL_OP1CAL              ((uint32_t)0x3f<<(OP_CAL_OP1CAL0_POS))
#define OP_CAL_OP1CAL0             ((uint32_t)1<<(OP_CAL_OP1CAL0_POS))
#define OP_CAL_OP1CAL1             ((uint32_t)1<<(OP_CAL_OP1CAL1_POS))
#define OP_CAL_OP1CAL2             ((uint32_t)1<<(OP_CAL_OP1CAL2_POS))
#define OP_CAL_OP1CAL3             ((uint32_t)1<<(OP_CAL_OP1CAL3_POS))
#define OP_CAL_OP1CAL4             ((uint32_t)1<<(OP_CAL_OP1CAL4_POS))
#define OP_CAL_OP1CAL5			   ((uint32_t)1<<(OP_CAL_OP1CAL5_POS))
#define OP_CAL_OP2CAL              ((uint32_t)0x3f<<(OP_CAL_OP2CAL0_POS))
#define OP_CAL_OP2CAL0             ((uint32_t)1<<(OP_CAL_OP2CAL0_POS))
#define OP_CAL_OP2CAL1             ((uint32_t)1<<(OP_CAL_OP2CAL1_POS))
#define OP_CAL_OP2CAL2             ((uint32_t)1<<(OP_CAL_OP2CAL2_POS))
#define OP_CAL_OP2CAL3             ((uint32_t)1<<(OP_CAL_OP2CAL3_POS))
#define OP_CAL_OP2CAL4             ((uint32_t)1<<(OP_CAL_OP2CAL4_POS))
#define OP_CAL_OP2CAL5			   ((uint32_t)1<<(OP_CAL_OP2CAL5_POS))
#define OP_CAL_OP3CAL              ((uint32_t)0x3f<<(OP_CAL_OP3CAL0_POS))
#define OP_CAL_OP3CAL0             ((uint32_t)1<<(OP_CAL_OP3CAL0_POS))
#define OP_CAL_OP3CAL1             ((uint32_t)1<<(OP_CAL_OP3CAL1_POS))
#define OP_CAL_OP3CAL2             ((uint32_t)1<<(OP_CAL_OP3CAL2_POS))
#define OP_CAL_OP3CAL3             ((uint32_t)1<<(OP_CAL_OP3CAL3_POS))
#define OP_CAL_OP3CAL4             ((uint32_t)1<<(OP_CAL_OP3CAL4_POS))
#define OP_CAL_OP3CAL5			   ((uint32_t)1<<(OP_CAL_OP3CAL5_POS))

/* OP_CTL0 λ�� */
#define OP_CTL0_OP0EN_POS          (0)
#define OP_CTL0_OP1EN_POS          (1)
#define OP_CTL0_OP2EN_POS          (2)
#define OP_CTL0_OP3EN_POS          (3)
#define OP_CTL0_OP0OUTEN_POS       (4)
#define OP_CTL0_OP1OUTEN_POS       (5)
#define OP_CTL0_OP2OUTEN_POS       (6)
#define OP_CTL0_OP3OUTEN_POS       (7)
#define OP_CTL0_OP3VINPSEL0_POS    (8)
#define OP_CTL0_OP3VINPSEL1_POS    (9)
#define OP_CTL0_OP0GAIN10X_POS     (16)
#define OP_CTL0_OP0GAIN20X_POS     (17)
#define OP_CTL0_OP0GAIN40X_POS     (18)
#define OP_CTL0_OP0GAIN80X_POS     (19)
#define OP_CTL0_OP1GAIN10X_POS     (20)
#define OP_CTL0_OP1GAIN20X_POS     (21)
#define OP_CTL0_OP1GAIN40X_POS     (22)
#define OP_CTL0_OP1GAIN80X_POS     (23)
#define OP_CTL0_OP2GAIN10X_POS     (24)
#define OP_CTL0_OP2GAIN20X_POS     (25)
#define OP_CTL0_OP2GAIN40X_POS     (26)
#define OP_CTL0_OP2GAIN80X_POS     (27)
#define OP_CTL0_OP0EN              ((uint32_t)1<<(OP_CTL0_OP0EN_POS))
#define OP_CTL0_OP1EN              ((uint32_t)1<<(OP_CTL0_OP1EN_POS))
#define OP_CTL0_OP2EN              ((uint32_t)1<<(OP_CTL0_OP2EN_POS))
#define OP_CTL0_OP3EN              ((uint32_t)1<<(OP_CTL0_OP3EN_POS))
#define OP_CTL0_OP0OUTEN           ((uint32_t)1<<(OP_CTL0_OP0OUTEN_POS))
#define OP_CTL0_OP1OUTEN		   ((uint32_t)1<<(OP_CTL0_OP1OUTEN_POS))
#define OP_CTL0_OP2OUTEN           ((uint32_t)1<<(OP_CTL0_OP2OUTEN_POS))
#define OP_CTL0_OP3OUTEN           ((uint32_t)1<<(OP_CTL0_OP3OUTEN_POS))
#define OP_CTL0_OP3VINPSEL         ((uint32_t)0x3<<(OP_CTL0_OP3VINPSEL0_POS))
#define OP_CTL0_OP3VINPSEL0        ((uint32_t)1<<(OP_CTL0_OP3VINPSEL0_POS))
#define OP_CTL0_OP3VINPSEL1        ((uint32_t)1<<(OP_CTL0_OP3VINPSEL1_POS))
#define OP_CTL0_OP0GAIN            ((uint32_t)0xf<<(OP_CTL0_OP0GAIN10X_POS))
#define OP_CTL0_OP0GAIN10X         ((uint32_t)1<<(OP_CTL0_OP0GAIN10X_POS))
#define OP_CTL0_OP0GAIN20X		   ((uint32_t)1<<(OP_CTL0_OP0GAIN20X_POS))
#define OP_CTL0_OP0GAIN40X         ((uint32_t)1<<(OP_CTL0_OP0GAIN40X_POS))
#define OP_CTL0_OP0GAIN80X         ((uint32_t)1<<(OP_CTL0_OP0GAIN80X_POS))
#define OP_CTL0_OP1GAIN            ((uint32_t)0xf<<(OP_CTL0_OP1GAIN10X_POS))
#define OP_CTL0_OP1GAIN10X         ((uint32_t)1<<(OP_CTL0_OP1GAIN10X_POS))
#define OP_CTL0_OP1GAIN20X         ((uint32_t)1<<(OP_CTL0_OP1GAIN20X_POS))
#define OP_CTL0_OP1GAIN40X         ((uint32_t)1<<(OP_CTL0_OP1GAIN40X_POS))
#define OP_CTL0_OP1GAIN80X		   ((uint32_t)1<<(OP_CTL0_OP1GAIN80X_POS))
#define OP_CTL0_OP2GAIN            ((uint32_t)0xf<<(OP_CTL0_OP2GAIN10X_POS))
#define OP_CTL0_OP2GAIN10X         ((uint32_t)1<<(OP_CTL0_OP2GAIN10X_POS))
#define OP_CTL0_OP2GAIN20X         ((uint32_t)1<<(OP_CTL0_OP2GAIN20X_POS))
#define OP_CTL0_OP2GAIN40X         ((uint32_t)1<<(OP_CTL0_OP2GAIN40X_POS))
#define OP_CTL0_OP2GAIN80X         ((uint32_t)1<<(OP_CTL0_OP2GAIN80X_POS))

/* OP_CTL1 λ�� */
#define OP_CTL1_OP0CAP0_POS        (0)
#define OP_CTL1_OP0CAP1_POS        (1)
#define OP_CTL1_OP0CAP2_POS        (2)
#define OP_CTL1_OP0CAPEN_POS       (3)
#define OP_CTL1_OP1CAP0_POS        (4)
#define OP_CTL1_OP1CAP1_POS        (5)
#define OP_CTL1_OP1CAP2_POS        (6)
#define OP_CTL1_OP1CAPEN_POS       (7)
#define OP_CTL1_OP2CAP0_POS        (8)
#define OP_CTL1_OP2CAP1_POS        (9)
#define OP_CTL1_OP2CAP2_POS        (10)
#define OP_CTL1_OP2CAPEN_POS       (11)
#define OP_CTL1_OP0CAP             ((uint32_t)7<<(OP_CTL1_OP0CAP0_POS))
#define OP_CTL1_OP0CAP0            ((uint32_t)1<<(OP_CTL1_OP0CAP0_POS))
#define OP_CTL1_OP0CAP1            ((uint32_t)1<<(OP_CTL1_OP0CAP1_POS))
#define OP_CTL1_OP0CAP2            ((uint32_t)1<<(OP_CTL1_OP0CAP2_POS))
#define OP_CTL1_OP0CAPEN           ((uint32_t)1<<(OP_CTL1_OP0CAPEN_POS))
#define OP_CTL1_OP1CAP		       ((uint32_t)7<<(OP_CTL1_OP1CAP0_POS))
#define OP_CTL1_OP1CAP0		       ((uint32_t)1<<(OP_CTL1_OP1CAP0_POS))
#define OP_CTL1_OP1CAP1            ((uint32_t)1<<(OP_CTL1_OP1CAP1_POS))
#define OP_CTL1_OP1CAP2            ((uint32_t)1<<(OP_CTL1_OP1CAP2_POS))
#define OP_CTL1_OP1CAPEN           ((uint32_t)1<<(OP_CTL1_OP1CAPEN_POS))
#define OP_CTL1_OP2CAP		       ((uint32_t)7<<(OP_CTL1_OP2CAP0_POS))
#define OP_CTL1_OP2CAP0		       ((uint32_t)1<<(OP_CTL1_OP2CAP0_POS))
#define OP_CTL1_OP2CAP1            ((uint32_t)1<<(OP_CTL1_OP2CAP1_POS))
#define OP_CTL1_OP2CAP2            ((uint32_t)1<<(OP_CTL1_OP2CAP2_POS))
#define OP_CTL1_OP2CAPEN           ((uint32_t)1<<(OP_CTL1_OP2CAPEN_POS))

#endif //KF32F_Periph_op
/* ������ض������ */


/* ----------------------------------------------------------------------------
   -- ���ܺ궨��
   ---------------------------------------------------------------------------- */
/* SFRλ��һ */
#define SFR_SET_BIT_ASM(SFR, POS) \
        __asm volatile("SET [%0], #%1"::"r"(&(SFR)),"i"(POS))
/* SFRλ���� */
#define SFR_CLR_BIT_ASM(SFR, POS) \
        __asm volatile("CLR [%0], #%1"::"r"(&(SFR)),"i"(POS))
/* д�ڴ� */
#define STW_ASM(ADDR, DATA) \
        __asm volatile("ST.w [%0], %1"::"r"(ADDR),"r"(DATA))
/* ���ܺ궨����� */


/* ----------------------------------------------------------------------------
   -- ��������
   ---------------------------------------------------------------------------- */
/* д���⹦�ܼĴ��� */
static inline uint32_t
SFR_Config (uint32_t SfrMem, uint32_t SfrMask, uint32_t WriteVal)
{
    return ((SfrMem & SfrMask) | (WriteVal));
}
/* д���⹦�ܼĴ���������� */


#endif /* _KF32F_BASIC_H */
