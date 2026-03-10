# ESP32-S3-AMOLED-1.91

中文wiki链接: https://www.waveshare.net/wiki/ESP32-S3-AMOLED-1.91<br>
Product English wiki link: https://www.waveshare.com/wiki/ESP32-S3-AMOLED-1.91

This repository is compatible with the following models:

* ESP32-S3-Touch-AMOLED-1.91
* ESP32-S3-Touch-AMOLED-1.91-M
* ESP32-S3-AMOLED-1.91
* ESP32-S3-AMOLED-1.91-M

# Arduino example Tools configuration
![alt text](<Tools Configuration.png>)

# Notes
- When using the 03_Playablity example, note that the version of arduino-esp32 must be lower than v3.0.0. If compilation fails, v2.0.9 can be used; this version has been tested and verified so far.
- When using the 03_Playablity example, remember to copy the libraries in this directory to the user's Arduino library directory.

# 注意事项
- 使用03_Playablity示例，需要注意控制arduino-esp32版本低于v3.0.0，如果出现编译失败，可使用v2.0.9；目前该版本已测试验证
- 使用03_Playablity示例，记得拷贝该目录下的库到用户arduino库目录下


## Change log

### [1.0.0] 2026/03/10
- Includes examples of WiFi driver, ADC voltage measurement, attitude sensor driver, SD card driver, playable GUI, LVGL, etc.

## 更新日志

### [1.0.0] 2026/03/10
- 包含wifi驱动、adc电压测量、姿态传感器驱动、sd卡驱动、可玩性gui、lvgl等示例。