#include <reg52.h>

sbit led=P0^1;
void delay();

void TRANSMIT(unsigned char *s);
void blink_led();

 int main()
 {
	 unsigned char b;
	TMOD=0x20;
	SCON=0x50;
	TH1=0xfd;
  TR1=1;
 
  TRANSMIT("HEY SILICON");
  delay();
	
	 while(1){
	 while(RI==0);
	 b=SBUF;
   RI=0;
	
	if(b == 'A' || b == 'a') {

		
            blink_led();
		
		
        } else if(b == 'B' || b == 'b') {
            led = 1;
        } else if(b == 'C' || b == 'c') {
            led = 0;
        }
			
	SBUF=b ;		 
	while(TI==0);
	TI=0;
			
	 }
  return 0;
 }
 void TRANSMIT(unsigned char *s){
	  
	while(*s){
		SBUF=*s++;
	while(TI==0);
	TI=0;
	

	} 
}
 
 void delay(){
	 int i;
  for(i=0;i<10000;i++){
	 
	}
 }
 void blink_led(){
  
	 led=1;
	 delay();
	led=0;
  delay();
  
 }