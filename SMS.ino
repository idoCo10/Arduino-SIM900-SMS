#include <SoftwareSerial.h>

SoftwareSerial SIM900(8, 7); // RX, TX

void setup() {
  SIM900.begin(19200);
  sendSMS("+xxxxxxxxx", "Hello, this is a test message from Arduino.");
}

void loop() {
  // Do nothing
}

void sendSMS(String number, String message) {
  SIM900.print("AT+CMGF=1\r"); // Set SMS mode to text
  delay(1000);
  SIM900.println("AT + CMGS = \"" + number + "\""); // Send SMS to number
  delay(1000);
  SIM900.println(message); // Send message
  delay(100);
  SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
  delay(1000);
}
