#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'debounceTimestamps' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY timestamps
 *  2. INTEGER K
 */

int debounceTimestamps(vector<int> timestamps, int K) {
    
    int count = 0;
    long number = timestamps[0];
    
    for(int i=1; i<timestamps.size(); i++)
    {
        if(static_cast<long>(timestamps[i]-number) >= K)
        {
            number = timestamps[i];
            count ++;
        }
        
    }
    return count;
}

int main()
{
    string timestamps_count_temp;
    cin >> timestamps_count_temp;

    int timestamps_count = stoi(timestamps_count_temp);

    vector<int> timestamps(timestamps_count);

    for (int i = 0; i < timestamps_count; i++) {
        string timestamps_item_temp;
        cin >> timestamps_item_temp;

        int timestamps_item = stoi(ltrim(rtrim(timestamps_item_temp)));

        timestamps[i] = timestamps_item;
    }

    string K_temp;
    cin >> K_temp;

    int K = stoi(ltrim(rtrim(K_temp)));

    int result = debounceTimestamps(timestamps, K);

    cout << result << "\n";

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
