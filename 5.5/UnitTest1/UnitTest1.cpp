#include "pch.h"
#include "CppUnitTest.h"

// Підключаємо файл із кодом програми 
#include "../5.5/Source.cpp" // Зміни назву папки 'Project1' на назву свого проєкту

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		// Тест 1: Перевірка n-го члена прогресії (a_n)
		TEST_METHOD(Test_An_Calculation)
		{
			// Вхідні дані: a1 = 3, d = 2, n = 5
			// Очікуваний результат: a5 = 3 + (5 - 1) * 2 = 11
			double a1 = 3.0;
			double d = 2.0;
			int n = 5;
			int depth = 0;

			double expected = 11.0;
			double actual = a_n(a1, d, n, 1, depth);

			// Перевірка результату з точністю do 0.0001
			Assert::AreEqual(expected, actual, 0.0001);
		}

		// Тест 2: Перевірка суми перших n членів (sum)
		TEST_METHOD(Test_Sum_Calculation)
		{
			// Вхідні дані: a1 = 3, d = 2, n = 5
			// Прогресія: 3, 5, 7, 9, 11
			// Очікувана сума: 3 + 5 + 7 + 9 + 11 = 35
			double a1 = 3.0;
			double d = 2.0;
			int n = 5;
			int depth = 0;

			double expected = 35.0;
			double actual = sum(a1, d, n, 1, depth);

			Assert::AreEqual(expected, actual, 0.0001);
		}

		// Тест 3: Перевірка глибини рекурсії
		TEST_METHOD(Test_Recursion_Depth)
		{
			// Для n = 4 занурення буде на рівні 1, 2, 3, 4 -> depth має бути 4
			double a1 = 1.0;
			double d = 1.0;
			int n = 4;
			int depth = 0;

			a_n(a1, d, n, 1, depth);

			Assert::AreEqual(4, depth);
		}
	};
}