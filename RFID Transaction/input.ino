void input()
{
inp = "";
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
while(customKey!='#')
{
  customKey = customKeypad.getKey();
  inp = inp + String(customKey);
  Serial.print(customKey);
}
inp.remove('#');
Serial.println();
}
