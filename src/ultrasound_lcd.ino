#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD의 address 주소 및 크기 입력

#define echo 6 //초음파 센서 모듈 에코(Echo) 핀, 아두이노 우노 R3의 디지털 6번 핀 연결
#define trig 7 //초음파 센서 모듈 트리거(Trigger) 핀, 아두이노 우노 R3의 디지털 7번 핀 연결

void setup() //초기화
{
  Serial.begin(9600);  //통신속도설정 9600bps
  pinMode(trig, OUTPUT); // trig 핀 출력 설정
  pinMode(echo, INPUT);  // echo 핀 입력 설정
  lcd.init();  // LCD 초기화
  lcd.backlight();
}

int read_ultrasonic(void)  // 초음파 센서 모듈 값 읽어오는 함수
{
  float return_time, howlong;  // 시간 값과 거리 값을 저장하는 변수를 만든다.
  // 초움파 센서 모듈은 초음파를 발사 후 돌아오는 시간을 역산하여 거리 값으로 계산한다.
  digitalWrite(trig, HIGH);  // 초음파 발사
  delay(5);  // 0.05초간 지연
  digitalWrite(trig, LOW);  // 초음파 발사 정지
  return_time = pulseIn(echo, HIGH);  // 돌아오는 시간
  howlong = ((float)(340*return_time) / 10000) /2;  // 시간을 거리로 계산
  return howlong;   // 거리 값 리턴
}

void loop()  // 무한루프
{
  Serial.print(" Check the value ! " );  //시리얼모니터에 "Check the value ! " 출력
  Serial.print( read_ultrasonic());  // 초음파 센서 모듈 거리계산 함수 실행
  delay(500); // 0.5초간 지연

  lcd.setCursor(0, 0); // 커서 첫번째칸 첫번재줄 위치
  lcd.print(read_ultrasonic());  // Welcome to 문자 출력
} 



