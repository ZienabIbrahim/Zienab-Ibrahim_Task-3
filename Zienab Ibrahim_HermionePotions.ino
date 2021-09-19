#include<Timer.h>
int red_led=5;
int green_led=6;
int white_led=7;
int push_button=9;
Timer mytimer;
int val;





void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(9,INPUT);
  Serial.begin(9600);
  mytimer.after(300,fn1);    //fn1 to turn on white led
  mytimer.after(480,fn1);    //fn1 to turn on white led

  mytimer.after(310,fn2);    //fn2 to turn off white led
  mytimer.after(490,fn2);    //fn2 to turn off white led

  

  mytimer.every(120,fn3);    //fn3 to turn on green led
 
  mytimer.every(125,fn4);   //fn4 to turn off green led

  mytimer.after(900,fn5);   //fn5 to turn off red led
  
  
  
  
  
  

}

void loop() {
  
  val=digitalRead(9); 
  
  
  
  if (val==HIGH)             // start the main recipe routine 
  { digitalWrite(5,HIGH);   // indicate the time that the heat should be turned on 
    mytimer.update();
    
    
    
    
    } 
 }

 void fn1()                // indicate the need for adding the next ingredient to the pot
 {digitalWrite(7,HIGH);
  delay(10);
  }
 
 void fn2()                
 {digitalWrite(7,LOW);
  }
 
 void fn3()               // indicate the need for mixing the ingredients in the pot 
 {digitalWrite(6,HIGH);
  }

 void fn4()                
 {digitalWrite(6,LOW);
  } 
  
  
  
  
  void fn5()                
 {digitalWrite(5,LOW);
  }
  
  
  
  
  
  
  
 

  
