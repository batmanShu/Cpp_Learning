//懒汉模式
class Singleton{
    private:
        Singleton(){}
        Singleton(Singleton const& s);
        Singleton& operator=(Singleton const& s);
        static Singleton* instance_ptr;
        static mutex m_mtx;
    public:
        static Singleton* getinstance(){
            m_mtx.lock();
            if(instance_ptr==nullptr)
                instance_ptr=new Singleton();
            m_mtx.unlock();
            return instance_ptr;
        }
};

//饿汉模式
class Singleton{
    private:
        Singleton(){}
        Singleton(Singleton const& s);
        Singleton& operator=(Singleton const& s);
        static Singleton instance;
    public:
        static Singleton* getinstance(){
            return &instance;
        }
};
Singleton Singleton::instance;