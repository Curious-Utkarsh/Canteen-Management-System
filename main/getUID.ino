void getUID() 
{

  content= "";
  byte letter;
  //  Serial.println((char *)mfrc522.uid.uidByte);
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
      //     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      //     Serial.print(mfrc522.uid.uidByte[i], HEX);
      content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  
}
