void printBill()
{
  printer.begin(); 
  printer.boldOn();
  printer.setSize('S');
  printer.justify('C');
  printer.println(F("COSMOS CATERING SERVICES LLP")); 
  printer.boldOff();
  printer.setSize('S');
  printer.justify('C');     
  printer.println(F("SOMAIYA VIDYAVIHAR"));      
  printer.println(F("GSTIN-27AA0FC3926H129\n"));  
  printer.boldOn(); 
  printer.setSize('S');
  printer.justify('C');   
  //printer.println(" BILL NO: 40084  "+date+"  "+Time+"\n");
  printer.println(F("- - - - - - - - - - - - - - -"));
  printer.boldOff();
  printer.justify('C');
  printer.setSize('S');
  printer.println(F(" ITEM      QTY   PRICE    AMOUNT"));
  printer.boldOn();
  printer.justify('C');
  printer.setSize('S');
  printer.println(F("- - - - - - - - - - - - - - -"));
  printer.boldOff();
  printer.justify('L');
  for(byte i = 0; i<=cnt; i++)
  {
    printer.justify('L');
    printer.setSize('S');
    printer.print(" "+items[i]+"     ");
    printer.justify('R');
    if((amounts[i]).length() <= 4)
    printer.println(qtys[i]+"     "+prices[i]+"     "+amounts[i]+" ");
    else
    printer.println(qtys[i]+"     "+prices[i]+"     "+amounts[i]);
    printer.println();
  }
  printer.boldOn();
  printer.justify('C');
  printer.setSize('S');
  printer.println(F("- - - - - - - - - - - - - - -"));
  printer.boldOff();
  printer.println(F("INCLUSIVE OF ALL TAXES"));
  printer.boldOn();
  printer.println(F("- - - - - - - - - - - - - - -\n"));
  printer.justify('L');
  printer.println(" GRAND TOTAL :         Rs. "+gTotal+"\n");
  printer.boldOff();
  printer.justify('C');
  printer.setSize('S');
  printer.println("***  HAVE A NICE DAY  ***");
  printer.justify('C');
  printer.print("DATE:"+date+"\t");
  printer.println("TIME:"+Time);
  printer.println("TODAY:"+today); 
  printer.print("\n");
  printer.println("-- POWERED BY : ENGINEERS --");
  printer.println(F("\n"));
  printer.write(10);
  printer.write(10);
  printer.write(10);
}
