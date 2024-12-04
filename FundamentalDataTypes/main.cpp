//
//  main.cpp
//  FundamentalDataTypes
//
//  Created by Gunnar Beck
//

#include <iostream>
#include <string>

using namespace std;

/*
 Fundamental Types:
 DICSB
 
 ** Double = 3.1416
    (floating numbers used for accurate representation)
    --64 bits in memory
 
 ** Int = 2
    (whole numbers)
    --4 bytes in memory
 
 ** Char = A single character
    (Ex: 'A' or other single character symbol that can be converted to ASCII format ex '*')
    --8 bits in memory--1 byte
    -Represent different values like numbers, letters, and even images;
    -Binary represents data using 0s and 1s, computer's natural language
    -binary 01010101 (each 0 and 1 are called bits)
    -Ex: A = 01000001
    -Ex: 100 = 00110001 00110000 00110000
 
    -Signed:
        -Can store both positive and negative values
        -Range: -128 to 127
        -Uses the first bit (most significant bit) as a sign bit.
            • 0 = positive
            • 1 = negative
        Ex:
            -Binary '01111111' = '127' (largest positive value) = In ASCII Format = A rectangle
            -Binary '10000000' = '-128' (smallest negative value) = In ASCII Format = A rectangle

    -Unsigned:
        -Can store only positive
        -Range: 0 to 255
        -All 8 bits are used for magnitude
            -Binary '11111111' = '255' = In ASCII Format = ÿ
            -Binary '00000001' = '1' = In ASCII Format = A rectangle
 
 ** String = Sequence of characters
    (Ex: "Michael")
    ~Overhead (Starting memory) 24 bytes
    ~Subject to the size of the string: n + 1 bytes
 
 ** Boolean = true or false
    (Ex: Truth or dare game)
    -1 byte in memory
 
 All can be used as functions, but must return something, except for void
 
 cout---C Out (Output)
 cin---C In (Input)
 
 ** Void function = Can be used without 
    needing to return anything,
    but used greatly to create actions,
    call upon other actions,
    ex: printing out
 */

//helper functions

//double function
double calculatedCircleArea(double radius) {
    //initialize values
    const double pi = 3.1416254;
    //return
    return pi * radius * radius;
}

//integer functions---example: addition, and subtraction
int addition(int a, int b){
    return a + b;
}

int subtract(int a, int b){
    return a - b;
}

//experiement division with integers
int divisionInt(int a, int b){
    return a / b;
}

//division as well--double
double divisionDouble(double a, double b){
    return a / b;
}

//char function
char processChar(char inputChar) {
    //check if the character is within the signed char's range (0-127)
    if (inputChar >= 0 && inputChar <= 127) {
        cout << "The character '" << inputChar << "' is treated as signed." << endl;
        return inputChar;
    }
    //if the character falls outside the sgined char range
    else {
        cout << "The character '" << inputChar << "' is treated as unsigned." << endl;
    }
    
    //invalid range edge case
    cout << "The character '" << inputChar << "' is invlaid or unknown." << endl;
    return '?';
}

//string function--concatenating first and last names
string createFullName(string firstName, string lastName) {
    return firstName + " " + lastName; //return the full name
}

//boolean function
bool isGreaterThan(int a, int b) {
    return a > b; //returns true if a is greater than b because booleans are default to true
}

//void function
void displayInfo(string name, int age) {
    cout << "Name: " << name << ", Age: " << age << endl;
}

int main() {
    
    //using a double
    double radiusMain;
    cout << "Enter the radius of the circle: ";
    cin >> radiusMain;
    double area = calculatedCircleArea(radiusMain); //calculated area
    cout << "The area of the circle with radius " << radiusMain << " is " << area << "\n\n";
    
    //integer functions
    int num1, num2;
    cout << "Enter the numbers to add and subtract: ";
    cin >> num1 >> num2;
    int sum = addition(num1, num2);
    int difference = subtract(num1, num2);
    cout << "The following numbers' sum and difference are: \n" << sum << "\n" << difference << "\n";
    
    //division integer
    int division1, division2;
    cout << "Enter the numbers to divide: ";
    cin >> division1 >> division2;
    int division = divisionInt(division1, division2);
    cout << "The division with the integers is the following: \n" << division << "\n";
    
    //division double
    double divisionOne, divisionTwo;
    cout << "Enter the double numbers to divide: ";
    cin >> divisionOne >> divisionTwo;
    double realDivision = divisionDouble(divisionOne, divisionTwo);
    cout << "The division with the doubles is the following: \n" << realDivision << "\n";
    
    //char
    char inputCharOne;
    cout << "Enter a single character to process: ";
    cin >> inputCharOne;
    char processedCharFunction = processChar(inputCharOne);
    cout << "Processed char: " << processedCharFunction << "\n\n";
    
    //string
    string firstNameMain, lastNameMain;
    cout << "Enter your first name: ";
    cin >> firstNameMain;
    cout << "Enter last name: ";
    cin >> lastNameMain;
    string ourFullName = createFullName(firstNameMain, lastNameMain);
    cout << "Your full name is: " << ourFullName << "\n\n";
     
     int a, b;
     cout << "Enter the two numbers to compare: ";
     cin >> a >> b;
     if (isGreaterThan(a, b)) {
         cout << a << " is greater than " << b << ".\n\n";
     } else {
         cout << a << " is not greater than " << b << ".\n\n";
     }
     
     string name;
     int age;
     cout << "Enter your name: ";
     cin >> name;
     cout << "Enter your age: ";
     cin >> age;
     displayInfo(name, age);
    
    return 0;
}
