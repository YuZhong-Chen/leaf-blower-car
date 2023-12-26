#include "fan.h"

namespace FAN {

void Init() {
  pinMode(FAN_PIN, OUTPUT);
  Disable();
}

void Enable() {
  digitalWrite(FAN_PIN, LOW);
}

void Disable() {
  digitalWrite(FAN_PIN, HIGH);
}

}