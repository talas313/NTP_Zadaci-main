#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
	ifstream datoteka;	// deklaracija objekta za citanje sa zeljene datoteke
	datoteka.open("Podaci.txt"); // otvaranje datoteke
	string ime, pol, godiste;	// deklaracija varijabli tipa string
	double prosjek;				// deklaracija varijable tipa double
	int brojZenskihOsoba = 0, brojOsobaSaPet = 0; // deklaracija brojaca zenskih osoba i brojaca osoba sa peticom
	while(!datoteka.eof()){
		datoteka >> ime >> pol >> godiste >> prosjek;
		if(pol == "zensko" || pol == "Zensko") brojZenskihOsoba++; // uslov koji ispituje da li je osoba zensko ako jeste povecava brojac zenskih osoba
		if(prosjek > 4.5) brojOsobaSaPet++;						   // uslov koji ispituje da li osoba ima prosjek veci od 4.5 ukoliko ima povecava se brojac osoba sa peticom 
	}
	datoteka.close();	// zatvaranje datoteke
	cout << "Unesi ime: "; 		// ispis teksta
	cin >> ime;					// smjestanje teksta u varijablu
	cout << "Unesi pol: ";		// ispis teksta
	cin >> pol;					// smjestanje teksta u varijablu
	cout << "Unesi godiste: ";	// ispis teksta
	cin >> godiste;				// smjestanje teksta u varijablu
	cout << "Unesi prosjek: ";	// ispis teksta
	cin >> prosjek;				// smjestanje teksta u varijablu
	ofstream dat("Podaci.txt", ios::app);		// deklaracija objekta za zapisivanje u zeljenu datoteku
	dat << endl << ime << " " << pol << " " << godiste << " " << prosjek;
	dat.close(); // zatvaranje datoteke
	
	cout << "Broj zenskih osoba: " << brojZenskihOsoba << endl; 	// ispis broja zensig osoba
	cout << "Broj osoba sa peticom: " << brojOsobaSaPet << endl;	// ispis broja osoba sa peticom
	return 0;
}
