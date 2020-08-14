template <typename T>
class UniquePtr{
public:
    UniquePtr()=default;

    explicit UniquePtr(T* raw_ptr){
        ptr=raw_ptr;
    }

    UniquePtr(UniquePtr&& p){
        if(ptr!=p.ptr)
        {
            ptr=p.ptr;
            p.ptr=nullptr;
        }
        return *this;
    }

    UniquePtr(const UniquePtr& p)=delete;

    UniquePtr& operator = (const UniquePtr& p)=delete;

    UniquePtr& operator = (UniquePtr&& p){
        if(ptr!=p.ptr)
        {
            ptr=p.ptr;
            p.ptr=nullptr;
        }
        return *this;
    }

    T& operator * () {
        return *ptr;
    }

    T* operator -> () {
        return ptr;
    }

    ~UniquePtr(){
        delete ptr;
        ptr=nullptr;
    }

private:
    T* ptr;
};
