#include <cstdlib>
#include <cstdio>

class Queue{

    private:
        int data[100];
        int first;
        int size;

    public:

        Queue(){

            size = 0; 

        }

        int insert(int value){

            if(size == 100) throw "Queue is full!";

            return data[size++] = value;

        }

        int remove(){

            if(size == 0) throw "Queue is empty!";

            for(int i = 0; i < size; i++){

                data[i] = data[i+1];

            }

            return data[size--];

        }

        void print(){

            printf("Queue: [");
            for(int i = 0; i < size; i++){

                printf("%d", data[i]);
                printf("%s", i == size -1 ? "]\n" : ", ");

            }

        }


        int getSize(){

            return size;

        }

};


int main(){

    Queue* q1 = new Queue;
    
    //insertion test
    q1->insert(1);
    q1->insert(2);
    q1->insert(3);
    q1->insert(4);
    q1->insert(5);
    q1->insert(6);

    //print test
    q1->print();

    //removal test
    q1->remove();

    q1->print();

    //getSize() test
    printf("Queue size: %d", q1->getSize());

    delete q1;

    return 0;

}