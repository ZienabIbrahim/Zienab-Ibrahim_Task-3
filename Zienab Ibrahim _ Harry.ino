int Right_Sensor=2;
int Middle_Sensor=3;
int Left_Sensor=4;

int Right_Sensor_state;
int Middle_Sensor_state;
int Left_Sensor_state;

void moveForward();
void moveBackward();
void rotate90right();
void rotate90left();
void Stop();




void setup() {
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);


Serial.begin(9600);

 
}

void loop() {
Right_Sensor_state = digitalRead(2);
Middle_Sensor_state = digitalRead(3);
Left_Sensor_state = digitalRead(4);


if (Right_Sensor_state==0 && Middle_Sensor_state==1 && Left_Sensor_state==0)   // Straight line only
  {moveForward(); 
  }

if (Right_Sensor_state==1 && Middle_Sensor_state==0 && Left_Sensor_state==0)   //Right Turn(rightonly)
 {rotate90right();
  }

if (Right_Sensor_state==0 && Middle_Sensor_state==0 && Left_Sensor_state==1)   //Left Turn(left only):
  {rotate90left(); 
    }
if (Right_Sensor_state==1 && Middle_Sensor_state==0 && Left_Sensor_state==1)  //T intersection  
  {rotate90left();    //In this algorithm LEFT direction has the highest priority 
   }
if (Right_Sensor_state==0 && Middle_Sensor_state==1 && Left_Sensor_state==1)  //Left T Intersection
   {rotate90left();   //In this algorithm LEFT direction has the highest priority 
    }

if (Right_Sensor_state==1 && Middle_Sensor_state==1 && Left_Sensor_state==0)  //RIGHT T Intersection
   {moveForward();   //In this algorithm Forward direction has the 2nd priority 
    }

if (Right_Sensor_state==0 && Middle_Sensor_state==0 && Left_Sensor_state==0)  
   {moveBackward(); //As no other direction is possible
    }

if (Right_Sensor_state==1 && Middle_Sensor_state==1 && Left_Sensor_state==1)    // The condition for 4 line intersection and End of Maze seems similar
   { moveForward();
     delay(100);
     Stop();

     if (Right_Sensor_state==1 && Middle_Sensor_state==1 && Left_Sensor_state==1)
        {
          Stop();   //END OF MAZE
        }
     else
        {
         rotate90left();   //4 Line intersection
         }
    
    
    }

}
