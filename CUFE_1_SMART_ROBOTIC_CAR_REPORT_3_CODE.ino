#define buzzer_pin 3
#define metal_sens A0
int ENA=5;
int ENB=6;
int IN1=7;
int IN2=8;
int IN3=9;
int IN4=11;

char t;
 
void setup() {
pinMode(buzzer_pin, OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
digitalWrite(ENA,HIGH);
digitalWrite(ENB,HIGH);
Serial.begin(9600);
}
 
void loop() {
  
int a=analogRead(A0);
  if(a<512){
    tone(buzzer_pin,500*2,200);
    }

if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(100);

}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(100);

}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction)
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(100);

}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction)
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(100);

}

else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(11,LOW);

}
delay(50);
}
