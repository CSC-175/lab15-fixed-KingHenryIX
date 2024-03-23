/*******************************************************************
* getInfo *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
*******************************************************************/
#include <iostream>
using namespace std;

double factorial(int n);


void getInfo(int & pickFrom, int & numPicks){
do{
cin.clear();
cout << "How many balls (1-12) are in the pool to pick from?";
cin >> pickFrom;
if(cin.fail() or pickFrom <1 or pickFrom >12){
    cin.fail() ? cout << "Input Error!\n" : cout << "Input Error! There must be between 1 and 12 balls.\n";

    cin.ignore(100, '\n');
}
} while (cin.fail());

do{
cin.clear();
cout << "How many balls (1-7) will be drawn?";
cin >> numPicks;
if(cin.fail() or numPicks <1 or numPicks >7){
    cin.fail() ? cout << "Input Error!\n" : cout << "Input Error! There must be between 1 and 7 balls.\n";

    cin.ignore(100, '\n');
}
} while (cin.fail());
}

/******************************************************************
* computeWays                                                     *
* Computes and returns the number of different possible sets      *
* of k numbers that can be chosen from a set of n numbers.        *
* The formula for this is     k!(n- k)!                           *
*                             --------                            *
*                                 n!                              *

How many balls (1-12) are in the pool to pick from? 7
How many balls (1-7) will be drawn? 9
Input Error! 
How many balls (1-7) will be drawn? 3

Probability of winning is 0.0286
Odds of winning are 1 in 35

Would you like to calculate the probability of another scenario? (y/n): y

How many balls (1-12) are in the pool to pick from? 14
Input Error! There must be between 1 and 12 balls.
How many balls (1-12) are in the pool to pick from? 12
How many balls (1-12) will be drawn? red
Input Error! 
How many balls (1-12) will be drawn? 5

Probability of winning is 0.0013
Odds of winning are 1 in 791

Would you like to calculate the probability of another scenario? (y/n): n
*******************************************************************/
// Note that the computation is done in a way that does not require
// multiplying two factorials together. This is done to prevent any
// intermediate result becoming so large that it causes overflow.
double computeWays(int n, int k){
    double result = factorial(n) / (factorial(k) * factorial(n - k));
    cout << result;
    return 1 / result;
}

// This function computes factorials recursively. It is called by computeWays.
double factorial(int n){
    if(n == 0 or n == 1){
        return 1;
    } else{
        return n * factorial (n-1);
    }
}