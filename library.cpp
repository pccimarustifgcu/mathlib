#include "library.h"

std::vector<int> getPrimes(int upperBound, int lowerBound){
    std::vector<int> primeNumbers;
    // true: index is prime
    // false: index is not prime
    std::vector<bool> primeBooleans;

    // Sets all booleans in primeBooleans to true
    primeBooleans.reserve(upperBound);
    for (int i = 0; i < upperBound; i++) {
        primeBooleans.push_back(true);
    }

    // Sieve of Eratosthenes to generate primes
    for (int i = lowerBound; i < upperBound; i++) {
        for (int j = lowerBound; j < upperBound / i + 1; j++) {
            primeBooleans[i * j] = false;
        }
    }

    // Copies indexes marked true to a list
    for (int i = 2; i < upperBound; i++) {
        if (primeBooleans[i]) {
            primeNumbers.push_back(i);
        }
    }
    return primeNumbers;
}

bool isPrime(int number)
{
    std::vector<int> primes = getPrimes(ceil(sqrt(number))) ;
    for (const int &p : primes)
    {
        if (number % p == 0)
        {
            return false;
        }
    }
    return true;
}

int getMultiplicativePersistence(int number) {
    // Converts number to string in order to reference each digit
    std::string strNumber = std::to_string(number);

    int iterations = 0;

    int product;
    do {
        product = 1;
        // for each digit in number
        for (int i = 0; i < strNumber.length(); i++) {
            product *= strNumber[i] - '0'; // - '0' converts a char to an int
        }

        iterations ++;
        strNumber = std::to_string(product);
//        std::cout << product << ", " << iterations << "\n";
    } while (product > 9); // while product is not a single digit
    return iterations;
}

int getCollatzNumber(int number) {
    int collatzIterations = 0;
    // The collatz conjecture states that all numbers will reach one
    // when C(n) is applied recursively
    while (number != 1) {
        // If n is odd
        if (number % 2 == 1) {
            number = number * 3 + 1;
        }
        // if n is even
        else {
            number /= 2;
        }
        collatzIterations ++;
    }
    return collatzIterations;
}

long double fibonacciIndex(long int number){
    return log(number * sqrt(5)) / log((1+sqrt(5))/2);
}

std::string derivative(std::string function){
    std::vector<std::string> vecFunc;

    // Adds a space (which is not a digit) to the end of the input to help with extracting numbers
    function.push_back(' ');

    // The number to be extracted
    std::string num;
    // Counter the number of characters in a row that are numbers
    int counter = 0;


    for (int c = 0; c < function.size(); c++)
    {
        if (!isnumber(function[c]))
        {
            for (int j = counter; j >= 1; j--)
            {
                num.push_back(function[c-j]);
            }

            vecFunc.push_back(num);
            counter = 0;
            num = "";
//            num.push_back(' ');

            switch (function[c])
            {
                case ' ':
                    break;
                case 'x':
                    vecFunc.push_back("x");
//                    std::cout << "x ";
                    break;
                case '+':
                    vecFunc.push_back("+");
//                    std::cout << "plus ";
                    break;
                case '-':
                    vecFunc.push_back("-");
//                    std::cout << "minus ";
                    break;
                case '*':
                    vecFunc.push_back("*");
//                    std::cout << "multiplication ";
                    break;
                case '/':
                    vecFunc.push_back("/");
//                    std::cout << "division ";
                    break;
                case '^':
                    vecFunc.push_back("^");
//                    std::cout << "exponent ";
                    break;
                default:
                    std::cout << "error 0 ";
            }
        }
        else {
            counter++;
        }
    }

    for (std::string c: vecFunc)
    {
        std::cout << c << ' ';
    }
    return num;
}
