#include "main.h"
#include <stdio.h>
#include <string.h>

  
void bytes2hex (unsigned char *src, char *out, int len)
{
		static char HexLookUp[] = "0123456789ABCDEF";  
    while(len--)
    {
        *out++ = HexLookUp[*src >> 4];
        *out++ = HexLookUp[*src & 0x0F];
        src++;
    }
    *out = 0;
}

void main(void)
{
	unsigned char key = 0x00;
	unsigned char datatext[8] = {0};
	lcd1602_init();
	
	UART_Init();
	UART_Puts("BAO DEP TRAI\n");
	delay_ms(1000);
	UART_Puts("duonggiabao278@gmail.com\n");
	SBUF = 0x00;
	lcd1602_gotoxy(0,0);
	lcd1602_puts("BAO DEP TRAI");
	lcd1602_gotoxy(0,1);
	lcd1602_puts("Data: ");
	lcd1602_gotoxy(11,1);
	lcd1602_puts("HEX");
	while(1)
	{
		if(RI==1)
		{
			RI=0;
			key=SBUF;
			P1 = ~key;
			P0_0 = ~P0_0;
			bytes2hex(&key,&datatext,1);
			lcd1602_gotoxy(7,1);
			lcd1602_puts(datatext);
		}
	}
}

