//this code failed many hidden test cases, which I can't figure out why
#include <bits/stdc++.h>
using namespace std;
//determine if current year is a leap year, if so, there is no Feb 29.
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
} 
 
bool isValidTime(const string &timeStr) {
    tm tm = {};
    istringstream ss(timeStr);
    ss >> get_time(&tm, "%H:%M:%S");
    return !ss.fail() && tm.tm_hour >= 0 && tm.tm_hour < 24 &&
           tm.tm_min >= 0 && tm.tm_min < 60 &&
           tm.tm_sec >= 0 && tm.tm_sec < 60;;
}

bool isValidDate(const string &dateStr) {
    tm tm = {};
    istringstream ss(dateStr);
    ss >> get_time(&tm, "%Y-%m-%d");

    // Check for failure and additional conditions for a valid date
    return !ss.fail() &&
           tm.tm_mon >= 0 && tm.tm_mon < 12 &&
           tm.tm_mday > 0 && tm.tm_mday <= 31 &&
           ((tm.tm_mon != 1 || tm.tm_mday != 29) || isLeapYear(tm.tm_year + 1900));
}
bool compareUserIds( const vector<string> &entry1, const vector<string> &entry2){
    int userid1=stoi(entry1[0].substr(4));
    int userid2=stoi(entry2[0].substr(4));
    
    return userid1<userid2;
}

bool compareDates( const vector<string> &entry1, const vector<string> &entry2){
    if(stoi(entry1[0].substr(4))==stoi(entry2[0].substr(4))){
        return entry1[1]<entry2[1];
    }
    return stoi(entry1[0].substr(4))<stoi(entry2[0].substr(4));
}
vector<vector<string>> countUserLogins(vector<vector<string>> logs) {
    map<int, map<string, int>> userCounts;
    
    for(const auto &log:logs){
        if(log.size()==3){
            if (isValidTime(log[1]) && isValidDate(log[2])) {
                int user_id=stoi(log[0].substr(4));
                userCounts[user_id][log[2]]++;
            }
        }
        
        
    }
    vector<vector<string>> outputLogs;
    for(const auto &userEntry: userCounts){
        int user_id=userEntry.first;
        for(const auto &dateEntry:userEntry.second){
            string login_date=dateEntry.first;
            int login_count=dateEntry.second;
            outputLogs.push_back({"user" + std::to_string(user_id), login_date, std::to_string(login_count)});
        }
    }
    sort(outputLogs.begin(), outputLogs.end(), compareUserIds);
    sort(outputLogs.begin(), outputLogs.end(), compareDates);
    
    return outputLogs;
}