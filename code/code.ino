// Define the pins for voltage, current, and resistance measurement
const int voltagePin = A0;
const int currentPin = A1;
const int resistancePin = A2;

// Define the pins for continuity test
const int continuityPin = 7;

// Define the variables for storing measurement values
float voltageValue;
float currentValue;
float resistanceValue;

void setup() {
  // Set the pins as input or output
  pinMode(voltagePin, INPUT);
  pinMode(currentPin, INPUT);
  pinMode(resistancePin, INPUT);
  pinMode(continuityPin, INPUT);
  
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Measure the voltage and convert the value to volts
  voltageValue = (analogRead(voltagePin) * 5.0) / 1024.0;
  
  // Measure the current and convert the value to amperes
  currentValue = (analogRead(currentPin) * 5.0) / 1024.0;
  
  // Measure the resistance and convert the value to ohms
  resistanceValue = (analogRead(resistancePin) * 5.0) / 1024.0;
  resistanceValue = (5.0 - resistanceValue) / resistanceValue;
  
  // Check for continuity
  int continuityValue = digitalRead(continuityPin);
  
  // Print the measurement values and continuity result to the serial monitor
  Serial.print("Voltage: ");
  Serial.print(voltageValue, 2);
  Serial.println("V");
  
  Serial.print("Current: ");
  Serial.print(currentValue, 2);
  Serial.println("A");
  
  Serial.print("Resistance: ");
  Serial.print(resistanceValue, 2);
  Serial.println("Ω");
  
  if (continuityValue == HIGH) {
    Serial.println("Continuity: Yes");
  } else {
    Serial.println("Continuity: No");
  }
  
  // Wait for a brief moment before taking measurements again
  delay(500);
}
