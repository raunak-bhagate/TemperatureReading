#define BLYNK_TEMPLATE_ID "TMPL3EcHxs5lF"
#define BLYNK_TEMPLATE_NAME "DHT IOT Sensor"
#define BLYNK_AUTH_TOKEN "vuMGLUyCglauItipofhmAOpm4MAa1mx1"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

# define DHTPIN 4 // Data pin is connected to pin D2 in ESP
#define DHTTYPE DHT11 //Name the sensor as an object
DHT dht(DHTPIN, DHTTYPE);

 char auth[] = "vuMGLUyCglauItipofhmAOpm4MAa1mx1";
 char ssid[] = "wifi";
 char pass[] = "password";
// Github Comment

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("DHT Test Successful!");
Blynk.begin(auth, ssid, pass);
Serial.println("Blynk Connected Successfully");
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
float h = dht.readHumidity();
float t = dht.readTemperature();
float f = dht.readTemperature(true);
if (isnan(h) || isnan(t) || isnan(f)){
  Serial.println("Something is not working as intented\n");
return;
}
Serial.println("Humidity:");
Serial.print(h);
Serial.print("%\n");
Serial.println("\nTemperature:");
Serial.print(t);
Serial.print(" degrees celsius.\n");
Blynk.virtualWrite(V0, t);
Blynk.virtualWrite(V1, h);
delay(2000);
}
