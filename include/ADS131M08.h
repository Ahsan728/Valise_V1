#ifndef ADS131M08_H
#define ADS131M08_H

#include <Arduino.h>
#include <SPI.h>

#define ADS131_ID 0x00
#define ADS131_STATUS 0x01
#define ADS131_MODE 0x02
#define ADS131_CLOCK 0x03
#define ADS131_GAIN1 0x04
#define ADS131_GAIN2 0x05
#define ADS131_CFG 0x06
#define ADS131_THRSHLD_MSB 0x07
#define ADS131_THRSHLD_LSB 0x08

#define ADS131_CH0_CFG 0x09
#define ADS131_CH0_OCAL_MSB 0x0A
#define ADS131_CH0_OCAL_LSB 0x0B
#define ADS131_CH0_GCAL_MSB 0x0C
#define ADS131_CH0_GCAL_LSB 0x0D
#define ADS131_CH1_CFG 0x0E
#define ADS131_CH1_OCAL_MSB 0x0F
#define ADS131_CH1_OCAL_LSB 0x10
#define ADS131_CH1_GCAL_MSB 0x11
#define ADS131_CH1_GCAL_LSB 0x12
#define ADS131_CH2_CFG 0x13
#define ADS131_CH2_OCAL_MSB 0x14
#define ADS131_CH2_OCAL_LSB 0x15
#define ADS131_CH2_GCAL_MSB 0x16
#define ADS131_CH2_GCAL_LSB 0x17
#define ADS131_CH3_CFG 0x18
#define ADS131_CH3_OCAL_MSB 0x19
#define ADS131_CH3_OCAL_LSB 0x1A
#define ADS131_CH3_GCAL_MSB 0x1B
#define ADS131_CH3_GCAL_LSB 0x1C
#define ADS131_CH4_CFG 0x1D
#define ADS131_CH4_OCAL_MSB 0x1E
#define ADS131_CH4_OCAL_LSB 0x1F
#define ADS131_CH4_GCAL_MSB 0x20
#define ADS131_CH4_GCAL_LSB 0x21
#define ADS131_CH5_CFG 0x22
#define ADS131_CH5_OCAL_MSB 0x23
#define ADS131_CH5_OCAL_LSB 0x24
#define ADS131_CH5_GCAL_MSB 0x25
#define ADS131_CH5_GCAL_LSB 0x26
#define ADS131_CH6_CFG 0x27
#define ADS131_CH6_OCAL_MSB 0x28
#define ADS131_CH6_OCAL_LSB 0x29
#define ADS131_CH6_GCAL_MSB 0x2A
#define ADS131_CH6_GCAL_LSB 0x2B
#define ADS131_CH7_CFG 0x2C
#define ADS131_CH7_OCAL_MSB 0x2D
#define ADS131_CH7_OCAL_LSB 0x2E
#define ADS131_CH7_GCAL_MSB 0x2F
#define ADS131_CH7_GCAL_LSB 0x30


#define ADS131_REGMAP_CRC 0x3E
#define ADS131_RESERVED 0x3F

//Default values for Register table
//#define ADS131_ID_VAL 0x00 // Read only, not required
//#define ADS131_STATUS_VAL 0x01 // Read only, not required

#define ADS131_MODE_VAL 0x0510 
#define ADS131_CLOCK_VAL 0xFF0E
#define ADS131_GAIN1_VAL 0x0000
#define ADS131_GAIN2_VAL 0x0000
#define ADS131_CFG_VAL 0x0600
#define ADS131_THRSHLD_MSB_VAL 0x0000
#define ADS131_THRSHLD_LSB_VAL 0x0000
#define ADS131_CH0_CFG_VAL 0x0000
#define ADS131_CH0_OCAL_MSB_VAL 0x0000
#define ADS131_CH0_OCAL_LSB_VAL 0x0000
#define ADS131_CH0_GCAL_MSB_VAL 0x8000
#define ADS131_CH0_GCAL_LSB_VAL 0x0000
#define ADS131_CH1_CFG_VAL 0x0000
#define ADS131_CH1_OCAL_MSB_VAL 0x0000
#define ADS131_CH1_OCAL_LSB_VAL 0x0000
#define ADS131_CH1_GCAL_MSB_VAL 0x8000
#define ADS131_CH1_GCAL_LSB_VAL 0x0000
#define ADS131_CH2_CFG_VAL 0x0000
#define ADS131_CH2_OCAL_MSB_VAL 0x0000
#define ADS131_CH2_OCAL_LSB_VAL 0x0000
#define ADS131_CH2_GCAL_MSB_VAL 0x8000
#define ADS131_CH2_GCAL_LSB_VAL 0x0000
#define ADS131_CH3_CFG_VAL 0x0000
#define ADS131_CH3_OCAL_MSB_VAL 0x0000
#define ADS131_CH3_OCAL_LSB_VAL 0x0000
#define ADS131_CH3_GCAL_MSB_VAL 0x8000
#define ADS131_CH3_GCAL_LSB_VAL 0x0000
#define ADS131_CH4_CFG_VAL 0x0000
#define ADS131_CH4_OCAL_MSB_VAL 0x0000
#define ADS131_CH4_OCAL_LSB_VAL 0x0000
#define ADS131_CH4_GCAL_MSB_VAL 0x8000
#define ADS131_CH4_GCAL_LSB_VAL 0x0000
#define ADS131_CH5_CFG_VAL 0x0000
#define ADS131_CH5_OCAL_MSB_VAL 0x0000
#define ADS131_CH5_OCAL_LSB_VAL 0x0000
#define ADS131_CH5_GCAL_MSB_VAL 0x8000
#define ADS131_CH5_GCAL_LSB_VAL 0x0000
#define ADS131_CH6_CFG_VAL 0x0000
#define ADS131_CH6_OCAL_MSB_VAL 0x0000
#define ADS131_CH6_OCAL_LSB_VAL 0x0000
#define ADS131_CH6_GCAL_MSB_VAL 0x8000
#define ADS131_CH6_GCAL_LSB_VAL 0x0000
#define ADS131_CH7_CFG_VAL 0x0000
#define ADS131_CH7_OCAL_MSB_VAL 0x0000
#define ADS131_CH7_OCAL_LSB_VAL 0x0000
#define ADS131_CH7_GCAL_MSB_VAL 0x8000
#define ADS131_CH7_GCAL_LSB_VAL 0x0000
#define ADS131_REGMAP_CRC_VAL 0x0000
#define ADS131_RESERVED_VAL 0x0000


class ADS131M08 {
    public:

    SPIClass * spi = NULL; // SPISettings(spiClk, MSBFIRST, SPI_MODE1)
    int CS, XTAL, DRDY;
    int SpiClk;

    bool firstRead = true;
    int nFrameWords = 10;
    // Dummy word frame to write ADC during ADC data reads
    ADS131M08(int cs=5, int xtal=22, int drdy=21, int clk = 2000000);
    void init();
    void readChannels(int8_t * channelArrPtr, int8_t channelArrLen, int32_t * outputArrPtr);
    void readAllChannels(int32_t inputArr[8]);
    int32_t readChannelSingle(int8_t channel);
    bool globalChop(bool enabled, uint8_t log2delay);
    bool writeReg(uint8_t reg, uint16_t data);
    uint16_t readReg(uint8_t reg);
    bool setGain(int gain);
    uint32_t spiTransferWord(uint16_t inputData = 0x0000);
    void spiCommFrame(uint32_t * outPtr, uint16_t command = 0x0000);
    int32_t twoCompDeco(uint32_t data);

};

#endif