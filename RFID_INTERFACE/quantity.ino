void qty()
{
  u8g2.clearBuffer();          
  u8g2.setFont(u8g2_font_6x12_tr); 
  u8g2.drawStr(25,11,"ENTER QUANTITY");  
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setCursor(35, 44);
  u8g2.print("<");
  u8g2.setCursor(85, 44);
  u8g2.print(">");
  u8g2.setFont(u8g2_font_6x12_tr);
  u8g2.drawLine(5, 14, 122, 14);
  counter();
  u8g2.sendBuffer();
}
