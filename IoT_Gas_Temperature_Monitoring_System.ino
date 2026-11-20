#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define GAS_PIN A0
#define LED_PIN 7
#define BUZZER_PIN 8

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Change this value for your required gas threshold
int gasThreshold = 300;

void setup() {

  Serial.begin(9600);

  dht.begin();

  lcd.init();
  lcd.backlight();

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Gas Monitoring");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  
  delay(3000);
  lcd.clear();
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int gasValue = analogRead(GAS_PIN);

  // Display gas value in Serial Monitor
  Serial.print("Gas Value: ");
  Serial.print(gasValue);

  Serial.print(" | Temperature: ");
  Serial.print(temperature);

  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // DHT11 error check
  if (isnan(temperature) || isnan(humidity)) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DHT11 ERROR");

    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);

    delay(1000);
    return;
  }

  // First LCD line
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C ");

  lcd.print("H:");
  lcd.print(humidity, 0);
  lcd.print("%");

  // Gas threshold checking
  if (gasValue >= gasThreshold) {

    // DANGER
    digitalWrite(LED_PIN, HIGH);

    // Buzzer sound
    tone(BUZZER_PIN, 1000);

    lcd.setCursor(0, 1);
    lcd.print("DANGER!");
    lcd.print(gasValue);

  } 
  else {

    // SAFE
    digitalWrite(LED_PIN, LOW);

    noTone(BUZZER_PIN);

    lcd.setCursor(0, 1);
    lcd.print("SAFE ");
    lcd.print(gasValue);
  }

  delay(1000);
}
