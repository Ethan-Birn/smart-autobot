#define PWMD 3 // Rear Right

#define DIRD 2 // Rear Right HIGH means FWD, LOW means BKWD*

#define PWMC 5 // Rear Left

#define DIRC 4 // Rear Left LOW means FWD, HIGH means BKWD*

#define PWMB 6 // Front Right

#define DIRB 7 // Front Right HIGH means FWD, LOW means BKWD

#define PWMA 9 // Front Left

#define DIRA 8 // Front Left LOW means FWD, HIGH means BKWD



int speed1; int speed2; int delayval1; int delayval2;



void setup() {

  pinMode(PWMA, OUTPUT);

  pinMode(DIRA, OUTPUT);

  pinMode(PWMB, OUTPUT);

  pinMode(DIRB, OUTPUT);

  pinMode(PWMC, OUTPUT);

  pinMode(DIRC, OUTPUT);

  pinMode(PWMD, OUTPUT);

  pinMode(DIRD, OUTPUT);



  Serial.begin(9600);

}



void turnLeft(int speed) {

  digitalWrite(DIRA,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB,HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRC,HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD,HIGH); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA, speed);  analogWrite(PWMB, speed);  analogWrite(PWMC, speed);  analogWrite(PWMD, speed);

}



void turnRight(int speed) {

  digitalWrite(DIRA,HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRC,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD,LOW); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA, speed);  analogWrite(PWMB, speed);  analogWrite(PWMC, speed);  analogWrite(PWMD, speed);

}



void forward(int speed) { 

  digitalWrite(DIRA, LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB, HIGH); // HIGH means FWD, LOW means BKWD*

  digitalWrite(DIRC, LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD, HIGH); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA, speed);  analogWrite(PWMB, speed);  analogWrite(PWMC, speed);  analogWrite(PWMD, speed);

}



void back(int speed) {

  digitalWrite(DIRA, HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB, LOW); // HIGH means FWD, LOW means BKWD*

  digitalWrite(DIRC, HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD, LOW); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA, speed);  analogWrite(PWMB, speed);  analogWrite(PWMC, speed);  analogWrite(PWMD, speed);

}



void stop() 

{

  digitalWrite(DIRA, LOW);  digitalWrite(DIRB, LOW);  digitalWrite(DIRC, LOW);  digitalWrite(DIRD, LOW);

  analogWrite(PWMA, 0);  analogWrite(PWMB, 0);  analogWrite(PWMC, 0);  analogWrite(PWMD, 0);

}



void motor_pmove_left(int speed)

{

  digitalWrite(DIRA,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRC,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD,HIGH); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA,0);  analogWrite(PWMB,speed);  analogWrite(PWMC,speed);  analogWrite(PWMD,0);

}



void motor_pmove_right(int speed)

{

  digitalWrite(DIRA,HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRB,HIGH); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRC,LOW); // LOW means FWD, HIGH means BKWD

  digitalWrite(DIRD,LOW); // HIGH means FWD, LOW means BKWD

  analogWrite(PWMA,speed);  analogWrite(PWMB,0);  analogWrite(PWMC,0);  analogWrite(PWMD,speed);

}



void loop() {

      speed1 = 150; 
      speed2 = 150; 
      delayval1 = 2000; 
      delayval2 = 2000;



      forward(speed1);   
      delay(delayval1);     
      stop();      
      delay(delayval2);

      back(speed1);      
      delay(delayval1);     
      stop();      
      delay(delayval2);

      /*turnLeft(speed1);      
      delay(delayval1);      
      stop();      
      delay(delayval2);

      turnRight(speed1);      
      delay(delayval1);      
      stop();      
      delay(delayval2);

      motor_pmove_left(speed2);       
      delay(delayval1);      
      stop();      
      delay(delayval2);

      motor_pmove_right(speed2);       
      delay(delayval1);      
      stop();      
      delay(delayval2);*/

}




