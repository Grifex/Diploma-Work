#include <iostream>
#include <vector>
#include "math.h"
#include <list>
#include "InvariantPolynomials.h"
#include "Orbit.h"
#include "TypeOrbit.h"
#include "TypeOrbitL.h"
#include "CubatureNodesOfInveriantGroup.h"

using namespace std;






int main(int argc, char** argv) {
	

	vector<Orbit> temp = CubatureNodesOfInveriantGroup(4,7);;

	
	
	vector<unsigned int> t;
	for(vector<Orbit>::iterator it = temp.begin();it!=temp.end();it++){
			t = (*it).GetVectorK();
			for(vector<unsigned int>::iterator itt = t.begin();itt!=t.end();itt++){		//чтение оптимального набора типов орбит удовлетвор€ющие условию на K
				cout<<(*itt)<<" ";
			}
		cout<<endl;
	}

	char x; cin >> x;
	return 0;
}
