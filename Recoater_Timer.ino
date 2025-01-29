// Pin assignments
const int limitSwitch1 = 2; // First limit switch
const int limitSwitch2 = 3; // Second limit switch
const int buttonPin = 4;    // Push button

// Variables
unsigned long startTime = 0;
unsigned long stopTime = 0;
bool timerRunning = false;
bool reset = false;

void setup() {
  pinMode(limitSwitch1, INPUT_PULLUP); // Use pull-up for normally open switches
  pinMode(limitSwitch2, INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Timer Ready. Press button to set.");
}

void loop() {
  // Wait for button press to reset the timer
  if (digitalRead(buttonPin) == LOW) {
    resetTimer();
  }

  // Check for limit switch release to start timer
  if (!timerRunning && digitalRead(limitSwitch1) == HIGH && digitalRead(limitSwitch2) == HIGH && reset == true) {
    startTimer();
  }

  // Check for limit switch press to stop timer
  if (timerRunning) {
    if (digitalRead(limitSwitch1) == LOW || digitalRead(limitSwitch2) == LOW && reset == true) {
      reset = false;
      stopTimer();
    } else {
      updateTimer();
    }
  }
}

void resetTimer() {
  reset = true;
  startTime = 0;
  stopTime = 0;
  timerRunning = false;
  Serial.println("Timer Reset. Waiting for release of first limit switch...");
  delay(500); // Debounce delay
}

void startTimer() {
  startTime = millis();
  timerRunning = true;
  Serial.println("Timer Started!");
}

void stopTimer() {
  stopTime = millis();
  timerRunning = false;
  unsigned long elapsed = stopTime - startTime;

  Serial.print("Timer Stopped! Final time: ");
  Serial.print(elapsed / 1000.0, 3); // Display in seconds with milliseconds
  Serial.println(" sec");  
  Serial.println("Press button to reset timer.");
}

void updateTimer() {
  unsigned long currentTime = millis();
  unsigned long elapsed = currentTime - startTime;

  // Serial.print("Elapsed time: ");
  // Serial.print(elapsed / 1000.0, 3); // Display in seconds with milliseconds
  // Serial.println(" sec");
  delay(1); // Reduce Serial output spam
}

