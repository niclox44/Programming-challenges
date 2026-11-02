#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'mergeHighDefinitionIntervals' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY intervals as parameter.
 */

vector<vector<int>> mergeHighDefinitionIntervals(vector<vector<int>> intervals) {
   
    if(intervals.empty()) return intervals;
    
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    int nElement = 0;
    result.push_back(intervals[0]);
    
    for(int i=1; i<intervals.size(); i++)
    {
            
        if(result[nElement][1] <= intervals[i][0])
        {
            result.push_back(intervals[i]);
            nElement++;

        }else if(result[nElement][1] < intervals[i][1])
        {
            result[nElement][1] = intervals[i][1];
        }
    }
    
    return result;
}
int main() {
    int intervals_rows;
    int intervals_columns;

    cin >> intervals_rows >> intervals_columns;

    vector<vector<int>> intervals(
        intervals_rows,
        vector<int>(intervals_columns)
    );

    for (int i = 0; i < intervals_rows; i++) {
        for (int j = 0; j < intervals_columns; j++) {
            cin >> intervals[i][j];
        }
    }

    vector<vector<int>> result =
        mergeHighDefinitionIntervals(intervals);

    for (const vector<int>& interval : result) {
        cout << interval[0] << " " << interval[1] << "\n";
    }

    return 0;
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


