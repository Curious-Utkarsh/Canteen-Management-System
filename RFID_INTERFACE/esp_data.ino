void esp_data() 
{
  for(byte i = 0; i<=y; i++)
  {
    if(r == y)
    {
      item = (item + (f[i]));
      qtyy = (qtyy + (q[i]));
      price = (price + (p[i]) + "/-");
      amt = (amt + String(p[i]*q[i]) + "/-");
    }
    else
    {
      item = (item + (f[i]) + ",");
      qtyy = (qtyy + (q[i]) + ",");
      price = (price + (p[i]) + "/-,");
      amt = (amt + String(p[i]*q[i]) + "/-,");
    }
    r++;
  }
  gTotal = String(sum);
  gTotal = (gTotal+"/-");
  r = 0;
  
  dataPack = ((String(y))+"*"+item+"*"+qtyy+"*"+price+"*"+amt+"*"+gTotal);
  Serial.println(dataPack);

  mySerial.println(dataPack);

  item = "";
  price = "";
  qtyy = "";
  amt = "";
  gTotal = "";
  dataPack = "";
}
