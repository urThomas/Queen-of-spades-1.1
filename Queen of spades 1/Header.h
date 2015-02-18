#include<iostream>
#include<string>
#include <vector>
using namespace std; 


class Player {
private: 
    string name; 
    int points; 
public: 
    Player(string name); 
    string getName();
    int getPoints();
    void setPoints(int thePoints);
    friend bool operator < (Player p1, Player p2);
    friend bool operator > (Player p1, Player p2);
    friend bool operator >= (Player p1, Player p2);
    /*int getPoints();
    void addPoints(int a);
    string toString(); */
};

void setPoints(vector<Player> &theVector, int theNumberOfPlayers, int theRound);
void showStats(vector<Player> theVector, int theNumberOfPlayers, int theRound); 
void sortVector(vector<Player>&theVector, int theNumberOfPlayers);
void showAces();


//void showAces();


