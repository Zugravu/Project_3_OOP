//Constructori
//Supra-incarcarea operatorilor >>,<<,=
//Functii prieten
//Functii virtuale de afisare si citire
//cerinte generale aplicate fiecarei teme din acest fisier: COMPLETATE
//clasa tempalte pentru a gestiona si memora toate tipurile de plata


#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

std::ifstream a("card.txt");
std::ifstream b("cec.txt");
std::ifstream c("cash.txt");
std::ofstream fout("afisare.txt");

class Client
{
protected:
	std::string nume;
public:
	Client operator=(Client client)
	{
		nume = client.nume;
		return *this;
	}
	Client(): nume(""){}
	Client(std::string Nume) : nume(Nume) {}
	friend std::istream& operator>>(std::istream& in, Client& client)
	{
		in >> client.nume;
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, Client& client)
	{
		out << client.nume;
		return out;
	}

	virtual void Citire(Client& client);

	~Client() { nume = ""; }
};

void Client::Citire(Client& client) {
	std::cout << "nume: ";
	std::cin >> client.nume;
}

class Plata : public Client
{
protected:
	int zi;
	int luna;
	int an;
	int suma;
public:
	Plata() : zi(0), luna(0), an(0), suma(-1){}
	Plata(int Zi, int Luna, int An, int bani): zi(Zi), luna(Luna), an(An), suma(bani){}
	Plata(std::string Nume, int Zi, int Luna, int An, int bani): Client(Nume), zi(Zi), luna(Luna), an(An), suma(bani) {}
	Plata operator=(Plata plata) 
	{
		nume = plata.nume;
		zi = plata.zi;
		luna = plata.luna;
		an = plata.an;
		suma = plata.suma;
		return *this;
	}

	friend std::istream& operator>>(std::istream& in, Plata& plata) 
	{
		in >> plata.nume;
		in >> plata.zi;
		in >> plata.luna;
		in >> plata.an;
		in >> plata.suma;
		return in;
	}
	friend std::ostream& operator<<(std::ostream &out, Plata &plata) 
	{
		out << "nume: " << plata.nume << std::endl;
		out << "zi: " << plata.zi << std::endl;
		out << "luna: " << plata.luna << std::endl;
		out << "an: " << plata.an << std::endl;
		out << "suma: " << plata.suma << std::endl;
		return out;
	}
	void Afisare(Plata& plata)
	{
		std::cout << "nume: " << plata.nume << std::endl;
		std::cout << "data: " << plata.zi <<"."<<plata.luna << "." << plata.an << std::endl;
		std::cout << "suma: " << plata.suma << std::endl;
	}
	void Citire(Plata& plata)
	{
		std::cout << "nume: ";
		std::cin >> plata.nume;
		std::cout << "zi: ";
		std::cin >> plata.zi;
		std::cout << "luna: ";
		std::cin >> plata.luna;
		std::cout << "an: ";
		std::cin >> plata.an;
		std::cout << "suma: ";
		std::cin >> plata.suma;
	}
	~Plata() {
		nume = "";
		zi = 0;
		luna = 0;
		an = 0;
		suma = 0;
	}
};

class Card : public Plata{
private:
	int nr_card;
public:
	Card():nr_card(-1){}
	Card(std::string Nume, int Zi, int Luna, int An, int bani, int cod) : Plata(Nume, Zi, Luna, An,bani), nr_card(cod) {}
	Card operator=(Card card)
	{
		nume = card.nume;
		zi = card.zi;
		luna = card.luna;
		an = card.an;
		suma = card.suma;
		nr_card = card.nr_card;
		return *this;
	}
	friend std::istream& operator>>(std::istream& in, Card& card)
	{
		std::cout << "Nume:";
		in >> card.nume;
		std::cin.get();
		std::cout << "Data:";
		in >> card.zi >> card.luna >> card.an;
		std::cout << "Suma:";
		in >> card.suma;
		std::cout << "Nr_Card";
		in >> card.nr_card;
		return in;
	}
	friend std::ostream &operator<<(std::ostream &out, Card &card)
	{
		out << "nume: " << card.nume << std::endl;
		out << "data: " << card.zi << "." << card.luna << "." << card.an << std::endl;
		out << "suma: " << card.suma << std::endl;
		out << "nr_card: " << card.nr_card << std::endl;
		return out;
	}

	void Afisare(Card& card)
	{
		std::cout << "nume: " << card.nume << std::endl;
		std::cout << "data: " << card.zi << "." << card.luna << "." << card.an << std::endl;
		std::cout << "suma: " << card.suma << std::endl;
		std::cout << "nr_card: " << card.nr_card << std::endl;
	}
	void Citire(Card& card)
	{
		a >> card.nume;
		a >> card.zi;
		a >> card.luna;
		a >> card.an;
		a >> card.suma;
		a >> card.nr_card;
	}
	~Card() {
		nume = "";
		zi = 0;
		luna = 0;
		an = 0;
		suma = 0;
		nr_card = 0;
	}
};

class Cec : public Plata {

public:
	Cec() {}
	Cec(std::string Nume, int Zi, int Luna, int An, int bani) : Plata(Nume, Zi, Luna, An, bani) {}
	Cec operator=(Cec cec)
	{
		nume = cec.nume;
		zi = cec.zi;
		luna = cec.luna;
		an = cec.an;
		suma = cec.suma;
		return *this;
	}
	friend std::istream& operator>>(std::istream& in, Cec& cec)
	{
		std::cout << "Nume:";
		in >> cec.nume;
		std::cin.get();
		std::cout << "Data:";
		in >> cec.zi >> cec.luna >> cec.an;
		std::cout << "Suma:";
		in >> cec.suma;
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, Cec& cec)
	{
		out << "nume: " << cec.nume << std::endl;
		out << "data: " << cec.zi << "." << cec.luna << "." << cec.an << std::endl;
		out << "suma: " << cec.suma << std::endl;
		return out;
	}

	void Afisare(Cec& cec)
	{
		std::cout << "nume: " << cec.nume << std::endl;
		std::cout << "data: " << cec.zi << "." << cec.luna << "." << cec.an << std::endl;
		std::cout << "suma: " << cec.suma << std::endl;
	}
	void Citire(Cec& cec)
	{
		b >> cec.nume;
		b >> cec.zi;
		b >> cec.luna;
		b >> cec.an;
		b >> cec.suma;
	}
	~Cec() {
		nume = "";
		zi = 0;
		luna = 0;
		an = 0;
		suma = 0;
	}
};

class Cash : public Plata {
public:
	Cash() {}
	Cash(int Zi,int Luna,int An, int bani) : Plata(Zi, Luna, An, bani) {}
	Cash operator=(Cash cash);
	friend std::istream& operator>>(std::istream& in, Cash& cash)
	{
		std::cout << "Data:";
		in >> cash.zi >> cash.luna >> cash.an;
		std::cout << "Suma:";
		in >> cash.suma;
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, Cash& cash)
	{
		out << "data: " << cash.zi << "." << cash.luna << "." << cash.an << std::endl;
		out << "suma: " << cash.suma << std::endl;
		return out;
	}

	void Afisare(Cash& cash)
	{
		std::cout << "data: " << cash.zi << "." << cash.luna << "." << cash.an << std::endl;
		std::cout << "suma: " << cash.suma << std::endl;
	}
	void Citire(Cash& cash)
	{
		c >> cash.zi;
		c >> cash.luna;
		c >> cash.an;
		c >> cash.suma;
	}
	~Cash() {
		zi = 0;
		luna = 0;
		an = 0;
		suma = 0;
	}
};

Cash Cash::operator=(Cash cash) {
	zi = cash.zi;
	luna = cash.luna;
	an = cash.an;
	suma = cash.suma;
	return *this;
}

template<typename T>
class Gestiune {
private:
	int n;
	std::unordered_map<int, T> map;
public:
	T operator+=(T& g) 
	{
		n++;
		map.insert(std::make_pair(n, g));
		return g;
	}
	T operator[](int index)
	{
		return map[index];
	}
	friend std::ostream& operator<<(std::ostream& out, Gestiune& g)
	{
		for (auto& x : g.map)
			out << x.second << std::endl;
		return out;
	}
	int GetN() { return n; }
	void Afisare(int index) { std::cout << map[index]; }
};


void MeniuInteractiv() {
	std::cout << "1: Adauga n plati noi" << std::endl;
	std::cout << "2: Afiseaza toate platile de tip card si numarul acestora" << std::endl;
	std::cout << "3: Afiseaza toate platile de tip cec si numarul acestora" << std::endl;
	std::cout << "4: Afiseaza toate platile de tip cash si numarul acestora" << std::endl;
	std::cout << "5: Afiseaza plata de un anumit tip cu id-ul: " << std::endl;
	std::cout << "0: Stop: " << std::endl;

}
void Citire(Gestiune<Card>& A, Gestiune<Cec>& B, Gestiune<Cash>& C){
	while (a)
	{
		Card card;
		card.Citire(card);
		A += card;
		if (a.tellg() == 0)
			break;
	}
	while (b)
	{
		Cec cec;
		cec.Citire(cec);
		B += cec;
		if (b.tellg() == 0)
			break;
	}
	while (c)
	{
		Cash cash;
		cash.Citire(cash);
		C += cash;
		if (c.tellg() == 0)
			break;
	}
}
void Optiune_1(Gestiune<Card>& A, Gestiune<Cec>& B, Gestiune<Cash>& C)
{
	int zi, luna, an, suma, n;
	std::string tip;
	std::cout << "Tipul platii: ";
	std::cin >> tip;
	std::cout << "Nr da plati care vor fi adaugate: ";
	std::cin >> n;
	if (tip.compare("Card")==0)
	{
		while (n)
		{
			Card card;
			std::cin >> card;
			A += card;
			n--;
		}
	}

	if (tip.compare("Cec") == 0)
	{
		while (n)
		{
			Cec cec;
			std::cin >> cec;
			B += cec;
			n--;
		}
	}
	else if (tip.compare("Cash") == 0)
	{
		while (n)
		{
			Cash cash;
			std::cin >> cash;
			C += cash;
			n--;
		}
	}
			
}
void Optiune_5(Gestiune<Card>& A, Gestiune<Cec>& B, Gestiune<Cash>& C)
{
	std::string tip;
	int id;
	std::cout << "Tipul de plata: ";
	std::cin >> tip;
	std::cout << "Id-ul: ";
	std::cin >> id;
	if (tip.compare("Card") == 0)
	{
		A.Afisare(id);
	}

	if (tip.compare("Cec") == 0)
	{
		B.Afisare(id);
	}
	else if (tip.compare("Cash") == 0)
	{
		C.Afisare(id);
	}

}
void Problema(){
	Gestiune<Card> A;
	Gestiune<Cec> B;
	Gestiune<Cash> C;
	Citire(A,B,C);
	int optiune;
	MeniuInteractiv();
	std::cin >> optiune;
	while (optiune != 0)
	{
		if (optiune == 1) {
			Optiune_1(A,B,C);
		}
		if (optiune == 2){
			std::cout << A;
			std::cout << "Nr de palti de acest tip: " << A.GetN() << std::endl << std::endl;
		}
		if (optiune == 3) {
			std::cout << B;
			std::cout << "Nr de palti de acest tip: " << B.GetN() << std::endl << std::endl;
		}
		if (optiune == 4) {
			std::cout << C;
			std::cout << "Nr de palti de acest tip: " << C.GetN() << std::endl << std::endl;
		}
		if (optiune == 5) {
			Optiune_5(A,B,C);
		}
		MeniuInteractiv();
		std::cin >> optiune;
	}
	fout << "Card:" << std::endl << A;
	fout << "Cec:" << std::endl << B;
	fout << "Cash:" << std::endl << C;
	
}

int main()
{
	Problema();
	return 0;
}

