void unpack(String dataPack)
{
  len = dataPack.length();
  UID = "";
  price = "";
  qty = "";
  order = "";
  
  String temp = "";
  int count = 0;
  
  for(int i=0;i<len;i++)
  {
    if(dataPack.charAt(i) == '#')
    {
      if(count == 0) UID = temp;
      if(count == 1) price = temp;
      if(count == 2) qty = temp;
      if(count == 3) order = temp;
      temp = "";
      count = count + 1;
    }
    else
    {
      temp = temp + dataPack.charAt(i);
    }
  }
  order = temp;
  Serial.println("ID is : "+UID);
  Serial.println("AMT PAID is : "+price);
  Serial.println("QTY is : "+qty);
  Serial.println("FOOD NAME is : "+order);
}
