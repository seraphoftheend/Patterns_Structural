#pragma once

#include <iostream>
#include <string>
using namespace std;

class TransmitDataOverEthernet						//Target
{
	string msg = "";
public:
	virtual ~TransmitDataOverEthernet() = default;
	virtual void  setMessage() {
		cout << "Enter your message: ";
		getline(cin, msg);
	}
	virtual string getMessage() { return msg; }
	virtual void transmitMessage() {
		cout << "Message \"" + msg +"\" was successfully transmitted over ethernet" << endl;
	};
};


class TransmitDataOverWiFi							//Adaptee
{
	bool enableTransmission = 0;
public:
	void setEnable() { enableTransmission = 1; }

	void resetEnable() { enableTransmission = 0; }

	void transmitDataOverWifi(string buf = "") {
		if (enableTransmission) {
			cout << "Message \"" + buf + "\" was successfully transmitted over WiFi" << endl;
		}
		else {
			cout << "Error during transmission over WiFi" << endl;
		}
	}
};


class TransmitDataOverWiFiAdapter : public TransmitDataOverEthernet
{
	TransmitDataOverWiFi* object;
public:
	TransmitDataOverWiFiAdapter(TransmitDataOverWiFi* auxObj) : object(auxObj) {};
	
	void transmitMessage() override {
		this->object->setEnable();
		this->object->transmitDataOverWifi(getMessage());
	}
};

void ClientCode(TransmitDataOverEthernet* obj) {
	obj->setMessage();
	obj->transmitMessage();
}