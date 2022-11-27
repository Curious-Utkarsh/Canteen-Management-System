void unpack(String dPack)
{
  int len = dPack.length();
  String IDu = "";
  String Elx_Paidu = "";
  String qtyu = "";
  String fNameu = "";
  
  String temp = "";
  int count = 0;
  
  for(int i=0;i<len;i++)
  {
    if(dPack.charAt(i) == '#')
    {
      if(count == 0) IDu = temp;
      if(count == 1) Elx_Paidu = temp;
      if(count == 2) qtyu = temp;
      if(count == 3) fNameu = temp;
      temp = "";
      count = count + 1;
    }
    else
    {
      temp = temp + dPack.charAt(i);
    }
  }
  fNameu = temp;
  Serial.println("ID is : "+IDu);
  Serial.println("AMT PAID is : "+Elx_Paidu);
  Serial.println("QTY is : "+qtyu);
  Serial.println("FOOD NAME is : "+fNameu);
}
