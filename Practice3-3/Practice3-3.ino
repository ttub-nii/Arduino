// 자동 야간 조명 프로그램

const int RLED=9; // 9번 핀을 사용하는 빨간색 RLED
const int LIGHT=0;  // 아날로그 입력 0번 핀을 사용하는 포토레지스터
const int MIN_LIGHT=200;  // 최저 조도값
const int MAX_LIGHT=900;  // 최대 조도값

int val=0;  // 포토레지스터가 읽은 현재 조도값

void setup() {
  // put your setup code here, to run once:
  pinMode(RLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(LIGHT);  // 포토레지스터에서 현재 조도값 읽음
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0); // 현재 조도값을 8비트의 값으로 매핑
  val = constrain(val, 0, 255); // 매핑된 조도값을 0~255 사이의 값
  analogWrite(RLED, val); // 조도값에 따라 LED 밝기 조정
}
