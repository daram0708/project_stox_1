
    #include<PS2X_lib.h>
    #include <Servo.h>
    #define PS2_DAT     5 // Data Pin
    #define PS2_CMD      4    // Command Pin
    #define PS2_CS      3  // Attention Pin
    #define PS2_CLK     2  // Clock Pin
    int mt11 = 9;
    int mt21 = 8;
    int mt31 = 7;
    int mt41 = 6;
    Servo myServo;
    PS2X ps2;

  void dichuyen(int ly , int lx){
    if(lx>0&&lx<255&&ly==0){//tien
      digitalWrite(mt11,1);
    digitalWrite(mt21,0);
  digitalWrite(mt31,0);
  digitalWrite(mt41,1);
    }

  else if(lx == 255&&ly>0&&ly<255){//sang phai

    digitalWrite(mt21,0);
    digitalWrite(mt11,1);
  digitalWrite(mt31,1);
  digitalWrite(mt41,0);
    
  }
  else if(ly>0&&ly<255&&lx==0 ){//sang trai
        digitalWrite(mt21,1);
    digitalWrite(mt11,0);
  digitalWrite(mt31,0);
  digitalWrite(mt41,1);
    
  }
  else if(ly==255&&lx>0&&lx<255){//lui
      digitalWrite(mt21,1);
    digitalWrite(mt11,0);
  digitalWrite(mt31,1);
  digitalWrite(mt41,0);
    
  }
  else {//dung 3
      digitalWrite(mt21,0);
    digitalWrite(mt11,0);
  digitalWrite(mt31,0);
  digitalWrite(mt41,0);
    
  }/*

  if(ly==0&&lx ==0){//cheo trai len
    digitalWrite(mt31,1);
    digitalWrite(mt41,0);
    digitalWrite(mt32,1);
    digitalWrite(mt42,0);
  }
  if(ly == 0 &&lx ==255){//cheo phai len
      digitalWrite(mt21,1);
    digitalWrite(mt11,0);
    digitalWrite(mt22,1);
    digitalWrite(mt12,0);
  }
  if(ly == 255 && lx ==0){//cheo trai xuong
      digitalWrite(mt12,1);
    digitalWrite(mt22,0);
    digitalWrite(mt12,1);
    digitalWrite(mt22,0);

  }
  if(ly == 255 && lx == 255 ){//cheo phai xuong
      digitalWrite(mt41,1);
    digitalWrite(mt31,0);
    digitalWrite(mt42,1);
    digitalWrite(mt32,0);

  }
  */
  }
  void setup() {
    /*
    pwm.begin();
  pwm.setOscillatorFrequency(27000000); 
  pwm.setPWMFreq(50);
  */
    myServo.attach(A5); // Gắn servo vào chân A5
    pinMode(mt11,OUTPUT);
    pinMode(mt21,OUTPUT);
    pinMode(mt31,OUTPUT);
  pinMode(mt41,OUTPUT);
  int error = ps2.config_gamepad(PS2_CLK, PS2_CMD, PS2_CS, PS2_DAT);

  }
void quay_servo (int rx ,int ry){
  if(rx == 128 && ry ==127 ){
    myServo.write(90);
  }else{
myServo.write(0);
  }
}

  void loop() {

  ps2.read_gamepad(0,0);// put your main code here, to run repeatedly:
  int rx = ps2.Analog(PSS_RX);
int ry = ps2.Analog(PSS_RY);
  quay_servo(rx,ry);
  if(ps2.config_gamepad(PS2_CLK, PS2_CMD, PS2_CS, PS2_DAT)==0){
int lx = ps2.Analog(PSS_LX);
int ly = ps2.Analog(PSS_LY);
  dichuyen(ly,lx);
  }else{
    
  digitalWrite(mt21,0);
  digitalWrite(mt11,0);
  digitalWrite(mt31,0);
  digitalWrite(mt41,0);
  }
  }
  /*
  void tien(){
    pwm.setPin(mt12,4095,true);
    pwm.setPin(mt11,0,true);
    pwm.setPin(mt22,4095,true);
    pwm.setPin(mt21,0,true);
    pwm.setPin(mt32,4095,true);
    pwm.setPin(mt31,0,true);
    pwm.setPin(mt42,4095,true);
    pwm.setPin(mt41,0,true);
  }
  void lui(){
    pwm.setPin(mt11,4095,true);
    pwm.setPin(mt12,0,true);
    pwm.setPin(mt21,4095,true);
    pwm.setPin(mt22,0,true);
    pwm.setPin(mt31,4095,true);
    pwm.setPin(mt32,0,true);
    pwm.setPin(mt41,4095,true);
    pwm.setPin(mt42,0,true);
  }
  void quay_trai(){
    pwm.setPin(mt12,4095,true);
    pwm.setPin(mt11,0,true);
    pwm.setPin(mt22,4095,true);
    pwm.setPin(mt21,0,true);
    pwm.setPin(mt31,4095,true);
    pwm.setPin(mt32,0,true);
    pwm.setPin(mt41,4095,true);
    pwm.setPin(mt42,0,true);
  }
  void quay_phai(){
    pwm.setPin(mt11,4095,true);
    pwm.setPin(mt12,0,true);
    pwm.setPin(mt21,4095,true);
    pwm.setPin(mt22,0,true);
    pwm.setPin(mt32,4095,true);
    pwm.setPin(mt31,0,true);
    pwm.setPin(mt42,4095,true);
    pwm.setPin(mt41,0,true);
  }
  void ngang_trai(){
    pwm.setPin(mt12,4095,true);
    pwm.setPin(mt11,0,true);
    pwm.setPin(mt21,4095,true);
    pwm.setPin(mt22,0,true);
    pwm.setPin(mt32,4095,true);
    pwm.setPin(mt31,0,true);
    pwm.setPin(mt41,4095,true);
    pwm.setPin(mt42,0,true);
  }
  void ngang_phai(){
    pwm.setPin(mt11,4095,true);
    pwm.setPin(mt12,0,true);
    pwm.setPin(mt22,4095,true);
    pwm.setPin(mt21,0,true);
    pwm.setPin(mt31,4095,true);
    pwm.setPin(mt32,0,true);
    pwm.setPin(mt42,4095,true);
    pwm.setPin(mt41,0,true);
  }
  void cheo_trai_len(){
    pwm.setPin(mt12,4095,true);
    pwm.setPin(mt11,0,true);
    pwm.setPin(mt32,4095,true);
    pwm.setPin(mt31,0,true);

  }
  void cheo_phai_len(){
      pwm.setPin(mt22,4095,true);
    pwm.setPin(mt21,0,true);
    pwm.setPin(mt42,4095,true);
    pwm.setPin(mt41,0,true);

  }
  void cheo_trai_xuong(){
      pwm.setPin(mt21,4095,true);
    pwm.setPin(mt22,0,true);
    pwm.setPin(mt41,4095,true);
    pwm.setPin(mt42,0,true);
  }
  void cheo_phai_xuong(){
    pwm.setPin(mt11,4095,true);
    pwm.setPin(mt12,0,true);
    pwm.setPin(mt31,4095,true);
    pwm.setPin(mt32,0,true);
  }
  */
  /*void lui(bool k2){
    if(k2 == HIGH){
      digitalWrite(IN11,HIGH);
      digitalWrite(IN31,HIGH);
      digitalWrite(IN12,HIGH);
      digitalWrite(IN32,HIGH);
    }else{
      
      digitalWrite(IN11,LOW);
      digitalWrite(IN31,LOW);
      digitalWrite(IN12,LOW);
      digitalWrite(IN32,LOW);
    }
  }

  void tien(bool k1){
    if(k1 == HIGH){
      digitalWrite(IN21,HIGH);
      digitalWrite(IN41,HIGH);
      digitalWrite(IN22,HIGH);
      digitalWrite(IN42,HIGH);
    }else{
      
      digitalWrite(IN21,LOW);
      digitalWrite(IN41,LOW);
      digitalWrite(IN22,LOW);
      digitalWrite(IN42,LOW);
    }
  }
  void quay_trai(bool k3){
  if(k3 == HIGH ){
    digitalWrite(IN21,HIGH);
    digitalWrite(IN22,HIGH);
    digitalWrite(IN31,HIGH);
    digitalWrite(IN32,HIGH);
  }else{
    digitalWrite(IN21,LOW);
    digitalWrite(IN22,LOW);
    digitalWrite(IN31,LOW);
    digitalWrite(IN32,LOW);
  }
  }
  void quay_phai(bool k4){
  if(k4 == HIGH ){
    digitalWrite(IN11,HIGH);
    digitalWrite(IN12,HIGH);
    digitalWrite(IN41,HIGH);
    digitalWrite(IN42,HIGH);
  }else{
    digitalWrite(IN11,LOW);
    digitalWrite(IN12,LOW);
    digitalWrite(IN41,LOW);
    digitalWrite(IN42,LOW);
  }
  }
  void di_trai(bool k3){
    if(k3==HIGH){
      digitalWrite(IN22,HIGH);
      digitalWrite(IN11,HIGH);
      digitalWrite(IN41,HIGH);
      digitalWrite(IN32,HIGH);
    }else{
      digitalWrite(IN22,LOW);
      digitalWrite(IN11,LOW);
      digitalWrite(IN41,LOW);
      digitalWrite(IN32,LOW);
    }
  }
  void di_phai(bool k4){
    if(k4==HIGH){
      digitalWrite(IN21,HIGH);
      digitalWrite(IN12,HIGH);
      digitalWrite(IN31,HIGH);
      digitalWrite(IN42,HIGH);

    }else{
      digitalWrite(IN21,LOW);
      digitalWrite(IN12,LOW);
      digitalWrite(IN31,LOW);
      digitalWrite(IN42,LOW);
    }
  }*/