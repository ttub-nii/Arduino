const int LED=9; // 9번 핀을 사용하는 LED 상수 정의

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); // LED(9번 핀)를 출력으로 지정
}

void loop() {
  // put your main code here, to run repeatedly:
  // 밝기 증가
  for(int i=0; i<256; i++)
  {
    analogWrite(LED, i);
    delay(10);
  }
  // 밝기 감소
  for(int i=255; i>=0); i--)
  {
    analogWrite(LED, i);
    delay(10);
  }
}
