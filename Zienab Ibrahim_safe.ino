int E1_Signal_A=2;
int E1_Signal_B=3;


int E2_Signal_A=18;
int E2_Signal_B=19;

int E3_Signal_A=20;
int E3_Signal_B=21;


long long counter1 ;
long long counter2 ;
long long counter3 ;

int degree1;
int degree2;
int degree3;

int Green_LED=5;



void setup() {
// Encoder 1
pinMode(2,INPUT_PULLUP);  
pinMode(3,INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(2),E1_ISR_A,CHANGE);
attachInterrupt(digitalPinToInterrupt(3),E1_ISR_B,CHANGE);

//Encoder 2
pinMode(18,INPUT_PULLUP);  
pinMode(19,INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(18),E2_ISR_A,CHANGE);
attachInterrupt(digitalPinToInterrupt(19),E2_ISR_B,CHANGE);

//Encoder 3
pinMode(20,INPUT_PULLUP);  
pinMode(21,INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(20),E3_ISR_A,CHANGE);
attachInterrupt(digitalPinToInterrupt(21),E3_ISR_B,CHANGE);
  
Serial.begin(9600); 

pinMode(5,OUTPUT); 
  }

void loop() {
  degree1=(counter1*360)/(2048*4);
  degree2=(counter2*360)/(2048*4);
  degree3=(counter3*360)/(2048*4);


  if (degree1==37 && degree2==10 && degree3==54)
      digitalWrite(5,HIGH);
  
  }
void E1_ISR_A()
    {if (digitalRead(2)!= digitalRead(3))
        counter1++ ;
     else
        counter1-- ;
      
      }
void E1_ISR_B()
    {if (digitalRead(2)<= digitalRead(3))
        counter1++ ;
     else
        counter1-- ;
      
      }


void E2_ISR_A()
    {if (digitalRead(18)!= digitalRead(19))
        counter2++ ;
     else
        counter2-- ;
      
      }
void E2_ISR_B()
    {if (digitalRead(18)<= digitalRead(19))
        counter2++ ;
     else
        counter2-- ;
      
      }

void E3_ISR_A()
    {if (digitalRead(20)!= digitalRead(21))
        counter3++ ;
     else
        counter3-- ;
      
      }
void E3_ISR_B()
    {if (digitalRead(20)<= digitalRead(21))
        counter3++ ;
     else
        counter3-- ;
      
      }
