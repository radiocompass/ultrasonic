// Укажем, что к каким пинам подключено
int trigPin = 10; 
int echoPin = 11;  

void setup() { 
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
} 
 
void loop() {
  long duration;
  int distance;
  // для большей точности установим значение LOW на пине Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Теперь установим высокий уровень на пине Trig
  digitalWrite(trigPin, HIGH);
  // Подождем 10 μs
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Узнаем длительность высокого сигнала на пине Echo
  duration = pulseIn(echoPin, HIGH, 30000);
  // Рассчитаем расстояние
  distance = duration / 58;
  if (distance < 300 && distance > 0) {
    // Выведем значение в Serial Monitor
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(100);
}