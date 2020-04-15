const int LED=9; // 9번 핀을 사용하는 LED 상수 정의
const int BUTTON=2; // 버튼을 2번 핀에 지정

boolean lastButton=LOW; // 이전 버튼의 눌림 상태
boolean currentButton=LOW;  // 현재 버튼의 눌림 상태
boolean ledOn=false;  // 현재 LED의 점멸 상태

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT); // BUTTON(2번 핀)을 입력으로 지정
}

/*
 * 스위치 디바운싱 함수
 * debounce() 함수에 이전 버튼 상태를 인수로 사용하여 디바운싱 처리된 현재 버튼 상태값을 반환
 */
boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);  // 현재 버튼 상태를 확인
  if(last!= current)  // 이전 버튼 상태와 다르냐? 달라야지만 동작.
  {
    delay(5);
    current = digitalRead(BUTTON);  // current에 현재 버튼 상태를 저장
  }
  return current; // current 변수 값을 반환
}const int LED=9; // 9번 핀을 사용하는 LED 상수 정의
const int BUTTON=2; // 버튼을 2번 핀에 지정

boolean lastButton=LOW; // 이전 버튼의 눌림 상태
boolean currentButton=LOW;  // 현재 버튼의 눌림 상태
boolean ledOn=false;  // 현재 LED의 점멸 상태

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT); // BUTTON(2번 핀)을 입력으로 지정
}

/*
 * 스위치 디바운싱 함수
 * debounce() 함수에 이전 버튼 상태를 인수로 사용하여 디바운싱 처리된 현재 버튼 상태값을 반환
 */
boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);  // 현재 버튼 상태를 확인
  if(last!= current)  // 이전 버튼 상태와 다르냐? 달라야지만 동작.
  {
    delay(5);
    current = digitalRead(BUTTON);  // current에 현재 버튼 상태를 저장
  }
  return current; // current 변수 값을 반환
}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton = debounce(lastButton); // 디바운싱 처리된 버튼 값을 읽음
  if(lastButton == LOW && currentButton == HIGH)  // 버튼을 누름
  {
    ledMode++;  // LED 모드값 증가
  }
  lastButton = currentButton; // 이전 버튼 값을 현재 버튼 값으로 변경
  if(ledMode == 8) ledMode = 0; // ledMode 변수 값이 8이면 0으로 리셋
  setMode(ledMode); // LED 모드 값을 다시 바꿈
}
