void choose_menu()
{
  if(menu_entry_list[destination_state.position].name == "Coffee/Tea")
  {
    count = 3;
    coffee_tea();
  }
  if(menu_entry_list[destination_state.position].name == "Snacks")
  {
    count = 5;
    snacks();
  }
  if(menu_entry_list[destination_state.position].name == "Drinks")
  {
    count = 3;
    drinks();
  }
  if(menu_entry_list[destination_state.position].name == "Ice-Cream")
  {
    count = 3;
    ice();
  }
  if(menu_entry_list[destination_state.position].name == "Maggi")
  {
    count = 3;
    maggi();
  }
}
