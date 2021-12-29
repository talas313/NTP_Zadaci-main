#include <iostream>
using namespace std;

struct Recenica{
	char* pRecenica = new char[100];
};

int main(){
	setlocale(LC_ALL,"");
	int n;
	cout << "Unesite broj re�enica: ";
	cin >> n;
	cin.ignore();
	Recenica recenica[n];
	for(int i=0;i<n;i++){
		cout << "Unesite " << i+1 << ". re�enicu: ";
		cin.getline(recenica[i].pRecenica,100);
	}
	cout << "Re�enice koje ste unijeli su: \n";
	for(int i=0;i<n;i++){
		cout << i+1 << ". " << recenica[i].pRecenica << endl;
	}
	char* temp=0;
	for(int i=0;i<n;i++)
	{		
		for(int j=i+1;j<n;j++)
		{
			if(int(*recenica[i].pRecenica)>int(*recenica[j].pRecenica))
			{
				temp = recenica[i].pRecenica;
				recenica[i].pRecenica = recenica[j].pRecenica;
				recenica[j].pRecenica = temp;
			}
		}
	}
	cout << "Re�enice nakon sortiranja: \n";
	for(int i=0;i<n;i++){
		cout << i+1 << ". " << recenica[i].pRecenica << endl;
	}
		
	return 0;
}

