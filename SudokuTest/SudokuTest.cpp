#include "pch.h"
#include "CppUnitTest.h"

#include "../Sudoku/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#pragma warning(disable:4996)
#pragma warning(disable:26451)

namespace SudokuTest
{
	TEST_CLASS(SudokuTest)
	{
	public:
		
		TEST_METHOD(Sudoku3x3)
		{
			Map mp
			{
				2,0,0,
				0,0,1,
				0,0,0
			};
			Map res
			{
				2,1,3,
				3,2,1,
				1,3,2
			};
			Solve(mp, 3);
			Assert::IsTrue(std::equal(mp.begin(), mp.end(), res.begin()));
		}

		TEST_METHOD(Sudoku4x4)
		{
			Map mp
			{
				0,0,2,0,
				0,0,0,4,
				3,0,0,1,
				0,1,0,0
			};
			Map res
			{
				1,4,2,3,
				2,3,1,4,
				3,2,4,1,
				4,1,3,2
			};
			Solve(mp, 4);
			Assert::IsTrue(std::equal(mp.begin(), mp.end(), res.begin()));
		}

		TEST_METHOD(Sudoku5x5)
		{
			Map mp
			{
				0,1,0,0,0,
				0,0,0,3,0,
				0,0,4,1,2,
				1,0,0,5,0,
				3,0,0,0,4
			};
			Map res
			{
				2,1,3,4,5,
				4,2,5,3,1,
				5,3,4,1,2,
				1,4,2,5,3,
				3,5,1,2,4
			};
			Solve(mp, 5);
			Assert::IsTrue(std::equal(mp.begin(), mp.end(), res.begin()));
		}

		TEST_METHOD(Sudoku6x6)
		{
			Map mp
			{
				0,0,0,2,0,0,
				2,0,0,0,3,0,
				0,5,0,3,0,2,
				3,2,6,0,1,0,
				0,0,1,0,0,3,
				0,0,0,5,4,0
			};
			Map res
			{
				4,1,3,2,5,6,
				2,6,5,1,3,4,
				1,5,4,3,6,2,
				3,2,6,4,1,5,
				5,4,1,6,2,3,
				6,3,2,5,4,1
			};
			Solve(mp, 6);
			Assert::IsTrue(std::equal(mp.begin(), mp.end(), res.begin()));
		}

		TEST_METHOD(Sudoku7x7)
		{
			Map mp
			{
				0,5,0,0,2,7,4,
				5,6,2,7,1,0,3,
				2,0,0,3,7,5,6,
				7,0,6,4,0,1,2,
				4,2,0,1,6,3,5,
				0,7,5,0,4,6,1,
				0,4,1,5,0,2,7
			};
			Map res
			{
				1,5,3,6,2,7,4,
				5,6,2,7,1,4,3,
				2,1,4,3,7,5,6,
				7,3,6,4,5,1,2,
				4,2,7,1,6,3,5,
				3,7,5,2,4,6,1,
				6,4,1,5,3,2,7
			};
			Solve(mp, 7);
			Assert::IsTrue(std::equal(mp.begin(), mp.end(), res.begin()));
		}

		TEST_METHOD(Sudoku8x8)
		{
			Map mp
			{
				0,5,0,0,0,7,4,0,
				0,0,4,3,2,0,0,0,
				0,0,1,0,0,0,0,0,
				7,0,0,0,4,0,0,0,
				0,0,0,0,0,5,0,2,
				0,0,0,0,6,0,0,0,
				4,0,3,0,1,0,0,0,
				6,0,0,8,0,0,3,0
			};
			Map res
			{
				2,5,8,6,3,7,4,1,
				1,6,4,3,2,8,5,7,
				8,4,1,7,5,6,2,3,
				7,3,5,2,4,1,6,8,
				3,7,6,4,8,5,1,2,
				5,2,7,1,6,3,8,4,
				4,8,3,5,1,2,7,6,
				6,1,2,8,7,4,3,5
			};
			Solve(mp, 8);
			Assert::IsTrue(std::equal(mp.begin(), mp.end(), res.begin()));
		}

		TEST_METHOD(Sudoku9x9)
		{
			Map mp
			{
				0,0,6,7,0,3,5,0,0,
				0,0,0,0,4,0,0,0,0,
				5,0,0,0,0,0,0,0,2,
				9,0,0,0,0,0,0,0,7,
				0,3,0,0,0,0,0,4,0,
				8,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,4,
				0,0,0,0,0,0,0,0,0,
				0,5,9,2,6,7,3,1,0

			};
			Map res
			{
				2,4,6,7,1,3,5,8,9,
				7,9,8,5,4,2,1,6,3,
				5,1,3,6,8,9,4,7,2,
				9,2,4,1,5,6,8,3,7,
				6,3,1,9,7,8,2,4,5,
				8,7,5,3,2,4,6,9,1,
				1,6,7,8,3,5,9,2,4,
				3,8,2,4,9,1,7,5,6,
				4,5,9,2,6,7,3,1,8
			};
			Solve(mp, 9);
			Assert::IsTrue(std::equal(mp.begin(), mp.end(), res.begin()));
		}

		TEST_METHOD(NoSolution)
		{
			Map mp
			{
				0,6,6,7,0,3,5,0,0,
				0,0,0,0,4,0,0,0,0,
				5,0,0,0,0,0,0,0,2,
				9,0,0,0,0,0,0,0,7,
				0,3,0,0,0,0,0,4,0,
				8,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,4,
				0,0,0,0,0,0,0,0,0,
				0,5,9,2,6,7,3,1,0

			};

			Assert::IsFalse(Solve(mp, 9));
		}

		TEST_METHOD(FileTest)
		{
			auto fp = fopen("test.i", "w");
			fputs("0 0 6 7 0 3 5 0 0\n"
					   "0 0 0 0 4 0 0 0 0\n"
					   "5 0 0 0 0 0 0 0 2\n"
					   "9 0 0 0 0 0 0 0 7\n"
					   "0 3 0 0 0 0 0 4 0\n"
					   "8 0 0 0 0 0 0 0 1\n"
					   "1 0 0 0 0 0 0 0 4\n"
					   "0 0 0 0 0 0 0 0 0\n"
					   "0 5 9 2 6 7 3 1 0\n", fp);
			fclose(fp);
			char* argv[] =
			{
				"",
				"-m",
				"9",
				"-n",
				"1",
				"-i",
				"test.i",
				"-o",
				"test.o"
			};

			main_(9, argv);

			fp = fopen("test.o", "r");

			char buf[200]{ 0 };

			auto size = fread(buf, sizeof(char), 200, fp);

			fclose(fp);

			auto bufStr = std::string(buf, size);

			remove("test.i");
			remove("test.o");

			Assert::AreEqual(
				std::string("2 4 6 7 1 3 5 8 9\n"
										"7 9 8 5 4 2 1 6 3\n"
										"5 1 3 6 8 9 4 7 2\n"
										"9 2 4 1 5 6 8 3 7\n"
										"6 3 1 9 7 8 2 4 5\n"
										"8 7 5 3 2 4 6 9 1\n"
										"1 6 7 8 3 5 9 2 4\n"
										"3 8 2 4 9 1 7 5 6\n"
										"4 5 9 2 6 7 3 1 8\n\n"), bufStr);
		}

		TEST_METHOD(FileNotFound)
		{
			char* argv[] =
			{
				"",
				"-mi",
				"9",
				"-n",
				"1",
				"-ii",
				"test.i",
				"-o",
				"test.o"
			};
			try
			{
				main_(9, argv);
			}
			catch (std::exception& exception)
			{
				Assert::AreEqual("open input file failed", exception.what());
			}
		}
	};

}
