# include <iostream> 
# include <string> 
# include <vector> 
using namespace std; 
int main(){  
	vector<string> a; 
	//unos broja rije�i
	int n; 
	cout << "Unesi broj rijeci: "; 
	cin >> n; 
	//unos rije�i u vektor
	for (int i=0; i<n; i++){ 
		cout << i+1 << ". "; 
		string pom; 
		cin >> pom; 
		a.push_back(pom); 
		} 
	//sortiranje rije�i po abecednom redu
	string pom; 
	for (int i=0;i<(a.size()-1);i++)     
		for (int j=i+1;j<a.size();j++)         
			if (a[j]<a[i]){             
				pom=a[i];             
				a[i]=a[j];             
				a[j]=pom; } 
	//ispis prve i zadnje rije�i
	cout << "Prva rijec je: " << a[0] << " a zadnja " << a[a.size()-1] << endl; 
	//ispis svih rije�i bez ispisa rije�i koje se ponavljaju
	cout << endl << "Ispis rijeci: " << endl; 
	a.push_back(""); 
	for (int i=0, j=0; i<a.size()-1; i++){ 
		if ((a[i]!=a[i+1])) { 
			cout << j+1 << ". " << a[i] << endl; 
			j++; } 
		} 
	 
	return 0; 
}
