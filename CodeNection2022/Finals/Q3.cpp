#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int gcd(int a, int b);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T{};
    cin>>T;
    if(T < 1 || T > 1000000)
        return -1;

    int facultyStudent[T];
    for(int i{}; i<T; i++)
    {
        cin>>facultyStudent[i];
        if(facultyStudent[i] < 1 || facultyStudent[i] > 1000000)
            return -1;
    }

    int commonFac{};
    //int highestFac{};
    commonFac = gcd(facultyStudent[0],facultyStudent[1]);
    for(int i = 2; i<T; i++)
    {
        commonFac = gcd(commonFac, facultyStudent[i]);
    }

    int sumStudent = 0;
    for(int i{}; i<T; i++)
    {
        sumStudent += facultyStudent[i]/commonFac;
    }
    cout<<sumStudent;

    return 0;
}

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}