# Platform files for Arduino for the OSWIN ATmega1284P based board http://zorg.org/oswin
# Using the MAX1284P bootloader based on Mighty-1284P

3 optiboot bootloaders for the clock speeds 16MHz, 12MHz and 8MHz are available. 12MHz and 8MHz are in spec at 3.3V, 16MHz is not.

The baudrate for 8MHz boards has been reduced to make it more reliable.

OSWIN's Blue LED is on PB3 (Arduino D7) and flashes on code upload.

## Installation

1. Download the [ZIP File]
2. Unzip it a folder called 'hardware' off your sketches directory, e.g. /Users/sketchbook/hardware/oswin
3. Restart the IDE
4. Select Tools > Board > OSWIN ATMega1284P 12MHz using Optiboot
5. To burn the bootloader, follow the Arduino [Bootloader](http://arduino.cc/en/Hacking/Bootloader) instructions.

## Requirements

* Works only on Arduino >= 1.0
* Cannot be burned using [USBtinyISP](http://www.ladyada.net/make/usbtinyisp/).  That programmer cannot flash to chips with >64k flash size.
* ArduinoISP has been used successfully to burn the bootloader, either using the ICSP header or with chip installed on breadboard.

## Thanks to
Maniacbug for providing original bootloader code: http://maniacbug.wordpress.com/2011/11/27/arduino-on-atmega1284p-4/
and Andrew Lindsay for 12MHz and 8MHz versions: http://max1284.homelabs.org.uk/

## OSWIN is using the Bobuino pinout for ATMEGA1284P:

```
                       +---\/---+
           (D 4) PB0 1 |        | 40 PA0 (D 21) AI 7
           (D 5) PB1 2 |        | 39 PA1 (D 20) AI 6
      INT2 (D 6) PB2 3 |        | 38 PA2 (D 19) AI 5
       PWM (D 7) PB3 4 |        | 37 PA3 (D 18) AI 4
   PWM/SS (D 10) PB4 5 |        | 36 PA4 (D 17) AI 3
     MOSI (D 11) PB5 6 |        | 35 PA5 (D 16) AI 2
 PWM/MISO (D 12) PB6 7 |        | 34 PA6 (D 15) AI 1
  PWM/SCK (D 13) PB7 8 |        | 33 PA7 (D 14) AI 0
                 RST 9 |        | 32 AREF
                VCC 10 |        | 31 GND 
                GND 11 |        | 30 AVCC
              XTAL2 12 |        | 29 PC7 (D 29) 
              XTAL1 13 |        | 28 PC6 (D 28) 
      RX0 (D 0) PD0 14 |        | 27 PC5 (D 27) TDI
      TX0 (D 1) PD1 15 |        | 26 PC4 (D 26) TDO
 INT0 RX1 (D 2) PD2 16 |        | 25 PC3 (D 25) TMS
 INT1 TX1 (D 3) PD3 17 |        | 24 PC2 (D 24) TCK
     PWM (D 30) PD4 18 |        | 23 PC1 (D 23) SDA
      PWM (D 8) PD5 19 |        | 22 PC0 (D 22) SCL
      PWM (D 9) PD6 20 |        | 21 PD7 (D 31) PWM
                       +--------+
```

