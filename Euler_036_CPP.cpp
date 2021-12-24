// Euler_036_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int decToBinary(int bin) //function taken from GeekstoGeeks and modified
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (bin > 0) {

        // storing remainder in binary array
        binaryNum[i] = bin % 2;
        bin = bin / 2;
        i++;
    }

    // printing binary array in reverse order
    int biVal = 0;
    for (int j = 0; j < i; j++)
        biVal = 10 * biVal + (binaryNum[j] + 1); //binary of 1,2 instead of 0,1 because zeroes not showing up
    //cout << biVal << endl;
    return biVal;
}

bool palCheck(int num, vector<int> v)
{
    while (num != 0) //separates ints into digits
    {
        v.push_back((num % 10)*1.0 + .5);
        num /= 10;
    }
    bool palin = true;
    for (int j = 0; j < v.size(); j++)
    {
        if (v[j] != v[v.size() - 1 - j])
            palin = false;
    }
    return palin;
}

int main()
{
    int n = 1000000;
    int total = 0;
    for (int i = 0; i < n/2; i++) //checks all numbers after 1, before limit
    {
        int temp = 2*i + 1;
        vector<int> vect;
        
        if (palCheck(temp, vect) == true && palCheck(decToBinary(temp), vect) == true)
        {
            cout << temp << endl;
            cout << decToBinary(temp) << endl;
            total = total + temp;
        }
    } //end for
    cout << "The total is: " << total << endl;
}
