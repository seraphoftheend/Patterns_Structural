#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <chrono>
#include <future>
#include <thread>
using namespace std;

class InternetConnection {
public:
	bool transmit(string message) {
		cout << "Transmission started" << endl << endl;
		this_thread::sleep_for(chrono::seconds(8));
		cout << "Message \"" << message << "\" was transmitted" << endl << endl;
		return true;
	};
};


bool atransmit(InternetConnection* iconn, string str) {
	return iconn->transmit(str);
}

class InternetConnectionProxy {
	queue <string> messages;
	InternetConnection* ic;
	future<bool> transmissionResult;
	future <int> fut;
	bool isTransmitting = false;
public:
	void transmit(string msg) {
		messages.push(msg);
		cout << "Message \"" << msg << "\" was added to queue" << endl;
		if (!isTransmitting) {
			while (messages.size() > 0) {
				transmissionResult = async(atransmit, ic, messages.front());
				messages.pop();
			}
		}
	}
};