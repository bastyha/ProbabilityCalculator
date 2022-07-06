#include <iostream>
#include "base.h"

int main()
{
	double temp[7][2] = { {0,division(nCr(24,6) * nCr(8,0),nCr(32,6))},
						{1,division(nCr(24,5) * nCr(8,1),nCr(32,6))},
						{2,division(nCr(24,4) * nCr(8,2),nCr(32,6))},
						{3,division(nCr(24,3) * nCr(8,3),nCr(32,6))},
						{4,division(nCr(24,2) * nCr(8,4),nCr(32,6))},
						{5,division(nCr(24,1) * nCr(8,5),nCr(32,6))},
						{6,division(nCr(24,0) * nCr(8,6),nCr(32,6))}
	};

	std::cout << "casual probability" << std::endl;
	Probability* prob = new Probability(7, *temp);

	
	/*
	std::cout << prob->spread() << std::endl;

	double ftArr[3][2] = { {-3,division(6,32)},{0, division(10,32)}, {2,division(16,32)}};

	Probability* ft = new Probability(3, *ftArr);

	std::cout << ft->expectedValue() << std::endl;

	double elso[5][2] = { {0,(nCr(4,1)*division(pow(2,3),pow(3,4)))},
		{1,(nCr(4,1) * division(pow(2,3),pow(3,4)))},
		{2,(nCr(4,2) * division(pow(2,2),pow(3,4)))},
		{3,(nCr(4,3) * division(pow(2,1),pow(3,4)))},
		{4,(nCr(4,4) * division(pow(2,0),pow(3,4)))} };

	Probability* pr = new Probability(5, *elso);
	
	std::cout <<
		pr->expectedValue() << " "<<
		pr->spread() <<" "	<<
		pow(pr->spread(),2) <<std::endl;

	double elso1[4][2] = { {0,division(nCr(4,0)* nCr(5,3),nCr(9,3))},
	{1,division(nCr(4,1) * nCr(5,2),nCr(9,3))},
	{2,division(nCr(4,2) * nCr(5,1),nCr(9,3))},
	{3,division(nCr(4,3) * nCr(5,0),nCr(9,3))} };

	double res = 0;
	for (int i = 1; i < 4; i++)
	{
		res += elso1[i][1];
	}

	std::cout <<"kszi ossz: " <<res << std::endl;




	Probability* p1 = new Probability(4, *elso1);
	std::cout << p1->expectedValue() <<' '<< p1->spread() << std::endl;
	*/

	//Probability* ref = new Probability(division(1,3), 4);
	//Probability* hyp = new Probability(9, 4, 3);
	//Probability* HW2 = new Probability((1.0/6.0), 3);
	//Probability* HW3 = new Probability(52, 13, 13);
	std::cout << "binominal probability" << std::endl;
	Probability* ora3 = new Probability(1.0 / 2.0, 8);
	std::cout << "hypergeometric probability" << std::endl;
	Probability* ora2 = new Probability(20,5,4);
	return 0;
}
