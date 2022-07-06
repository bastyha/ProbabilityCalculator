#include <iostream>

double roundToDecimal(double numToRound, int decToRound);
unsigned int nCr(unsigned int n, unsigned int r);

class Probability
{
public:
	// casual probability
	Probability(int numOfVariates, double* FirstVariatesDistribution); 

	// casual probability
	double expectedValue();
	void secondDistribution();
	double spread();

private:
	int m_numOfVariates;
	double* m_FirstVariatesDistribution;
	double* m_SecondVariatesDistribution;





public:
	//binominal probability 
	Probability(double p, int n);

	void Binom_distribution();
	double Binom_expectedValue();
	double Binom_spread();

private:
	double m_p;
	double m_q;
	int m_n;

	double* m_Binom_VariateDistr = new double[0];
	double m_Binom_expVal = 0;
	double m_BinomSpread = 0;

public:
	// hypergeometric distribution
	Probability(double m, double s, double n);

	void Hyper_distribution();
	void Hyper_distributionVarNO2();
	double Hyper_expectedValue();
	double Hyper_spread();

private:
	double m_H_m;
	double m_H_s;
	double m_H_n;
	double m_H_p = 0;

	double* m_Hyper_VariateDistr = new double[0];
	double* m_Hyper_VariateDistrNO2 = new double[0];
	double m_Hyper_expVal = 0;
	double m_HyperSpread = 0;

};


