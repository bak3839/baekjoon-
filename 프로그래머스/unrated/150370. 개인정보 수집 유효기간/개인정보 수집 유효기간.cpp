#include <string>
#include <vector>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> ans;
    vector<int> t(26);
    
    int tyear = stoi(today.substr(0, 4));
    int tmonth = stoi(today.substr(5, 2));
    int tday = stoi(today.substr(8, 2));
    
    // 약관별 기간 알파벳 순서로 배열에 저장
    for(int i = 0; i < terms.size(); i++) {
        char ch = terms[i][0];        
        string month = terms[i].substr(2);
        
        t[ch - 'A'] = stoi(month);
    }
    
    for(int i = 0; i < privacies.size(); i++) {
        char ch = privacies[i].back();
        
        int year = stoi(privacies[i].substr(0, 4));
        int month = stoi(privacies[i].substr(5, 2));
        int day = stoi(privacies[i].substr(8, 2));
        
        int period = t[ch - 'A'];
        
        int share = (period + month) / 12;
        int mod = (period + month) % 12;
        
        month = mod;
        year += share;        
        day--;
        
        if(month == 0) {
            month = 12;
            year--;
        }
        
        if(day == 0) {
            month--;
            day = 28;          
            if(month == 0) {
                year--;
                month = 12;
            }
        }
        
        if(year < tyear) ans.push_back(i + 1);
        
        else if(year == tyear) {
            if(month < tmonth) ans.push_back(i + 1);
            
            else if(month == tmonth) {
                if(day < tday) ans.push_back(i + 1);
            }
        }
    }
    
    return ans;
}