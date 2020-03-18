#include <cstdlib>
#include <cstdio>

class List{

    private:
        
        int data[100];
        int size;

        void shiftRight(int begin){

            for(int i = size-1; i >= begin; i--){

                data[i+1] = data[i];

            }

        }

        void shiftLeft(int begin){

            for(int i = begin; i < size; i++){

                data[i] = data[i+1];

            }

        }




    public:

        List(){

            size = 0;

        }

        
        int insert(int value, int position){

            if(size == 100) throw "List is full!";

            if(size == 0 || position == size){

               return data[size++] = value;

            }

            shiftRight(position);
            data[position] = value;
            return size++;

        }


        int remove(int position){

            if(size == 0) throw "List is empty!";

            if(position == size || size == 1){

                return data[size--];

            }

            shiftLeft(position);
            return size--;

        }


        void print(){

            if(size == 0) throw "List is empty!";

            printf("List: [");
            for(int i = 0; i < size; i++){

                printf("%d", data[i]);
                printf("%s", i == size-1 ? "]\n" : ", ");

            }

        }


        int getSize(){

            return size;

        }

};


int main(){

    List* l1 = new List;

    l1->insert(1, l1->getSize());
    l1->insert(2, l1->getSize());
    l1->insert(3, l1->getSize());
    l1->insert(4, l1->getSize());
    l1->insert(7, l1->getSize());
    l1->insert(8, l1->getSize());

    l1->print();

    l1->insert(6, 4);

    l1->print();

    delete l1;

    return 0;

}