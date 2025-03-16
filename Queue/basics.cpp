// A Queue is a linear data structure that follows the First-In, First-Out (FIFO) principle, meaning the first element added to the queue will be the first one to be removed.
// A Queue in real life can be visualized as a line of people waiting for their turn, such as at a ticket counter, grocery checkout, or for boarding a bus. This scenario directly follows the First-In, First-Out (FIFO) principle: the first person to join the queue is the first person to be served, while others have to wait their turn.
// A Queue has two ends :- 
// Front :- The end from which elements are removed.
// Rear :- The end from which elements are added. 

// Intitially, the Queue is empty. It looks something like :- Front ----- Rear
// After adding Element1, the queue looks like this :- Front ----- Element1 ----- Rear
// Now we add Element2. The queue grows, and the rear moves back :- Front ----- Element1 ----- Element2 ----- Rear
// Adding Element3 extends the queue further :- Front ----- Element1 ----- Element2 ----- Element3 ----- Rear
// After removing the front element (Element1), the front moves to the next element :- Front ----- Element2 ----- Element3 ----- Rear
// We add Element4, and the rear moves again :- Front ----- Element2 ----- Element3 ----- Element4 ----- Rear

// Operations that can be performed on Queue :-
// 1. Enqueue
// Add an element to the rear of the queue.
// Example: If the queue is [1, 2], after enqueuing 3, it becomes [1, 2, 3]

// 2. Dequeue
// Removes the element from the front (beginning) of the queue. The element that is removed is returned or used.
// Example: If the queue is [1, 2, 3], after dequeuing, it becomes [2, 3], and 1 is the dequeued element.

// 3. Peek Front
// Returns the element at the front of the queue without removing it.
// Example: If the queue is [1, 2, 3], peeking the front will return 1, and the queue remains [1, 2, 3]

// 4. Peek Rear
// Returns the element at the rear of the queue without removing it.
// Example: If the queue is [1, 2, 3], peeking the rear will return 3, and the queue remains [1, 2, 3]

// 5. isEmpty
// Checks whether the queue is empty. Returns true if the queue is empty, otherwise false.
// Example: If the queue is [], isEmpty will return true. If the queue is [1, 2, 3], isEmpty will return false.

// 6. Size
// Returns the number of elements currently in the queue.
// Example: If the queue is [1, 2, 3], size will return 3.

// 7. isFull
// Checks whether the queue is full. Returns true if the queue has reached its maximum capacity, otherwise false. This is usually relevant for queues implemented with a fixed size (like an array-based queue or circular queue).
// Example: If the queue has a maximum capacity of 3 and currently holds [1, 2, 3], isFull will return true. If the queue has [1, 2], isFull will return false.