#include <bits/stdc++.h>
using namespace std;

//Time -> O(n)
//Space -> O(n) for recursion + O(n) for Vector
int fiboWithRecursion(vector<int> &dp, int n)
{

    if (n <= 1){
        return n;
    }
    if (dp[n] != -1){
        return dp[n];
    }
    return dp[n] = fiboWithRecursion(dp,n-1) + fiboWithRecursion(dp,n-2);
}

//Time -> O(n)
//Space -> O(n) for Vector
int fiboWithDp(vector<int> &dp, int n){
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i < n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{

    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout<<"Dp with recursion"<<endl;
    cout << fiboWithRecursion(dp, n) << endl;
    cout<<"Only Dp"<<endl;
    cout << fiboWithDp(dp, n) << endl;
    return 0;
}