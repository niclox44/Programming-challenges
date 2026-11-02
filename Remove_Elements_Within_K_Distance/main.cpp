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
    
    int count = 1;
    long number = timestamps[0];
    cout << timestamps.size();
    for(size_t i=1; i<timestamps.size(); i++)
    {
        cout << static_cast<long>(timestamps[i]-number) << endl;
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

        int timestamps_item = stoi(timestamps_item_temp);

        timestamps[i] = timestamps_item;
    }

    string K_temp;
    cin >> K_temp;

    int K = stoi(K_temp);

    int result = debounceTimestamps(timestamps, K);

    cout << result << "\n";

    return 0;
}

