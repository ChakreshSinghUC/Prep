#include <iostream>

using namespace std;

// Function to check if a number is odd or even
bool isEven(int n)
{
    return (n & 1) == 0;
}

// Function to get the ith bit of a number
int getBit(int n, int i)
{
    return (n & (1 << i)) != 0;
}

// Function to set the ith bit of a number
int setBit(int n, int i)
{
    return n | (1 << i);
}

// Function to clear the ith bit of a number
int clearBit(int n, int i)
{
    return n & ~(1 << i);
}

// Function to toggle the ith bit of a number
int toggleBit(int n, int i)
{
    return n ^ (1 << i);
}

// Function to count the number of set bits (Hamming weight)
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Function to check if a number is a power of two
bool isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

// Function to swap two numbers using XOR
void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

int main()
{
    int n = 29; // Binary: 11101
    int i = 2;

    cout << "Number: " << n << endl;
    cout << "Is even: " << (isEven(n) ? "Yes" : "No") << endl;
    cout << "Get bit at position " << i << ": " << getBit(n, i) << endl;
    cout << "Set bit at position " << i << ": " << setBit(n, i) << endl;
    cout << "Clear bit at position " << i << ": " << clearBit(n, i) << endl;
    cout << "Toggle bit at position " << i << ": " << toggleBit(n, i) << endl;
    cout << "Count of set bits: " << countSetBits(n) << endl;
    cout << "Is power of two: " << (isPowerOfTwo(n) ? "Yes" : "No") << endl;

    int a = 5, b = 7;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    return 0;
}