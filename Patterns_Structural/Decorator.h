#pragma once
#include <iostream>
#include <string>
using namespace std;

class WeatherInfo {
public:
	virtual void showInfo() = 0;
	virtual ~WeatherInfo() {};
};

class Weather :public WeatherInfo {
public:
	void showInfo() {
		cout << "Temperature: 23 Celsius\n"
			<< "Humidity: 78%\n"
			<< "Pressure: 754 mmHg\n"
			<< "Rainy" << endl << endl;
	}
};

class WeatherDecorator :public WeatherInfo {
	bool isNeededTraffic = false;
	bool isNeededRecomendations = false;
	Weather* _weather = new Weather;
public:
	WeatherDecorator() {};
	WeatherDecorator(bool needTraffic, bool needRecomendations) {
		isNeededTraffic = needTraffic;
		isNeededRecomendations = needRecomendations;
	}

	void showInfo() {
		_weather->showInfo();
		if (this->isNeededTraffic) {
			cout << "Traffic jams are everywhere in Center, in other parts of the city situation is much better " << endl << endl;
		}
		if (this->isNeededRecomendations) {
			cout << "Please, use public transport, if you are going to move through the Center. And don't forget your umbrella." << endl << endl;
		}
	}
};


