void ScreenSetup(void)
{
  lcd.begin();
  lcd.backlight();
}

void ScreenWelcome(void)
{
  lcd.setCursor(0,0);
  lcd.print(" SANTA SCANNER");
  lcd.setCursor(0,1);
  lcd.print("  Hello Isaac");
}

void PinSetup(void)
{ 
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);

  pinMode(ledScan, OUTPUT);
  digitalWrite(ledScan, 0);
  
  pinMode(ledDetect, OUTPUT);
  digitalWrite(ledScan, 0);
}


void ScanningScan(void)
{
  lcd.setCursor(0,0);
  lcd.print("  NOW SCANNING  ");
  lcd.setCursor(0,1);
  lcd.print("      ....      ";
  delay(5000);
  
}


