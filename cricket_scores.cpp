#include <iostream>
using namespace std;

class Player {
    string name;
    string teamName;
    int ID;
    int no_of_Matches;
    int total_score;
    int total_wickets;
    int total_catches;

public:
    // Setters and getters
    void setName(string N) {
        name = N;
    }

    string getName() {
        return name;
    }

    void setID(int id) {
        ID = id;
    }

    int getID() {
        return ID;
    }

    void setNoOfMatches(int M) {
        no_of_Matches = M;
    }

    int getNoOfMatches() {
        return no_of_Matches;
    }

    void setTeamName(string TN) {
        teamName = TN;
    }

    string getTeamName() {
        return teamName;
    }

    void setTotalScore(int S) {
        total_score = S;
    }

    int getTotalScore() {
        return total_score;
    }

    void setTotalWickets(int W) {
        // Validation for wickets entered by user
        if (W < 0) {
            cout << "Wickets cannot be negative. Please enter a valid number of wickets." << endl;
            return;
        }
        total_wickets = W;
    }

    int getTotalWickets() {
        return total_wickets;
    }

    void setTotalCatches(int C) {
        // Validation for catches entered by user
        if (C < 0) {
            cout << "Catches cannot be negative. Please enter a valid number of catches." << endl;
            return;
        }
        total_catches = C;
    }

    int getTotalCatches() {
        return total_catches;
    }

    // Constructor
    Player() : name(" "), teamName(" "), ID(0), no_of_Matches(0), total_score(0), total_wickets(0), total_catches(0) {}

    Player(string N, string TN, int id, int S, int C, int M, int W) 
        : name(N), teamName(TN), ID(id), no_of_Matches(M), total_score(S), total_wickets(W), total_catches(C) {}

    // Data displaying function
    void dataDisplayer(Player members[], int size) {
        for (int i = 0; i < size; i++) {
            cout << "Name of player " << i + 1 << " : " << members[i].getName() << endl;
            cout << "ID of player " << i + 1 << " : " << members[i].getID() << endl;
            cout << "Team name: " << members[i].getTeamName() << endl;
            cout << "Score of player " << i + 1 << " : " << members[i].getTotalScore() << endl;
            cout << "Wickets taken by player " << i + 1 << " : " << members[i].getTotalWickets() << endl;
            cout << "Catches taken by player " << i + 1 << " : " << members[i].getTotalCatches() << endl;
            cout << endl;
        }
    }

    // Displaying career stats
    void displayCareerFunction(Player members[], int size) {
        int highestScore = members[0].getTotalScore();
        string highestScorer;
        int mostWickets = members[0].getTotalWickets();
        string highestWicketTaker;
        int mostCatches = members[0].getTotalCatches();
        string highestCatcher;

        for (int i = 1; i < size; i++) {
            if (members[i].getTotalScore() > highestScore) {
                highestScore = members[i].getTotalScore();
                highestScorer = members[i].getName();
            }
            if (members[i].getTotalWickets() > mostWickets) {
                mostWickets = members[i].getTotalWickets();
                highestWicketTaker = members[i].getName();
            }
            if (members[i].getTotalCatches() > mostCatches) {
                mostCatches = members[i].getTotalCatches();
                highestCatcher = members[i].getName();
            }
        }

        cout << "HIGHEST SCORE: " << highestScore << " by " << highestScorer << endl;
        cout << "MOST WICKETS TAKEN: " << mostWickets << " by " << highestWicketTaker << endl;
        cout << "MOST CATCHES TAKEN: " << mostCatches << " by " << highestCatcher << endl;
    }
};

int main() {
    int teamSize = 5;
    Player members[teamSize];
    string N, TN;
    int id, S, M, W, C;

    cout << "Enter total matches the team played: ";
    cin >> M;

    for (int i = 0; i < teamSize; i++) {
        cout << "Enter name of player " << i + 1 << ": ";
        cin >> N;
        members[i].setName(N);
        cout << "Enter ID of player " << i + 1 << ": ";
        cin >> id;
        members[i].setID(id);
        cout << "Score of player " << i + 1 << ": ";
        cin >> S;
        members[i].setTotalScore(S);
        cout << "Enter wickets player " << i + 1 << " has taken: ";
        cin >> W;
        members[i].setTotalWickets(W);
        cout << "Total catches player " << i + 1 << " has taken: ";
        cin >> C;
        members[i].setTotalCatches(C);
    }

    cout << "Enter team name: ";
    cin >> TN;
    for (int i = 0; i < teamSize; i++) {
        members[i].setTeamName(TN);
    }

    // Displaying player data
    members[0].dataDisplayer(members, teamSize);

    // Displaying career stats
    members[0].displayCareerFunction(members, teamSize);

    return 0;
}
