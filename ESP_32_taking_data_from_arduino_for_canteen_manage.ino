#include <WiFi.h>
#include <HTTPClient.h>

#define RXp2 16
#define TXp2 17

String ID = "";
String Unp_Paid = "";
String dataPack = "";
int len = 0;
int i = 0;

const char * ssid = "172.0.0.0";
const char * password = "8652070679";

String server = "http://maker.ifttt.com";
String eventName = "Serial_Data";
String IFTTT_Key = "Ebs08WehpN9Vqk20Kk4sg";
String IFTTTUrl="http://maker.ifttt.com/trigger/Serial_Data/with/key/Ebs08WehpN9Vqk20Kk4sg";


void setup() 
{ 
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);

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
  String url = server + "/trigger/" + eventName + "/with/key/" + IFTTT_Key + "?value1="+String(ID) + "&value2="+String(Unp_Paid);  
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
  if(Serial2.available()>0)
  {
    dataPack = Serial2.readString();
    len = dataPack.length();
    if(len>2)
    {
      Serial.println("...DATA_PACK Recieved...");
      Serial.println();
      for(i=0; i<len; i++)
      {
        char ch = dataPack.charAt(i);
        if(ch != '#')
        {
          ID = ID + String(ch);
        }
        else
        {
          break;
        }
      }
    
      Unp_Paid = (dataPack.substring(i+1)).toInt();
  
      Serial.print("ID/Name Entered is : ");
      Serial.println(ID);
      Serial.print("UNP Paid is : ");
      Serial.println(Unp_Paid);
      Serial.println();

      sendDataToSheet();
  
      ID = "";
      Unp_Paid = "";
      dataPack = "";
      len = 0;
      i = 0;
      }
  }
}
