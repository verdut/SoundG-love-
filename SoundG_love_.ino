#include "DFRobotDFPlayerMini.h"
#include "Arduino.h"
#include "SoftwareSerial.h"


#define BUTTON 7   //butonul care schimba din pian in chitara si invers
#define S1 2       //senzorii de atingere
#define S2 3 
#define S3 19
#define S4 20
#define S5 21



SoftwareSerial mySoftwareSerial(50, 51); // RX, TX ; este nevoie de un serial software pentru a realiza comunicarea intre Arduino si modulul mp3
DFRobotDFPlayerMini myDFPlayer;          //instantierea unui obiect de tipul modulului mp3;





int flexSensor1,flexSensor2, flexSensor3, flexSensor4, flexSensor5;   //senzorii flex
int action=0;                                                         //cantecul care trebuie cantat
int buttonState=0;                                                    //variabila de control pentru buton
boolean isSinging=false;                                              //variabila de control pentru modul mp3
boolean isGuitar=false;                                               //instrumentul activ


void tone1()     //alegerea tonurilor pentru degetul 1
{  
  
 if (flexSensor1==1)
   {  
      
     if(isSinging==false)
       {  
        isSinging=true;
         
        if(isGuitar==true) 
          action=1;             //myDFPlayer.play(1);
            else action=16;    //myDFPlayer.play(16); 

           
        }       
   }
    else if (flexSensor1==2)
    {  
      if(isSinging==false)
           {  
            isSinging=true;

            if(isGuitar==true) 
              action=2;           //myDFPlayer.play(2);
                else action=17;   //myDFPlayer.play(17); 
            }     

       }
    else if (flexSensor1==3)
    {   
      if(isSinging==false)
           {  
            isSinging=true;

            if(isGuitar==true) 
              action=3;           //myDFPlayer.play(3);
                else action=18;   //myDFPlayer.play(18); 
            }     

       }
  else
  {
      if(isSinging==false)
         {  
          isSinging=true;

          if(isGuitar==true) 
            action=1;           //myDFPlayer.play(1);
              else action=16;  //myDFPlayer.play(16); 
          }    

     }

   
}


void tone2()                 //alegerea tonurilor pentru degetul 2
{
  
 if (flexSensor2==1)
   {
    if(isSinging==false)
       {  
        isSinging=true;

        if(isGuitar==true) 
          action=4;           //myDFPlayer.play(4);
            else action=19;   //myDFPlayer.play(19); 
        }    
    
    }
  else if (flexSensor2==2)
  {
    if(isSinging==false)
         {  
          isSinging=true;

          if(isGuitar==true) 
            action=5;               //myDFPlayer.play(5);
              else action=20;       //myDFPlayer.play(20); 
          }    
    }
  else if (flexSensor2==3)
  {
    if(isSinging==false)
         {  
          isSinging=true;

          if(isGuitar==true) 
            action=6;             //myDFPlayer.play(6);
              else action=21;     //myDFPlayer.play(21); 
          }   
    }
  else
  {
    if(isSinging==false)
         {  
          isSinging=true;

          if(isGuitar==true) 
            action=4 ;          //myDFPlayer.play(4);
              else action=19;   //myDFPlayer.play(19); 
          }    
    }
  
}

void tone3()       //alegerea tonurilor pentru degetul 3
{
if (flexSensor3==1)
   {
    if(isSinging==false)
       {  
        isSinging=true;

        if(isGuitar==true) 
          action=7;               //myDFPlayer.play(7);
            else action=22;       //myDFPlayer.play(22); 
        }   
    }
else if (flexSensor3==2)
{
  if(isSinging==false)
       {  
        isSinging=true;

        if(isGuitar==true) 
          action=8;                 //myDFPlayer.play(8);
            else action=23;         //myDFPlayer.play(23);
        }    
  }
    else if (flexSensor3==3)
    {
      if(isSinging==false)
           {  
            isSinging=true;

            if(isGuitar==true) 
              action=9;                 //myDFPlayer.play(9);
                else action=24;         //myDFPlayer.play(24);
            }    
      }
    else
    {
      if(isSinging==false)
           {  
            isSinging=true;

            if(isGuitar==true) 
              action=7;             //myDFPlayer.play(7);
                else action=22;     //myDFPlayer.play(22); 
            }    
      }
}



void tone4()                        //alegerea tonurilor pentru degetul 4
{

  if (flexSensor4==1)
   {
      if(isSinging==false)
         {  
          isSinging=true;

          if(isGuitar==true) 
            action=10;                //myDFPlayer.play(10);
              else action=25;         //myDFPlayer.play(25); 
          }    
      }
      else if (flexSensor4==2)
      {
        if(isSinging==false)
             {  
              isSinging=true;

              if(isGuitar==true) 
                action=11;              //myDFPlayer.play(11);
                  else action=26;       //myDFPlayer.play(26); 
              }    
        }
      else if (flexSensor4==3)
      {
        if(isSinging==false)
             {  
              isSinging=true;

              if(isGuitar==true) 
                action=12;              //myDFPlayer.play(12);
                  else action=27;         //myDFPlayer.play(27); 
              }   
        }
      else
      {
        if(isSinging==false)
             {  
              isSinging=true;

              if(isGuitar==true) 
                action=10;                //myDFPlayer.play(10);
                  else action=25;         //myDFPlayer.play(25); 
              }    
        }
}



void tone5()                              //alegerea tonurilor pentru degetul 5
{
      if (flexSensor5==1)
         {
          if(isSinging==false)
             {  
              isSinging=true;

              if(isGuitar==true) 
                action=13;            //myDFPlayer.play(13);
                  else action=28;     //myDFPlayer.play(28); 
              }  
          }
        else if (flexSensor5==2)
        {
          if(isSinging==false)
               {  
                isSinging=true;

                if(isGuitar==true) 
                  action=14;              //myDFPlayer.play(14);
                    else action=29;       //myDFPlayer.play(29); 
                }     
          }
        else if (flexSensor5==3)
        {
          if(isSinging==false)
               {  
                isSinging=true;

                if(isGuitar==true) 
                  action=15;                //myDFPlayer.play(15);
                    else action=30;         //myDFPlayer.play(30); 
                }     
          }
          else
          {
            if(isSinging==false)
                 {  
                  isSinging=true;

                  if(isGuitar==true) 
                    action=13;              //myDFPlayer.play(13);
                      else action=28;       //myDFPlayer.play(28); 
                  }    
            }
}




void setup() {
 
 isSinging=false;
 
 mySoftwareSerial.begin(9600);   //pornirea serialului software
  
  Serial.begin(115200);


  pinMode(S1, INPUT_PULLUP);      //setarea pinilor de intrerupere pentru senzori
  pinMode(S2, INPUT_PULLUP);
  pinMode(S3, INPUT_PULLUP);
  pinMode(S4, INPUT_PULLUP);
  pinMode(S5, INPUT_PULLUP);

  pinMode(BUTTON, INPUT);          //setarea butonul de schimbare instrument
  
  attachInterrupt(digitalPinToInterrupt(S1), tone1, LOW);     //maparea pinilor de intrerupere cu subprogramele respective senzorilor
  attachInterrupt(digitalPinToInterrupt(S2), tone2, LOW);
  attachInterrupt(digitalPinToInterrupt(S3), tone3, LOW);
  attachInterrupt(digitalPinToInterrupt(S4), tone4, LOW);
  attachInterrupt(digitalPinToInterrupt(S5), tone5, LOW);
 
  
  //verificarea modulului mp3
  
  Serial.println(" ");
  Serial.println("DFRobot DFPlayer Mini Demo");
  Serial.println("Initializing DFPlayer ... (May take 3~5 seconds)");


      
   myDFPlayer.begin(mySoftwareSerial);   //pornirea comunicarii serialului software

  
  myDFPlayer.setTimeOut(20);            //timeOut pentru modulul mp3, expirarea asteptarii pentru o noua comanda.
  myDFPlayer.volume(29);               //Set volume value. From 0 to 30; volumul modului mp3
 
  

}

void loop() {
  

  buttonState=digitalRead(BUTTON);             //verificarea butonului

  if(buttonState==HIGH) isGuitar=!isGuitar;   //schimbarea instrumentului.

  
  flexSensor1 = map(analogRead(A5),780,880,1,3);      //maparea senzorilor flex
  flexSensor2 = map(analogRead(A6),796,855,1,3); 
  flexSensor3 = map(analogRead(A7),830,910,1,3); 
  flexSensor4 = map(analogRead(A10),810,920,1,3);
  flexSensor5 = map(analogRead(A9),800,890,1,3); 


  
     
   if(action!=0)
    {
      myDFPlayer.play( action );   //cantarea tonului ales de deget;
      action=0;                    //resetarea tonului
    }

    if( isSinging==true )
     {  
      isSinging=false;      //variabila de control. Sensorii sunt foarte sensibili si modulul mp3 da crash repede. 
     }
    
     
     
  }






