#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

void pop_two_numbers(stack<float>& stack, float& b, float& a) {
    a = stack.top();
    stack.pop();
    b = stack.top();
    stack.pop();
}

float solve_RPN(int argc, char* argv[]) {
    if(argc == 1) {
        throw invalid_argument("You need to pass an expression.");
    }

    stack<float> stack;
    float a, b, num;
    char* ptr;

    for(int i = 1; i < argc; i++) {

        num = strtof(argv[i], &ptr);

        if(ptr == argv[i] + strlen(argv[i])) {
            stack.push(num);
        }
        else {

            string op = argv[i];

            if(op == "/") {
                pop_two_numbers(stack, b, a);
                if(a == 0)
                    throw invalid_argument("Division by zero.");
                stack.push(b / a);
            }
            else if(op == "*") {
                pop_two_numbers(stack, b, a);
                stack.push(b * a);
            }
            else if(op == "-") {
                pop_two_numbers(stack, b, a);
                stack.push(b - a);
            }
            else if(op == "+") {
                pop_two_numbers(stack, b, a);
                stack.push(b + a);
            }
            else if(op == "^") {
                pop_two_numbers(stack, b, a);
                stack.push(pow(b, a));
            }
            else if(op == "sqrt") {
                a = stack.top();
                stack.pop();
                stack.push(sqrt(a));
            }
            else
                throw invalid_argument("Invalid operator -> " + op);
        }
    }

    return stack.top();
}

int main(int argc, char* argv[]) {

    cout<<solve_RPN(argc, argv);
    
    return 0;
}