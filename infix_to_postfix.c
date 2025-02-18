#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct stack {
    char data[MAX];
    int top;
};

// Push function
void push(struct stack *st, char d) {
    if (st->top == MAX - 1) {
        printf("\nStack Overflows..");
    } else {
        st->top++;
        st->data[st->top] = d;
    }
}

// Pop function
char pop(struct stack *st) {
    if (st->top == -1) {
        return -1; // or handle error appropriately
    } else {
        return st->data[st->top--];
    }
}

// Define precedence
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '$':
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Convert infix to postfix
char *convert(char *expr) {
    int i, j;
    char sym, el;
    struct stack s;
    char *pexpr;

    s.top = -1;

    // Allocate memory for postfix expression
    pexpr = (char *)malloc(strlen(expr) + 1); // Allocate enough memory
    if (pexpr == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }

    for (i = 0, j = 0; expr[i] != '\0'; i++) {
        sym = expr[i];
        switch (sym) {
            case '(':
                push(&s, sym);
                break;
            case ')':
                while (s.top != -1 && (el = pop(&s)) != '(')
                    pexpr[j++] = el;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '$':
            case '^':
                while (s.top != -1 && precedence(s.data[s.top]) >= precedence(sym))
                    pexpr[j++] = pop(&s);
                push(&s, sym);
                break;
            default:
                pexpr[j++] = sym;
                break;
        }
    }
    while (s.top != -1)
        pexpr[j++] = pop(&s);
    pexpr[j] = '\0'; // Null-terminate the postfix expression

    return pexpr;
}

int main() {
    char infix[MAX], *postfix;

    printf("Enter the Infix Expression: ");
    scanf("%s", infix); // Read the infix expression

    postfix = convert(infix);

    printf("\nPostfix Expression is: %s\n", postfix);

    // Free allocated memory
    free(postfix);

    return 0;
}
