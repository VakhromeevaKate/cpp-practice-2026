// Задача 1. «Максимальное число встреч» (15 мин)
// Тема: жадность по времени окончания, сортировка с компаратором.

// Условие: Дан список встреч (начало, конец).
// Выберите максимальное число встреч, которые не пересекаются.
// Считаем, что встреча, заканчивающаяся в момент t, и встреча,
// начинающаяся в момент t, не пересекаются.

// 5 встреч:
// (1, 4), (3, 5), (0, 6), (5, 7), (3, 9), (5, 9), (6, 10), (8, 11), (8, 12), (2, 14)
// Идея: сортируем по времени окончания и берём каждую встречу, 
// которая не пересекается с последней выбранной.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start, end;
    int id;
};

vector<Meeting> maxMeetings(vector<Meeting>& meetings) {
    // Сортируем по времени окончания; при равенстве — по началу
    sort(meetings.begin(), meetings.end(),
         [](Meeting& a, Meeting& b) {
             if (a.end != b.end) return a.end < b.end;
             return a.start < b.start;
         });

    vector<Meeting> chosen;
    int lastEnd = -1;

    for (Meeting& m : meetings) {
        if (m.start >= lastEnd) {
            chosen.push_back(m);
            lastEnd = m.end;
        }
    }
    return chosen;
}

int main() {
    vector<Meeting> meetings = {
        {1, 4, 1}, {3, 5, 2}, {0, 6, 3}, {5, 7, 4}, {3, 9, 5},
        {5, 9, 6}, {6, 10, 7}, {8, 11, 8}, {8, 12, 9}, {2, 14, 10}
    };

    vector<Meeting> result = maxMeetings(meetings);

    cout << "Выбрано встреч: " << result.size() << endl;
    for (Meeting& m : result) {
        cout << "  #" << m.id << ": [" << m.start << ", " << m.end << "]" << endl;
    }
    return 0;
}