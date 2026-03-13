using namespace std;

#ifndef ACTIVITY_LOG_H
#define ACTIVITY_LOG_H

#include <string>

struct Activity {
    int sampleID;
    string specimenType;
    string testRequested;
    
    Activity(int id= -1, string type = "NONE", string test = "NONE"){
        sampleID = id;
        specimenType= type;
        testRequested = test;
    }
};
    class ActivityLogArray{
    private:
    static const int MAX_SIZE = 100;
    Activity samples[MAX_SIZE];
    int front;
    int back;
    int count;

    public:
    ActivityLogArray();
    void receiveSample(Activity s);
    Activity processSample();
    Activity nextInLine();
    bool isLogEmpty();
    int sampleCount();
    };
struct Node {
    Activity data;
    Node* next;
};
class ActivityLogLinked {
private:
Node* frontPtr;
Node* backPtr;
int count;

public:
ActivityLogLinked();
~ActivityLogLinked();
void receiveSample(Activity s);
Activity processSample();
Activity nextInLine();
bool isLogEmpty();
int sampleCount();
};
#endif

