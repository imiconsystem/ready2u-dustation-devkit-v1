#include <Preferences.h>
#include <nvs_flash.h>

Preferences preferences;
const char *prekey = "APcredentials";

void storageSetup() {
  String WIssid, WIpass, Assid, Apass, www_realm, www_username, www_password, _device_name, _webTitle;

  int32_t mx_temp, mx_humi, mx_pm1, mx_pm2, mx_pm10;

  preferences.begin(prekey, false);

  devRunmode = preferences.getInt("devRunmode",0);

  Serial.print("devRunmode before: ");
  Serial.println(preferences.getInt("devRunmode"));

  mx_temp = preferences.getInt("maxTemp", 0);
  if (mx_temp > 0) {
    Serial.print("SET maxTemp: ");
    maxTemp = mx_temp;
    Serial.println("No values saved for maxTemp");
    Serial.println("maxTemp Saved using default value.");
  }
  mx_humi = preferences.getInt("maxHumi", 0);
  if (mx_humi > 0) {
    Serial.print("SET maxHumi: ");
    maxHumi = mx_humi;
    Serial.println("No values saved for maxHumi");
    Serial.println("maxHumi Saved using default value.");
  }
  mx_pm1 = preferences.getInt("maxPM1", 0);
  if (mx_pm1 > 0) {
    Serial.print("SET maxPM1: ");
    maxPM1 = mx_pm1;
    Serial.println("No values saved for maxPM1");
    Serial.println("maxPM1 Saved using default value.");
  }
  mx_pm2 = preferences.getInt("maxPM2", 0);
  if (mx_pm2 > 0) {
    Serial.print("SET maxPM2: ");
    maxPM2 = mx_pm2;
    Serial.println("No values saved for maxPM2");
    Serial.println("maxPM2 Saved using default value.");
  }
  mx_pm10 = preferences.getInt("maxPM10", 0);
  if (mx_pm10 > 0) {
    Serial.print("SET maxPM10: ");
    maxPM10 = mx_pm10;
    Serial.println("No values saved for maxPM10");
    Serial.println("maxPM10 Saved using default value.");
  }

  WIssid = preferences.getString("WiFissid", "");
  WIpass = preferences.getString("WiFipassword", "");

  _device_name = preferences.getString("deviceName", "");
  _webTitle = preferences.getString("webTitle", "");

  Assid = preferences.getString("APssid", "");
  Apass = preferences.getString("APpassword", "");

  www_realm = preferences.getString("www_realm", "").c_str();
  www_username = preferences.getString("www_username", "").c_str();
  www_password = preferences.getString("www_password", "").c_str();

  if (devRunmode == 0) {
    Serial.print("SET devRunmode: ");
    preferences.putInt("devRunmode", DEVRUNMODE);
    Serial.println("No values saved for Device run mode");
    Serial.println("Device run mode Saved using default value.");
  }
  
  Serial.print("devRunmode after: ");
  Serial.println(preferences.getInt("devRunmode"));

    if (Assid == "" || Apass == "") {
    preferences.putString("APssid", APssid);
    preferences.putString("APpassword", APpassword);
    Serial.println("No values saved for APssid or APpassword");
    Serial.println("AP Credentials Saved using default value.");
  }

  if (WIssid == "" || WIpass == "") {
    preferences.putString("WiFissid", WiFissid);
    preferences.putString("WiFipassword", WiFipassword);
    Serial.println("No values saved for WIFssid or WiFipassword");
    Serial.println("WIFI Credentials Saved using default value.");
  }

  if (_device_name == "") {
    preferences.putString("deviceName", device_name);
    Serial.println("No values saved for deviceName");
    Serial.println("deviceName Saved using default value.");
  }

  if (_webTitle == "") {
    preferences.putString("webTitle", webTitle);
    Serial.println("No values saved for webTitle");
    Serial.println("webTitleSaved using default value.");
  }

  preferences.end();
}

void storagePutString(const char *key, String value) {
  preferences.begin(prekey, false);
  preferences.putString(key, value);
  preferences.end();
}

void storagePutInt(const char *key, int32_t value) {
  preferences.begin(prekey, false);
  preferences.putInt(key, value);
  preferences.end();
}

void storagePutChar(const char *key, int8_t val) {
  preferences.begin(prekey, false);
  preferences.putChar(key, val);
  preferences.end();
}

String storageGetString(const char *key) {
  String result;
  preferences.begin(prekey, false);
  result = preferences.getString(key, "");
  preferences.end();
  return result;
}

String storageGetInt(const char *key) {
  String result;
  preferences.begin(prekey, false);
  result = preferences.getInt(key, 0);
  preferences.end();
  return result;
}

String storageGetChar(const char *key) {
  String result;
  preferences.begin(prekey, false);
  result = preferences.getChar(key);
  preferences.end();
  return result;
}

void storageClear() {
  nvs_flash_erase();  // erase the NVS partition and...
  nvs_flash_init();   // initialize the NVS partition.
  while (true)
    ;
}