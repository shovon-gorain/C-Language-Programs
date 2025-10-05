/*
 * C LANGUAGE PROGRAMS COLLECTION
 * Consolidated from: https://github.com/dimpeshmalviya/C-Language-Programs
 * Created as a unique compilation file
 * Organized by category and functionality
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/* ===== UTILITY FUNCTIONS ===== */

void clearScreen() {
    system("cls || clear");
}

void waitForEnter() {
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

/* ===== MATHEMATICAL PROGRAMS ===== */

// Factorial Calculation
unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

void factorialProgram() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d = %llu\n", num, factorial(num));
    }
}

// Fibonacci Series
void fibonacciSeries() {
    int n, first = 0, second = 1, next;
    
    printf("Enter number of terms: ");
    scanf("%d", &n);
    
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
    printf("\n");
}

// Prime Number Check
int isPrime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
}

void primeCheckProgram() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (isPrime(num))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);
}

// Armstrong Number Check
int isArmstrong(int num) {
    int original = num, sum = 0, digits = 0;
    
    // Count digits
    int temp = num;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }
    
    // Calculate sum of digits raised to power of digits count
    temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }
    
    return (sum == original);
}

void armstrongProgram() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);
}

// Palindrome Check
int isPalindrome(int num) {
    int reversed = 0, original = num;
    
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    
    return (original == reversed);
}

void palindromeProgram() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (isPalindrome(num))
        printf("%d is a palindrome.\n", num);
    else
        printf("%d is not a palindrome.\n", num);
}

/* ===== ARRAY OPERATIONS ===== */

// Array Input and Display
void arrayOperations() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Array Sum and Average
void arraySumAverage() {
    int n, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", (float)sum / n);
}

// Find Maximum and Minimum in Array
void arrayMaxMin() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
}

// Linear Search
void linearSearch() {
    int n, key, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    
    if (!found)
        printf("Element not found in array.\n");
}

// Bubble Sort
void bubbleSort() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Bubble sort algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* ===== STRING OPERATIONS ===== */

// String Length
void stringLength() {
    char str[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    
    printf("Length of string: %d\n", length);
}

// String Reverse
void stringReverse() {
    char str[100], reversed[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0';
    
    printf("Reversed string: %s\n", reversed);
}

// String Palindrome Check
void stringPalindrome() {
    char str[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    
    int length = strlen(str);
    int isPalin = 1;
    
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            isPalin = 0;
            break;
        }
    }
    
    if (isPalin)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
}

// Count Vowels and Consonants
void countVowelsConsonants() {
    char str[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    
    int vowels = 0, consonants = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }
    
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
}

/* ===== PATTERN PROGRAMS ===== */

// Right Triangle Pattern
void rightTrianglePattern() {
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Number Pyramid
void numberPyramid() {
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    
    for (int i = 1; i <= rows; i++) {
        // Print spaces
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        // Print numbers
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

// Floyd's Triangle
void floydsTriangle() {
    int rows, num = 1;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", num++);
        }
        printf("\n");
    }
}

/* ===== MATRIX OPERATIONS ===== */

// Matrix Addition
void matrixAddition() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    int mat1[rows][cols], mat2[rows][cols], sum[rows][cols];
    
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    
    // Add matrices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    
    printf("Sum of matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

// Matrix Multiplication
void matrixMultiplication() {
    int r1, c1, r2, c2;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);
    
    if (c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return;
    }
    
    int mat1[r1][c1], mat2[r2][c2], product[r1][c2];
    
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    
    // Initialize product matrix
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            product[i][j] = 0;
        }
    }
    
    // Multiply matrices
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                product[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    
    printf("Product of matrices:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
}

/* ===== FILE OPERATIONS ===== */

// Write to File
void writeToFile() {
    FILE *file;
    char filename[100], content[1000];
    
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter content to write: ");
    scanf(" %[^\n]", content);
    
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return;
    }
    
    fprintf(file, "%s", content);
    fclose(file);
    printf("Content written to file successfully!\n");
}

// Read from File
void readFromFile() {
    FILE *file;
    char filename[100], ch;
    
    printf("Enter filename to read: ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("File content:\n");
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    fclose(file);
    printf("\n");
}

/* ===== ADVANCED PROGRAMS ===== */

// Calculator Program
void calculator() {
    char operator;
    double num1, num2, result;
    
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else {
                printf("Error: Division by zero!\n");
                return;
            }
            break;
        default:
            printf("Invalid operator!\n");
            return;
    }
    
    printf("Result: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
}

// Binary to Decimal Conversion
void binaryToDecimal() {
    long long binary;
    int decimal = 0, base = 1, remainder;
    
    printf("Enter a binary number: ");
    scanf("%lld", &binary);
    
    long long temp = binary;
    while (temp != 0) {
        remainder = temp % 10;
        decimal += remainder * base;
        base *= 2;
        temp /= 10;
    }
    
    printf("Binary: %lld = Decimal: %d\n", binary, decimal);
}

// Decimal to Binary Conversion
void decimalToBinary() {
    int decimal;
    long long binary = 0;
    int remainder, place = 1;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    int temp = decimal;
    while (temp != 0) {
        remainder = temp % 2;
        binary += remainder * place;
        place *= 10;
        temp /= 2;
    }
    
    printf("Decimal: %d = Binary: %lld\n", decimal, binary);
}

/* ===== MENU SYSTEM ===== */

void displayMenu() {
    printf("\n=== C LANGUAGE PROGRAMS MENU ===\n");
    printf("MATHEMATICAL PROGRAMS:\n");
    printf("1. Factorial Calculation\n");
    printf("2. Fibonacci Series\n");
    printf("3. Prime Number Check\n");
    printf("4. Armstrong Number Check\n");
    printf("5. Palindrome Check\n");
    
    printf("\nARRAY OPERATIONS:\n");
    printf("6. Array Input and Display\n");
    printf("7. Array Sum and Average\n");
    printf("8. Find Max and Min in Array\n");
    printf("9. Linear Search\n");
    printf("10. Bubble Sort\n");
    
    printf("\nSTRING OPERATIONS:\n");
    printf("11. String Length\n");
    printf("12. String Reverse\n");
    printf("13. String Palindrome Check\n");
    printf("14. Count Vowels and Consonants\n");
    
    printf("\nPATTERN PROGRAMS:\n");
    printf("15. Right Triangle Pattern\n");
    printf("16. Number Pyramid\n");
    printf("17. Floyd's Triangle\n");
    
    printf("\nMATRIX OPERATIONS:\n");
    printf("18. Matrix Addition\n");
    printf("19. Matrix Multiplication\n");
    
    printf("\nFILE OPERATIONS:\n");
    printf("20. Write to File\n");
    printf("21. Read from File\n");
    
    printf("\nADVANCED PROGRAMS:\n");
    printf("22. Calculator\n");
    printf("23. Binary to Decimal\n");
    printf("24. Decimal to Binary\n");
    
    printf("\n0. Exit\n");
    printf("===============================\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    
    printf("=== C LANGUAGE PROGRAMS COLLECTION ===\n");
    printf("Consolidated from GitHub Repository\n");
    printf("All programs in one unified file\n\n");
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        clearScreen();
        
        switch (choice) {
            case 1: factorialProgram(); break;
            case 2: fibonacciSeries(); break;
            case 3: primeCheckProgram(); break;
            case 4: armstrongProgram(); break;
            case 5: palindromeProgram(); break;
            case 6: arrayOperations(); break;
            case 7: arraySumAverage(); break;
            case 8: arrayMaxMin(); break;
            case 9: linearSearch(); break;
            case 10: bubbleSort(); break;
            case 11: stringLength(); break;
            case 12: stringReverse(); break;
            case 13: stringPalindrome(); break;
            case 14: countVowelsConsonants(); break;
            case 15: rightTrianglePattern(); break;
            case 16: numberPyramid(); break;
            case 17: floydsTriangle(); break;
            case 18: matrixAddition(); break;
            case 19: matrixMultiplication(); break;
            case 20: writeToFile(); break;
            case 21: readFromFile(); break;
            case 22: calculator(); break;
            case 23: binaryToDecimal(); break;
            case 24: decimalToBinary(); break;
            case 0: printf("Thank you for using C Programs Collection!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
        
        if (choice != 0) {
            waitForEnter();
            clearScreen();
        }
        
    } while (choice != 0);
    
    return 0;
}
