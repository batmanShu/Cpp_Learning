template <typename T1, typename T2>
class hashmap{
    private:
        struct Node{
            T1 key;
            T2 val;
            Node* next;
            Node(T1 _key,T2 _val):key(_key),val(_val){
                next=nullptr;
            }
        };
        int bucket_size;
        int _size;
        int max_size;
        vector<Node*> container;
        T2 val_null;

    public:
        hashmap(int n,int N):bucket_size(n),max_size(N){
            container.resize(n);
            _size=0;
        }

        void insert(T1 key,T2 val){
            int hashval=hash(key);
            Node* curnode=container[hashval];
            while(curnode&&curnode->key!=key)
            {
                curnode=curnode->next;
            }
            if(!curnode)
            {
                Node* node=new Node(key,val);
                node->next=container[hashval];
                container[hashval]=node;
                _size++;
                if(_size>max_size*0.75)
                    rehash();
            }
            else
            {
                curnode->val=val;
            }
            
        }

        T2& find(const T1& key){
            int hashval=hash(key);
            Node* curnode=container[hashval];
            while(curnode&&curnode->key!=key)
            {
                curnode=curnode->next;
            }
            if(!curnode)
                return val_null;
            return curnode->val;
        }

        T2& operator[](const T1& key){
            int hashval=hash(key);
            Node* curnode=container[hashval];
            while(curnode&&curnode->key!=key)
            {
                curnode=curnode->next;
            }
            if(!curnode)
                return val_null;
            return curnode->val;
        }

        void erase(T1 key){
            int hashval=hash(key);
            Node* prevnode=nullptr;
            Node* curnode=container[hashval];
            while(curnode&&curnode->key!=key)
            {
                prevnode=curnode;
                curnode=curnode->next;
            }
            //没找到对应的key，直接退出
            if(!curnode)
                return;
            //找到了，进入删除操作
            if(!prevnode)
            {
                container[hashval]=curnode->next;
                curnode=nullptr;
            }
            else
            {
                prevnode=curnode->next;
                curnode=nullptr;
            }
            _size--;
        }

        int hash(T1 key){
            int k=(int)key;
            return k%bucket_size;
        }

        int size(){
            return _size;
        }

        void rehash(){
            vector<Node*> Oldcontainer=container;
            container.resize(2*bucket_size);
            bucket_size=2*bucket_size;
            max_size=2*max_size;
            for(int i=0;i<container.size();i++)
                container[i]=nullptr;
            _size=0;
            for(int i=0;i<Oldcontainer.size();i++)
            {
                Node* curnode=Oldcontainer[i];
                while(curnode)
                {
                    insert(curnode->key,curnode->val);
                    curnode=curnode->next;
                }
            }
        }
};