### **Recursion**

**Pseudocode** is a high-level description of a problem or algorithm in a more humanly readable code-like format. 

**Recursion** is where a function calls itself. There's often no performance improvement, but it can allow a solution to be clearer.

In order to avoid an infinite loop, there must be something that tells the function to stop. That is why every recursive function must have two parts: 
* **Recursive case:** where the function calls itself
* **Base case:** where the function doesn't call itself again - so it comes to a stop.

### **The Call Stack**

A **stack** is a data structure that stores multiple items, but only allows two operations:
- **Push:** Add an element to the top of the stack
- **Pop:** Remove (and return) the element from the top of the stack

Stacks follow the **LIFO** principle: _Last In, First Out_.

Computers use stacks internally through something called the **call stack**.  
When one function calls another, the calling function is **paused** in a partially completed state.  
All of its variables and the point of execution are **saved on the call stack** until the called function finishes.

This is convenient because it allows programs to remember where they left off. However, it can also lead to problems — for example, **stack overflow** — if too many function calls are stored at once.

To avoid this, recursive code can often be rewritten:
- As an **iterative** version using loops
- Or using **tail recursion**, where the recursive call is the last operation in the function

### **Tail Recursion**

In tail recursion, the function’s recursive call is the final action before returning — meaning there’s no pending computation after it.
This allows the interpreter (in languages that support it) to reuse the same stack frame for each call instead of adding new ones, reducing space complexity to O(1).

For example, a regular recursive factorial must “wait” to multiply after returning:

`return n * factorial(n - 1)`

requiring it to keep track of the state of the function even after calling it.

Whereas a tail-recursive version passes the result forward directly:

`return factorial(n - 1, acc * n)`

### **Exercises**
**3.1** - Greet2 has a variable *name* with value *"Maggie"*, and it is called from Greet, which also has a variable *name = "Maggie"*. 

**3.2** - On an infinite recursion, the program will keep adding to the call stack until it runs out of the maximum allocated memory and throw an error.


