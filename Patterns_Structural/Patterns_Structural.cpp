#include <iostream>
#include <string>

#include "Adapter.h"
#include "Flyweight.h"
#include "Proxy.h"
#include "Facade.h"
#include "Decorator.h"


int main()
{
    ////------------------------------- Adapter ------------------------------------------------

    /*TransmitDataOverEthernet *object = new TransmitDataOverEthernet;        
    ClientCode(object);
    cout << endl;

    TransmitDataOverWiFi* obj = new TransmitDataOverWiFi;
    obj->transmitDataOverWifi();
    cout << endl;

    TransmitDataOverWiFiAdapter* adapter = new TransmitDataOverWiFiAdapter(obj);
    ClientCode(adapter);*/

    ////----------------------------------------------------------------------------------------

    //------------------------------- Flyweight ------------------------------------------------
    /*string e = "electron";
    ParticleShared electron(e, 9.11e-31, 2.82e-15);
    string p = "proton";
    ParticleShared proton(p, 1.67e-27, 0.831e-15);

    ParticleUnique state1(2.0, 3.0, 4.0, 2.2e+6, 1.0, 1.0, 1.0),
        state2(10.0, -15.0, 18.0, 3.7e+6, -0.2, 0.8, 0.5);
  
    FlyweightFactory factory;

    FlyweightParticle* particle = factory.getFlyweight(electron);
    particle->simulateParticle(state1);

    cout << endl << "-----------------------------------------" << endl << endl;
    FlyweightParticle* particle2 = factory.getFlyweight(electron);
    particle->simulateParticle(state2);

    cout << endl << "-----------------------------------------" << endl << endl;
    particle = factory.getFlyweight(proton);
    particle->simulateParticle(state1);*/
    
    //------------------------------------------------------------------------------------------

    //------------------------------- Proxy ------------------------------------------------
   
    //InternetConnection ic;
    //InternetConnectionProxy icp;
    ////auto start = chrono::steady_clock::now();
    //ic.transmit("A very important message1");
    //ic.transmit("A very important message2");
    //ic.transmit("A very important message3");
    //ic.transmit("A very important message4");
    //ic.transmit("A very important message5");
    //ic.transmit("A very important message6");
    ////auto stop = chrono::steady_clock::now();
    ////chrono::duration<double> elapsedTime = stop - start;
    ////cout << "Elapsed time: " << elapsedTime.count() << "seconds" << endl << endl;

    ////start = chrono::steady_clock::now();
    //icp.transmit("A very important message");
    //this_thread::sleep_for(chrono::milliseconds(2));
    //icp.transmit("A very important message2");
    //icp.transmit("A very important message3");
    //icp.transmit("A very important message4");
    //icp.transmit("A very important message5");
    //icp.transmit("A very important message6");
    ////stop = chrono::steady_clock::now();
    ////elapsedTime = stop - start;
    ////cout << "Elapsed time: " << elapsedTime.count() << "seconds" << endl << endl;

    //cout << "The end of main" << endl;
    
    //------------------------------------------------------------------------------------------

    //------------------------------- Facade ------------------------------------------------

    /*TemperatureMeasurement* tm = new TemperatureMeasurement;
    cout << "Current temperature is: " << tm->measure() << " Celsius" << endl << endl;
    cout << "Current temperature is: " << tm->measure() << " Celsius" << endl << endl;*/

    //------------------------------------------------------------------------------------------

   //------------------------------- Decorator ------------------------------------------------
    WeatherInfo* weather = new Weather;
    weather->showInfo();

    cout << "-------------------------------------------------" << endl << endl;

    WeatherInfo* wInfo = new WeatherDecorator(false, true);
    wInfo->showInfo();

    cout << "-------------------------------------------------" << endl << endl;

    WeatherInfo* wInfo1 = new WeatherDecorator(true, true);
    wInfo1->showInfo();

    return 0;
}