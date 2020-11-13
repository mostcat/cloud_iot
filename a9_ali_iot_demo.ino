#include <WiFi.h>
#include "Esp32MQTTClient.h"
static WiFiClient espClient;
// 引入阿里云 IoT SDK
#include <AliyunIoTSDK.h>

#define INTERVAL 10000
#define DEVICE_ID "m5atom"
#define MESSAGE_MAX_LEN 256

// Please input the SSID and password of WiFi
const char* ssid     = "Rickwan_AP";
const char* password = "wz22334455";


// 设置产品和设备的信息，从阿里云设备信息里查看
#define PRODUCT_KEY "a1fc6fiPlL2"
#define DEVICE_NAME "MzqRVt6KazICZXjoKolr"
#define DEVICE_SECRET "2oFsQbil3r8ksITskKmW2nYn5Lmg2kjE"
#define REGION_ID "cn-shanghai"

int messageCount = 1;
static bool hasWifi = false;
static bool messageSending = true;
static uint64_t send_interval_ms;

static void InitWifi()
{
  Serial.println("Connecting...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  hasWifi = true;
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup()
{
    Serial.begin(115200);
    Serial.println("ESP32 Device");
    Serial.println("Initializing...");
  
    // Initialize the WiFi module
    Serial.println(" > WiFi");
    hasWifi = false;
    InitWifi();
    if (!hasWifi)
    {
      return;
    }
    
    // 初始化 iot，需传入 wifi 的 client，和设备产品信息
    AliyunIoTSDK::begin(espClient, PRODUCT_KEY, DEVICE_NAME, DEVICE_SECRET, REGION_ID);
    
    // 绑定一个设备属性回调，当远程修改此属性，会触发 powerCallback
    // PowerSwitch 是在设备产品中定义的物联网模型的 id
    AliyunIoTSDK::bindData("PowerSwitch", powerCallback);
    
    // 发送一个数据到云平台，LightLuminance 是在设备产品中定义的物联网模型的 id
    AliyunIoTSDK::send("CurrentTemperature", 97);
}

void loop()
{
    AliyunIoTSDK::loop();
}

// 电源属性修改的回调函数
void powerCallback(JsonVariant p)
{
    int PowerSwitch = p["PowerSwitch"];
    if (PowerSwitch == 1)
    {
        // 启动设备
    } 
}
