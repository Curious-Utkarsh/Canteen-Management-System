void printBill()
{
  printer.begin();
  printer.justify('C');
  printer.println("***   WELCOME TO COSMOS   ***");
  printer.justify('C');
  printer.setSize('S');        // Set type size, accepts 'S', 'M', 'L'
  printer.println("_______________\n");
  printer.boldOn();
  printer.justify('L');
  printer.setSize('S');
  printer.println(" QTY   ORDER\t\t PRICE");
  printer.println();
  printer.print("  "+qty+"    "+order+"\t\t "+price);
  printer.println("\n");
  printer.boldOff();
  printer.print("\n");
  printer.justify('C');
  printer.setSize('S');
  printer.println("***  HAVE A NICE DAY  ***");
  printer.justify('C');
  printer.print("DATE:"+date+"\t");
  printer.println("TIME:"+Time);
  printer.println("TODAY:"+today); 
  printer.print("\n");
  printer.print("-- POWERED BY : ENGINEERS --");
  printer.println("\n");  
  printer.println();
  printer.write(10);
  printer.write(10);
  printer.write(10);
}
