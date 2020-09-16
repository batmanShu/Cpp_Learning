template <typename T>
struct circularQueue{
    T* base;
    int front;
    int rear;
    int maxsize;
    circularQueue(int n):maxsize(n+1){
        base=(T*)malloc((maxsize)*sizeof(T));
        if(!base)
            exit(0);
        front=0;
        rear=0;
    }
 
    void push(T element){
        if(front==(rear+1)%maxsize)
            return;
        base[rear]=element;
        rear=(rear+1)%maxsize;
    }

    void pop(){
        if(front==rear)
            return;
        front=(front+1)%maxsize;
    }
};
