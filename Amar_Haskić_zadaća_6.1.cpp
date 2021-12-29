#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Proizvod{		// deklaracija strukture 
	string naziv; 		
	string proizvodjac; // od 9. do 12. linije - deklaracija varijabli razlicitog tipa
	double cijena;	
	int kolicina;
}p[10000];				// deklaracija i inicijalizacija niza koji prima podatke o proizvodima

int main(){
	setlocale(LC_ALL, "");
	fstream datoteka;				// deklaracija objekta u koji se smjesta zeljena datoteka
	datoteka.open("proizvodi.txt");	// otvaranje datoteke u kojoj su smjesteni podaci o proizvodima
	int br=0, i=0, fiat=0;			// deklaracija brojaca za niz, brojaca proizvoda koje proizvodi FIAT i 
                           			// brojaca svih proizvoda
	double ukupnaVrijednost;		// deklaracija varijable u koju ce se smjestati ukupna vrijednost svih proizvoda u prodavnici
	
	if(datoteka.is_open()){ // ispitivanje uslova, ukoliko je ispunjen izvrsava se zadani zadatak
		while(datoteka >> p[i].naziv >> p[i].proizvodjac >> p[i].cijena >> p[i].kolicina){ // while petlja koja radi do zavrsetka datoteke i uzima podatke iz svake linije smjestene u neku od varijabli iz strukture Proizvod
			if(datoteka){
				br++;		// od 25. do 27. linije koda - prebrojavanje ukupnog broja proizvoda u prodavnici
			}
			if(p[i].kolicina != 0){
				ukupnaVrijednost += p[i].cijena * p[i].kolicina;	// od 28. do 30. linije - izracun ukupne vrijednosti proizvoda ukoliko je kolicina veca od 0				
			}
			if(p[i].proizvodjac == "FIAT"){
				fiat++;						// od 31. do 33. linije - povecavanje brojaca koji broji proizvode FIATA
			}
			i++;							// povecavanje brojaca kojeg cemo kasnije koristiti za nizove
		}
	
		datoteka.close();		// zatvaranje datoteke
		cout << "Ukupan broj proizvoda je: " << br << endl;		// ispis ukupnog broja proizvoda
		cout << "Ukupna vrijednost svih proizvoda u prodavnici je: " << setprecision(2) << fixed << ukupnaVrijednost << endl; // ispis ukupne vrijednosti svih proizvoda u prodavnici
		cout << "Spisak proizvoda cija je trenutna kolicina nula: \n";
		int n = 1;
		for(int j=0; j<i; j++){
			if(p[j].kolicina == 0){
				cout << n << ". " << p[j].naziv << endl; 	// ispis naziva proizvoda cija je kolicina 0
				n++;
			}
		}
		cout << "Broj proizvoda koje proizvodi FIAT je: " << fiat << endl; // ispis broja proizvoda FIATA
	
		string temp1, temp2; 
		int temp3;				// od 50. do 52. linije - deklaracija pomocnih varijabli razlicitog tipa
		double pom;
		for(int j=0; j<i; j++){ // 53. i 54. linija - dvije for petlje za prolazak kroz niz
			for(int k=j+1; k<i; k++){ 
				if(p[j].cijena > p[k].cijena){	//sortiranje niza prema cijeni
					
					temp1 = p[j].naziv;
					p[j].naziv = p[k].naziv;  
					p[k].naziv = temp1;
					
					temp2 = p[j].proizvodjac;
					p[j].proizvodjac = p[k].proizvodjac;
					p[k].proizvodjac = temp2;
															// od 57. do 71. linije - izmjena razlicith varijabli uz pomoc pomocnih odnosno temp varijabli
					temp3 = p[j].kolicina;
					p[j].kolicina = p[k].kolicina;
					p[k].kolicina = temp3;
					
					pom = p[j].cijena;
					p[j].cijena = p[k].cijena;
					p[k].cijena = pom;
				}
			}
		}
		
		cout << "\nProizvodi sortirani po cijeni (od najnize do najvise)\n\n"; // ispis teksta
		cout << setw(15) << left << "NAZIV" << setw(15) << left << "PROIZVODJAC" << setw(15) << left << "KOLICINA" << setw(15) << left << "CIJENA (KM)" << endl; // ispis teksta u obliku tabele
		cout << "---------------------------------------------------------\n";
		
		for(int j=0; j<i; j++){
			cout << setw(15) << left << p[j].naziv << setw(15) << left << p[j].proizvodjac << setw(15) << left << p[j].kolicina << setw(15) << left << p[j].cijena << endl; // ispis sortiranih podataka vezanih za strukturu Proizvod
		}
		
	}else{
		cout << "Datoteka se ne moze otvoriti!\n"; // ispis u slucaju da datoteka nije otvorena
	}
	
	
	return 0;
}

