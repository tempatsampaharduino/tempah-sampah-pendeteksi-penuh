const int trigPin = 2;
const int echoPin = 3;

long durasi;
float jarak;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  durasi = pulseIn(echoPin, HIGH, 30000);

  if (durasi == 0) {
    Serial.println("Sensor tidak membaca jarak");
  } else {
    jarak = durasi * 0.0343 / 2;

    Serial.print("Jarak sampah: ");
    Serial.print(jarak);
    Serial.println(" cm");

    if (jarak <= 5) {
      Serial.println("TEMPAT SAMPAH PENUH!");
    } else {
      Serial.println("TEMPAT SAMPAH BELUM PENUH");
    }
  }

  delay(1000);
}