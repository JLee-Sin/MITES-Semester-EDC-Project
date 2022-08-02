#define LED_PIN 3
#define BUTTON_PIN 2
#define VERBOSE_PIN A0
byte lastButtonState = LOW;
byte ledState = LOW;
float potVal = 0;
float dutyCycle = 0;

unsigned long lastTimeButtonStateChanged = millis();
unsigned long debounceDuration = 50;


void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(VERBOSE_PIN, INPUT);
  lastButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  controlButtonPush();
  verboseOut();
  delay(50);
}

void controlButtonPush() {
  if (millis() - lastTimeButtonStateChanged >= debounceDuration) {
  byte buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != lastButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
        if (buttonState == LOW) {
          if (ledState == HIGH) {
            Serial.println("Circuit turned off");
            ledState = LOW;
          }
        else {
          ledState = HIGH;
          Serial.println("Circuit turned on");
        }
        digitalWrite(LED_PIN, ledState);
    }
  }
 }
}

void verboseOut() {
  if(potVal != analogRead(VERBOSE_PIN)) {
    potVal = analogRead(VERBOSE_PIN);
    float temp = (potVal/1023)*10;
    Serial.println("Current speed is " + temp + "% ", 0);
  }
}
  

