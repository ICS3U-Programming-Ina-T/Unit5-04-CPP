// Copyright (c) 2022 Ina Tolo All rights reserved.
//
// Created by: Ina Tolo
// Created on: Jan. 18, 2022
// This program asks the user for three
// parameters: an operation and two numbers.
// It then calculates the results using a separate
// function.

#include <iostream>
#include <iomanip>
#include <cmath>

// calculates the result of two numbers
double calculate(char sign, float firstNum, float secondNum) {
    float result;

    if (sign == '%') {
        result = fmod(firstNum, secondNum);
    } else if (sign == '/') {
        result = firstNum / secondNum;
    } else if (sign == '*') {
        result = firstNum * secondNum;
    } else if (sign == '-') {
        result = firstNum - secondNum;
    } else {
        result = firstNum + secondNum;
    }

    return result;
}


// checks for invalid input and calls
// function to determine result of two numbers
int main() {
    // displays opening message
    std::cout << "This program will perform calculations between two numbers!";
    std::cout << std::endl;
    std::cout << std::endl;

    // declares variables
    char signUser;
    std::string firstNumString, secondNumString;
    float firstNumFloat, secondNumFloat;
    double resultUser;

    // gets operation from user
    std::cout << "Enter the operation you want to perform (+, -, *, /, %): ";
    std::cin >> signUser;

    // checks if invalid operator is entered
    if (signUser == '+' || signUser == '-' || signUser == '*' \
        || signUser == '/' || signUser == '%') {
        std::cout << "Enter the first number: ";
        std::cin >> firstNumString;

        try {
            // convert the user's input to a float
            firstNumFloat = std::stof(firstNumString);

            std::cout << "Enter the second number: ";
            std::cin >> secondNumString;

            try {
                // convert the user's input to a float
                secondNumFloat = std::stof(secondNumString);

                // assigns variable to function call that gives return value
                resultUser = calculate(signUser, firstNumFloat, secondNumFloat);

                // displays results to user
                std::cout << std::endl;
                std::cout << "The result of " << std::fixed;
                std::cout << std::setprecision(2) << firstNumFloat << " ";
                std::cout << signUser << " " << std::fixed;
                std::cout << std::setprecision(2) << secondNumFloat;
                std::cout << " is " <<  std::fixed << std::setprecision(2);
                std::cout << resultUser;

            // determines if the input is valid
            } catch (std::invalid_argument) {
            // tells user did the input is not a number
            std::cout << secondNumString << " is not a valid number.";
            }

        // determines if the input is valid
        } catch (std::invalid_argument) {
        // tells user did the input is not a number
        std::cout << firstNumString << " is not a valid number.";
        }
    } else {
        std::cout << "Error. " << signUser << " is not a recognized operation.";
    }
}
