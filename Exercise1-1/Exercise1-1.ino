const int RLED=9;  //9 번 핀을 사용하는 빨간색
const int GLED=10; //10 번 핀을 사용하는 초록색
const int BLED=11; //11 번 핀을 사용하는 파란색
const int TEMP=0; // 아날로그 입력 0 번 핀을 사용하는 온도 센서 TEMP 상수 정의const

void setup() {
  // put your setup code here, to run once:
  pinMode(RLED, OUTPUT); //RLED 를 출력으로 지정
  pinMode(GLED, OUTPUT); //GLED 를 출력으로 지정
  pinMode(BLED, OUTPUT); //BLED 를 출력으로 지정
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RLED, HIGH);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, LOW);
  delay(1000);
  digitalWrite(RLED, HIGH);
  digitalWrite(GLED, HIGH);
  digitalWrite(BLED, LOW);
  delay(1000);
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, HIGH);
  digitalWrite(BLED, LOW);
  delay(1000);
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, HIGH);
  digitalWrite(BLED, HIGH);
  delay(1000);
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, HIGH);
  delay(1000);
  digitalWrite(RLED, HIGH);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, HIGH);
}
