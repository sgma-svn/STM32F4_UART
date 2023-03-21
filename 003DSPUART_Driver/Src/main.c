
#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>
#include "signals.h"
#include "uart.h"

extern float _5hz_signal[HZ_5_SIG_LEN];
float g_in_sig_sample;

//static void plot_input_signal(void);
static void psuedo_dly(int dly);


int main(void)
{
	/* Enable Floating Point Unit */
	/* CPACR - Floating Point Co-processor */
	/* Register 20 and 22 or CP10 and CP11 provided full access */
	//SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));

	// Clear version of the one above
	SCB->CPACR |= (1U<<20);
	SCB->CPACR |= (1U<<21);
	SCB->CPACR |= (1U<<22);
	SCB->CPACR |= (1U<<23);

	/* initialize the uart */
	uart2_tx_init();

	while(1)
	{
		printf("Hello from STM32...\n\r");
		//plot_input_signal();
	}
}

/* static void plot_input_signal(void)
{
	int i;
	for(i=0;i<(HZ_5_SIG_LEN);i++)
	{
		g_in_sig_sample = _5hz_signal[i];
		psuedo_dly(9000);
	}
} */

/* forced delay */
static void psuedo_dly(int dly)
{
	for(int i=0; i<dly; i++){}
}

