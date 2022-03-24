#include <IRremote.h>


int RECV_PIN = 11; // IR 수신센서
int LED1_PIN =2;
int LED2_PIN=4;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() // 초기화
{
  Serial.begin(9600); // 시리얼통신 사용, 통신 보레이트 9600bps 설정
  irrecv.enableIRIn(); // 수신센서 감지 시작(Start the receiver)
  pinMode(RECV_PIN,INPUT);
  pinMode(LED1_PIN,OUTPUT);
  pinMode(LED2_PIN,OUTPUT);
}
/*
  IR리모콘 버튼을 누르면 적외선 신호가 IR 리모콘 수신센서가 감지하며,
  수신 된 데이터 값을 분석 한 후, 수신값을 시리얼통신을 이용하여 전송하여 PC에서 확인 하도록 한다.
*/
void loop() // 무한루프
{
    if (irrecv.decode(&results)) {
        if (results.decode_type == NEC) { 
            if(results.value ==0x00FF6897)
            {
                Serial.println("Press '0'"); // 시리얼통신으로 데이터 출력 "Press '0'"
                digitalWrite(LED1_PIN,HIGH);
                delay(300);
             }
            if(results.value ==0x00FF30CF)
            {
                Serial.println("Press '1'"); // 시리얼통신으로 데이터 출력 "Press '0'"
                digitalWrite(LED2_PIN,HIGH);
                delay(300);
            }else 
    irrecv.resume();  // 다음 값 수신(Receive the next value)
  }
  digitalWrite(LED1_PIN,LOW); 
  digitalWrite(LED2_PIN,LOW);
}
}
