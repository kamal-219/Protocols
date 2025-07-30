#include<reg52.h>
#define lcd P2
sbit rs=P0^0;
sbit rw=P0^1;
sbit e=P0^2;

void lcds();
void cmd(unsigned char a);
void datas(unsigned char b);
void word(unsigned char *s);
void delay();
void lcds(){
	cmd(0X38);
	cmd(0X0c);
	cmd(0X01);
	cmd(0X06);
	cmd(0X80);
}
void cmd(unsigned char a){
	lcd=a;
	rs=0;
	rw=0;
	e=1;
	delay();
  e=0;
}
void datas(unsigned char b){
	lcd=b;
	rs=1;
	rw=0;
	e=1;
	delay();
	e=0;
}
void word(unsigned char *s){
	while(*s){
		datas(*s++);
	}
}
void delay(){
	unsigned int delay;
	for(delay=0;delay<50000;delay++);
}
int main(){
	lcds();
	while(1){
		cmd(0x80);
		word("silicon");
		delay();
		cmd(0x01);
		delay();
	}
}