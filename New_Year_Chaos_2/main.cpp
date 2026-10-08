#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

void minimumBribes(vector<int> q) {
    long totalBribes = 0;
    
    for(long i= static_cast<int>(q.size())-1; i>=0; i--)
    {
        int expected = i+1;

        if(q[i] == expected) continue;

        if(i>=1 && q[i-1] == expected){
            swap(q[i-1], q[i]);
            totalBribes++;
        }
        else if(i>=2 && q[i-2] == expected)
        {
            swap(q[i-2], q[i-1]);
            swap(q[i-1], q[i]);
            totalBribes += 2;
        }
        else
        {
            cout << "Too chaotic" << endl;
            return;
        }
    }

    cout << totalBribes << endl;

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

        string q_temp_temp;
        getline(cin >> ws, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}
string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) {
            return !std::isspace(c);
        })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) {
            return !std::isspace(c);
        }).base(),
        s.end()
    );

    return s;
}
vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
