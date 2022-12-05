void choose_menu()
{
  if(menu_entry_list[destination_state.position].name == "Coffee/Tea")
  {
    coffee_tea();
  }
  if(menu_entry_list[destination_state.position].name == "Snacks")
  {
    //snacks();
  }
  if(menu_entry_list[destination_state.position].name == "Drinks")
  {
    //drinks();
  }
  if(menu_entry_list[destination_state.position].name == "Ice-Cream")
  {
    //ice();
  }
  if(menu_entry_list[destination_state.position].name == "Thali")
  {
    //thali();
  }
}
