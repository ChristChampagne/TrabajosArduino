
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <MySQL_Encrypt_Sha1.h>
#include <MySQL_Packet.h>

#include <SPI.h>
#include <Ethernet.h>

 int sensor3 = 6;
 int sensor1 = 7;
 int sensor2 = 8; 

byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // Dirección MAC de Ethernet
IPAddress server_addr(92, 249, 45, 155); // IP del servidor MySQL
char user[] = "u646610080_rodriguezchris";              // nombre de usuario MySQL
char password[] = "Utd_2020"; // password del usuario MySQL
// Prepara la trama para la consulta SQL


char consulta[128];
EthernetClient client;  //Crea cliente Ethernet
MySQL_Connection conn((Client *)&client);  //Asocia el cliente al conector MySQL



void setup() {


  
   pinMode(sensor1,INPUT);
   pinMode(sensor2,INPUT);
   pinMode(sensor3,INPUT);
  Serial.begin(115200);
  while (!Serial); // Espera que esté libre el puerto serie
  Ethernet.begin(mac_addr); // Inicia la conexión con el router para recibir una IP por DHCP
  Serial.print("  IP asignada por DHCP: ");
  Serial.println(Ethernet.localIP());  //Muestra la IP asignada a la shield Ethernet de Arduino
  Serial.println("Conectando...");
  delay(1000);
  if (conn.connect(server_addr, 3306, user, password)) {
    delay(1000); //Se conecta al servidor MyQL por el puerto 3306 mediante el usuario indicado
  }
  else{
    Serial.println("Connection failed.");
  }

}

void loop() {






  
  if(digitalRead(sensor1) == LOW){

//    char MONEDA1[] = "INSERT INTO  u646610080_rodriguezchris.prueba_integradora (descripcion,valor) VALUES ('Moneda de 1 peso',1)";

  }
  

    if(digitalRead(sensor2) == LOW){


//    char MONEDA1[] = "INSERT INTO  u646610080_rodriguezchris.prueba_integradora (descripcion,valor) VALUES ('Moneda de 5 pesos',5)";

    }

    if(digitalRead(sensor3)==LOW){

//    char MONEDA1[] = "INSERT INTO  u646610080_rodriguezchris.prueba_integradora (descripcion,valor) VALUES ('Moneda de 10 pesos',10)";

      
   }
  
  
}
