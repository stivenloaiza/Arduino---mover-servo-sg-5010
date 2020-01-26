#include <Servo.h>
Servo servoTrizio; 
int pos = 0; 
byte cmd=0;
boolean onoff=false;
void setup()
{
  servoTrizio.attach(9);
  Serial.begin(9600); 
  servoTrizio.write(0);
  Serial.println("Configurado...");
}
void loop()
{

  Serial.println("Ingrese Estado: ");
  cmd= Serial.read();
  
  switch (cmd) 
  {
    case '0': //apagado
    Serial.println("Servo Apagado");
    onoff=false;
    servoTrizio.write(0);
    break;
    
    case '1': //prendido
    onoff=true;
    break;
    
  } //fin de switch


  if(onoff)
  {
    Serial.println("Servo prendido");
    // Desplazamos a la posición 0º
    servoTrizio.write(0);
    Serial.println("Posicion 0");
    // Esperamos 1 segundo
    delay(1000);
    // Desplazamos a la posición 90º
    servoTrizio.write(180);
    Serial.println("Posicion 180");
    // Esperamos 1 segundo
    delay(1000);
    onoff=false;
    servoTrizio.write(0);
    Serial.println("Posicion 0");
  }
  
}
