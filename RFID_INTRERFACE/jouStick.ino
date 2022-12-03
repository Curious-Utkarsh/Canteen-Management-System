void joyStick()
{
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  sVal = digitalRead(sPin);
  //Serial.println(xVal);
  //Serial.println(yVal);
  //Serial.println("\n");

  if((xVal>=400 && xVal<=600) && (yVal>=400 && yVal<=600))
  {
    check = 0;
    button = "";
    rst = 1;
  }
  if(rst == 1)
  {
    if(xVal >= 1000)
    {
      button = "r";
    }
    if(xVal <= 23)
    {
      button = "l";
    }
    if(yVal >= 1000 && (yPos >= 16 && yPos <= (yPos + ((count-1)*10))) && (flag > 0))
    {
      button = "u";
      flag--;
      rst = 0;
    }
    if(yVal <= 23 && (yPos >= 16 && yPos <= (yPos + ((count-1)*10))) && (flag < (count-1)))
    {
      button = "d";
      flag++;
      rst = 0;
    }
    if(sVal == LOW)
    {
      button = "s";
      rst = 0;
    }
}
}
