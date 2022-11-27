void input()
{
inp = "";
customKey = ' ';
int index = 0;
const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; 
byte colPins[COLS] = {4, 3, 2, 1}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
while(true)
{
  customKey = customKeypad.getKey();
  if(customKeypad.getState() != PRESSED)
  {
    continue;
  }
  if(customKey == '#')
  {
    break;
  }
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
