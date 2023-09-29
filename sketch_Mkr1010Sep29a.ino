const int ledPin = 13; // Broche de la LED
int sensorPin = A6;  // Broche analogique où le capteur d'humidité est connecté
int sensorValue = 0;

void setup() {
  Serial.begin(9600); // Initialisation du port série
  pinMode(ledPin, OUTPUT); // Configuration de la broche de la LED en sortie
  delay(2000);  // Attendez quelques secondes que le port série se connecte
}

void loop() {
  // Mesure de l'humidité du sol
  sensorValue = analogRead(sensorPin);

  // Envoi de la valeur de l'humidité du sol via le port série
  Serial.print("Humidité du sol : ");
  Serial.print(sensorValue);
  Serial.println("%");

  // Attendez quelques secondes avant la prochaine mesure
  delay(5000);

  // -------- Le bouton ON et OFF --------
  
  if (Serial.available() > 0) {
    char command = Serial.read(); // Lecture de la commande série

    // Si la commande est '1', allume la LED
    if (command == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED allumée");
    }
    // Si la commande est '0', éteint la LED
    else if (command == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED éteinte");
    }
  }
}
