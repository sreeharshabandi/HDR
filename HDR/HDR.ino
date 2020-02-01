int echopin = 2;
int trigpin = 3;
int PIRpin = 5;
int buzzerpin = 7;
int motor_left[] = {8, 9};
int motor_right[] = {10, 11};

void setup(){
  Serial.begin(9600);
  int i;
  for(i = 0; i < 2; i++){
  pinMode(motor_left[i], OUTPUT);
  pinMode(motor_right[i], OUTPUT);
  }
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(PIRpin,INPUT);
  pinMode(buzzerpin,OUTPUT);

}
void loop(){
  long duration,distance;
  {
  digitalWrite(motor_left[0], HIGH); 
  digitalWrite(motor_left[1], LOW); 

  digitalWrite(motor_right[0], HIGH); 
  digitalWrite(motor_right[1], LOW); 
  }
  digitalWrite(trigpin,LOW);
  delay(200);
  digitalWrite(trigpin,HIGH);
  distance=(duration/2)/29.1;
  if(distance<4){
    digitalWrite(motor_left[0], LOW); 
    digitalWrite(motor_left[1], LOW); 

    digitalWrite(motor_right[0], LOW); 
    digitalWrite(motor_right[1], LOW);

    digitalWrite(buzzerpin,HIGH);
  }
  else{
       digitalWrite(motor_left[0], HIGH); 
       digitalWrite(motor_left[1], LOW); 

       digitalWrite(motor_right[0], HIGH); 
       digitalWrite(motor_right[1], LOW);
       delay(500); 
  }
    
    
  }



