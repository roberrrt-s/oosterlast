#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

#include <ESP8266HTTPClient.h>

char ssid[] = "iPhone van Robert Spier"; //  your network SSID (name) 
char pass[] = "vixgm9fruiida"; // your network password
int status = WL_IDLE_STATUS;
WiFiClient client;

char* host = "www.robertspier.nl";
String path = "hva/pw3/receive/reports.json";
const int httpPort = 80;

void setup() {
  
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(A0, INPUT);

  Serial.begin(9600);

  Serial.print("Connecting to the WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connection established");
  
}

// the loop function runs over and over again forever
void loop() {

    HTTPClient http;

    http.begin("http://robertspier.nl/hva/pw3/receive/lights.txt"); 
    int httpCode = http.GET();        
    String payload = http.getString();

    Serial.println(payload);

    int data = analogRead(A0);
    Serial.print("Pot: ");
    Serial.println(data);

    if(payload.indexOf("1") > -1) {
      digitalWrite(D0, HIGH); 
    }
    else {
      digitalWrite(D0, LOW);
    }
    if(payload.indexOf("2") > -1) {
      digitalWrite(D1, HIGH); 
    }
    else {
      digitalWrite(D1, LOW);
    }
    if(payload.indexOf("3") > -1) {
      digitalWrite(D2, HIGH); 
    }
    else {
      digitalWrite(D2, LOW);
    }
    if(payload.indexOf("4") > -1) {
      digitalWrite(D3, HIGH); 
    }
    else {
      digitalWrite(D3, LOW);
    }
    if(payload.indexOf("5") > -1) {
      digitalWrite(D4, HIGH); 
    }
    else {
      digitalWrite(D4, LOW);
    }

     String pot = "pot=" + data;
    
    //check if and connect the nodeMCU to the server
    if (client.connect(host, httpPort)) {
      //make the POST headers and add the data string to it
      client.println("POST /hva/pw3/report/index.php HTTP/1.1");
      client.println("Host: www.robertspier.nl:80");
      client.println("Content-Type: application/x-www-form-urlencoded");
      client.println("Connection: close");
      client.print("Content-Length: ");
      client.println();
      client.print(pot);
      client.println();
      Serial.println("Send data:" + pot);
    
    } else {
      Serial.println("Something went wrong");
    }
    
}