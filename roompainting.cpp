#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    //store the sold painting in a sorted vector
    //for each input, lower bound to get the closest amt 
    int sold,needed,size;
    long long extra = 0;
    vector<int> soldCans;
    
    cin >> sold >> needed;
    while(sold--){
        cin >> size;
        soldCans.push_back(size);
    }
    
    sort(soldCans.begin(),soldCans.end());
    
    while(needed--){
        cin >> size;
        auto bought = lower_bound(soldCans.begin(),soldCans.end(),size);//amt of the bought can
        extra += (*bought - size);
    }
    cout << extra;
}