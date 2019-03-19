//LED Pins
int ledPins[] = {5, 6, 7, 8, 9, 10, 11, 12};

/*
Params:
  power - turn Light On or Off
*/
void turnMachineOnOrOff(boolean power){
  if(power)
  {
    pinMode(ledPins[4], HIGH);
  }else
  {
    turnEverythingOff();
  }
  delay(800);
}

void turnEverythingOff(){
  for(int i=0; i<sizeof(ledPins); i++)
  {
    pinMode(ledPins[i], LOW);
  }    
}

void takeTheWater(){
  pinMode(ledPins[5], HIGH);
  delay(5000);
  pinMode(ledPins[5], LOW);
  delay(800);
}

void heatTheWater(){
  pinMode(ledPins[7], HIGH);
  delay(5000);
  pinMode(ledPins[7], LOW);
  delay(800);
}

void dropTheWater(){
  pinMode(ledPins[6], HIGH);
  delay(5000);
  pinMode(ledPins[6], LOW);
  delay(800);
}

/*
Params:
  numberOfSpins - how many spins drum will make
  speedOfDrum - delay between lights blinking
*/
void spinTheDrum(int numberOfSpins, int speedOfDrum){
  if(speedOfDrum < 100){
    centrifuga(numberOfSpins, speedOfDrum);
  }
  else
  {
    spinClockWise(numberOfSpins, speedOfDrum);
    delay(500);
    spinCounterClockWise(numberOfSpins, speedOfDrum);
  }
}

void spinClockWise(int numberOfSpins, int speedOfDrum){
  for(int i=0; i<numberOfSpins; i++)
  {
    for(int i=0; i<4; i++)
      {
        pinMode(ledPins[i], LOW);
        delay(speedOfDrum);
      }
      for(int i=0; i<4; i++)
      {
        pinMode(ledPins[i], HIGH);
        delay(speedOfDrum);
      }
  }
}

void spinCounterClockWise(int numberOfSpins, int speedOfDrum){
  for(int i=0; i<numberOfSpins; i++)
  {
    for(int i=3; i>=0; i--)
    {
        pinMode(ledPins[i], LOW);
        delay(speedOfDrum);
    }
    for(int i=3; i>=0; i--)
    {
        pinMode(ledPins[i], HIGH);
        delay(speedOfDrum);
    }
  }
}

void centrifuga(int numberOfSpins, int speedOfDrum){
  pinMode(ledPins[0], HIGH);
  delay(speedOfDrum);
  pinMode(ledPins[1], HIGH);
  for(int i=0; i<numberOfSpins; i++)
  {
      
        pinMode(ledPins[2], HIGH);
        pinMode(ledPins[0], LOW);
        delay(speedOfDrum);
        pinMode(ledPins[3], HIGH);
        pinMode(ledPins[1], LOW);
        delay(speedOfDrum);
        pinMode(ledPins[0], HIGH);
        pinMode(ledPins[2], LOW);
        delay(speedOfDrum);
        pinMode(ledPins[1], HIGH);
        pinMode(ledPins[3], LOW);
        delay(speedOfDrum);
  }
  pinMode(ledPins[0], LOW);
  delay(speedOfDrum);
  pinMode(ledPins[1], LOW);
}

void setup() {

  turnMachineOnOrOff(true);
  takeTheWater();
  spinTheDrum(3, 200);
  heatTheWater();
  spinTheDrum(3, 200);
  dropTheWater();
  takeTheWater();
  spinTheDrum(20, 70);
  dropTheWater();
  turnMachineOnOrOff(false);

}

void loop() {
  // put your main code here, to run repeatedly:

}
