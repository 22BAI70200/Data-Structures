#include <iostream>
using namespace std;
#define TYPE int

struct Stack
{
    int top;
    int capacity;
    TYPE *data;
};

/// @brief This function returns a new stack.
/// @param capacity Maximum size of the stack.
/// @return stack
Stack *init(int capacity)
{
    Stack *stack = new Stack;
    stack->capacity = capacity;
    stack->data = new TYPE[capacity];
    stack->top = -1;
    return stack;
}

/// @brief Checks if stack is empty or not.
/// @param stack stack to consider.
/// @return 1 or 0
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

/// @brief Checks if stack can accomodate any more items
/// @param stack stack to consider.
/// @return 1 or 0
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

/// @brief removes the top value of the stack and updates the stack.
/// @param stack stack to consider.
/// @return popped element
TYPE pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->data[stack->top--];
    }
    return -1; // Underflow
}

/// @brief pushes a new element to stack and updates the top value.
/// @param stack stack to push value to
/// @param data value to push
void push(Stack *stack, TYPE data)
{
    if (!isFull(stack))
    {
        stack->data[++stack->top] = data;
        return;
    }
    return; // Overflow
}

/// @brief returns values at the top without removing it
/// @param stack stack to check the top of.
/// @return top element of stack.
TYPE peek(Stack *stack)
{
    return stack->data[stack->top];
}

/// @brief total elements in a stack.
/// @param stack stack to consider.
/// @return size of stack
int size(Stack *stack)
{
    return stack->top + 1;
}

/// @brief prints the elements in stack in order of popping.
/// @param stack the stack to print.
void displayStack(Stack *stack)
{
    auto temp = *stack;
    while (temp.top != -1)
    {
        cout << pop(&temp) << " ";
    }
    cout << endl;
}

/// @brief reverses the stack passed.
/// @param stack stack to reverse.
/// @return reversed stack
Stack *reverseStack(Stack *stack)
{
    auto temp = *stack, *revStack = init(stack->capacity);
    while (temp.top != -1)
    {
        push(revStack, pop(&temp));
    }
    return revStack;
}

/// @brief deletes the stack from heap.
/// @param stack stack to delete.
void deleteStack(Stack *stack)
{
    if (stack)
    {
        if (stack->data)
        {
            free(stack->data);
        }
        free(stack);
    }
}
