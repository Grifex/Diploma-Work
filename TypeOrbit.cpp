#include <iostream>
#include <vector>
#include "math.h"
#include <list>
#include "TypeOrbit.h"
#include "InvariantPolynomials.h"
#include "Orbit.h"

using namespace std;




int SumVecEl(vector<unsigned int> &v){
	int sum=0;
	for(int i=0;i<v.size();i++){
		sum+=(v[i]);
	}
	return sum;
}



void TypeOrbit::EnumerationPolynomialsTypeVector(vector<unsigned int> v){
	if (t == v.size()) {
		if((SumVecEl(v)<=n)){
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

void TypeOrbit::EnumerationTypeVector(){
	vector<unsigned int> VectorK;
	for(int i=1;i<n;i++){
		VectorK.resize(i);
		EnumerationPolynomialsTypeVector(VectorK);
	}
}



void SortVectorOrbitByPowerOrbit(vector<Orbit> &v){
	for(int i = 0;i<v.size();i++){
		for(int j = 0;j<v.size()-1;j++){
			if(v[j].PowerOrbit()>v[j+1].PowerOrbit()){
				swap(v[j], v[j+1]);		
			}
				
			}
		}
}

TypeOrbit::TypeOrbit(unsigned int N,vector<unsigned int> j){
	
	int u = j.size();
	n = N;
	t = 0;
	
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
	
	
	SortVectorOrbitByPowerOrbit(VectorOrbit);			//���������� ������� ����� �� ��������
	
	list<Orbit> ListOrbit;								//�������� ����� ��� ��������� ������ �� ������� ��������� 
	
	for(int i=0;i<VectorOrbit.size();i++){
		ListOrbit.push_back(VectorOrbit[i]);			
	}
	
	for(list<Orbit>::iterator it = ListOrbit.begin();it!=ListOrbit.end();it++){
		if((*it).GetL()>=2){														//	
			ListOrbit.insert(it,u,*it);												//������� ��������� ��������������� ����� ������� u ��� 
		}
	}
	
	VectorOrbit.clear();
	
	for(list<Orbit>::iterator it = ListOrbit.begin();it!=ListOrbit.end();it++){
		VectorOrbit.push_back(*it);													//�������� �������� ��� ����������� � ������ 
	}
	
	ListOrbit.clear();
	
	major.resize(VectorOrbit.size());
	
	for(int i=0;i<VectorOrbit.size();i++){											//�������������� major(������ bool ������� �������� ���������� 																						
		major[i] = false;															// �������������� ��� �����  K ��� ���
	}
		
	
}


TypeOrbit::TypeOrbit(){}


vector<Orbit> TypeOrbit::OptimalSetOfTypeOrbitOnK(vector<Orbit> TempVectorOrbit,vector<unsigned int> TempJ){
	
	list<Orbit> ListOrbit;								//�������� ����� ��� ��������� ������ �� ������� ��������� 
	
	for(int i=0;i<TempVectorOrbit.size();i++){
		ListOrbit.push_back(TempVectorOrbit[i]);			
	}
	
	for(list<Orbit>::iterator it = ListOrbit.begin();it!=ListOrbit.end();it++){
		if((*it).GetL()>=2){														//	
			ListOrbit.insert(it,u,*it);												//������� ��������� ��������������� ����� ������� u ��� 
		}
	}
	
	TempVectorOrbit.clear();
	
	for(list<Orbit>::iterator it = ListOrbit.begin();it!=ListOrbit.end();it++){
		TempVectorOrbit.push_back(*it);													//�������� �������� ��� ����������� � ������ 
	}
	
	ListOrbit.clear();
	
	major.resize(TempVectorOrbit.size());
	
	for(int i=0;i<TempVectorOrbit.size();i++){											//�������������� major(������ bool ������� �������� ���������� 																						
		major[i] = false;															// �������������� ��� �����  K ��� ���
	}
	
	for(int u = 0;u<TempJ.size();u++){
		for(int T=0;T<TempVectorOrbit.size();T++){
			if(!major[T]&&TempVectorOrbit[T].GetK()>=TempJ[u]){		//�������� �� ������ ������� ����������
				major[T] = true;
				break;
			}
		}
	}
	
	vector<Orbit> temp;															
	
	
	for(int i=0;i<major.size();i++){							//�������� ������ ��������� �� ��� ����� ������� �������� �������������
		if(major[i]==true){
			temp.push_back(TempVectorOrbit[i]);
		}
	}
	
	major.clear();
	
	return temp;
	
}



vector<Orbit> TypeOrbit::OptimalSetOfTypeOrbitOnK(){
	
	
	for(int u = 0;u<j.size();u++){
		for(int T=0;T<VectorOrbit.size();T++){
			if(!major[T]&&VectorOrbit[T].GetK()>=j[u]){		//�������� �� ������ ������� ����������
				major[T] = true;
				break;
			}
		}
	}
	
	vector<Orbit> temp;															
	
	
	for(int i=0;i<major.size();i++){							//�������� ������ ��������� �� ��� ����� ������� �������� �������������
		if(major[i]==true){
			temp.push_back(VectorOrbit[i]);
		}
	}
	
	return temp;
}
	
	








