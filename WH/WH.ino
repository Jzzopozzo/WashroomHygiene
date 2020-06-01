#include<LiquidCrystal.h>
int pro, door, level;
const int rs= 12, en= 11, d4= 5, d5= 4, d6= 3, d7= 2;
const int Prox= 7;
const int Door= 8;
const int LED= 6;
const int Buzz= 10;
const int Level= A0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  pinMode(7, INPUT);  //Proximity
  pinMode(8, INPUT);  //Door Sensor
  pinMode(6, OUTPUT);  //LED
  pinMode(10, OUTPUT);  //Buzzer
  Serial.begin(9600);
  lcd. begin(16, 2);
}

void loop()
{
   lcd. clear();
   level= analogRead(A0);
   Serial.print("Water level:");
   Serial.println(level);

   if(level> 600)
   {
    digitalWrite(LED, LOW);
    lcd. print("NON- FUNCTIONAL");
   // digitalWrite(Buzz, HIGH);
    if(door== 1)
    {
      tone(Buzz, 50, 500);
      Serial.println("alnflkdf");
    }
   }    //PERFECT
   else
   {
    digitalWrite(LED, HIGH);
    lcd.print("FUNCTIONAL");
    if(door == 1 && pro== 1)
    {
      lcd.clear();
      lcd.print("PLEASE FLUSH");
    }
   }

   delay(1000);

   pro= digitalRead(Prox);
   if(pro== 0)
   {
     Serial.println("Somebody's in!");  //User using toilet
   }
   else
   {
    Serial.println("Nobody's in.");
   }
   
   door= digitalRead(Door);
   if(door== 0)
   {
     Serial.println("Door is closed."); //Door is closed
        Serial.println("\n");
   }

   else
   {
      Serial.println("Door is open.");
     // Serial.println(door);
      Serial.println("\n");
   }

   if(level< 600 && pro== 0)
   {
      digitalWrite(LED, HIGH);
   }

   if(pro== 1 && level< 600 && door== 1)    //Person leaving without flush
   {
    lcd.print("PLEASE FLUSH!");
     digitalWrite(Buzz, HIGH);
     
   }

   else if(pro== 1 && level> 600) //No one inside+ Non- functional 
   {
    lcd.print("NON- FUNCTIONAL");
    digitalWrite(LED, LOW);
   }
   
   else if(pro== 0 && level> 600 && door== 0) //Non- functional+ User entering
   {
    lcd.print("NON- FUNCTIONAL");
    digitalWrite(LED, LOW); 
   }

   else if(pro== 0&& level< 600 && door== 1)
  {
    digitalWrite(LED, HIGH)  ;
  }

   else if((pro== 1) && (level> 600) && (door== 1))//Non-functional+user on commode
  {
    digitalWrite(10,LOW);
    lcd.print("NON FUNCTIONAL");
  }
  
  else if((pro== 1) && (level> 600) && (door== 0))//Non-functional+user on commode before closing door
  {
    digitalWrite(10,LOW);
    lcd.print("NON FUNCTIONAL");
  }
   else if((pro== 0) && (level< 600) && (door== 0))//Commode in use
  {
    digitalWrite(10,LOW);
  }
   else if((pro== 1) && (level< 600) && (door== 0))//commode in use for tp
  {
    digitalWrite(10,LOW);
  }
    
}
