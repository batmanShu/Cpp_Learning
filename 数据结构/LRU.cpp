struct ListNode{
    int key;
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int _k,int _v):key(_k),val(_v){
        prev=nullptr;
        next=nullptr;
    }
};


class LRU{
    private:
        unordered_map<int,ListNode*> mp;
        ListNode* head;
        ListNode* tail;
        int cap;
    public:
        LRU(int c){
            head=new node(-1,-1);
            tail=new node(-2,-2);
            head->next=tail;
            tail->prev=head;
            mp.clear();
            cap=c;
        }

        void deletenode(int key){
            if(!mp.find(key)==mp.end())
                return;
            ListNode* node=mp[key];
            ListNode* prevnode=node->prev;
            ListNode* nextnode=node->next;
            prevnode->next=nextnode;
            nextnode->prev=prevnode;
            free(node);
            node=nullptr;
        }

        void put(int key,int val){
            if(mp.find(key)!=mp.end())
            {
                deletenode(key);
                put(key,val);
            }
            else
            {
                if(mp.size()>=cap)
                {
                    ListNode* node=new ListNode(key,val);
                    int last_k=tail->prev->key;
                    deletenode(last_k);
                    mp.erase(last_k);
                }
                ListNode* node=new ListNode(key,val);
                ListNode* nextnode=head->next;
                head->next=node;
                node->next=nextnode;
                node->prev=head;
                nextnode->prev=node;
                mp[key]=node;
            }
        }

        int get(int key){
            if(!mp.find(key)==mp.end())
                return;
            int v=mp[key]->val;
            deletenode(key);
            put(key,v);
            return v;
        }
};