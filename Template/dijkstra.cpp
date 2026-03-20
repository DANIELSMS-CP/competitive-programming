priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int start=0;
vector<int> dist(n+1,inf);
dist[start]=0;
pq.push({0,start});
while(not pq.empty())
{
    auto topz=pq.top();
    pq.pop();
    int node=topz.second,weight=topz.first;
    if(dist[node]<weight)
    {
        continue;
    }
    for(auto i:adjlist[node])
    {
        int new_dist=dist[node]+weight;
        if(new_dist<dist[i.second]) // assume i.second is node in the adjlist
        {
            dist[i.second]=new_dist;
            pq.push({dist[i.second],i.second});
        } 
    }
}