#include <bits/stdc++.h>

using namespace std;


#include <map>

/*
 * Complete the 'getRemovableIndices' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING str1
 *  2. STRING str2
 */

vector<int> getRemovableIndices(string str1, string str2) {
    int n = str2.length();
    int right = str1.size();
    int left = 0;
    std::vector<int> pos;

    while(left < n && str1[left] == str2[left]){
        left++;
    }
    while(right > 0 && str1[right] == str2[right-1]){
        right--;
    }
    
    if(right > left){
        return {-1};
    }

    for(int i=right; i <= left; i++)
    {
        pos.push_back(i);
    }

    return pos;
    
}

int main()
{
    string str1;
    cin >> str1;    

    string str2;
    cin >> str2;

    vector<int> result = getRemovableIndices(str1, str2);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}
