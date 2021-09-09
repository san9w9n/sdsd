#include <bits/stdc++.h>
using namespace std;
int X;
int dist[2000002];
int pre[2000002];

int bfs() {
    int x, r;
    queue<int> Q;
    if(X==1) return 0;
    Q.push(X);
    dist[X] = 1;
    
    while(!Q.empty()) {
        x = Q.front(); Q.pop();
        if(x%3==0) {
            r = x/3;
            if(r>0 && dist[r]==0) { 
                pre[r] = x;
                if(r==1) return dist[x];
                dist[r] = dist[x] + 1;
                Q.push(r);
            }
        }
        if(x%2==0) {
            r = x/2;
            if(r>0 && dist[r]==0) {
                pre[r] = x;
                if(r==1) return dist[x];
                dist[r] = dist[x] + 1;
                Q.push(r);
            }
        }
        r = x-1;
        if(r>0 && dist[r]==0) {
            pre[r] = x;
            if(r==1) return dist[x];
            dist[r] = dist[x] + 1;
            Q.push(r);
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> X;
    if(X==1) {
        cout << 0 << '\n' << 1;
        return 0;
    }
    cout << bfs() <<'\n';

    vector<int> path;
    path.push_back(1);
    int n=pre[1];
    while(1) {
        if(n==X) break;
        path.push_back(n);
        n=pre[n];
    }
    path.push_back(X);
    for(int i=path.size()-1; i>=0; i--) cout << path[i] << ' ';
    return 0;
}