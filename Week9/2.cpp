/*
Given a knapsack of maximum capacity w. N items are provided, each
having its own value and weight. You have to Design an algorithm and
implement it using a program to find the list of the selected items such that
the final selected content has weight w and has maximum value. You can
take fractions of items,i.e. the items can be broken into smaller pieces so
that you have to carry only a fraction xi of item i, where 0 ≤xi≤ 1.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item
{
    int weight;
    int value;
    double ratio;
};
bool compareItems(const Item &a, const Item &b)
{
    return a.ratio > b.ratio;
}
void fractionalKnapsack(int numItems, vector<int> &weights, vector<int> &values, int maxCapacity)
{
    vector<Item> items(numItems);
    for (int i = 0; i < numItems; i++)
    {
        items[i].weight = weights[i];
        items[i].value = values[i];
        items[i].ratio = static_cast<double>(values[i]) / weights[i];
    }
    sort(items.begin(), items.end(), compareItems);
    int remainingCapacity = maxCapacity;
    double knapsackValue = 0.0;
    vector<double> fractions(numItems, 0.0);
    for (int i = 0; i < numItems; i++)
    {
        if (items[i].weight <= remainingCapacity)
        {
            fractions[i] = 1.0;
            remainingCapacity -= items[i].weight;
            knapsackValue += items[i].value;
        }
        else
        {
            fractions[i] = static_cast<double>(remainingCapacity) / items[i].weight;
            knapsackValue += fractions[i] * items[i].value;
            break;
        }
    }
    cout << "Maximum value: " << knapsackValue << endl;
    cout << "Selected items:\n";
    for (int i = 0; i < numItems; i++)
    {
        if (fractions[i] > 0.0)
        {
            cout << "Item " << (i + 1) << ": " << fractions[i] << " fraction\n";
        }
    }
}

int main()
{
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;
    vector<int> weights(numItems);
    vector<int> values(numItems);
    cout << "Enter the weights of items: ";
    for (int i = 0; i < numItems; i++)
    {
        cin >> weights[i];
    }
    cout << "Enter the values of items: ";
    for (int i = 0; i < numItems; i++)
    {
        cin >> values[i];
    }
    int maxCapacity;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> maxCapacity;
    fractionalKnapsack(numItems, weights, values, maxCapacity);
    return 0;
}
