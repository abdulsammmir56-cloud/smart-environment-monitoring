
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ========================================
// PIN DEFINITIONS
// ========================================

#define DHT_PIN 4
#define DHT_TYPE DHT22

#define MQ2_PIN 34

#define OLED_SDA 21
#define OLED_SCL 22

#define LED_PIN 2
#define BUZZER_PIN 5

// ========================================
// OLED CONFIGURATION
// ========================================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

// ========================================
// DHT22
// ========================================

DHT dht(DHT_PIN, DHT_TYPE);

// ========================================
// SAFETY THRESHOLDS
// Simulation values
// ========================================

const float TEMP_LIMIT = 35.0;
const float HUMIDITY_LIMIT = 80.0;
const int GAS_LIMIT = 2000;

// ========================================
// SETUP
// ========================================

void setup() {

  // Serial communication
  Serial.begin(115200);

  // Start DHT22
  dht.begin();

  // Configure LED and buzzer
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Initially turn alarm OFF
  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);

  // Start I2C
  Wire.begin(OLED_SDA, OLED_SCL);

  // Start OLED
  if (!display.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_ADDRESS
      )) {

    Serial.println("ERROR: OLED initialization failed!");

    while (true) {
      delay(100);
    }
  }

  // ========================================
  // STARTUP SCREEN
  // ========================================

  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);

  display.setCursor(0, 0);
  display.println("SMART ENVIRONMENT");

  display.setCursor(0, 12);
  display.println("MONITORING SYSTEM");

  display.setCursor(0, 30);
  display.println("Initializing...");

  display.display();

  delay(2000);

  display.clearDisplay();

  display.setCursor(0, 20);
  display.println("System Ready");

  display.display();

  delay(1000);
}

// ========================================
// MAIN LOOP
// ========================================

void loop() {

  // ========================================
  // READ DHT22
  // ========================================

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check DHT22
  if (isnan(temperature) || isnan(humidity)) {

    Serial.println("ERROR: DHT22 reading failed!");

    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);

    display.clearDisplay();

    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("SENSOR ERROR");

    display.setCursor(0, 20);
    display.println("DHT22 reading");

    display.setCursor(0, 32);
    display.println("failed!");

    display.display();

    delay(2000);

    return;
  }

  // ========================================
  // READ MQ-2
  // ========================================

  int gasValue = analogRead(MQ2_PIN);

  // ========================================
  // CHECK SAFETY LIMITS
  // ========================================

  bool temperatureAlert =
    temperature > TEMP_LIMIT;

  bool humidityAlert =
    humidity > HUMIDITY_LIMIT;

  bool gasAlert =
    gasValue > GAS_LIMIT;

  bool danger =
    temperatureAlert ||
    humidityAlert ||
    gasAlert;

  // ========================================
  // CONTROL LED + BUZZER
  // ========================================

  if (danger) {

    digitalWrite(LED_PIN, HIGH);

    tone(BUZZER_PIN, 1000);

  } else {

    digitalWrite(LED_PIN, LOW);

    noTone(BUZZER_PIN);
  }

  // ========================================
  // SERIAL MONITOR
  // ========================================

  Serial.println();
  Serial.println("================================");
  Serial.println("       SENSOR READINGS");
  Serial.println("================================");

  Serial.print("Temperature : ");
  Serial.print(temperature, 1);
  Serial.println(" C");

  Serial.print("Humidity    : ");
  Serial.print(humidity, 1);
  Serial.println(" %");

  Serial.print("Gas Level   : ");
  Serial.println(gasValue);

  Serial.println();

  // ========================================
  // DISPLAY STATUS
  // ========================================

  if (danger) {

    Serial.println("STATUS: WARNING");

    if (temperatureAlert) {
      Serial.println("Reason: Temperature HIGH");
    }

    if (humidityAlert) {
      Serial.println("Reason: Humidity HIGH");
    }

    if (gasAlert) {
      Serial.println("Reason: Gas Level HIGH");
    }

  } else {

    Serial.println("STATUS: SAFE");
  }

  Serial.println("================================");

  // ========================================
  // OLED DISPLAY
  // ========================================

  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);

  // Title
  display.setTextSize(1);

  display.setCursor(0, 0);
  display.println("ENVIRONMENT MONITOR");

  // Temperature
  display.setCursor(0, 13);
  display.print("Temp: ");
  display.print(temperature, 1);
  display.println(" C");

  // Humidity
  display.setCursor(0, 25);
  display.print("Hum : ");
  display.print(humidity, 1);
  display.println(" %");

  // Gas
  display.setCursor(0, 37);
  display.print("Gas : ");
  display.println(gasValue);

  // Status
  display.setCursor(0, 50);

  if (danger) {

    display.print("WARNING!");

  } else {

    display.print("STATUS: SAFE");
  }

  display.display();

  // ========================================
  // WAIT
  // ========================================

  delay(2000);
}

