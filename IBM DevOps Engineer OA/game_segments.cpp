/* A video game developer is developing a game in which the character makes their way through several segments of a level. 
In each segment, if the character collects a coin, the player scores a point. However, if a segment does not contain a coin, 
the player loses a point. Player 1 always begins the level, and, at some point, game play is turned over to Player 2 to 
complete the level. Player 1 's goal is to achieve a higher score than Player 2 once the level is completed. Given the 
status of game segments (whether they contain a coin or not), determine the minimum number of segments Player 1 
should play so that, in the end, their score is greater than Player 2's score.


Example
segments =[1,1,0,1]
Player 1 has the following options:

Play 0 segments. This would give them a score of 0 . Player 2 would have a score of 3-1=2 
(because they gain a point for each of the 3 segments with a coin, and lose 1 point for the segment without a coin).

Play 1 segment. This would give them a score of 1 Player 2 would have a score of 2*1=1.

Play 2 segments. This would give them a score of 2 Player 2 would have a score of l*l=0,*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);

string rtrim(const string &);



/*

* Complete the 'playSegments' function below.

*

* The function is expected to return an INTEGER.

* The function accepts INTEGER_ARRAY coins as parameter.

*/

int playSegments(vector<int> coins) {
    //points of player one and two
    int playerTwoSum = 0, playerOneSum = 0;
    
    //calculate the expected points of player two if player one play zero segement
    for (int coin : coins) {
       if(coin==1){
           playerTwoSum++;
       }else{
           playerTwoSum--;
       }
    }

    //if points of player one still bigger than player two just return 0 segement
    if(playerOneSum>playerTwoSum){
        return 0;
    }

    // Start from the first segment and iterate through the list.
    for (int i = 0;i<coins.size();i++) {
        //if player one play this segement
        if(coins[i]==1){
            playerOneSum++;
            playerTwoSum--;
        }else{
            playerTwoSum++;
            playerOneSum--;
        }
        //when player one can win the current number of segements
        if(playerOneSum>playerTwoSum){
            return i+1;
        }
    }
    
    // If never a good moment to stop, play all segments
    return coins.size();
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));
    string coins_count_temp;
    getline(cin, coins_count_temp);
    int coins_count = stoi(ltrim(rtrim(coins_count_temp)));
    vector<int> coins(coins_count);
    for (int i = 0; i < coins_count; i++) {
        string coins_item_temp;
        getline(cin, coins_item_temp);
        int coins_item = stoi(ltrim(rtrim(coins_item_temp)));
        coins[i] = coins_item;
    }
    int result = playSegments(coins);
    fout << result << "\n";
    fout.close();
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