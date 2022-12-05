void checkout()
{
  char cnt_ch[10];    
  itoa(cnt, cnt_ch, 10);  
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x10_tr); 
  u8g2.drawStr(35,10,"YOUR CART"); 
  u8g2.drawLine(5, 12, 122, 12);
  u8g2.setFont(u8g2_font_5x8_tr);
  u8g2.setCursor(55, 45);
  u8g2.print(cnt_ch);

  joyStick();

  if(button == "r")
  {
    xCnt = 1;
    button = "";
  }
  if(button == "l")
  {
    xCnt = 0;
    button = "";
  }  
  u8g2.setFontMode(1);
  u8g2.setDrawColor(1);
  u8g2.drawBox((xPos+(xCnt*71)), 55, 45, 11);
  u8g2.setDrawColor(2);

  u8g2.drawStr(6,63,"ADD-ITEM");  
  u8g2.drawStr(80,63,"CHECKOUT");
  
  u8g2.sendBuffer();
}
