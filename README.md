# RFID Canteen Payment System — Arduino, ESP32, GSM, Thermal Printer

[![Arduino](https://img.shields.io/badge/MCU-Arduino%20%7C%20ESP32-00979D?logo=arduino)](https://www.arduino.cc/)
[![RFID](https://img.shields.io/badge/RFID-MFRC522-555)](#how-it-works)

My college canteen had such weak mobile signal that digital payments kept failing and a queue formed just to pay. This system moves payment onto the student's college ID card: recharge once at a station, then tap the card to order. Payment no longer depends on the network, and the queue went down noticeably. Built in my second year (Nov–Dec 2022) with classmates Nimish Tiwari and Piyush.

## Demo

[![NFC-based smart ordering system](https://img.youtube.com/vi/iQ-vjzbL71g/hqdefault.jpg)](https://youtu.be/iQ-vjzbL71g)

<sub>The later Q'Less Pro kiosk — see [Q-Less_Final_Code](https://github.com/Curious-Utkarsh/Q-Less_Final_Code)</sub>

## How it works

1. **Recharge station** — the student pays by UPI; a SIM800 GSM module receives the payment confirmation; the MFRC522 reader tops up the card; an LCD shows the balance.
2. **Ordering kiosk** — browse the menu with a joystick, see the total, tap the card; the balance is deducted on the card.
3. **Billing and logging** — an ESP32 prints the bill on a thermal printer, logs transactions to Google Sheets and sends SMS updates.
4. Card data is stored encrypted so the balance cannot be edited by hand.

## Folders

| Folder / file | Role |
|---|---|
| `RFID_INTERFACE/` | Kiosk menu (joystick, categories, quantity, checkout) |
| `RFID_MONEY_TRANSACTION/`, `main/` | Card read/write and balance logic |
| `ESP_with_PRINTER___SERVER_update_FINAL.ino`, `Data_Test/` | ESP32 print server and bill format |
| `ESP32_GOOGLE_SPREADSHEET.ino`, `RecvSMS.ino` | Transaction logging and SMS |
| `Libraries Needed/` | LiquidCrystal_I2C library used |

Wi-Fi credentials go in the sketches before flashing.

## Related

[Q'Less Pro kiosk](https://github.com/Curious-Utkarsh/Q-Less_Final_Code) · [Spencer Pro 370 pill dispenser](https://github.com/Curious-Utkarsh/Pill-Dispenser)

---
[Kumar Utkarsh](https://github.com/Curious-Utkarsh) · [LinkedIn](https://www.linkedin.com/in/kumar-utkarsh-124aab227/) · [Portfolio of builds](https://www.mechamindlabs.com/projects)
