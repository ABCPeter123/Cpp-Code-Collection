#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

// Pull 2 cards from 52 card pile, if they are same, you win. If they are different, player pull again and if the smallest card and the third card add up to the biggest, player wins

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main() {
    int n;
    double bet;
    long int counter1 = 0, counter2 = 0, counter3 = 0;
    long double total = 0;
    long double money = 0;
    cout << "How many times do you want to play: ";
    cin >> n;
    cout << "How much are you betting: ";
    cin >> bet;
    int numbers[52];
    for (int j = 0; j < 52; j++) {
        numbers[j] = j;
    }
    random_device rd;
    mt19937 gen(rd());
    for (int i = 0; i < n; i++) {
        money -= bet;
        int deal[3];
        shuffle(numbers, numbers + 52, gen);
        for (int j = 0; j < 2; j++) {
            int temp = numbers[j];
            deal[j] = (temp - temp % 4) / 4 + 1;
        }
    
        if (deal[0] == deal[1]) {
            money += 2 * bet;
            counter1++;
            continue;
        } else {
            int minimum = min(deal[0], deal[1]);
            int maximum = max(deal[0], deal[1]);
            int temp = numbers[2];
            deal[2] = (temp - temp % 4) / 4 + 1;
            if ((2 * minimum) == maximum && minimum == deal[2]) {
                money += 101 * bet;
                counter3++;
                continue;
            } else if (min(deal[0], deal[1]) + deal[2] == max(deal[0], deal[1])) {
                    money += 6 * bet;
                    counter2++;
                    continue;
            }
        }
    }

    cout << "You have total: $" << money << endl;
    cout << "In average you have earned $" << (double) (money / n) << endl;
    cout << "There were " << counter1 << " same cards" << endl;
    cout << "There were " << counter2 << " different cards but win" << endl;
    cout << "There were " << counter3 << " special win" << endl;
    cout << "There were " << n - counter1 - counter2 - counter3 << " of none of the above" << endl;
    cout << "Probability of #1: " << (double) (counter1 * 1.00/ n) << endl;
    cout << "Probability of #2: " << (double) (counter2 * 1.00/ n) << endl;
    cout << "Probability of #3: " << (double) (counter3 * 1.00/ n) << endl;
    cout << "Probability of #4: " << (double) ((n - counter1 - counter2 - counter3) * 1.00 / n) << endl;
    
}