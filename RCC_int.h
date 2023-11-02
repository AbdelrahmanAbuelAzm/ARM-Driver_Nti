/*
 * G9_Round6.c
 *
 * Created: 11/02/2023 10:45:07 AM
 * Author : Abdelrahman Aboelazm
 */ 


#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_

#define RCC_AHB1    0
#define RCC_AHB2	1
#define RCC_APB1	2


#define RCC_EN_GPIOA  0
#define RCC_EN_GPIOB  1
/*
 * and so on ...
 * */


void MRCC_vSystemInit(void) ;
void MRCC_vEnableClock(/*???*/);
void MRCC_vDisableClock(/*???*/);




#endif /* MCAL_RCC_RCC_INT_H_ */
