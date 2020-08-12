template <typename T>
class SharedPtr{
public:
    SharedPtr(T* raw_ptr){
        ptr=raw_ptr;
        cnt=new int(1);
    }

    SharedPtr(const SharedPtr<T>& p){
        ptr=p.ptr;
        cnt=p.cnt;
        ++(*cnt);
    }

    SharedPtr<T>& operator =(const SharedPtr<T>& p){
        if(&p==this)
            return *this;
        ptr=p.ptr;
        cnt=p.cnt;
        ++(*cnt);
        return *this;
    }

    ~SharedPtr(){
        --(*cnt);
        cout<<*cnt<<endl;
        if(*cnt==0)
            delete ptr;
        ptr=nullptr;
        cnt=nullptr;
    }

    T& operator * (){
        return *ptr;
    }

    T* operator -> (){
        return ptr;
    }

private:
    int* cnt;
    T* ptr;
};
