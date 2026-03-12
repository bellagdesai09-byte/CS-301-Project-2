#include "ActivityLog.h"

ActivityLogArray::ActivityLogArray() {
    front = 0;
    back = 0;
    count = 0;
}
void ActivityLogArray::receiveSample(Activity s) {
    if (count < MAX_SIZE) {
        samples[back] = s;
        back = (back+1) % MAX_SIZE;
        count++;
    }
}
Activity ActivityLogArray::processSample(){
    if (isLogEmpty()) {
        return Activity();
    }
    Activity processed = samples[front];
    front = (front + 1) % MAX_SIZE;
    count--;

    return processed;
}
bool ActivityLogArray::isLogEmpty(){
    return count ==0;
}
int ActivityLogArray::sampleCount() {
    return count;
}
Activity ActivityLogArray::nextInLine(){
    if (isLogEmpty()) {
        return Activity ();
    }
    return samples[front];
}
