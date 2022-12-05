void coffee_tea()
{
  String menu[] = {"COFFEE", "TEA", "MILK"};
  String str = "";
  flag = 0;
  while(selection == 0)
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
    joyStick();
    if(button == "s")
    {
      button = "";
      selection = 1;
      str = menu[flag];
      delay(dt);
      while(selection_qty == 0)
      {

        joyStick(); 
        if(button == "s")
        {
          button = "";
          selection_qty = 1;
          break;
        }
        qty();
      }
      while(digitalRead(sPin) == LOW)
      {}
      break;
    }
  }
  delay(dt);
  selection = 0;
  
  while(selection == 0)
  {
    joyStick();
    if(button == "s")
    {
      button = "";
      selection = 1;
      break;
    }
    checkout();
  }
  delay(dt);

  selection = 0;
  selection_qty = 0;
  flag = 0;
  cnt = 1;
}
