#include <SPI.h>
#include <MFRC522.h>
#include <Keypad.h>
#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

String pts = "";
String inp="";
char customKey = '';
int balance_pts = 0;
int deduct_pts = 0;
String deduct_ptss = "";
int new_balance_pts = 0;
String new_balance_ptss = "";
String ch = "";
int choice = 0;

void setup() 
{
  Serial.begin(9600);        // Initialize serial communications with the PC
  SPI.begin();               // Init SPI bus
  mfrc522.PCD_Init();        // Init MFRC522 card
}

void loop()
{
  Serial.println(".....PRESS '1' TO ADD UNP TO CARD.....");
  Serial.println(".....PRESS '2' TO CHECK BALANCE UNP IN CARD.....");
  Serial.println(".....PRESS '3' TO MAKE TRANSACTION.....");
  Serial.println();

  while(Serial.available() == 0)
  {}

  ch = Serial.readStringUntil('#');
  choice = ch.toInt();

  switch(choice)
  {
    case 1:
    Serial.println("PLACE CARD ON SCANNER TO ADD UNP  #");
    delay(3000);
    write_unp();
    Serial.println("UNP ADDED");
    delay(1000);
    Serial.println("REMOVE CARD");
    Serial.println();
    delay(4000);
    break;

    case 2:
    Serial.println("PLACE CARD ON SCANNER TO CHECK BALANCE UNP");
    delay(3000);
    read_unp();
    Serial.print("BALANCE UNP IN CARD : ");
    Serial.println(balance_pts);
    delay(1000);
    Serial.println("REMOVE CARD");
    Serial.println();
    delay(4000);
    break;

    case 3:
    Serial.println("ENTER UNP TO DEDUCT  #");
    while(Serial.available()== 0)
    {}
    deduct_ptss = Serial.readStringUntil('#');
    deduct_pts = deduct_ptss.toInt();
    Serial.print("POINTS TO BE DEDUCTED : ");
    Serial.println(deduct_pts);
    delay(1000);
    
    Serial.println("PLACE CARD ON SCANNER TO MAKE TRANSACTION");
    delay(3000);
    read_write_new_unp();
    Serial.println("TRANSACTION MADE SUCCESSFULLY");
    delay(1000);
    Serial.println("REMOVE CARD");
    Serial.println();
    delay(3000);
    break;

    default :
    Serial.println("INVALID CHOICE");
    Serial.println();
    break; 
  }
  pts=""; // this line is very important

}
