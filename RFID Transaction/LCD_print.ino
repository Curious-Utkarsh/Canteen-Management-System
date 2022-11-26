//#include<LiquidCrystal_I2C.h>
//#include<Wire.h>

//LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD SDA -> A4; SCL -> A5

void lcd_place_card(){
  lcd.backlight();
  char mystr[]="Place card on the scanner to Add UNP";
  //int a = strlen(mystr);
  lcd.setCursor(2,0);
  lcd.print(mystr);
  for(int Positioncounter=0; Positioncounter<(strlen(mystr)); Positioncounter++){
    lcd.scrollDisplayLeft();
    delay(150);
  }
}

void lcd_unp_added(){
  lcd.backlight();
  char mystr[]="UNP Added";
  lcd.setCursor(3,0);
  lcd.print(mystr);
  lcd.setCursor(3,1);
  lcd.print(deduct_pts);
}

void lcd_rmv_card(){
  lcd.backlight();
  char mystr[]="Remove Card";
  lcd.setCursor(2,0);
  lcd.print(mystr);
}

void lcd_check_unp(){
  lcd.backlight();
  char mystr[]="PLACE CARD ON SCANNER TO CHECK BALANCE UNP";
  //int a = strlen(mystr);
  lcd.setCursor(2,0);
  lcd.print(mystr);
  for(int Positioncounter=0; Positioncounter<(strlen(mystr)); Positioncounter++){
    lcd.scrollDisplayLeft();
    delay(150);
  }
}

void lcd_bal_pts(){
  lcd.backlight();
  char mystr[]="BALANCE UNP:";
  lcd.setCursor(2,0);
  lcd.print(mystr);
  lcd.setCursor(6,1);
  lcd.print(balance_pts);
}
