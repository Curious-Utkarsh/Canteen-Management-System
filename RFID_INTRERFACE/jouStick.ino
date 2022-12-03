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
  }

  if(xVal >= 1000)
  {
    button = "r";
  }
  if(xVal <= 23)
  {
    button = "l";
  }
  if(yVal >= 1000)
  {
    button = "u";
  }
  if(yVal <= 23)
  {
    button = "d";
  }
  if(sVal == LOW)
  {
    button = "s";
  }
}
