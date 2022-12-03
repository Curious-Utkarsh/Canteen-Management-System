void coffee_tea()
{
  while(true)
  {
    u8g2.clearBuffer();         
    u8g2.setFont(u8g2_font_6x10_tr); 
    u8g2.drawStr(30,10,"SELECT ITEM");  
    u8g2.drawLine(5, 12, 122, 12);
    Cursor();
    u8g2.drawStr(8, 25, "COFFEE         10/-\n");
    u8g2.drawStr(8, 35, "TEA            10/-\n");
    u8g2.drawStr(8, 45, "MILK           10/-");
    u8g2.sendBuffer();   
  }
}



