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
        vector<Node*> container;
    public:
        hashmap(int n):bucket_size(n){
            container.resize(n);
            _size=0;
        }

        void insert(T1 key,T2 val){
            int hashval=hash(key);
            Node* node=new Node(key,val);
            node->next=container[hashval];
            container[hashval]=node;
            _size++;
        }

        T2& find(const T1& key){
            int hashval=hash(key);
            Node* curnode=container[hashval];
            while(curnode->key!=key)
            {
                curnode=curnode->next;
            }
            return curnode->val;
        }

        T2& operator[](const T1& key){
            int hashval=hash(key);
            Node* curnode=container[hashval];
            while(curnode->key!=key)
            {
                curnode=curnode->next;
            }
            return curnode->val;
        }

        void erase(T1 key){
            int hashval=hash(key);
            Node* prevnode=nullptr;
            Node* curnode=container[hashval];
            while(curnode->key!=key)
            {
                prevnode=curnode;
                curnode=curnode->next;
            }
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

};
