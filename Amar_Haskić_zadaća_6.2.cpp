#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Apartman{		// deklaracija strukture
	string naziv; 	
	string mjesto; 		// od 9. do 12. linije - deklaracija varijabli razlicitog tipa
	int broj_kreveta; 
	int cijena; 
}p[10000]; 				// deklaracija i inicijalizacija niza koji prima podatke o apartmanima

int main (){
	setlocale(LC_ALL,"");
	fstream datoteka; 				// deklaracija objekta u koji se smjesta datoteka zeljena datoteka
	datoteka.open("apartmani.txt"); // otvaranje datoteke u kojoj su smjesteni podaci o apartmanima
	int i=0, paralia=0, min;		// deklaracija brojaca niza, brojaca apartmana u mjestu Paralia i 
									// varijable min 
	float suma=0;  					// deklaracija i inicijalizacija varijable suma
	
	if(datoteka.is_open()){ 		// ispitivanje uslova, ukoliko je uslov ispunjen izvrsava se zadani zadatak
	
		while(datoteka >> p[i].naziv >> p[i].mjesto>> p[i].broj_kreveta >> p[i].cijena){ // while petlja while petlja koja radi do zavrsetka datoteke i uzima podatke iz svake linije smjestene u neku od varijabli iz strukture Apartman	
			if(datoteka){
				suma+=p[i].cijena;		// izracun sume koja je potrebna za dobijanje prosjecne cijene
			}
				
			if(p[i].mjesto=="Paralia"){ 
				paralia++; 				//  od 29. do 31. linije - povecavanje brojaca koji broji apartmane u mjestu Paralia
			} 
			i++; 
		}
		
		datoteka.close(); 	// zatvaranje datoteke
		cout << "Ukupan broj apartmana je: " << i << endl;  				// ispis ukupnog broja apartmana
		cout << "Prosjecna cijena apartmana je: " << suma/i << endl; 		// ispis prosjecne cijene apartmana
		cout << "Broj apartmana u mjestu Paralia je: " << paralia << endl; 	// ispis broja apartmana u mjestu Paralia
	
	
		string ime;					// deklaracija varijable 
		double min = p[0].cijena;	// deklaracija i inicijalizacija varijable min
	
		for(int j=0; j<i; j++){
			if (p[j].broj_kreveta==2){	
	  			if(min>=p[j].cijena){	
					min = p[j].cijena;  //  u 45. i 46. liniji - ispitivanje uslova koji ako se ispune izvrsava se zadani zadatak
					ime = p[j].naziv;	// min postaje najmanja cijena apartmana za 2 osobe, a varijabla ime dobija naziv tog apartmana
				}
	  		}	
		}
		cout << "Naziv apartmana za 2 osobe s najnizom cijenom je: " << ime << endl; //ispis naziva apartmana	
		
		string temp1,temp2; 
		int temp3; 			// od 54. do 56. linije - deklaracija pomocnih varijabli razlicitog tipa
		double pom; 
		for(int j=0; j<i; j++){  		// 57. i 58. linija - dvije for petlje za prolazak kroz niz
			for(int k=j+1; k<i; k++){  
				if(p[j].cijena>p[k].cijena){  	// sortiranje niza prema cijeni				
					
					temp1= p[j].naziv;
					p[j].naziv = p[k].naziv;
					p[k].naziv = temp1;
					
					temp2 = p[j].mjesto;
					p[j].mjesto = p[k].mjesto;
					p[k].mjesto = temp2;
												//  od 61. do 76. linije - izmjena razlicith varijabli uz pomoc pomocnih odnosno temp varijabli
					temp3 = p[j].broj_kreveta;
					p[j].broj_kreveta = p[k].broj_kreveta;
					p[k].broj_kreveta = temp3;
					
					pom = p[j].cijena;
					p[j].cijena = p[k].cijena;
					p[k].cijena = pom;
				}
			}
		}
		
		cout << "\nApartmani sortirani po cijeni (od najnize do najvise)\n\n";  // ispis teksta
		cout << setw(15) << left << "NAZIV" << setw(15) << left << "MJESTO" << setw(15) << left << "BROJ KREVETA" << setw(15) << left << "CIJENA (KM)" << endl;  // ispis teksta u obliku tabele
		cout << "---------------------------------------------------------\n";
	
		for(int j=0; j<i; j++){ 
			cout << setw(15) << left << p[j].naziv << setw(15) << left << p[j].mjesto << setw(15) << left << p[j].broj_kreveta << setw(15) << left << p[j].cijena << endl;  // ispis sortiranih podataka vezanih za strukturu
		}
		
	}else{ 
		cout << "Datoteka se ne moze otvoriti!" << endl; // ispis u slucaju da datoteka nije otvorena
	}
	
	return 0;
}
