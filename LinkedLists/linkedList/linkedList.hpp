#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__
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
    ll_int() {  //   O(1)
        this->head = 0;
        this->tail = 0;
        size_  = 0;
    }
    ~ll_int(){    //    O(N)
        ll_int_node *current, *to_remove;
        current = this->head;
        while (current!=0){
            to_remove = current;
            current = current->next;
            delete to_remove;
        }
    } 
    void push_front(int value) {  //     O(1)
        ll_int_node* new_node = new ll_int_node;
        new_node->value = value;
        new_node->next = this->head;
        if (this->head == 0)
            this->tail = new_node;
        this->head = new_node;
        size_++;
    }

    void push_back(int value){  //     O(1)
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

    void pop_front(){  // O(1)
        if (this->head == 0)
            return;
        ll_int_node *to_remove = this->head;
        if (this->tail==this->head)
            this->tail = 0;
        this->head = this->head->next;
        delete to_remove;
        size_--;
    }

    void pop_back(){  // O(n)
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

    int front(){ // O(1)
        if (this->head != 0)
            return this->head->value;
        else
            return -1;
    }
    int back(){ // O(1)
        if (this->tail != 0)
            return this->tail->value;
        else
            return -1;
    }

    void insert_at(int index, int value){ //     O(N)
        ll_int_node* new_node = new ll_int_node;
        new_node->value = value;

        ll_int_node *current = this->head;
        ll_int_node *before;
        if(index == 0){
            this->head = new_node;
            new_node->next = current;
        }else if(index == size_ ){
            for(int i = 0; i < size_-1; i++){
                current = current->next;
            }
            this->tail = new_node;
            new_node->next = 0;
            current->next = new_node;
        }else{
            for(int i = 0; i< index; i++){
                before = current;
                current = current->next;
            }
            before->next = new_node;
            new_node->next = current;
        }
        size_++;
    } 

    int get_at(int index){ //    O(N)
        ll_int_node *current = this->head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->value;
    } 

    void remove_at(int index){  //     O(N-2)
        ll_int_node *current = this->head;
        ll_int_node *before;
        if (this->head == 0)
            return;
        if(index == 0){
            this->head = current->next;
            delete current;
        }else if(index == size_ ){
            for(int i = 0; i < size_- 2; i++){
                before = current;
                current = current->next;
            }
            this->tail = before;
            delete current;
        }else{
            for(int i = 0; i< index; i++){
                before = current;
                current = current->next;
            }
            before->next = current->next;
            delete current;
        }
        size_--;
    }

    unsigned int size() { //   O(1)
        return size_; 
    } 

    int count(int value){ // O(N)
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

    int sum(){ // O(N)
        ll_int_node *current = this->head;
        int sum = current->value;
        for (int i = 0; i < size_-1; i++)
        {
            current = current->next;
            sum += current->value;
        }
        return sum;
    } 

    int max(){ // O(N)
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

    int min(){     //   O(N)
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

    bool repeated(){ //   O(nlogn)
        if (size_== 0){
            return false;
        }
        
        ll_int_node *current = this->head;
        ll_int_node *temp;
        for (int i = 0; i < size_-1; i++){
            temp = current->next;
            for (int j = i+1; j < size_; j++) {
                if (current->value - temp->value == 0){
                    return true;
                }
                temp = temp->next;
            }
            current = current->next;
        }
        return false;
    }

    void bigDifference(){ // O(N)
        int diff = 0, index = 0;
        ll_int_node *current = this->head;
        for (int i = 0; i < size_-1; i++){
            if (current->value - current->next->value < 0 )
            {
                if ((current->value - current->next->value) * -1 > diff)
                {
                    diff = (current->value - current->next->value) * -1;
                    index = i;
                    std::cout << "atualizou " << index << " " << diff << std::endl ;
                }
                
            }else{
                if (current->value - current->next->value > diff)
                {
                    diff = current->value - current->next->value;
                    index = i;
                    std::cout << "atualizou " << index << " " << diff << std::endl ;
                }
                
            }
            current = current->next;
        }
        std::cout << "Index: " << index << " Diff: " << diff << std::endl;
    }

};

#endif // __LINKED_LIST_IFRN__