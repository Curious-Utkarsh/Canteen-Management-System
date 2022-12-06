void checkout()
{
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x10_tr); 
  u8g2.drawStr(35,10,"YOUR CART"); 
  u8g2.drawLine(5, 12, 122, 12);
  u8g2.setFont(u8g2_font_5x8_tr);

  char ch_q[10];    
  char ch_f[10]; // If error in printing comes then increase buffer size...
  char ch_p[10];
  
  for(byte i = 0; i<=y; i++)
  {
    itoa(q[i], ch_q, 10);  
    itoa(p[i], ch_p, 10);
    f[i].toCharArray(ch_f, 10);
    u8g2.drawStr(8, (25+(i*10)), ch_f);
    u8g2.drawStr(82, (25+(i*10)), ch_p);
    u8g2.setCursor(115, (25+(i*10)));
    u8g2.print(ch_q);
    u8g2.setCursor(93, (25+(i*10)));
    u8g2.print("/-");
    u8g2.drawStr(110, (25+(i*10)), "x\n");
  }
  
  joyStick();

  if(button == 'r')
  {
    xCnt = 1;
    button = ' ';
  }
  if(button == 'l')
  {
    xCnt = 0;
    button = ' ';
    slq = 0;
  }  
  u8g2.setFontMode(1);
  u8g2.setDrawColor(1);
  u8g2.drawBox((xPos+(xCnt*71)), 55, 45, 11);
  u8g2.setDrawColor(2);

  u8g2.drawStr(6,63,"ADD-ITEM");  //xCnt = 0
  u8g2.drawStr(80,63,"  PAY  ");  //xCnt = 1
  
  u8g2.sendBuffer();
}
