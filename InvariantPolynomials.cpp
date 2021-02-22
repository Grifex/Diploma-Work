#include <iostream>
#include <vector>
#include "math.h"
#include <list>
#include "InvariantPolynomials.h"
using namespace std;


int SumVecElementov(vector<unsigned int> v,int n){
	int sum=0;
	for(int i=2;i<=n;i++){				//Исправленно Версия 1.1 было:(int i=2;i<n;i++)
		sum+=(i*2)*(v[i-1]);
	}
	return sum;
}




void InvariantPolynomials::EnumerationPolynomials(){
	if (t == n) {
		if(SumVecElementov(AlphN,n)<=m){
		
		lBase_alphes.push_back(AlphN);
		}	
	}
	else
	{
		t++;
		for (int i = 0; i <= m / 2; i++){
			AlphN.at(t-1) = i;
			EnumerationPolynomials();
		}

	t--;

	}
}

InvariantPolynomials::InvariantPolynomials(int n,int m){
	this->n = n;
	this->m = m;
	t=1;
	AlphN.resize(n);
	EnumerationPolynomials();	
}


list<vector<unsigned int> > InvariantPolynomials::Get(){
	return lBase_alphes;
}

void InvariantPolynomials::WriteInvariantPolynomials(){
	for(list<vector<unsigned int> >::iterator it  = lBase_alphes.begin(); it != lBase_alphes.end(); it++){
        cout << "( ";
    	for(vector<unsigned int>::iterator itt = it->begin(); itt != it->end(); itt++)
    		cout<<*itt<<' ';
    	cout << ")\n";
	}
}


unsigned int InvariantPolynomials::J(vector<unsigned int> g){			//vector<int> g	— базис пространства инвариантных относительно группы	
	
	unsigned int max = 2;
	unsigned int n = g.size();
	unsigned int count = 0;
	for(unsigned int i = 1;i<n;i++){
		if(g[i]!=0){
			max = i+1;
		}
		if(g[i]==0){
			count++;
		}
	}
	
	if(count==n-1){
		return 1;
	}
	
	return max;
	
}

vector<unsigned int> InvariantPolynomials::GetJList(){
	vector<unsigned int> Temp;
	
	for(list<vector<unsigned int> >::iterator it  = lBase_alphes.begin(); it != lBase_alphes.end(); it++){
		
    	Temp.push_back(J(*it));
		
	}
	
	return Temp;
}



