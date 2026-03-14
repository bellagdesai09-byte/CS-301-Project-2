#include "ActivityLog.h"
void ActivityLogLinked::receiveSample(Activity s) {
    //1. create a new "carrier" (node)
    Node* newNode= new Node;
    newNode->data = s;
    newNode->next = nullptr;

    //2. Link it to the existing line
    if(isLogEmpty()){
        frontPtr = newNode;

    } else {
        backPtr->next = newNode;
    }
    backPtr = newNode;
    count++;
}
ActivityLogLinked::~ActivityLogLinked(){
    while(!isLogEmpty()){
        processSample();
    }
}
Activity ActivityLogLinked::processSample(){
    if(isLogEmpty()){
        return Activity();
    }
    //1. save the data we want to return
    Activity dataToReturn = frontPtr->data;
    //2. Keep a temporary pointer to the node we're removing
    Node* temp = frontPtr;
    //3. Move the front pointer forward
    frontPtr = frontPtr->next;
    //4. If the list is now empty, the back pointer should be null too
    if (frontPtr == nullptr){
        backPtr = nullptr;
    }
    delete temp;
    count--;
    
    return dataToReturn;
}
ActivityLogLinked::ActivityLogLinked(){
    frontPtr = nullptr;
    backPtr = nullptr;
    count = 0;
}
bool ActivityLogLinked::isLogEmpty(){
    return frontPtr == nullptr;
}
int ActivityLogLinked::sampleCount(){
    return count;
}
Activity ActivityLogLinked::nextInLine(){
    if(isLogEmpty()){
        return Activity();
    }
    return frontPtr->data;
}