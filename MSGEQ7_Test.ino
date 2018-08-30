// **********************************************************
//  MSGEQ7_Test.ino
//
//  The MSGEQ7 chip analyzes an audio signal and outputs the 
//  intensity of seven frequency ranges as analog values. 
//  However, the MSGEQ7 can only output one value at a time, 
//  so the Arduino must "strobe" the MSGEQ7 to read the 
//  intensities of all the seven frequency ranges.
//
//  The outputs are on an "on/off" basis: "on" when the
//  frequency range is loud enough to meet the "sensibility"
//  treshold, "off" when not loud enough. 
//
//  An easy improvement could be to output each frequency's 
//  intensity on a PWM basis, where the LED's turn brighter 
//  as the corresponding frequency range gets louder.
//
//  Connect the output of the MSGEQ7 to Arduino's analog pin
//  5. Wire up the MSGEQ7 as per its datasheet.
//   
//  Author: Michael Katilevsky
//
//  26 December 2015
//
// **********************************************************

const byte strobe = 12;       //digital pins  
const byte reset = 13;

const byte tStrobe = 20;   // Strobe duration in microseconds
const byte tSettle = 40;   // Output settling time in microseconds

// How powerful/loud the frequency range must be to trigger the output
int sensibility = 300; // value must be between 0 and 1023

void setup() 
{
  
  pinMode(strobe, OUTPUT);
  pinMode(reset, OUTPUT);

  for(byte a = 3; a < 10; a++) {
    pinMode(a, OUTPUT);
    digitalWrite(a, LOW);
  }

  // Initialize the chip
  digitalWrite(reset, LOW);
  digitalWrite(strobe, HIGH);
  
  delay(100);

  Serial.begin(9600);

}





void loop()
{
  // Declare an array to store the intensities of the seven frequency ranges
  int freq[7];
  
  digitalWrite(reset, HIGH);
  digitalWrite(reset, LOW);      
  
  for(byte b = 0; b < 7; b++)    // cycle through frequencies
  {
    digitalWrite(strobe, LOW);
    delayMicroseconds(tSettle);

    freq[b] = analogRead(5); // store the value

    digitalWrite(strobe, HIGH);
    delayMicroseconds(tStrobe);
  }

  // Output the frequencies' intensity
  for(byte b = 3; b < 10; b++)
  {
    if(freq[b-3] > sensibility)
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
