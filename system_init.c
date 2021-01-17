/**
  ******************************************************************************
  * 文件名  system_init.c
  * 作  者  ChipON_AE/FAE_Group
  * 版  本  V2.61
  * 日  期  2019-11-16
  * 描  述  该文件提供了外设时钟与系统时钟初始化
  *
  ******************************************************************************
  */
#include "system_init.h"

static unsigned int systick_us;
static unsigned int systick_ms;
/**
  * 描述  时钟默认配置。
  * 输入  无。
  * 返回  无。
*/
static void SetSysClock(void)
{
	/* 使能内部高频时钟*/
	OSC_INTHF_Software_Enable(TRUE);
	while(OSC_Get_INTHF_INT_Flag() != SET);
	/* PLL时钟源选择 */
#ifdef SYSCLK_FREQ_HSI
	OSC_PLL_Input_Source_Config(PLL_INPUT_INTHF);
#else
	OSC_PLL_Input_Source_Config(PLL_INPUT_EXTHF);
#endif
	/* PLL倍频时钟选择 */
#ifdef SYSCLK_FREQ_48MHz
	OSC_PLL_Multiple_Value_Select(48,2,8);
#elif defined SYSCLK_FREQ_72MHz
	OSC_PLL_Multiple_Value_Select(36,2,4);
#elif defined SYSCLK_FREQ_96MHz
	OSC_PLL_Multiple_Value_Select(12,1,2);
#elif defined SYSCLK_FREQ_120MHz
	OSC_PLL_Multiple_Value_Select(30,2,2);
#endif
	OSC_PLL_Start_Delay_Config(PLL_START_DELAY_1024);
	OSC_PLL_Software_Enable(TRUE);
	OSC_PLL_RST();
	while(OSC_Get_PLL_INT_Flag() != SET);
	/* 主时钟配置 */
	OSC_SCK_Division_Config(SCLK_DIVISION_1);
	OSC_SCK_Source_Config(SCLK_SOURCE_PLL);
	/* 外设高速时钟 */
	OSC_HFCK_Division_Config(HFCK_DIVISION_1);
	OSC_HFCK_Source_Config(HFCK_SOURCE_INTHF);
	OSC_HFCK_Enable(TRUE);
}

/**
  * 描述  系统初始化。
  * 输入  无。
  * 返回  无。
*/
void SystemInit(void)
{
	/* 时钟配置 */
	SetSysClock();
	FLASH_CFG=0xC3;//FLASH读取周期4周期
}


/**
  * 描述  systick_delay初始化
  * 输入  无。
  * 返回  无。
*/
void systick_delay_init()
{
	ST_CTL&=0xFFFFFFFC;//禁止节拍定时器,无中断请求
	ST_RELOAD=0xFFFFFFFF;//重载计数周期
	ST_CV=0;//当前计数
	ST_CTL|=0x00000004;//SCLK时钟
#ifdef SYSCLK_FREQ_48MHz
	systick_us=48;
#elif defined SYSCLK_FREQ_72MHz
	systick_us=72;
#elif defined SYSCLK_FREQ_96MHz
	systick_us=96;
#elif defined SYSCLK_FREQ_120MHz
	systick_us=120;
#endif
    systick_ms=systick_us*1000;
}
/**
  * 描述  us延时
  * 输入  nus
  * 返回  无
*/
void systick_delay_us(unsigned int nus)
{
	unsigned int temp;

	ST_RELOAD=systick_us*nus;//加载周期
	ST_CV=0;//当前计数清0
	ST_CTL|=0x00000001;//使能节拍定时器
	do
	{
		temp=ST_CTL;
	}while((temp&0x01)&&!(temp&(1<<16)));	//等待时间到达
	ST_CTL&=0xFFFFFFFE;//禁止节拍定时器
}

/**
  * 描述  ms延时
  * 输入  mus
  * 返回  无
*/
void systick_delay_ms(unsigned int mus)
{
	unsigned int temp;

	ST_RELOAD=systick_ms*mus;//加载周期
	ST_CV=0;//当前计数清0
	ST_CTL|=0x00000001;//使能节拍定时器
	do
	{
		temp=ST_CTL;
	}while((temp&0x01)&&!(temp&(1<<16)));	//等待时间到达
	ST_CTL&=0xFFFFFFFE;//禁止节拍定时器
}
