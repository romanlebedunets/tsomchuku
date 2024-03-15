#include "pch.h"
#include "CppUnitTest.h"
#include "../grapeMult/Header.h"
#include "../grapeMult/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab2Tests
{
	TEST_CLASS(lab2Tests)
	{
	public:

		TEST_METHOD(testStandartMult)
		{
			int n = 2;
			int** m1 = new int* [n];
			int** m2 = new int* [n];

			for (size_t i = 0; i < n; i++) {
				m1[i] = new int[n];
				m2[i] = new int[n];
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					m1[i][j] = i + j + 1;
					m2[i][j] = i + j + 5;
				}
			}
			//m1: 1 2    m2: 5 6
			//    2 3        6 7

			int** res = standartMult(m1, n, n, m2, n, n);

			Assert::AreEqual(17, res[0][0]);
			Assert::AreEqual(20, res[0][1]);
			Assert::AreEqual(28, res[1][0]);
			Assert::AreEqual(33, res[1][1]);

			for (int i = 0; i < n; ++i) {
				delete[] m1[i];
				delete[] m2[i];
				delete[] res[i];
			}
			delete[] m1;
			delete[] m2;
			delete[] res;
		}

		TEST_METHOD(testGrapeMult)
		{
			int n = 2;
			int** m1 = new int* [n];
			int** m2 = new int* [n];

			for (size_t i = 0; i < n; i++) {
				m1[i] = new int[n];
				m2[i] = new int[n];
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					m1[i][j] = i + j + 1;
					m2[i][j] = i + j + 5;
				}
			}

			int** res = grapeMult(m1, n, n, m2, n, n);

			Assert::AreEqual(17, res[0][0]);
			Assert::AreEqual(20, res[0][1]);
			Assert::AreEqual(28, res[1][0]);
			Assert::AreEqual(33, res[1][1]);

			for (int i = 0; i < n; ++i) {
				delete[] m1[i];
				delete[] m2[i];
				delete[] res[i];
			}
			delete[] m1;
			delete[] m2;
			delete[] res;
		}
	};
}

