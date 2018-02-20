# Semaforo
Semaforo para automóviles y peatones en arduino. 
[Descripción] 
Se desarrolló un semaforo vehicular y peatonal con ayuda de una placa de Arduino. 

[Requisitos]
  {Para armar el circuito}
    * 2 leds verdes 
    * 2 leds rojos 
    * 1 led amarillo 
    * Protoboard 
    * Push Button 
    * Cable 
    * Potenciometro 
    * 5 resistencias 330 ohms
  
  {Desarrollar}
    * 1 placa Arduino UNO (Recomendado)
    * Cable Usb A - Usb B 
    * Una computadora 
    * Arduino IDE 

[Procedimiento]
  {Circuito}
  Colcamos un led verde, amarillo y rojo, en fila, en orden. 
  En la parte negativa de cada led conectamos un cable que lleve a tierra en la protoboard, en la parte positiva 
  conectamos las resistencias de 330 ohms, seguido de las resistencias conectamos cable macho-macho que irán di-
  recto a la placa de arduino. Los conectaremos como corresponden en el código que se encuentra en este reposito
  rio. 
  
  En otro punto de la protoboard conectamos el led verde y rojo restante, hacemos el mismo procedimiento que con
  los otros leds. Después conectamos el push button, una pata del mismo irá a tierra, la cual conectaremos con un
  cable, la otra patita ira al arduino. 
  
  Seguido conectamos el potenciometro. La patita izquiera se conecta a tierra, la derecha a vcc y la patita de en
  medio irá all arduino. 
  
  {Código}
  El codigo está en este repositorio comentando y explicando su funcinamiento lo más detallado posible. 
  
  [Autor] 
    Isabel Guadalupe Rocha Ramírez 
  
  [Expresiones de gratitud]
    Este proeyecto quiero agradecer a mi profesor de la materia Sistemas 
    Programables Ing. Levy Rojas Carlos Rafael
  

