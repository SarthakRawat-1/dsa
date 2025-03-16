// A stack is a data structure that operates on a Last In, First Out (LIFO) principle. This means that the last item added to the stack is the first one to be removed.
// It is a linear data structure in which insertion and deletion only allowed at the end, called the top of stack.

// Imagine a stack of commercially available white bread. Each loaf of bread is individually wrapped and placed one on top of the other in a stack. When new loaves of bread are delivered to the store, they are placed on top of the existing stack. The most recently delivered loaf is now on the top of the stack. When a customer buys a loaf of bread, they take the top loaf. This means the loaf that was last added to the stack (most recent delivery) is the first one to be removed.

// Imagine the stack as a vertical column. Each block in the column represents an item in the stack. Items are added to the top of the stack and removed from the top.
// +---------+       <-- Top of the stack, where the last item added is located
// |   Item 4  |       <-- Most recent item added (last in)
// +---------+       <-- Removing from here (first out)
// |   Item 3  |
// +---------+
// |   Item 2  |
// +---------+
// |   Item 1  |       <-- First item added (bottom of the stack)
// +---------+

// 1. Intial State :- Empty Stack. Imagine an empty space with nothing in it. This is an empty stack. There's no "top" because there are no items in the stack.

// 2. Adding (Pushing) Items :- As you push (add) items onto the stack, they get placed on top of the previous items.
// Push Item 1
// +---------+
// |   Item 1  |      <-- First item added, currently at the top and bottom
// +---------+
// Push Item 2
// +---------+
// |   Item 2  |      <-- New top item
// +---------+
// |   Item 1  |      <-- Item 1 is now below Item 2
// +---------+
// Push Item 3
// +---------+
// |   Item 3  |      <-- New top item
// +---------+
// |   Item 2  |      <-- Item 2 is now below Item 3
// +---------+
// |   Item 1  |      <-- Item 1 is now below Item 2
// +---------+

// 3. Removing (Popping) Items :- As you pop (remove) items from the stack, they get removed from the top of the stack.
// Pop Item 3
// +---------+
// |   Item 2  |      <-- After popping, Item 2 becomes the new top item
// +---------+
// |   Item 1  |
// +---------+
// Pop Item 2
// +---------+
// |   Item 1  | <-- After popping, Item 1 is the only item left and is now the top item
// +---------+
// Pop Item 1
// (Empty)          <-- Stack is empty again after popping all items


// When we define a stack as an Abstarct data type, then we are only interested in knowing the stack operations from user POV.
// It simply means we are not interested in knowing the details, we are only interested in what type of O/P we can perform.

// Operations that can be performed on Stack :-
// 1. Push
// Adds an element to the top of the stack.
// Example: If the stack is [1, 2], after pushing 3, it becomes [1, 2, 3].

// 2. Pop
// Removes the top element from the stack. The element that is removed is returned or used.
// Example: If the stack is [1, 2, 3], after popping, it becomes [1, 2], and 3 is the popped element.

// 3. Peek/Top
// Returns the top element of the stack without removing it.
// Example: If the stack is [1, 2, 3], peeking will return 3, and the stack remains [1, 2, 3].

// 4. isEmpty
// Checks whether the stack is empty. Returns true if the stack is empty, otherwise false.
// Example: If the stack is [], isEmpty will return true. If the stack is [1, 2, 3], isEmpty will return false.

// 5. Size
// Returns the number of elements currently in the stack.
// Example: If the stack is [1, 2, 3], size will return 3.


// The reason why Stack is considered LIFO and not FILO is because when you push some elements into a Stack, and then pop them all out so it is empty again. We have already removed the First element but now if you push elements back in the stack and push them out later, the First element has already been taken out before these elements. Hence, it was not the last element to leave the data structure.
// LIFO is the standard term because it directly describes the behavior of the stack in relation to its most recent operation. The focus is on the last element added because that element's removal is immediate and relevant.

