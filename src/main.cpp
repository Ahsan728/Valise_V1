#include <Arduino.h>
#include <SAMD21turboPWM.h>
#include "ADS131M08.h"
#include <SPI.h>

//ADC SPI Parameters;
#define ADC_CS          14       // à corriger
#define ADC_CS1         6        // ADC Non utilisé
#define ADC_XTAL_PIN    7        //
#define ADC_XTAL_VAL    2        // 2.048MHZ
#define ADC_DRDY_PIN    4        //
#define SPI_FREQ        2000000
#define RESET           2
ADS131M08 ADC_ADC131(ADC_CS, ADC_XTAL_PIN, ADC_DRDY_PIN, SPI_FREQ);

// DAC Parameters and waveforms
#define DAC_ANALOG_RESOLUTION 10
uint16_t DAC_Waveform[] = { 
    128,131,134,137,140,143,146,149,152,155,158,162,165,167,170,173,
    176,179,182,185,188,190,193,196,198,201,203,206,208,211,213,215,
    218,220,222,224,226,228,230,232,234,235,237,238,240,241,243,244,
    245,246,248,249,250,250,251,252,253,253,254,254,254,255,255,255,
    255,255,255,255,254,254,254,253,253,252,251,250,250,249,248,246,
    245,244,243,241,240,238,237,235,234,232,230,228,226,224,222,220,
    218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,
    176,173,170,167,165,162,158,155,152,149,146,143,140,137,134,131,  
    128,124,121,118,115,112,109,106,103,100,97,93,90,88,85,82,
    79,76,73,70,67,65,62,59,57,54,52,49,47,44,42,40,
    37,35,33,31,29,27,25,23,21,20,18,17,15,14,12,11,
    10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,
    0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,
    10,11,12,14,15,17,18,20,21,23,25,27,29,31,33,35,
    37,40,42,44,47,49,52,54,57,59,62,65,67,70,73,76,
    79,82,85,88,90,93,97,100,103,106,109,112,115,118,121,124
};

void ADC_SetParametres(ADS131M08 ADC_ADC131);
//Channels[number of channels Sampeld, Sampling Counter]= ADC_ReadChannels(S_Channels,S_Suration);

void setup() {
    /* Start Serial Comunication*/
      Serial.begin(9600);

    /* Start the clock for the ADC*/
    ADC_ADC131.init();
    ADC_SetParametres(ADC_ADC131);
    pinMode(ADC_CS1, OUTPUT);          // Disable the CS of ADC1, use only ADC2 in the Schematics
    digitalWrite(ADC_CS1, HIGH);

    //  Set up the DAC
      pinMode( A0, OUTPUT );
      analogWriteResolution( DAC_ANALOG_RESOLUTION );
}

void loop() {
static uint32_t loopCount = 0;
int32_t channelArr[8] = {};

if(digitalRead(ADC_DRDY_PIN)) {
    // Read Data
    ADC_ADC131.readAllChannels(channelArr);
    Serial.println(channelArr[0]);          // Print data in channel 1.

    // Output to the DAC
    analogWrite( A0, DAC_Waveform[loopCount]/1);
    loopCount = loopCount + 1;
    if (loopCount==255) {loopCount=0;}
  }
  else {
  }
}

void ADC_SetParametres(ADS131M08 ADC_ADC131){

  /* Reset the ADC */
  pinMode(RESET, OUTPUT);
  digitalWrite(RESET, LOW);
  delay(1);
  digitalWrite(RESET, HIGH);

  /* Write Setting Registers*/
  ADC_ADC131.writeReg(ADS131_CLOCK,0b1111111100011111); //Clock register (page 55 in datasheet)
  ADC_ADC131.setGain(1);
  //ADC_ADC131.globalChop(true,2);
  /* Read and check Register values*/
  uint16_t clkreg = ADC_ADC131.readReg(ADS131_CLOCK);
  uint16_t gainreg = ADC_ADC131.readReg(ADS131_GAIN1);
  Serial.print("CLOCK: ");
  Serial.println(clkreg,BIN);
  };