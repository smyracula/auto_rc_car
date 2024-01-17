
#define echoPin 10 
#define trigPin 11 

#define Buzzer 8 

#define MotorR1 7 
#define MotorR2 6 
#define MotorRenable 9  


int isEngineForward = 0;
long sure, uzaklik; 
int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
int noteDurations[] = {4, 4, 4, 4, 4, 4, 4, 4};


void setup() {

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRenable, OUTPUT);
  Serial.begin(9600);
  delay(250);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(15);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);

  sure = pulseIn(echoPin, HIGH); 
  uzaklik = sure / 29.1 / 2; 
  if (uzaklik > 2 && uzaklik < 30)
  {
    stopEngine();
  }
  else {
    forward();
    if (uzaklik > 30 && uzaklik < 60) {
      playBuzzer();
    }
  }
}

void forward() {
  if (isEngineForward == 0)
  {
    //noTone(Buzzer);
    isEngineForward = 1;
    digitalWrite(MotorR1, HIGH);
    digitalWrite(MotorR2, LOW); 
    analogWrite(MotorRenable, 250);
    Serial.println("Ileri");
  }
}

void stopEngine() { 
  isEngineForward = 0;
  digitalWrite(MotorR1, LOW); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRenable, 0);

  Serial.println("DUR");
}

void playBuzzer() {
  tone(Buzzer, 245, 200);
  delay(250); 
  noTone(Buzzer);
  delay(250);
}
