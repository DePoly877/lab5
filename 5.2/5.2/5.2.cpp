#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Оголошення функцій
double S(const double x, const double eps, int& n);
double A(const double x, const int n, double a);

int main()
{
    double x_st, x_end, x, x_kr, eps, s = 0;
    int n = 0;

    cout << "x_st = "; cin >> x_st;
    cout << "x_end = "; cin >> x_end;
    cout << "x_krok = "; cin >> x_kr;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(10) << "ln(x)" << " |"
        << setw(10) << "S" << " |"
        << setw(7) << "n" << " |"
        << endl;
    cout << "-------------------------------------------" << endl;

    x = x_st;
    while (x <= x_end)
    {
        if (x <= 0)
        {
            // Для x <= 0 ln(x) не існує в дійсних числах
            cout << "|" << setw(7) << setprecision(2) << x << " |"
                << setw(10) << "ERROR" << " |"
                << setw(10) << "-" << " |"
                << setw(7) << "-" << " |" << endl;
        }
        else
        {
            s = S(x, eps, n);

            cout << "|" << setw(7) << setprecision(2) << x << " |"
                << setw(10) << setprecision(5) << log(x) << " |"
                << setw(10) << setprecision(5) << s << " |"
                << setw(7) << n << " |"
                << endl;
        }
        x += x_kr;
    }

    cout << "-------------------------------------------" << endl;

    return 0;
}

// Функція обчислення суми ряду Тейлора для ln(x)
double S(const double x, const double eps, int& n)
{
    n = 0;
    double a = (x - 1.0) / (x + 1.0); // Перший доданок ряду (n = 0)
    double s = a;

    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);

    return 2.0 * s; // Множимо суму ряду на 2 за формулою для ln(x)
}

// Функція обчислення наступного члена ряду через рекурентне співвідношення
double A(const double x, const int n, double a)
{
    // Рекурентний множник R для ряду ln(x)
    double term = (x - 1.0) / (x + 1.0);
    double R = (term * term) * (2.0 * n - 1.0) / (2.0 * n + 1.0);

    a *= R;
    return a;
}