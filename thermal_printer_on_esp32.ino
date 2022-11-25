#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "Adafruit_Thermal.h"

#define RXp2 16
#define TXp2 17

Adafruit_Thermal printer(&Serial2);     

const char *ssid     = "You2.4";
const char *password = "12341234";

WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800);

String formattedTime = "";
String hh = "";
String mn = "";
String date_time = "";
String dd = "";
String mm = "";
String yyyy = "";
String date = "";
String Time = "";
String today = "";

String daysWeek[] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"}; 

String order = "";
String qty = "";
String cost = "";

void setup()
{
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) 
  {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() 
{
  timeClient.update();
  //Serial.println();
  formattedTime = timeClient.getFormattedTime();

  hh = String(timeClient.getHours());
  mn = String(timeClient.getMinutes());

  Time = (hh+":"+mn);
  //Serial.println("TIME : "+Time);

  int day = timeClient.getDay();
  today = daysWeek[day];
  //Serial.println("TODAY : "+today);

  date_time = timeClient.getFormattedDate();

  int index_date = date_time.indexOf("T");
  dd = date_time.substring(8, index_date);
  mm = date_time.substring(5, index_date-3);
  yyyy = date_time.substring(0, index_date-6);

  date = (dd+"/"+mm+"/"+yyyy);
  //Serial.println("DATE : "+date);

  Serial.println("Enter Food To be Ordered");
  while(Serial.available()==0)
  {}
  order = Serial.readStringUntil('#');
  Serial.println("Enter Quantity");
  while(Serial.available()==0)
  {}
  qty = Serial.readStringUntil('#');
  Serial.println("Enter Price");
  while(Serial.available()==0)
  {}
  cost = Serial.readStringUntil('#');

  printBill();
  
  delay(1000);

  
}


void printBill()
{
  printer.begin();
  printer.justify('C');
  printer.println("***   WELCOME TO COSMOS   ***");
  printer.justify('C');
  printer.setSize('S');        // Set type size, accepts 'S', 'M', 'L'
  printer.println("_______________\n");
  printer.boldOn();
  printer.justify('L');
  printer.setSize('S');
  printer.println("QTY   ORDER            PRICE");
  printer.println();
  printer.print(qty+"     "+order+"       "+cost);
  printer.println("\n");
  printer.boldOff();
  printer.print("\n");
  printer.justify('C');
  printer.setSize('S');
  printer.println("***  HAVE A NICE DAY  ***");
  printer.justify('C');
  printer.print("DATE:"+date+"\t");
  printer.println("TIME:"+Time);
  printer.println("TODAY:"+today); 
  printer.print("\n");
  printer.print("--POWERED BY : UTK & NIM--");
  printer.println("\n");  
  printer.write(10);
  printer.write(10);
  printer.write(10);
}
