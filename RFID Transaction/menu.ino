int total = 0;
int total1 = 0;
int vadapav=15;
int misalpav=40;
int dosa=50;
int samosa=20;
int coldrink=20;
int fruitjuice=25;
int milkshake=30;
char choice1 = " ";

const byte ROWS1 = 4; 
const byte COLS1 = 4;

char hexaKeys1[ROWS1][COLS1] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS1] = {8, 7, 6, 5}; 
byte colPins[COLS1] = {4, 3, 2, 1}; 

void menu(){
  Serial.println("Press 1 to order Food");
  Serial.println(F("Press 2 to order Beevrage"));
  Keypad choiceKeypad = Keypad(makeKeymap(hexaKeys1), rowPins, colPins, ROWS1, COLS1);
  while(choice==-1)
  {
    input();
    choice = inp.toInt();
  }
  switch(choice){
    case 1:
    Serial.println("Make your selection: ");
    Serial.println("Press A to checkout");
//    Keypad choiceKeypad = Keypad(makeKeymap(hexaKeys1), rowPins, colPins, ROWS1, COLS1); 
    menu_driven:
        while(choice1!='A')
        {
          choice1 = choiceKeypad.getKey();
          switch(choice1){
            case 1:
              Serial.println("Vadapav added to cart");
              total+=vadapav;
              lcd.setCursor(0,0);
              lcd.print("VadaPav added to cart");
              break;
              goto menu_driven;
            case 2:
              Serial.println("Misal Pav added to cart");
              total+=misalpav;
              lcd.setCursor(0,0);
              lcd.print("Misal Pav added to cart");
              break;
              goto menu_driven;
            case 3:
              Serial.println("Samosa added to cart");
              total+=samosa;
              lcd.setCursor(0,0);
              lcd.print("Samosa added to cart");
              break;
              goto menu_driven;
            case 4:
              Serial.println("Dosa added to cart");
              total+=dosa;
              lcd.setCursor(0,0);
              lcd.print("Dosa added to cart");      
              break;
              goto menu_driven;
          }
        }
        deduct_ptss=total;
        deduct_pts=total;
        Serial.print("You've to pay ");
        Serial.print(total);
        Serial.println(" points");
        read_write_new_unp();
        if(check == 0)
    {
      Serial.println("TRANSACTION WAS UNSUCCESSFUL!");
      check = -1;
    }
    else{
      Serial.println("TRANSACTION MADE SUCCESSFULLY");
      delay(1000);
      Serial.println("REMOVE CARD");
      Serial.println();
      delay(3000);
    }
    break;
    case 2:
      Serial.println("Make your selection: ");
      Serial.println("Press A to checkout");
//      Keypad choiceKeypad = Keypad(makeKeymap(hexaKeys1), rowPins, colPins, ROWS1, COLS1); 
      menu_driven1:
          while(choice1!='A'){
            choice1 = choiceKeypad.getKey();
            switch(choice1){
              case 1:
                Serial.println("Cold drink added to cart");
                total1+=coldrink;
                lcd.setCursor(0,0);
                lcd.print("Cold drink added to cart");
                break;
                goto menu_driven1;
              case 2:
                Serial.println("Fruit Juice added to cart");
                total1+=fruitjuice;
                lcd.print("Fruit Juice added to cart");
                total1+=coldrink;
                break;
                goto menu_driven1;
              case 3:
                Serial.println("Milkshake added to cart");
                total1+=milkshake;
                lcd.print("Milkshake added to cart");
                total1+=coldrink;
                break;
                goto menu_driven1;
            }
          }
          deduct_ptss=total1;
          deduct_pts=total1;
          Serial.print("You've to pay ");
          Serial.print(total1);
          Serial.println(" points");
          read_write_new_unp();
          if(check == 0)
    {
      Serial.println("TRANSACTION WAS UNSUCCESSFUL!");
      check = -1;
    }
    else{
      Serial.println("TRANSACTION MADE SUCCESSFULLY");
      delay(1000);
      Serial.println("REMOVE CARD");
      Serial.println();
      delay(3000);
    }
          break;
  }
}
