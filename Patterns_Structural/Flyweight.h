#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class ParticleShared				//Shared State 
{
	string type = "";
	double mass = 0.0;
	double radius = 0.0;
	
public:
	ParticleShared(string& type_in, double mass_in, double radius_in) : type(type_in), mass(mass_in), radius(radius_in) {}

	friend ostream& operator << (ostream& os, const ParticleShared& ps)
	{
		return os << "----- Shared state -----" << "\ntype: \t\t" << ps.type << "\nmass: \t\t" << ps.mass << "\nradius: \t" << ps.radius  << endl;
	}
	friend bool operator == (const ParticleShared& ps1, const ParticleShared& ps2)
	{
		return ps1.mass == ps2.mass && ps1.radius && ps2.radius && ps1.type == ps2.type;
	}
};


class ParticleUnique				//Unique State
{
	double coordinate[3] = { 0 };
	double speed = 0.0;
	double direction[3] = { 0 };

public:
	ParticleUnique(double coord_x, double coord_y, double coord_z, double speed_in, double direction_x, double direction_y, double direction_z) : speed(speed_in)
	{
		coordinate[0] = coord_x;
		coordinate[1] = coord_y;
		coordinate[2] = coord_z;

		direction[0] = direction_x;
		direction[1] = direction_y;
		direction[2] = direction_z;
	}

	friend ostream& operator << (ostream& os, const ParticleUnique& pu)
	{
		return os << "----- Unique state -----"
			<< "\ncoordinate: \t" << "\n\tx: \t" << pu.coordinate[0] << "\n\ty: \t" << pu.coordinate[1] << "\n\tz: \t" << pu.coordinate[2]
			<< "\nspeed: \t\t" << pu.speed << "\ndirection: \t" << "\n\tx: \t" << pu.direction[0] << "\n\ty: \t" << pu.direction[1] << "\n\tz: \t" << pu.direction[2];
	}
};


class FlyweightParticle
{
	ParticleShared* particleShared;
public:
	FlyweightParticle(const ParticleShared* ps) : particleShared(new ParticleShared(*ps)) {};
	FlyweightParticle(FlyweightParticle&fl) : particleShared(new ParticleShared(*fl.particleShared)) {};

	friend ostream& operator << (ostream& os, const FlyweightParticle& fl)
	{
		return os << "~~~~ Flyweight object ~~~~" << endl << *fl.particleShared << endl;
	}

	friend bool operator == (const FlyweightParticle& fp1, const FlyweightParticle& fp2) 
	{
		return fp1.particleShared == fp2.particleShared;
	}

	void simulateParticle(const ParticleUnique &pu)
	{
		cout << *this << endl << pu << endl;
	}

	ParticleShared getSharedState() {
		return *this->particleShared;
	}
};


class FlyweightFactory
{
	vector <FlyweightParticle*> flyweightParticles;
public:
	FlyweightParticle* getFlyweight(const ParticleShared & _particleShared) {
		for (FlyweightParticle* x : flyweightParticles) {
			if (x->getSharedState() == _particleShared) {
				cout << "Such FlyweightParticle exists" << endl;
				return x;
			}
		}
		FlyweightParticle* tmp = new FlyweightParticle(&_particleShared);
		flyweightParticles.push_back(tmp);
		cout << "Created new FlyweightParticle" << endl;
		return tmp;
	}
};