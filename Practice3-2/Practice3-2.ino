// 온도 경보 장치 프로그램

const int BLED=9; // 9번 핀을 사용하는 파란색 BLED 상수 정의
const int GLED=10;  // 10번 핀을 사용하는 초록색 GLED 상수 정의
const int RLED=11;  // 11번 핀을 사용하는 빨간색 RLED 상수 정의
const int TEMP=0; // 아날로그 입력 0번 핀을 사용하는 온도 센서 TEMP 상수 정의

const int LOWER_BOUND=139;  // 온도 하한값을 정의
const int UPPER_BOUND=147;  // 온도 상한값을 정의

int val=0;  // 온도 센서의 현재값을 저장

void setup() {
  // put your setup code here, to run once:
  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(TEMP);
  if(val < LOWER_BOUND)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
  else if(val > UPPER_BOUND)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
  else
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
}
