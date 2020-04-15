const int LED=9;  // 9번 핀을 사용하는 LED 상수 정의
const int BUTTON=2; // 버튼을 2번 핀에 지정

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); // LED(9번 핀)를 출력으로 지정
  pinMode(BUTTON, INPUT); // BUTTON(2번 핀)을 입력으로 지정
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BUTTON) == LOW)
  {
    digitalWrite(LED, LOW);
  }
  else
  {
    digitalWrite(LED, HIGH);
  }
}
