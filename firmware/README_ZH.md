[English](README.md)

# 出厂固件

| 文件 | 用途 | 烧录偏移 |
| --- | --- | --- |
| [ESP32-S3-AMOLED-1.91_FactoryOnly_20241111.bin](ESP32-S3-AMOLED-1.91_FactoryOnly_20241111.bin) | 出厂固件（2024-11-11） | `0x0` |

下载 BIN，使开发板进入下载模式并连接电脑，然后烧录合并镜像：

```sh
python -m esptool --chip esp32s3 write-flash 0x0 ESP32-S3-AMOLED-1.91_FactoryOnly_20241111.bin
```
