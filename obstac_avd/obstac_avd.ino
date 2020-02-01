const int trigPin = 3;
const int echoPin = 2;
const int in1 = 8;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;
const int buzzerpin = 7;
const int pirpin = 5; 
            
int count = 0;
int count2 = 0;
int count3 = 0;
int MAX_COUNT = 24;
int statePin = LOW;


 void setup(){
 {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
 }
 
   Serial.begin(115200);
  
 }
 void loop(){
 
   
 
 void intruder_detect()//This function is called whenever an intruder is detected by the arduino

  // intruder++;
  // Serial.println("Intruder detected");
   for(int i=0; i<3; i++)//Play the alarm three times
   siren();

 void siren()//This function will make the alarm sound using the piezo buzzer

      for (count = 0; count < MAX_COUNT; count++) {
      for (count3 = 0; count3 <= (melody[count*2] - 48) * 30; count3++) {
      for (count2=0;count2<8;count2++) {
        if (names[count2] == melody[count*2 + 1]) {       
          analogWrite(buzzerpin,1023);
          delayMicroseconds(tones[count2]);
          analogWrite(buzzerpin, 0);
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




long duration, distance;


     
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  if(distance<45)
    {
      digitalWrite(in1, LOW); 
      digitalWrite(in2, HIGH); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW);
    }
  else
    {
      digitalWrite(in1, HIGH); 
      digitalWrite(in2, LOW); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW);
    }  
  delay(50);
}
