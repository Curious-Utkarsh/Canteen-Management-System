void coffee_tea()
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

    u8g2.drawStr(8, 25, "COFFEE         15/-\n");
    u8g2.drawStr(8, 35, "TEA            10/-\n");
    u8g2.drawStr(8, 45, "MILK           10/-");
    u8g2.sendBuffer();   
    joyStick();
    if(digitalRead(backPin) == LOW)
    {
      backState = 1;
      break;
    }
    if(button == 's')
    {
      button = ' ';
      sl = 1;
      if(flag == 0)
      {
        f[y] = "COFFEE";
        p[y] = 15;
      }
      if(flag == 1)
      {
        f[y] = "TEA   ";
        p[y] = 10;
      }
      if(flag == 2)
      {
        f[y] = "MILK  ";
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
      }
      q[y] = cnt;
      while(digitalRead(sPin) == LOW)
      {}
      break;
    }
  }
  delay(dt);
  sl = 0;

  if(backState == 0)
  {
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
          u8g2.clearBuffer();
          u8g2.setFont(u8g2_font_6x10_tr); 
          u8g2.drawStr(32,10,"MAKE PAYMENT"); 
          u8g2.drawLine(5, 12, 122, 12);
  
          if(pay == 0)
          {
            for(byte i = 0; i<=y; i++)
            {
              sum = sum + (p[i]*q[i]);
              pay = 1;
            }
          }
          char s[10];
          itoa(sum, s, 10);
          u8g2.setFont( u8g2_font_courB12_tr);
          u8g2.setCursor(2, 28);
          u8g2.print("AMOUNT TO BE");
          u8g2.setCursor(10, 42);
          u8g2.print("PAID : ");
          if(sum <= 99)
          {
            u8g2.setCursor(78, 42);
            u8g2.print(s);
          }
          if(sum >= 100)
          {
            u8g2.setCursor(70, 42);
            u8g2.print(s);
          }
          u8g2.setCursor(99, 42);
          u8g2.print("/-");
          u8g2.setFont(u8g2_font_t0_11_tr);
          u8g2.setCursor(2, 60);
          u8g2.print("--PLACE CARD TO PAY--");
          
          u8g2.sendBuffer();
          detectCard();
          scan(-1);
          if(button == 's')
          {
            button = ' ';
            sl = 1;
            String f[3];
            byte p[3];
            byte q[3];
            y = 0;
            sum = 0;
            pay = 0;
            break;
          }
        }
          break;
        }
      checkout();
    }
  }
  delay(dt);

  sl = 0;
  slq = 0;
  flag = 0;
  cnt = 1;
  backState = 0;
}
