#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Dinh nghia ngan xep
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// Khoi tao ngan xep
void initializeStack(Stack *stack) {
    stack->top = -1;
}

// Kiem tra ngan xep rong
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Them phan tu vao ngan xep
void push(Stack *stack, char value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    }
}

// Lay phan tu khoi ngan xep
char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

int isValidExpression(const char *expression) {
    Stack stack;
    initializeStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                return 0; 
            }

            char topChar = pop(&stack);
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return 0; 
            }
        }
    }
    return isEmpty(&stack);
}

int main() {
    char expression[MAX_SIZE];
    printf("Nhap bieu thuc can kiem tra: ");
    fgets(expression, MAX_SIZE, stdin);
    expression[strcspn(expression, "\n")] = '\0'; 
    if (isValidExpression(expression)) {
        printf("Hop le\n");
    } else {
        printf("Khong hop le\n");
    }

    return 0;
}

