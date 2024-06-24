#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Evaluate a mathematical expression and return the result
double evaluate_expression(const char* expression) {
    // TODO: Implement a more advanced expression evaluator
    return strtod(expression, NULL);
}

// Solve a linear equation of the form "ax + b = 0"
void solve_linear_equation(double a, double b) {
    if (a == 0) {
        if (b == 0) {
            printf("方程式はすべてのxに対して真です。\n");
        } else {
            printf("方程式は解を持ちません。\n");
        }
    } else {
        double x = -b / a;
        printf("方程式の解は x = %f です。\n", x);
    }
}

// Solve a quadratic equation of the form "ax^2 + bx + c = 0"
void solve_quadratic_equation(double a, double b, double c) {
    if (a == 0) {
        solve_linear_equation(b, c);
        return;
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        printf("方程式は実数解を持ちません。\n");
    } else if (discriminant == 0) {
        double x = -b / (2 * a);
        printf("方程式の重解は x = %f です。\n", x);
    } else {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("方程式の解は x1 = %f, x2 = %f です。\n", x1, x2);
    }
}

// Perform basic arithmetic operations (+, -, *, /)
double perform_operation(double operand1, double operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                printf("ゼロで割ることはできません。\n");
                return NAN; // NAN (Not a Number) for division by zero
            }
        default:
            printf("サポートされていない演算子です。\n");
            return NAN; // NAN for unsupported operations
    }
}

// Parse and solve the equation based on its form
void parse_and_solve_equation(const char* equation) {
    // Trim leading and trailing spaces
    char trimmed_equation[256];
    sscanf(equation, "%255[^\n]", trimmed_equation);

    // Check for arithmetic operation (+, -, *, /)
    double operand1, operand2;
    char operator;
    if (sscanf(trimmed_equation, "%lf %c %lf", &operand1, &operator, &operand2) == 3) {
        double result = perform_operation(operand1, operand2, operator);
        if (!isnan(result)) {
            printf("計算結果は %f です。\n", result);
        }
        return;
    }

    // Check for linear equation "ax + b = 0"
    double a, b;
    if (sscanf(trimmed_equation, "%lfx + %lf", &a, &b) == 2) {
        solve_linear_equation(a, b);
        return;
    }

    // Check for quadratic equation "ax^2 + bx + c = 0"
    double c;
    if (sscanf(trimmed_equation, "%lfx^2 + %lfx + %lf", &a, &b, &c) == 3) {
        solve_quadratic_equation(a, b, c);
        return;
    }

    // If no valid format is recognized
    printf("サポートされていない方程式形式です。\n");
}
