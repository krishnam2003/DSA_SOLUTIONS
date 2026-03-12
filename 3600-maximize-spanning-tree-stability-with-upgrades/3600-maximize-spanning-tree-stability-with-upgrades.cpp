class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    
    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }
    
    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        
        if(rank[a]<rank[b]) swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b]) rank[a]++;
        return true;
    }
};

class Solution {
public:

    bool can(int n, vector<vector<int>>& edges, int k, int mid){
        DSU dsu(n);
        int used = 0;
        int upgrades = 0;
        
        vector<pair<int,int>> needUpgrade;
        
        for(auto &e:edges){
            int u=e[0], v=e[1], s=e[2], must=e[3];
            
            if(must==1){
                if(s < mid) return false;
                if(!dsu.unite(u,v)) return false;
                used++;
            }
        }
        
        for(auto &e:edges){
            int u=e[0], v=e[1], s=e[2], must=e[3];
            if(must) continue;
            
            if(s>=mid){
                if(dsu.unite(u,v))
                    used++;
            }
            else if(2*s>=mid){
                needUpgrade.push_back({u,v});
            }
        }
        
        for(auto &p:needUpgrade){
            if(upgrades>=k) break;
            if(dsu.unite(p.first,p.second)){
                upgrades++;
                used++;
            }
        }
        
        return used==n-1;
    }
    
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        
        int low=0, high=200000;
        int ans=-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(can(n,edges,k,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        
        return ans;
    }
};