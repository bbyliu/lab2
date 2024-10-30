#ifndef BANKPERCENTAGERATE_H
#define BANKPERCENTAGERATE_H

#include <string>
#include <iostream>
using namespace std;

/**----------------------------------------------------------------------------------------
********** For Lab Submission: Do NOT change anything in BankPercentageRate.h ************
----------------------------------------------------------------------------------------**/

class BankPercentageRate
{
    public:
        BankPercentageRate(string bankName);  // Constructor of the class "BankPercentageRate"
        virtual ~BankPercentageRate();  // Constructor of the class "BankPercentageRate"

        string GetBankName() { return m_BankName; } // Get the name string stored inside the private variable "m_BankName"
        float GetDeposit() { return m_Deposit; } // Get the rate stored inside the private variable "m_Rate"

        void DepositToBank(float depositValue); // Declare the function for problem 1
        float EstimateInterestByRate(float depositValue, float percentageRate); // Declare the function for problem 2
        float EstimateInterestByYearDependentRate(float depositValue, int depositTimeDuration); // Declare the function for problem 3
        float EstimateInterestByYearDependentRate2(float depositValue, unsigned int depositTimeDuration); // Declare the function for problem 4
        void EstimateDepositFromCompoundInterest(float increasedDepositByYear[], float depositValue, int depositTimeDuration, float percentageRate); // Declare the function for problem 5

    private:
        string m_BankName = ""; // Private variable to be used in this lab, storing the name of your bank
        float m_Deposit = 0.0; // Private variable to be used in this lab, storing the deposit value of your bank
};

#endif // BANKPERCENTAGERATE_H


BankPercentageRate::BankPercentageRate(string bankName) // Constructor of the class "BankPercentageRate"
{
    m_BankName = bankName;
    cout << "A bank has been created under the name of " << m_BankName << endl;
}

BankPercentageRate::~BankPercentageRate() // Destructor of the class "BankPercentageRate"
{
    //Keep it empty for this class
}

/**----------------------------------------------------------------------------------------
******************************** LAB CONENT START FROM HERE *******************************
----------------------------------------------------------------------------------------**/

/**------------------------------- Problem 1 ---------------------------------------**/
void BankPercentageRate::DepositToBank(float depositValue)
{
    /*Adjust "m_Deposit" by adding/subtracting the changed value "depositValue", note that
    there is not return value needed since "m_Deposit" is a private variable of the class that
    can store the existing deposit.
    Function inputs:
        "depositValue" - value change to be added to the existing deposit "m_Deposit"
    */

   // Complete the following line of code

   m_Deposit += depositValue;
}

/**------------------------------- Problem 2 ---------------------------------------**/
float BankPercentageRate::EstimateInterestByRate(float depositValue, float percentageRate = 1.80)
{
    /*Compute the estimated interest by multiplying depositValue and percentageRate, note that
    the percentageRate should be converted from percentage to a fraction by dividing 100; For example,
    given depositValue = 1000 and percentageRate = 1.8 (%), then estimatedInterest = 18.
    Function inputs:
        "depositValue" - a given value of deposit to be used for estimating the earned interest
        "percentageRate" -  given interest rate in percentage, e.g., 1.80% = 0.018
    Function output:
        "estimatedInterest" - interest value earned
    */

   // Complete the code

   float rateFraction = percentageRate / 100.0;
   float estimatedInterest = depositValue * rateFraction;

   return estimatedInterest;
}

/**------------------------------- Problem 3 ---------------------------------------**/
float BankPercentageRate::EstimateInterestByYearDependentRate(float depositValue, int depositTimeDuration)
{
    /*Compute the estimated interest based on rate depending on the time duration of the deposit.
    The interest rates for different deposit time durations (from 1 year to 3 years) are given.
    For example, given depositValue = 1000, if deposit for only 1 year, which has a rate of 1.35 (%),
    then estimatedInterest = 13.5; however, if deposit for 3 years, which has a rate of 1.75 (%),
    then estimatedInterest = 17.5. Try realizing this function using "Switch" or "If" statements.
    Function inputs:
        "depositValue" - a given value of deposit to be used for estimating the earned interest
        "depositTimeDuration" - number of years to be used to get the interest rate and compute the interest
    Function output:
        "estimatedInterest" - interest value earned
    */

    const float oneYearRate = 1.35, twoYearRate = 1.45, threeYearRate = 1.75; // Here, we only consider varied rates of one, two, and three years (don't change them)

    // Complete the code, note that some variable definitions are missing.
    // Hint: Aside from rewriting the interest estimation code, you can reuse the function created in problem 2
    float percentageRate;

    switch (depositTimeDuration)
    {
    case 1:
        percentageRate = oneYearRate;
        break;
    case 2:
        percentageRate = twoYearRate;
        break;
    case 3:
        percentageRate = threeYearRate;
        break;    
    default:
        return 0;
    }
    float estimatedInterest = depositValue * (percentageRate / 100);
    return estimatedInterest;
}

/**------------------------------- Problem 4 ---------------------------------------**/
float BankPercentageRate::EstimateInterestByYearDependentRate2(float depositValue, unsigned int depositTimeDuration)
{
    /*Realize the same function in problem 3 without using any "Switch" or "If" statements.
    This time, we store the year dependent interest rate inside a float array, which allow
    us to find the needed rate value via indexing. Function inputs and output are the same as defined in Problem 3��
    Function inputs:
        "depositValue" - a given value of deposit to be used for estimating the earned interest
        "depositTimeDuration" - number of years to be used to get the interest rate and compute the interest
    Function output:
        "estimatedInterest" - interest value earned
    */

    const float yearDependentRate[5] = {1.35, 1.45, 1.75, 1.78, 1.80}; // Here, we consider varied rates of one to five years (don't change them)

    // Complete the code, note that some variable definitions are missing.
    // Hint: use "if" here to check and ensure a valid indexing of the array "yearDependentRate"
    if (depositTimeDuration > 0 && depositTimeDuration <= 5)
    {
        float percentageRate = yearDependentRate[depositTimeDuration - 1];
        return EstimateInterestByRate(depositValue, percentageRate);
    }
    return 0;
}

/**------------------------------- Problem 5 ---------------------------------------**/
void BankPercentageRate::EstimateDepositFromCompoundInterest(float increasedDepositByYear[], float depositeValue, int depositTimeDuration, float percentageRate = 1.80)
{
    /*Compute the estimated deposit from Compound Interest for deposit up to N years, where 1 < N < 1000.
    The compound interest is defined as: for year i, Deposit(i) = Deposit(i-1) + Deposit(i-1)*Rate,
    namely, the deposit of current year equals to the deposit from the last year plus the interest earned
    from last year. Note that here the interest rate is fixed and stays the same for each year.
    For example, given a starting deposit of 100 CNY and a fixed rate of 10%, after one year,
    the deposit will be increased to 100+(100*0.1)=110 CNY, then, after another year (2nd year), the deposit
    will be 110+(110*0.1) = 121 CNY. And after the 3rd years, the deposit will be 121+(121*0.1) = 133.1 CNY.
    Realize this iterative interest computation (compound interest) by utilizing a "For" loop.
    Function inputs:
        "increasedDepositByYear" - An array passing by pointer to this function to store the result. Note that
        this function does not "return" anything. (see Lecture 6 arrays and Lecture 10 pointers)
        "depositValue" - a given value of deposit to be used for estimating the earned interest
        "depositTimeDuration" - number of years to be used to get the interest rate and compute the interest
        "percentageRate" -  given yearly interest rate in percentage, e.g., 1.80% = 0.018
    */

    // Complete the code, using 'for' or 'while' loop to realize the function

    float rateFraction = percentageRate / 100;

    
    for (int i = 0; i < depositTimeDuration; i++)
    {
      if (i == 0)
        {
            increasedDepositByYear[i] = depositeValue + depositeValue * rateFraction;
        }
        else
        {
            increasedDepositByYear[i] = increasedDepositByYear[i - 1] + increasedDepositByYear[i - 1] * rateFraction;
        }
    }
    
}


/**----------------------------------------------------------------------------------------
********************************** LAB CONENT ENDS HERE **********************************
----------------------------------------------------------------------------------------**/

/**----------------------------------------------------------------------------------------
*************** For Lab Submission: Do NOT change anything in main.cpp *******************
----------------------------------------------------------------------------------------**/

int main()
{
    string bankName = "X's Bank"; // Create a name for your bank
    BankPercentageRate myBankRate(bankName); // Instantiate the class "BankPercentageRate" and provide your bank name as input to its constructor

    /**------------------------------------------------ Testing Problem 1 --------------------------------------------------------**/
    myBankRate.DepositToBank(1000); // Stored 1000 CNY to your bank

    cout << "[Testing Problem 1]\nDeposit of " << myBankRate.GetBankName() << " is " << myBankRate.GetDeposit() << " CNY" << endl << endl;

    /**------------------------------------------------ Testing Problem 2 --------------------------------------------------------**/
    cout << "[Testing Problem 2]\nGiven a deposit of 10000 CNY, interest of 2.5% rate will be "
    << myBankRate.EstimateInterestByRate(10000, 2.5) << " CNY" << endl;

     cout << "For current deposite (" << myBankRate.GetDeposit() << " CNY) in " << myBankRate.GetBankName() << ", interest of 1.1% rate is  "
    << myBankRate.EstimateInterestByRate(myBankRate.GetDeposit(), 1.1) << " CNY" << endl << endl;


    /**------------------------------------------------ Testing Problem 3 --------------------------------------------------------**/
    float givenDeposit = 20000;
    cout << "[Testing Problem 3]\nGiven a deposit of " << givenDeposit << " CNY\n, interest for 1-year deposit will be "
    << myBankRate.EstimateInterestByYearDependentRate(givenDeposit, 1) << " CNY" << endl
    << ", interest for 2-year deposit will be " << myBankRate.EstimateInterestByYearDependentRate(givenDeposit, 2) << " CNY" << endl
    << ", interest for 3-year deposit will be " << myBankRate.EstimateInterestByYearDependentRate(givenDeposit, 3) << " CNY" << endl << endl;

    /**------------------------------------------------ Testing Problem 4 --------------------------------------------------------**/
    givenDeposit = 20000;
    cout << "[Testing Problem 4]\nGiven a deposit of " << givenDeposit << " CNY\n, interest for 2-year deposit will be "
    << myBankRate.EstimateInterestByYearDependentRate2(givenDeposit, 2) << " CNY" << endl
    << ", interest for 5-year deposit will be " << myBankRate.EstimateInterestByYearDependentRate2(givenDeposit, 5) << " CNY" << endl << endl;

    /**------------------------------------------------ Testing Problem 5 --------------------------------------------------------**/
    givenDeposit = 10000; // (CNY)
    int totalDepositDuration = 10; // (Years)
    float givenRate = 2.25; // (%)

    float* yearlyDeposit = new float[totalDepositDuration]; // Results to be stored inside this array, which will be initialized by the "EstimateDepositFromCompoundInterest" function

    myBankRate.EstimateDepositFromCompoundInterest(yearlyDeposit, givenDeposit, totalDepositDuration, givenRate);

    cout << "[Testing Problem 5]\nGiven a deposit of " << givenDeposit << " CNY and a rate of " << givenRate << " %, yearly deposit will be: " << endl;
    for(int i = 0; i < totalDepositDuration; ++i)
    {
        cout << "After " << i+1 << " year, your deposit will be " << yearlyDeposit[i] << endl;
    }

    return 0;
}
