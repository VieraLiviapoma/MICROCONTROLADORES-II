//ESTE PROGRAMA CONTROLA LA VELOCIDAD DEL MOTOR.

//HOLA VIERA

const int LED = 10;
byte intensidad;  // Porcentaje de 0 a 100

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  // Si llega un nuevo dato por Serial
  if (Serial.available() > 0) {
    int valor = Serial.parseInt();  // Lee el número

    // Validar rango
    if (valor >= 0 && valor <= 100) {
      intensidad = map(valor, 0, 100, 0, 255); // Convertir a 0–255
      Serial.print("PWM actualizado a: ");
      Serial.print(valor);
      Serial.println("%");
    } else {
      Serial.println("Valor fuera de rango (0-100).");
    }
  }

  // Aplicar siempre el último valor al PWM
  analogWrite(LED, intensidad);

  delay(10); // Delay corto para evitar sobrecargar el loop
}
