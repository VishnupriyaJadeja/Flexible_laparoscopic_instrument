int battery = 0;

volatile int rx_val = 0;
volatile int ry_val = 0;
volatile int lx_val = 0;
volatile int ly_val = 0;

void notify() {
  //---------------- Analog stick value events ---------------
  if (abs(Ps3.event.analog_changed.stick.rx) + abs(Ps3.event.analog_changed.stick.ry) > 2) {
    Serial.print("Right joystick: ");
    rx_val = map((abs(Ps3.data.analog.stick.rx)>22)?Ps3.data.analog.stick.rx:0,-128,127,-60,60);
    ry_val = ((abs(Ps3.data.analog.stick.ry)>22)?Ps3.data.analog.stick.ry:0)*-0.46875;
    Serial.print("x = "); Serial.print(rx_val);
    Serial.print(", y = "); Serial.print(ry_val);
    Serial.println();
  }

  if (abs(Ps3.event.analog_changed.stick.lx) + abs(Ps3.event.analog_changed.stick.ly) > 2) {
    Serial.print("Left joystick: ");
    lx_val = map((abs(Ps3.data.analog.stick.lx)>22)?Ps3.data.analog.stick.lx:0,-128,127,-60,60);
    ly_val = ((abs(Ps3.data.analog.stick.ly)>22)?Ps3.data.analog.stick.ly:0)*-0.46875;
    Serial.print("x = "); Serial.print(lx_val);
    Serial.print(", y = "); Serial.print(ly_val);
    Serial.println();
  }

  //---------------------- Battery events ---------------------
  if (battery != Ps3.data.status.battery) {
    battery = Ps3.data.status.battery;
    Serial.print("The controller battery is ");
    if (battery == ps3_status_battery_charging) Serial.println("charging");
    else if (battery == ps3_status_battery_full) Serial.println("FULL");
    else if (battery == ps3_status_battery_high) Serial.println("HIGH");
    else if (battery == ps3_status_battery_low) Serial.println("LOW");
    else if (battery == ps3_status_battery_dying) Serial.println("DYING");
    else if (battery == ps3_status_battery_shutdown) Serial.println("SHUTDOWN");
    else Serial.println("UNDEFINED");
  }
}

void onConnect() {
  Serial.println("Connected.");
}

void PS3_config (){
  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("11:11:11:11:11:11");
  Serial.println("Ready.");  
}
