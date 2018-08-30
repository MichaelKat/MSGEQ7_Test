
// **********************************************************
//   MSGEQ7_Test.ino
//
//   
//   
//   Author: Michael Katilevsky
//
//   26 December 2015
//
// **********************************************************

const byte Strobe = 12;       //digital pins  
const byte Reset = 13;

int Freq[7];        // MSGEQ7 value 

const byte TStrobe = 20;   // Strobe duration in microseconds
const byte TSettle = 40;   // Output settling time in microseconds

byte b;

int Sensability = 300;

void setup() 
{
  
  pinMode(Strobe, OUTPUT);
  pinMode(Reset, OUTPUT);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  


  digitalWrite(Reset, LOW);
  digitalWrite(Strobe, HIGH);
  
  delay(100);

  Serial.begin(9600);

}





void loop()
{
    
  digitalWrite(Reset, HIGH);
  digitalWrite(Reset, LOW);      
  
  for(b = 0; b < 7; b++)    // cycle through frequencies
  {
    digitalWrite(Strobe, LOW);
    delayMicroseconds(TSettle);

    Freq[b] = analogRead(5);

    digitalWrite(Strobe, HIGH);
    delayMicroseconds(TStrobe);
  }

  for(b = 3; b < 10; b++)
  {
    if(Freq[b-3] > Sensability)
    {
      digitalWrite(b, HIGH);
      Serial.print(" ");
      Serial.print("YES");
    }
    else
    {
      digitalWrite(b, LOW);
      Serial.print(" ");
      Serial.print("---");
    }
  }

  Serial.println();
  
}
