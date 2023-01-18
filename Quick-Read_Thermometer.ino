//temp control circuit

#define HOT 6
#define NORMAL 4
#define COLD 2

float voltage = 0;
float celsius = 0;
float hotTemp = 26;
float coldTemp = 20;
float sensor = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(HOT, OUTPUT);
pinMode(NORMAL, OUTPUT);
pinMode(COLD, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sensor = analogRead(0);
voltage = (sensor*500)/1024; //convert raw sensor value to millions
voltage = voltage - 500; //remove voltage offset
celsius = voltage/10; //convert millivolt to Celsius

//act on temperature range
if (celsius < coldTemp)
{
  digitalWrite(COLD, HIGH);
  delay(1000);
  digitalWrite(COLD, LOW);
}
else if(celsius > coldTemp && celsius <= hotTemp)
{
  digitalWrite(NORMAL, HIGH);
  delay(1000);
  digitalWrite(NORMAL, LOW);
}
else
{
  //celsius is > hotTemp
  digitalWrite(HOT, HIGH);
  delay(1000);
  digitalWrite(HOT, LOW);
   
}
}
