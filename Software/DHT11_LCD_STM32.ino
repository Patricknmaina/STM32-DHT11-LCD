/*
This program displays real-time temperature and humidity recordings
from the DHT11 sensor, which is interfaced to the STM32 blue pill
(STM32F103C8T6)
*/

// include LCD library code
#include <LiquidCrystal.h>
// include Adafruit DHT library code
#include <DHT.h>

// LCD module connections (RS, E, D4, D5, D6, D7) to the STM32 blue pill
LiquidCrystal lcd(PB11, PB10, PB0, PA7, PA6, PA5);

// Define the DHT pin and DHT module
#define DHTPIN  PA1           // DHT11 data pin is connected to Blue Pill PA1 pin
#define DHTTYPE DHT11         // DHT11 sensor is used
DHT dht11(DHTPIN, DHTTYPE);   // initialize DHT library

void setup() {

  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);           // move cursor to position (0, 0) -> 1st column & 1st row
  lcd.print("STM32 Blue Pill");  // print text on the LCD
  lcd.setCursor(0, 1);           // move cursor to position (0, 1) -> 1st column & 2nd row
  lcd.print("& DHT11 Sensor");
  
  delay(10000);    // wait 10 seconds
  lcd.clear();    // clear the display
  lcd.setCursor(0, 0);   // move cursor to position (0, 0) -> 1st column & 1st row
  lcd.print("Temp:");    // print text on the LCD
  lcd.setCursor(0, 1);   // move cursor to position (0, 1) -> 1st column & 2nd row
  lcd.print("Humid:");

  // initialize DHT11 sensor
  dht11.begin();

}

// data display buffer
char dis_buf[7];

void loop() {

  delay(1000);           // change the readings after 1 second

  // read humidity in rH%
  uint16_t H = dht11.readHumidity() * 10;
  // read temperature in degrees Celsius
  uint16_t T = dht11.readTemperature() * 10;

  /*// Check if any readings have failed and exit (to try again)
  if (isnan(H) || isnan(T)) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Error");
    return;
  }*/

  // print temperature (in °C)
  sprintf( dis_buf, "%02u.%1u%cC", (T / 10) % 100, T % 10, 223 );
  lcd.setCursor(6, 0);
  lcd.print(dis_buf);

  // print humidity (in %)
  sprintf( dis_buf, "%02u.%1u %%", (H / 10) % 100, H % 10 );
  lcd.setCursor(6, 1);
  lcd.print(dis_buf);

}