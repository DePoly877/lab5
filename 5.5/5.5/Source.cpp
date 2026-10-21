#include <iostream>
#include <iomanip>

using namespace std;

// Рекурсивна функція знаходження n-го члена прогресії з фіксацією глибини
double a_n(double a1, double d, int n, int level, int& depth)
{
    // Фіксація максимальної глибини
    if (level > depth)
        depth = level;

    // Вивід значення поточного рівня рекурсії
    cout << "level = " << level << endl;

    // Умова завершення рекурсії (базовий випадок)
    if (n <= 1)
        return a1;

    // Рекурсивний виклик з level + 1
    return a_n(a1, d, n - 1, level + 1, depth) + d;
}

// Рекурсивна функція знаходження суми перших n членів прогресії з фіксацією глибини
double sum(double a1, double d, int n, int level, int& depth)
{
    // Фіксація максимальної глибини
    if (level > depth)
        depth = level;

    // Вивід значення поточного рівня рекурсії
    cout << "level = " << level << endl;

    // Умова завершення рекурсії (базовий випадок)
    if (n <= 1)
        return a1;

    // n-й член прогресії: an = a1 + (n - 1) * d
    double an = a1 + (n - 1) * d;

    // Рекурсивний виклик з level + 1
    return sum(a1, d, n - 1, level + 1, depth) + an;
}

int main()
{
    double a1, d;
    int n;

    cout << "First (a1): ";
    cin >> a1;

    cout << "d: ";
    cin >> d;

    cout << "n (n >= 1): ";
    cin >> n;


    cout << fixed << setprecision(2);

    // --- 1. Обчислення n-го члена прогресії ---
    cout << "\n--- Calculating the n-term  ---" << endl;
    cout << "Level:" << endl;
    cout << " " << endl;
    int depth_an = 0; // початкове значення глибини
    double an = a_n(a1, d, n, 1, depth_an); // 1 - початкове значення level

    // вивід глибини рекурсії
    cout << "\ndepth = " << depth_an << endl; 
    cout << " " << endl;

    //Вивід результату
    cout << "a_" << n << " = " << an << endl;
    

    // --- 2. Обчислення суми n членів прогресії ---
    cout << "\n--- Calculating the sum of the first n terms ---" << endl;
    cout << "Level:" << endl;
    cout << " " << endl;
    int depth_sn = 0; // початкове значення глибини
    double sn = sum(a1, d, n, 1, depth_sn); // 1 - початкове значення level

    // вивід глибини рекурсії
    cout << "\ndepth = " << depth_sn << endl; 
    cout << " " << endl;

    //Вивід результату
    cout << "S_" << n << " = " << sn << endl;

    return 0;
}