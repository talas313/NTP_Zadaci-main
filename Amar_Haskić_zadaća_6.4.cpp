#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Ucenik{ 					// deklaracija strukture
	string ime; 
	string prezime; 
	int razred; 				// deklracija varijabli razlicitog tipa
	int uspjeh;
	double prosjecna_ocjena; 
}p[10000]; 						// deklaracija i inicijalizacija niza koji sprema podatke o ucenicima

int main (){
	setlocale(LC_ALL,"");
	fstream datoteka; 				// deklaracija objekta u koji se smjesta zeljena biblioteka
	datoteka.open("ucenici.txt");   // otvaranje datoteke
	int i=0,br=0,br1=0;    			// deklaracija brojaca koji se koristi u nizovima, brojaca ucenika 4. razreda i brojaca svih ucenika
	float suma=0;  
	if(datoteka.is_open()){ 
	
		while(datoteka >> p[i].ime >> p[i].prezime>> p[i].razred >> p[i].uspjeh >> p[i].prosjecna_ocjena){ // while petlja koja radi do zavrsetka datoteke i uzima podatke iz svake linije smjestene u neku od varijabli iz strukture Ucenik
			if(datoteka){
				br1++;
			}
			if(p[i].razred==4){
				br++;				// if petlja koja povecava brojac ukoliko je trenutni ucenik, ucenik 4. razreda
			}
		
			if(p[i].uspjeh>4){ 
				cout <<"Ime ucenika sa odlicnim uspjehom: " << p[i].ime << endl;	// if petlja koja ispisuje imena ucenika sa odlicnim uspjehom u slucaju da je ispunjen uslov
			} 
			i++;
		}		
		datoteka.close(); // zatvaranje datoteke
		cout << "Ukupan broj ucenika je: " << br1 << endl;	   // ispis teksta
		cout << "Broj ucenika 4. razreda je: " << br << endl;  // ispis teksta
			
		string ime1;						// deklaracija varijable u koju se smjesta ime ucenika sa najboljom prosjecnom ocjenom
		double max=p[0].prosjecna_ocjena;	// deklaracija varijable max i priduzivanje prosjecne ocjene prvog ucenika toj varijabli

		for(int j=0; j<i; j++){
			if(max<p[j].prosjecna_ocjena){	
				max=p[j].prosjecna_ocjena;
				ime1=p[j].ime;	 
			}
		}
	
		cout << "Ime ucenika s najboljom prosjecnom ocjenom: " << ime1 << endl;	// ispis imena ucenika sa najboljom prosjecnom ocjenom
		
		string temp1,temp2; 
		int temp3,temp4; 		// od 52. do 54. linije - deklaracija pomocnih varijabli razlicitog tipa
		double pom; 
		for(int j=0; j<i; j++){ 	// 55. i 56. linija - dvije petlje za prolazak kroz niz
			for(int k=j+1; k<i; k++){  
				if(p[j].razred>p[k].razred){  
				
					temp1= p[j].ime;
					p[j].ime = p[k].ime;
					p[k].ime = temp1;
					
					temp2 = p[j].prezime;
					p[j].prezime = p[k].prezime;
					p[k].prezime = temp2;
						
					temp3 = p[j].razred;
					p[j].razred	 = p[k].razred;			// od 58. do 77. linije - izmjena razlicith varijabli uz pomoc pomocnih odnosno temp varijabli
					p[k].razred = temp3;
					
					temp4 = p[j].uspjeh;
					p[j].uspjeh = p[k].uspjeh;
					p[k].uspjeh  = temp4;
							
					pom = p[j].prosjecna_ocjena;
					p[j].prosjecna_ocjena = p[k].prosjecna_ocjena;
					p[k].prosjecna_ocjena  = pom;
				}	
			}
		}
	
		cout << "\nImena ucenika sortiranih po razredima (1-4)\n\n";  // ispis teksta
		cout << setw(15) << left << "IME" << setw(15) << left << "RAZRED" << endl; // ispis teksta u obliku tabele
		cout << "-----------------------------------------------------------------------\n";

		for(int j=0; j<i; j++){ 
			cout << setw(15) << left << p[j].ime << setw(15) << left << p[j].razred <<endl; // ispis sortiranih podataka vezanih za strukturu Ucenik
		}
	
	}else{ 
		cout << "Datoteka se ne moze otvoriti!" << endl; // ispis u slucaju da datoteka nije otvorena
	}
	
	return 0;
}
