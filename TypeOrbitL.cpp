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
	
	for(int i=0;i<j.size();i++){							//инициализация j списка
		this->j.push_back(j[i]);
	}
	
	for(int i = 0;i<j.size();i++){
		for(int k = 0;k<j.size()-1;k++){								//сортировка j списка по не убыванию
			if(this->j[k]>this->j[k+1]){
				swap(this->j[k], this->j[k+1]);		
			}
				
		}
	}
	
	
	SortVectorOrbitByPowerOrbitL(VectorOrbit);			//Сортировка вектора орбит по мощности
	
	
}




vector<Orbit> TypeOrbitL::OptimalSetOfTypeOrbitOnKAndL(){
	
	vector<unsigned int> TempJ;								//Временная переменная для j списка
	vector<Orbit> TempVectorOrbitOnLAndK;						//Временная переменная для условия на L и на K
	vector<Orbit> TempVectorOrbitOnK;						//Временная переменная для условия на K 
	vector<Orbit> R;										//вектор R
	M=0;
	for(int T = 0;T<VectorOrbit.size();T++){
		int count = 0; 								//счётчик для того чтобы удалить только один элемент тз j списка
		if(VectorOrbit[T].GetL()>=w){				//тип T удовлетворяет "условию на l"					
				 						
			for(int u=j.size()-1;u>=0;u--){					
				if(j[u]<=VectorOrbit[T].GetK()&&count==0){			//Формируем j' список
					count++;
					continue;
				}
				TempJ.push_back(j[u]);
			}
			
		
		count=0;
//		TempVectorOrbit = VectorOrbit;
//		
//		TempVectorOrbit.erase(TempVectorOrbit.begin()+T);
		
		for(int TempT =0;TempT<VectorOrbit.size();TempT++){			//Формируем T' список для условия на K
			if((VectorOrbit[T].GetL()==1&&w==1)&&T==TempT){
				continue;
			}
			TempVectorOrbitOnK.push_back(VectorOrbit[TempT]);		
		}
		TypeOrbit TempTypeOrbit;																	//создаём объект типа TypeOrbit											
		TempVectorOrbitOnLAndK = TempTypeOrbit.OptimalSetOfTypeOrbitOnK(TempVectorOrbitOnK,TempJ); //Формируем T'' список для условия на L		
				
		
		
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
	
