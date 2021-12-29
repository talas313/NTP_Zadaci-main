#include <iostream>
using namespace std;
//deklaracija strukture
struct Skladiste{
	string nazivRobe;
	int brojSkladista;
	int kolicinaRobe;
	double cijenaRobe;
	string imeDobavljaca;
	int minimalnaKolicina;
};
int main(){
	setlocale(LC_ALL,"");
	//deklaracija i unos broja artikala
	int brojArtikala;
	cout << "Unesite broj artikala koje zelite unijeti u skladiste: ";
	cin >> brojArtikala;
	//deklaracija niza strukture
	Skladiste skladiste[brojArtikala];
	//unos podataka artikala u strukturu
	for(int i=0;i<brojArtikala;i++){
		cout << "--------------------------------------------------\n"; 
		cout << "Unos podataka za " << i+1 << ". artikal: \n";
		cout << "--------------------------------------------------\n";
		cout << "Naziv:";
		cin >> skladiste[i].nazivRobe;
		cout << "Broj skladista: ";
		cin >> skladiste[i].brojSkladista;
		cout << "Kolicina robe: ";
		cin >> skladiste[i].kolicinaRobe;
		cout << "Cijena: ";
		cin >> skladiste[i].cijenaRobe;
		cout << "Ime dobavljaca: ";
		cin >> skladiste[i].imeDobavljaca;
		cout << "Minimalna kolicina: ";
		cin >> skladiste[i].minimalnaKolicina;
	}
	//ispis podataka artikala iz strukture
	for(int i=0;i<brojArtikala;i++){
		cout << "--------------------------------------------------\n";
		cout << "Ispis podataka " << i+1 << ". artikla:\n";
		cout << "--------------------------------------------------\n";
		cout << "Naziv: \t\t\t\t" << skladiste[i].nazivRobe << endl;
		cout << "Broj skladista: \t\t" << skladiste[i].brojSkladista << endl;
		cout << "Kolicina robe: \t\t\t" << skladiste[i].kolicinaRobe << endl;
		cout << "Cijena: \t\t\t" << skladiste[i].cijenaRobe << endl;
		if(skladiste[i].kolicinaRobe<skladiste[i].minimalnaKolicina){
			cout << "Ime dobavljaca: \t\t" << skladiste[i].imeDobavljaca << endl;
		}
	}
	
	return 0;
}

