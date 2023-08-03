#include<bits/stdc++.h>
using namespace std;
#define mx 100

struct act{
    string name;
    int start;
    int finish;
};

void b_sort(vector<act>& activities) {
    for (int i = 0; i < activities.size() - 1; i++) {
        for (int j = 0; j < activities.size() - 1; j++) {
            if (activities[i].finish < activities[j].finish) {
                struct act temp = activities[i];
                activities[i] = activities[j];
                activities[j] = temp;
            }
        }
    }
}

int main() {
    freopen("test.txt", "r", stdin);
    int num, t;
    string s;

    cout << "Enter number of activities: ";
    cin >> num;

    vector<act> activities;
    vector<string> order;

    for (int i = 0; i < num; i++) {
        struct act act1;
        cout << "Enter name of activity: ";
        cin >> s;
        act1.name = s;
        cout << "Enter start time: ";
        cin >> t;
        act1.start = t;
        cout << "Enter ending time: ";
        cin >> t;
        act1.finish = t;
        activities.push_back(act1);
    }

    b_sort(activities);

    int lastTime = activities[0].finish;
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastTime) {
            order.push_back(activities[i].name);
            lastTime = activities[i].finish;
        }
    }

    for (int i = 0; i < order.size(); i++)
        cout << order[i] << " ";

    return 0;
}
