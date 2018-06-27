#include "stm32f0xx.h"

const uint32_t delay = 400000;

void cfg_clock_hsi(void){
	FLASH->ACR |= FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY;
	//---------Set mul for PLL (Clock = 4 * MUL)
	RCC->CFGR |= RCC_CFGR_PLLMUL12;
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));
	
	while(RCC->CFGR & RCC_CFGR_SWS)
		RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));
}

int main(void) {
	uint32_t i;
	cfg_clock_hse();
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODER1_0;
	
	while(1){
		for(i=0; i<delay; i++);
		GPIOB->BSRR = GPIO_BSRR_BR_1;
		for(i=0; i<delay; i++);
		GPIOB->BSRR = GPIO_BSRR_BS_1;
	}
}
