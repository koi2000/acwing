//
// Created by DELL on 2023/5/28.
//
#include "bits/stdc++.h"
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 1e6+10;

struct edge{
    int u,v,w,nxt;
};
edge edges[4*N];
int head[N];
int vis[N];
int cnt[N];
int dis[N];
int tot = 0;
void init(){
    memset(head,-1,sizeof head);
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
}

void addEdge(int u,int v,int w){
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt= head[u];
    head[u] = tot++;
}

void dij(int u){
    priority_queue<pii>q;
    q.push({0,u});
    while (q.empty()){

    }
}

int main(){


    return 0;
}