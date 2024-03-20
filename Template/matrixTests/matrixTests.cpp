#include "pch.h"
#include "CppUnitTest.h"
#include "../Template/Header.h"
#include "../Template/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace matrixTests
{
	TEST_CLASS(matrixTests)
	{
	public:
		
		TEST_METHOD(testNorm)
		{
			Matrix<int> matrix(2, 3);
			matrix.setEl(0, 0, 1);
			matrix.setEl(0, 1, 2);
			matrix.setEl(0, 2, 3);
			matrix.setEl(1, 0, 4);
			matrix.setEl(1, 1, 5);
			matrix.setEl(1, 2, 6);

			double expected = 9.53939;
			double mistake = 0.00001;

			Assert::IsTrue(abs(matrix.norm() - expected) < mistake);
		}
		TEST_METHOD(testMaxElement)
		{
			Matrix<double> matrix(2, 3);
			matrix.setEl(0, 0, 1.0);
			matrix.setEl(0, 1, 2.0);
			matrix.setEl(0, 2, 3.0);
			matrix.setEl(1, 0, 4.0);
			matrix.setEl(1, 1, 5.0);
			matrix.setEl(1, 2, 6.0);

			Assert::AreEqual(6.0, matrix.maxEl());
		}
	};
}
