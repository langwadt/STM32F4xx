/*
  protoneer_3.xx_map.h - driver code for STM32F411 ARM processor on a Nucleo-F411RE board

  Part of grblHAL

  Copyright (c) 2020-2021 Terje Io

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#if TRINAMIC_ENABLE
#error Trinamic plugin not supported!
#endif

#define BOARD_NAME "Protoneer v3"
#define I2C_PORT 1
#define IS_NUCLEO_BOB

// Define step pulse output pins.
#define X_STEP_PORT             GPIOA // D2
#define X_STEP_PIN              10
#define X_STEP_BIT              (1<<X_STEP_PIN)
#define Y_STEP_PORT             GPIOB // D3
#define Y_STEP_PIN              3
#define Y_STEP_BIT              (1<<Y_STEP_PIN)
#define Z_STEP_PORT             GPIOB // D4
#define Z_STEP_PIN              5
#define Z_STEP_BIT              (1<<Z_STEP_PIN)
#define STEP_OUTMODE            GPIO_BITBAND
//#define STEP_PINMODE            PINMODE_OD // Uncomment for open drain outputs

// Define step direction output pins.
#define X_DIRECTION_PORT        GPIOB // D5
#define X_DIRECTION_PIN         4
#define X_DIRECTION_BIT         (1<<X_DIRECTION_PIN)
#define Y_DIRECTION_PORT        GPIOB // D6
#define Y_DIRECTION_PIN         10
#define Y_DIRECTION_BIT         (1<<Y_DIRECTION_PIN)
#define Z_DIRECTION_PORT        GPIOA // D7
#define Z_DIRECTION_PIN         8
#define Z_DIRECTION_BIT         (1<<Z_DIRECTION_PIN)
#define DIRECTION_OUTMODE       GPIO_BITBAND
//#define DIRECTION_PINMODE       PINMODE_OD // Uncomment for open drain outputs

// Define stepper driver enable/disable output pin.
#define STEPPERS_DISABLE_PORT   GPIOA // D8
#define STEPPERS_DISABLE_PIN    9
#define STEPPERS_DISABLE_BIT    (1<<STEPPERS_DISABLE_PIN)
#define STEPPERS_DISABLE_MASK   STEPPERS_DISABLE_BIT
//#define STEPPERS_DISABLE_PINMODE PINMODE_OD // Uncomment for open drain outputs

// Define homing/hard limit switch input pins.
#define X_LIMIT_PORT            GPIOC // D9
#define X_LIMIT_PIN             7
#define X_LIMIT_BIT             (1<<X_LIMIT_PIN)
#define Y_LIMIT_PORT            GPIOB // D10
#define Y_LIMIT_PIN             6
#define Y_LIMIT_BIT             (1<<Y_LIMIT_PIN)
#define Z_LIMIT_PORT            GPIOA // D11
#define Z_LIMIT_PIN             7
#define Z_LIMIT_BIT             (1<<Z_LIMIT_PIN)
#define LIMIT_MASK              (X_LIMIT_BIT|Y_LIMIT_BIT|Z_LIMIT_BIT) // All limit bits
#define LIMIT_INMODE            GPIO_BITBAND

// Define A axis step pulse and step direction output pins.
#ifdef A_AXIS
#define A_STEP_PORT             GPIOA // D12
#define A_STEP_PIN              6
#define A_STEP_BIT              (1<<A_STEP_PIN)
#define A_DIRECTION_PORT        GPIOA // D13
#define A_DIRECTION_PIN         5
#define A_DIRECTION_BIT         (1<<A_DIRECTION_PIN)
#endif

// Define spindle enable and spindle direction output pins.
#ifndef A_AXIS
#define SPINDLE_ENABLE_PORT     GPIOA // D12
#define SPINDLE_ENABLE_PIN      6
#define SPINDLE_ENABLE_BIT      (1<<SPINDLE_ENABLE_PIN)
#define SPINDLE_DIRECTION_PORT  GPIOA // D13
#define SPINDLE_DIRECTION_PIN   5
#define SPINDLE_DIRECTION_BIT   (1<<SPINDLE_DIRECTION_PIN)
#else
// use A4 & A5?
#endif

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT      GPIOB // A3
#define COOLANT_FLOOD_PIN       0
#define COOLANT_FLOOD_BIT       (1<<COOLANT_FLOOD_PIN)

// Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
#define CONTROL_PORT            GPIOA // A0
#define RESET_PIN               0
#define RESET_BIT               (1<<RESET_PIN)
#define FEED_HOLD_PIN           1 // A1
#define FEED_HOLD_BIT           (1<<FEED_HOLD_PIN)
#define CYCLE_START_PIN         4 // A2
#define CYCLE_START_BIT         (1<<CYCLE_START_PIN)
#define CONTROL_MASK            (RESET_BIT|FEED_HOLD_BIT|CYCLE_START_BIT)
#define CONTROL_INMODE          GPIO_MAP

/**/
