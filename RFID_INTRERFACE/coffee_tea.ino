void coffee_tea()
{
  u8g2.setFont(u8g2_font_6x10_tr);
  while(true)
  {
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.drawStr(50,10,"Hello World!");  // write something to the internal memory
  u8g2.sendBuffer();          // transfer internal memory to the display
  }
}
