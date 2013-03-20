#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

// ATMEL ATMEGA1284P
//
//                       +---\/---+
//           (D 8) PB0  1|        |40  PA0 (AI 5 / D29)
//           (D 9) PB1  2|        |39  PA1 (AI 4 / D28)
//     INT2 (D 14) PB2  3|        |38  PA2 (AI 3 / D27)
//      PWM (D 15) PB3  4|        |37  PA3 (AI 2 / D26)
//   PWM/SS (D 10) PB4  5|        |36  PA4 (AI 1 / D25)
//     MOSI (D 11) PB5  6|        |35  PA5 (AI 0 / D24)
// PWM/MISO (D 12) PB6  7|        |34  PA6 (AI 6 / D30)
//  PWM/SCK (D 13) PB7  8|        |33  PA7 (AI 7 / D31)
//                 RST  9|        |32  AREF
//                 VCC 10|        |31  GND 
//                 GND 11|        |30  AVCC
//               XTAL2 12|        |29  PC7 (D 23)
//               XTAL1 13|        |28  PC6 (D 22)
//       RX0 (D 0) PD0 14|        |27  PC5 (D 21) TDI
//       TX0 (D 1) PD1 15|        |26  PC4 (D 20) TDO
//  RX1/INT0 (D 2) PD2 16|        |25  PC3 (D 19) TMS
//  TX1/INT1 (D 3) PD3 17|        |24  PC2 (D 18) TCK
//       PWM (D 4) PD4 18|        |23  PC1 (D 17) SDA
//       PWM (D 5) PD5 19|        |22  PC0 (D 16) SCL
//       PWM (D 6) PD6 20|        |21  PD7 (D 7) PWM
//                       +--------+
//

/*
   PCINT15-8: D7-0  : bit 1
   PCINT31-24: D15-8  : bit 3
   PCINT23-16: D23-16 : bit 2
   PCINT7-0: D31-24   : bit 0
   */

#define NUM_DIGITAL_PINS            31
#define NUM_ANALOG_INPUTS           8
//#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + 24 : -1)
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + 24 : -1)

#define digitalPinToAnalogPin(p)    ( (p) >= 24 && (p) <= 31 ? ((p) < 30 ? 5-((p)-24) : ((p) - 24)) : (((p)<=5) ? 5-(p) : (((p)<=7) ? (p) : -1 )) )
#define digitalPinHasPWM(p)         ((p) == 4 || (p) == 5 || (p) == 6 || (p) == 7 || (p) == 10 || (p) == 12 || (p) == 13 || (p) == 15)

static const uint8_t SS   = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 12;
static const uint8_t SCK  = 13;

static const uint8_t SDA = 17;
static const uint8_t SCL = 16;
static const uint8_t LED = 23;

static const uint8_t A0 = 24;
static const uint8_t A1 = 25;
static const uint8_t A2 = 26;
static const uint8_t A3 = 27;
static const uint8_t A4 = 28;
static const uint8_t A5 = 29;
static const uint8_t A6 = 30;
static const uint8_t A7 = 31;

#define digitalPinToPCICR(p)    ifpin(p,&PCICR,(uint8_t *)0)
#define digitalPinToPCICRbit(p) ifpin(p,digital_pin_to_pcint[p] >> 3,(uint8_t *)0)
#define digitalPinToPCMSK(p)    ifpin(p,__pcmsk[digital_pin_to_pcint[]],(uint8_t *)0)
#define digitalPinToPCMSKbit(p) ifpin(p,digital_pin_to_pcint[p] & 0x7,(uint8_t *)0)

#ifdef ARDUINO_MAIN

#define PA 1
#define PB 2
#define PC 3
#define PD 4

const uint8_t digital_pin_to_pcint[NUM_DIGITAL_PINS] =
{
  24, // D0 PD0
  25, // D1 PD1
  26, // D2 PD2
  27, // D3 PD3
  28, // D4 PD4
  29, // D5 PD5
  30, // D6 PD6
  31, // D7 PD7
  8, // D8 PB0
  9, // D9 PB1
  12, // D10 PB4
  13, // D11 PB5
  14, // D12 PB6
  15, // D13 PB7
  10, // D14 PB2
  11, // D15 PB3
  16, // D16 PC0
  17, // D17 PC1
  18, // D18 PC2
  19, // D19 PC3
  20, // D20 PC4
  21, // D21 PC5
  22, // D22 PD6
  23, // D23 PC7

  5, // D31 PA7
  4, // D30 PA6
  3, // D24 PA5
  2, // D25 PA4
  1, // D26 PA3
  0, // D27 PA2
  6, // D28 PA1
  7, // D29 PA0

//  7, // D31 PA7
//  6, // D30 PA6
//  0, // D24 PA5
//  1, // D25 PA4
//  2, // D26 PA3
//  3, // D27 PA2
//  4, // D28 PA1
//  5, // D29 PA0
};

const uint16_t __pcmsk[] = 
{
  (uint16_t)&PCMSK0, 
  (uint16_t)&PCMSK1, 
  (uint16_t)&PCMSK2, 
  (uint16_t)&PCMSK3
};

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] =
{
	PD, /* 0 */
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PB, /* 8 */
	PB,
	PB,
	PB,
	PB,
	PB,
	PB,
	PB,
	PC, /* 16 */
	PC,
	PC,
	PC,
	PC,
	PC,
   	PC,
	PC,
	PA, /* 24 */
	PA,
	PA,
	PA,
	PA,
	PA,
	PA,
	PA  /* 31 */
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
{
	_BV(0), /* 0, port D */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* 8, port B */
	_BV(1),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(2),
	_BV(3),
	_BV(0), /* 16, port C */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(5), /* 24, port A */
	_BV(4),
	_BV(3),
	_BV(2),
	_BV(1),
	_BV(0),
	_BV(6),
	_BV(7)
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
	NOT_ON_TIMER, 	/* 1 - PD0 */
	NOT_ON_TIMER, 	/* 2 - PD1 */
	NOT_ON_TIMER, 	/* 3 - PD2 */
	NOT_ON_TIMER, 	/* 4 - PD3 */
	TIMER1B,     	/* 5 - PD4 */
	TIMER1A,     	/* 6 - PD5 */
	TIMER2B,     	/* 7 - PD6 */
	TIMER2A,     	/* 8 - PD7 */

	NOT_ON_TIMER, 	/* 8  - PB0 */
	NOT_ON_TIMER, 	/* 9  - PB1 */
	TIMER0B, 	/* 10 - PB4 */
	NOT_ON_TIMER, 	/* 11 - PB5 */
	TIMER3A, 	/* 12 - PB6 */
	TIMER3B,	/* 13 - PB7 */
	NOT_ON_TIMER, 	/* 14 - PB2 */
	TIMER0A,     	/* 15 - PB3 */

	NOT_ON_TIMER, 	/* 16 - PC0 */
	NOT_ON_TIMER,   /* 17 - PC1 */
	NOT_ON_TIMER,   /* 18 - PC2 */
	NOT_ON_TIMER,   /* 19 - PC3 */
	NOT_ON_TIMER,   /* 20 - PC4 */
	NOT_ON_TIMER,   /* 21 - PC5 */
	NOT_ON_TIMER,   /* 22 - PC6 */
	NOT_ON_TIMER,   /* 23 - PC7 */
	NOT_ON_TIMER,   /* 24 - PA0 */
	NOT_ON_TIMER,   /* 25 - PA1 */
	NOT_ON_TIMER,   /* 26 - PA2 */
	NOT_ON_TIMER,   /* 27 - PA3 */
	NOT_ON_TIMER,   /* 28 - PA4 */
	NOT_ON_TIMER,   /* 29 - PA5 */
	NOT_ON_TIMER,   /* 30 - PA6 */
	NOT_ON_TIMER    /* 31 - PA7 */
};

#endif // ARDUINO_MAIN

#endif // Pins_Arduino_h
// vim:ai:cin:sts=2 sw=2 ft=cpp
