
int seg[] ={7,8,2,3,4,6,5,9};

int patterns[] = {
  0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6
};

void setup() {
  for (int i = 0; i < 8; i++) { // 세그먼트 제어 핀을 출력으로 설정
    pinMode(seg[i], OUTPUT);
  }
}
void show_digit(int number) { // ( 출력할 숫자)
  for (int i = 0; i < 8; i++) {
    boolean on_off = bitRead(patterns[number], 7 - i);
    digitalWrite(seg[i], on_off);
  }
}
void show_jjum(int i){
     if(i <=3){
            digitalWrite(seg[7],HIGH);
        }
}

void loop(){
    for(int i=0;i<10;i++){
        show_digit(i);
        show_jjum(i);
        delay(500);
    }
}

// byte digits_data[10]={ 0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};

// void setup(){
//     // for(int i=0;i<2;i++)
//     // {
//     //     pinMode(digit_select_pin[i],OUTPUT);
//     // }
//     for(int i=0;i<8;i++){
//         pinMode(seg[i],OUTPUT);
//     }
// }
// void show_digit(int pos,int number){
//     // for(int i=0;i<2;i++){
//     //     if(i==pos)
//     //     digitalWrite(digit_select_pin[i],LOW);
//     //     else
//     //     digitalWrite(digit_select_pin[i],HIGH);
//     // }
//     for(int i = 0; i < 7; i++){
//     byte segment_data = (digits_data[number] 
//          & (0x01 << i)) >> i;
//     if(segment_data == 1)
//       digitalWrite(seg[7-i], HIGH);
//     else
//       digitalWrite(seg[7-i], LOW);
//   }
// } 
// void loop(){
//     for(int i=0;i<10;i++)
//     {
//         d1=i;
//         for(int j=0;j<10;j++)
//         {
//             show_digit(1,d1);
//             delay(time_delay);
//         }
//     }
// }