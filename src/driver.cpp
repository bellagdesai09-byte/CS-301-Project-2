#include "ActivityLog.h"
#include<iostream>
using namespace std;

int main() {
    //1. Initialize both version
    ActivityLogArray arrayLog;
    ActivityLogLinked linkedLog;
    //Test 1: Array Log (Add 5, Remove All)---
    cout << "--- LAB SYSTEM TEST STARTING ===\n" <<endl;
    cout<< "CHECKLIST: Adding 5 samples to Array Log..." <<endl;
    for(int i=1; i<=5; i++){
        arrayLog.receiveSample(Activity(100+i,"Blood","PCR"));
    }
    cout << "CHECKLIST: Removing samples (Should be IDs 101 to 105):" <<endl;
    while(!arrayLog.isLogEmpty()){
        Activity s = arrayLog.processSample();
        cout << "   Processing ID: " << s.sampleID << "| Type: " <<s.specimenType<<endl;
           
    }
    // TEST 2: Peek and Size check
    cout << "\nCHECKLIST: Verifying Linked Log Peek/Size..." <<endl;
    for(int i = 1; i<=5;i++){
    linkedLog.receiveSample(Activity(100 + i,"DNA","Sequencing"));
    }
    linkedLog.processSample();
    cout << "   Current Size:  " <<linkedLog.sampleCount()<< " (Expected: 4)" <<endl;
    cout << "   Peeking ID:  " << linkedLog.nextInLine().sampleID << "  (Expected: 102)" <<endl;
    cout<<  "   Size after Peek:  "<<linkedLog.sampleCount() << " (Still Expected: 4)" << endl;

    // --- TEST 3: Safe Empty Removal ---
    cout << "\nCHECKLIST: Removing log and testing safety..." <<endl;
    while(!linkedLog.isLogEmpty()){
            linkedLog.processSample();
    }
    Activity errorSample = linkedLog.processSample();

    if(errorSample.sampleID == -1){
        cout << "   SUCCESS: System handled emtpy removal safely." <<endl;
    }
    //---Test 4: Testing Add and Remove Operations---
cout << "\nCHECKLIST: Testing Interleaved Operations..."  << endl;
linkedLog.receiveSample(Activity(301,"QuickTest","Rapid"));
linkedLog.receiveSample(Activity(302,"QuickTest", "Rapid"));
cout << "Processing 1st: " << linkedLog.processSample().sampleID << " (Expected: 301)" << endl;
linkedLog.receiveSample(Activity(303, "QuickTest", "Rapid"));
cout << "  Next in line:  " << linkedLog.nextInLine().sampleID << " (Expected:302)" <<endl;
cout << "  Current Size:  " << linkedLog.sampleCount() << " (Expected: 2)" <<endl;
cout << "--- IDENTICAL BEHAVIOR CHECK ---" << endl;
//---Test 5: Add same sample to both---
while(!linkedLog.isLogEmpty()){
    linkedLog.processSample();
}
arrayLog.receiveSample(Activity(500, "HEK-RM-V5-tagged", "Western Blot"));
linkedLog.receiveSample(Activity(500, "HEK-RM-V5-tagged", "Western Blot"));

cout << " Array Result ID:  " << arrayLog.processSample().sampleID << endl;
cout << "Linked Result ID:  " << linkedLog.processSample().sampleID << endl;
cout << "\n--- ALL TESTS COMPLETE ---" << endl; 
return 0;
}
