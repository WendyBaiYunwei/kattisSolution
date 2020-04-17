#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

vector<vector<int>> redList;
bool cycle;
vector<bool> visited;
set<int> stopPoints;

void dfs(int start,int a, int b, int fault){
    bool stop = 1;
    
    if(fault == 1 && start == a && visited[start] != 1){
        visited[start] = 1;
        stop = 0;
        dfs(b,a,b,fault);
    }

    visited[start] = 1;
    
    for(auto i: redList[start]){
        stop = 0;
        if(visited[i] == 0)
            dfs(i,a,b,fault);
    }
    
    if(stop == 1)
        stopPoints.insert(start);
}

int main(){         
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int vertices,edges,a,b;
    vector<pair<int,int>> black;
    cin >> vertices >> edges;
    
    redList.assign(1000,vector<int>());
    
    while(edges--){
        cin >> a >> b;
        if(a > 0)
            black.push_back(make_pair(a,b));
        else
            redList[-a].push_back(b);
    }
    
    
    for(auto i: black){
        visited.assign(1000,0);
        dfs(1,i.first,i.second,1);
    }
    
    //no fault
    dfs(1,1,1,0);

    /*for(auto i: stopPoints)
        cout << i << endl;*/
    cout << stopPoints.size();
}