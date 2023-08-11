/* 
 * ไลบรารี่ TridentTD_LineNotify version 2.1
 */
#define LINE_TOKEN ""
#include <TridentTD_LineNotify.h>

void lineNotifySetup() {
  Serial.println(LINE.getVersion());
  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);
}


//แจ้งเตือนแบบเช็คเงื่อนไข
unsigned long line_mx_previousMillis = 0;
//unsigned long line_mx_interval = 300000;  // 5 minutes
unsigned long line_mx_interval = 60000;  // 1 minute 
void lineNotifyLoop() {
  unsigned long currentMillis = millis();
  while (currentMillis - line_mx_previousMillis >= line_mx_interval)  // None blocking delay
  {
    line_mx_previousMillis = currentMillis;

    if (TEMP > maxTemp && maxTemp > 0) {
      String msg = "เตือนอุณหภูมิ: ";
      msg += TEMP;
      msg += " > ";
      msg += maxTemp;
      LINE.notify(msg);
    }

    if (HUMI > maxHumi && maxHumi > 0) {
      String msg = "เตือนความชื้น: ";
      msg += HUMI;
      msg += " > ";
      msg += maxHumi;
      LINE.notify(msg);
    }

    if (PM1 > maxPM1 && maxPM1 > 0) {
      String msg = "เตือนค่า PM1: ";
      msg += PM1;
      msg += " > ";
      msg += maxPM1;
      LINE.notify(msg);
    }

    if (PM2 > maxPM2 && maxPM2 > 0) {
      String msg = "เตือนค่า PM2.5: ";
      msg += PM2;
      msg += " > ";
      msg += maxPM2;
      LINE.notify(msg);
    }

    if (PM10 > maxPM10 && maxPM10 > 0) {
      String msg = "เตือนค่า PM10: ";
      msg += PM10;
      msg += " > ";
      msg += maxPM10;
      LINE.notify(msg);
    }
  }
}
