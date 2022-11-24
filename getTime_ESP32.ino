#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>

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

void setup()
{
  Serial.begin(115200);

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
  
  delay(1000);
}
