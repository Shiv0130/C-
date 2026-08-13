//#include <iostream>

//using namespace std;

//int main()
//{
//    cout << "Hello world!" << endl;
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    int A, B, C, D;
} Expression;

int randomInt() {
    return (rand() % 101) - 50;
}

double computeValue(Expression* expr, double x) {
    return expr->A * x * x + expr->B * sin(expr->C * x) + expr->D;
}

void computeStatistics(Expression* expr, int n, double* mean, double* stddev, double* sumPositive, double* sumNegative) {
    double sum = 0;
    double sumSquares = 0;
    *sumPositive = 0;
    *sumNegative = 0;

    for (int i = 0; i < n; i++) {
        double value = computeValue(expr + i, (double)i / (n - 1) * 20 - 10);
        sum += value;
        sumSquares += value * value;

        if (value > 0) {
            *sumPositive += value;
        } else if (value < 0) {
            *sumNegative += value;
        }
    }

    *mean = sum / n;
    *stddev = sqrt(sumSquares / n - (*mean) * (*mean));
}

void applyTransformation(Expression* expr, int n, double (*transformation)(double)) {
    for (int i = 0; i < n; i++) {
        double value = computeValue(expr + i, (double)i / (n - 1) * 20 - 10);
        double transformedValue = transformation(value);
        expr[i].D = transformedValue;
    }
}

// Function to compute the sum of all elements recursively
double recursiveSum(Expression* expr, int n) {
    if (n == 0) {
        return 0;
    } else {
        return computeValue(expr, (double)n / (n - 1) * 20 - 10) + recursiveSum(expr, n - 1);
    }
}

void swapArrays(Expression** arr1, Expression** arr2) {
    Expression* temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

int main() {
    srand(time(NULL));

    int n = 10;
    Expression* expr = (Expression*)malloc(n * sizeof(Expression));

    for (int i = 0; i < n; i++) {
        expr[i].A = randomInt();
        expr[i].B = randomInt();
        expr[i].C = randomInt();
        expr[i].D = randomInt();
    }

    double mean, stddev, sumPositive, sumNegative;
    computeStatistics(expr, n, &mean, &stddev, &sumPositive, &sumNegative);

    printf("Mean: %f\n", mean);
    printf("Standard Deviation: %f\n", stddev);
    printf("Sum of Positive Values: %f\n", sumPositive);
    printf("Sum of Negative Values: %f\n", sumNegative);

    double (*transformation)(double);
    transformation = sqrt;
    applyTransformation(expr, n, transformation);

    double sum = recursiveSum(expr, n);
    printf("Sum of All Elements: %f\n", sum);

    Expression* expr2 = (Expression*)malloc(n * sizeof(Expression));

    for (int i = 0; i < n; i++) {
        expr2[i].A = randomInt();
        expr2[i].B = randomInt();
        expr2[i].C = randomInt();
        expr2[i].D = randomInt();
    }

    swapArrays(&expr, &expr2);

    free(expr);
    free(expr2);

    return 0;
}

