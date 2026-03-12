## Purpose: 
The purpose of this Activity Log is to manage a sequence of lab samples. It ensures that samples are processed in the exact order they were received (FIFO), preventing older samples from being overlooked.

## Logical Data Model:
1. Sample ID: A unique number (like 1001).
2. Specimen Type: What is in the tube? (e.g., Blood, Saliva, DNA).
3. Test Requested: What are we doing? (e.g., PCR, Sequencing)

## Defining the "Contract"
Required Operation      ThemeName       What it does
add(activity)        receiveSample     Places a new sample at end of line.
remove()             processSample     Takes the oldest sample out of the log to be tested. 
peek()               nextInLine        Looks at the oldest sample without removing. 
isEmpty()            isLogEmpty        Returns true if there are zero samples left.
size()               sampleCount       Returns the total number of samples waiting.

## Behavioral Guarantees:
If a technician tries to processSample() or nextInline() 
The operation should return an empty Activity record and the user will be encouraged to check isLogEmpty() first.

The Guarantee: Because the user can only add to the back and only remove from the front, there is no physical way for a user to "reach into the middle" and pull out a sample. This ensures the integrity of the FIFO process.
