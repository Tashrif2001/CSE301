#include <bits/stdc++.h>
using namespace std;

struct activity {
    string name;
    int start_t;
    int end_t;
};

bool compare(activity a, activity b) {
    return a.end_t < b.end_t;
}

int main() {
    vector<activity> works;
    string s;
    int t;
    for (int i = 0; i < 6; i++) {
        cin >> s;
        activity act;
        act.name = s;
        cin >> t;
        act.start_t = t;
        cin >> t;
        act.end_t = t;
        works.push_back(act);
    }
    sort(works.begin(), works.end(), compare);

    vector<activity> sorted;
    sorted.push_back(works[0]);
    int lastEnd = works[0].end_t;
    for (int i = 1; i < works.size(); i++) {
        if (works[i].start_t >= lastEnd) {
            sorted.push_back(works[i]);
            lastEnd = works[i].end_t;
        }
    }
    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i].name << endl;
    }
    return 0;
}
