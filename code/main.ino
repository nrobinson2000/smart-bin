/* Main.ino
  This is the firmware for Smart Bin.  It detects whenever a new bottle, can, cup, or milk carton is
  placed into the bin.  There will be 5 different receptacles for each different drink container.


*/

#define GPIN D0   // <Drink container pins>
#define PPIN D1
#define CAPIN D2
#define CPIN D3
#define MPIN D4  // </Drink container pins>
#define MODEPIN D6

int glassCount = 0;   // <Drink count variables>
int plasticCount = 0;
int canCount = 0;
int cupCount = 0;
int milkCount = 0;    // </Drink count variables>

void setup()
{
  Serial.begin(9600);

  pinMode(GPIN, INPUT);
  pinMode(PPIN, INPUT);
  pinMode(CAPIN, INPUT);
  pinMode(CPIN, INPUT);
  pinMode(MPIN, INPUT);
  pinMode(MODEPIN, INPUT);

  Spark.variable("glass", &glassCount, INT);
  Spark.variable("plastic", &plasticCount, INT);
  Spark.variable("can", &canCount, INT);
  Spark.variable("cup", &cupCount, INT);
  Spark.variable("milk", &milkCount, INT);

}

void loop()
{

  if (digitalRead(GPIN) == HIGH)
    {
      delay(150);
      if (digitalRead(MODEPIN) == HIGH)
      {
        glassCount++;
      }
      else
      {
        if (glassCount > 0)
        {
        glassCount--;
        }
        else
        {
          return;
        }
      }
    Serial.println("Glass pushed!   "+String(glassCount));
    }

    if (digitalRead(PPIN) == HIGH)
      {
        delay(150);
        if (digitalRead(MODEPIN) == HIGH)
        {
          plasticCount++;
        }
        else
        {
          if (plasticCount > 0)
          {
          plasticCount--;
          }
          else
          {
            return;
          }
        }
        Serial.println("Plastic pushed!   "+String(plasticCount));
      }

      if (digitalRead(CAPIN) == HIGH)
        {
          delay(150);
          if (digitalRead(MODEPIN) == HIGH)
          {
            canCount++;
          }
          else
          {
            if (canCount > 0)
            {
            canCount--;
            }
            else
            {
              return;
            }
          }
          Serial.println("Can pushed!   "+String(canCount));
        }

        if (digitalRead(CPIN) == HIGH)
          {
            delay(150);
            if (digitalRead(MODEPIN) == HIGH)
            {
              cupCount++;
            }
            else
            {
              if (cupCount > 0)
              {
              cupCount--;
              }
              else
              {
                return;
              }
            }
            Serial.println("Cup pushed!  "+String(cupCount));
          }

          if (digitalRead(MPIN) == HIGH)
            {
              delay(150);
              if (digitalRead(MODEPIN) == HIGH)
              {
                milkCount++;
              }
              else
              {
                if (milkCount > 0)
                {
                milkCount--;
                }
                else
                {
                  return;
                }
              }
              Serial.println("Milk pushed!   "+String(milkCount));
            }

}
