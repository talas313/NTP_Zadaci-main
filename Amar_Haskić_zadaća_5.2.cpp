#include <iostream>
#include <cstring>
using namespace std;
//deklaracija funkcije
void podblok(int* prviClanNiza1,int* zadnjiClanNiza1,int* prviClanNiza2,int* zadnjiClanNiza2){
	int br = 0;
	//petlja prvog niza
	for(prviClanNiza1;prviClanNiza1<zadnjiClanNiza1;prviClanNiza1++){
		if(*prviClanNiza1==*prviClanNiza2){
			int* povratniClan = prviClanNiza1;
			//petlja drugog niza
			for(prviClanNiza2;prviClanNiza2<zadnjiClanNiza2;prviClanNiza2++){
				if(*povratniClan==*prviClanNiza2){
					int* zadnjiClan = zadnjiClanNiza2-1;
					if(*prviClanNiza2==*zadnjiClan){
						povratniClan -= br;
						cout << *povratniClan;
					}
					povratniClan++;
					br++;
				}else{
					break;
				}
			}
		}
	}
}

int main(){
	setlocale(LC_ALL,"");
	//unos broja elemenata
	int n1,n2;
	cout << "Unesite broj elemenata prvog niza: ";
	cin >> n1;
	cout << "Unesite broj elemenata prvog niza: ";
	cin >> n2;
	//deklaracija nizova
	int niz1[n1],niz2[n2];
	//unos elemenata u prvi niz
	cout << "Unesite elemente prvog niza: \n";
	for(int i=0;i<n1;i++){
		cout << i+1 << ". ";
		cin >> niz1[i];
	}
	//unos elemenata u drugi niz
	cout << "Unesite elemente drugog niza: \n";
	for(int i=0;i<n2;i++){
		cout << i+1 << ". ";	
		cin >> niz2[i];
	}
	//poziv funkcije
	podblok(niz1,niz1+n1,niz2,niz2+n2);

	
	return 0;
}

