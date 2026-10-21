#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

string isGood(int n)
{
    for(int i=1; i<n; i++)
    {


        double k = static_cast<double>(n) /(((static_cast<double>(i)*i) + 1 + 2*i)/i);

        /*
            if(n == 57379)
        {
            long A = abs(k-i);
            long B = k+i;
            long C = k/i;
            long D = k*i;
            
            cout << endl;

            cout << "k: " << k << endl;
            cout << "E: " << i << endl;
            cout << "A: " << A << endl;
            cout << "B: " << B << endl;
            cout << "C: " << C << endl;
            cout << "D: " << D << endl;

            cout << "A+B+C+D = " << A+B+C+D << endl;
            cout << "X: " << n << endl;
        }
        */
        
        if(fmod(k, 1.0) == 0.0) //Es entero y k>E
        {

            long A = abs(k-i);
            long B = k+i;
            long C = k/i;
            long D = k*i;
           
        

            if((A+B+C+D) == n) return "YES";
            

        }else continue; // K<E no seguimos.

        
      
    }
    return "NO";
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; cin.ignore();
        cout << isGood(x) << endl;
    }
    
}