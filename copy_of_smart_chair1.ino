// C++ code
//
const int buzzer=13;
const int buzzer1=9;
void setup()
{
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
  pinMode(buzzer1,OUTPUT);
}

void loop()
{
  if(digitalRead(13)==LOW)
  {
    digitalWrite(13,HIGH);
    delay(3000);
    tone(buzzer,1000);//in reality buzzer responds after 5min ,so he change position 
    delay(1000);
    noTone(buzzer);
    delay(3000);
  }
  else
    digitalWrite(13,LOW);
  
  delay(10000);
  int analogReading = analogRead(A0);
  int analogReading1 = analogRead(A1);
  int analogReading2 = analogRead(A2);
  int analogReading3 = analogRead(A3);
  int analogReading4 = analogRead(A4);
  
  if((analogReading2>0) && (analogReading3 >0) && (analogReading==0) && (analogReading1 ==0) && (analogReading4==0))
  {//if the person tries to arrange something like books.
    //more delay is needed so he can come back.
    Serial.println("wrong posture");
    delay(7000);
    tone(buzzer1,1000);
    delay(1000);
    noTone(buzzer1);
    delay(20000);
  }
  
  
  else if((analogReading==0) && (analogReading1==0) && (analogReading2==0) && (analogReading3==0) && (analogReading4 ==0))
  {
    Serial.println("no pressure");
    
  }
  else if((analogReading >0) && (analogReading1 >0) && (analogReading2 >0) && (analogReading3 >0) && (analogReading4 >0))
  {
    Serial.println("person present in correct position");//person present in correct position
    
  }
  else
  {
   
        
    delay(10000);//this delay of 10sec is ony for testing purposes
    //in reality the buzzer rings after 5 min indicating he sat i wrong posture for more than 5 min
    if((analogReading!=0) && (analogReading1!=0) && (analogReading2!=0) && (analogReading3!=0) && (analogReading4 !=0))
       {
         Serial.println("person present");
       }
 
   else
   {
     Serial.println("wrong posture");
    tone(buzzer1,1000);
    delay(1000);
    noTone(buzzer1);
    delay(3000);
   }
  }
    
 delay(1000);
}