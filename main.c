/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>

/*
 * ======== Grace related includes ========
 */
#include <ti/mcu/msp430/Grace.h>
#define cs_disable1 (P2OUT |= BIT0)
#define cs_enable1 (P2OUT &= ~BIT0)

volatile unsigned int i;
volatile unsigned char data;

void inicializa(char address, char data_acc)
{
	IFG2 &= ~UCB0RXIFG;
	UCB0TXBUF = address;
	while (!(IFG2 & UCB0RXIFG));
	data = UCB0RXBUF;

	IFG2 &= ~UCB0RXIFG;
	UCB0TXBUF = data_acc;
	while (!(IFG2 & UCB0RXIFG));
	data = UCB0RXBUF;
}


//  ======== main ========

void main(void)
{

	Grace_init();                   // Activate Grace-generated configuration

	P2OUT &= ~BIT2;
	P2OUT &= ~BIT0;
	for (i = 30000; i; i--);
	P2OUT |= BIT2;
	for (i = 30000; i; i--);
	P2OUT |= BIT0;
	for (i = 30000; i; i--);

	while (1)
	{

				cs_enable1;
				inicializa( 0x20 , 0xC7 ); //turn-on the device and gather acceleration data
				cs_disable1;

				cs_enable1;
				inicializa( 0xA0 , 0xDB );
				cs_disable1;

				cs_enable1;
				inicializa( 0x21 , 0x84 );
				cs_disable1;

				cs_enable1;
				inicializa( 0xA1 , 0xDB );
				cs_disable1;

				for (i = 300; i; i--);
	}
}


void acc_isr(void) {

	P2IFG &= ~BIT1;

	while (!(IFG2 & UCB0TXIFG));

	//UCB0TXBUF = ;
}
