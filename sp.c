#ifndef _SERIAL_H
#define _SERIAL_H

void initClocks(void);
void initUART0(void);
void U0Write(char data);
void Send_String(char* StringPtr);

void initUART0(void)
{
 PINSEL0 = 0x5;  /* Select TxD for P0.0 and RxD for P0.1 */
 U0LCR = 0x83; /* 8 bits, no Parity, 1 Stop bit | DLAB set to 1 */
 U0DLL = 110;
 U0DLM = 1;  
 U0FDR = 0xF1; /* MULVAL=15(bits - 7:4) , DIVADDVAL=0(bits - 3:0)*/
 U0LCR &= 0x0F; // Set DLAB=0 to lock MULVAL and DIVADDVAL
 //BaudRate is now ~9600 and we are ready for UART communication!
}
 
void U0Write(char data)
{
 while (!(U0LSR & (1<<5))); // wait till the THR is empty
 // now we can write to the Tx FIFO
 U0THR = data;
}
 
void initClocks(void)
{
 PLL0CON = 0x01;   //Enable PLL
 PLL0CFG = 0x24;   //Multiplier and divider setup
 PLL0FEED = 0xAA;  //Feed sequence
 PLL0FEED = 0x55;
 
 while(!(PLL0STAT & 0x00000400)); //is locked?
 
 PLL0CON = 0x03;   //Connect PLL after PLL is locked
 PLL0FEED = 0xAA;  //Feed sequence
 PLL0FEED = 0x55;
 VPBDIV = 0x01;    // PCLK is same as CCLK i.e.60 MHz
}
 
void Send_String(char* StringPtr){
 
 while(*StringPtr != 0x00){
 U0Write(*StringPtr);
 StringPtr++;}
}
 
#endif /* SERIAL_H */