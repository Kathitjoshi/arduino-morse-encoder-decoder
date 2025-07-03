#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD setup — change address from 0x27 to 0x3F if needed
LiquidCrystal_I2C lcd(0x27, 16, 2);  

// Sensor pins
const int ldrPin = A0;
const int piezoPin = A1;
const int potPin = A2;

// Thresholds and timing
const int threshold = 500;
const int dotDuration = 200;
const int dashDuration = 600;
const int charPause = 800;
const int wordPause = 1400;

// Morse tracking
String morseCode = "";
String decodedMessage = "";
bool simulateMode = true;  
String simulatedMorse[] = { ".--.", ".", "..." };
int currentChar = 0;
int signalIndex = 0;

// Morse dictionary
const char* morseAlphabet[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--.."
};
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(piezoPin, INPUT);
  pinMode(potPin, INPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Morse Decoder");
  Serial.println("Morse Decoder Initialized");
  delay(1500);
  lcd.clear();
}

void loop() {
  int modeValue = analogRead(potPin);
  bool isLDR = (modeValue < 512);  // Left = LDR, Right = Piezo

  if (simulateMode) {
    simulatePES();
  } else {
    readFromSensors(isLDR);
  }
}

void simulatePES() {
  if (currentChar < 3) {
    String symbol = simulatedMorse[currentChar];

    if (signalIndex < symbol.length()) {
      char s = symbol.charAt(signalIndex);
      if (s == '.') {
        morseCode += ".";
        delay(dotDuration);
      } else if (s == '-') {
        morseCode += "-";
        delay(dashDuration);
      }

      signalIndex++;
      delay(200);  // Pause between symbols
    } else {
      char decodedChar = decodeMorse(morseCode);
      if (decodedChar != '\0') {
        decodedMessage += decodedChar;
        displayOutput(decodedMessage);
      }

      morseCode = "";
      signalIndex = 0;
      currentChar++;
      delay(charPause);
    }
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sim Done: PES");
    while (true);  // Stop after decoding
  }
}

void readFromSensors(bool isLDR) {
  int inputValue = analogRead(isLDR ? ldrPin : piezoPin);

  if (inputValue < threshold) {
    int duration = measureSignalDuration(isLDR);
    if (duration < dotDuration + 100) {
      morseCode += ".";
    } else {
      morseCode += "-";
    }
  } else if (morseCode.length() > 0) {
    char decodedChar = decodeMorse(morseCode);
    if (decodedChar != '\0') {
      decodedMessage += decodedChar;
      displayOutput(decodedMessage);
    }
    morseCode = "";
    delay(charPause);
  }

  int pauseTime = measurePauseDuration(isLDR);
  if (morseCode.length() == 0 && pauseTime > wordPause) {
    decodedMessage += " ";
    displayOutput(decodedMessage);
  }
}

int measureSignalDuration(bool isLDR) {
  int start = millis();
  while (analogRead(isLDR ? ldrPin : piezoPin) < threshold) {
    if (millis() - start > 2000) break;
  }
  return millis() - start;
}

int measurePauseDuration(bool isLDR) {
  int start = millis();
  while (analogRead(isLDR ? ldrPin : piezoPin) >= threshold) {
    if (millis() - start > wordPause) break;
  }
  return millis() - start;
}

char decodeMorse(String morse) {
  for (int i = 0; i < 26; i++) {
    if (morse.equals(morseAlphabet[i])) {
      return alphabet[i];
    }
  }
  return '\0';
}

void displayOutput(String message) {
  Serial.print("Decoded Message: ");
  Serial.println(message);

  lcd.setCursor(0, 0);
  lcd.print("Decoded Msg:     ");
  lcd.setCursor(0, 1);
  lcd.print("                ");

  lcd.setCursor(0, 0);
  lcd.print("Decoded Msg:");
  lcd.setCursor(0, 1);
  lcd.print(message.substring(message.length() > 16 ? message.length() - 16 : 0));
}
