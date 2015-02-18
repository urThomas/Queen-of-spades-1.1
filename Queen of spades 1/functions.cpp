#include <iostream>
#include <string>
#include <sstream>
#include "Header.h"

Player::Player(string theName){
    name = theName; 
    points = 0;
}


string Player::getName(){
    return name; 
}

int Player::getPoints(){
    return points;
}

bool operator < (Player p1, Player p2){
    return(p1.points < p2.points);
}

bool operator > (Player p1, Player p2){
    return(!(p1.points < p2.points));
}

bool operator >= (Player p1, Player p2){
    return(p1.points <= p2.points);
}


void Player::setPoints(int thePoints){
    points += thePoints;
}
void showAces(){
    cout << "  _________   _________   _________   __________"<<endl;
    cout << " /         \\ /         \\ /         \\ /          \\"<<endl;
    cout << " |A        | |A        | |A        | |A         |"<<endl;
    cout << " |    ,    | |   _ _   | |    _    | |          |"<<endl;
    cout << " |   / \\   | |  / ^ \\  | |   (_)   | |    /\\    |"<<endl;
    cout <<" |  (_ _)  | |  \\   /  | |  (_)_)  | |   <  >   |"<<endl;
    cout <<" |   /_\\   | |   \\ /   | |   /_\\   | |    \\/    |"<<endl;
    cout <<" |         | |    `    | |         | |          |"<<endl;
    cout <<" |        A| |        A| |        A| |         A|"<<endl;
    cout <<" \\_________/ \\_________/ \\_________/ \\__________/"<<endl;
}

void sortVector(vector<Player> &theVector, int theNumberOfPlayers){
    bool switched = 1;
    int teller = 0; 
    while (switched == 1 && teller < 50) {
        switched = 0;
        for (int i = 0; i < theNumberOfPlayers - 1; i++){
            if (theVector[i] > theVector[i+1]){
                swap(theVector[i], theVector[i+1]);
                switched = 1;
            }
        }
        teller++;
    }
    
}

void setPoints(vector<Player> &theVector, int theNumberOfPlayers, int theRound){
    cout << "Skriv inn resultet fra runde " << theRound<< endl<<endl; 
    for (int i = 0; i < theNumberOfPlayers; i++){
        cout << (theVector[i]).getName()<< ": ";
        int tempPoints;
        cin >> tempPoints;
        (theVector[i]).setPoints(tempPoints);
    }
}

void showStats(vector<Player> theVector, int theNumberOfPlayers, int theRound){
        cout << "Plass \t Spiller \t\t Poeng" << endl<< endl;
    for (int i = 0; i < theNumberOfPlayers; i++){
        cout << i+1 << "\t\t  " <<  theVector[i].getName() << ":  \t\t\t" << theVector[i].getPoints()<< endl; 
    }
}