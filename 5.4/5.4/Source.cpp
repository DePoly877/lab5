// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>

using namespace std;


double S_0(int j, const int N)
{
    double s = 0;
    for (j = 2; j <= N; ++j) {
        double numerator = j * (N - j);
        double denominator = pow(j, 2) + pow(N - j, 2);
        s += numerator / denominator;
    }
    return s;
}
// Спуск
// Зі зменшенням
double S_1(const int N, int j, double t)
{
    t += (1.0 * j * (N - j)) / (j * j + (N - j) * (N - j));

    if (j <= 2)
        return t;
    else
        return S_1(N, j - 1, t);
}
// Зі збільшенням
double S_2(const int N, int j, double t)
{
    t += (1.0 * j * (N - j)) / (j * j + (N - j) * (N - j));
    
    if (j >= N)
        return t;
    else
        return S_2(N, j + 1, t);
}
//Підйом
//Зі зменшенням
double S_3(const int N, int j)
{
    if (j < 2)
        return 0;
    else
        return (1.0 * j * (N - j)) / (j * j + (N - j) * (N - j)) + S_3(N, j - 1);

}
//Зі збільшенням
double S_4(const int N, int j)
{
    if (j > N)
        return 0;
    else
    {
        return (1.0 * j * (N - j)) / (j * j + (N - j) * (N - j)) + S_4(N, j + 1);
    }
}
int main()
{
    int N;
    int j = 2;
    cout << "N = "; cin >> N;
    cout << "(iter) S0 = " << S_0(j, N) << endl;
    cout << "(rec down --) S1 = " << S_1(N, N, 0) << endl;
    cout << "(rec down ++) S2 = " << S_2(N, 2, 0) << endl;
    cout << "(rec up --) S3 = " << S_3(N,N) << endl;
    cout << "(rec up ++) S4 = " << S_4(N, 2) << endl;
    return 0;
}