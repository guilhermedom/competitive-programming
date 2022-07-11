#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstdio>

using namespace std;

typedef struct {
    int points;
    int goalsScored;
    int goalsAgainst;
    int goalDifference;
    string name;
    int matches;
    int wins;
    int draws;
    int losses;
} Team;

bool compare(const Team a, const Team b) {
    if (a.points > b.points)
        return true;
    if (a.points < b.points)
        return false;

    if (a.wins > b.wins)
        return true;
    if (a.wins < b.wins)
        return false;

    if (a.goalDifference > b.goalDifference)
        return true;
    if (a.goalDifference < b.goalDifference)
        return false;

    if (a.goalsScored > b.goalsScored)
        return true;
    if (a.goalsScored < b.goalsScored)
        return false;

    if (a.matches < b.matches)
        return true;
    if (a.matches > b.matches)
        return false;

    if (a.name < b.name)
        return true;
    if (a.name > b.name)
        return true;

    return false;
}

int main() {
    int n, i, j, k, nTeams, numMatches, goals1, goals2;
    string name, currentTeam1, currentTeam2, teamName;
    char car;
    vector<Team> array_v;

    cin >> n;

    for (i = 0; i < n; i++) {
        if (i == 0)
            cin.ignore(INT_MAX, '\n');
        getline(cin, name);

        cin >> nTeams;

        Team team;
        for (j = 0; j < nTeams; j++) {
            team.losses = 0;
            team.wins = 0;
            team.draws = 0;
            team.goalsAgainst = 0;
            team.goalsScored = 0;
            team.goalDifference = 0;
            team.matches = 0;
            team.points = 0;
            if (j == 0)
                cin.ignore(INT_MAX, '\n');
            getline(cin, teamName);

            team.name = teamName;

            array_v.push_back(team);
        }

        cin >> numMatches;

        for (j = 0; j < numMatches; j++) {
            if (j == 0)
                cin.ignore(INT_MAX, '\n');
            getline(cin, currentTeam1, '#');
            cin >> goals1;
            cin >> car;
            cin >> goals2;
            cin >> car;
            getline(cin, currentTeam2);

            for (k = 0; k < nTeams; k++) {
                if (array_v.at(k).name == currentTeam1) {
                    if (goals1 > goals2) {
                        array_v.at(k).points += 3;
                        array_v.at(k).wins++;
                    }
                    else if (goals1 == goals2) {
                        array_v.at(k).points++;
                        array_v.at(k).draws++;
                    }
                    else
                        array_v.at(k).losses++;

                    array_v.at(k).matches++;

                    array_v.at(k).goalsScored += goals1;
                    array_v.at(k).goalsAgainst += goals2;
                    array_v.at(k).goalDifference += (goals1 - goals2);
                }

                if (array_v.at(k).name == currentTeam2) {
                    if (goals2 > goals1) {
                        array_v.at(k).points += 3;
                        array_v.at(k).wins++;
                    }
                    else if (goals1 == goals2) {
                        array_v.at(k).points++;
                        array_v.at(k).draws++;
                    }
                    else
                        array_v.at(k).losses++;

                    array_v.at(k).matches++;

                    array_v.at(k).goalsScored += goals2;
                    array_v.at(k).goalsAgainst += goals1;
                    array_v.at(k).goalDifference += (goals2 - goals1);
                }
            }
        }

        sort(array_v.begin(), array_v.end(), compare);

        cout << name << "\n";

        for (j = 0; j < nTeams; j++) {
            cout << j + 1 << ") " << array_v[j].name << " ";
            cout << array_v[j].points << "p, " << array_v[j].matches;
            cout << "g (" << array_v[j].wins << "-" << array_v[j].draws;
            cout << "-" << array_v[j].losses << "), " << array_v[j].goalDifference;
            cout << "gd (" << array_v[j].goalsScored << "-" << array_v[j].goalsAgainst << ")\n";
        }

        if (i != (n-1))
            cout << "\n";
        array_v.clear();
    }

    return 0;
}
