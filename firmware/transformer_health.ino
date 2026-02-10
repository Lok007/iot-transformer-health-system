// Embedded firmware for transformer health monitoring
// Implements sensing and relay-based protection logic

#include <OneWire.h>
#include <DallasTemperature.h>

// ---------------- Pin Configuration ----------------
#define TEMP_SENSOR_PIN     4
#define CURRENT_SENSOR_PIN  34
#define PROTECTION_RELAY    26

// ---------------- Safety Thresholds ----------------
#define MAX_TEMP_C          70.0
#define MAX_CURRENT_A       5.0

// ---------------- Sensor Setup ---------------------
OneWire oneWireBus(TEMP_SENSOR_PIN);
DallasTemperature temperatureProbe(&oneWireBus);

// --------------------------------------------------
void setup() {
  Serial.begin(115200);

  pinMode(PROTECTION_RELAY, OUTPUT);
  digitalWrite(PROTECTION_RELAY, LOW);

  temperatureProbe.begin();

  Serial.println("Transformer Health Monitoring System");
  Serial.println("------------------------------------");

  if (temperatureProbe.getDeviceCount() == 0) {
    Serial.println("Error: Temperature sensor not detected");
    while (true);
  }

  Serial.println("System ready");
}

// --------------------------------------------------
void loop() {
  // Acquire temperature data
  temperatureProbe.requestTemperatures();
  float tempReading = temperatureProbe.getTempCByIndex(0);

  // Acquire current data
  int adcValue = analogRead(CURRENT_SENSOR_PIN);
  float sensedVoltage = (adcValue / 4095.0) * 3.3;
  float loadCurrent = (sensedVoltage - 1.65) / 0.066;

  Serial.println("------------------------------");
  Serial.print("Temperature: ");
  Serial.print(tempReading);
  Serial.println(" C");

  Serial.print("Current: ");
  Serial.print(loadCurrent);
  Serial.println(" A");

  // Protection logic
  if (tempReading > MAX_TEMP_C || abs(loadCurrent) > MAX_CURRENT_A) {
    Serial.println("Warning: Unsafe condition detected");
    digitalWrite(PROTECTION_RELAY, HIGH);
  } else {
    Serial.println("Operating within safe limits");
    digitalWrite(PROTECTION_RELAY, LOW);
  }

  delay(2500);
}
