#include "Probability.h"

//------------------------------------------------
//------------Casual probability------------------
//------------------------------------------------

//Casual
Probability::Probability(int numOfVariates, double* VariatesArr)
{
    m_numOfVariates = numOfVariates;
    m_FirstVariatesDistribution = VariatesArr;

    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "expected value: " << this->expectedValue() << std::endl;
    this->secondDistribution();
    for (int i = 0; i < numOfVariates; i++)
    {
        std::cout << "eta: " << *(m_SecondVariatesDistribution + i) << std::endl;
    }
    std::cout << "spread: " << this->spread() << std::endl;
}


double Probability::expectedValue()
{
    double l_Result = 0;
 
    for (int i = 0; i < m_numOfVariates; i++)
    {
        l_Result += *(m_FirstVariatesDistribution) * *(m_FirstVariatesDistribution + 1);
        m_FirstVariatesDistribution += 2;
    }
    m_FirstVariatesDistribution -= m_numOfVariates * 2;
    return roundToDecimal(l_Result,4);
}

void Probability::secondDistribution()
{
    double* SecVarArr;
    SecVarArr = new double[m_numOfVariates];
    double expValFirstVar = this->expectedValue();

    for (int i = 0; i < m_numOfVariates; i++)
    {
        SecVarArr[i] = pow(*m_FirstVariatesDistribution - expValFirstVar, 2);
        m_FirstVariatesDistribution +=2;
    }
    m_FirstVariatesDistribution -= (m_numOfVariates * 2);
    m_SecondVariatesDistribution = SecVarArr;
}

double Probability::spread()
{
    double l_Result = 0;
    if (m_SecondVariatesDistribution == nullptr)
        secondDistribution();

    for (int i = 0; i < m_numOfVariates; i++)
    {
        l_Result += *(m_SecondVariatesDistribution) * *(m_FirstVariatesDistribution + 1);

        m_FirstVariatesDistribution += 2;
        m_SecondVariatesDistribution++;
    }
    m_FirstVariatesDistribution -= m_numOfVariates * 2;
    m_SecondVariatesDistribution -= m_numOfVariates;
    return sqrt(l_Result);
}

//----------------------------------------------------------
//---------------Binominal probability----------------------
//----------------------------------------------------------

//Binominal
Probability::Probability(double p, int n)
{
    m_p = p;
    m_q = 1-p;
    m_n = n;

    //writing out
    std::cout << "------------------------------------------------------------------------------------" <<std::endl;
    std::cout << std::endl;
    std::cout << "distribution array:" << std::endl;


    this->Binom_distribution();

    for (int k = 0; k <= m_n; k++)
    {
        std::cout << *m_Binom_VariateDistr
            << ' '
            << *(m_Binom_VariateDistr + 1)
            << std::endl;
        m_Binom_VariateDistr+=2;
    }
    m_Binom_VariateDistr -= ((m_n + 1) * 2);

    std::cout << "expected value: "<< this->Binom_expectedValue() << std::endl;
    std::cout << "spread: "<< this->Binom_spread() << std::endl;

}

void Probability::Binom_distribution()
{
    double* locArr;
    int z = (m_n + 1) * 2;
    locArr = new double[z];

    for (int k = 0; k <= m_n; k++)
    {
        *(locArr) = k;
        *(locArr + 1) = (nCr(m_n, k) * pow(m_p, k) * pow(m_q, (m_n - k)));
        locArr += 2;
    }

    locArr -= z;
    m_Binom_VariateDistr = locArr;
}

double Probability::Binom_expectedValue()
{
    return m_Binom_expVal = (m_n * m_p);
}

double Probability::Binom_spread()
{
    return  m_BinomSpread = sqrt(m_n * m_p * m_q);
}


//----------------------------------------------------------
//---------------Hypergeometric distribution----------------
//----------------------------------------------------------

//hypergeometric
Probability::Probability(double m, double s, double n)
{
    m_H_m = m;
    m_H_s = s;
    m_H_n = n;
    m_H_p = (s/m);


    //writing out
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "distribution array:" << std::endl;


    this->Hyper_distribution();

    for (int k = 0; k <= m_H_n; k++)
    {
        std::cout << *m_Hyper_VariateDistr
            << ' '
            << *(m_Hyper_VariateDistr + 1)
            << std::endl;
        m_Hyper_VariateDistr += 2;
    }
    m_Hyper_VariateDistr -= (((int)m_H_n+1)* 2); 

    std::cout << "expected value: " << this->Hyper_expectedValue() << std::endl;
    std::cout << std::endl;
    std::cout << "2nd distribution array:" << std::endl;

    this->Hyper_distributionVarNO2();

    for (int k = 0; k <= m_H_n; k++)
    {
        std::cout << *m_Hyper_VariateDistrNO2
            << std::endl;
        m_Hyper_VariateDistrNO2++;
    }
    m_Hyper_VariateDistrNO2 -= ((int)m_H_n+1);

    std::cout << "spread: " << this->Hyper_spread() << std::endl;
} 

void Probability::Hyper_distribution()
{
    double* locArr;
    int z = (m_H_n + 1) * 2;
    locArr = new double[z];

    for (int k = 0; k <= m_H_n; k++)
    {
        *(locArr) = k;
        double P = nCr(m_H_s, k) * nCr((m_H_m - m_H_s), (m_H_n - k));
        *(locArr + 1) = P/(nCr(m_H_m, m_H_n));
        locArr += 2;
    }

    locArr -= z;
    m_Hyper_VariateDistr = locArr;
}

void Probability::Hyper_distributionVarNO2()
{
    int z = ((m_H_n + 1));
 
    double* SecVarArr;
    SecVarArr = new double[z];

    for (int i = 0; i <= m_H_n; i++)
    {
        *SecVarArr = pow((*(m_Hyper_VariateDistr) - m_Hyper_expVal), 2);
        m_Hyper_VariateDistr +=2;
        SecVarArr++;
    }
    SecVarArr -= z;
    m_Hyper_VariateDistr -= z*2;
    m_Hyper_VariateDistrNO2 = SecVarArr;
}

double Probability::Hyper_expectedValue()
{
    return m_Hyper_expVal = (m_H_n*m_H_p);
}

double Probability::Hyper_spread()
{
    return m_HyperSpread = sqrt(m_H_n * m_H_p * (1 - m_H_p) * (1 - ((m_H_n - 1) / (m_H_m - 1))));
}
