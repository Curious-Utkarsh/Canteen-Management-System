void check_button_event(void)
{
  joyStick();
  if ( button_event == 0 && check == 0)
  {
    if(button == "r")
    {
      button_event = U8X8_MSG_GPIO_MENU_NEXT;
    }
    if(button == "l")
    {
      button_event = U8X8_MSG_GPIO_MENU_PREV;
    }
    if(button == "s")
    {
      button_event = U8X8_MSG_GPIO_MENU_SELECT;
    }
  }
}
