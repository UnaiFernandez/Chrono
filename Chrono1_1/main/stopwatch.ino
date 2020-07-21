void loopSW(){
  while(stop == false){
    lcd.setCursor(5,2);
    lcd.print("CHRONO");
    lcd.setCursor(4,0);
    if(hr < 10){
      lcd.print("0");
      lcd.print(hr);
    }else{
      lcd.print(hr);
    }
    lcd.setCursor(6,0);
    if(m < 10){
      lcd.print(":");
      lcd.print("0");
      lcd.print(m);
    }else{
      lcd.print(":");
      lcd.print(m);
    }
    lcd.setCursor(9,0);
    lcd.print(":");
    lcd.print(sec);
    lcd.print(".");
    lcd.print(mili);
    mili = mili + 1;
    delay(100);

    if(mili == 9){
      mili = 0;
      sec = sec+1;
    }else;
    if(sec == 60){
      sec=0;
      m=m+1; 
    }else;
    if(m == 60){
      m=0;
      hr=hr+1;
    }else;

  lcd.clear();
  if(digitalRead(9) == HIGH){
    restartSW();
    m = 0;
  }
  if(digitalRead(2) == HIGH){
      stop = true;
  }
  }
  lcd.setCursor(5,2);
    lcd.print("CHRONO");
    lcd.setCursor(4,0);
    if(hr < 10){
      lcd.print("0");
      lcd.print(hr);
    }else{
      lcd.print(hr);
    }
    lcd.setCursor(6,0);
    if(m < 10){
      lcd.print(":");
      lcd.print("0");
      lcd.print(m);
    }else{
      lcd.print(":");
      lcd.print(m);
    }
    lcd.setCursor(9,0);
    lcd.print(":");
    lcd.print(sec);
    lcd.print(".");
    lcd.print(mili);
  delay(6000);
  lcd.clear();
  if(digitalRead(2) == HIGH){
    lcd.clear();
    loop(); 
  }
}

void restartSW(){
  mili = 0;
  sec = 0;
  int m=0;
  int hr=0;
}
