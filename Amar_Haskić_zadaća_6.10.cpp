#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
	ifstream datoteka;	// deklaracija objekta za citanje sa zeljene datoteke
	datoteka.open("Ocjene.txt"); // otvaranje datoteke
	int temp, sumaEng = 0, brojEng = 0, sumaNjem = 0, brojNjem = 0, brojPetEng = 0, brojPetNjem = 0; // deklaracija pomocne varijable, te suma, brojaca i brojaca petica iz stranih jezika
	string temp1, temp2, jezik, brojUcenika; // deklaracija varijabli tipa string
	
	getline(datoteka, brojUcenika); // uzima broj ucenika koji je zapisan u prvom redu datoteke
	
	while(!datoteka.eof()){								// while petlja koja se izvrsava dok ne dodje do kraja datoteke
		datoteka >> temp1 >> temp2 >> jezik >> temp; 
		if(jezik == "engleski" || jezik == "Engleski"){ // ispitivanje uslova da li je strani predmet kod ucenika engleski
			sumaEng += temp;			// racunanje ukupnog broja ucenika ciji je strani jezik engleski
			brojEng++;					// povecavanje brojaca koji broji ucenike ciji je strani jezik engleski
			if(temp == 5) brojPetEng++; // ispitivanje uslova koji ako je ispunjen povecava brojac ucenika koji imaju peticu iz engleskog jezika
		}else{
			sumaNjem += temp;		    	// racunanje ukupnog broja ucenika ciji je strani jezik njemacki
			brojNjem++;				    	// povecavanje brojaca koji broji ucenike ciji je strani jezik njemacki
			if(temp == 5) brojPetNjem++;	// ispitivanje uslova koji ako je ispunjen povecava brojac ucenika koji imaju peticu iz njemackog jezika
		}
	}
	
	cout << "Prosjecna ocjena iz engleskog je: " << setprecision(2) << double(sumaEng)/brojEng << endl;		// ispis prosjecne ocjene iz engleskog jezika
	cout <<	"Prosjecna ocjena iz njemackog je: " << setprecision(2) << double(sumaNjem)/brojNjem << endl;	// ispis prosjecne ocjene iz njemackog jezika
	cout << "Broj petica iz engleskog je: " << setprecision(2) << brojPetEng << endl;						// ispis broja ucenika sa peticom iz engleskog jezika
	cout << "Broj petica iz njemackog je: " << setprecision(2) << brojPetNjem << endl;						// ispis broja ucenika sa peticom iz njemackog jezika
	
	datoteka.close();		// zatvaranje datoteke
	
	return 0;
}
