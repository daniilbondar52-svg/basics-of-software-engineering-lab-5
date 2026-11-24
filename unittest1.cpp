// unittest1.cpp - модульні тести (Native Unit Test Project, Visual Studio)
#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
#include <stdexcept>
#include "../Lab3/calc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(CalcTests)
    {
    public:
        // гілка x < 0: при n = 4 добуток складається з одного множника (2+1)
        TEST_METHOD(Negative_n4)
        {
            Assert::AreEqual(3.0, calculate(-1.0, 4), 1e-9);
        }
        // n = 6: (2+1)(3+1)(4+1) = 60
        TEST_METHOD(Negative_n6)
        {
            Assert::AreEqual(60.0, calculate(-5.5, 6), 1e-9);
        }
        // гілка x >= 0, x = 0, n = 4: 0 + 100 + 396 + 1008 = 1504
        TEST_METHOD(Positive_x0_n4)
        {
            Assert::AreEqual(1504.0, calculate(0.0, 4), 1e-9);
        }
        // x = 1, n = 4: 100 + 396 + 1008 + 2080 = 3584
        TEST_METHOD(Positive_x1_n4)
        {
            Assert::AreEqual(3584.0, calculate(1.0, 4), 1e-9);
        }
        // дробове x: x = 0.5, n = 4
        TEST_METHOD(Positive_x05_n4)
        {
            double expected = 0.5*1.5*4.5*9.5 + 1.5*2.5*5.5*10.5 + 2.5*3.5*6.5*11.5 + 3.5*4.5*7.5*12.5;
            Assert::AreEqual(expected, calculate(0.5, 4), 1e-9);
        }
        // n <= 3 - виняток
        TEST_METHOD(Calculate_BadN_Throws)
        {
            Assert::ExpectException<std::invalid_argument>([] { calculate(1.0, 3); });
        }
        TEST_METHOD(Params_Valid)
        {
            checkValidParams(5, -2.0, 2.0, 0.5); // не повинно бути винятку
        }
        TEST_METHOD(Params_BadN_Throws)
        {
            Assert::ExpectException<std::invalid_argument>([] { checkValidParams(2, 0.0, 1.0, 0.1); });
        }
        TEST_METHOD(Params_ZeroStep_Throws)
        {
            Assert::ExpectException<std::invalid_argument>([] { checkValidParams(5, 0.0, 1.0, 0.0); });
        }
        TEST_METHOD(Params_AGreaterB_Throws)
        {
            Assert::ExpectException<std::invalid_argument>([] { checkValidParams(5, 3.0, 1.0, 0.5); });
        }
        TEST_METHOD(ReadInt_Ok)
        {
            std::istringstream in("12");
            Assert::AreEqual(12, readInt(in));
        }
        TEST_METHOD(ReadInt_Letters_Throws)
        {
            std::istringstream in("abc");
            Assert::ExpectException<std::invalid_argument>([&] { readInt(in); });
        }
        TEST_METHOD(ReadInt_Double_Throws)
        {
            std::istringstream in("4.5");
            Assert::ExpectException<std::invalid_argument>([&] { readInt(in); });
        }
        TEST_METHOD(ReadDouble_Ok)
        {
            std::istringstream in("-2.25");
            Assert::AreEqual(-2.25, readDouble(in), 1e-12);
        }
        TEST_METHOD(ReadDouble_Letters_Throws)
        {
            std::istringstream in("1,5x");
            Assert::ExpectException<std::invalid_argument>([&] { readDouble(in); });
        }
    };
}
