void esp_data() 
{
  Elx_Paid = String(sum);
  
  dataPack = (ID+"#"+Elx_Paid+"#");

  mySerial.println(dataPack);

  ID = "";
  Elx_Paid = "";
  dataPack = "";
}
