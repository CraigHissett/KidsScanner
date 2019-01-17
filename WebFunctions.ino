
void handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/html", "<center><h2>Hello this is an example Web Server from www.likeciruit.com</h2></center>");
  digitalWrite(led, 0);
}

String getPage(){
  String page = "<html lang=fr-FR><head><meta http-equiv='refresh' content='10'/>";
  page += "<title>ESP8266 Demo - www.projetsdiy.fr</title>";
  page += "<style> body { background-color: #fffff; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }</style>";
  page += "</head><body><h1>ESP8266 Demo</h1>";
  page += "<h3>DHT22</h3>";
  page += "<ul><li>Temperature : ";
  page += t;
  page += "°C</li>";
  page += "<li>Humidite : ";
  page += h;
  page += "%</li></ul><h3>BMP180</h3>";
  page += "<ul><li>Pression atmospherique : ";
  page += p;
  page += " mbar</li></ul>";
  page += "<h3>GPIO</h3>";
  page += "<form action='/' method='POST'>";
  page += "<ul><li>D3 (etat: ";
  page += etatLed;
  page += ")";
  page += "<INPUT type='radio' name='LED' value='1'>ON";
  page += "<INPUT type='radio' name='LED' value='0'>OFF</li></ul>";
  page += "<INPUT type='submit' value='Actualiser'>";
  page += "<br><br><p><a hrf='https://diyprojects.io'>diyprojects.io</p>";
  page += "</body></html>";
  return page;
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
