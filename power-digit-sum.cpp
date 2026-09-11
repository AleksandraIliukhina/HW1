// Aleksandra Iliukhina
// Homework 1, part 2

#include <iostream> // Connects input and output tools.
#include <string> // Helps us to use string, since we need it in this code.
#include <climits> // Gives us information about limits of integer data types.
#include <vector> // Allows us to create and work with vectors.
#include <algorithm> // Provides functions for working with collections, for example, reverse().
#include <cmath> // Provides mathematical functions, including log10() that we use for overflow check here.
using namespace std; // So I don't have to write std:: every time. 


unsigned long long int power(unsigned int a, unsigned int b){
    unsigned long long int result = 1;
    // Result is equal to 1 because we are going to gradually multiply the result by a.  If we started with 0, everything would always remain 0.
    for (unsigned int i = 0; i < b; i++){
        result = result * a;
    }
    return result;
}

// Separates a number into individual digits and stores them in a vector.
vector<int> vectorize_digits(unsigned long long n){
    vector<int> digits;
    // Without this special case, vectorize_digits(0) would return an empty vector because the while loop would never run.
    if (n == 0){
        digits.push_back(0);
        return digits;
    }

    while (n > 0){
        // % 10 gives us the last digit, and dividing by 10 removes the last digit.
        digits.push_back(n % 10);
        n = n / 10;
    }
    // The digits are collected from right to left, so we reverse them to get their original order.
    reverse(digits.begin(), digits.end());
    return digits;
}

// Adds all the numbers that are in a vector.
int sum_vector(vector<int> v){
    int sum = 0;
    for (int digit : v){
        sum = sum + digit;
    }
    return sum;
}

// Converts a vector of digits into the string format.
string vec_to_string(vector<int> vec){
    string result = "[";
    for (int i = 0; i < vec.size(); i++){
        result += to_string(vec[i]);
        if (i < vec.size() - 1){
            result += ", ";
        }
    }
    result += "]";
    return result;
}


int main(int argc, char* argv[]){
    if (argc != 3){
        cout << "Error: Please enter two integers: a and b." << endl;
        cout << "Example: ./pds 2 15" << endl;
        return 1;
    }

    // Keeps the inputs as strings first so we can check them.
    string aString = argv[1];
    string bString = argv[2];

    if (aString[0] == '-' || bString[0] == '-'){
        cout << "Error: a and b must be non-negative integers!" << endl;
        return 1;
    }

    for (char c : aString){
        if (c < '0' || c > '9')
        {
            cout << "Error: integers only! Letters and other characters are not allowed." << endl;
            return 1;
        }
    }

    for (char c : bString){
        if (c < '0' || c > '9'){
            cout << "Error: integers only! Letters and other characters are not allowed." << endl;
            return 1;
        }
    }

    // Now we can turn the strings into numbers.
    unsigned int a = stoi(aString);
    unsigned int b = stoi(bString);

    // Check for overflow before calculating a^b.
    if (a > 0 && b * log10(a) >= 64 * log10(2)){
        cout << "Error: a^b is too large, would cause overflow." << endl;
        return 1;
    }

    unsigned long long int n = power(a, b);

    // Finds all the digits and then calculates their sum.
    vector<int> digits = vectorize_digits(n);
    int digitSum = sum_vector(digits);

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

https://www.w3schools.com/cpp/cpp_ref_vector.asp

https://www.geeksforgeeks.org/cpp/difference-between-long-int-and-long-long-int-in-c-cpp/ 

https://www.geeksforgeeks.org/cpp/convert-vector-of-chars-to-string-in-cpp/ 

https://www.geeksforgeeks.org/cpp/vector-in-cpp-stl/ 
*/