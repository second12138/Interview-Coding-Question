/*a company plans to shift its infrastructure to cloud. as a result they will rent k computing cores per day for n days. the company is provided with 
m pricing plans for this duration. each pricing plans has a l[i] and r[i] representing the days when it is available, c[i] cores available each day, 
and it costs p[i] to rent one core per day. the company can rent an arbitary number of cores on each day from each available plan, ranging from 0 to c[i] cores. 
given n,k and plans as a 2d array, the function returns the minimum cost to complete the process.*/

#include <bits/stdc++.h>
#include <limits>
using namespace std;

long getMinCost(int n, int k, vector<vector<int>> plans) {
    // Sort the plans based on their prices
    sort(plans.begin(), plans.end(),[]
    (const vector<int> &a, const vector<int> &b){
        return a[3] < b[3];
    });
    long minCost=0;
    //interate all the days
    for(int i=0; i<=n; i++){
        int curr_c=k, curr_p=0, total_c=k;
        //interate all the plans
        if(total_c==0){
                    break;
                }
        for(auto &p : plans){
            //if the plan is not available on that day just continue
            if(i<p[0]||i>p[1]){
                continue;
            }else{
                //if we 
                
                curr_c=min(curr_c, p[2]);
                curr_p=curr_c*p[3];
                total_c-=curr_c;
                curr_c=total_c;
                minCost+=curr_p;
            }
        }
    }
    return minCost;
}

int main() {
    // Example usage
    int n = 4, k = 100;
    vector<vector<int>> plans = {{3, 3, 2, 5}, {1, 1, 3, 2}, {2, 4, 4, 4}};
    long result = getMinCost(n, k, plans);
    cout << "Minimum Cost: " << result << endl;

    return 0;
}