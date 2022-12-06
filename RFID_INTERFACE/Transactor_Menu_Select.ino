#include <U8g2lib.h>
#include <SPI.h>

U8G2_ST7920_128X64_F_HW_SPI u8g2(U8G2_R0, /* CS=*/ 10, /* reset=*/ 8);

#define xPin A0
#define yPin A1
#define sPin 5

unsigned int xVal = 0;
unsigned int yVal = 0;
bool sVal = LOW;

byte check = 0;
char button = ' ';
byte rst = 0;

byte flag = 0;
byte xCnt = 1;
byte k = 0;

byte count;
#define yPos 16
#define xPos 3
#define dt 200

byte cnt = 1;
byte slq = 0;

String f[3];
byte p[3];
byte q[3];
byte y = 0;

void setup() 
{
  u8g2.begin(); 
  u8g2.setFont(u8g2_font_6x12_tr);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  digitalWrite(sPin, HIGH);
}

struct menu_entry_type
{
  const uint8_t *font;
  uint16_t icon;
  const char *name;
};

struct menu_state
{
  int16_t menu_start;  
  int16_t frame_position;   
  uint8_t position;   
};

#define ICON_WIDTH 21
#define ICON_HEIGHT 21
#define ICON_GAP 4
#define ICON_BGAP 6
#define ICON_Y 25+ ICON_GAP

struct menu_entry_type menu_entry_list[] =
{
  { u8g2_font_streamline_food_drink_t, 50, "Coffee/Tea"},
  { u8g2_font_streamline_food_drink_t, 62, "Snacks"},
  { u8g2_font_streamline_food_drink_t, 49, "Drinks"},
  { u8g2_font_streamline_food_drink_t, 56, "Ice-Cream"},
  { u8g2_font_streamline_health_beauty_t, 54, "Thali"},
  { NULL, 0, NULL } 
};

int8_t button_event = 0;    

struct menu_state current_state = { ICON_BGAP, ICON_BGAP, 0 };
struct menu_state destination_state = { ICON_BGAP, ICON_BGAP, 0 };

void loop() 
{
  do
  {
    u8g2.firstPage();
    do
    {
      draw(&current_state);  
      u8g2.setFont(u8g2_font_helvB10_tr);  
      u8g2.setCursor((u8g2.getDisplayWidth()-u8g2.getStrWidth(menu_entry_list[destination_state.position].name))/2,u8g2.getDisplayHeight()-5);
      u8g2.print(menu_entry_list[destination_state.position].name);
      check_button_event();
      delay(10);
    } 
    while( u8g2.nextPage() );
    
    if ( button_event == U8X8_MSG_GPIO_MENU_NEXT )
    {
      to_right(&destination_state);
      check = 1;
      button_event = 0;
      button = ' ';
    }
    if ( button_event == U8X8_MSG_GPIO_MENU_PREV )
    {
      to_left(&destination_state);
      check = 1;
      button_event = 0;
      button = ' ';
    }
    if ( button_event == U8X8_MSG_GPIO_MENU_SELECT )
    { 
      check = 1;
      button = ' ';
      delay(dt);
      button_event = 0;
      choose_menu();
    }
    
  } 
  while ( towards(&current_state, &destination_state) );
}
