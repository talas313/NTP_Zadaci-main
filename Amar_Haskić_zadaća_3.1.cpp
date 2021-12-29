#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Datum{
	int dan,mjesec,godina;
};

Datum fdatum(char *jmbg){
	Datum datum;
	string sJmbg = jmbg;
	datum.dan = stoi(sJmbg.substr(0,2));
	datum.mjesec = stoi(sJmbg.substr(2,2));
	datum.godina = stoi(sJmbg.substr(4,3));
	if(jmbg[4] == '0'){
		datum.godina += 2000;
	}else{
		datum.godina += 1000;
	}
	cout << "Datum roğenja osobe èiji je jmbg " << jmbg << " je " << datum.dan << "." << datum.mjesec << "." << datum.godina;
}

int main(){
	setlocale(LC_ALL,"");
	char jmbg[13];
	do{
		cout << "Unesite jmbg: ";
		cin >> jmbg;
		if(strlen(jmbg) != 13){
			cout << "Unijeti jmbg nije ispravan!\n";
		}
	}while(strlen(jmbg) != 13);
	fdatum(jmbg);
	
	
	return 0;
}

