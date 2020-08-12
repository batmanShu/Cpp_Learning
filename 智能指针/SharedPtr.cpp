template <typename T>
class SharedPtr{
public:
    SharedPtr(T* raw_ptr){
        ptr=raw_ptr;
        cnt=new int(1);
    }

    SharedPtr(SharedPtr& p){
        ptr=p->ptr;
        cnt=p->cnt;
        ++(*cnt);
    }

    SharedPtr<T>& operator =(SharedPtr& p){
        if(&p==this)
            return *this;
        ptr=p->ptr;
        cnt=p->cnt;
        ++(*cnt);
        return *this;
    }

    ~SharedPtr(){
        --(*cnt);
        if(*cnt==0)
            delete ptr;
        ptr=nullptr;
        cnt=nullptr;
    }

    SharedPtr<T>& operator * (){
        return *this;
    }

    SharedPtr<T>* operator -> (){
        return this;
    }

    T* get(){
        return ptr;
    }

private:
    int* cnt;
    T* ptr;
};
