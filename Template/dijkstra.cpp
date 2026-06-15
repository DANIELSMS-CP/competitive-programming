priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int start=0;
vector<int> dist(n+1,inf);
dist[start]=0;
pq.push({0,start});
while(not pq.empty())
{
    auto topz=pq.top();
    pq.pop();
    int node=topz.second,d=topz.first;
    if(dist[node]<d)
    {
        continue;
    }
    for(auto edge:adjlist[node])
    {
        int new_node = edge.first; 
        int new_dist = d+edge.second;
        if(new_dist < dist[new_node])
        {
            dist[new_node]=new_dist;
            pq.push({dist[new_node], new_node});
        } 
    }
}