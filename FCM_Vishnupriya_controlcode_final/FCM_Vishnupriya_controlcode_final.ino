#include <ESP32_Servo.h>
#include <Ps3Controller.h>
#include "FCM_Vishnupriya_controlcode_PSfunc.h"
#include "FCM_Vishnupriya_controlcode_Servofunc.h"
#include "FCM_Vishnupriya_controlcode_Mathfunc.h"

void setup() {
  Serial.begin(115200);
  PS3_config();
  srv_config();
}

void loop() {
  if (!Ps3.isConnected())
    return;

  fcm_1(rx_val, ry_val);
  fcm_2(lx_val, ly_val);
}
