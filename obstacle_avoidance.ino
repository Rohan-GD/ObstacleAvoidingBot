char Incoming_value;
int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;
int state = 0;
int flag = 0;
#define trig 6
#define echo 7
float distance,duration;
void setup() {

  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(motor1pin1, OUTPUT);
   pinMode(motor1pin2, OUTPUT);
   pinMode(motor2pin1, OUTPUT);
   pinMode(motor2pin2, OUTPUT);
   pinMode(trig, OUTPUT);
   pinMode(echo,INPUT);
}

void loop(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
   digitalWrite(trig,LOW);
  delayMicroseconds(10);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  Serial.println(distance);
  if(distance>40)
  {
    if(Serial.available()>0)
    {
      Incoming_value=Serial.read();
      if(Incoming_value=='F')
      {
     digitalWrite(motor1pin1, HIGH);
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1, HIGH);
   digitalWrite(motor2pin2, LOW);
      }
    else if(Incoming_value=='B')
      {
     digitalWrite(motor1pin1, LOW);
   digitalWrite(motor1pin2, HIGH);
   digitalWrite(motor2pin1, LOW);
   digitalWrite(motor2pin2, HIGH); 
    }
   else if(Incoming_value=='R')
      {
     digitalWrite(motor1pin1, HIGH);
   digitalWrite(motor1pin2, LOW);
      }
     else if(Incoming_value=='L')
      {
     
   digitalWrite(motor2pin1, HIGH);
   digitalWrite(motor2pin2, LOW);
}
else if(Incoming_value=='S')
      {
     digitalWrite(motor1pin1, LOW);
   digitalWrite(motor1pin2, LOW);
   digitalWrite(motor2pin1, LOW);
   digitalWrite(motor2pin2, LOW);
      }}
    }
    else
    {

     digitalWrite(motor1pin1, LOW);
   digitalWrite(motor1pin2, HIGH);
   digitalWrite(motor2pin1, LOW);
   digitalWrite(motor2pin2, HIGH);
    }
}
    
      
