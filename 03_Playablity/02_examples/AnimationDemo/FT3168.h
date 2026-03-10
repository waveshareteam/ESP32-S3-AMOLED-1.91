#ifndef _FT3168_H
#define _FT3168_H

#include <Wire.h>

#define I2C_ADDR_FT3168 0x38

//手势
enum GESTURE
{
    None = 0x00,       //无手势
    SlideDown = 0x08,  //向下滑动
    SlideUp = 0x04,    //向上滑动
    SlideLeft = 0x01,  //向左滑动
    SlideRight = 0x02, //向右滑动
    SingleTap = 0x00,  //单击
    DoubleTap = 0x10,  //双击
    LongPress = 0x00   //长按
};

/**************************************************************************/
/*!
    @brief  CST816D I2C CTP controller driver
*/
/**************************************************************************/
class FT3168
{
public:
    FT3168(int8_t sda_pin = -1, int8_t scl_pin = -1, int8_t rst_pin = -1, int8_t int_pin = -1);

    void begin(void);
    bool getTouch(uint16_t *x, uint16_t *y, uint8_t *gesture);

private:
    int8_t _sda, _scl, _rst, _int;

    uint8_t i2c_read(uint8_t addr);
    uint8_t i2c_read_continuous(uint8_t addr, uint8_t *data, uint32_t length);
    void i2c_write(uint8_t addr, uint8_t data);
    uint8_t i2c_write_continuous(uint8_t addr, const uint8_t *data, uint32_t length);
};
#endif