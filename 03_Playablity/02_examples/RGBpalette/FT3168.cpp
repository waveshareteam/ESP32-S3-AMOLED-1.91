#include "FT3168.h"
#include <Wire.h>

FT3168::FT3168(int8_t sda_pin, int8_t scl_pin, int8_t rst_pin, int8_t int_pin)
{
    _sda = sda_pin;
    _scl = scl_pin;
    _rst = rst_pin;
    _int = int_pin;
}

void FT3168::begin(void)
{
    // Initialize I2C
    if (_sda != -1 && _scl != -1)
    {
        Wire.begin(_sda, _scl);
    }
    else
    {
        Wire.begin();
    }

    // Int Pin Configuration
    if (_int != -1)
    {
        pinMode(_int, OUTPUT);
        digitalWrite(_int, HIGH); // 高电平
        delay(1); 
        digitalWrite(_int, LOW); // 低电平
        delay(1);
    }

    // Reset Pin Configuration
    if (_rst != -1)
    {
        pinMode(_rst, OUTPUT);
        digitalWrite(_rst, LOW);
        delay(10);
        digitalWrite(_rst, HIGH);
        delay(300);
    }

    // Initialize Touch
    i2c_write(0x00, 0x00); // 切换到工厂模式
}

bool FT3168::getTouch(uint16_t *x, uint16_t *y, uint8_t *gesture)
{
    bool FingerIndex = false;
    FingerIndex = (bool)i2c_read(0x02);
    // printf("FingerIndex: %d\n",FingerIndex);
    *gesture = i2c_read(0xD1);
    if (!(*gesture == SlideUp || *gesture == SlideDown))
    {
        // printf("AA\n");
        *gesture = None;
    }

    uint8_t data[4];
    i2c_read_continuous(0x03, data, 4);
    *x = ((data[0] & 0x0F) << 8) | data[1];
    // i2c_read_continuous(0x02, data, 4);
    // Wire.endTransmission(false);
    // *y = ((data[2] & 0x0F) << 16) | data[3]; //读取的y值反向
    *y = ((data[2] & 0x0F) << 8) | data[3];

    // *x = 240 - *x;

    return FingerIndex;
}

uint8_t FT3168::i2c_read(uint8_t addr)
{
    uint8_t rdData;
    uint8_t rdDataCount;
    do
    {
        Wire.beginTransmission(I2C_ADDR_FT3168);
        Wire.write(addr);
        Wire.endTransmission(false); // Restart
        rdDataCount = Wire.requestFrom(I2C_ADDR_FT3168, 1);
    } while (rdDataCount == 0);
    while (Wire.available())
    {
        rdData = Wire.read();
    }
    return rdData;
}

uint8_t FT3168::i2c_read_continuous(uint8_t addr, uint8_t *data, uint32_t length)
{
    Wire.beginTransmission(I2C_ADDR_FT3168);
    Wire.write(addr);
    if (Wire.endTransmission(true)) return -1;
    Wire.requestFrom(I2C_ADDR_FT3168, length);
    for (int i = 0; i < length; i++)
    {
        *data++ = Wire.read();
    }
    return 0;
}

void FT3168::i2c_write(uint8_t addr, uint8_t data)
{
    Wire.beginTransmission(I2C_ADDR_FT3168);
    Wire.write(addr);
    Wire.write(data);
    Wire.endTransmission();
}

// 添加新的方法来读取寄存器

// uint8_t FT3168::readModeSwitch()
// {
//     return i2c_read(0x00);
// }

// uint8_t FT3168::readTDStatus()
// {
//     return i2c_read(0x02);
// }

// uint16_t FT3168::readP1X()
// {
//     uint8_t high = i2c_read(0x03) & 0x0F;
//     uint8_t low = i2c_read(0x04);
//     return (high << 8) | low;
// }

// uint16_t FT3168::readP1Y()
// {
//     uint8_t high = i2c_read(0x05) & 0x0F;
//     uint8_t low = i2c_read(0x06);
//     return (high << 8) | low;
// }

// 根据需要添加更多的方法以读取其他寄存器...
