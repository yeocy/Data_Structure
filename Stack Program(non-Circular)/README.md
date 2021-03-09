Implement a Stack Program for a (non-Circular) Integer Stack of size 10

# 4 functions, using an array of size 10
- push (int)
- int pop()
- int stack_full()
- int stack_empty()

# Test the Stack Program 
  Write the main function to exercise the 4 function

# Do not use pointers to call functions

# (for testing) Use scanf, printf only in "main"

# Use defensive coding
-push
      call stack_full before "push"
-pop
      call stack_empty before "pop"

#push
  - description: appends data to the stack
  - input: data to append (the stack is a global structure)
  - output: none
  
#pop
  - description: removes data from the stack
  - input: none
  - output: data on top of the stack

References
Data Structure Lecture(Software Department) in Gachon University
