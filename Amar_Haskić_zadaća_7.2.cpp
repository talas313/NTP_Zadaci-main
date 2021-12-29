#include<iostream> 
#include<conio.h>
#include<string>

using namespace std;

class Book {
	private:
		string isbn,title,author,edition,publication; //privatne varijable
	public:
		//setteri -> dodjeljivanje korisnicke vrijednosti privatnim varijablama
		void setIsbn(string a){isbn = a;}
		void setTitle(string b){title = b;}
		void setAuthor(string c){author = c;}
		void setEdition(string d){edition = d;}
		void setPublication(string e){publication = e;}
		//getteri -> za dobavljanje vrijednosti iz privatnih varijabli
		string getIsbn(){return isbn;}
		string getTitle(){return title;}
		string getAuthor(){return author;}
		string getEdition(){return edition;}
		string getPublication(){return publication;}
};
//incijalizacija funkcija sa brojacem kao parametar
void addBook(int counter);
void deleteBook(int counter);
void editBook(int counter);
void searchBook(int counter);
void viewAllBooks(int counter);
void quit();
//brojac za knjige
int counter=0;
//funkcija za povecanje brojaca -> inkrement
void increment(int a){
	a++;
	counter=a;
}
//funkcija za smanjenje brojaca ->dekrement
void decrement(int a){
	a--;
	counter=a;
}
//Book (knjiga) klasa niza
Book books[1000];

int main(){
	string choice;
	system("CLS");
	cout<<"SISTEM ZA KNJIGE\n\n";
	cout<<"\t1. DODAJ KNJIGU\n";	
	cout<<"\t2. OBRISI KNJIGU\n";	
	cout<<"\t3. EDITUJ KNJIGU\n";	
	cout<<"\t4. PRETRAZI KNJIGU\n";	
	cout<<"\t5. POGLEDAJ SVE KNJIGE\n";	
	cout<<"\t6. IZLAZ\n\n";
	
	cout<<"VAS ODABIR: ";
	getline(cin,choice);
	system("CLS");
	
	if(choice=="1"){
		addBook(counter); 
	}		
	else if(choice=="2"){	
		deleteBook(counter); 
	}
	else if(choice=="3"){
		editBook(counter); 
	}
	else if(choice=="4"){
		searchBook(counter); 
	}
	else if(choice=="5"){
		viewAllBooks(counter);
	}
	else if(choice=="6"){
		quit();	
	}
	else{
		main(); 
	}
		
	_getch();
	return 0;
}


void addBook(int counter){
	string isbn,title,author,edition,publication;
	cout<<"DODAJ KNJIGU\n\n";
	if(counter<10){
		cout<<"Unesite ISBN: ";
		getline(cin,isbn); 
		cout<<"Unesite ime knjige: ";
		getline(cin,title);
		cout<<"Unesite autora: ";
		getline(cin,author);
		cout<<"Unesite izdanje: ";
		getline(cin,edition);
		cout<<"Unesite izdavaca: ";
		getline(cin,publication);
		books[counter].setIsbn(isbn); //dodavanje vrijednosti unesenim knjigama
		books[counter].setTitle(title);
		books[counter].setAuthor(author);
		books[counter].setEdition(edition);
		books[counter].setPublication(publication);	
		increment(counter);	//pozivanje funkcije za uvecanje
		cout<<"\n!KNJIGA USPJESNO DODANA!\n\nPritisnite enter za nastavak . . .";
		_getch();
		main();
	}
	else{
		cout<<"DOSTIGLI STE MAKSIMALAN BROJ UNOSA KNJIGA KOJE MOGU BITI DODANE!\n\nPritisnite enter za nastavak . . .";
		_getch();
		main();
	}
}


void deleteBook(int counter){
	string isbn;
	int choice;
	cout<<"OBRISI KNJIGU\n\n";
	if(counter==0){
		cout<<"! NEMA KNJIGA ZA OBRISAT :( !\n\nPritisnite enter za nastavak . . .";
		_getch();
		main();
	}
	cout<<"Unesite ISBN: ";
	getline(cin,isbn);
//pronalazanje mecinga pomocu for petlje
	for(int i=0;i<counter;i++){
		if(books[i].getIsbn()==isbn){
			cout<<"\nKNJIGA PRONADJENA\n\n";
			cout<<"Da li zaista zelite obrisati?\n[1]Da\n[2]Ne\n\nUnesite odabir: ";
			cin>>choice;
			if(choice==1){
				books[i].setIsbn(""); //postavljanje vrijednosti na 0
				books[i].setTitle("");
				books[i].setAuthor("");
				books[i].setEdition("");
				books[i].setPublication("");
				for(int a=i;a<counter;a++){
					books[a] = books[a+1];
				}
				books[999].setIsbn(""); //dodjeljivanje ako je biblioteka puna 1000
				books[999].setTitle("");
				books[999].setAuthor("");
				books[999].setEdition("");
				books[999].setPublication("");
				decrement(counter); 
				cout<<"\n!KNJIGA USPJESNO IZBRISANA!\n\nPritisnite enter za nastavak . . .";
				_getch();
				main();
			}
			else{
				main();
			}
		}
	}
	cout<<"\n!KNJIGA NIJE PRONADJENA!\n\nPritisnite enter za nastavak . . .";
	_getch();
	main();
	
}
void editBook(int counter){
	system("CLS");
	string editIsbn,choice;
	string isbn,title,author,edition,publication;
	cout<<"\nUREDITE KNJIGU\n\n";
	if(counter==0){
		cout<<"! NEMA KNJIGA ZA UREDJIVANJE :( !\n\nPritisnite enter za nastavak . . .";
		_getch();
		main();
	}
	cout<<"Unesite ISBN: ";
	getline(cin,editIsbn);
	for(int i=0;i<counter;i++){
		//finding a match using for loop
		if(books[i].getIsbn()==editIsbn){
			cout<<"\nKNJIGA PRONADJENA!\n\n";
			cout<<"ISBN: "<<books[i].getIsbn()<<endl;
			cout<<"NAZIV KNJIGE: "<<books[i].getTitle()<<endl;
			cout<<"AUTOR KNJIGE: "<<books[i].getAuthor()<<endl;
			cout<<"IZDANJE KNJIGE: "<<books[i].getEdition()<<endl;
			cout<<"IZDAVAC: "<<books[i].getPublication()<<endl;
			cout<<"\nDa li zaista zelite urediti knjig?\n[1]Da\n[2]Ne\n\nUnesite odabir: ";
			getline(cin,choice);
			if(choice=="1"){
				cout<<"Unesite ISBN: ";
				getline(cin,isbn);
				cout<<"Unesite naziv knjige: ";
				getline(cin,title);
				cout<<"Unesite autora: ";
				getline(cin,author);
				cout<<"Unesite izdanje: ";
				getline(cin,edition);
				cout<<"Unesite izdavaca: ";
				getline(cin,publication);
				books[i].setIsbn(isbn);
				books[i].setTitle(title);
				books[i].setAuthor(author);
				books[i].setEdition(edition);
				books[i].setPublication(publication);	
				cout<<"\nKJNIGA USPJESNO UREDJENA!\n\nPritisnite enter za nastavak . . .";
				_getch();
				editBook(counter);
			}
			else{
				main();
			}			
		}
}
	cout<<"\n!KNJIGA NIJE PRONADJENA :(!\n\nPritisnite enter za nastavak . . .";
	_getch();
	main();
}
void searchBook(int counter){
	string isbn;
	int choice;
	bool print = false; //bool ekspresija da odredi sta da baci na ekran (printa)
	cout<<"PRETRAZI KNJIGE\n\n";
	if(counter==0){
		cout<<"! NEMA PRONADJENIH KNJIGA :( !\n\nPritisnite enter za nastavak . . .";
		_getch();
		main();
	}
	cout<<"Unesite ISBN: ";
	getline(cin,isbn);
	for(int i=0;i<counter;i++){
		if(books[i].getIsbn()==isbn){ 
			cout<<"\nKNJIGA PRONADJENA!\n\n";
			cout<<"ISBN: "<<books[i].getIsbn()<<endl;
			cout<<"NAZIV KNJIGE: "<<books[i].getTitle()<<endl;
			cout<<"AUTOR KNJIGE: "<<books[i].getAuthor()<<endl;
			cout<<"IZDANJE KNJIGE: "<<books[i].getEdition()<<endl;
			cout<<"IZDAVAC: "<<books[i].getPublication()<<endl;
			print = true;
		}
	}
	if(print){
		cout<<"\n\nPritisnite enter za nastavak . . .";
		_getch();
		main();
	}
	else{
		cout<<"\n!KNJIGA NIJE PRONADJENA :( \n\nPritisnite enter za nastavak . . .";
		_getch();
		main();		
	}
}
void viewAllBooks(int counter){
	//iteracija sa svim vrijednostima biblkioteke koristeci niz knjiga
	cout<<"POGLEDAJTE SVE KNJIGE U BAZI\n\n";
	for(int i=0;i<counter;i++){
		cout<<"DETALJI KNJIGE\n\n";
		cout<<"ISBN: "<<books[i].getIsbn()<<endl;
		cout<<"NAZIV KNJIGE: "<<books[i].getTitle()<<endl;
		cout<<"AUTOR KNJIGE: "<<books[i].getAuthor()<<endl;
		cout<<"IZDANJE KNJIGE: "<<books[i].getEdition()<<endl;
		cout<<"IZDAVAC: "<<books[i].getPublication()<<endl<<endl;
	}
	cout<<"Pritisnite enter za nastavak . . .";
	_getch();
	main();
}
void quit(){
	//izlaz
	_exit(1);
}
