class DisjSet
{
    public:
        DisjSet(int maxsize):parents(vector<int>(maxsize)),ranks(vector<int>(maxsize,0)){
            for(int i=0;i<maxsize;i++)
            {
                parents[i]=i;
            }
        }

        int find(int x){
            return parents[x]==x ? x:(parents[x]=find(parents[x]));
        }

        void to_union(int x, int y){
            int p1=find(x);
            int p2=find(y);
            if(ranks[p1]>ranks[p2])
                parents[p2]=p1;
            else
            {
                parents[p1]=p2;
                if(ranks[p1]==ranks[p2])
                    ++ranks[p2];
            }
            parents[find(x)]=find(y);
        }

        bool is_same(int x,int y){
            return find(x)==find(y);
        }
    private:
        vector<int> parents;
        vector<int> ranks;
};
