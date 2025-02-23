// Declare Variables
int sensor1Pin = A0;
int sensor2Pin = A1; 
int sensor3Pin = A2; 
int sensor4Pin = A3; 
int sensor5Pin = A4;
int blue = 5;
int yellow = 6;  
int fetPin = 3;
float res1;
float res2;
float res3;
float res4;
float res5;
float temp1;
float temp2;
float temp3;
float temp4;
float temp5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(fetPin, OUTPUT);
}

void loop() {
  // Get temp from each sensor
  int reading1 = analogRead(sensor1Pin);
  res1 = (1023.0 / (float)reading1 - 1) * 100000; // Calculate the resistance
  temp1 = 1 / (log(res1 / 100000) / 3950 + 1 / 298.15) - 273.15; // Calculate the temperature (celsius)

  int reading2 = analogRead(sensor2Pin);
  res2 = (1023.0 / (float)reading2 - 1) * 100000; // Calculate the resistance
  temp2 = 1 / (log(res2 / 100000) / 3950 + 1 / 298.15) - 273.15; // Calculate the temperature (celsius)

  int reading3 = analogRead(sensor3Pin);
  res3 = (1023.0 / (float)reading3 - 1) * 100000; // Calculate the resistance
  temp3 = 1 / (log(res3 / 100000) / 3950 + 1 / 298.15) - 273.15; // Calculate the temperature (celsius)

  int reading4 = analogRead(sensor4Pin);
  res4 = (1023.0 / (float)reading4 - 1) * 100000; // Calculate the resistance
  temp4 = 1 / (log(res4 / 100000) / 3950 + 1 / 298.15) - 273.15; // Calculate the temperature (celsius)

  int reading5 = analogRead(sensor5Pin);
  res5 = (1023.0 / (float)reading5 - 1) * 100000; // Calculate the resistance
  temp5 = 1 / (log(res5 / 100000) / 3950 + 1 / 298.15) - 273.15; // Calculate the temperature (celsius)

  // Check if any readings are below 29 and 23 degrees celsius. If yes, start heating pad
    if(temp1 <= 23 || temp2 <= 23 || temp3 <= 23 || temp4 <= 23 || temp5 <= 23)
    {
      digitalWrite(yellow, HIGH);
      digitalWrite(blue, HIGH);
      analogWrite(fetPin, 213);
    }
    else if(temp1 <= 29 || temp2 <= 29 || temp3 <= 29 || temp4 <= 29 || temp5 <= 29)
    {
      digitalWrite(yellow, HIGH);
      digitalWrite(blue, LOW);
      analogWrite(fetPin, 157);
    }
    else
    {
      digitalWrite(yellow, LOW);
      digitalWrite(blue, LOW);
      analogWrite(fetPin, 0);
    }
  delay(1000);
}
