#include <IRremote.h>

//#include <avr/sleep.h>

//#include <avr/power.h>

#include <U8glib.h>

#define INTERVAL_LCD 20

unsigned long lcd_time = millis();

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

#define setFont_L u8g.setFont(u8g_font_7x13)




#define setFont_M u8g.setFont(u8g_font_fixed_v0r)

#define setFont_S u8g.setFont(u8g_font_fixed_v0r)

#define setFont_SS u8g.setFont(u8g_font_fub25n)

int RECV_PIN = 10;

int i=0,j=0,n=0;

const int buttonPin = 2;

int buttonState = 0;

/*void pin2Interrupt(void) {




/*Serial.println("wake up!!!");

detachInterrupt(0);

}*/

/*void enterSleep(void) {




/* attachInterrupt(0, pin2Interrupt, LOW);

delay(100);*/

/*   set_sleep_mode(SLEEP_MODE_PWR_DOWN);

sleep_enable();

sleep_mode();

sleep_disable();

}*/

unsigned long password[5]={33464415,33464415,33464415,33464415,33464415};

unsigned long answer[5];

IRrecv irrecv(RECV_PIN);

decode_results results;

#include<Servo.h>

Servo mcservo;

/*void relock(void)

{

if (irrecv.decode(&results));

Serial.print(results.value);

Serial.print('\n');

// while(results.value)

// mcservo.write(90);

}*/

int unlock()

{int m=0;

if (irrecv.decode(&results))

{

if(i<=4)

{Serial.println(results.value, DEC);//

answer[i]=results.value;

i++;

irrecv.resume();

}

else if(i=5)

/* {for(j;j<=4;j++)

{Serial.print(answer[j]);

Serial.print(" ");

i++;}

}}}*/

{for(i=0;i<=4;i++)

{if(answer[i]==password[i])

m++;

else ;}

return m;




}}}










void setup(){

pinMode(buttonPin, INPUT);

mcservo.attach(6);

//mcservo.write(90);

Serial.begin(9600);

Serial.print("completed");

int pin2 = 2;

pinMode(pin2, INPUT);

irrecv.enableIRIn();

}










void loop() {int n=0,temp=0;







if (unlock()==5)

{

mcservo.write(0);

u8g.firstPage();

do {

setFont_L;

u8g.setPrintPos(0, 15);

u8g.print("unlocked");

}while( u8g.nextPage() );










temp=digitalRead(buttonPin);

while(!temp)

mcservo.write(90);

}




else

{

mcservo.write(90);

u8g.firstPage();

do {

setFont_L;

u8g.setPrintPos(0, 15);

u8g.print("password to unlock:");

}while( u8g.nextPage() );

}

}
