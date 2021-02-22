#ifndef InvariantPolynomials_H
#define InvariantPolynomials_H

#include <vector>
#include <list>


using namespace std;

class InvariantPolynomials{
	int n,m;
	int t ;								//индекс последнего свободного элменета в переборе
	vector<unsigned int> AlphN;
	list<vector<unsigned int> > lBase_alphes;
	void AddVectorInBase_Alphes();
	void EnumerationPolynomials();
	unsigned int J(vector<unsigned int> g);
	public:
		
		InvariantPolynomials(int n,int m);
		list<vector<unsigned int> > Get();
		void WriteInvariantPolynomials();
		
		vector<unsigned int> GetJList(); 
		
};
#endif
