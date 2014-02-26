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
volatile unsigned int UART_FG;

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


	cs_enable1;
	inicializa( 0x20 , 0xF7 ); //CTRL_REG1
	cs_disable1;

	cs_enable1;
	inicializa( 0xA0 , 0xDB );
	cs_disable1;

	cs_enable1;
	inicializa( 0x21 , 0x84 ); //CTRL_REG2
	cs_disable1;

	cs_enable1;
	inicializa( 0xA1 , 0xDB );
	cs_disable1;

	for( i=30 ; i > 0 ; i--);


	while ( 1 )
	{
		if( UART_FG == 1 )
		{

		}
	}

}


void acc_isr(void) {	//acc data read spi

	P2IFG &= ~BIT1;

/*	cs_enable1;
	inicializa( 0xA7 , 0xDB ); //STATUS_REG
	cs_disable1;
*/
	cs_enable1;
	inicializa( 0xA8 , 0xDB ); //OUTX_L
	cs_disable1;

	cs_enable1;
	inicializa( 0xA9 , 0xDB ); //OUTX_H
	cs_disable1;

	cs_enable1;
	inicializa( 0xAA , 0xDB ); //OUTY_L
	cs_disable1;

	cs_enable1;
	inicializa( 0xAB , 0xDB ); //OUTY_H
	cs_disable1;

	cs_enable1;
	inicializa( 0xAC , 0xDB ); //OUTZ_L
	cs_disable1;

	cs_enable1;
	inicializa( 0xAD , 0xDB ); //OUTZ_H
	cs_disable1;

	UART_FG = 1;
}



