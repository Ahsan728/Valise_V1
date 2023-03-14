# Valise
This is the firmware of Voltage, current, noise and temperature data acquisition system. We are implementing this system in Arduino SAMD board which is a LTE-M device.
Our PCB has been designed in Kikad. The major component of our system is a Texas Instruments ADC (Analog to Digital converter) package name ADS131M08. This ADC has eight channel analog data reading capability. 


## Fast Clock Generation for ADS131 
We are using Arduino SAMD21 Turbo PWM [library](https://github.com/ocrdu/Arduino_SAMD21_turbo_PWM) for generating 2/4/8 MHz clock for the ADC. 
SAMD21's timers TCC0, TCC1, and TCC2 to generate PWM signals on eight pins:
MKR series (untested): 2, 3, 4, 5, 6, 7, 8, and 9;

#### Include the library:

#include <SAMD21turboPWM.h>

#### Create a TurboPWM object (called pwm here):

TurboPWM pwm;

#### Set input clock divider and Turbo Mode (which uses a 96MHz instead of a 48Mhz input clock):

pwm.setClockDivider([1-255], [true, false]);

#### Initialise timer x, with prescaler, with steps (resolution), with fast aka single-slope PWM (or not -> double-slope PWM):

pwm.timer([0, 1, 2], [1, 2, 4, 8, 16, 64, 256, 1024], [2-MaxSteps], [true, false]);

- For the Arduino MKR series, we need to initialise timer 1 for pins 2 and 3, timer 0 for pins 4, 5, 6 and 7, and timer 2 for pins 8 and 9;
MaxSteps is 0xFFFFFF for (24-bits) timers 0 and 1, and 0xFFFF for (16 bits) timer 2.
#### Start PWM on a pin with a duty cycle:

pwm.analogWrite([pin number], [0-1000]);

#### Enable/disable a timer:

pwm.enable([0, 1, 2], [true, false]);

#### Get a timer's current PWM frequency:

pwm.frequency([0, 1, 2]);

