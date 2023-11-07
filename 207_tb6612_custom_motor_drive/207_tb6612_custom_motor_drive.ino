#include <driver/ledc.h>

#define MSLEEP  16
#define IA1     14
#define IB1     12
#define PWM1    13
#define IA2     27
#define IB2     26
#define PWM2    25
#define IA3     17
#define IB3     5
#define PWM3    18
#define IA4     4
#define IB4     2
#define PWM4    15

#define DEFAULT_LEDC_FREQ 20000
#define DEFAULT_LEDC_RANGE LEDC_TIMER_10_BIT

void motor1_setup(int ia1, int ib1, int pwm1){
  pinMode(ia1, OUTPUT);
  pinMode(ib1, OUTPUT);
  ledcSetup(LEDC_CHANNEL_0, DEFAULT_LEDC_FREQ, LEDC_TIMER_10_BIT);
  ledcAttachPin(pwm1, LEDC_CHANNEL_0 );
}

void motor2_setup(int ia2, int ib2, int pwm2 ){
  pinMode(ia2, OUTPUT);
  pinMode(ib2, OUTPUT);
  ledcSetup(LEDC_CHANNEL_0, DEFAULT_LEDC_FREQ, DEFAULT_LEDC_RANGE);
  ledcAttachPin(LEDC_CHANNEL_0, pwm2);
}

void motor3_setup(int ia3, int ib3, int pwm3 ){
  pinMode(ia3, OUTPUT);
  pinMode(ib3, OUTPUT);
  ledcSetup(LEDC_CHANNEL_0, DEFAULT_LEDC_FREQ, DEFAULT_LEDC_RANGE);
  ledcAttachPin(LEDC_CHANNEL_0, pwm3);
}

void motor4_setup(int ia4, int ib4, int pwm4 ){
  pinMode(ia4, OUTPUT);
  pinMode(ib4, OUTPUT);
  ledcSetup(LEDC_CHANNEL_0, DEFAULT_LEDC_FREQ, DEFAULT_LEDC_RANGE);
  ledcAttachPin(LEDC_CHANNEL_0, pwm4);
}

void tb6612_enable(int m_sleep){
  pinMode(m_sleep, OUTPUT);
  digitalWrite(m_sleep, HIGH);
}

void motor1_move_forward(){
  digitalWrite(IA1, HIGH);
  digitalWrite(IB1, LOW);
  ledcWrite(LEDC_CHANNEL_0, 1024);
}

void setup() {
  Serial.begin(115200);
  motor1_setup(IA1, IB1, PWM1);
  //motor2_setup(IA1, IB1, PWM2);
  //motor3_setup(IA1, IB1, PWM3);
  //motor4_setup(IA1, IB1, PWM4);
  tb6612_enable(MSLEEP);
  delay(1000);
}

void loop() {
 motor1_move_forward();
}
