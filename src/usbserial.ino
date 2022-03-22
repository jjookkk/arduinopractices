char character; // char 형 변수 선언 
void setup() // 초기화 
{ 
  Serial.begin(9600);  // 시리얼통신속도를 9600bps 로 설정 
  Serial.println("hello World.!");  // 시리얼모니터에 문자출력 (ln은 개행을 뜻함)
} 

void loop()  // 무한루프 
{   if (Serial.available())  // 시리얼 값을 입력 받았을 때 실행 
  {  
    character = Serial.read();  // 입력 받은 값을 변수에 저장 
    Serial.print(character);  // 변수를 시리얼모니터에 출력 
  } 
}