# STM32-DHT11-LCD
This project involves interfacing an STM32F103C8T6 microcontroller to a DHT11 sensor module and a 16x2 LCD Display for real-time recording of temperature and humidity.
The main components used in the setup are:
- STM32 Blue Pill Development Board
- DHT11 Sensor module
- 16x2 LCD Display
- USB to TTL Serial Converter module -> for debugging the STM32 MCU
- 10K Potentiometer -> for varying the contrast on the LCD Display

The hardware setup is shown in the schematic below:
![Schematic](https://github.com/maina-patrick/STM32-DHT11-LCD/blob/main/Images/Schematic.png "Schematic")

I was not able to implement an I2C Serial Adapter module in the hardware setup, and that explains the numerous connections between the LCD Display and the STM32 MCU.

The Software can be found in the "Software" folder in this repository.

The results can be seen in the pictorials below:
![Prototype](https://github.com/maina-patrick/STM32-DHT11-LCD/blob/main/Images/Image%202.jpg "DHT11 Sensor Prototype")


![Temp and Humid](https://github.com/maina-patrick/STM32-DHT11-LCD/blob/main/Images/Image%201.jpg "Temp and Humidity Readings")
