#define UNIT_TESTING
#include "pch.h"
#include "CppUnitTest.h"
#include "../5.4/Source.cpp" 

// Оголошуємо прототипи функцій з вашої програми
double S_0(int j, const int N);
double S_1(const int N, int j, double t);
double S_2(const int N, int j, double t);
double S_3(const int N, int j);
double S_4(const int N, int j);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Тест перевіряє правильність обчислень усіх 5 функцій для N = 4
        TEST_METHOD(TestMethod1)
        {
            const int N = 4;
            const double expected = 0.8; // точне розраховане значення
            const double eps = 1e-5;     // допустима похибка для дійсних чисел (double)

            // Перевіряємо кожну з функцій з точністю eps
            Assert::AreEqual(expected, S_0(2, N), eps, L"Помилка в S_0 (ітерація)");
            Assert::AreEqual(expected, S_1(N, N, 0), eps, L"Помилка в S_1 (хвостова спадна)");
            Assert::AreEqual(expected, S_2(N, 2, 0), eps, L"Помилка в S_2 (хвостова зростаюча)");
            Assert::AreEqual(expected, S_3(N, N), eps, L"Помилка в S_3 (проста спадна)");
            Assert::AreEqual(expected, S_4(N, 2), eps, L"Помилка в S_4 (проста зростаюча)");
        }
    };
}