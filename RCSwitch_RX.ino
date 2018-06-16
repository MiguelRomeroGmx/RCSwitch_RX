/*
codigo creado por ing edison viveros
  funciona muy bien el codigo
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // pin #2 de arduino como RX
}

void loop()
{
  if (mySwitch.available())
  {
    long  int value = mySwitch.getReceivedValue();//en la libreria viene int
    if (value == 0) 
    {
      Serial.println("error de codigo");
    } 
    else 
    {
      Serial.print("codigo Recibido: ");
      Serial.println(value);
     // Serial.println( mySwitch.getReceivedValue() );
      //////////compara dato recibido
      if(value == 956393)
        {
          digitalWrite(13,HIGH);
          Serial.println("Sensor de Presencia Activado");  //ENVIO AL PC EL CODIGO
           
        }
        //////////compara dato recibido
        if(value == 15442820)

        {
          digitalWrite(13,LOW);
          Serial.println("Desactivar Alarma");  //ENVIO AL PC EL CODIGO
        }
        ///////////////
        if(value == 4824046)//control remoto rojo
        {
          digitalWrite(13,HIGH);
          Serial.println("Puerta 1 Abierta");  //ENVIO AL PC EL CODIGO
        }
        if(value == 15442818)//apago led

        {
          digitalWrite(13,LOW);
          Serial.println("Activar Alarma");  //ENVIO AL PC EL CODIGO
        }
        
        if(value == 15442817)//apago led

        {
          digitalWrite(12,HIGH);
          Serial.println("Activar Alarma");  //ENVIO AL PC EL CODIGO
        }

        if(value == 15442824)//apago led

        {
          digitalWrite(12,LOW);
          Serial.println("Activar Alarma");  //ENVIO AL PC EL CODIGO
        }

        ///////////////
    }//else
    

    mySwitch.resetAvailable();
  }//if
}//void
