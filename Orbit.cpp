#include <iostream>
#include <vector>
#include "math.h"
#include <list>
#include "Orbit.h"

bool IsPrime(unsigned int n){
	bool temp=true;
	if(n==1) return false;
	for(int i=2;i<=n/2;i++){
		if(n%i==0){
			temp=false;
		}
	}
	return temp;	
}


vector<unsigned int> Decomposition(unsigned int N){
	int temp = N;					
	vector<unsigned int> VectorTemp;
	
	if(N==1){
	VectorTemp.push_back(1);
	return VectorTemp;
	}
	if(N==2){
		VectorTemp.push_back(2);
		return VectorTemp;
		
	}
	
	int i=2;
	while(i!=N){
		while(IsPrime(i)&&temp%i==0){
			VectorTemp.push_back(i);
			temp/=i;
		}
		i++;
		
	}
	
	return VectorTemp;
}

void DevideDenominatorAndNumerator(vector<unsigned int> &v1, vector<unsigned int> &v2){
	
	
	
	
	for(int i=0;i<v1.size();i++){
		for(int j=v2.size()-1;j>=0;j--){
			if(v1[i]==v2[j]){
				v1.erase(v1.begin()+i);
				v2.erase(v2.begin()+j);
			}
		}
	}
	
	for(int i=0;i<v1.size();i++){
			for(int j=0;j<v2.size();j++){
				if(v1[i]==v2[j]){
					v1.erase(v1.begin()+i);
					v2.erase(v2.begin()+j);
				}
		}
	}
	
	
	
	
}	

unsigned int SumVectorElement(const vector<unsigned int> &v){	

	unsigned int sum=0;
	
	for(vector<unsigned int>::const_iterator it=v.begin();it!=v.end();it++){
		sum+=*it;
	}
	return sum;
}


Orbit::Orbit(unsigned int n, const vector<unsigned int> &_K) : K(_K) {
		this->n=n;
		this->l=K.size();
		try{
    		if(l<1) throw "l<1";
		}catch(const char *exception){
			cout<<"Error: "<<exception;
		}			
		unsigned int s = SumVectorElement(K);
		try{	
            if(s>n) throw "summ of element vector K not eqaul n";
		}catch(const char *exception){
			cout<<"Error: "<<exception;
		}
		this->k=s;
		
		vector<unsigned int> TempN;
		TempN.push_back(1);
		for(int i=2;i<=n;i++){
			if(!IsPrime(i)){
					vector<unsigned int> Temp = Decomposition(i);
					for(int p = 0;p<Temp.size();p++){
						TempN.push_back(Temp[p]);
				}
			}
			else TempN.push_back(i);		
		}
			
		vector<unsigned int> Temp2K;
		for(int i=0;i<k;i++){
			Temp2K.push_back(2);
		}
			
			
		vector<unsigned int> TempKl;
			
		for(int i=0;i<l;i++){
			for(int j=1;j<=K[i];j++){
				if(!IsPrime(j)){
					vector<unsigned int> Temp = Decomposition(j);
					for(int p = 0;p<Temp.size();p++){
						TempKl.push_back(Temp[p]);
					}
				}
				else TempKl.push_back(j);
			}
		}
			
			
		int NK = n-k;
			
		vector<unsigned int> TempNK;
		TempNK.push_back(1);
		for(int i=2;i<=NK;i++){
			if(!IsPrime(i)){
					vector<unsigned int> Temp = Decomposition(i);
					for(int p = 0;p<Temp.size();p++){
						TempNK.push_back(Temp[p]);
					}
			}
			else TempNK.push_back(i);		
		}
			
			
		
	
		TempN.insert(TempN.begin(),Temp2K.begin(),Temp2K.end());
		

			
			
		TempKl.insert(TempKl.begin(),TempNK.begin(),TempNK.end());

		
		vector<unsigned int> Numerator;
		
		for(int i=0;i<TempN.size();i++){
			Numerator.push_back(TempN[i]);
		}
		
			
		vector<unsigned int> Denominator;
		
		for(int i=0;i<TempKl.size();i++){
			Denominator.push_back(TempKl[i]);
		}
		
		
	
			
		DevideDenominatorAndNumerator(Numerator,Denominator);
			
		unsigned int TempDenominator=1;
			
		for(int i=0;i<Denominator.size();i++){
			TempDenominator*=Denominator[i];
		}
			
			
		unsigned int TempNumerator=1;
		unsigned int Max=0xFFFFFFFF;
			
		for(int i=0;i<Numerator.size();i++){
            if (TempNumerator > Max/Numerator[i]) {
				TempPowerOrbit = Max;
				break;
			}
			TempNumerator*=Numerator[i];
		}
		
		if(TempPowerOrbit!=Max){
			TempPowerOrbit = TempNumerator / TempDenominator;
		}
		 
			
			
		
		
		
}

unsigned int Orbit::PowerOrbit(){
	return TempPowerOrbit;
}


unsigned int Orbit::GetK(){
	return k;
}
unsigned int Orbit::GetL(){
	return l;
}
unsigned int Orbit::GetN() {
	return n;
}

vector<unsigned int> Orbit::GetVectorK(){
	return K;
}

bool Orbit::operator <(Orbit right){
	return this->PowerOrbit()<right.PowerOrbit();
}


