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

String items[3];
String qtys[3];
String prices[3];
String amounts[3];


String item = ""; // get from arduino
String qty = ""; // get from arduino
String price = ""; // get from arduino
String amount = ""; // get from arduino
String gTotal = ""; // get from arduino
String y = ""; // get from arduino
int n = 0; //get

String dataPack = ""; // to unpack data got from arduino

int len = 0;

void setup()
{
  Serial.begin(9600);
  dataPack = "2*Maggie,Tea,Coffee*2,3,5*25,10,10*50,30,50*500";
  unpack(dataPack);
  for(int i = 0;i<3;i++)
  {
    Serial.println("ITEMS ARE : "+items[i]);
  }
    for(int i = 0;i<3;i++)
  {
    Serial.println("QTY ARE : "+qtys[i]);
  }
    for(int i = 0;i<3;i++)
  {
    Serial.println("PRICE ARE : "+prices[i]);
  }
}

void loop() 
{
  
}
