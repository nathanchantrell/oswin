#For the OSWIN ATmega1284P based Arduino compatible http://zorg.org/oswin/
By Nathan Chantrell.


##Emoncms gateway: oswin_emoncms
Receives data from multiple TinyTX sensors and/or emonTX and uploads to an emoncms server.


##Arduino core and bootloader: core
Copy the oswin directory to your Arduino hardware directory.
Uses the Bobuino pinout with the MAX1284 bootloader (http://max1284.homelabs.org.uk/) by Andrew Lindsay, based on maniacbugs Mighty-1284P: http://maniacbug.wordpress.com/2011/11/27/arduino-on-atmega1284p-4/


##RFM12B Support

Use of the RFM12B requires a modification to Jeelib library to add support for ATmega1284P as follows:

In RF12.cpp

Add new pin definitions for OSWIN:

#elif defined(__AVR_ATmega1284P__)

  #define RFM_IRQ     6     // The PIN the IRQ is on
  #define RFM_IRQ_NO  2     // The IRQ number
  #define SS_DDR      DDRC
  #define SS_PORT     PORTC
  #define SS_BIT      5

  #define SPI_SS      10    // PB4, pin 5
  #define SPI_MOSI    11    // PB5, pin 6
  #define SPI_MISO    12    // PB6, pin 7
  #define SPI_SCK     13    // PB7, pin 8


AND CHANGE:

  #else
      if ((nodeid & NODE_ID) != 0)
          attachInterrupt(0, rf12_interrupt, LOW);
      else
          detachInterrupt(0);
  #endif

TO:

  #else
      #if RFM_IRQ_NO  // If IRQ number is defined use that, if not use IRQ0
      if ((nodeid & NODE_ID) != 0)
          attachInterrupt(RFM_IRQ_NO, rf12_interrupt, LOW);
      else
          detachInterrupt(RFM_IRQ_NO);
      #else
      if ((nodeid & NODE_ID) != 0)
          attachInterrupt(0, rf12_interrupt, LOW);
      else
          detachInterrupt(0);
      #endif
  #endif
