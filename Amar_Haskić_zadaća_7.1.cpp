#include <iostream>
using namespace std;
class Robot{
	public:
		double x,y,ugao;
		double pomak;
		double okretLijevo,okretDesno;
		void Postavi(){
			cout<<"Unesite koordinatu x: ";
			cin>>x;
			cout<<"Unesite koordinatu y: ";
			cin>>y;
			cout<<"Unesite ugao: ";
			cin>>ugao;
			if(ugao<0){
				ugao=360+ugao;
			}else if(ugao>=360){
				ugao=ugao-360;
			}
			Ispis();
		}
		void IdiNaprijed(double pomak){
			cout<<"Unesite za koliko se robot treba pomjeriti naprijed: ";
			cin>>pomak;
			x+=pomak;
			y+=pomak;
			Ispis();
		}
		void IdiNazad(double pomak){
			cout<<"Unesite za koliko se robot treba pomjeriti nazad: ";
			cin>>pomak;
			x-=pomak;
			y-=pomak;
			Ispis();
		}
		void OkreniSeNalijevo(double okretLijevo){
			cout<<"Unesite za koliko se robot treba okrenuti na lijevu stranu: ";
			cin>>okretLijevo;
			ugao+=okretLijevo;
			if(ugao<0){
				ugao=360+ugao;
			}else if(ugao>360){
				ugao=ugao-360;
			}
			Ispis();
		}
		void OkreniSeNadesno(double okretDesno){
			cout<<"Unesite za koliko se robot treba okrenuti na desnu stranu: ";
			cin>>okretDesno;
			ugao-=okretDesno;
			if(ugao<0){
				ugao=360+ugao;
			}else if(ugao>360){
				ugao=ugao-360;
			}
			Ispis();
		}
		double DajPozicijuX() const{
			return x;
		}
		double DajPozicijuY() const{
			return y;
		}
		double DajOrijentaciju() const{
			return ugao;
		}
		void Ispis() const{
			cout<<"------------------------------------------------------------------------------------------"<<endl;
			cout<<"Robot se nalazi na poziciji ("<<x<<","<<y<<") i gleda pod uglom od "<<ugao<<" stepeni u odnosu na x osu"<<endl;
			cout<<"------------------------------------------------------------------------------------------"<<endl;
		}
};
int main(){
	Robot r;
	int operacija;
	r.Postavi();
	do{
		cout << "Odaberite operaciju koju zelite:\n\t1. Naprijed\n\t2. Nazad\n\t3. Lijevo\n\t4. Desno\n\t5. Izlaz\n";
		cout << "Unesite izbor:";
		cin >> operacija;
		switch(operacija){
			case 1:
				r.IdiNaprijed(r.pomak);
				break;
			case 2:
				r.IdiNazad(r.pomak);
				break;
			case 3:
				r.OkreniSeNalijevo(r.okretLijevo);
				break;
			case 4:
				r.OkreniSeNadesno(r.okretDesno);
				break;
			default:
				if(operacija!=5){
					cout << "Greska!Unijeti izbor nije validan\n";
				}
				break;
		}
	}while(operacija!=5);
	
	return 0;
}
