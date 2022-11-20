#include <WiFi.h>
#include <HTTPClient.h>

const char * ssid = "172.0.0.0";
const char * password = "8652070679";

String server = "http://maker.ifttt.com";
String eventName = "Serial_Data";
String IFTTT_Key = "Ebs08WehpN9Vqk20Kk4sg";
String IFTTTUrl="http://maker.ifttt.com/trigger/Serial_Data/with/key/Ebs08WehpN9Vqk20Kk4sg";

String Payment = "";
String Name = "";

void setup() 
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Hurray, Connected !!!");
}

void sendDataToSheet(void)
{
  String url = server + "/trigger/" + eventName + "/with/key/" + IFTTT_Key + "?value1="+Name + "&value2="+Payment;  
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

void loop() 
{
  delay(1000);
  Serial.println("Enter NAME");
  while(Serial.available()==0)
  {}
  Name=Serial.readStringUntil('#');

  Serial.println("Enter Amount Paid");
  while(Serial.available()==0)
  {}
  Payment=Serial.readStringUntil('#');

  Serial.print("Name is : ");
  Serial.println(Name);
  Serial.println();
  Serial.print("Amount Paid is : ");
  Serial.println(Payment);
  Serial.println();

  sendDataToSheet();
  //delay(10000);
}
