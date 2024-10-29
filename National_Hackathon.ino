#define trigPin 9          
#define echoPin 8           
#define BUZ 13              
long duration, distance;
unsigned long previousMillis = 0;
const long interval = 100;  

void setup() 
{
   pinMode(BUZ, OUTPUT);
   pinMode(trigPin, OUTPUT);  
   pinMode(echoPin, INPUT);   
   Serial.begin(9600);        
}

void loop() 
{
  unsigned long currentMillis = millis();  
  
  if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;  
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);   
    digitalWrite(trigPin, HIGH);       
    delayMicroseconds(10);
    
    duration = pulseIn(echoPin, HIGH);  
    distance = duration / 58.2;         
    
    Serial.println(distance);           
    
    if (distance < 100)                 
    {
      
      for (int i = 0; i < 5; i++)
      {
        digitalWrite(BUZ, HIGH);
        delay(50);
        digitalWrite(BUZ, LOW);
        delay(50);
      }
    }
  }
}

