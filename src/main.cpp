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
long NumberOfSamples = 100;

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
//Register Table 
uint16_t ADC_Registers_Val[49] = {
 ADS131_MODE_VAL, 
 ADS131_CLOCK_VAL,
 ADS131_GAIN1_VAL, 
 ADS131_GAIN2_VAL, 
 ADS131_CFG_VAL, 
 ADS131_THRSHLD_MSB_VAL, 
 ADS131_THRSHLD_LSB_VAL, 
 ADS131_CH0_CFG_VAL, 
 ADS131_CH0_OCAL_MSB_VAL, 
 ADS131_CH0_OCAL_LSB_VAL, 
 ADS131_CH0_GCAL_MSB_VAL, 
 ADS131_CH0_GCAL_LSB_VAL, 
 ADS131_CH1_CFG_VAL, 
 ADS131_CH1_OCAL_MSB_VAL, 
 ADS131_CH1_OCAL_LSB_VAL, 
 ADS131_CH1_GCAL_MSB_VAL, 
 ADS131_CH1_GCAL_LSB_VAL, 
 ADS131_CH2_CFG_VAL, 
 ADS131_CH2_OCAL_MSB_VAL, 
 ADS131_CH2_OCAL_LSB_VAL, 
 ADS131_CH2_GCAL_MSB_VAL, 
 ADS131_CH2_GCAL_LSB_VAL, 
 ADS131_CH3_CFG_VAL, 
 ADS131_CH3_OCAL_MSB_VAL, 
 ADS131_CH3_OCAL_LSB_VAL, 
 ADS131_CH3_GCAL_MSB_VAL, 
 ADS131_CH3_GCAL_LSB_VAL, 
 ADS131_CH4_CFG_VAL, 
 ADS131_CH4_OCAL_MSB_VAL, 
 ADS131_CH4_OCAL_LSB_VAL, 
 ADS131_CH4_GCAL_MSB_VAL, 
 ADS131_CH4_GCAL_LSB_VAL, 
 ADS131_CH5_CFG_VAL, 
 ADS131_CH5_OCAL_MSB_VAL, 
 ADS131_CH5_OCAL_LSB_VAL, 
 ADS131_CH5_GCAL_MSB_VAL, 
 ADS131_CH5_GCAL_LSB_VAL, 
 ADS131_CH6_CFG_VAL, 
 ADS131_CH6_OCAL_MSB_VAL, 
 ADS131_CH6_OCAL_LSB_VAL, 
 ADS131_CH6_GCAL_MSB_VAL, 
 ADS131_CH6_GCAL_LSB_VAL, 
 ADS131_CH7_CFG_VAL, 
 ADS131_CH7_OCAL_MSB_VAL, 
 ADS131_CH7_OCAL_LSB_VAL, 
 ADS131_CH7_GCAL_MSB_VAL, 
 ADS131_CH7_GCAL_LSB_VAL, 
 ADS131_REGMAP_CRC_VAL,
 ADS131_RESERVED_VAL
};


uint16_t ADC_Registers_Add[49] = {
 ADS131_MODE, 
 ADS131_CLOCK,
 ADS131_GAIN1, 
 ADS131_GAIN2, 
 ADS131_CFG, 
 ADS131_THRSHLD_MSB, 
 ADS131_THRSHLD_LSB, 
 ADS131_CH0_CFG, 
 ADS131_CH0_OCAL_MSB, 
 ADS131_CH0_OCAL_LSB, 
 ADS131_CH0_GCAL_MSB, 
 ADS131_CH0_GCAL_LSB, 
 ADS131_CH1_CFG, 
 ADS131_CH1_OCAL_MSB, 
 ADS131_CH1_OCAL_LSB, 
 ADS131_CH1_GCAL_MSB, 
 ADS131_CH1_GCAL_LSB, 
 ADS131_CH2_CFG, 
 ADS131_CH2_OCAL_MSB, 
 ADS131_CH2_OCAL_LSB, 
 ADS131_CH2_GCAL_MSB, 
 ADS131_CH2_GCAL_LSB, 
 ADS131_CH3_CFG, 
 ADS131_CH3_OCAL_MSB, 
 ADS131_CH3_OCAL_LSB, 
 ADS131_CH3_GCAL_MSB, 
 ADS131_CH3_GCAL_LSB, 
 ADS131_CH4_CFG, 
 ADS131_CH4_OCAL_MSB, 
 ADS131_CH4_OCAL_LSB, 
 ADS131_CH4_GCAL_MSB, 
 ADS131_CH4_GCAL_LSB, 
 ADS131_CH5_CFG, 
 ADS131_CH5_OCAL_MSB, 
 ADS131_CH5_OCAL_LSB, 
 ADS131_CH5_GCAL_MSB, 
 ADS131_CH5_GCAL_LSB, 
 ADS131_CH6_CFG, 
 ADS131_CH6_OCAL_MSB, 
 ADS131_CH6_OCAL_LSB, 
 ADS131_CH6_GCAL_MSB, 
 ADS131_CH6_GCAL_LSB, 
 ADS131_CH7_CFG, 
 ADS131_CH7_OCAL_MSB, 
 ADS131_CH7_OCAL_LSB, 
 ADS131_CH7_GCAL_MSB, 
 ADS131_CH7_GCAL_LSB, 
 ADS131_REGMAP_CRC,
 ADS131_RESERVED
};

void ADC_SetParametres(ADS131M08 ADC_ADC131);
//Channels[number of channels Sampeld, Sampling Counter]= ADC_ReadChannels(S_Channels,S_duration);

void setup() {
    /* Start Serial Comunication*/
      Serial.begin(9600);
      delay(500);
      while(!Serial);
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

while (NumberOfSamples>0)
{

if(digitalRead(ADC_DRDY_PIN)) {
    // Read Data
    ADC_ADC131.readAllChannels(channelArr);
    Serial.println(channelArr[0]);          // Print data in channel 1.

    // Output to the DAC
    analogWrite( A0, DAC_Waveform[loopCount]/1);
    loopCount = loopCount + 1;
    if (loopCount==255) {loopCount=0;}
    NumberOfSamples=NumberOfSamples-1;
  }
  else {
  }
}



/*
  //Sampling Rate Measurement
  long numberOfSamples = 150000; //Number of conversions
  long finishTime = 0;
  long startTime = micros();
  for (long i = 0; i < numberOfSamples; i++)
    {
      ADC_ADC131.readAllChannels(channelArr);
    }
  finishTime = micros() - startTime; //Calculate the elapsed time
  //Printing the results
    Serial.print("Total conversion time for 150k samples: ");
    Serial.print(finishTime);
    Serial.println(" us");

    Serial.print("Sampling rate: ");
    Serial.print(numberOfSamples * (1000000.0 / finishTime), 3);
    Serial.println(" SPS");
*/
}

void ADC_SetParametres(ADS131M08 ADC_ADC131){

  /* Reset the ADC */
  pinMode(RESET, OUTPUT);
  digitalWrite(RESET, LOW);
  delay(1);
  digitalWrite(RESET, HIGH);

  // write to registers list
  for (int i = 0; i < 49; i++) {
    ADC_ADC131.writeReg(ADC_Registers_Add[i], ADC_Registers_Val[i]);
    Serial.println("Register ");
    Serial.println(ADC_Registers_Add[i]);
    Serial.println(" value: ");
    Serial.println(ADC_Registers_Val[i]);
    delay(100);
  }
  
 
    // Read the registers list
  for (int i = 0; i < 49; i++) {
    ADC_ADC131.readReg(ADC_Registers_Add[i]);
    Serial.print("Register ");
    Serial.print(ADC_Registers_Add[i]);
    Serial.print(" value: ");
    Serial.println(ADC_Registers_Val[i]);
  } 
 
 
 /*
  // Write Setting Registers
  //ADC_ADC131.writeReg(ADS131_MODE,0b0000010100010000);// Gain2 register (page 57 in datasheet)
  ADC_ADC131.writeReg(ADS131_CLOCK,0b1111111100011111); //Clock register (page 55 in datasheet)
  ADC_ADC131.writeReg(ADS131_GAIN1,0b0000000000000111);// Gain1 register (page 57 in datasheet)
  ADC_ADC131.writeReg(ADS131_GAIN2,0b0000000000000000);// Gain2 register (page 57 in datasheet)
  ADC_ADC131.writeReg(ADS131_CFG,0b0000011000001111);// CFG register (page 61 in datasheet)
  ADC_ADC131.writeReg(ADS131_THRSHLD_MSB,0b0000000000000000);// THRSHLD_LSB register (page 63 in datasheet)
  ADC_ADC131.writeReg(ADS131_THRSHLD_LSB,0b0000000000000000);// THRSHLD_LSB register (page 63 in datasheet)
  ADC_ADC131.setGain(1);
  
  //Channel settings
  ADC_ADC131.writeReg(ADS131_CH0_CFG,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH0_OCAL_MSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH0_OCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH0_GCAL_MSB,0b1000000000000000);
  ADC_ADC131.writeReg(ADS131_CH0_GCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH1_CFG,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH1_OCAL_MSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH1_OCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH1_GCAL_MSB,0b1000000000000000);
  ADC_ADC131.writeReg(ADS131_CH1_GCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH2_CFG,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH2_OCAL_MSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH2_OCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH2_GCAL_MSB,0b1000000000000000);
  ADC_ADC131.writeReg(ADS131_CH2_GCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH3_CFG,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH3_OCAL_MSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH3_OCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH3_GCAL_MSB,0b1000000000000000);
  ADC_ADC131.writeReg(ADS131_CH3_GCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH4_CFG,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH4_OCAL_MSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH4_OCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH4_GCAL_MSB,0b1000000000000000);
  ADC_ADC131.writeReg(ADS131_CH4_GCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH5_CFG,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH5_OCAL_MSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH5_OCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH5_GCAL_MSB,0b1000000000000000);
  ADC_ADC131.writeReg(ADS131_CH5_GCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH6_CFG,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH6_OCAL_MSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH6_OCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH6_GCAL_MSB,0b1000000000000000);
  ADC_ADC131.writeReg(ADS131_CH6_GCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH7_CFG,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH7_OCAL_MSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH7_OCAL_LSB,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_CH7_GCAL_MSB,0b1000000000000000);
  ADC_ADC131.writeReg(ADS131_CH7_GCAL_LSB,0b0000000000000000);

  ADC_ADC131.writeReg(ADS131_REGMAP_CRC,0b0000000000000000);
  ADC_ADC131.writeReg(ADS131_RESERVED,0b0000000000000000);
  
  ADC_ADC131.setGain(1);
  
  
  //ADC_ADC131.globalChop(true,2);
  // Read and check Register values
  uint16_t clkreg = ADC_ADC131.readReg(ADS131_CLOCK);
  uint16_t gainreg = ADC_ADC131.readReg(ADS131_GAIN1);
  Serial.print("CLOCK: ");
  Serial.println(clkreg,BIN);
*/
}