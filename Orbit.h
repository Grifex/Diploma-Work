#ifndef Orbit_H
#define Orbit_H

#include <vector>
#include <list>

using namespace std;

class Orbit{
private:
		unsigned int k,l,n;
		vector<unsigned int> K;
		unsigned int TempPowerOrbit;
	public:
		Orbit(unsigned int n, const vector<unsigned int> &_K);
		Orbit();
		
		unsigned int PowerOrbit();
		unsigned int GetK();
		unsigned int GetL();
		unsigned int GetN();
		vector<unsigned int> GetVectorK();
		bool operator < (Orbit right);
	
};

#endif


