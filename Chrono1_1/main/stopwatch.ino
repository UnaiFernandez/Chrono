int sec=00;
int min=00;
int hr=00;
void loopSW(){
  while(stop == false){
    lcd.setCursor(2,2);
    lcd.print("CHRONOMETER");
    lcd.setCursor(4,0);
    lcd.print(hr);
    lcd.setCursor(6,0);
    lcd.print(":");
    lcd.print(min);
    lcd.setCursor(9,0);
    lcd.print(":");
    lcd.print(sec);
    sec=sec+1;
    delay(1000);

    if(sec == 60){
      sec=00;
      min=min+1; 
    }else;
    if(min == 60){
      min=0;
      hr=hr+1;
    }else;

  lcd.clear();
  if(digitalRead(9) == HIGH){
    restartSW();
  }
  if(digitalRead(2) == HIGH){
      stop = true;
  }
  }
  lcd.setCursor(2,2);
  lcd.print("CHRONOMETER");
  lcd.setCursor(4,0);
  lcd.print(hr);
  lcd.setCursor(6,0);
  lcd.print(":");
  lcd.print(min);
  lcd.setCursor(9,0);
  lcd.print(":");
  lcd.print(sec);
  delay(3000);
  lcd.clear();
  if(digitalRead(2) == HIGH){
    lcd.clear();
    loop(); 
  }
}

void restartSW(){
  sec = 00;
  int min=00;
  int hr=00;
}
