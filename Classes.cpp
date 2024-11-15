#include <iostream>
#include "CVector.h"
#include <string>
#include "Polynomial.cpp"
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество элементов полинома" << endl;
    cin >> n;
    vector<int> Vector(n);
    vector<int> Vector1(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        cout << "Введите "<<i+1 << " элемент" << endl;
        cin >> num;
        Vector[i] = num;
        Vector1[i] = num + num;
    }
    Polynomial <int> Poly (Vector, Vector); //В данном случае степени переменной равны коэффицентам
    Polynomial <int> Poly2(Vector1, Vector);
    Polynomial <int> Poly3 (Vector, Vector); 
    cout << Poly<<endl;

    bool Equal = Poly == Poly3;
    bool NotEqual = Poly != Poly2;
    if (Equal)
    {
        cout << Poly << " == "<<Poly3<<endl;
    }
    if (NotEqual)
    {
        cout << Poly << " != " << Poly2 << endl;
    }

    vector<int> Plus = Poly + Poly2;
    cout << Poly << " + " << Poly2 << " = ";
    for (int i = 0; i < n; i++)
    {
        cout << Plus[i] << " ";
    }
    cout << endl;

    vector<int> MinusScalar = Poly - 78;
    cout << Poly << " - " << 78 << " = ";
    for (int i = 0; i < n; i++)
    {
        cout << MinusScalar[i] << " ";
    }
    cout << endl;

    vector<int> Divide = Poly / Poly2;
    cout << Poly << " / " << Poly2 << " = ";
    for (int i = 0; i < n; i++)
    {
        cout << Divide[i] << " ";
    }
    cout << endl;

    vector<int> Mod = Poly % Poly2;
    cout << Poly << " % " << Poly2 << " = ";
    for (int i = 0; i < n; i++)
    {
        cout << Mod[i] << " ";
    }
    cout << endl;

    vector<int> Nod = (Poly, Poly2);
    for (int i = 0; i < n; i++)
    {
        cout << Nod[i] << " ";
    }
    cout << endl;

    double result = Poly(2);
    cout << result << endl;

    return 0;
};

