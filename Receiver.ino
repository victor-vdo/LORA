#include <SPI.h>
#include <LoRa.h> 
int cont = 0; 
void setup() 
{ 
  Serial.begin(9600); 
  while (!Serial);
  Serial.println("Receptor LORA");

  if (!LoRa.begin(433E6))
  {
    Serial.println("Iniciação da LORA falhou!"); 
  }
   
}

void loop()
{
  // try to parse packet  
  int packetSize = LoRa.parsePacket(); 
  
  if (packetSize)
  {
    // received a packet
    Serial.println("Pacote Recebido ");
    Serial.print(cont);
    cont++;

    // read packet
    while (LoRa.available())
    {
       Serial.print((char)LoRa.read());
    }
  }
}
