#ifndef TypeOrbitL_h
#define TypeOrbitL_h

#include <vector>
#include <list>
#include "InvariantPolynomials.h"
#include "Orbit.h"

using namespace std;

class TypeOrbitL{
private:
		unsigned int n;
		unsigned int t; 
		
		unsigned int w,M;       								
		vector<Orbit> VectorOrbit;										//Набор орбит 
		
		vector<unsigned int> j;
		vector<bool> major;						
		void EnumerationPolynomialsTypeVector(vector<unsigned int> v);
		void EnumerationTypeVector();
	public:
		TypeOrbitL(unsigned int n,unsigned int w,vector<unsigned int> j); 
		
		vector<Orbit> OptimalSetOfTypeOrbitOnKAndL();
		
		
	
		unsigned int GetN(){
			return n;
		}
		
		unsigned int GetW(){
			return w;
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
