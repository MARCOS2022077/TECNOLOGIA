#include <SoftwareSerial.h>//para el bluetoo
SoftwareSerial miBT(8, 9);//se indica el tx rxt de los pines que van y tambien el nombre del bluetooo
#define salida 3 // se crea una variable
#define salida_2 4 // se crea una variable
#define outpin(pin) pinMode(pin,OUTPUT) // se define y se acorta una función
char Dato;//nos ayudaran a leer el dato que viene como caracter
bool estado = 0;
bool estado1=0;  

void setup(){ //inica el void setup
miBT.begin(9600);//se inicializa el bluetoo
Serial.begin(9600); //para el monitor serial.
outpin(salida);  //se declara que pin va a hacer
outpin(salida_2);  //se declara que pin va a hacer
} // se cierra el void setup


void loop(){ //inica el bucle
  if (miBT.available() > 0){//se indica lo que lleva la configuración del bluetoo
    Dato = miBT.read();//se indica que dato sea igual que lee el bluetoo
   Serial.println(Dato);// y que imprima el valor del dato

   if(Dato == 'S')//se dato es igual a el caracter A hace lo siguiente 
     foco();

    if(Dato == 'P')//se dato es igual a el caracter A hace lo siguiente 
     foco_2();

  }
}//finaliza  el programa. 
void foco(){
   estado=!estado;// para apagar y encender con el mismo boton
   digitalWrite(salida, estado);

}
void foco_2(){
    estado1=!estado1;// para apagar y encender con el mismo boton
    digitalWrite(salida, estado1);
}

