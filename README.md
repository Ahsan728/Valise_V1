# Valise
This is the firmware of Voltage, current, noise and temperature data acquisition system. We are implementing this system in Arduino SAMD board which is a LTE-M device.
Our PCB has been designed in Kikad. The major component of our system is a Texas Instruments ADC (Analog to Digital converter) package name ADS131M08. This ADC has eight channel analog data reading capability. 


## Fast Clock Generation for ADS131 
We are using Arduino SAMD21 Turbo PWM [library] (https://github.com/ocrdu/Arduino_SAMD21_turbo_PWM) for generating 2/4/8 MHz clock for the ADC. 
