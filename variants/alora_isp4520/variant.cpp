/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2018, Adafruit Industries (adafruit.com)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

#include "wiring_constants.h"
#include "wiring_digital.h"
#include "nrf.h"

const uint32_t g_ADigitalPinMap[] = {
	// D0 - D7
	0, // xtal 1
	1, // xtal 2
	2, // A0
	3, // A1
	4, // A2
	5, // A3
	6, // TXD
	7, // GPIO #7

	// D8 - D13
	8, // RXD

	9,  // LED #1 (red) / FRST
	10, // LED #2 (blue) / DFU

	11, // Not exposed DIO1 of SX1262

	12, // GPIO #12
	13, // GPIO #13
	14, // GPIO #14
	15, // GPIO #15

	16, // SCL

	17, // GPIO #17
	18, // GPIO #18 / SWO

	19, // Not exposed NRST of SX1262

	20, // SDA
	21, // Reset

	22, // MOSI SPI #2

	23, // Not exposed SCK of SX1262
	24, // Not exposed NSS of SX1262

	25, // Not exposed MISO of SX1262
	26, // Not exposed MOSI of SX1262
	27, // Not exposed BUSY of SX1262

	28, // A4
	29, // A5

	30, // SCK SPI #2
	31, // MISO SPI #2

};

void initVariant()
{
  // LED1 & LED2
  pinMode(PIN_LED1, OUTPUT);
  ledOff(PIN_LED1);

  pinMode(PIN_LED2, OUTPUT);
  ledOff(PIN_LED2);
}

