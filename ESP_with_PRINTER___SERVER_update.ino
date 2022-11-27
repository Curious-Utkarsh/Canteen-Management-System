#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <HTTPClient.h>
#include <Adafruit_Thermal.h>

#define RXp2 16 // for printer
#define TXp2 17 // for printer

Adafruit_Thermal printer(&Serial2);      //for printer

const char *ssid     = "172.0.0.0";
const char *password = "8652070679";

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

String UID = "";

String server = "http://maker.ifttt.com";
String eventName = "Serial_Data";
String IFTTT_Key = "Ebs08WehpN9Vqk20Kk4sg";
String IFTTTUrl="http://maker.ifttt.com/trigger/Serial_Data/with/key/Ebs08WehpN9Vqk20Kk4sg";


void setup()
{
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2); // Esp talks with printer
  WiFi.mode(WIFI_STA);
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
  Serial.println();
  formattedTime = timeClient.getFormattedTime();

  hh = String(timeClient.getHours());
  mn = String(timeClient.getMinutes());

  Time = (hh+":"+mn);
  Serial.println("TIME : "+Time);

  int day = timeClient.getDay();
  today = daysWeek[day];
  Serial.println("TODAY : "+today);

  date_time = timeClient.getFormattedDate();

  int index_date = date_time.indexOf("T");
  dd = date_time.substring(8, index_date);
  mm = date_time.substring(5, index_date-3);
  yyyy = date_time.substring(0, index_date-6);

  date = (dd+"/"+mm+"/"+yyyy);
  Serial.println("DATE : "+date);

  Serial.println("Enter Name");
  while(Serial.available()==0)
  {}
  UID = Serial.readStringUntil('#');
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
  sendDataToSheet();

  Serial.println();
  
  delay(1000);

  UID = "";
  cost = "";
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
  printer.println(" QTY   ORDER\t\t PRICE");
  printer.println();
  printer.print("  "+qty+"    "+order+"\t\t "+cost);
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
  printer.print("-- POWERED BY : ENGINEERS --");
  printer.println("\n");  
  printer.println();
  printer.write(10);
  printer.write(10);
  printer.write(10);
}

void sendDataToSheet(void)
{
  String url = server + "/trigger/" + eventName + "/with/key/" + IFTTT_Key + "?value1="+String(UID) + "&value2="+String(cost);  
  Serial.println(url);
  //Start to send data to IFTTT
  HTTPClient http;
  Serial.print("[HTTP] begin...\n");
  http.begin(url); //HTTP

  Serial.print("[HTTP] GET...\n");
  // start connection and send HTTP header
  int httpCode = http.GET();
  // httpCode will be negative on error
  if(httpCode > 0) 
  {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    // file found at server
    if(httpCode == HTTP_CODE_OK) 
    {
      String payload = http.getString();
      Serial.println(payload);
    }
  } 
  else 
  {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
}
