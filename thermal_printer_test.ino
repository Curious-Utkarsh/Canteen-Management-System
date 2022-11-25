#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"


#define TX_PIN A2 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN A3 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor
void setup() {
  mySerial.begin(9600);  // Initialize SoftwareSerial
  printer.begin();        // Init printer (same regardless of serial type)
  printer.justify('L');
  printer.println("***  MY ENGINEERING STUFFS  ***\n");
  printer.justify('C');
  printer.setSize('L');        // Set type size, accepts 'S', 'M', 'L'
  printer.println("TOKEN NUMBER");
  printer.boldOn();
  printer.setSize('L');
  printer.println("001\n");
  printer.boldOff();
  printer.justify('C');
  printer.setSize('S');
  printer.println("***  HAVE A NICE DAY  ***");
  printer.justify('C');
  printer.print("DATE:24/01/2018\t");
  printer.println("TIME: 00:07");
  printer.println("TODAY: WEDNESDAY");   
  printer.write(10);
  printer.write(10);
  printer.write(10);
}

void loop() {
}
