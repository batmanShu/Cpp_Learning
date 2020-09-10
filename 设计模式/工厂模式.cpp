// 简单工厂
class Product{
    public:
        virtual ~Product(){}
        virtual void show()=0;
};

class ProductA:public Product{
    public:
        void show(){

        }
};

class ProductB:public Product{
    public:
        void show(){

        }
};

class ProductC:public Product{
    public:
        void show(){

        }
};

enum PRODUCT_TYPE
{
    A,
    B,
    C
};

class Factory{
    public:
        Product* create(PRODUCT_TYPE type){
            switch(type)
            {
                case A:
                    return new ProductA();
                    break;
                case B:
                    return new ProductB();
                    break;
                case C:
                    return new ProductC();
                    break;   
                default:
                    return nullptr;
                    break;
            }
        }
};

// 工厂方法模式
class Product{
    public:
        virtual ~Product(){}
        virtual void show()=0;
};

class ProductA:public Product{
    public:
        void show(){

        }
};

class ProductB:public Product{
    public:
        void show(){

        }
};

class ProductC:public Product{
    public:
        void show(){

        }
};

class Factory{
    public:
        virtual ~Factory(){}
        virtual Product* create()=0;
};

class FactoryA{
    public:
        Product* create(){
            return new ProductA();
        }
};

class FactoryB{
    public:
        Product* create(){
            return new ProductB();
        }
};

class FactoryC{
    public:
        Product* create(){
            return new ProductC();
        }
};

//抽象工厂模式
class Product{
    public:
        virtual ~Product(){}
        virtual void show()=0;
};

class ProductA:public Product{
    public:
        void show(){

        }
};

class ProductB:public Product{
    public:
        void show(){

        }
};

class ProductC:public Product{
    public:
        void show(){

        }
};

class newProduct{
    public:
        virtual ~newProduct(){}
        virtual void show()=0;
};

class newProductA:public newProduct{
    public:
        void show(){

        }
};

class newProductB:public newProduct{
    public:
        void show(){

        }
};

class newProductC:public newProduct{
    public:
        void show(){

        }
};

class Factory{
    public:
        virtual ~Factory(){}
        virtual Product* create()=0;
        virtual newProduct* newcreate()=0;
};

class FactoryA{
    public:
        Product* create(){
            return new ProductA();
        }
        newProduct* newcreate(){
            return new newProductA();
        }
};

class FactoryB{
    public:
        Product* create(){
            return new ProductB();
        }
        newProduct* newcreate(){
            return new newProductB();
        }
};

class FactoryC{
    public:
        Product* create(){
            return new ProductC();
        }
        newProduct* newcreate(){
            return new newProductC();
        }
};