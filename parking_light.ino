const int yellowLedPin = 23;
const int redLedPin = 32;

// bool commandReceived = false;
// unsigned long lastCommandTime = 0;
// const unsigned long commandTimeout = 5000; // Timeout in milliseconds (adjust as needed)

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'Y') {
      digitalWrite(yellowLedPin, HIGH); // Turn on yellow LED
      digitalWrite(redLedPin, LOW);
      commandReceived = true;
      lastCommandTime = millis(); // Update last command time
    } else if (command == 'R') {
      digitalWrite(yellowLedPin, LOW);  // Turn off yellow LED
      digitalWrite(redLedPin, HIGH); // Turn on red LED
      commandReceived = true;
      lastCommandTime = millis(); // Update last command time
    }
  }

//   // Check if it's been too long since last command received
//   if (commandReceived && (millis() - lastCommandTime) > commandTimeout) {
//     digitalWrite(yellowLedPin, LOW);  // Turn off yellow LED
//     digitalWrite(redLedPin, LOW); // Turn off red LED
//     commandReceived = false; // Reset flag
//   }
// }
