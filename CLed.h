// CLed.h

#ifndef _CLED_h
#define _CLED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define LEDS 3

class CLed {
private:
	uint8_t brightness[LEDS] = { 0 };
	uint8_t pins[LEDS] = { 0 };

public:
	enum LED {
		Red = 0,
		Green,
		Blue
	};

private:
	void SetLedBrightness(CLed::LED led, uint8_t brightness) {
		this->brightness[led] = brightness ^ 255;
	}

public:
	CLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin) {
		pins[LED::Red] = redPin;
		pins[LED::Green] = greenPin;
		pins[LED::Blue] = bluePin;

		pinMode(pins[LED::Red], OUTPUT);
		pinMode(pins[LED::Green], OUTPUT);
		pinMode(pins[LED::Blue], OUTPUT);
	}

	uint8_t GetLedBrightness(CLed::LED led) {
		return this->brightness[led];
	}

	void Loop() {
		analogWrite(this->pins[LED::Red], this->brightness[LED::Red]);
		analogWrite(this->pins[LED::Green], this->brightness[LED::Green]);
		analogWrite(this->pins[LED::Blue], this->brightness[LED::Blue]);
	}

	void SetColor(long hexColor) {
		byte red = (hexColor >> 16) & 0xFF;
		byte green = (hexColor >> 8) & 0xFF;
		byte blue = hexColor & 0xFF;

		this->SetLedBrightness(Red, red);
		this->SetLedBrightness(Green, green);
		this->SetLedBrightness(Blue, blue);
	}
};

#endif

