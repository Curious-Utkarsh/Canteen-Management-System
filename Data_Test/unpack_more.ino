void unpack_more(String sz, String pData, int sel)
{
  n = sz.toInt();
  n += 1;
  String unpacked[n];
  for(int i=0;i<n;i++)
  {
    unpacked[i] = "";
  }
  len = pData.length();
  
  String temp = "";
  int count = 0;
  
  for(int i=0;i<len;i++)
  {
    if(pData.charAt(i) == ',')
    {
      unpacked[count] = temp;
      temp = "";
      count = count + 1;
    }
    else
    {
      temp = temp + pData.charAt(i);
    }
  }
  unpacked[count] = temp;
  if(sel == 0)
  {
    for(int i=0;i<n;i++)
    {
      items[i] = unpacked[i];
    }
  }
  if(sel == 1)
  {
    for(int i=0;i<n;i++)
    {
      qtys[i] = unpacked[i];
    }
  }
  if(sel == 2)
  {
    for(int i=0;i<n;i++)
    {
      prices[i] = unpacked[i];
    }
  }
  if(sel == 3)
  {
    for(int i=0;i<n;i++)
    {
      amounts[i] = unpacked[i];
    }
  }
}
