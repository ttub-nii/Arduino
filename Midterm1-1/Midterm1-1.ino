// 학적: 2017110059 디지털미디어학과 황수빈
// 프로그램 설명: 생활 공간의 습도와 조도에 따라 3색 LED로 측정치 표시하기

#include <SimpleDHT.h>

int cds = A0;     // 조도센서
int pinDHT11 = 2; // 온습도센서
int RLED=9;       // 9 번 핀을 사용하는 빨간색
int GLED=10;      // 10 번 핀을 사용하는 초록색
int BLED=11;      // 11 번 핀을 사용하는 파란색
SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(9600);    // 시리얼 통신을 설정 (전송 속도 9600bps)
  pinMode(RLED, OUTPUT); // RLED 를 출력으로 지정
  pinMode(GLED, OUTPUT); // GLED 를 출력으로 지정
  pinMode(BLED, OUTPUT); // BLED 를 출력으로 지정
}

void loop() {
  // start working...
  Serial.println("====== Detecting Now ======");

  // 1. 조도 센서 값 측정 
  int cdsValue = analogRead(cds);
  
  // 2. 온습도 센서 값 측정 
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err); delay(1000);
    return;
  }

  // 3. map함수와 constrain을 사용하여 조도센서의 밝기 범위를 0~1023에서 0~255로 변경
  cdsValue = map(cdsValue, 0, 1023, 0, 255);
  cdsValue = constrain(cdsValue, 0, 255);

  Serial.print((int)humidity); Serial.println(" H");
  Serial.print("cds = "); Serial.println(cdsValue);

  // 4. 3색 LED를 사용하여 각각의 단계에 해당하는 색깔을 표시
  /* 측정 기준, 
      평균 습도: 53도 ~ 60도
      평균 조도: 170 ~ 185

      R: 습도가 높음. 습함.
      G: 조도가 낮음. 어두움.
      B: 둘 값 모두 평균
  */

  if (((int)humidity >= 53 && (int)humidity <= 60) && (cdsValue >= 170 && cdsValue <= 185)) {
    analogWrite(BLED,cdsValue);
    digitalWrite(RLED,LOW);
    digitalWrite(GLED,LOW);
  }else if ((int)humidity > 70) {
    analogWrite(RLED,cdsValue);
    digitalWrite(BLED, LOW);
    digitalWrite(GLED, LOW);
  }else if (cdsValue < 100) {
    analogWrite(GLED,cdsValue);
    digitalWrite(BLED, LOW);
    digitalWrite(RLED, LOW);
  }

  // DHT11 sampling rate is 1HZ.
  delay(1500);
}
