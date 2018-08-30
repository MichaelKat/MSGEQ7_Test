# MSGEQ7_Test
A simple sketch for an Arduino to communicate with an MSGEQ7 chip.

The MSGEQ7 chip analyzes an audio signal and outputs the intensity of seven frequency ranges as analog values.
However, the MSGEQ7 can only output one value at a time, so the Arduino must "strobe" the MSGEQ7 to read the 
intensities of all the seven frequency ranges.

In this program, I've decided to output said intensities through the Arduino's Serial interface and through the 
Arduino's GPIO pins. Connect the Arduino to your computer or insert the positive leads of LED's to Arduino's pins 
3 through 9 and watch the MSGEQ7 do its job!
