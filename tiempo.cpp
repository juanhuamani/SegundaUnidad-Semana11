
#include <iostream>
using namespace std;

class Tiempos
{
public:
	int hora, minutos, segundos;

	Tiempos(const int hora, const int minutos, const int segundos)
	{
		this->hora = hora;
		this->minutos = minutos;
		this->segundos = segundos;
	}

	friend ostream &operator<<(ostream &o, const Tiempos &p);
};

Tiempos operator+(const Tiempos &p1, const Tiempos &p2)
{

	int horas = p1.hora + p2.hora;
	int minuto = p1.minutos + p2.minutos;
	int segundo = p1.segundos + p2.segundos;
	int segundototal;

	horas = horas * 3600;
	minuto = minuto * 60;
	segundototal = horas + minuto + segundo;
	horas = segundototal / 3600;
	minuto = (segundototal % 3600) / 60;
	segundo = segundototal % 60;

	Tiempos tiemposuma(horas, minuto, segundo);
	return tiemposuma;
}

Tiempos operator-(const Tiempos &p1, const Tiempos &p2)
{
	int segundo = p1.segundos - p2.segundos;
	int horas = p1.hora - p2.hora;
	int minuto = p1.minutos - p2.minutos;
	int segundototal;

	if (segundo < 0)
	{
		segundo = 60 + segundo;
		minuto = minuto - 1;
	}
	if (minuto < 0)
	{
		minuto = 60 + minuto;
		horas = horas - 1;
	}
	if (horas < 0)
	{
		horas = 24 + horas;
	}

	horas = horas * 3600;
	minuto = minuto * 60;
	segundototal = horas + minuto + segundo;
	horas = segundototal / 3600;
	minuto = (segundototal % 3600) / 60;
	segundo = segundototal % 60;

	Tiempos tiemporesta(horas, minuto, segundo);
	return tiemporesta;
}

string operator<(const Tiempos &p1, const Tiempos &p2)
{
	string menor;

	if (p1.hora > p2.hora)
	{
		if (p1.minutos > p2.minutos)
		{
			if (p1.segundos > p2.segundos)
			{
				menor = "La primera hora  es menor que la segunda hora ";
			}
			else
			{
				menor = "La primera hora no es menor que la segunda hora ";
			}
		}
		else
		{
			menor = "La primera hora no es menor que la segunda hora ";
		}
	}
	else
	{
		menor = "La primera hora no es menor que la segunda hora ";
	}

	return menor;
}

string operator>(const Tiempos &p1, const Tiempos &p2)
{
	string mayor;

	if (p1.hora < p2.hora)
	{
		if (p1.minutos < p2.minutos)
		{
			if (p1.segundos < p2.segundos)
			{
				mayor = "La primera hora  no es mayor que la segunda hora ";
			}
			else
			{
				mayor = "La primera hora es mayor que la segunda hora ";
			}
		}
		else
		{
			mayor = "La primera hora es mayor que la segunda hora ";
		}
	}
	else
	{
		mayor = "La primera hora es mayor que la segunda hora ";
	}

	return mayor;
}

string operator<=(const Tiempos &p1, const Tiempos &p2)
{
	string menorigual;

	if (p1.hora >= p2.hora)
	{
		if (p1.minutos >= p2.minutos)
		{
			if (p1.segundos >= p2.segundos)
			{
				menorigual = "La primera hora  es menor igual que la segunda hora ";
			}
			else
			{
				menorigual = "La primera hora no es menor igual que la segunda hora ";
			}
		}
		else
		{
			menorigual = "La primera hora no es menor igual que la segunda hora ";
		}
	}
	else
	{
		menorigual = "La primera hora no es menor igual que la segunda hora ";
	}

	return menorigual;
}

string operator>=(const Tiempos &p1, const Tiempos &p2)
{
	string mayorigual;

	if (p1.hora <= p2.hora)
	{
		if (p1.minutos <= p2.minutos)
		{
			if (p1.segundos <= p2.segundos)
			{
				mayorigual = "La primera hora  no es mayor igual que la segunda hora ";
			}
			else
			{
				mayorigual = "La primera hora es mayor igual que la segunda hora ";
			}
		}
		else
		{
			mayorigual = "La primera hora es mayor igual que la segunda hora ";
		}
	}
	else
	{
		mayorigual = "La primera hora es mayor igual que la segunda hora ";
	}

	return mayorigual;
}

string operator==(const Tiempos &p1, const Tiempos &p2)
{
	string igual;

	if (p1.hora == p2.hora && p1.minutos == p2.minutos && p1.segundos == p2.segundos)
	{
		igual == "La primera hora es igual a la segunda hora";
	}
	else
	{
		igual = "La primera hora no es igual a la segunda hora ";
	}

	return igual;
}

ostream &operator<<(ostream &o, const Tiempos &p)
{
	return o << p.hora << " : " << p.minutos << " : " << p.segundos << endl;
}

int main()
{
	Tiempos tiempo1(12, 45, 30);
	Tiempos tiempo2(0, 30, 35);
	Tiempos tiempo3 = tiempo1 + tiempo2;
	Tiempos tiempo4 = tiempo1 - tiempo2;
	string tiempo5 = tiempo1 < tiempo2;
	string tiempo6 = tiempo1 > tiempo2;
	string tiempo7 = tiempo1 <= tiempo2;
	string tiempo8 = tiempo1 >= tiempo2;
	string tiempo9 = tiempo1 == tiempo2;

	cout << "PRIMERA HORA " << tiempo1;
	cout << "SEGUNDA HORA " << tiempo2;
	cout << "SUMA = " << tiempo3;
	cout << "RESTA = " << tiempo4;
	cout << tiempo5 << endl;
	cout << tiempo6 << endl;
	cout << tiempo7 << endl;
	cout << tiempo8 << endl;
	cout << tiempo9 << endl;

	return 0;
}
