unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period;
int magnetstate=0;
int laststate=1;
int sensor=3;
int counter=0;
float speed;
float radius=0.05;   //in m
float pi=3.14;
float circumference =2*radius*pi;             // declare all variables and values

void setup(){
	Serial.begin(115200);
	startMillis=millis();  
	pinMode(sensor,INPUT)                        // declare sensor as input and start the time and serial monitor
} 

void loop(){
  currentMillis=millis();		        // start the current time (start time gets reset every loop  
  magnetstate=digitalRead(sensor);        // read the state of the sensor and save on magnetstate
  if(magnetstate==0 && laststate==1){   // condition of magnet’s current and last state
    laststate=0;			        // change last state to 0 if previous condition true
    if(currentMillis-startMillis>=period & laststate==0){	     //  condition for time to detect
      speed=circumference/(currentMillis-startMillis)*1000   //  calculate the speed 
      stattMillis=currentMillis;					    //  reset current time
      counter++ 						   //count the number of tours
      Serial.print(string(speed)+"m/s");			   // print speed in serial monitor
    }
  }
  else{								   //if previous conditions false
    if(currentMillis-startMillis>=period && laststate==0){	   //condition of time and last state

      startMillis=currentMillis;					   //current time gets updated
      laststate=1;						   //last state of magnate gets updated
    }
}

