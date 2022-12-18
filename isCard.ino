void isCard()
{
  while(true)
  {
    if ( ! mfrc522.PICC_IsNewCardPresent()) 
    {
      continue;
    }
    break;
    if ( ! mfrc522.PICC_ReadCardSerial()) 
    {
      return;
    }
  }
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}
