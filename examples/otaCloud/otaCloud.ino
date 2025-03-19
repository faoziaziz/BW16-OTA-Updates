
#include <WiFi.h>
#include <AnchorOTA.h>

char ssid[] = "gdg-wrk";
char pass[] = "gdg123wrk";

#define OTA_PORT 8082

// Address of device where this board can fetch its updates
IPAddress ip = {34,101,137,39};

void setup() {
  Serial.begin(115200);

  Serial.println("Try to connect to WiFi");
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  
}

void loop() {
  if (OTA.beginCloud(ip, OTA_PORT) < 0) {
    Serial.println("OTA failed!");
    delay(5000);
  }
}
