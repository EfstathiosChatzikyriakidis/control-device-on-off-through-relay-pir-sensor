/*
 *  Control Device (On/Off) Through Relay & PIR Sensor.
 *
 *  Copyright (C) 2010 Efstathios Chatzikyriakidis (contact@efxa.org)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

const uint8_t sensorPin = 5; // the sensor pin number.
const uint8_t relayPin = 7;  // the relay pin number.

// sensor calibration time (10-60 secs according to the datasheet).
const int32_t calibrationTime = 30000; // 30 secs here.

// delay time the device will stay on.
const int32_t delayTime = 10000;

// startup point entry (runs once).
void
setup () {
  // set the input sensor as input.
  pinMode(sensorPin, INPUT);

  // set the relay as output.
  pinMode(relayPin, OUTPUT);

  // give the sensor some time to calibrate.
  delay(calibrationTime);
}

// loop the main sketch.
void
loop () {
  // check if there is a motion.
  if (digitalRead(sensorPin) == HIGH) {
    // on the device.
    digitalWrite(relayPin, HIGH);

    // wait some time.
    delay(delayTime);
  }
  else
    // off the device.
    digitalWrite(relayPin, LOW);
}
