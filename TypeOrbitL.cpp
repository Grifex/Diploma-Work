#include <iostream>
#include <vector>
#include "math.h"
#include <list>
#include "TypeOrbitL.h"
#include "InvariantPolynomials.h"
#include "Orbit.h"
#include "TypeOrbit.h"

using namespace std;


int SumVecElem(vector<unsigned int> &v){
	int sum=0;
	for(int i=0;i<v.size();i++){
		sum+=(v[i]);
	}
	return sum;
}



void TypeOrbitL::EnumerationPolynomialsTypeVector(vector<unsigned int> v){
	if (t == v.size()) {
		if((SumVecElem(v)<=n)){
			VectorOrbit.push_back(Orbit(n,v));	
		}	
	}
	else
	{
		t++;
		for (int i = 1; i <= n - v.size() + 1; i++){
			v.at(t-1) = i;
			EnumerationPolynomialsTypeVector(v);
		}

	t--;

	}
}

void TypeOrbitL::EnumerationTypeVector(){
	vector<unsigned int> VectorK;
	for(int i=1;i<n;i++){
		VectorK.resize(i);
		EnumerationPolynomialsTypeVector(VectorK);
	}
}



void SortVectorOrbitByPowerOrbitL(vector<Orbit> &v){
	for(int i = 0;i<v.size();i++){
		for(int j = 0;j<v.size()-1;j++){
			if(v[j].PowerOrbit()>v[j+1].PowerOrbit()){
				swap(v[j], v[j+1]);		
			}
				
			}
		}
}

TypeOrbitL::TypeOrbitL(unsigned int n,unsigned int w,vector<unsigned int> j){
	
	this->n = n;
	t = 0;
	
	this->w=w;
	
	
	
	
	EnumerationTypeVector();
	
	for(int i=0;i<j.size();i++){							//������������� j ������
		this->j.push_back(j[i]);
	}
	
	for(int i = 0;i<j.size();i++){
		for(int k = 0;k<j.size()-1;k++){								//���������� j ������ �� �� ��������
			if(this->j[k]>this->j[k+1]){
				swap(this->j[k], this->j[k+1]);		
			}
				
		}
	}
	
	
	SortVectorOrbitByPowerOrbitL(VectorOrbit);			//���������� ������� ����� �� ��������
	
	
}




vector<Orbit> TypeOrbitL::OptimalSetOfTypeOrbitOnKAndL(){
	
	vector<unsigned int> TempJ;								//��������� ���������� ��� j ������
	vector<Orbit> TempVectorOrbitOnLAndK;						//��������� ���������� ��� ������� �� L � �� K
	vector<Orbit> TempVectorOrbitOnK;						//��������� ���������� ��� ������� �� K 
	vector<Orbit> R;										//������ R
	M=0;
	for(int T = 0;T<VectorOrbit.size();T++){
		int count = 0; 								//������� ��� ���� ����� ������� ������ ���� ������� �� j ������
		if(VectorOrbit[T].GetL()>=w){				//��� T ������������� "������� �� l"					
				 						
			for(int u=j.size()-1;u>=0;u--){					
				if(j[u]<=VectorOrbit[T].GetK()&&count==0){			//��������� j' ������
					count++;
					continue;
				}
				TempJ.push_back(j[u]);
			}
			
		
		count=0;
//		TempVectorOrbit = VectorOrbit;
//		
//		TempVectorOrbit.erase(TempVectorOrbit.begin()+T);
		
		for(int TempT =0;TempT<VectorOrbit.size();TempT++){			//��������� T' ������ ��� ������� �� K
			if((VectorOrbit[T].GetL()==1&&w==1)&&T==TempT){
				continue;
			}
			TempVectorOrbitOnK.push_back(VectorOrbit[TempT]);		
		}
		TypeOrbit TempTypeOrbit;																	//������ ������ ���� TypeOrbit											
		TempVectorOrbitOnLAndK = TempTypeOrbit.OptimalSetOfTypeOrbitOnK(TempVectorOrbitOnK,TempJ); //��������� T'' ������ ��� ������� �� L		
				
		
		
		unsigned int sum = 0;
		for(vector<Orbit>::iterator it = TempVectorOrbitOnLAndK.begin();it!=TempVectorOrbitOnLAndK.end();it++){
				sum+=(*it).PowerOrbit();
		}
		
		if(M<sum||M==0){
			M = sum;
			R = TempVectorOrbitOnLAndK;
			R.push_back(VectorOrbit[T]);
		}
		
		
		TempVectorOrbitOnK.clear();   
		TempJ.clear();
		
		
		if(M>0&&M<VectorOrbit[T].PowerOrbit()){
			break;
		}
		
		
		}
		
		
	}
	
	
	
	return R;
}
	
