// 가변저항값 읽기

const int POT=0;  // 아날로그 입력 0번 핀을 사용하는 가변저항 POT 상수 정의
int val=0;  // 가변저항값을 저장하는 val 변수 선언

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(POT);
  Serial.println(val);
  delay(500);
}
