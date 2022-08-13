#include <IRremote.h>

int receiver = 13; // Signal Pin of IR receiver to Arduino Digital Pin 13
int red = 0;
int green = 0;
int blue = 0;

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

/*-----( Function )-----*/
void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{

  switch(results.value)

  {
  case 0xFFA25D: Serial.println("POWER"); break;
  case 0xFFE21D: Serial.println("FUNC/STOP"); break;
  case 0xFF629D: Serial.println("VOL+"); break;
  case 0xFF22DD: Serial.println("FAST BACK");    break;
  case 0xFF02FD: Serial.println("PAUSE");    break;
  case 0xFFC23D: Serial.println("FAST FORWARD");   break;
  case 0xFFE01F: Serial.println("DOWN");    break;
  case 0xFFA857: Serial.println("VOL-");    break;
  case 0xFF906F: Serial.println("UP");    break;
  case 0xFF9867: Serial.println("EQ");    break;
  case 0xFFB04F: Serial.println("ST/REPT");    break;
  case 0xFF6897: Serial.println("0");  red = 255; green = 255; blue = 255;  break;
  case 0xFF30CF: Serial.println("1");  red = 255; green = 0; blue = 0;  break;
  case 0xFF18E7: Serial.println("2");  red = 0; green = 255; blue = 0;  break;
  case 0xFF7A85: Serial.println("3");  red = 0; green = 0; blue = 255;  break;
  case 0xFF10EF: Serial.println("4");  red = 255; green = 255; blue = 0;  break;
  case 0xFF38C7: Serial.println("5");  red = 255; green = 0; blue = 255;  break;
  case 0xFF5AA5: Serial.println("6");  red = 255; green = 255; blue = 0;   break;
  case 0xFF42BD: Serial.println("7");  red = 0; green = 0; blue = 0;  break;
  case 0xFF4AB5: Serial.println("8");  red = 0; green = 100; blue = 200;  break;
  case 0xFF52AD: Serial.println("9");  red = 0; green = 50; blue = 100;  break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  

  default: 
    Serial.println(" other button   ");

  }// End Case

  delay(500); // Do not get immediate repeat


} //END translateIR 

// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  // put your main code here, to run repeatedly:
  /*delay(1000);
  analogWrite(RED, rand() % 255);
  delay(1);
  analogWrite(GREEN, rand() % 255);
  delay(1);
  analogWrite(BLUE, rand() % 255);
  delay(2000);
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);*/

  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    translateIR(); 
    irrecv.resume(); // receive the next value
    analogWrite(RED, red);
    analogWrite(GREEN, green);
    analogWrite(BLUE, blue);
  }  
  
}
