#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
vector<vector<pair<int,int>>> AL;//vertex index and weight
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//distance and index

void dikjstra(int start){
    ii u;
    //assign 0 and 1e9
    dist[start] = 0;
    pq.push(make_pair(0,start));
    
    while(!pq.empty()){
        //find the min dist node, and relax all its edges
        u = pq.top();
        pq.pop();
        
        for(auto v: AL[u.second])
            if(dist[u.second] + v.second < dist[v.first]){
                dist[v.first] = dist[u.second] + v.second;
                pq.push(make_pair(dist[v.first],v.first));
            }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int nodes,edges,queries,start,from,to,weight,dest;
    int result;
    
    while(cin >> nodes >> edges >> queries >> start, 
    nodes || edges || queries || start){
        
        AL.clear();
        dist.clear();
        while(!pq.empty())
            pq.pop();
        AL.assign(10000,vector<pair<int,int>>());
        dist.assign(10000,1e9);
        
        while(edges--){
            cin >> from >> to >> weight;
            AL[from].push_back(make_pair(to,weight));
        }
        
        //dikjstra
        while(queries--){
            cin >> dest;
            dikjstra(start);
            result = dist[dest];
            if(result == 1e9) cout << "impossible\n";
            else cout << result << '\n';
        }
        
        cout << '\n';
    }
}