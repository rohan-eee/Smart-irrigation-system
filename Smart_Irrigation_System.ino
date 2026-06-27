#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

// Pins
const int soilPin = A0;
const int tankPin = A1;
const int relayPin = 9;
const int greenLED = 8;
const int redLED = 7;

// Variables
int moisture;
int waterLevel;
float temperature;
float humidity;

void setup() {

  pinMode(relayPin, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  dht.begin();

  lcd.setCursor(0,0);
  lcd.print("Smart");
  lcd.setCursor(0,1);
  lcd.print("Irrigation");
  delay(2000);
  lcd.clear();
}

void loop() {

  moisture = analogRead(soilPin);
  waterLevel = analogRead(tankPin);

  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  Serial.print("Moisture: ");
  Serial.print(moisture);

  Serial.print("  Tank: ");
  Serial.print(waterLevel);

  Serial.print("  Temp: ");
  Serial.print(temperature);

  Serial.print("  Humidity: ");
  Serial.println(humidity);

  // Pump Control
  if (moisture < 500) {

    if (waterLevel > 300) {

      digitalWrite(relayPin, HIGH);
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);

    } else {

      digitalWrite(relayPin, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);

    }

  } else {

    digitalWrite(relayPin, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

  }

  // LCD Screen 1
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temperature,1);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Hum:");
  lcd.print(humidity,0);
  lcd.print("%");

  delay(2000);

  // LCD Screen 2
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Moist:");
  lcd.print(moisture);

  lcd.setCursor(0,1);

  if (moisture >= 500) {

    lcd.print("Soil Wet");

  } else {

    if (waterLevel > 300) {

      lcd.print("Pump ON");

    } else {

      lcd.print("Tank Empty");

    }
  }

  delay(2000);
}
