
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(VERBOSE_PIN, INPUT);
  lastButtonState = digitalRead(BUTTON_PIN);
  Serial.begin(9600);
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
    float temp = map(potVal, 0, 1023, 0, 100);
    Serial.print("Current speed is ");
    Serial.print(temp, 0);
    Serial.println("% ");
    delay(2000);
  }
}

