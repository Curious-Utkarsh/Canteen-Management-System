#include <SPI.h>
#include <MFRC522.h>
#include <Keypad.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD SDA -> A4; SCL -> A5

String pts = "";
String inp="";
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
String content= "";
int cardDet = 1;

void setup() 
{
  Serial.begin(9600);        // Initialize serial communications with the PC
  SPI.begin();               // Init SPI bus
  mfrc522.PCD_Init();        // Init MFRC522 card
  lcd.init();
}

void loop()
{

  Serial.println(".....PRESS '1' TO ADD UNP TO CARD.....");
  Serial.println(".....PRESS '2' TO CHECK BALANCE UNP IN CARD.....");
  Serial.println(".....PRESS '3' TO MAKE TRANSACTION.....");
  Serial.println();

  while(choice==-1)
  {
    input();
    choice = inp.toInt();

  }

  switch(choice)
  {
    case 1:
    Serial.println("PLACE CARD ON SCANNER TO ADD UNP  #");
    lcd_place_card();
    while(cardDet == 1)
    {
        // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    continue;
  }
  cardDet = 0;
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

    }
    write_unp();
    Serial.println("UNP ADDED");
    lcd_unp_added();
    delay(1000);
    lcd.clear();
    lcd_bal_pts();
    Serial.println("REMOVE CARD");
    lcd_rmv_card();
    Serial.println();
    delay(4000);
    cardDet = 0;
    break;

    case 2:
    Serial.println("PLACE CARD ON SCANNER TO CHECK BALANCE UNP");
    delay(3000);
    read_unp();
    Serial.print("BALANCE UNP IN CARD : ");
    Serial.println(balance_pts);
    lcd_bal_pts();
    delay(1000);
    Serial.println("REMOVE CARD");
    Serial.println();
    lcd_rmv_card();
    delay(4000);
    break;

    case 3:
    menu();
//    Serial.println("ENTER UNP TO DEDUCT  #");
//    while(Serial.available()== 0)
//    {}
//    deduct_ptss = Serial.readStringUntil('#');
//    deduct_pts = deduct_ptss.toInt();
//    Serial.print("POINTS TO BE DEDUCTED : ");
//    Serial.println(deduct_pts);
//    delay(1000);
//    
//    Serial.println("PLACE CARD ON SCANNER TO MAKE TRANSACTION");
//    delay(3000);
//    read_write_new_unp();
//    if(check == 0)
//    {
//      Serial.println("TRANSACTION WAS UNSUCCESSFUL!");
//      check = -1;
//    }
//    else{
//      Serial.println("TRANSACTION MADE SUCCESSFULLY");
//      delay(1000);
//      Serial.println("REMOVE CARD");
//      Serial.println();
//      delay(3000);
//    }
    break;

    default :
    Serial.println("INVALID CHOICE");
    Serial.println();
    lcd.setCursor(0,0);
    lcd.print("Invalid Choice");
    break; 
  }
  pts="";
  choice = -1;
  check = -1;// this line is very important

}
