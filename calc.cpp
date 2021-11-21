/**
 * @file calculator.cpp
 * @author Nikolai Uzhinskii
 * @brief calculates value from reverse polish notation, takes int only 
 * @version 0.1
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

/**
 * @brief Get int number from string staring from i-th character
 * 
 * @param s string from which fucntion gets the number
 * @param start number of character, from which function starts to get integer number 
 * @return integer number
 */

int GetNum(string s, int start)
{
    int result = 0;
    int i = start;
    while(s[i] >= '0' && s[i] <= '9' && i<=s.length())
    {
        result *= 10;
        result += s[i] - '0';
        i++;
    }
    return result;
}

int main()
{
    /**
     * @brief stack of values
     * keeps current result of calculations and values to be included in calculations
     * num.top is a current result of calculations
     */
    stack <double> num;
    double temp1, temp2;
    /**
     * @brief string from which we will get numbers and operation signs
     * 
     */
    string s;
    getline(cin, s);
    /**
     * @brief main cycle
     * goes character by character, if its a number, reads it with GetNum function
     * if its an operation sign, executes it 
     * only revers polish notation
     * only "+", "-", "*", "/" operations
     */
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            temp1 = GetNum(s,i);
            num.push(temp1);
        }
        else if(s[i] == '+')
        {
            temp1 = num.top();
            num.pop();
            temp2 = num.top();
            num.pop();
            num.push(temp1+temp2);
        }
        else if(s[i] == '-')
        {
            temp1 = num.top();
            num.pop();
            temp2 = num.top();
            num.pop();
            num.push(temp1-temp2);
        }
        else if(s[i] == '*')
        {
            temp1 = num.top();
            num.pop();
            temp2 = num.top();
            num.pop();
            num.push(temp1 *temp2);
        }
        else if(s[i] == '/')
        {
            temp1 = num.top();
            num.pop();
            temp2 = num.top();
            num.pop();
            num.push(temp1/temp2);
        }
    }
    cout << num.top() << endl;
    return 0;
}