#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    std::string time;
    time.push_back(s[s.size()-2]);
    time.push_back(s[s.size()-1]);
    
    std::string final_time;
    std::string hour;
    hour.push_back(s[0]);
    hour.push_back(s[1]);
    int int_hour = std::stoi(hour);
    
    if(time == "AM" && int_hour >= 12){
        int_hour -= 12;
        hour = std::to_string(int_hour);
        
        final_time.push_back(hour[0]);
        final_time.push_back(hour[1]);
        
        for(int i=2; i<s.length()-2; i++) final_time.push_back(s[i]);
        
        
    }else if(time == "PM" && int_hour < 12){
        
        int_hour += 12;
        hour = std::to_string(int_hour);
        
        final_time.push_back(hour[0]);
        final_time.push_back(hour[1]);
        
        for(int i=2; i<s.length()-2; i++) final_time.push_back(s[i]);
    }else{
        for(int i=0; i<s.length()-2; i++) final_time.push_back(s[i]);
    }
    
    return final_time;
}

int main()
{

    string s;
    std::cin >> s;

    string result = timeConversion(s);

    std::cout << result << "\n";

    return 0;
}
