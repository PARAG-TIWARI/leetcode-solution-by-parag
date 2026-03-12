class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
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

    bool can(int n, vector<vector<int>>& edges, int k, long long mid){

        DSU dsu(n);

        int used=0;

        // mandatory edges
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must==1){
                if(s<mid) return false;

                if(!dsu.unite(u,v)) return false;

                used++;
            }
        }

        // optional edges without upgrade
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must==0 && s>=mid){
                if(dsu.unite(u,v)) used++;
            }
        }

        // optional edges with upgrade
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must==0 && s<mid && 2LL*s>=mid && k>0){
                if(dsu.unite(u,v)){
                    used++;
                    k--;
                }
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        long long l=1,r=2e5,ans=-1;

        while(l<=r){

            long long mid=(l+r)/2;

            if(can(n,edges,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        return ans;
    }
};