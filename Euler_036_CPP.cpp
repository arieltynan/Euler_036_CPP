// Euler_036_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
// Current runtime sub-7 seconds

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> decToBinary(int bin) //function taken from GeekstoGeeks and heavily modified
{
    // array to store binary number
    vector<int> binaryNum;

    // counter for binary array
    int i = 0;
    while (bin > 0) {

        // storing remainder in binary array
        binaryNum.push_back(bin % 2);
        bin = bin / 2;
        i++;
    }
    return binaryNum;
}

bool palCheck(vector<int> v)
{

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
        int inc = 2 * i + 1; //does not include even numbers, they will not be palindromic in binary
        int temp = inc;
        vector<int> vect;
        while (temp != 0) //separates ints into digits
        {
            vect.push_back(temp % 10);
            temp /= 10;
        }
        if ((palCheck(vect) == true) && palCheck(decToBinary(inc)) == true)
        {
            cout << 2*i + 1 << endl;
            //cout << decToBinary(temp) << endl;
            total = total + inc;
        }
    } //end for
    cout << "The total is: " << total << endl;
}
