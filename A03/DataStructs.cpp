#include <cstdio>

class Node{

    private:

        int data;
        Node* next;

    public:

        Node(){

            this->next = nullptr;

        }

        int getData(){
            return this->data;
        }

        Node* getNextNode(){
            return this->next;
        }

        void setData(int data){
            this->data = data;
        }

        void setNextNode(Node* node){
            this->next = node;
        }
};


class Collection{

    protected:

        int size;

    public:

        int getSize(){

            return this->size;

        }

};


class Queue: public Collection{

    private:

        Node* first;
        Node* last;


    public:

        Queue(){

            this->first = nullptr;
            this->last = nullptr;
            this->size = 0;

        }

        
        void insert(int data){

            Node* newNode = new Node();
            newNode->setData(data);

            if(this->size == 0){

                this->first = newNode;
                this->last = newNode;

            }else{

                Node* aux = this->last;
                this->last = newNode;
                aux->setNextNode(this->last);   

            }

            this->size++;

        }

        void remove(){

            if(this->size == 0) throw "Queue is Empty";

            Node* excluded = this->first;
            this->first = this->first->getNextNode();
            this->size--;

            delete excluded;

        }


        void print(){

            Node* aux = this->first;

            printf("Queue: [");
            while(aux != nullptr){

                printf("%d", aux->getData());
                printf("%s", aux->getNextNode() == nullptr ? "]\n" : ", ");
                aux = aux->getNextNode();

            }

        }

};


class List: public Collection{

    private:

        Node* first;
        Node* last;

        Node* getLeftNode(int position){

            Node* aux = this->first;

            for(int i = 0; i < position; i++){

                aux = aux->getNextNode();

            }

            return aux;

        }


    public:

        List(){

            this->first = nullptr;
            this->last = nullptr;

        }


        void insert(int data, int position){

            if(position > this->size + 1) throw "Invalid Position";

            Node* newNode = new Node;
            newNode->setData(data);

            if(size == 0){

                this->first = newNode;
                this->last = newNode;

            }else if(position == this->size){

                Node* aux = this->last;
                aux->setNextNode(newNode);
                this->last = newNode;
            
            }else{

                Node* leftNode = getLeftNode(position);

                Node* rightNode = leftNode->getNextNode();
                leftNode->setNextNode(newNode);
                newNode->setNextNode(rightNode);

            }

            size++;

        }


        void remove(int position){

            if(size == 0) throw "List is already empty!";

            Node* leftNode = getLeftNode(position);
            leftNode->setNextNode(leftNode->getNextNode()->getNextNode());
            size--;

        }

        
        void print(){

            Node* aux = this->first;

            printf("List: [");
            for(int i = 0; i < size; i++){

                printf("%d", aux->getData());
                printf("%s", aux->getNextNode() == nullptr ? "]\n" : ", ");
                aux = aux->getNextNode();

            }

        }
};


class Stack: public Collection{

    private:
    
        Node* top;

    public:

        Stack(){

            top = nullptr;

        }


        void push(int data){

            Node* newNode = new Node;
            newNode->setData(data);

            if(size != 0){

                newNode->setNextNode(this->top);

            }

            this->top = newNode;
            size++;

        }


        void pop(){

            if(size == 0) throw "Stack is empty!";

            this->top = this->top->getNextNode();
            size--;

        }

        
        void print(){

            Node* aux = this->top;

            printf("Stack: Top -> [");
            for(int i = 0; i < size; i++){

                printf("%d", aux->getData());
                printf("%s", i == size-1 ? "] <- base\n" : ", ");
                aux = aux->getNextNode();

            }

        }

};


int main(){

    //QUEUE TEST
    Queue* q1 = new Queue;

    q1->insert(1);
    q1->insert(2);
    q1->insert(3);
    q1->insert(4);
    q1->insert(5);

    q1->print();

    q1->remove();

    q1->print();

    printf("Queue size: %d\n\n", q1->getSize());


    //LIST TEST
    List* l1 = new List;

    l1->insert(1, l1->getSize());
    l1->insert(2, l1->getSize());
    l1->insert(3, l1->getSize());
    l1->insert(4, 1);
    l1->insert(5, 2);

    l1->print();

    l1->remove(1);
    l1->print();

    l1->remove (1);
    l1->print();

    printf("List size: %d\n\n", l1->getSize());

    //STACK TEST
    Stack* s1 = new Stack;    

    s1->push(1);
    s1->push(2);
    s1->push(3);
    s1->push(4);
    s1->push(5);

    s1->print();

    printf("Stack size: %d\n\n", s1->getSize());

    s1->pop();

    s1->print();

    printf("Stack size: %d\n\n", s1->getSize());

    return 0;

}