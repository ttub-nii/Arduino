#define buzzer_pin 10
#define switch1_pin 4
#define switch2_pin 5
#define switch3_pin 6
#define switch4_pin 7

#define do_4 262
#define re_4 294
#define mi_4 330
#define fa_4 349
#define sol_4 392
#define la_4 440
#define si_4 494
#define do_5 523

unsigned char sw = 0;

void play_scale(unsigned int scale, unsigned long push_sw) {
  tone(buzzer_pin, scale);
  while((digitalRead(switch1_pin) + (digitalRead(switch2_pin) << 1) + (digitalRead(switch3_pin) << 2) + (digitalRead(switch4_pin) << 3)) == push_sw);

  noTone(buzzer_pin);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(switch1_pin, INPUT);
  pinMode(switch2_pin, INPUT);
  pinMode(switch3_pin, INPUT);
  pinMode(switch4_pin, INPUT);
  pinMode(buzzer_pin, OUPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(switch1_pin) == LOW || digitalRead(switch2_pin) == LOW || digitalRead(switch3_pin) == LOW || digitalRead(switch4_pin) == LOW) {
    delay(100);
    sw = digitalRead(switch1_pin) + (digitalRead(switch2_pin) << 1) + (digitalRead(switch3_pin) << 2) + (digitalRead(switch4_pin) << 3);

    if (sw == 0b1110) play_scale(do_4,sw);
    else if (sw == 0b1101) play_scale(re_4,sw);
    else if (sw == 0b1011) play_scale(mi_4,sw);
    else if (sw == 0b0111) play_scale(fa_4,sw);
    else if (sw == 0b1100) play_scale(sol_4,sw);
    else if (sw == 0b1001) play_scale(la_4,sw);
    else if (sw == 0b0011) play_scale(si_4,sw);
    else if (sw == 0b1010) play_scale(do_5,sw);
    else noTone(buzzer_pin);
  }
  else noTone(buzzer_pin);
}
