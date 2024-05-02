#include "Io.h"
void RGBLED_Init(void){
SYSCTL_RCGCGPIO_R |=PF_mask;
while((SYSCTL_PRGPIO_R&0x20)==0);
GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
GPIO_PORTF_CR_R  |= 0x0E;
GPIO_PORTF_AMSEL_R &= ~PF1_mask;
 GPIO_PORTF_AFSEL_R &= ~PF1_mask;
	GPIO_PORTF_PCTL_R &=~0x0000FFF0;
	GPIO_PORTF_DIR_R |= PF1_mask;
	GPIO_PORTF_DEN_R |= PF1_mask;
}
void SW12_Init(void){
SYSCTL_RCGCGPIO_R |=PF_mask;
while((SYSCTL_PRGPIO_R&0x20)==0);
GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
GPIO_PORTF_CR_R  |= PF0_mask;
GPIO_PORTF_AMSEL_R &= ~PF0_mask;
 GPIO_PORTF_AFSEL_R &= ~PF0_mask;
	GPIO_PORTF_PCTL_R &=~0x000F000F;
	GPIO_PORTF_DIR_R |= PF0_mask;
	GPIO_PORTF_DEN_R |= PF0_mask;
	GPIO_PORTF_PUR_R = PF0_mask;
}
unsigned char sw12_input(void)
{return GPIO_PORTF_DATA_R &0x11;}

void leds_output(unsigned char data)
{GPIO_PORTF_DATA_R &= ~0x0E;
	GPIO_PORTF_DATA_R |=data;}
unsigned char button;
unsigned char led;
	int main()
	{while(1){
			SW12_Init();
			RGBLED_Init();
			button =sw12_input();
		
			 if(button==0x10)
			{
				leds_output(0x02);
			}
		}
				
	}
		
		

			
	
	


	
		