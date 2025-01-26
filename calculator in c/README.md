# a calculator
#### Video Demo:  <https://youtu.be/pPgfw5V4FKY>
#### Description:
this is a simple calculator that does a number of mathematic operations in the command-line.
xplanation of a Calculator Implementation
A calculator program is a fundamental utility that processes arithmetic expressions and evaluates their results. This implementation uses the Shunting-Yard algorithm to convert infix expressions (e.g., 3 + 5 * 2) into Reverse Polish Notation (RPN) (e.g., 3 5 2 * +) and then evaluates the RPN expression.

Here’s a breakdown of the design and workflow:

1. Core Concepts
Infix Expression: This is the usual way we write arithmetic, where operators are between operands (e.g., 3 + 4).
Reverse Polish Notation (RPN): This removes the need for parentheses by reordering operators and operands (e.g., 3 4 +).
Shunting-Yard Algorithm: Converts an infix expression to RPN using a stack for operators and a queue for the output.
Stack and Queue Data Structures:
Stack: Used to store operators temporarily (e.g., +, *) while processing the expression.
Queue: Used to store the final RPN tokens in the correct order for evaluation.
2. Key Components
Data Types:

Tokens: Represent either a number (operand) or an operator (+, -, etc.).
Stack: A data structure that follows the Last In, First Out (LIFO) principle, suitable for operator precedence management.
Queue: A data structure that follows the First In, First Out (FIFO) principle, used for storing RPN tokens.
Functions:

shunting_yard: Converts the infix expression into RPN.
compute_rpn: Evaluates the RPN expression to compute the final result.
Stack and Queue Operations:
stack_push, stack_pop, queue_enqueue, queue_dequeue: Perform basic operations on the stack and queue.
3. Workflow of the Calculator
Step 1: Parse Input
The user provides an infix expression (e.g., 3 + 5 * 2). The program reads the input character by character to identify numbers, operators, and parentheses.

Step 2: Convert Infix to RPN (Shunting-Yard Algorithm)
Operators and Precedence:
Operators are processed based on their precedence (e.g., * and / have higher precedence than + and -).
Parentheses are used to enforce grouping.
The algorithm uses a stack to store operators temporarily and a queue to output numbers and operators in RPN order.
For example: Input: 3 + 5 * 2

Process 3 (number): Add to the output queue.
Process + (operator): Push onto the stack.
Process 5 (number): Add to the output queue.
Process * (operator): Push onto the stack (higher precedence than +).
Process 2 (number): Add to the output queue.
At the end, pop remaining operators from the stack to the output queue.
Resulting RPN: 3 5 2 * +

Step 3: Evaluate RPN
Using a stack, the program evaluates the RPN expression.
Numbers are pushed onto the stack, and operators apply to the topmost numbers on the stack.
Example: RPN: 3 5 2 * +

Push 3 onto the stack.
Push 5 onto the stack.
Push 2 onto the stack.
Apply *: Pop 5 and 2, compute 5 * 2 = 10, and push 10 onto the stack.
Apply +: Pop 3 and 10, compute 3 + 10 = 13, and push 13 onto the stack.
Final Result: 13

Step 4: Display the Result
The computed value is printed to the user.

4. Error Handling
The program includes error checks for:

Invalid Characters: Non-numeric and non-operator inputs trigger an error.
Unbalanced Parentheses: If parentheses are mismatched, the program exits with an error.
Division by Zero: Prevents illegal operations and exits safely.
Overflow: Ensures the stack and queue never exceed their maximum size.
5. Code Organization
Header File (calculator.h):
Defines data types, constants, and function prototypes.
Source File:
Implements the stack, queue, and algorithm logic.
Main Program:
Parses input, calls shunting_yard to convert to RPN, and evaluates the result using compute_rpn.
6. Example Execution
Input: 2 + 3 * (4 ^ 2 - 6) / 2

Convert to RPN: 2 3 4 2 ^ 6 - * 2 / +
Evaluate RPN:
Push 2, 3, 4, and 2.
Apply ^: 4 ^ 2 = 16.
Push 6, apply -: 16 - 6 = 10.
Apply *: 3 * 10 = 30.
Push 2, apply /: 30 / 2 = 15.
Apply +: 2 + 15 = 17.
Output: 17

7. Key Benefits of This Approach
Flexibility: Supports multiple operators, precedence levels, and parentheses.
Scalability: Easy to extend for more complex operations (e.g., trigonometric functions).
Robustness: Handles input validation and edge cases (e.g., unbalanced parentheses, division by zero).



