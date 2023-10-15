// There is a frog on the '1st' step of an 'N' stairs long staircase.
// The frog wants to reach the 'Nth' stair. 'HEIGHT [i]' is the
// height of the '(i+l)th' stair.lf Frog jumps from 'ith' to 'jth' stair,
// the energy lost in the jump is given by absolute value of (
// HEIGHT[i-1] - HEIGHT[j-1] If the Frog is on 'ith' staircase,
// he can jump either to '(i+l)th' stair or to '(i+2)th' stair. Your
// task is to find the minimum total energy used by the frog to
// reach from '1st' stair to 'Nth' stair.

// ---Test Cases---

// 4 -> No. of test cases
// 4 -> No. of element in array
// 10 20 30 10 -> array elements

// 3
// 10 50 10

// 8
// 7 4 4 2 6 6 3 4 

// 6
// 4 8 3 10 4 4 

#include <bits/stdc++.h>
using namespace std;

//With DP Memoization
//Time->O(n)
//Space->O(n)(Stack)+O(w)(Array)
int MinEnergyMemoization(int n,vector<int>& heights,vector<int> dp){
    if(n==0) return 0;
    if(dp[n] != -1){
        return dp[n];
    }
    int left = MinEnergyMemoization(n-1,heights,dp) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if(n>1){
        right = MinEnergyMemoization(n-2,heights,dp) + abs(heights[n] - heights[n-2]);
    }

    return dp[n] = min(left,right);
}


//With DP Aarray
//Time->O(n)
//Space->O(n)

// int MinEnergyDP(int n,vector<int>& heights,vector<int> dp){
//     dp[0] = 0;
//     for(int i=1;i<n;i++){
//          int left = dp[i-1] + abs(heights[i]-heights[i-1]);
//          int right = INT_MAX;
//         if(i>1){
//             right = dp[i-2] + abs(heights[i]-heights[i-2]);
//         }
//         dp[i] = min(left,right);
//     }
//     return dp[n-1];
// }


//WithOut DP Aarray
//Time->O(n)
//Space->O(1)
int MinEnergyDP(int n,vector<int>& heights){
    int prev = 0,prev2 = 0;
    int curr = 0;
    for(int i=1;i<n;i++){
         int left = prev + abs(heights[i]-heights[i-1]);
         int right = INT_MAX;
        
        if(i>1){
            right = prev2 + abs(heights[i]-heights[i-2]);
        }
        
        curr = min(left,right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> heights(n);
        for(int i = 0;i<n;i++){
            cin>>heights[i];
        }
        vector<int> dp(n+1,-1);
        cout<<"Mix Energy With Memoization: "<<MinEnergyMemoization(n-1,heights,dp)<<endl;
        //  cout<<"Mix Energy With DP: "<<MinEnergyDP(n,heights,dp)<<endl; 
        cout<<"Mix Energy With DP: "<<MinEnergyDP(n,heights)<<endl; 
    }
}