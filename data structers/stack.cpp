#include <iostream>
#include "stack.h"

#define size_s 64

// Application specific Object type
typedef struct {
    char* name;
} Person;

// Application specific functions
char* to_string(stack::Object* object){
    Person* person = (Person*) object;
    char* output = (char*) malloc(size_s);

    snprintf(output, size_s, "%s", person->name);
    return output;
}
bool are_equal(stack::Object* object1, stack::Object* object2){
    Person* person1  = (Person*) object1;
    Person* person2  = (Person*) object2;
    return strcmp(person1->name, person2->name) == 0 ? true : false;
}
void show(stack::Stack* stack){
    if(stack->BOS == NULL){
        std::cout << "The list is empty!" << std::endl;
    } else {
        int i = 0;
        stack::Item* current = stack->BOS;
        while(i < stack->length){
            std::cout << to_string(current->reference) << ", ";
            current = current->next;
            i++;
        }
    }
}

int manu(){
    printf ("\n\n Stack of names managment\n\n");
    printf (" 0 - End the program\n");
    printf ("\n");
    printf (" 1 - Push item to the stack \n");
    printf (" 2 - Pop item from the stack\n");
    printf (" 3 - Print out the file\n");
    printf ("\n");
    printf ("What's your choice ? : ");
    int cod;
    std::cin >> cod;
    std::cout << std::endl;
    return cod;
}

int main(){
    stack::Stack* stack = new stack::Stack();
    stack->init();
    bool end = false;
    while(!end){
        switch(manu()){
            case 0:
                end = true;
                break;
            case 1:{
                try{
                    char* name = (char*) malloc(size_s);

                    std::cout << "Enter the element to be pushed : ";
                    std::cin >> name; std::cout << std::endl;
                    Person* person = new Person{name};
                    stack->push(person);
                    std::cout << "The item was pushed successfully !";
                } catch(...){
                    std::cout << "Error was detected while pushing !";
                }
                }break;
            case 2:{
                try{
                    std::cout << "The item " << to_string(stack->pop()) << " was poped successfully !";
                } catch(...){
                    std::cout << "Error was detected while poping !";
                }
                }break;
            case 3:{
                show(stack);
                }break;
            default:
                end = true;
                break;
        }
    }
}