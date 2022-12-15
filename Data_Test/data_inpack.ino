void unpack(String dataPack)
{
  len = dataPack.length();
  y = "";
  item = "";
  price = "";
  qty = "";
  amount = "";
  gTotal = "";

  int sel = 0;
  String temp = "";
  int count = 0;
  
  for(int i=0;i<len;i++)
  {
    if(dataPack.charAt(i) == '*')
    {
      if(count == 0) y = temp;
      if(count == 1) item = temp;
      if(count == 2) qty = temp;
      if(count == 3) price = temp;
      if(count == 4) amount = temp;
      if(count == 5) gTotal = temp;
      temp = "";
      count = count + 1;
    }
    else
    {
      temp = temp + dataPack.charAt(i);
    }
  }
  gTotal = temp;
  Serial.println("y is : "+y);
  Serial.println("ITEMS is : "+item);
  Serial.println("QTY is : "+qty);
  Serial.println("PRICE is : "+price);
  Serial.println("AMT is :"+amount);
  Serial.println("gTot is :"+gTotal);
  unpack_more(y,item,sel);
  unpack_more(y,qty,sel+1);
  unpack_more(y,price,sel+2);
  unpack_more(y,amount,sel+3);
  
}
