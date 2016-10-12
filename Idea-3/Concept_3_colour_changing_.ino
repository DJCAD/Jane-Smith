/* Changes colours of an RGB LED based on potentiometer
  Created: Ravi Kanth Kosuru
  Date: 28/12/2013 */

int rPin = 13;
int gPin = 12;
int bPin = 8;
int switchCase = 0;
int pot = A0;
int gButton = 7;
int bButton = 2;
char rVal, gVal, bVal;
void setup()

{

  pinMode(rPin, OUTPUT);

  pinMode(gPin, OUTPUT);

  pinMode(bPin, OUTPUT);

  pinMode(pot, INPUT_PULLUP);

  pinMode(gButton, INPUT_PULLUP);

  pinMode(bButton, INPUT_PULLUP);

  Serial.begin(9600);
}



void loop()

{
  //Divide Potentiometer Values by 4 to get a smaller range
  int potValue = analogRead(pot) / 4;
  Serial.println(potValue);
  //Starts with Blue for values below 100 and Red for values above 15
  // Could be used to map optimum settings with
  //Green between 115 - 145. Values before and after Green zones change colour
  //to show boundary condtions for optimum values
  if (potValue > 0 && potValue < 100) {
    switchCase = 0;
  }
  else if (potValue >= 100 && potValue < 115) {
    switchCase = 1;
  }
  else if (potValue >= 115 && potValue < 135) {
    switchCase = 2;
  }
  else if (potValue >= 135 && potValue < 150) {
    switchCase = 1;
  }
  else {
    switchCase = 4;
  }

  switch (switchCase) {
    case 0:
      setColour(HIGH, HIGH, LOW);
      break;
    case 1:
      setColour(LOW, LOW, LOW);
      break;
    case 2:
      setColour(HIGH, LOW, HIGH);
      break;
    case 4:
      setColour(LOW, HIGH, HIGH);
      break;
  }

}


void setColour(char red, char green, char blue)
{

  digitalWrite(rPin, red);

  digitalWrite(gPin, green);

  digitalWrite(bPin, blue);

}
//Code ends here
