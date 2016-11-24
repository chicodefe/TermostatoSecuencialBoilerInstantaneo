#include <OneWire.h>
#include <DallasTemperature.h>

int SetPoint = 40;
int Dif = 1;
int Stages = 4;
int Boilers = 4;
int Flujo = 0;

#define ONE_WIRE_BUS_1 2
#define ONE_WIRE_BUS_2 4

OneWire oneWire_in(ONE_WIRE_BUS_1);
OneWire oneWire_out(ONE_WIRE_BUS_2);

DallasTemperature sensor_inhouse(&oneWire_in);
DallasTemperature sensor_outhouse(&oneWire_out);

void setup() {
  Serial.begin(9600);

  Serial.println("Dallas Temperature Control Library Demo - TwoPin_DS18B20");
    sensor_inhouse.begin();
    sensor_outhouse.begin();

  Serial.print("Found ");
  Serial.print(sensor_inhouse.getDeviceCount(), DEC);
    Serial.print(sensor_outhouse.getDeviceCount(), DEC);
  Serial.println(" devices.");}


void loop() {



  Serial.print("Requesting temperatures...");
    sensor_inhouse.requestTemperatures();
    sensor_outhouse.requestTemperatures();
    Serial.println(" done");

    Serial.print("Inhouse: ");
    Serial.println(sensor_inhouse.getTempCByIndex(0));

    Serial.print("Outhouse: ");
    Serial.println(sensor_outhouse.getTempCByIndex(0));


     delay(1000); 
}
