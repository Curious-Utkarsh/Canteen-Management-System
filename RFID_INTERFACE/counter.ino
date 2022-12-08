void counter()
{
  u8g2.setFont(u8g2_font_ncenB14_tr);
  joyStick();
  if (check == 0)
  {
    if(button == 'r' && (cnt>=1 && cnt<=10))
    {
      cnt++;
      button = ' ';
      check = 1;
    }
    if(button == 'l' && (cnt>1 && cnt<=10))
    {
      cnt--;
      button = ' ';
      check = 1;
    }
  }
  
  if(cnt > 10)
  { 
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.setCursor(9, 28);
    u8g2.print("----LIMIT----");
    u8g2.setCursor(8, 50);
    u8g2.print("EXCEEDED");
    u8g2.sendBuffer();
    cnt = 10;
    delay(2000);
  }
  else
  {
    if(cnt == 10)
    {
        u8g2.setCursor(53, 45);
        u8g2.print(cnt);
    }
    else
    {
        u8g2.setCursor(60, 45);
        u8g2.print(cnt);
    }
  }
}
