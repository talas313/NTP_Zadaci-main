#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


struct Radnik{ 		// deklaracija strukture
	string ime; 
	string prezime; 	
	int radniStaz; 		// od 9. do 13. linije - deklaracija varijabli razlicitog tipa
	int strucnaSprema;
	int plata; 
}p[10000]; 				// deklaracija i inicijalizacija niza koji prima podatke o radnicima


int main (){
	setlocale(LC_ALL,"");
	fstream datoteka; 		// deklaracija objekta u  koji se smjesta datoteka zeljena datoteka
	datoteka.open("radnici.txt"); // otvaranje datoteke
	int i=0, br1=0;		// deklaracija brojaca za niz i brojaca koji broji radnike sa radnim stazom vecim od 5 godina
	float suma=0;
	  
	if(datoteka.is_open()){ 
		while(datoteka >> p[i].ime >> p[i].prezime>> p[i].radniStaz >> p[i].strucnaSprema >> p[i].plata){ // while petlja koja radi do zavrsetka datoteke i uzima podatke iz svake linije smjestene u neku od varijabli iz strukture Radmik
			if(datoteka){
				suma+=p[i].plata;	// racunanje sume koja se koristi za racunanje prosjecne plate
			}
				
			if(p[i].radniStaz>5){ 	// uslov za provjeru radnog staza radnika
				br1++; 				// povecavanje brojaca koji broji radnike sa radnim stazom vecim od 5 godina
			} 
			i++; 
		}
		datoteka.close(); 	// zatvaranje datoteke
		cout << "Ukupan broj radnika je: " << i << endl; // ispis teksta
		cout << "Prosjecna plata radnika je: " << suma/i << endl; // ispis teksta
		cout << "Broj radnika sa vise od 5 godina radnog staza je: " << br1 << endl; // ispis teksta
		
		string ime1;					// deklaracija varijable u koju se smjesta ime radnika sa najvecim stepenom strucne spreme
		double max=p[0].strucnaSprema;	// deklaracija varijable max kojoj dajemo vrijednost stepena strucne spreme prvog radnika

		for(int j=0; j<i; j++){
			if(max<p[j].strucnaSprema){		// uslov u kojem ukoliko je max manje od p[j].strucnaSprema
				max=p[j].strucnaSprema;			 
				ime1=p[j].ime;	 
			}
		}
		cout << "Ime radnika s najvecim stepenom strucne spreme: " << ime1 << endl;	// ispis imena radnika sa najvecim stepenom strucne spreme
		
		string temp1,temp2; 
		int temp3; 				// od 49. do 51. - deklaracija pomocnih varijabli razlicitog tipa
		double pom; 
		for(int j=0; j<i; j++){  
			for(int k=j+1; k<i; k++){  
				if(p[j].ime>p[k].ime){  
				
					temp1= p[j].ime;
					p[j].ime = p[k].ime;
					p[k].ime = temp1;
					
					temp2 = p[j].prezime;
					p[j].prezime = p[k].prezime;
					p[k].prezime = temp2;
														// od 56. do 70. linije - izmjena razlicith varijabli uz pomoc pomocnih odnosno temp varijabli
					temp3 = p[j].radniStaz;
					p[j].radniStaz = p[k].radniStaz;
					p[k].radniStaz = temp3;
					
					pom = p[j].strucnaSprema;
					p[j].strucnaSprema = p[k].strucnaSprema;
					p[k].strucnaSprema = pom;
				}
			}
		}
			
		cout << "\nRadnici sortirani po imenima (abecednim redom)\n\n";  //
		cout << setw(15) << left << "IME" << setw(15) << left << "PREZIME" << setw(15) << left << "RADNI STAZ" << setw(15) << left << "STRUCNA SPREMA"  << setw(15) << left << "PLATA" << endl; // ispis teksta u obliku tabele
		cout << "------------------------------------------------------------------\n";
		
		for(int j=0; j<i; j++){ 
			cout << setw(15) << left << p[j].ime << setw(15) << left << p[j].prezime << setw(15) << left << p[j].radniStaz << setw(15) << left << p[j].strucnaSprema << setw(15) << left << p[j].plata<<endl; // ispis sortiranih podataka vezanih za strukturu Radnik
		}
						
	}else{
		cout << "Datoteka se ne moze otvoriti!" << endl; // ispis u slucaju da datoteka nije otvorena
	}
	
	return 0;
}
