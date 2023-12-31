/*
 * G9_Round6.c
 *
 * Created: 11/02/2023 10:39:46 AM
 * Author : Abdelrahman Aboelazm
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "RCC_int.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"


void MRCC_vSystemInit(void)
{
	/*1- CSS (ON/OFF) */
	/*2- HSE_BYP */
	CLR_BIT(RCC->CR, HSEBYP);
	/*3- select clock switch (HSI/HSE/PLL) */
	SET_BIT(RCC->CFGR, SW0);
	/*4- Bus prescalers   */
	/*5- PLL configuration */
	/*6- Enable the selected clock (HSI ON / HSE ON / PLL ON)*/
#if RCC_HSE_ENABLE == ENABLE
	SET_BIT(RCC->CR, HSEON);
#endif

}

void MRCC_vEnableClock(u32 A_u32BusId, u32 A_u32PeripheralId)
{
	switch(A_u32BusId)
	{
	case RCC_AHB1:
		SET_BIT(RCC->AHB1ENR,A_u32PeripheralId ) ;
		break;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR,A_u32PeripheralId ) ;
		break;
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR,A_u32PeripheralId ) ;
		break;
	default:
		/* Error: Bus ID out of range */
		break;
	}
}

void MRCC_vDisableClock(u32 A_u32BusId, u32 A_u32PeripheralId)
{
	switch(A_u32BusId)
	{
	case RCC_AHB1:
		CLR_BIT(RCC->AHB1ENR,A_u32PeripheralId ) ;
		break;
	case RCC_AHB2:
		CLR_BIT(RCC->AHB2ENR,A_u32PeripheralId ) ;
		break;
	case RCC_APB1:
		CLR_BIT(RCC->APB1ENR,A_u32PeripheralId ) ;
		break;
	}
}
