void input()
{
inp = "";
customKey = ' ';
int index = 0;
const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = 
{
  {'A', '2', '3', '1'},
  {'B', '5', '6', '4'},
  {'C', '8', '9', '7'},
  {'D', '0', '#', '*'}
};

byte rowPins[ROWS] = {A7, A6, A5, A4}; 
byte colPins[COLS] = {A3, A2, A1, A0}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
while(true)
{
  customKey = customKeypad.getKey();
  if(customKeypad.getState() != PRESSED)
  {
    if(Serial.available() == 0){}
    else{
      inp=String(Serial.readStringUntil('#'));
      Serial.println(inp);
      break;
    }
    continue;
  }
  if(customKey == '#')
  {
    break;
  }
//  if(customKey == 'A')
//  {
//    break;
//  }
  if(customKey == '*')
  {
    index = inp.length() - 1;
    inp.remove(index);
    Serial.println("");
    Serial.println("After Delete : "+inp);
    Serial.println("");
    continue;
  }
  inp = inp + String(customKey);
  Serial.print(customKey);
}
Serial.println();
}
