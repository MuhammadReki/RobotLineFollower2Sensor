/*
 * Robot Penghindar Halangan / Line Follower 2 Sensor IR dengan L298N
 * Arah motor dibalik
 */

void setup() {

  // Sensor
  pinMode(2, INPUT); // IR kiri
  pinMode(3, INPUT); // IR kanan

  // Enable motor
  pinMode(8, OUTPUT); // ENA
  pinMode(9, OUTPUT); // ENB

  // Kontrol motor
  pinMode(10, OUTPUT); // IN4
  pinMode(11, OUTPUT); // IN3
  pinMode(12, OUTPUT); // IN2
  pinMode(13, OUTPUT); // IN1

  // Kecepatan motor
  analogWrite(8, 128);
  analogWrite(9, 120);
}

void loop() {

  int kiri = digitalRead(2);
  int kanan = digitalRead(3);

  // MUNDUR (dari MAJU)
  if (kiri == 1 && kanan == 1) {

    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);

    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }

  // BELOK KIRI (dari BELOK KANAN)
  else if (kiri == 1 && kanan == 0) {

    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);

    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }

  // BELOK KANAN (dari BELOK KIRI)
  else if (kiri == 0 && kanan == 1) {

    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);

    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
  }

  // STOP tetap
  else {

    digitalWrite(13, LOW);
    digitalWrite(12, LOW);

    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }

  delay(5);
}