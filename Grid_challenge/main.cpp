#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
 */

string gridChallenge(vector<string> grid) {
   
    
    int n  = grid.size();
    std::vector<int> sumsRows(n,0);

    for(int i=0; i<n-1; i++)
    {
        std::sort(grid[i].begin(), grid[i].end());
        std::sort(grid[i+1].begin(), grid[i+1].end());
        
        for(int j=0; j<n; j++)
        {
            if(grid[i][j] < grid[i+1][j]) return "NO";
            
            cout << "[" << i << "]" << "[" << j << "]: " << grid[i][j] << endl;
            cout << "[" << i+1 << "]" << "[" << j << "]: " << grid[i+1][j] << endl;
        }
    }
    
    return "YES";
}

int main()
{

    string t_temp;
    cin >> t_temp;

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        cin >> n_temp;

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            cin >> grid_item;

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

        cout << result << "\n";
    }

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
