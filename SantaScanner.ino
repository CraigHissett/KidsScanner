#include <Wire.h>
#include <ESP8266WebServer.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>

const char* ssid = "TALKTALK89EA45";
const char* password = "QHAJ4W7J";


ESP8266WebServer server(80);

const int led = LED_BUILTIN;

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/html", "<center><h2>Hello this is an example Web Server from www.likeciruit.com</h2></center>");
  digitalWrite(led, 0);
}

void handleNotFound(){
  digitalWrite(led,1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message +=  "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message +=  " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led,0);
}

void setup(void) {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  WiFi.begin(ssid, password);

  lcd.begin();
  lcd.backlight();

  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    lcd.setCursor(0,0);
    lcd.print(" SANTA SCANNER");
    lcd.setCursor(0,1);
    lcd.print("  Hello Isaac");

    server.on("/", handleRoot);
    server.onNotFound(handleNotFound);
    server.begin();        
  }

}


void loop(void) {
  // put your main code here, to run repeatedly:
  server.handleClient();

}
