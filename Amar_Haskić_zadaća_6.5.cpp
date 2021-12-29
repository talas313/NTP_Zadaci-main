#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Klijent{ 			// deklaracija strukture
	string ime; 
	string prezime; 
	string mjesto; 			// deklaracija varijabli razlicitog tipa
	int telBroj;
	double posljednjiRacun; 
}p[10000]; 					// deklaracija i inicijalizacija niza koji sprema podatke o klijentima
int main (){
	setlocale(LC_ALL,"");
	fstream datoteka; 		// deklaracija objekta u koji se sprema zeljena datoteka
	datoteka.open("klijenti.txt"); // otvaranje datoteke
	int i=0, br=0, br1=0;		// deklaracija brojaca koji se koristi za niz, brojaca svih klijenata i brojaca klijenata iz Zenice
	float suma=0;  
	if(datoteka.is_open()){ 
	
		while(datoteka >> p[i].ime >> p[i].prezime>> p[i].mjesto >> p[i].telBroj >> p[i].posljednjiRacun){ // while petlja koja radi do zavrsetka datoteke i uzima podatke iz svake linije smjestene u neku od varijabli iz strukture Klijent
			if(datoteka){
			suma += p[i].posljednjiRacun;
			br++;		
			}	
				
			if(p[i].mjesto=="Zenica"){  // uslov za provjeru mjesta klijenta
				br1++;					// brojac koji se povecava sa svakim klijentom iz Zenice
			}
			i++; 
		}
		datoteka.close(); 			// zatvaranje datoteke
		cout << "Ukupan broj klijenata je: " << br << endl; // ispis teksta
		cout<<"Prosjecan racun za posljednji mjesec je: "<<suma/br<<endl; // ispis teksta
		cout << "Broj klijenata iz Zenice je: " << br1 << endl;  // ispis teksta
		
		string ime1;							// deklaracija varijable u koju se smjesta ime klijenta sa najvecim posljednjim racunom
		int broj1;								// deklaracija varijable u koju se smjesta broj tog klijenta 
		double max = p[0].posljednjiRacun;		// deklaracija varijable max i pridruzivanje vrijednosti posljednjeg racuna prvog klijenta toj varijabli

		for(int j=0; j<i; j++){
			if(max<p[j].posljednjiRacun){	
				max = p[j].posljednjiRacun;
				ime1 = p[j].ime;	
				broj1 = p[j].telBroj; 
			}
		}
	
		cout << "Ime klijenta s najvecim posljednjim racunom je: " << ime1 << endl;		// ispis teksta 
		cout << "Telefonski broj tog klijenta je: " << broj1 << endl;					// ispis teksta
	
		string temp1, temp2, temp3; 
		int temp4; 								// od 53. do 55. linije - deklaracija pomocnih varijabli razlicitog tipa
		double pom; 
		for(int j=0; j<i; j++){  				// 56. i 57. linija - dvije for petlje za prolazak kroz niz
			for(int k=j+1; k<i; k++){  
				if(p[j].prezime>p[k].prezime){  // sortiranje niza po prezimenima
			
					temp1= p[j].ime;
					p[j].ime = p[k].ime;
					p[k].ime = temp1;
					
					temp2 = p[j].prezime;
					p[j].prezime = p[k].prezime;
					p[k].prezime = temp2;
					
					temp3 = p[j].mjesto;
					p[j].mjesto	 = p[k].mjesto;			// od 60. do 78. linije - izmjena razlicith varijabli uz pomoc pomocnih odnosno temp varijabli
					p[k].mjesto = temp3;
					
					temp4 = p[j].telBroj;
					p[j].telBroj = p[k].telBroj;
					p[k].telBroj = temp4;
					
					pom = p[j].posljednjiRacun;
					p[j].posljednjiRacun = p[k].posljednjiRacun;
					p[k].posljednjiRacun = pom;
				}
			}
		}
	
		cout << "\nKlijenti sortirani po prezimenima (abecednim redom)\n\n";  	// ispis teksta	
		cout << setw(15) << left << "IME" << setw(15) << left << "PREZIME" << setw(15) << left << "MJESTO" << setw(15) << left << "TEL. BROJ" << setw(15) << left << "POSLJEDNJI RACUN" << endl; // ispis teksta u obliku tabele
		cout << "-----------------------------------------------------------------------\n";

		for(int j=0; j<i; j++){ 
			cout << setw(15) << left << p[j].ime << setw(15) << left << p[j].prezime << setw(15) << left << p[j].mjesto << setw(15) << left << p[j].telBroj << p[j].posljednjiRacun << endl; // ispis sortiranih podataka vezanih za strukturu  
		}
	
	}else{ 
		cout << "Datoteka se ne moze otvoriti!" << endl; // ispis u slucaju da datoteka nije otvorena
	}
	
	return 0;
}
