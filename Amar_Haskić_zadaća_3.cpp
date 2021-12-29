#include <iostream>
#include <cstring>
using namespace std;

int ispravna(char* adresa){										//deklaracija funkcije
	string ba = ".ba";											//deklaracija stringa
	for(int i=0;i<strlen(adresa);i++){							//petlja za adresu
		if(adresa[i] == '@'){									//da li ima "@" u adresi
			for(i;i<strlen(adresa);i++){						//petlja od "@" do kraja adrese
				if(adresa[i] == '.'){							//da li ima "." u adresi
					if(strrchr(adresa,'.') == ba)return 1;		//da li ima ".ba" na kraju adrese i ako je sve tacno vrati 1
				}
			}
		}
	}return 0;													//ako nesto nije tacno vrati 0
}
int main(){
	char a[20];													//deklaracija niza karaktera
	cout << "Unesi adresu:";									//ispis za unos adrese
	cin >> a;													//unos adrese
	cout << ispravna(a);										//ispis pozvane funkcije
	
	
	return 0;
}

