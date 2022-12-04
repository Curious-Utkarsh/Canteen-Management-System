void coffee_tea()
{
  String menu[] = {{"COFFEE"}, {"TEA"}, {"MILK"}};
  String str = "";
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
      selection = 1;
      str = String(menu[flag]);
      delay(500);
      while(selection_qty == 0)
      {

        buttonPress(); // LONG PRESS SWITCH TO CHECKOUT THE QUANTITY ENTERED...
        if(button == "s")
        {
          selection_qty = 1;
          break;
        }
        qty();
      }
      break;
    }
  }
  delay(100);


  selection = 0;
  selection_qty = 0;
  flag = 0;
}
