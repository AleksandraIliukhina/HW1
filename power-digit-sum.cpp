#include <iostream> // Connects input and output tools.
#include <string> // Helps us to use string, since we need it in this code.
#include <climits> // To check the maximum value.
using namespace std; // So I don't have to write std:: every time. 


// Calculates a to the power of b.
long power(unsigned short a, unsigned short b){
    long result = 1;
    for (int i = 0; i < b; i++){
        // If a is 0, the result will be 0.
        if (a == 0){
            return 0;
        }
        // Check if the result would become too large.
        if (result > LONG_MAX / a){
            cout << "Error: value is too large for long." << endl;
            return -1;
        }
        result = result * a;
    }
    return result;
}

int main(int argc, char* argv[]){
    // We need two arguments: a and b.
    if (argc != 3){
        cout << "Error: Please enter two integers: a and b." << endl;
        cout << "Example: ./pds 2 15" << endl;
        return 1;
    }
    // Keeps the inputs as strings first so we can check them.
    string aString = argv[1];
    string bString = argv[2];
    // Checks if a contains only numbers.
    for (char c : aString){
        if (c < '0' || c > '9')
        {
            cout << "Error: integers only! Letters and other characters are not allowed." << endl;
            return 1;
        }
    }

    // Checks if b contains only numbers.
    for (char c : bString){
        if (c < '0' || c > '9'){
            cout << "Error: integers only! Letters and other characters are not allowed." << endl;
            return 1;
        }
    }
    // Now we can turn the strings into numbers.
    unsigned short a = stoi(aString);
    unsigned short b = stoi(bString);
    // Finds a to the power of b.
    long n = power(a, b);
    // Stops if the result was too large.
    if (n == -1){
        return 1;
    }

    // Finds the sum of all the digits.
    long temp = n;
    long digitSum = 0;

    while (temp > 0){
        // Gets the last digit and add it to the sum.
        digitSum = digitSum + (temp % 10);
        // Removes the last digit.
        temp = temp / 10;
    }

    // Prints the answer.
    cout << a << "^" << b << " = " << n << endl;
    cout << "Sum Of Digits: " << digitSum << endl;

    return 0;
}


/*
I thought about needing this program about 0 times per day last week.

I added the long value check after prof. Novak suggested
thinking about the maximum value that the program can handle.

Sources that I used to understand how to write code better: 

https://learn.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-170

https://www.studyplan.dev/intro-to-programming/include-directive

https://www.programiz.com/cpp-programming/type-modifiers

*/