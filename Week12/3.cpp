/*
Q3 :- Given a string of characters, design an algorithm and implement it
using a program to print all possible permutations of the string in
lexicographic order.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void generatePermutations(string sortedString, string prefix, vector<string> &permutations)
{
    if (sortedString.empty())
    {
        permutations.push_back(prefix);
        return;
    }

    for (int i = 0; i < sortedString.length(); i++)
    {
        string newPrefix = prefix + sortedString[i];
        string newSortedString = sortedString.substr(0, i) + sortedString.substr(i + 1);
        generatePermutations(newSortedString, newPrefix, permutations);
    }
}
int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    sort(input.begin(), input.end());

    vector<string> permutations;
    generatePermutations(input, "", permutations);

    cout << "Permutations in lexicographic order:" << endl;
    for (const string &permutation : permutations)
    {
        cout << permutation << endl;
    }

    return 0;
}
