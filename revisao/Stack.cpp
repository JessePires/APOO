#include <cstdlib>
#include <cstdio>

class Stack{

    private:
        int data[100];
        int size;

    public:

        Stack(){

            size = 0; 

        }

        int insert(int value){

            if(size == 100) throw "Stack is full!";

            return data[size++] = value;

        }

        int remove(){

            if(size == 0) throw "Stack is empty!";

            return data[size--];

        }

        void print(){

            printf("base: [");
            for(int i = 0; i < size; i++){

                printf("%d", data[i]);
                printf("%s", i == size -1 ? "]top\n" : ", ");

            }

        }


        int getSize(){

            return size;

        }

};


int main(){

    Stack* s1 = new Stack;
    
    //insertion test
    s1->insert(1);
    s1->insert(2);
    s1->insert(3);
    s1->insert(4);
    s1->insert(5);
    s1->insert(6);

    //print test
    s1->print();

    //removal test
    s1->remove();

    s1->print();

    //getSize() test
    printf("Stack size: %d\n", s1->getSize());


    delete s1;
    
    return 0;

}