void checkout()
{
  char ch_q[10];    
  char ch_f[10]; // If error in printing comes then increase buffer size...
  char ch_p[10];
  itoa(q[0], ch_q, 10);  
  itoa(p[0], ch_p, 10);
  f[0].toCharArray(ch_f, 10);
  
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x10_tr); 
  u8g2.drawStr(35,10,"YOUR CART"); 
  u8g2.drawLine(5, 12, 122, 12);
  u8g2.setFont(u8g2_font_5x8_tr);
  
  u8g2.drawStr(8, 25, ch_f);
  u8g2.drawStr(82, 25, ch_p);
  u8g2.setCursor(93, 25);
  u8g2.print("/-");
  
  u8g2.drawStr(110, 25, "x\n");
  u8g2.setCursor(115, 25);
  u8g2.print(ch_q);

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
  }  
  u8g2.setFontMode(1);
  u8g2.setDrawColor(1);
  u8g2.drawBox((xPos+(xCnt*71)), 55, 45, 11);
  u8g2.setDrawColor(2);

  u8g2.drawStr(6,63,"ADD-ITEM");  
  u8g2.drawStr(80,63,"CHECKOUT");
  
  u8g2.sendBuffer();
}
