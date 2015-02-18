#include<iostream> 
#include "Header.h"
#include <vector>

using namespace std; 


int main(){
    
    int numberOfPlayers; 
    vector<Player> playersVector; 
    string status;
    int round = 1;
    bool gameOver = 0;
    
    cout << "Velkommen til Spardam!" << endl<< endl; 
    showAces();
    
    cout <<endl<<endl<< "Skriv inn antall spillere: "; 
    cin >> numberOfPlayers; 
    cout << endl<<endl; 
    
    for (int i = 0; i < numberOfPlayers ; i++){
        string nameTemp;
        cout << "Spiller " << i+1 << ":";
        cin >> nameTemp; 
        Player *pointer = new Player(nameTemp); 
        playersVector.push_back(*pointer);
    }
    
    cout << "Vil du starte spillet? (y/n)"; 
    
    cin >> status;
    
    cout << endl<<endl; 
    
    while ((status != "n") || (gameOver =0)){
        setPoints(playersVector, numberOfPlayers, round);
        sortVector(playersVector, numberOfPlayers);
        cout <<endl<<endl<< "Result etter runde " << round << ":" << endl << endl;
        showStats(playersVector, numberOfPlayers, round);
        for (int i = 0; i < numberOfPlayers; i++){
            if (playersVector[i].getPoints() > 50 || playersVector[i].getPoints() < -25){
                gameOver = 1; 
            }
        }
        cout <<endl<<endl<< "Vil du spille en runde til? (y/n)";
        cin >> status;
        cout << endl<<endl;
        round = round + 1;  
    }
    showAces();
    cout << "Spillet er avsluttet etter "<< round <<" runder og resultet ble som følgende: " << endl<<endl; 
    sortVector(playersVector, numberOfPlayers);
    
    cout << endl<<endl;
    cout << "VINNER: \t" << playersVector[0].getName() << endl << endl << "TAPER: \t\t" << playersVector[numberOfPlayers-1].getName() <<  endl<<endl; 
    showStats(playersVector, numberOfPlayers, round);
    cout << "Thomas takker for spillet og gratulerer "<< (playersVector[0]).getName() << " med seieren!" ; 
}