const int green = 3;
const int red = 4;
const int pir_sensor = 2;
const int buzzer = 10;
const int button1 =11;
const int button2 =12;

bool alarm = false;


void setup()
{
  
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(pir_sensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Serial.begin(9600);

}

void loop()
{

if(digitalRead(button1)==HIGH)
{
  alarm = true;
  delay(3000);
  
}

if(digitalRead(button2)==HIGH)
{
  alarm = false;
  
  
}
Serial.print("ALARM  :");
Serial.println(alarm);
  
  
if(alarm == true)
{
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
  if(digitalRead(pir_sensor)==HIGH)
  {
    while(digitalRead(button2) == LOW){
      digitalWrite(buzzer,HIGH);
      delay(250);
      digitalWrite(buzzer,LOW);
      delay(250);}
  }
  
    
}
if(alarm == false)
{
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
}
  
}