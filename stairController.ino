
 unsigned long czas = 0;
 unsigned long roznica = 0;
 unsigned long aktualny = 0;

void setup() {
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(12,INPUT_PULLUP);
 pinMode(13,INPUT_PULLUP);
}


void fromDown()
  {
    int j=0;
    boolean f = false;
    for(int i = 2; i < 10; i++)
    {
      czas = millis();
      roznica = 0;
      while(roznica < 500UL) 
      {
        aktualny = millis();
        roznica = aktualny - czas;
        if(digitalRead(13) == LOW && f == false)
        {
            j=9;
            f= true;
        } 
      }

      if(j!=0)
      {
        digitalWrite(j,HIGH); 
        j--;
      }
      digitalWrite(i,HIGH);
      
    }
    for(int i = 2; i < 10; i++)
    {
      digitalWrite(i,LOW);
      delay(400);
    }
  }

void fromUp()
  {
    int j=0;;
    boolean f = false;
    for(int i = 9; i > 1; i--)
    {
      czas = millis();
      roznica = 0;
      while(roznica < 500UL) 
      {
        aktualny = millis();
        roznica = aktualny - czas;
        if(digitalRead(12) == LOW && f == false)
        {
            j=2;
            f= true;
        } 
      }

      if(j!=0)
      {
        digitalWrite(j,HIGH);
        j++;
      }
      digitalWrite(i,HIGH);
      
    }
    for(int i = 9; i > 1; i--)
    {
      digitalWrite(i,LOW);
      delay(400);
    }
  }



  
void loop() {

  if(digitalRead(12) == LOW)
  {
      fromDown();
  }
  if(digitalRead(13) == LOW)
  {
      fromUp();
  }
    
}
