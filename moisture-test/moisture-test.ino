// moisture-test.ino
// Eric Graves
// Created 8/18/2023

// Arduino script to test powering and reading from moisture sensor. 
// Also useful for calibration via potentiometer on sensor board. 

// - Different plants require different amounts of water.
// - Need data for each plant type, pot type, and soil type.

// Data below:
// 
// Regular potting Soil
//=========================================
// Pothos, small pot:
//    after watering: ~680 +-10 
//
// Cactus potting soil
//=========================================
// Snake Plant, large pot
//    no watering: ~500 +-10


#define __DEBUG__

#ifdef __DEBUG__
#define DEBUG_SO(...) Serial.println(__VA_ARGS__)
#else
#define DEBUG_SO(...)
#endif

#define BAUD_DEBUG 9600
#define SAMPLE_PERIOD_MS 1000     // 1 sec //3600000 // 1 hour 
#define SETTLING_TIME_MS 1000     // 1 sec
// Pins:
#define D_SENSOR_VCC 7 
#define A_SENSE_PIN 0


// Calibration values:
// Dry sensor gives value ~987
#define SATURATED_VAL 300 // reading when fully submerged in tap water
#define DRY_LEVEL 700 // level at which to water


void setup() 
{  
  #ifdef __DEBUG__
  Serial.begin(BAUD_DEBUG); 
  #endif

  pinMode(D_SENSOR_VCC, OUTPUT);

  DEBUG_SO("Starting moisture sensor script:");

}

void loop() 
{
  int moisture_reading = 0;

  // Read moisture sensor
  // only power sensor when we want to read it
  digitalWrite(D_SENSOR_VCC, HIGH);
  delay(SETTLING_TIME_MS);

  moisture_reading = analogRead(A_SENSE_PIN);
  DEBUG_SO(String("Read: ") + moisture_reading + "\n");

  if(moisture_reading > DRY_LEVEL)
  {
    // Time to water!
    DEBUG_SO("Water me please!");

    // TODO add motor controls and stuff
  }

  digitalWrite(D_SENSOR_VCC, LOW);

  // Time delay
  delay(SAMPLE_PERIOD_MS);

}
