void menu(){
int total = 0;
int vadapav=15;
int misalpav=40;
int dosa=50;
int samosa=20;
int coldrink=20;
int fruitjuice=25;
int milkshake=30;
int choice1 = -1;
int choice2 = -1;
int choice3 = -1;
int quantity = 1;

Serial.println("Press 1 to order Food");
Serial.println(F("Press 3 to order Beverage"));
input();
choice1 = inp.toInt();
switch(choice1){
  case 1:{
  Serial.println(" 1 :- Vadapav = 15");
  Serial.println(" 3 :- MisalPav = 40");
  Serial.println(" 4 :- Dosa = 50");
  Serial.println(" 5 :- Samosa = 20");
  Serial.println("Make your selection: ");
  Serial.println("After making selection finally press A");
  Serial.println("to proceed with checkout");
  menu_food:{
    input();
    while(customKey != 'A'){
      choice2 = inp.toInt();
      switch(choice2){
        case 1:{
          Serial.println("Enter the quantity required: ");
          input();
          quantity=inp.toInt();
          Serial.print(quantity);
          Serial.println(" Vadapav added to cart");
          total+=(quantity*vadapav);
        }break;
        goto menu_food;
        case 3:{
          Serial.println("Enter the quantity required: ");
          input();
          quantity=inp.toInt();
          Serial.print(quantity);
          Serial.println(" Misalpav added to cart");
          total+=(quantity*misalpav);
        }break;
        goto menu_food;
        case 4:{
          Serial.println("Enter the quantity required: ");
          input();
          quantity=inp.toInt();
          Serial.print(quantity);
          Serial.println(" Dosa added to cart");
          total+=(quantity*dosa);
        }break;
        goto menu_food;
        case 5:{
          Serial.println("Enter the quantity required: ");
          input();
          quantity=inp.toInt();
          Serial.print(quantity);
          Serial.println(" Samosa added to cart");
          total+=(quantity*samosa);
        }break;
        goto menu_food;
      }
    }
  }
  Serial.print("You've to pay ");
  Serial.print(total);
  Serial.println("Elixir points");
  }break;
  case 3:{
  Serial.println(" 1 :- Cold drink = 20");
  Serial.println(" 3 :- Fruit Juice = 25");
  Serial.println(" 4 :- Milkshake = 30");
  Serial.println("Make your selection: ");
  Serial.println("After making selection finally press A");
  Serial.println("to proceed with checkout");
  menu_bev:{
    input();
    while(customKey != 'A'){
      choice3 = inp.toInt();
      switch(choice3){
        case 1:{
          Serial.println("Enter the quantity required: ");
          input();
          quantity=inp.toInt();
          Serial.print(quantity);
          Serial.println(" Cold drink added to cart");
          total+=(quantity*coldrink);
        }break;
        goto menu_bev;
        case 3:{
          Serial.println("Enter the quantity required: ");
          input();
          quantity=inp.toInt();
          Serial.print(quantity);
          Serial.println(" Fruit Juice added to cart");
          total+=(quantity*fruitjuice);
        }break;
        goto menu_bev;
        case 4:{
          Serial.println("Enter the quantity required: ");
          input();
          quantity=inp.toInt();
          Serial.print(quantity);
          Serial.println(" Milk shake added to cart");
          total+=(quantity*milkshake);
        }break;
        goto menu_bev;
      }
    }
  }
  }break;
}
}
