## Design Decisions

1. Ordering Policy 
For this Activity Log, a FIFO policy was selected. In clinical microbiology and biotechnology settings, samples must be processed in the order they are received to ensure patient results are delivered within medical windows. A LIFO approach would be unethical as the oldest samples, which could be potentially the most urgent, would be buried under new arrivals.

2. Representation Comparison
This project implements the ADT using both a Circular Array and a Singly Linked List

* Array-Based:
    * Pros: Extremely fast access times and zero overhead for pointers.
    * Cons: Fixed capacity. The lab is limited to 100 samples (MAX_SIZE). If the lab exceeds this, new samples are to be rejected.

* Linked-Based:
    * Pros: Dynamic scaling. The log can grow as long as system memory allows, which is perfect for high-volume lab days. 

    * Cons: Higher memory usage per sample due to the storage of "next" pointers, and slightly more complexity in managing manual memory allocation/deallocation. 

3. Enforcement of Invariants
To ensure the ADT remains stable, the following invariants are enforced across both implementations:

* Size Tracking: A count variable is updated during every receive and process operation. This ensure sampleCount() is an O(1) operation rather than O(n).

* Ordering: In the array version, the front and back are managed by the modulo operator so nothing can "creep" out of bounds. In the linked version, the backPtr is strictly updated only during additions to maintain the chain. //https://www.geeksforgeeks.org/cpp/modulo-operator-in-c-cpp-with-examples/

* Empty Handling: Both implementations return a specialized Activity record with a sampleID of -1 when a process is attempted on an empty log, this prevents program crashes.

4. Tradeoffs

* Clarity vs. Complexity: The Array implementation is easier read and debug. The Linked implementation requires careful use of the "Rule of Three" (especially the destructor) in order to prevent memory leaks.

* Structural Implications: The Array version uses a pre-allocated block of memory, which is safer in embedded lab equipment, whereas the Linked version is better suited for a desktop database application. 
