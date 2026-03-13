#include "ActivityLog.h"
#include<iostream>
using namespace std;

int main() {
    //1. Initialize both version
    ActivityLogArray arrayLog;
    ActivityLogLinked linkedLog;
    cout << "--- LAB SYSTEM TEST STARTING ===\n" <<endl;
    cout<< "CHECKLIST: Adding 5 samples to Array Log..." <<endl;
    for(int i=1; i<=5; i++){
        arrayLog.receiveSample(Activity(100+i,"Blood","PCR"));
    }
    cout << "CHECKLIST: Removing samples (Should be IDs 101 to 105):";
    while(!arrayLog.isLogEmpty()){
        Activity s = arrayLog.processSample();
        cout << "   Processing ID: " << s.sampleID << "| Type: " <<s.specimenType<<endl;
        
        
    }
    // TEST 2: Peek and Size check
    cout << "\nCHECKLIST: Testing Linked Log Peek/Size..." <<endl;
    linkedLog.receiveSample(Activity(201,"DNA","Sequencing"));

    cout << "   Current Size:  " <<linkedLog.sampleCount()<< " (Expected: 1)" <<endl;
    cout << "   Peeking ID:  " << linkedLog.nextInLine().sampleID << "  (Expected: 201)" <<endl;
    cout<<  "   Size after Peek:  "<<linkedLog.sampleCount() << " (Still Expected: 1)" << endl;
    // --- TEST 3: Safe Empty Removal ---
    cout << "\nCHECKLIST: Removing from epty log..." <<endl;
    Activity emptySample = linkedLog.processSample(); //becomes empty here
    Activity errorSample = linkedLog.processSample(); //Trying to remove while empty

    if(errorSample.sampleID == -1){
        cout << "   SUCCESS: System handled emtpy removal safely." <<endl;
    }
    cout << "\n--- ALL TESTS COMPLETE ---" << endl;
    return 0;
}
