const int trigPin = 3;
const int echoPin = 4;
const int in1 = 8;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;
const int pirpin = 2;
int buzzerpin = 13;
byte names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'};  
int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};
byte melody[] = "2d2a1f2c2d2a2d2c2f2d2a2c2d2a1f2c2d2a2a2g2p8p8p8p";
// count length: 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0
//                                10                  20                  30
int count = 0;
int count2 = 0;
int count3 = 0;
int MAX_COUNT = 24;
int statePin = LOW;
void siren();

 volatile byte intruder;


void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(pirpin, INPUT); 
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  Serial.begin(115200);
   attachInterrupt(0, intruder_detect, RISING);//Initialize the intterrupt pin for the motion sensor (Arduino digital pin 2)
   intruder = 0;
}
long duration, distance;

void loop()
{     
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  if(distance<55)
    {
      digitalWrite(in1, HIGH); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, HIGH);
    }
  else
    {
      digitalWrite(in1, LOW); 
      digitalWrite(in2, HIGH); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, HIGH);
    }  
  delay(50);
}
void intruder_detect()//This function is called whenever an intruder is detected by the arduino
 {
   intruder++;
   Serial.println("Intruder detected");
   for(int i=0; i<1; i++)//Play the alarm three times
   siren();
 }
 void siren()//This function will make the alarm sound using the piezo buzzer
{
for (count = 0; count < MAX_COUNT; count++) {
      for (count3 = 0; count3 <= (melody[count*2] - 48) * 30; count3++) {
      for (count2=0;count2<8;count2++) {
        if (names[count2] == melody[count*2 + 1]) {       
          analogWrite(buzzerpin,1023);
          delayMicroseconds(tones[count2]);
          analogWrite(buzzerpin,0);
          delayMicroseconds(tones[count2]);
        } 
        if (melody[count*2 + 1] == 'p') {
          // make a pause of a certain size
          analogWrite(buzzerpin, 0);
          delayMicroseconds(100);
        }
      }
    }
  }
}
