void thali()
{
  byte sl = 0;
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

    u8g2.drawStr(8, 25, "HALF-PLT       40/-\n");
    u8g2.drawStr(8, 35, "FULL-PLT       70/-\n");
    u8g2.sendBuffer();   
    joyStick();
    if(button == 's')
    {
      button = ' ';
      sl = 1;
      if(flag == 0)
      {
        f[y] = "HALF-PLT";
        p[y] = 40;
      }
      if(flag == 1)
      {
        f[y] = "FULL-PLT";
        p[y] = 70;
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
    if(button == 's' && slq == 0 && y<2)
    {
      button = ' ';
      sl = 1;
      y++;
      xCnt = 1;
      slq = 1;
      break;
    }
    if(button == 's' && xCnt == 1)
    {
      button = ' ';
      sl = 2;
      while(digitalRead(sPin) == LOW)
      {}
      while(sl == 2)
      {
        joyStick();
        if(button == 's')
        {
          button = ' ';
          sl = 1;
          String f[3];
          byte p[3];
          byte q[3];
          y = 0;
          break;
          
        }
        u8g2.clearBuffer();
        u8g2.setFont(u8g2_font_6x10_tr); 
        u8g2.drawStr(30,10,"MAKE PAYMENT"); 
        u8g2.drawLine(5, 12, 122, 12);
        u8g2.sendBuffer();
      }
        break;
      }
    checkout();
  }
  delay(dt);

  sl = 0;
  slq = 0;
  flag = 0;
  cnt = 1;
}
