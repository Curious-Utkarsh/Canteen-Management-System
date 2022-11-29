#include <SPI.h>
#include <MFRC522.h>
#include <Keypad.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

SoftwareSerial mySerial(A0, A1); //(rx, tx)

#define RST_PIN     5 //Configurable
#define SS_PIN     53 //Configurable

MFRC522 mfrc522(SS_PIN, RST_PIN); //Create MFRC522 instance

String pts = "";
String inp = "";
int menu_deduct_pts = 0;
  char customKey = ' ';
   int balance_pts = 0;
   int deduct_pts = 0;
   int custom_pts = 0;
String deduct_ptss = "";
   int new_balance_pts = 0;
String new_balance_ptss = "";
String ch = "";
   int choice = -1;
   int check = -1;
String content = "";
   int cardDet = 1;

String ID = "";
String Elx_Paid = "";
String qty = "";
String fName = "";
String dataPack = "";

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
//  Serial1.begin(9600);
  mySerial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop()
{
  Serial.println(".....PRESS '1' TO ADD UNP TO CARD.....");
  lcd.setCursor(0,0);
  lcd.home();
  lcd.print("Press 1 to Add pts");
  Serial.println(".....PRESS '5' TO CHECK BALANCE UNP IN CARD.....");
  lcd.setCursor(0,1);
  lcd.home();
  lcd.print("Press 5 to check bal");
  Serial.println(".....PRESS '3' TO MAKE TRANSACTION.....");
  Serial.println();

  input();
  choice = inp.toInt();

  switch(choice)
  {
    case 1:
      Serial.println("PLACE CARD ON SCANNER TO ADD ELIXIR : ");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Place Card on scanner");
      isCard();
      writeElx(1);
      Serial.println("ELIXIR ADDED! +");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ELIXIR ADDED! +");
      Serial.print(deduct_pts);
      delay(2000);
      Serial.println("New Balance: ");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("New Balance: ");
      lcd.setCursor(0,1);
      lcd.print(new_balance_pts);
      Serial.print(new_balance_pts);
      Serial.println("REMOVE THE CARD!");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Remove Card");
      delay(2000);
      break;
      
    case 5:
      Serial.println("PLACE CARD ON SCANNER TO CHECK BALANCE");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Place Card on scanner");
      isCard();
      readElx();
      Serial.println("YOUR BALANCE IS :");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("YOUR BALANCE IS :");
      lcd.setCursor(0,1);
      lcd.print(balance_pts);
      Serial.println(balance_pts);
      delay(1000);
      Serial.println("REMOVE THE CARD!");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Remove Card");
      delay(2000);
      break;
      
    case 3:
      menu();
//      delay(3000);
//      deduct_pts=menu_deduct_pts;
//      Serial.println("PLACE CARD ON THE READER:");
//      isCard();
//      writeElx(-1);
//      if(check == 0)
//      {
//        Serial.println("TRANSACTION UNSUCCESSFUL!");
//        check = -1;
//      }
//      else
//      {
//        Serial.println("TRANSACTION DONE!");
//        Serial.println("ENTER QUANTITY :");
//        while(Serial.available() == 0)
//        {}
//        qty = Serial.readStringUntil('#');
//        Serial.println("ENTER FOOD NAME :");
//        while(Serial.available() == 0)
//        {}
//        fName = Serial.readStringUntil('#');
//        getUID();
//        ID = String(content);
//          deduct_pts=menu_deduct_pts;
//          Elx_Paid = String(deduct_pts);
//        dataPack = (ID+"#"+Elx_Paid+"#"+qty+"#"+fName);
//        Serial1.println(dataPack);
//        unpack(dataPack);
//        delay(2000);
//      }
//      Serial.println("REMOVE THE CARD!");
//      delay(2000);
      break;

    default:
      Serial.println("INVALID CHOICE!");
      Serial.println();
      delay(2000);
      break;
       
  }
  pts = "";
  choice = -1;
  check = -1;
  
}
