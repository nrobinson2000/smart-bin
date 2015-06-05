/* Main.ino
  This is the firmware for Smart Bin.  It detects whenever a new bottle, can, cup, or milk carton is
  placed into the bin.  There will be 5 different receptacles for each different drink container.


*/

#define GPIN D0   // <Drink container pins>
#define PPIN D1
#define CAPIN D2
#define CPIN D3
#define MPIN D4  // </Drink container pins>

int glassCount = 0;   // <Drink count variables>
int plasticCount = 0;
int canCount = 0;
int cupCount = 0;
int milkCount = 0;    // </Drink count variables>

int derpPin = D6;

void setup()
{
  Serial.begin(9600);

  pinMode(GPIN, INPUT);
  pinMode(PPIN, INPUT);
  pinMode(CAPIN, INPUT);
  pinMode(CPIN, INPUT);
  pinMode(MPIN, INPUT);

  Spark.variable("glass", &glassCount, INT);
  Spark.variable("plastic", &plasticCount, INT);
  Spark.variable("can", &canCount, INT);
  Spark.variable("cup", &cupCount, INT);
  Spark.variable("milk", &milkCount, INT);

  Spark.function("derp", derp);
  pinMode(derpPin, OUTPUT);
}

int derp(String data)
{
  if (data.compareTo("on") == 0)
  {
    digitalWrite(derpPin, HIGH);
    return 1;
  }
  else if (data.compareTo("off") == 0)
  {
    digitalWrite(derpPin, LOW);
    return 1;
  }

  else
  {
    return -1;
  }

}


void loop()
{
  if (digitalRead(GPIN) == HIGH)
    {
      delay(50);
      if (digitalRead(GPIN) == LOW)
      {  glassCount++;}
    }

    if (digitalRead(PPIN) == HIGH)
      {
        delay(50);
        if (digitalRead(PPIN) == LOW)
        {  plasticCount++;  }

      }

      if (digitalRead(CAPIN) == HIGH)
        {
          delay(50);
          if (digitalRead(CAPIN) == LOW)
          {  canCount++;}

        }

        if (digitalRead(CPIN) == HIGH)
          {
            delay(50);
            if (digitalRead(CPIN) == LOW)
            {cupCount++;}

          }

          if (digitalRead(MPIN) == HIGH)
            {
              delay(50);
              if (digitalRead(MPIN) == LOW)
              {milkCount++;}

            }



}
