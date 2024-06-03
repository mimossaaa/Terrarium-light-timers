unsigned long onDuration = 500;
unsigned long offDuration = 500;
const int PIN_UV = 13;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_UV, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');  // Read input until newline
    int separatorIndex = input.indexOf(',');  // Find the comma separator

    if (separatorIndex != -1) {
      // Extract the on and off durations from the input
      String onStr = input.substring(0, separatorIndex);
      String offStr = input.substring(separatorIndex + 1);

      // Convert the strings to integers
      onDuration = onStr.toInt();
      offDuration = offStr.toInt();
    }
  }

  digitalWrite(PIN_UV, HIGH);
  delay(onDuration);  // LED stays on for the duration specified by serial input
  digitalWrite(PIN_UV, LOW);
  delay(offDuration);  // LED stays off for the duration specified by serial input
}
