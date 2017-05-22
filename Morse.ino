//Inizializzazione pin
const int BuzzerPin = 8;   // Buzzer su pin 8
const int LedPin = 12;     // Led su pin 12
const int AnalogPin = 1;   // Input dello switch su pin analogico 1


void setup() {
  // Comandi eseguiti una volta sola all'inizio del programma
  pinMode(LedPin, OUTPUT);    //Imposto il pin del Led in uscita
  pinMode(BuzzerPin, OUTPUT); //Imposto il pin del Buzzer in uscita
}

void loop() {
  // Comandi eseguiti ripetutamente
  int valoreSwitch = 0;                  // Resetto la posizione dello switch
  valoreSwitch = analogRead(AnalogPin);  // Leggo la posizione dello switch dal pin analogico
  
  if (valoreSwitch < 1019) {    //Se lo switch è premuto, non passa corrente (valore registrato scende sotto la soglia)
    digitalWrite(LedPin, HIGH); // Accendiamo il led
    tone(BuzzerPin, 800);       // Riproduciamo il suono sul buzzer
  }
  else {  //Se lo switch non è premuto, passa corrente (valore registrato è sopra la soglia)
      digitalWrite(LedPin, LOW);  // Spegniamo il led
      noTone(BuzzerPin);          // Spegniamo il suono
    }

}
