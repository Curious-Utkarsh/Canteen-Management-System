#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

String pts = "";
int balance_pts = 0;
int deduct_pts = 0;
String deduct_ptss = "";
int new_balance_pts = 0;
String new_balance_ptss = "";

void setup() 
{
  Serial.begin(9600);        // Initialize serial communications with the PC
  //while (!Serial); 
  SPI.begin();               // Init SPI bus
  mfrc522.PCD_Init();        // Init MFRC522 card
}

void loop()
{
  Serial.println("PUT CARD to Write Points");
  delay(3000);
  write_unp();
  Serial.println("REMOVE CARD");
  delay(4000);

  Serial.println("Enter Points to Deduct");
  while(Serial.available()== 0)
  {}
  deduct_ptss = Serial.readStringUntil('#');
  deduct_pts = deduct_ptss.toInt();
  Serial.print("POINTS TO BE DEDUCTED : ");
  Serial.println(deduct_pts);
  delay(1000);
   
  Serial.println("PUT CARD to Transacte");
  delay(3000);
  read_write_new_unp();
  //Serial.print("BALACE POINTS IN CARD : ");
  //Serial.println(balance_pts);
  //delay(2000);
  //Serial.println("REMOVE CARD");

//  new_balance_pts = int(balance_pts - deduct_pts);
  //Serial.print("NEW BALANCE POINTS AFTER DEDN : ");
  //Serial.println(new_balance_pts);
  //delay(2000);
  //Serial.println("Writing New Points to Card");
  //delay(3000);
  //Serial.println("Put Card to write new balance points after deduction");
  //delay(3000);
  //write_new_unp();
  Serial.println("REMOVE CARD");
  delay(3000);
  Serial.println("PUT CARD TO READ NEW UNP");
  delay(3000);
  pts=""; // this line is very important
  read_unp();
  Serial.print("NEW BALANCE POINTS : ");
  Serial.println(balance_pts);
  Serial.println("REMOVE CARD FINALLY");
  delay(5000);
  exit(0);
}
