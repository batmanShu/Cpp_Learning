struct minheap{
    vector<int> data;
    int cur=0;

    minheap(int n){
        data.resize(n+1);
        data[0]=INT_MIN;
    }

    bool empty(){
        return cur==0;
    }

    void put(int x){
        cur++;
        data[cur]=x;
        int i=cur;
        while(data[i]<data[i/2])
        {
            swap(data[i],data[i/2]);
            i=i/2;
        }
    }

    int top(){
        return data[1];
    }

    int size(){
        return cur;
    }

    void pop(){
        data[1]=data[cur];
        int i=1;
        while(2*i+1<cur&&data[i]>min(data[2*i],data[2*i+1]))
        {
            if(data[2*i]<data[2*i+1])
            {
                swap(data[i],data[2*i]);
                i=2*i;
            }
            else
            {
                swap(data[i],data[2*i+1]);
                i=2*i+1;
            }
        }
        cur--;
    }

    void print(){
        for(int i=1;i<=cur;i++)
            cout<<data[i]<<" ";
    }
};
