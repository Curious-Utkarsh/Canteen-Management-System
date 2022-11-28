#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <HTTPClient.h>
#include <Adafruit_Thermal.h>
#include <HardwareSerial.h>

HardwareSerial SerialPort(1); // esp talk to arduino

#define RXp1 4 // esp talk to arduino
#define TXp1 2

#define RXp2 16 // esp talk to printer
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

String order = ""; // get from arduino
String qty = ""; // get from arduino
String price = ""; // get from arduino
String UID = ""; // get from arduino

String dataPack = ""; // to unpack data got from arduino

int len = 0;

String server = "http://maker.ifttt.com";
String eventName = "Serial_Data";
String IFTTT_Key = "Ebs08WehpN9Vqk20Kk4sg";
String IFTTTUrl="http://maker.ifttt.com/trigger/Serial_Data/with/key/Ebs08WehpN9Vqk20Kk4sg";


void setup()
{
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2); // Esp talks with printer
  SerialPort.begin(9600, SERIAL_8N1, RXp1, TXp1); // Esp talks to arduino
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
  geTTime();
  if(SerialPort.available() > 0)
  {
    dataPack = SerialPort.readString();
    len = dataPack.length();
    if(len>2)
    {
      Serial.println("...DATA_PACK Recieved...");
      Serial.println();
      unpack(dataPack);
      printBill();
      sendDataToSheet();
      Serial.println();
      UID = "";
      price = "";
      dataPack = "";
    }
}
delay(1000);
}
