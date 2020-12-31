#include <Arduino.h>
#include <Adafruit_ADXL345_U.h>

extern "C" {
#include <stddef.h>
#include "tiny_timer.h"
#include "tiny_time_source.h"
#include "tiny_heartbeat.h"
}

static tiny_timer_group_t timer_group;
static Adafruit_ADXL345_Unified sensor;

void setup()
{
  Serial.begin(9600);

  sensor.begin();

  tiny_timer_group_init(&timer_group, tiny_time_source_init());
  tiny_heartbeat_init(&timer_group, 1000);
}

void loop()
{
  sensors_event_t event;
  sensor.getEvent(&event);

  Serial.print("(");
  Serial.print(String(event.acceleration.x) + ", ");
  Serial.print(String(event.acceleration.y) + ", ");
  Serial.print(String(event.acceleration.z));
  Serial.println(")");

  delay(100);

  tiny_timer_group_run(&timer_group);
}
