#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double s(const double x);

int main()
{
    double tp, tk, z;
    int n;

    cout << "t_st = "; cin >> tp;
    cout << "t_end = "; cin >> tk;
    cout << "n = "; cin >> n;

    double dt = (tk - tp) / n;
    double t = tp;

    cout << fixed;
    cout << "-----------------------" << endl;
    cout << "|" << setw(7) << "t" << " |" << setw(11) << "z" << " |" << endl;
    cout << "-----------------------" << endl;

    while (t <= tk)
    {
        z = s(t * t + 1) + 2 * pow(s(1 - t), 2) + s(1);
        cout << "|" << setw(7) << setprecision(2) << t
            << " |" << setw(11) << setprecision(5) << z << " |" << endl;
        t += dt;
    }
    cout << "-----------------------" << endl;

    return 0;
}

double s(const double x)
{
    if (abs(x) > 1)
    {
        return (pow(cos(x), 2) + 1) / exp(x);
    }
    else
    {
        double S = 0;
        int k = 0;
        double a = x; // перший доданок при k = 0: x^(2*0+1)/(2*0+1)! = x/1 = x
        S = a;

        do
        {
            k++;
            // Рекурентний коефіцієнт R = a_k / a_{k-1} = (x^2) / (2k * (2k + 1))
            double R = (x * x) / ((2 * k) * (2 * k + 1));
            a *= R;
            S += a;
        } while (k < 4); // сума від k = 0 до 4

        return S;
    }
}