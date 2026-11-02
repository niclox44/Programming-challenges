#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'generateAngleBracketSequences' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts INTEGER n as parameter.
 */

 void generate(
    int n,
    int open,
    int close,
    string& current,
    vector<string>& result
 )
 {
    if(current.size() == size_t(n*2))
    {
        result.push_back(current);
        return;
    }

    if(open < n)
    {
        current.push_back('<');
        generate(n, open+1, close, current, result);
        current.pop_back();
    }

    if(close < open)
    {
        current.push_back('>');
        generate(n, open, close+1, current, result);
        current.pop_back();
    }
 }

vector<string> generateAngleBracketSequences(int n) {
   vector<string> result;
   string current;

   generate(n,0,0,current, result);

   return result;
    
}

int main()
{
    int n;
    cin >> n;

    vector<string> result = generateAngleBracketSequences(n);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
