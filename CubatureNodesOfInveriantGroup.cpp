#include <iostream>
#include <vector>
#include "math.h"
#include "CubatureNodesOfInveriantGroup.h"
#include "Orbit.h"
#include "InvariantPolynomials.h"
#include "TypeOrbitL.h"


vector<Orbit> CubatureNodesOfInveriantGroup(unsigned int n,unsigned int m){
	
	try{
    	if(n<3) throw "n<3";
		}catch(const char *exception){
			cout<<"Error: "<<exception<<endl;
			
	}
	
	try{
    	if(m<5||(m%2!=1)) throw "m<5 or even number";
		}catch(const char *exception){
			cout<<"Error: "<<exception<<endl;
			
	}
	
	
	InvariantPolynomials TempInvariantPolynomials(n,m);
	

	vector<unsigned int> J = TempInvariantPolynomials.GetJList();
	
	unsigned int w = min(static_cast<int>(n),static_cast<int>( (floor( sqrt(m/2) ) ) ) );
	
	TypeOrbitL type(n,w,J);
	
	return type.OptimalSetOfTypeOrbitOnKAndL();

	
}

