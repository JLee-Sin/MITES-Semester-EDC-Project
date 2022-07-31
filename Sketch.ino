int button = 2;    // select the input pin for the potentiometer
int onOffPin = 3;      // select the pin for the LED
int buttonSignal=LOW;
int prevButton=LOW;
int counter = 1;
//int outputValue=0;
void setup() {
  // put your setup code here, to run once:
   pinMode(onOffPin, OUTPUT);
   Serial.begin(9600);
}



void loop() {
  buttonSignal = digitalRead(button);
 if((buttonSignal==HIGH)&&(prevButton==LOW)){
    digitalWrite(onOffPin, HIGH);
    prevButton=HIGH;
    Serial.println("Circuit is on ");
  }

  else if((buttonSignal==HIGH)&&(prevButton==HIGH)){
    digitalWrite(onOffPin, LOW);
    prevButton=LOW;
    Serial.println("Circuit is off");
  }
  if((digitalRead(onOffPin))==HIGH){
    Serial.println("Circuit is on ");
  }
  delay(150);

}
