void Cursor()
{
  joyStick();
  u8g2.setFontMode(1);
  u8g2.setDrawColor(1);
  u8g2.drawBox(4, (yPos + (flag*10)), 120, 11);
  u8g2.setDrawColor(2);  
}
