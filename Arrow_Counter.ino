#include <M5StickC.h>
#include <Wire.h>
#include <I2C_MPU6886.h>

int counter = 0;


void setup() {
  M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(50, 20);
  M5.Lcd.print("Arrows");
  M5.MPU6886.Init();
}


void loop() {
  float ax, ay, az;
  float gx, gy, gz;
  M5.MPU6886.getGyroData(&gx, &gy, &gz);
  M5.MPU6886.getAccelData(&ax, &ay, &az);
  
  // Calculate the magnitude of acceleration
  float acceleration = sqrt(ax*ax + ay*ay + az*az);

  // Calculate the magnitude of rotation
  float rotation = sqrt(gx*gx + gy*gy + gz*gz);

  // Check if the acceleration is greater than 5 and if there is massive rotation in one plane
  if (acceleration > 6 && rotation > 11) {
    // Increment the counter
    counter++;
  }

  // Display the counter on the M5StickC screen
  M5.Lcd.setCursor(80, 40);
  M5.Lcd.print(counter);

  delay(100);
}

