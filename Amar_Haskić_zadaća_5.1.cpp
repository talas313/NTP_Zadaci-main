#include <iostream>
#include <cstring>
using namespace std;
//deklaracija funkcije
void IzdvojiRijec(char recenica[],int redniBroj){
	char rijec[100];
	int brojac=1,brojSlova=0;
	bool provjera=false;
	//petlja koja prolazi kroz svaki karakter u recenici
	for(int i=0;i<strlen(recenica);i++){
		if(recenica[i]==' '){
			if(provjera){
				if(brojac==redniBroj){
					break;
				}else{
					brojac++;
					provjera=false;
					memset(rijec, 0, 100);
					brojSlova=0;
				}
			}
		}else{
			if(brojSlova==0){
				rijec[brojSlova]=recenica[i];
			}else{
			rijec[brojSlova]+=recenica[i];
			}
			brojSlova++;
			provjera=true;
		}
	}
	cout << rijec;
}
int main(){
	setlocale(LC_ALL,"");
	//deklaracija i unos recenice i rednog broja rijeci za ispis
	char rec[100];
	int rB;
	cout << "Unesite reèenicu:";
	cin.getline(rec,100);
	cout << "Unesite redni broj rijeèi koju želite ispisati:";
	cin >> rB;
	//poziv funkcije
	IzdvojiRijec(rec,rB);
	
	return 0;
}

