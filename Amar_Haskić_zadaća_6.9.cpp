#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int ukupnoIzostanaka(int *niz, int velNiz){		// deklaracija funkcije i davanje parametara funkciji
	int suma=0, i;								// deklaracija varijable suma i postavljanje na nulu i deklaracija varijable koja se koristi za niz
	for(i=0; i<velNiz; i++)						// for petlja za prolazak kroz niz
		suma += niz[i];							// racunanje ukupnog broja izostanaka preko varijable suma
	
	return suma;								// povratna vrijednost sume koja je ukupan broj izostanaka u odjeljenju
}
int bezIzostanaka(int *niz, int velNiz){		// deklaracija funkcije i davanje parametara funkciji
	int br=0, i;								// deklaracija brojaca i postavljanje na nulu te deklaracija varijable koja se koristi za niz
	for(i=0; i<velNiz; i++)						// for petlja za prolzak kroz niz
		if(niz[i] == 0)							// uslov koji ako je ispunjen povecava brojac koji broji ucenike bez izostanaka
			br++;
		
	return br;									// povratna vrijednost brojaca koja predstavlja broj ucenika bez izostanaka
}
int najveciBroj(int *niz, int velNiz){			// deklaracija funkcije i davanje parametara funkciji
	int max = 0;								// deklaracija varijable max i postavljanje na nulu
	int i;										// deklaracija varijable koja se koristi za niz
	for(i=0; i<velNiz; i++)						// for petlja za prolazaka kroz niz
		if(niz[i]>max)							// uslov koji ako je ispunjen pridruzuje prethodno navedenoj varijabli max vrijednost trenutnog elementa niza
			max = niz[i];
		
	return max;									// povratna vrijednost max koja predstavlja maksimalan broj izostanaka koje ima neki ucenik u odjeljenju
}
int main(){
	fstream datoteka;							// deklaracija objekta u koji se sprema zeljena datoteka
	int *niz, velNiz = 0, i;					// deklaracija pokazivaca na niz, velicine niza koja je na pocetku nula te varijable koja se koristi za niz
	datoteka.open("Izostanci.txt");				// otvaranje datoteke
	while(datoteka >> i){
		velNiz++;
	}
	niz = (int*) malloc(velNiz*sizeof(int));
	datoteka.close();					// zatvaranje datoteke
	datoteka.open("Izostanci.txt");		// otvaranje datoteke
	for(i=0; i<velNiz; i++){
		datoteka >> niz[i];
	}
	cout << "Ukupan broj izostanaka: " << ukupnoIzostanaka(niz, velNiz) << endl;	// ispis ukupnog broja izostanaka u odjeljenju pomocu funkcije ukupnoIzostanaka
	cout << "Prosjecno izostanaka: " << (float)ukupnoIzostanaka(niz, velNiz) / velNiz << endl;	// ispis prosjecnog broja izostanaka u odjeljenju pomocu funkcije ukupnoIzostanaka
	cout << "Maksimalan broj izostanaka je: " << najveciBroj(niz, velNiz) << endl;		// ispis maksimalnog broja izostanaka		
	cout << "Ukupno ucenika bez izostanaka: " << bezIzostanaka(niz, velNiz); 	// ispis ukupnog broja ucenika bez izostanaka pomocu funkcije bezIzostanaka
	datoteka.close();							// zatvaranje datoteke
	
	
	
	
	return 0;
}

