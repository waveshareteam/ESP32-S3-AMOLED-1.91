[中文](README_ZH.md)

# Factory firmware

| File | Description | Flash offset |
| --- | --- | --- |
| [ESP32-S3-AMOLED-1.91_FactoryOnly_20241111.bin](ESP32-S3-AMOLED-1.91_FactoryOnly_20241111.bin) | Factory firmware (2024-11-11) | `0x0` |

Download the BIN, connect the board in download mode, and flash the merged image:

```sh
python -m esptool --chip esp32s3 write-flash 0x0 ESP32-S3-AMOLED-1.91_FactoryOnly_20241111.bin
```
