
char character;
void call_A()
{
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(100); 
}
void call_SOS()
{
    for(int i=0;i<3;i++){
    digitalWrite(LED_BUILTIN, HIGH);   
    delay(500);                      
    digitalWrite(LED_BUILTIN, LOW);    
    delay(500);
   }
     for(int i=0;i<3;i++){
    digitalWrite(LED_BUILTIN, HIGH);   
    delay(1000);                      
    digitalWrite(LED_BUILTIN, LOW);    
    delay(1000);
   }
     for(int i=0;i<3;i++){
    digitalWrite(LED_BUILTIN, HIGH);   
    delay(500);                      
    digitalWrite(LED_BUILTIN, LOW);    
    delay(500);
   }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("helloworld");
}
void loop()
{
    while(1){
    if(Serial.available())
    {
        character = Serial.read();  // 입력 받은 값을 변수에 저장 
	    if(character=='a')
        {
            call_A();
        }
      else if(character=='s')
        {
            call_SOS();
        }
        Serial.print(character); 
    }
    }
    
}
