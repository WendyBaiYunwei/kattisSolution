#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int members,songs,song,i,j,k,divider,max = 0;
    vector<vector<int>> ranks;
    vector<int> maxDist;
    
    ranks.assign(1000000,vector<int>());
    maxDist.assign(1000000,0);
    
    cin >> members >> songs;
    for(k = 0;k < members; k++){
        for(i = 0;i < songs; i++){
            cin >> song;
            ranks[k].push_back(song);
        }
    }//what's the time complexity here?
    
    //find out the max distance from the beginning of each song. song-number-indexed
    for(k = 0;k < members; k++){
        for(i = 0;i < songs; i++){
            if(i > maxDist[ranks[k][i]])
                maxDist[ranks[k][i]] = i;
        }
    }
    
    for(divider = 0; divider < songs; divider++){
        for(k = 0;k < members; k++){
            if(maxDist[ranks[k][divider]] > max)
                max = maxDist[ranks[k][divider]];
        }
        if(max == divider)
            break;
    }
    
    cout << max+1 << endl;
    
    sort(ranks[0].begin(),ranks[0].begin() + max + 1);
    for(i = 0;i < max + 1; i++)
        cout << ranks[0][i] << ' ';
}