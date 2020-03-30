const int LED=9; //9 번 핀을 사용하는 LED 상수 정의

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); //LED 9번을 출력으로 지정
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i =100; i <=1000; i =i+100){
    digitalWrite(LED, HIGH);
    delay(i);
    digitalWrite(LED, LOW);
    delay(i);
  }
}
