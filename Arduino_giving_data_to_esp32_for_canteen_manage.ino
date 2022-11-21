#include <SoftwareSerial.h>

SoftwareSerial mySerial(8 , 7); //(rx, tx)

String ID = "";
String Unp_Paid = "";
String dataPack = "";

void setup() 
{
  Serial.begin(115200);
  mySerial.begin(9600);
}

void loop() 
{
  Serial.println("Enter ID / Name of Customer.......#");
  while(Serial.available()==0)
  {}
  ID = Serial.readStringUntil('#');
  Serial.println();
  Serial.println("Enter UNP Paid.......#");
  while(Serial.available()==0)
  {}
  Unp_Paid = Serial.readStringUntil('#');
  Serial.println();
  Serial.print("ID/Name Entered is : ");
  Serial.println(ID);
  Serial.print("UNP Paid is : ");
  Serial.println(Unp_Paid);
  Serial.println();

  dataPack = (ID+"#"+Unp_Paid);

  mySerial.println(dataPack);

  ID = "";
  Unp_Paid = "";
  dataPack = "";
}

