#define LED_PIN 3
#define BUTTON_PIN 2
byte lastButtonState = LOW;
byte ledState = LOW;

unsigned long lastTimeButtonStateChanged = millis();
unsigned long debounceDuration = 50;


void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  lastButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  controlButtonPush();
}

void controlButtonPush() {
  if (millis() - lastTimeButtonStateChanged >= debounceDuration) {
  byte buttonState = digitalRead(BUTTON_PIN);
    if (buttonState != lastButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
        if (buttonState == LOW) {
          if (ledState == HIGH) {
            ledState = LOW;
          }
        else {
          ledState = HIGH;
        }
        digitalWrite(LED_PIN, ledState);
    }
  }
 }
