#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size=0;
    for (int i=0;i<MAX_TASKS;i++){
        tasks[i]=nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for (int i=0;i<MAX_TASKS;i++){
        delete[] tasks[i];
        tasks[i]=nullptr;
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int len=0;
    int i=0;
    while (str[i]!='\0'){
        len++;
        i++;
    }
    return len;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int len=string_length(src);
    for (int i=0;i<len;i++){
        dest[i]=src[i];
    }
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if (size==MAX_TASKS){
        throw std::out_of_range("Out of Range");
    }
    int len=string_length(task);
    tasks[size]=new char[len+1];
    for (int i=0;i<=len;i++){ //i<=len for '\0'
        tasks[size][i]=task[i];
    }
    size++;
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if (index<0||index>=MAX_TASKS){
        throw std::out_of_range("Out of Range");
    }
    delete[] tasks[index];
    for (int i=index;i<size-1;i++){
        tasks[i]=tasks[i+1];
    }

    tasks[size-1]=nullptr;
    size--;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count=size;
    return (const char**) tasks;
}