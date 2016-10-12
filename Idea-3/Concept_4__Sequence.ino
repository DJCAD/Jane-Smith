int spd=270;      //Chane sanning speed.
void setup()
{
  for (int outpin =7;outpin < 14; outpin++) // spin 7-13 as output
{
  pinMode(outpin,OUTPUT);
}
}
void loop()
{
for(int strobe = 7; strobe < 13; strobe++) //turn on and off pins 7-12
{
  digitalWrite(strobe,HIGH);
  delay(spd);
  digitalWrite(strobe,LOW);
}
for(int strobe = 13;strobe > 7;strobe--) //turn on and off pins 13 to 8
{
  digitalWrite(strobe,HIGH);
  delay(spd);
  digitalWrite(strobe,LOW);
}
}

