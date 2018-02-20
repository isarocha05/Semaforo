/*
Fecha: Martes 20 de Febrero de 2018
Nombre: Isabel Guadalupe Rocha Ramirez. 
No. Control: 14240260
Descripción: Realizar un semaforo para automoviles y peatones.
*/
int Verde_Auto = 13; //El led verde del semaforo de automoviles se conecta en el pin 13 de la placa de arduino.
int Amarillo_Auto = 12; //El led amarilo del semaforo de automoviles se conecta en el pin 12 de la placa de arduino.
int Rojo_Auto = 11; //El led rojo del semaforo de automoviles se conecta en el pin 11 de la placa de arduino.
int Verde_Peaton = 10; //El led verde del semaforo de peatones se conecta en el pin 10 de la placa de arduino.
int Rojo_Peaton = 9; //El led rojo del semaforo de automoviles se conecta en el pin 9 de la placa de arduino.
int btn = 8; //El botón que permite el cambio de semaforo se conecta en el pin 8 de la placa de arduino.
int tiempo_minimo_verde_auto = 7000; //tiempo minimo del led en verde del semaforo del automoviles
 
void semaforo_inicia(void) {
   digitalWrite(Verde_Auto, HIGH); //Encendemos el led verde 
   digitalWrite(Rojo_Auto, LOW); //El led rojo se queda apagado 
   digitalWrite(Amarillo_Auto, LOW); //El led amarillo se queda apagado
 
   // Enciende el led rojo para peatones. Apaga los demás leds
   digitalWrite(Rojo_Peaton, HIGH);
   digitalWrite(Verde_Peaton, LOW);
}
 
 
/*Este metodo cambia el semaforo de automoviles a rojo*/
void semaforo_auto_rojo(void) {
   
   digitalWrite(Verde_Auto,  LOW); //El led verde se apaga 
 
   //Ciclo for para encender y apagar el led amarillo 3 veces.
   for(int i=4; i>0; i--) {
      delay(500); //Está apagado por 5 segundos. 
      digitalWrite(Amarillo_Auto, HIGH); //El led amarillo se prende.
      delay(500); //Se enciende por 5 segundos.
      digitalWrite(Amarillo_Auto, LOW); //El led amarillo se apaga.
   }
 
   
   digitalWrite(Rojo_Auto, HIGH); //Se enciende el led rojo del semaforo de automoviles. 
}
 

void semaforo_espera_btn(void) {
   int estado;
   long time;
   
   time = millis() + tiempo_minimo_verde_auto; 
   estado = 0;
   while(1) {
      // Lee el estado del pulsador
      if (digitalRead(btn) == LOW) //si el boton es presionado el valor de presionado cambia a 1.
         estado = 1;
      // Si ha pasado el tiempo de verde para coches
      // y se ha presionado el pulsador, salir
      if ((millis() > time) && (estado == 1))
         break;
   }
}
 
 
/*Espera x tiempo, x --> Depende del potenciometro.*/
void semaforo_delay(void) {
   int tiempo_peatones;
   tiempo_peatones =  analogRead(A0); //Se incializa el potenciometro que está conectado al pin A0 de la placa de arduino y toma el valor del mismo. 
   tiempo_peatones = tiempo_peatones * 10; //El valor del mismo lo multiplica por 10 qué es la capacidad del potenciometro.
   
   // Envía por el puerto serie el tiempo de espera
   //Serial.print("Tiempo peatones="); 
   //Serial.println(tiempo_peatones);
   delay(tiempo_peatones); //Se toma el tiempo de espera
}
 

/*Método para cambiar a rojo el semaforo de peatones*/
void semaforo_peatones_rojo(void) {
 
   //For para que el led verde parpadee 3 veces
   for(int i=3; i>0; i--) {
      digitalWrite(Verde_Peaton, LOW); //El led se apaga 
      delay(500); //Se espera .5 segundos. 
      digitalWrite(Verde_Peaton, HIGH); //El led se prende 
      delay(500); //Se espera .5 segundos. 
   }

   //Terminando de parpadear el led verde se apaga y el led rojo se enciende
   digitalWrite(Verde_Peaton, LOW);
   digitalWrite(Rojo_Peaton, HIGH);
}
 
 
void setup() {
   /*Definimos las salidas*/
   pinMode(Verde_Auto, OUTPUT);
   pinMode(Amarillo_Auto, OUTPUT);
   pinMode(Rojo_Auto, OUTPUT);
   pinMode(Verde_Peaton, OUTPUT);
   pinMode(Rojo_Peaton, OUTPUT);
 
   /*Definimos las entradas*/
   pinMode(btn, INPUT_PULLUP); //Potenciometro.
   
   Serial.begin(9600);
   Serial.println("Semaforo en marcha");
}
 
void loop() {
   
   //Llamamos al metodo que inicia el semaforo
   semaforo_inicia();
   
   //Llamamos al metodo y checamos si se pulso el boton
   semaforo_espera_btn();
   
   //Cambiamos el semaforo de autos a rojo
   semaforo_auto_rojo();
 
   // Espera antes de permitir paso a peatones
   delay(1500);
 
   // Enciende el led verde para peatones
   digitalWrite(Rojo_Peaton, LOW);
   digitalWrite(Verde_Peaton, HIGH);
 
   // Espera el tiempo que le de el potenciometro
   semaforo_delay();
 
   // Cambia el semáforo de peatones a rojo
   semaforo_peatones_rojo();
 
   // Espera 2 segundos.
   delay(2000);
}


