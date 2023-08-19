// moisture-test.ino
// Eric Graves
// Created 8/18/2023

// Arduino script to test powering and reading from moisture sensor. 
// Also useful for calibration via potentiometer on sensor board. 

#define BAUD_DEBUG 9600
#define SAMPLE_PERIOD_MS 1000 //3600000 // 1 hour 
#define SETTLING_TIME_MS 1000    // 1 sec
// Pins:
#define D_SENSOR_VCC 13 
#define A_SENSE_PIN 0


// Calibration values:
#define SATURATED_VAL 5 // reading when fully submerged in tap water


void setup() {
  
  Serial.begin(BAUD_DEBUG); 

  pinMode(D_SENSOR_VCC, OUTPUT);

  Serial.println("Starting moisture sensor script:");

}

void loop() {
  
  int moisture_val = 0;

  // Read moisture sensor
  // only power sensor when we want to read it
  digitalWrite(D_SENSOR_VCC, HIGH);
  delay(SETTLING_TIME_MS);

  moisture_val = analogRead(A_SENSE_PIN);
  Serial.println(String("Read: ") + moisture_val + "\n");

  digitalWrite(D_SENSOR_VCC, LOW);

  // Time delay
  delay(SAMPLE_PERIOD_MS);

}
