#include "CLed.h"

CLed *ledStrip = nullptr;

long color[3] = {
	0xFF0000,
	0x00FF00,
	0x0000FF
};
uint8_t counter;

void setup() {
	ledStrip = new CLed(9, 10, 11);
	Serial.begin(600);
}

void loop() {
	ledStrip->SetColor(color[counter++ % 3]);
	ledStrip->Loop();
	delay(1000);
}