#include <iostream>
using namespace std;
//deklaracija strukture
struct Cvor{
	string ime_i_prezime;
	double prosjek;
	Cvor* veza;
};
int main(){
	setlocale(LC_ALL,"");
	int brojac = 0;
	Cvor cvor[1000];
	//petlja za unos podataka u strukturu dok se ne pritisne ENTER
	for(int i=0;i<1000;i++){
		cout << "Unesite ime i prezime: ";
		getline(cin,cvor[i].ime_i_prezime);
		if(cvor[i].ime_i_prezime.empty()){
			break;	
		}
		cout << "Unesite prosjek: ";
		cin >> cvor[i].prosjek;
		cin.ignore();
		brojac++;
		cout << "--------------------------------------------------\n";
	}
	//sortiranje strukture
	for(int i=0;i<brojac;i++){    
		for (int j=i+1;j<brojac+1;j++){
			if (cvor[j].prosjek>cvor[i].prosjek){             
				string temp1=cvor[i].ime_i_prezime;             
				cvor[i].ime_i_prezime=cvor[j].ime_i_prezime;             
				cvor[j].ime_i_prezime=temp1;
				double temp2=cvor[i].prosjek;             
				cvor[i].prosjek=cvor[j].prosjek;             
				cvor[j].prosjek=temp2;
			}else if(cvor[j].prosjek==cvor[i].prosjek){
				int duzaRijec = 0;
				if(cvor[i].ime_i_prezime.length()>cvor[j].ime_i_prezime.length()){
					duzaRijec = cvor[i].ime_i_prezime.length();
				}else{
					duzaRijec = cvor[j].ime_i_prezime.length();
				}
				for(int k=0;k<duzaRijec;k++){
					if(cvor[i].ime_i_prezime[k]>cvor[j].ime_i_prezime[k]){
					string temp=cvor[i].ime_i_prezime;             
					cvor[i].ime_i_prezime=cvor[j].ime_i_prezime;             
					cvor[j].ime_i_prezime=temp;	
					}
				}
			}
		}
	}
	//ispis strukture
	cout << "--------------------------------------------------\n";
	cout << "Imena studenata:\t\t\tProsjek:\n";
	for(int i=0;i<brojac;i++){
		cout << "\t\t" << cvor[i].ime_i_prezime << "\t\t\t\t" << cvor[i].prosjek << endl;
	}
	
	return 0;
}

