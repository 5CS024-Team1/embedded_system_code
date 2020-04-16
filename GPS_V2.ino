//GPSTRACKER.v2
//ABIGAIL COULSON
//1827159
//GROUP 01

//Software serial is the library used to allow serial communication from digital pins on the arduino, 
//TinyGPS is the library we are using to format the data collected from the tracker.
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

//Establishing the SoftwareSerial pins
int RX = 3;
int TX = 4;

//Variable to set the baud rate, baud rate is the rate at which information is transferred (9600 bits per second)
int BR = 9600;

//Creating the GPS object
TinyGPSPlus gps;

//Creating the software serial object
SoftwareSerial SoftSer(RX, TX);

void setup()
{
  //Start the arduino up
  Serial.begin(9600);

  // Start up the software serial port
  SoftSer.begin(BR);
}

//*****************************************************************************************************************************************

void loop()
{
  //While there is information available through the software serial.
  while (SoftSer.available() > 0)
  //Read the information... THEN GO TO THE FORMATTING LOOP TO PROCESS THE INFORMATION INTO DATA
    if (gps.encode(SoftSer.read()))
      //FIND THIS FORMAT LOOP BELOW
      format();

  // If 5000 milliseconds pass and there are no characters coming in
  // over the software serial port, show a "No GPS detected" error
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println("No GPS detected");
    //while(true);
    delay(30000);
  }
}

void format()
{
  //IF A LOCATION IS FOUND FORMAT THE LONGITUDE AND LATITUDE TO 6 DECIMAL PLACES
  if (gps.location.isValid())
  {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
  }
  else
  //IF IT IS NOT FOUND JUST PRINT A MESSAGE
  {
    Serial.println("N/A");
  }




/*
 * //MAY USE THIS TO FIND THE DATA DEPENDING ON WHAT IS REQUIRED BY THE DATABASE
 //FORMATTING THE DATE THAT THE LOCATION WAS FOUND
  Serial.print("Date: ");
  //IF A DATE IS FOUND FORMAT IT SO THE DAY, MONTH AND YEAR ARE SEPERATED BY A /
  if (gps.date.isValid())
  {
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.println(gps.date.year());
  }
  else
  //IF IT IS NOT FOUND JUST PRINT A MESSAGE
  {
    Serial.println("N/A");
  }
 


//MAY USE THIS TO FIND THE TIME DEPENGING ON WHAT IS REQUIRED BY THE DATABASE
 
//FORMATTING THE TIME THE LOCATION WAS FOUND
  Serial.print("Time: ");
  //IF THE TIME IS FOUND, FORMAT IT SO THE HOUR, MINUTE AND SECOND ARE SERPERATED BY A :
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(":");
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
  }
  //IF IT IS NOT FOUND JUST PRINT A MESSAGE
  else
  {
    Serial.println("N/A");
  }*/

  Serial.println();
  Serial.println();
  delay(1000);
}
