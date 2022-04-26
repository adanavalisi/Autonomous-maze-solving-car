 //SERGEN FARKI
  
  //left motor setup
  #define INL1 7
  #define INL2 8
  #define PWML 9
  
  //right motor setup
  #define INR1 12
  #define INR2 13
  #define PWMR 3

  //HCSR1 setup
  #define TRIG1 10
  #define ECHO1 11
  #define TRIG2 4
  #define ECHO2 5

  #define echoPin3 6 //Ultrasonik sensörün echo pini Arduino'nun 12.pinine
  #define trigPin3 2

  
void setup() {
  // put your setup code here, to run once:
  
  pinMode(PWML,OUTPUT);
  pinMode(PWMR,OUTPUT);
  pinMode(INL1,OUTPUT);
  pinMode(INL2,OUTPUT);
  pinMode(INR1,OUTPUT);
  pinMode(INR2,OUTPUT);

  //Serial.begin (9600);
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin3, OUTPUT);
}
long duration, cm, dstcF, dstcR,uzaklik3,sure3;
int a=0;
long threedata[3];
unsigned long interval = 0;
void loop() {
  dstcF = distanceFront();
  dstcR = distanceRight();
  caprazUzaklik();

  //Serial.println(dstcF);
  //Serial.println(dstcR);
  //Serial.println(uzaklik3);


if(uzaklik3<=10){
    fullStop();
    delay(80);
    solGeri();
    delay(80); //80
    a=1;
  }

  
  if(dstcR < 8 and a==0){
    turnLeftFor(80);
    a=0;
  }
  if(dstcF < 15 and a==0){
      backward();
     a=0;
  }
  if(dstcF >= 17 && dstcR <= 17 and a==0){
    if(dstcR < 8){
      turnLeftFor(0);
      
    }
    forward();
    a=0;
  }
  if(dstcF >= 17 && dstcR > 17 and a==0){
    //delay(250);
    fullStop();
    turnRight();
    delay(200); //300
    fullStop();
    delay(100);
    if(uzaklik3>10){
    forwardFor(250);
    }
    a=0;
  }
  if(dstcF < 17 && dstcR <= 17 and a==0){
    backFor(200); //250
    turnLeft();
    delay(300);  //450
    forwardFor(100);
    a=0;
  }
  if(dstcF < 17 && dstcR > 17 and a==0){

    backFor(250);
    turnLeft();
    delay(500);
    a=0;
    
    }

  a=0;



}
long distanceFront(){
  long cm1,cm2,cm3;
  digitalWrite(TRIG1, LOW);
  delay(5);
  digitalWrite(TRIG1, HIGH);
  delay(10);
  digitalWrite(TRIG1, LOW);
  duration = pulseIn(ECHO1, HIGH);
  cm1 = (duration/2)/ 29.1;
  cm2 = (duration/2)/ 29.1;
  cm3 = (duration/2)/ 29.1;
  cm = (cm1+cm2+cm3)/3;
  delay(50);
  return cm;
}
long distanceRight(){
  long cm1,cm2,cm3;
  digitalWrite(TRIG2, LOW);
  delay(5);
  digitalWrite(TRIG2, HIGH);
  delay(10);
  digitalWrite(TRIG2, LOW);
  duration = pulseIn(ECHO2, HIGH);
  cm1 = (duration/2)/ 29.1;
  cm2 = (duration/2)/ 29.1;
  cm3 = (duration/2)/ 29.1;
  cm = (cm1+cm2+cm3)/3;
  delay(50);
  return cm;
}
void backward() {
  digitalWrite(INL1, HIGH);
  digitalWrite(INR1, HIGH);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, LOW);
  analogWrite(PWML,190);
  analogWrite(PWMR,185);
  
}
void fullForward() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,190);
  analogWrite(PWMR,190);  
}
void forward() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,150);
  analogWrite(PWMR,150);  
}

void fullStop() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, LOW);
  
  analogWrite(PWML,0);
  analogWrite(PWMR,0);
  
}

void turnRight() {
  digitalWrite(INL1, HIGH);
  digitalWrite(INR1, HIGH);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, LOW);
  analogWrite(PWML,180);
  analogWrite(PWMR,0);
}
void turnRight90() {
  turnRight();
  delay(900);
  fullStop();
}
void turnLeft() {
  digitalWrite(INL1, HIGH);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, LOW);
  digitalWrite(INR2, HIGH);
  
  analogWrite(PWML,0);
  analogWrite(PWMR,180);
}
void turnLeft90() {
  turnLeft();
  delay(950);
  fullStop();
}
//smart commands
void turnLeft180() {
  turnLeft();
  delay(950);
  fullStop();
}
int turnLeftFor(int leftTime) {
  turnLeft();
  delay(leftTime);
  fullStop();
}
void forwardFor(int forwardTime) {
  fullForward();
  delay(forwardTime);
  fullStop();
}
void backFor(int backTime) {
  backward();
  delay(backTime);
  fullStop();
}
void rotateLeft() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,155);
  analogWrite(PWMR,180);  
}
void rotateRight() {
  digitalWrite(INL1, LOW);
  digitalWrite(INR1, LOW);
  digitalWrite(INL2, HIGH);
  digitalWrite(INR2, HIGH);
  analogWrite(PWML,180);
  analogWrite(PWMR,155);  
}



void solGeri(){

  digitalWrite(INR1, HIGH); // Sağ motorun ileri hareketi pasif
  digitalWrite(INR2, LOW); // Sağ motorun geri hareketi aktif
  analogWrite(PWMR, 180); // Sağ motorun hızı 150

  digitalWrite(INL1, HIGH); // Sol motorun ileri hareketi pasif
  digitalWrite(INL2, LOW); // Sol motorun geri hareketi aktif
  analogWrite(PWML, 0); // Sol motorun hızı 150
  
}





long caprazUzaklik(){
digitalWrite(trigPin3, LOW); //sensör pasif hale getirildi
  delayMicroseconds(100);
  digitalWrite(trigPin3, HIGH); //Sensore ses dalgasının üretmesi için emir verildi
  delayMicroseconds(100);
  digitalWrite(trigPin3, LOW);
  sure3 = pulseIn(echoPin3, HIGH); //ses dalgasının geri dönmesi için geçen sure ölçülüyor
  uzaklik3 =( sure3 / 29.1) / 2;

  return uzaklik3;
}
