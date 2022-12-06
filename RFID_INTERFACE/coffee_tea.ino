void coffee_tea()
{
  byte sl = 0;
  byte slq = 0;
  flag = 0;
  while(sl == 0)
  {
    u8g2.clearBuffer();         
    u8g2.setFont(u8g2_font_6x10_tr); 
    u8g2.drawStr(30,10,"SELECT ITEM");  
    u8g2.drawLine(5, 12, 122, 12);

    joyStick(); //cursor()
    u8g2.setFontMode(1);
    u8g2.setDrawColor(1);
    u8g2.drawBox(4, (yPos + (flag*10)), 120, 11);
    u8g2.setDrawColor(2);  

    u8g2.drawStr(8, 25, "COFFEE         10/-\n");
    u8g2.drawStr(8, 35, "TEA            10/-\n");
    u8g2.drawStr(8, 45, "MILK           10/-");
    u8g2.sendBuffer();   
    joyStick();
    if(button == 's')
    {
      button = ' ';
      sl = 1;
      if(flag == 0)
      {
        f[y] = "COFFEE";
        p[y] = 10;
      }
      if(flag == 1)
      {
        f[y] = "TEA";
        p[y] = 10;
      }
      if(flag == 2)
      {
        f[y] = "MILK";
        p[y] = 10;
      }
      delay(dt);
      while(slq == 0)
      {
        joyStick(); 
        if(button == 's')
        {
          button = ' ';
          slq = 1;
          break;
        }
        qty();
        q[y] = cnt;
      }
      while(digitalRead(sPin) == LOW)
      {}
      break;
    }
  }
  delay(dt);
  sl = 0;
  
  while(sl == 0)
  {
    joyStick();
    if(button == 's')
    {
      button = ' ';
      sl = 1;
      break;
    }
    checkout();
  }
  delay(dt);

  sl = 0;
  slq = 0;
  flag = 0;
  cnt = 1;
  y++;
}
