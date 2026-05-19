#include <iostream>
using namespace std;

// Item structure
struct Item {
    int profit, weight;
    float ratio;
};

// Swap function
void swap(Item &a,
          Item &b) {

    Item temp = a;
    a = b;
    b = temp;
}

int main() {

    int n;

    cout << "Enter number of items: ";
    cin >> n;

    Item item[100];

    // Input items
    for(int i = 0; i < n; i++) {

        cout << "\nEnter profit and weight: ";
        cin >> item[i].profit
            >> item[i].weight;

        item[i].ratio =
        (float)item[i].profit /
        item[i].weight;
    }

    int capacity;

    cout << "\nEnter knapsack capacity: ";
    cin >> capacity;

    // Sort by ratio
    for(int i = 0; i < n - 1; i++) {

        for(int j = i + 1; j < n; j++) {

            if(item[i].ratio <
               item[j].ratio) {

                swap(item[i], item[j]);
            }
        }
    }

    float maxProfit = 0;

    // Fractional Knapsack
    for(int i = 0; i < n; i++) {

        // Full item taken
        if(capacity >= item[i].weight) {

            capacity -= item[i].weight;

            maxProfit += item[i].profit;
        }

        // Fraction taken
        else {

            maxProfit +=
            item[i].ratio * capacity;

            break;
        }
    }

    cout << "\nMaximum Profit = "
         << maxProfit;

    return 0;
}