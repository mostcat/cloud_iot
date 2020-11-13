*** cloud_iot demo



### A7 AzureIotHub ESP32 M5ATOM OK

------

阿里云物联网连接

### A8 AliyunIoTSDK方式

ESP32 m5stack atom通过

AliyunIoTSDK方式
https://www.icxbk.com/article/detail?aid=1529

arduino上阿里云所需要用到的四个库文件：
PubSubClient，
ArduinoJson，
Crypto（SHA256）
AliyunIoTSDK
https://github.com/yu-tou/arduino-aliyun-iot-sdk

***必须修改
     解决方法是更改PubSubClient.h文件中的两个宏MQTT_MAX_PACKET_SIZE和MQTT_KEEPALIVE，将其改大点，比如改成1024和60。

-----
### A9 aliyun_mqtt库方式

ESP32 ESP32 m5stack atom通过

aliyun_mqtt库方式,https://github.com/legenddcr/aliyun-mqtt-arduino,下载zip,库加载

参考文章:
https://www.jianshu.com/p/f0d46324a2c6

也要改pubsuclent的配置
