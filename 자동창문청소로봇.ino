
#define speed1 10
#define In1 28 //노갈주파빨초 초록부터 시작
#define In2 26 
#define speed2 11
#define In3 24
#define In4 22

#define switch1 30
#define switch2 32
#define switch3 34
#define switch4 36
#define switch5 38
#define switch6 40
#define switch7 42
#define switch8 44

int SpeedA = 10; //표시되있는것
int SpeedB = 10; 


int a = 0;
int b = 0;
int c = 0;
int i = 0;
int j = 0;
int k = 0;
int o = 0;
int asd = 0;
int bsd = 0;
int csd = 0;
int dsd = 0;
int esd = 0;
int fsd = 0;

void setup(){
  Serial.begin(9600);

  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT); //모터 

  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);
  pinMode(switch4, INPUT_PULLUP);
  pinMode(switch5, INPUT_PULLUP);
  pinMode(switch6, INPUT_PULLUP);
  pinMode(switch7, INPUT_PULLUP);
  pinMode(switch8, INPUT_PULLUP); //충돌센서
  
}

void loop(){
  
  if(i==0){
    delay(5000);
    while(digitalRead(switch1) == HIGH && digitalRead(switch2) == HIGH){
      junjin();
      Serial.print("스위치 1,2 인식 xx 가는중/");
     Serial.print("SpeedA =");
      Serial.print(SpeedA);
      Serial.print("/SpeedB =");
      Serial.println(SpeedB);

     
      if(digitalRead(switch1) == LOW){
        //왼쪽바퀴만돌아라
        Serial.println("스위치 1 신호 받음 (처음)");
        delay(3000);
        while(digitalRead(switch2) == HIGH){
          
          Serial.println("스위치 1 먼저 신호 받음 왼쪽바퀴만 도는중");
          }
        i++;
      }
      else if(digitalRead(switch2) == LOW){
        //오른쪽바퀴만돌아라
        Serial.println("스위치 2 신호 받음 (처음)");  
        delay(3000);
        while(digitalRead(switch1) == HIGH){
          
          Serial.println("스위치 2 먼저 신호 받음 오른쪽바퀴만 도는중");
        }
        i++;
      }
    }
  }
  jungji();
  Serial.println("처음 정지");
  delay(3000);

  if(i==1){
    if(a==0){
        if(asd==0){
          while(digitalRead(switch5) == HIGH){//5
            sasun3();
            Serial.println("사선 3");
            
            if(digitalRead(switch7)== LOW){
              asd=1;
              break;
            }
          }
          delay(1000);
          if(digitalRead(switch7)==HIGH){
            while(digitalRead(switch6)==HIGH){
              
              Serial.println("바퀴 높이 맞춰죠");
              a=1;
            }
          }
        }
        else if(asd==1){
          while(digitalRead(switch8) == HIGH){
            sasun2();
            Serial.println("사선 2");
          }
          while(digitalRead(switch5) == HIGH && digitalRead(switch6) == HIGH){//5
            back();
            Serial.println("뒤로 갓");
          }
          a=2;
          i++;
        }
    }
    else if(a==1){
      if(bsd==0){
        while(digitalRead(switch2) == HIGH){
          sasun4();
          Serial.println("사선 4");
          if(digitalRead(switch8)== LOW){
            bsd=1;
            break;
          }
        }
        delay(1000);
        if(digitalRead(switch8)==HIGH){
          while(digitalRead(switch1)==HIGH){
            Serial.println("바퀴 높이 맞춰죠");
            a=0;
          }
        }
      }
      else if(bsd==1){
        while(digitalRead(switch7) == HIGH){
          sasun1();
          Serial.println("사선 1");
        }
        while(digitalRead(switch5) == HIGH && digitalRead(switch6) == HIGH){//5
          back();
          Serial.println("뒤로 갓");
        }
        a=2;
        i++;
      }
    }
  }

  if(i==2){
    if(b==0){
        if(csd==0){
          while(digitalRead(switch1) == HIGH){//5
            sasun1();
            Serial.println("사선 1");
            if(digitalRead(switch3)== LOW){
              csd=1;
              break;
            }
          }
          if(digitalRead(switch3)==HIGH){
            while(digitalRead(switch2)==HIGH){
              leftgo();
              Serial.println("바퀴 높이 맞춰죠");
              b=1;
            }
          }
        }
        else if(csd==1){
          while(digitalRead(switch4) == HIGH){
            sasun4();
            Serial.println("사선 4");
          }
          while(digitalRead(switch1) == HIGH && digitalRead(switch2) == HIGH){//5
            junjin();
            Serial.println("앞으로 갓");
          }
          b=2;
          i++;
        }
    }
    else if(b==1){
      if(dsd==0){
        while(digitalRead(switch6) == HIGH){
          sasun2();
          Serial.println("사선 2");
          if(digitalRead(switch4)== LOW){
            dsd=1;
            break;
          }
        }
        if(digitalRead(switch4)==HIGH){
          while(digitalRead(switch5)==HIGH){
            leftback();
            Serial.println("바퀴 높이 맞춰죠");
            b=0;
          }
        }
      }
      else if(dsd==1){
        while(digitalRead(switch3) == HIGH){
          sasun3();
          Serial.println("사선 3");
        }
        while(digitalRead(switch1) == HIGH && digitalRead(switch2) == HIGH){//5
          back();
          Serial.println("앞으로 갓");
        }
        b=2;
        i++;
      }
    }
  }
  
  if(i==3){
    if(c==0){
        if(esd==0){
          while(digitalRead(switch5) == HIGH){//5
            sasun3();
            Serial.println("사선 3");
            if(digitalRead(switch7)== LOW){
              esd=1;
              break;
            }
          }
          if(digitalRead(switch7)==HIGH){
            while(digitalRead(switch6)==HIGH){
              rightback();
              Serial.println("바퀴 높이 맞춰죠");
              c=1;
            }
          }
        }
        else if(esd==1){
          while(digitalRead(switch8) == HIGH){
            sasun2();
            Serial.println("사선 2");
          }
          while(digitalRead(switch5) == HIGH && digitalRead(switch6) == HIGH){//5
            back();
            Serial.println("뒤로 갓");
          }
          c=2;
          i++;
        }
    }
    else if(c==1){
      if(fsd==0){
        while(digitalRead(switch2) == HIGH){
          sasun4();
          Serial.println("사선 4");
          if(digitalRead(switch8)== LOW){
            fsd=1;
            break;
          }
        }
        if(digitalRead(switch8)==HIGH){
          while(digitalRead(switch1)==HIGH){
            leftgo();
            Serial.println("바퀴 높이 맞춰죠");
            c=0;
          }
        }
      }
      else if(fsd==1){
        while(digitalRead(switch7) == HIGH){
          sasun1();
          Serial.println("사선 1");
        }
        while(digitalRead(switch5) == HIGH && digitalRead(switch6) == HIGH){//5
          back();
          Serial.println("뒤로 갓");
        }
        c=2;
        i++;
      }
    }
  }
 
}
void leftgo(){
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(speed1, 250);
  delay(300);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(speed2, 0);
  delay(300);
}

void rightgo(){
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(speed1, 0);
  delay(300);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(speed2, 250);
  delay(300);
}

void leftback(){
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(speed1, 100);
  delay(300);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(speed2, 0);
  delay(300);  
}

void rightback(){
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(speed1, 0);
  delay(300);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(speed2, 100);
  delay(300);
}

void junjin(){
  
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(speed1, 250);
  delay(50);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(speed2, 250);
  delay(50);
}


void back(){
  
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(speed1, 250);
  
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(speed2, 250);
  
}


void jungji(){
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  analogWrite(speed1, 0);
  delay(300);
  
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  analogWrite(speed2, 0);
  delay(300);
}

void sasun1(){
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(speed1, 150);
  delay(300);
  
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(speed2, 95);
  delay(300);
}

void leftback(){
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(speed1, 100);
  delay(300);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(speed2, 0);
  delay(300);  
}

void sasun2(){
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(speed1, 95);
  delay(300);
  
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(speed2, 150);
  delay(300);
}//위로가는거

void sasun3(){
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(speed1, 210);
  delay(50);
  
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(speed2, 240);
  delay(50);
}
void sasun4(){
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(speed1, 230);
  delay(50);
  
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(speed2, 250);
  delay(50);
}

//내려오는거
