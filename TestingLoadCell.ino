//Jack Shaver
//Testing Load Cell Sub Master Controller
// 2/16/2024

#include <Arduino.h>
#include "HX711.h"

#define LOADCELL_DATA_PIN 31
#define LOADCELL_CLK_PIN 32
#define LOADCELL_CALIBRATION_FACTOR 15.94

HX711 loadCell;

void setup() {
  Serial.begin(9600);
  Serial.println("Measuring the Load Cell");

  loadCell.begin(LOADCELL_DATA_PIN, LOADCELL_CLK_PIN);
  loadCell.set_scale(LOADCELL_CALIBRATION_FACTOR);
  loadCell.power_up();

  delay(1000);

  loadCell.tare();
}

void loop() {
  Serial.print("Current Reading: ");
  Serial.println(loadCell.get_units(10), 1);
  delay(100);
}
