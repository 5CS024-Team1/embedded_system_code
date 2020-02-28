// I NEED TO ADD THE FUNCTION THAT IS GOING TO ALLOW THE DATA FROM THE SERIAL MONITOR TO BE EXPORTED TO A CSV FILE.
// I NEED TO BUILD THE HARDWARE THAT WILL SUPPORT THIS SOFTWARE.​
// I NEED TO ADD SOME MORE FORMATTING THAT IS GOING TO ALLOW ME TO SEE THE TIME, DATE AND ADD AN ID TO THE ARDUINO I AM USING (FOR THE DATABASE).​
​
​
//Libraries needed - TinyGPS allows you to format the data from the GPS module into something that can be easily understood ​
//& SoftwareSerial to enable serial communcation on digital pins for the arduino ​
#include <TinyGPS++.h>​
#include <SoftwareSerial.h>​
​
//Telling the arduino what pins we are using so it can communicate with the GPS module.​
static const int RXPin = 4, TXPin = 3;​
//Setting the baud rate - This is the rate that information will be transferred from the GPS to the arduino.​
static const uint32_t GPSBaud = 9600;​
​
//Creating the GPS object​
TinyGPSPlus gps;​
​
//Establishing a connection to the GPS device​
SoftwareSerial ss(RXPin, TXPin);​
​
//General setting up​
void setup(){​
  Serial.begin(9600);​
  ss.begin(GPSBaud);​
}​
​
//This is the loop that is going to format the data, it is essentailly saying:​
// While there is information to be transferred, read the information from the GPS module, ​
//if the GPS location is updated, print the word latitide and the latitude to 6 decimal places, then do the same for the longitude. ​
void format(){​
  // This sketch displays information every time a new sentence is correctly encoded.​
  // While there is data available for transfer​
  while (ss.available() > 0){​
  // Read the data on the GPS module​
    gps.encode(ss.read());​
  // If the location on the GPS module is updated​
    if (gps.location.isUpdated()){​
      //This may work, the decinal place of the time needs to be updated, I will do this once I have the code working with the actual gps module and I can see how many characters are in the time aspect of the data.​
      //Serial.print(" Time= "); ​
      //Serial.println(gps.location.time(), 6);​
      //These ones do work​
      //Print the word Latitude ​
      Serial.print("Latitude= "); ​
      //Print the actual Latitide to 6 decimal places​
      Serial.print(gps.location.lat(), 6);​
      //Print the word Longitude​
      Serial.print(" Longitude= "); ​
      //Print the actual Longitude to 6 decimal places​
      Serial.println(gps.location.lng(), 6);​
    }​
  }​
}
