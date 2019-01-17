#include <Wire.h>
#include <ESP8266WebServer.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>

//PN532 NFC RFID Module Reader Writer Kit library to add

const char* ssid = "";
const char* password = "";


ESP8266WebServer server(80);

const int led = LED_BUILTIN;
const int ledScan = D5;
const int ledDetect = D6;


LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup(void) {
  // put your setup code here, to run once:
  
  PinSetup();
  
  WiFi.begin(ssid, password);

  ScreenSetup();

  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    
    ScreenWelcome();

    server.on("/", handleRoot);
    server.onNotFound(handleNotFound);
    server.begin();        
  }

}


void loop(void) {
  // put your main code here, to run repeatedly:
  server.handleClient();

}
