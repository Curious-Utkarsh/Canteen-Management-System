#include <SPI.h>
#include <SoftwareSerial.h>
#include <MFRC522.h>
#include <Sim800l.h>
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);
Sim800l Sim800l;
hd44780_I2Cexp lcd;
hd44780_I2Cexp lcd2(0x3f);

const int LCD_COLS = 16;
const int LCD_ROWS = 2;
int cPresent = 0;
String pts = "";
int balance_pts = 0;
String bPts = "";
int deduct_pts = 0;
int custom_pts = 0;
String deduct_ptss = "";
int new_balance_pts = 0;
String new_balance_ptss = "";
int dt = 500;
int sPin = 4;
int clk = 0;
byte state = 0;
String msg = "";
String msgFrom = "";


void setup()
{
  pinMode(sPin, INPUT);
  digitalWrite(sPin,HIGH);
  Serial.begin(9600);
  Sim800l.begin();
  Sim800l.delAllSms();
  SPI.begin();
  mfrc522.PCD_Init();
  int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if(status)
  {
    status = -status;
    hd44780::fatalError(status);
  }
}

void loop()
{
//  Sim800l.reset();
//  Sim800l.delAllSms();
  lcd.clear();
//  delay(dt);
  lcd.setCursor(0,0);
  lcd.print("Scan/Pay to");
  lcd.setCursor(0,1);
  lcd.print("Add ELX ...");
//  Sim800l.delAllSms();
  msg = Sim800l.readSms(1);
  Serial.println(msg);
  if(msg.indexOf("OK") == -1)
  {
    if(digitalRead(sPin) == HIGH)
    {
      clk = 1;
//      break;
    }
    if(clk == 1)
    {
//      return;
    }
    else
    {
      return;
    }
  }
  if(clk == 1)
  {
    deduct_ptss = "0";
  }
  else
  {
    msgFrom = Sim800l.getNumberSms(1);
    if(msgFrom == "+917999388767")
    {
      getMoney(msg);
      Serial.println(deduct_ptss);
    }
  }
  delay(dt);
  lcd.clear();
  delay(dt);
  if(clk == 0)
  {
    lcd.setCursor(0,0);
    lcd.print("Amount Recieved :");
    lcd.setCursor(0,1);
    lcd.print(deduct_ptss);
    delay(2000);
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Check Balance :");
    delay(1500);
  }
  lcd.clear();
  delay(dt);
  lcd.setCursor(0,0);
  lcd.print("Place Card");
  lcd.setCursor(0,1);
  lcd.print("To Proceed ...");
  isCard();
  addPts(1);
//  delay(2000);
  lcd.clear();
  delay(dt);
  if(clk == 2)
  {
    lcd.setCursor(0,0);
    lcd.print("ELX Added");
    lcd.setCursor(0,1);
    lcd.print("Successfully");
    delay(1000);
  }
  lcd.clear();
  delay(dt);
  lcd.setCursor(0,0);
  lcd.print("Balance Is :");
  lcd.setCursor(0,1);
  lcd.print(new_balance_ptss);
  delay(3000);
  lcd.clear();
  delay(dt);
  lcd.setCursor(0,0);
  lcd.print("Thank You !");
  delay(1000);
  pts = "";
  clk = 0;
  msg = "";
  Sim800l.delAllSms();
  
  

}
