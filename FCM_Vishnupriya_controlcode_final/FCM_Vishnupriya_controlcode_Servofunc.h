Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int servo1Pin = 13;
int servo2Pin = 12;
int servo3Pin = 14;
int servo4Pin = 26;
int servo5Pin = 33;
int servo6Pin = 32;

void srv_config() {
  servo1.attach(servo1Pin, 500, 2400);
  servo2.attach(servo2Pin, 500, 2400);
  servo3.attach(servo3Pin, 500, 2400);
  servo4.attach(servo4Pin, 500, 2400);
  servo5.attach(servo5Pin, 500, 2400);
  servo6.attach(servo6Pin, 500, 2400);

  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90);
  servo6.write(90);
  delay(300);
}
