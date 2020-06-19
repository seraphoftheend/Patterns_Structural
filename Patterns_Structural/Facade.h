#pragma once
#include <iostream>
#include <string>
using namespace std;

class ADC {
	uint16_t rawData = 3581;
public:
	bool init() {
		cout << "ADC initialization complete" << endl << endl;
		return true;
	}
	uint16_t makeMeasurement() {
		cout << "Measurement is finished" << endl << endl;
		rawData += 50;
		return rawData;
	}
};


class GPIO {
public:
	bool set() {
		cout << "GPIO setting complete" << endl << endl;
		return true;
	}
};

class TemperatureMeasurement {						//Facade
	uint8_t nrPin = 2;					//номер пина, к которому подключен датчик температуры
	bool isADCset = false;				//хранит информацию о том, был ли настроен АЦП
	bool isGPIOset = false;				//хранит информацию о том, был ли настроен пин
	ADC adc;
	GPIO gpio;
public:
	float convertToCelsius(uint16_t rawData) {
		static uint16_t Vo = 0;
		static float_t R1 = 10000;
		static float_t logR2 = 0, R2 = 0, T = 0, k = 40;
		static float_t c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741;    //steinhart-hart coeficients for thermistor
		static float_t tmp;
		Vo = rawData;
		R2 = R1 / (4095.0 / (float)Vo - 1.0);    //calculate resistance on thermistor
		logR2 = log(R2);
		T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2)) + k;     // temperature in Kelvin
		tmp = T - 273.15;
		return tmp;
	}

	float measure() {
		if (!isADCset) {
			isADCset = adc.init();
		}
		if (!isGPIOset) {
			isGPIOset = gpio.set();
		}
		uint16_t tmp = adc.makeMeasurement();
		return this->convertToCelsius(tmp);
	}
};

