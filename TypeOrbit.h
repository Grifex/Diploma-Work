#ifndef TypeOrbit_h
#define TypeOrbit_h

#include <vector>
#include <list>
#include "InvariantPolynomials.h"
#include "Orbit.h"

using namespace std;

class TypeOrbit{
private:
		unsigned int n;
		unsigned int t; 
		unsigned int u;
		vector<Orbit> VectorOrbit;										//Набор орбит 
		
		vector<unsigned int> j;
		vector<bool> major;						
		void EnumerationPolynomialsTypeVector(vector<unsigned int> v);
		void EnumerationTypeVector();
	public:
		TypeOrbit(unsigned int N,vector<unsigned int> j);
		TypeOrbit();
		
		
		vector<Orbit> OptimalSetOfTypeOrbitOnK();
		
		vector<Orbit> OptimalSetOfTypeOrbitOnK(vector<Orbit> TempVectorOrbit,vector<unsigned int> TempJ);
	
		unsigned int GetN(){
			return n;
		}
		
		unsigned int GetVectorOrbitSize(){
			return VectorOrbit.size();
		}
		
		void ReadVectorOrbit(){
			vector<unsigned int> t;
			for(vector<Orbit>::iterator it = VectorOrbit.begin();it!=VectorOrbit.end();it++){
				t = (*it).GetVectorK();
				for(vector<unsigned int>::iterator itt = t.begin();itt!=t.end();itt++){
					cout<<(*itt)<<" ";
				}
				cout<<endl;
			}
		}
		
		
		void ReadMajor(){
			for(int i=0;i<j.size();i++){
				cout<<major[i];
			}
		}
		
		void ReadJ(){
			for(int i=0;i<j.size();i++){
				cout<<j[i];
			}
		}
		
		
};

#endif
