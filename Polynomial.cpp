#include <iostream>
#include <vector>
#include <string>
#include <numeric>


using namespace std;


template <class T>
class Polynomial
{
private:
	vector<T> container; //коэфиценты
	vector<T> degrees;   //степени переменной
public:
	Polynomial(const vector<T>& Vector, const vector<T>& Degrees)
	{
		container = Vector;
		degrees = Degrees;
	}

	vector<T> GetContainer()
	{
		return container;
	}
	vector<T> GetDegrees()
	{
		return degrees;
	}

	bool operator == (Polynomial& Poly2) //Перегрузка операторов
	{
		return container == Poly2.GetContainer() && degrees == Poly2.GetDegrees();
	}

	bool operator != (Polynomial& Poly2) 
	{
		return container != Poly2.GetContainer() || degrees == Poly2.GetDegrees();
	}

	vector<T> operator += (Polynomial& Poly2) //Действия происходят над коэфицентами без учета степени
	{
		vector<T> V1 = container;
		vector<T> V2 = Poly2.GetContainer();
		if (container.size() > Poly2.GetContainer().size())
		{
			for (int i = 0; i < V2.size(); i++)
			{
				V1[i] = V2[i] + V1[i];
			}
			return V1;
		}
		for (int i = 0; i < V1.size(); i++)
		{
			V2[i] = V1[i] + V2[i];
		}
		return V2;
	}
	vector<T> operator +=(const T smth)
	{
		vector<T> V1 = container;
		for (int i = 0; i < V1.size(); i++)
		{
			V1[i] = smth + V1[i];
		}
		return V1;
	}

	vector<T> operator -= (Polynomial& Poly2)
	{
		vector<T> V1 = container;
		vector<T> V2 = Poly2.GetContainer();
		if (container.size() > Poly2.GetContainer().size())
		{
			for (int i = 0; i < V2.size(); i++)
			{
				V1[i] = V1[i] - V2[i];
			}
			return V1;
		}
		for (int i = 0; i < V1.size(); i++)
		{
			V2[i] = V1[i] - V2[i];
		}
		return V2;
	}

	vector<T> operator -=(const T smth)
	{
		vector<T> V1 = container;
		for (int i = 0; i < V1.size(); i++)
		{
			V1[i] = V1[i] - smth;
		}
		return V1;
	}

	vector<T> operator *= (Polynomial& Poly2)
	{
		vector<T> V1 = container;
		vector<T> V2 = Poly2.GetContainer();
		if (container.size() > Poly2.GetContainer().size())
		{
			for (int i = 0; i < V2.size(); i++)
			{
				V1[i] = V1[i] * V2[i];
			}
			return V1;
		}
		for (int i = 0; i < V1.size(); i++)
		{
			V2[i] = V1[i] * V2[i];
		}
		return V2;
	}

	vector<T> operator *=(const T smth)
	{
		vector<T> V1 = container;
		for (int i = 0; i < V1.size(); i++)
		{
			V1[i] = smth * V1[i];
		}
		return V1;
	}

	vector<T> operator +(Polynomial& Poly2)
	{
		vector<T> V1 = container;
		vector<T> V2 = Poly2.GetContainer();
		if (container.size() > Poly2.GetContainer().size())
		{
			for (int i = 0; i < V2.size(); i++)
			{
				V1[i] += V2[i];
			}
			return V1;
		}
		for (int i = 0; i < V1.size(); i++)
		{
			V2[i] += V1[i];
		}
		return V2;
	}

	vector<T> operator +(const T smth)
	{
		vector<T> V1 = container;
		for (int i = 0; i < V1.size(); i++)
		{
			V1[i] += smth;
		}
		return V1;
	}

	vector<T> operator -(Polynomial& Poly2)
	{
		vector<T> V1 = container;
		vector<T> V2 = Poly2.GetContainer();
		if (container.size() > (Poly2.GetContainer()).size())
		{
			for (int i = 0; i < V2.size(); i++)
			{
				V1[i] -= V2[i];
			}
			return V1;
		}
		for (int i = 0; i < V1.size(); i++)
		{
			V2[i] -= V1[i];
		}
		return V2;
	}

	vector<T> operator -(const T smth)
	{
		vector<T> V1 = container;
		for (int i = 0; i < V1.size(); i++)
		{
			V1[i] -= smth;
		}
		return V1;
	}

	vector<T> operator *(Polynomial& Poly2)
	{
		vector<T> V1 = container;
		vector<T> V2 = Poly2.GetContainer();
		if (container.size() > (Poly2.GetContainer()).size())
		{
			for (int i = 0; i < V2.size(); i++)
			{
				V1[i] *= V2[i];
			}
			return V1;
		}
		for (int i = 0; i < V1.size(); i++)
		{
			V2[i] *= V1[i];
		}
		return V2;
	}

	vector<T> operator *(const T smth)
	{
		vector<T> V1 = container;
		for (int i = 0; i < V1.size(); i++)
		{
			V1[i] *= smth;
		}
		return V1;
	}

	vector<T> operator / (Polynomial& Poly2)
	{
		vector<T> V1 = container;
		vector<T> V2 = Poly2.GetContainer();
		if (container.size() > Poly2.GetContainer().size())
		{
			for (int i = 0; i < V2.size(); i++)
			{
				V1[i] = round(V1[i] / V2[i]);
			}
			return V1;
		}
		for (int i = 0; i < V1.size(); i++)
		{
			V2[i] = round(V2[i] / V1[i]);
		}
		return V2;
	}

	vector<T> operator % (Polynomial& Poly2)
	{
		vector<T> V1 = container;
		vector<T> V2 = Poly2.GetContainer();
		if (container.size() > Poly2.GetContainer().size())
		{
			for (int i = 0; i < V2.size(); i++)
			{
				V1[i] = V1[i] % V2[i];
			}
			return V1;
		}
		for (int i = 0; i < V1.size(); i++)
		{
			V2[i] = V2[i] % V1[i];
		}
		return V2;
	}

	vector<T> operator , (Polynomial& Poly2) {
		vector<T> V1 = container;
		vector<T> V2 = Poly2.GetContainer();
		if (container.size() > Poly2.GetContainer().size())
		{
			for (int i = 0; i < V2.size(); i++)
			{
				V1[i] = Euclid(container[i], V2[i]);
			}
			return V1;
		}
		for (int i = 0; i < V1.size(); i++)
		{
			V2[i] = Euclid(container[i], V1[i]);
		}
		return V2;

	}

	T operator [] (const int coef) //нет проверки на выход из диапазона
	{
		return container[coef];
	}

	int Degree() //маскимальная степень
	{
		int max = -1;
		for (int i = 0; i < degrees.size(); i++)
		{
			if (max < degrees[i])
			{
				max = degrees[i];
			}
		}
		return max;
	}

	double operator () (const double dote) //вычисление многочлена в точке х = dote
	{
		double result = 0;
		for (int i = 0; i < container.size(); i++)
		{
			result += container[i] * pow(dote, degrees[i]);
		}
		return result;
	}

	template <typename T> //Нахождение НОД по алгоритму Евклида
	T Euclid(T a, T b) {
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

};



template <typename T>
ostream& operator << (ostream& stream, Polynomial<T>& Poly) //Всегда перегружается отдельно от класса
{
	vector<T> PolyVector = Poly.GetContainer();
	vector<T> PolyDegreees = Poly.GetDegrees();
	for (int i = 0; i < PolyVector.size(); i++)
	{


		if (PolyDegreees[i] != 0)
		{
			if (i != 0)
			{
				if (PolyVector[i] > 0 && PolyVector[i] != 1)
				{
					stream << "+";
				}
				else if (PolyVector[i] < 0 && PolyVector[i] != -1)
				{
					stream << "-";
				}
			}
			if (PolyVector[i] == 1)
			{
				stream << "x^";
			}
			else if (PolyVector[i] == -1)
			{
				stream << "-x^";
			}
			else
			{
				stream << PolyVector[i];
				stream << "x^";
			}
			stream << PolyDegreees[i];
		}
		else
		{
			if (i != 0)
			{
				stream << "+1";
			}
			else
			{
				stream << "1";
			}
		}
	}
	return stream;
}