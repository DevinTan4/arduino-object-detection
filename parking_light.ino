const int motorbikeRedLed = 21;
const int motorbikeGreenLed = 22;
const int carRedLed = 12;
const int carGreenLed = 13;

bool commandReceived = false;
unsigned long lastCommandTime = 0;
const unsigned long commandTimeout = 5000; // Timeout in milliseconds (adjust as needed)

void setup() {
  pinMode(motorbikeRedLed, OUTPUT);
  pinMode(motorbikeGreenLed, OUTPUT);
  pinMode(carRedLed, OUTPUT);
  pinMode(carGreenLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // if (Serial.available() > 0) {
  //   char command = Serial.read();
  //   if (command == 'Y') {
  //     digitalWrite(motorbikeGreenLed, HIGH); // Turn on yellow LED
  //     digitalWrite(motorbikeRedLed, LOW);
  //     commandReceived = true;
  //     lastCommandTime = millis(); // Update last command time
  //   } else if (command == 'R') {
  //     digitalWrite(motorbikeGreenLed, LOW);  // Turn off yellow LED
  //     digitalWrite(motorbikeRedLed, HIGH); // Turn on red LED
  //     commandReceived = true;
  //     lastCommandTime = millis(); // Update last command time
  //   }
  // }

  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'G'){
      digitalWrite(motorbikeGreenLed, HIGH);
      digitalWrite(carGreenLed, HIGH);
      digitalWrite(carRedLed, LOW);
      digitalWrite(motorbikeRedLed, LOW);
      commandReceived = true;
      lastCommandTime = millis();
    } else if (command == 'R') {
      digitalWrite(motorbikeRedLed, HIGH);
      digitalWrite(carRedLed, HIGH);
      digitalWrite(motorbikeGreenLed, LOW);
      digitalWrite(carGreenLed, LOW);
      commandReceived = true;
      lastCommandTime = millis();
    } else if (command == 'M') {
      digitalWrite(motorbikeGreenLed, HIGH);
      digitalWrite(motorbikeRedLed, LOW);
      digitalWrite(carGreenLed, LOW);
      digitalWrite(carRedLed, HIGH);
      commandReceived = true;
      lastCommandTime = millis();
    } else if (command == 'C') {
      digitalWrite(motorbikeGreenLed, LOW);
      digitalWrite(motorbikeRedLed, HIGH);
      digitalWrite(carGreenLed, HIGH);
      digitalWrite(carRedLed, LOW);
      commandReceived = true;
      lastCommandTime = millis();
    }
  }

  // Check if it's been too long since last command received
  if (commandReceived && (millis() - lastCommandTime) > commandTimeout) {
    digitalWrite(motorbikeGreenLed, LOW);  // Turn off motorbike green led
    digitalWrite(motorbikeRedLed, LOW); // Turn off motorbike red led
    digitalWrite(carGreenLed, LOW); // Turn off car green led
    digitalWrite(carRedLed, LOW); // Turn off car red led
    commandReceived = false; // Reset flag
  }
}

