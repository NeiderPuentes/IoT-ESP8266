/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest
  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.
    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app
  Blynk library is licensed under MIT license
  This example code is in public domain.
 *************************************************************
  This example runs directly on ESP8266 chip.
  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino
  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!
  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <BlynkSimpleEsp8266.h>

#include <ESP8266WiFi.h>
#include <SPI.h> // LIBRERIA ESP8266
#include <Servo.h>



Servo servo;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "GK0-MM68JEJDoaFoPwbKcsdeEkvIAFyq";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "CORONAVIRUS";
char pass[] = "0HM1CR0N";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  servo.attach(15); // NodeMCU D8 pin
}

void loop()
{
  Blynk.run();
}
BLYNK_WRITE(V1)
{
  servo.write(param.asInt());
   Serial.println("Giro controlado");
}


BLYNK_WRITE(V2)
{
  servo.write(0);
   Serial.println("Posició cero");
}

BLYNK_WRITE(V3) {
  servo.write(90);
   Serial.println("Giro 90 grados");
}
