

#include <iostream>
#include <iomanip>
using namespace std;

class Racional
{
public:
	int numerador, denominador;
	Racional()
	{
		numerador = 0;
		denominador = 1;
	}
	Racional(int numerador, int denominador)
	{
		this->numerador = numerador;
		this->denominador = denominador;
	}
	void aprox(void);
	void reducir(void);
	Racional operator+(Racional p)
	{
		Racional suma;
		suma.numerador = (numerador * p.denominador) + (denominador * p.numerador);
		suma.denominador = denominador * p.denominador;
		suma.reducir();

		return suma;
	}
	Racional operator-(Racional p)
	{
		Racional resta;
		resta.numerador = (numerador * p.denominador) - (denominador * p.numerador);
		resta.denominador = denominador * p.denominador;
		resta.reducir();

		return resta;
	}

	Racional operator*(Racional p)
	{
		Racional por;
		por.numerador = (numerador) * (p.numerador);
		por.denominador = denominador * p.denominador;
		por.reducir();

		return por;
	}
	Racional operator/(Racional p)
	{
		Racional entre;
		entre.numerador = (numerador) * (p.denominador);
		entre.denominador = denominador * p.numerador;
		entre.reducir();

		return entre;
	}

	friend istream &operator>>(istream &i, const Racional &p);
	friend ostream &operator<<(ostream &o, const Racional &p);
};

void Racional::aprox()
{
	double aproximacion = (double)numerador / denominador;
	cout << fixed << setprecision(2) << aproximacion << setprecision(0) << endl;
}

void Racional::reducir()
{
	double mayor;
	if (numerador > denominador)
	{
		mayor = numerador;
	}
	else
	{
		mayor = denominador;
	}

	for (int i = 2; i < mayor; i++)
	{
		while (numerador % i == 0 && denominador % i == 0)
		{
			numerador = numerador / i;
			denominador = denominador / i;
		}
	}

	if (numerador == 0 || denominador == 0)
	{
		numerador = 0;
		denominador = 0;
	}
}

istream &operator>>(istream &i, Racional &p)
{

	return i >> p.numerador >> p.denominador;
}

ostream &operator<<(ostream &o, const Racional &p)
{
	if (p.numerador == 0 || p.denominador == 0)
	{
		return o << p.numerador << endl;
	}
	else if (p.numerador == p.denominador)
	{
		return o << 1 << endl;
	}
	else
		return o << p.numerador << " / " << p.denominador << endl;
}

int main()
{
	Racional racional1(4, 5);
	cout << "Primera fraccion : " << racional1;

	Racional racional2(5, 3);
	cout << "Segunda fraccion : " << racional2;
	Racional racional3 = racional1 + racional2;
	Racional racional4 = racional1 - racional2;
	Racional racional5 = racional1 * racional2;
	Racional racional6 = racional1 / racional2;

	cout << "Suma  : " << racional3;
	cout << "Resta  : " << racional4;
	cout << "Multiplicacion  : " << racional5;
	cout << "Division  : " << racional6;
}