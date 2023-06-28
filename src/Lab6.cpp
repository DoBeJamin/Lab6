/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/benja/OneDrive/Desktop/visualStudioCode/summerIOT/Lab6/src/Lab6.ino"
void setup();
void loop();
#line 1 "c:/Users/benja/OneDrive/Desktop/visualStudioCode/summerIOT/Lab6/src/Lab6.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

//import
#include "oled-wing-adafruit.h"

OledWingAdafruit display;

void setup() {
  
  //initialize pin
  pinMode(A5, INPUT);

}

void loop() {

  // prevents epilepsy
  delay(100);

  //format screen 
	display.loop();  
  display.setup();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
 
  //calculate temperatures
  uint64_t reading = analogRead(A5);
  double voltage = (reading * 3.3) / 4095.0;
  double temperature_celcius = (voltage - 0.5) * 100;
  double temperature_fahrenheit = (temperature_celcius * 9.0 / 5.0) + 32.0;

  //format Text
  display.println("TEMPERATURE");
  display.print(temperature_celcius);
  display.print("C : ");
  display.print(temperature_fahrenheit);
  display.print("F");

  //
  display.display();

}