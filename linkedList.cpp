// - implemente os métodos definidos na classe ll_int
// - Defina o desempenho de cada método usando a notação big-Oh
// - Realize testes para cada método implementado
#include <iostream>

class ll_int {
private:
    struct ll_int_node {
        int value;
        
        struct ll_int_node* next;
    };
    int size_;
    ll_int_node *head, *tail;
public:
    ll_int() {
        this->head = 0;
        this->tail = 0;
        size_  = 0;
    }
    ~ll_int(){
        ll_int_node *current, *to_remove;
        current = this->head;
        while (current!=0){
            to_remove = current;
            current = current->next;
            delete to_remove;
        }
    }
    void push_front(int value) { 
        ll_int_node* new_node = new ll_int_node;
        new_node->value = value;
        new_node->next = this->head;
        if (this->head == 0)
            this->tail = new_node;
        this->head = new_node;
        size_++;
    }

    void push_back(int value){
        ll_int_node* new_node = new ll_int_node;
        new_node->value = value;
        new_node->next = 0;
        if (this->head==0)
            this->head=new_node;
        else
            this->tail->next=new_node;
        this->tail = new_node;
        size_++;
    }

    void pop_front(){
        if (this->head == 0)
            return;
        ll_int_node *to_remove = this->head;
        if (this->tail==this->head)
            this->tail = 0;
        this->head = this->head->next;
        delete to_remove;
        size_--;
    }

    void pop_back(){
        if (this->tail == 0)
            return;
        if (this->head == this->tail){
            delete this->head;
            this->head = 0;
            this->tail = 0;
        }
        ll_int_node *current = this->head;
        while (current->next != this->tail)
            current = current->next;
        current->next = 0;
        delete this->tail;
        this->tail = current;
        size_--;
    }

    int front(){
        if (this->head != 0)
            return this->head->value;
        else
            return -1;
    }
    int back(){
        if (this->tail != 0)
            return this->tail->value;
        else
            return -1;
    }

    void insert_at(int index, int value){ // Insere 'value' no índice 'index FALTA AJEITAR O HEAD E TAIL
        ll_int_node *current = this->head;
        ll_int_node *before;
        for(int i = 0; i < index; i++){
            before = current;
            current = current->next;
        }
        ll_int_node* new_node = new ll_int_node;
        new_node->value = value;
        new_node->next = current;
        before->next = new_node;
    } 

    int get_at(int index){ // retorna o elemento do índice 'index' TESTADO OK
        ll_int_node *current = this->head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->value;
    } 

    // void remove_at(int index){} // remove o elemento do índice index

    unsigned int size() { // retorna a quantidade de elementos da lista  TESTADO OK
        return size_; 
    } 

    int count(int value){ // conta quantas vezes 'value' ocore na lista  TESTADO OK 
        ll_int_node *current = this->head;
        int count = 0;
        for(int i = 0; i<size_ ; i++){
            if(current->value == value){
                count++;
            }
            current = current->next;
        }
        return count;
    } 

    int sum(){ // soma os elementos da lista TESTADO OK
        ll_int_node *current = this->head;
        int sum = current->value;
        for (int i = 0; i < size_-1; i++)
        {
            current = current->next;
            sum += current->value;
        }
        return sum;
    } 

    int max(){ // retorna o maior elemento da lista TESTADO OK
        ll_int_node *current = this->head;
        int max = current->value;
        for (int i = 0; i < size_-1; i++)
        {
            current = current->next;
            if( current->value > max){
                max = current->value;
            }
        }
            
        return max;
    } 

    int min(){     // retorna o menor elemento da lista TESTADO OK
        ll_int_node *current = this->head;
        int min = current->value;
        for (int i = 0; i < size_-1; i++)
        {
            current = current->next;
            if( current->value < min){
                min = current->value;
            }
        }
            
        return min;
    }

};


int main() {
    ll_int lista1;
    for (int i=1 ; i<=30; i+=3){
        lista1.push_back(i);
    }

    std::cout << lista1.sum() << std::endl;
    std::cout << "Size: " << lista1.size() << std::endl; 


    std::cout << "lista1 = { ";
    for (int i=0 ; i<10 ; ++i){
        std::cout << lista1.front() << " ";
        lista1.pop_front();
    }
    std::cout << "}" << std::endl;
    return 0;
}