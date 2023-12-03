#include<iostream>
using namespace std;

class circularQ
{
    private:
    int front,rear;
    int* Queue;
    int size;
    public:
    circularQ()
    {
        size = 5;
        Queue = new int[5];
        if (Queue == nullptr)
        {
            cerr << "Memory allocation failed." << endl;
            exit(EXIT_FAILURE);
        }
        front = rear =-1;
    }
    circularQ(int n)
    {
        size = n;
        Queue =new int[n];
        if (Queue == nullptr)
        {
            cerr << "Memory allocation failed." << endl;
            exit(EXIT_FAILURE);
        }
        front=rear=-1;
    }
    bool isFull()
    {
        return (rear+1)%size == front;
    }
    void enQueue(int x)
    {
        if(isFull())
        {
            cout<<"OVERFLOW"<<endl;
            return;
        }
        if(front==-1)
        {
            front = 0;
        }
        rear = (rear+1)%size;
        Queue[rear]= x;
        return;
    }
    bool isEmpty()
    {
        return front==-1 ;
    }
    int deQueue()
    {
        if(isEmpty())
        {
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }
        int temp = Queue[front];
        if(front==rear)
        {
            front =rear =-1;
        }
        else 
        {
            front = (front+1)%size;
        }
        
        return temp;
    }
    ~circularQ()
    {
        delete[] Queue;
    }

};

int main()
{
    

    // Test 3: Fill and empty the queue
    circularQ q3(4);
    q3.enQueue(10);
    q3.enQueue(20);
    q3.enQueue(30);
    q3.enQueue(40);
    cout << q3.deQueue() << " was dequeued" << endl;
    cout << q3.deQueue() << " was dequeued" << endl;
    cout << q3.deQueue() << " was dequeued" << endl;
    cout << q3.deQueue() << " was dequeued" << endl; 
    cout << q3.deQueue() << " was dequeued" << endl; 



    return 0;
}