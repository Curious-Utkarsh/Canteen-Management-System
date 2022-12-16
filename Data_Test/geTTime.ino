void geTTime()
{
  timeClient.update();
  Serial.println();
  formattedTime = timeClient.getFormattedTime();

  hh = String(timeClient.getHours());
  mn = String(timeClient.getMinutes());

  Time = (hh+":"+mn);
  Serial.println("TIME : "+Time);

  int day = timeClient.getDay();
  today = daysWeek[day];
  Serial.println("TODAY : "+today);

  date_time = timeClient.getFormattedDate();

  int index_date = date_time.indexOf("T");
  dd = date_time.substring(8, index_date);
  mm = date_time.substring(5, index_date-3);
  yyyy = date_time.substring(0, index_date-6);

  date = (dd+"/"+mm+"/"+yyyy);
  Serial.println("DATE : "+date);
}
