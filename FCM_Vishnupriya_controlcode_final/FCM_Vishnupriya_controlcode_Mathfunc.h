float pi = 22 / 7;
float wt1 = 1.5;
float wt3 = 1.5;
float wt5 = 1.5;
float wt2 = 0.75;
float wt4 = 0.75;
float wt6 = 0.75;
float Corr_fac = 1;

float theta1;
float theta3;
float theta5;
float theta2;
float theta4;
float theta6;

void fcm_1(int X1, int Y1) {
  volatile float alpha = 0;
  volatile float r_joystick = 0;

  r_joystick = sqrt(X1 * X1 + Y1 * Y1);
  if (Y1 > 0) {
    alpha = atan2(Y1, X1) * (180 / pi);
  } else if (Y1 < 0) {
    alpha = ((2 * pi) + atan2(Y1, X1)) * (180 / pi);
  } else {
    alpha = 0;
  }

  theta1 = Corr_fac * r_joystick * wt1 * cos(alpha * (pi / 180));
  theta3 = Corr_fac * r_joystick * wt3 * cos((120 - alpha) * (pi / 180));
  theta5 = Corr_fac * r_joystick * wt5 * cos((240 - alpha) * (pi / 180));

//  Serial.print("theta1: ");
//  Serial.print(theta1);
//  Serial.print(" ");
//  Serial.print("theta3: ");
//  Serial.print(theta3);
//  Serial.print(" ");
//  Serial.print("theta5: ");
//  Serial.print(theta5);
//  Serial.print(" ");
//  Serial.print(alpha);

  servo1.write(90 + theta1);
  servo3.write(90 + theta3);
  servo5.write(90 + theta5);
}

void fcm_2(int X2, int Y2) {
  volatile float alpha = 0;
  volatile float r_joystick = 0;

  r_joystick = sqrt(Y2 * Y2 + X2 * X2);
  if (X2 > 0) {
    alpha = atan2(X2, Y2) * (180 / pi);

    theta2 = Corr_fac * r_joystick * wt1 * cos((alpha) * (pi / 180));
    theta4 = Corr_fac * r_joystick * wt2 * cos((120 - alpha) * (pi / 180));
    theta6 = Corr_fac * r_joystick * wt3 * cos((240 - alpha) * (pi / 180));

  } else if (X2 < 0) {
    alpha = ((2 * pi) + atan2(X2, Y2)) * (180 / pi);

    theta2 = Corr_fac * r_joystick * wt1 * cos((alpha) * (pi / 180));
    theta4 = Corr_fac * r_joystick * wt2 * cos((120 - alpha) * (pi / 180));
    theta6 = Corr_fac * r_joystick * wt3 * cos((240 - alpha) * (pi / 180));
  } else {

    theta2 = 0;
    theta4 = 0;
    theta6 = 0;
    alpha = 0;
  }

//  Serial.print(" | theta2: ");
//  Serial.print(theta2);
//  Serial.print(" ");
//  Serial.print("theta4: ");
//  Serial.print(theta4);
//  Serial.print(" ");
//  Serial.print("theta6: ");
//  Serial.print(theta6);
//  Serial.print(" ");
//  Serial.print(alpha);
//  Serial.println();

  servo2.write(90 + theta2);
  servo4.write(90 + theta4);
  servo6.write(90 + theta6);
}
