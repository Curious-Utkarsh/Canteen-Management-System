void menu() {
  //delay(3000);
  int total = 0;
  int menu_deduct_pts = 0;
  int vadapav = 15;
  int misalpav = 40;
  int dosa = 50;
  int samosa = 20;
  int coldrink = 20;
  int fruitjuice = 25;
  int milkshake = 30;
  int food_or_bev_choice = -1;
  int food_select = -1;
  int bev_select = -1;
  int quantity = 1;

  Serial.setTimeout(20000L);
  Serial.println("Press 1 to order Food");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press 1-Food");
  lcd.setCursor(0, 1);
  lcd.print("Press 3-Beverage");
  Serial.println(F("Press 3 to order Beverage"));
  input();
  food_or_bev_choice = inp.toInt();

  switch (food_or_bev_choice) {

    case 1: {
menu_food: {
          Serial.println("**********************");
          Serial.println("*Food Menu:          *");
          Serial.println("* 1 :- Vadapav = 15  *");
          Serial.println("* 3 :- MisalPav = 40 *");
          Serial.println("* 4 :- Samosa = 20   *");
          Serial.println("* 5 :- Dosa = 50     *");
          Serial.println("**********************");
          Serial.setTimeout(20000L);
          Serial.println(("Make your selection: "));
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Make selection");
          lcd.setCursor(0, 1);
          lcd.print("Press 0 to checkout");
          Serial.print(F("After making selection finally press 0 to proceed with checkout"));

          input();
          food_select = inp.toInt();
          Serial.print("Your selection: ");
          Serial.println(food_select);

          // while(choice2 != 0){
          if (food_select != 0) {
            switch (food_select) {

              case 1: {
                  Serial.println("You have selected vadapav");
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("You have selected vadapav");
                  Serial.setTimeout(20000L);
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("Enter quantity: ");
                  Serial.println(F("Enter the quantity required: "));
                  Serial.println();
                  input();
                  quantity = inp.toInt();
                  Serial.print("Quantity: ");
                  lcd.setCursor(0,1);
                  lcd.print(quantity);
                  Serial.println(quantity);
                  Serial.println();
                  Serial.print(quantity);
                  Serial.println(" Vadapav added to cart");
                  total += (quantity * vadapav);
                  delay(1000);
                  goto menu_food;
                } break;


              case 3: {
                  Serial.println("You have selected Misal Pav");
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("You have selected misal pav");
                  Serial.setTimeout(20000L);
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("Enter quantity: ");
                  Serial.println(F("Enter the quantity required: "));
                  Serial.println();
                  input();
                  quantity = inp.toInt();
                  Serial.print("Quantity: ");
                  lcd.setCursor(0,1);
                  lcd.print(quantity);
                  Serial.println(quantity);
                  Serial.println();
                  Serial.print(quantity);
                  Serial.println(" Misal Pav added to cart");
                  total += (quantity * misalpav);
                  delay(1000);
                  goto menu_food;
                } break;

              case 4: {
                  Serial.println("You have selected Samosa");
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("You have selected Samosa");
                  Serial.setTimeout(20000L);
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("Enter quantity: ");
                  Serial.println(F("Enter the quantity required: "));
                  Serial.println();
                  input();
                  quantity = inp.toInt();
                  Serial.print("Quantity: ");
                  lcd.setCursor(0,1);
                  lcd.print(quantity);
                  Serial.println(quantity);
                  Serial.println();
                  Serial.print(quantity);
                  Serial.println("Samosa added to cart");
                  total += (quantity * samosa);
                  delay(1000);
                  goto menu_food;
                } break;


              case 5: {
                  Serial.println("You have selected Dosa");
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("You have selected dosa");
                  Serial.setTimeout(20000L);
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("Enter quantity: ");
                  Serial.println(F("Enter the quantity required: "));
                  Serial.println();
                  input();
                  quantity = inp.toInt();
                  Serial.print("Quantity: ");
                  lcd.setCursor(0,1);
                  lcd.print(quantity);
                  Serial.println(quantity);
                  Serial.println();
                  Serial.print(quantity);
                  Serial.println(" Vadapav added to cart");
                  total += (quantity * dosa);
                  delay(1000);
                  goto menu_food;
                } break;


            }
          }
          else {
            menu_deduct_pts = total;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Pay ");
            lcd.print(total);
            lcd.print("Elx points");
            Serial.print("You have to pay ");
            Serial.print(total);
            Serial.println(" Elixir points");
          }
          //    }
        }
      } break;


    case 3: {
bev_menu: {
          Serial.println("*************************");
          Serial.println("*Beverage Menu:         *");
          Serial.println("* 1 :- Cold drink = 20  *");
          Serial.println("* 3 :- Fruit Juice = 25 *");
          Serial.println("* 4 :- Milkshake = 30   *");
          Serial.println("*************************");
          Serial.setTimeout(20000L);
          Serial.println("Make your selection: ");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Make selection");
          lcd.setCursor(0, 1);
          lcd.print("Press 0 to checkout");
          Serial.print(F("After making selection finally press 0 to proceed with checkout"));

          input();
          bev_select = inp.toInt();
          Serial.print("Your selection: ");
          Serial.println(bev_select);

          // while(choice2 != 0){
          if (bev_select != 0) {
            switch (bev_select) {

              case 1: {
                  Serial.println("You have selected Cold Drink");
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("You have selected coldrink");
                  Serial.setTimeout(20000L);
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("Enter quantity: ");
                  Serial.println(F("Enter the quantity required: "));
                  Serial.println();
                  input();
                  quantity = inp.toInt();
                  Serial.print("Quantity: ");
                  lcd.setCursor(0,1);
                  lcd.print(quantity);
                  Serial.println(quantity);
                  Serial.println();
                  Serial.print(quantity);
                  Serial.println(" Cold Drink added to cart");
                  total += (quantity * coldrink);
                  delay(1000);
                  goto bev_menu;
                } break;

              case 3: {
                  Serial.println("You have selected Fruit Juice");
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("You have selected fruitjuice");
                  Serial.setTimeout(20000L);
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("Enter quantity: ");
                  Serial.println(F("Enter the quantity required: "));
                  Serial.println();
                  input();
                  quantity = inp.toInt();
                  Serial.print("Quantity: ");
                  lcd.setCursor(0,1);
                  lcd.print(quantity);
                  Serial.println(quantity);
                  Serial.println();
                  Serial.print(quantity);
                  Serial.println(" Fruit juice added to cart");
                  total += (quantity * fruitjuice);
                  delay(1000);
                  goto bev_menu;
                } break;

              case 4: {
                  Serial.println("You have selected Milk shake");
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("You have selected milkshake");
                  Serial.setTimeout(20000L);
                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("Enter quantity: ");
                  Serial.println(F("Enter the quantity required: "));
                  Serial.println();
                  input();
                  quantity = inp.toInt();
                  Serial.print("Quantity: ");
                  lcd.setCursor(0,1);
                  lcd.print(quantity);
                  Serial.println(quantity);
                  Serial.println();
                  Serial.print(quantity);
                  Serial.println(" Milk shake added to cart");
                  total += (quantity * milkshake);
                  delay(1000);
                  goto bev_menu;
                } break;

            }
          }
          else {
            menu_deduct_pts = total;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Pay ");
            lcd.print(total);
            lcd.print("Elx points");
            Serial.print("You have to pay ");
            Serial.print(total);
            Serial.println(" Elixir points");
          }
        }
      } break;
  }
}
