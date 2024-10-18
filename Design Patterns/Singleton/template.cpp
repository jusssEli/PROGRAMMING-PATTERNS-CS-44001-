// Games, Template Method example
// Elijah Rogers

#include <ctime>
#include <cstdlib>
#include <iostream>

using std::cout; using std::endl; using std::cin;

// template for any game where players take 
// turns to make moves
// and there is a winner
class Game{
public:
   Game():playersCount_(0), movesCount_(0), playerWon_(noWinner){}

   // template method
   void playGame(const int playersCount = 0) {
      playersCount_ = playersCount;
      movesCount_=0;

      initializeGame();

      for(int i=0; !endOfGame(); i = (i+1) % playersCount_ ){
	 makeMove(i);
	 if (i==playersCount_-1) 
	    ++movesCount_; 
      }
      printWinner();
   }

   virtual ~Game(){}

protected:
   // primitive operations
   virtual void initializeGame() = 0;
   virtual void makeMove(int player) = 0;
   virtual void printWinner() = 0;
   virtual bool endOfGame() { return playerWon_ != noWinner;} // this is a hook
                   // returns true if winner is decided
   static const int noWinner=-1;

   int playersCount_;
   int movesCount_;
   int playerWon_;
};

// Monopoly - a concrete game implementing primitive 
// operations for the template method
// class Monopoly: public Game {
// public:  
//     // implementing concrete methods
//     //    void initializeGame(){
//     //       playersCount_ = rand() % numPlayers_ + 1 ; // initialize players
//     //    }
//     void score(int tracker){
//         for(int i = 0; i < 5; ++i){
//             tracker = rand() % 6+1;
//             tracker += tracker;
//         }
//     }
//     void makeMove(int player) {
//         if (movesCount_ > minMoves_){ 
//         const int chance = minMoves_ + rand() % (maxMoves_ - minMoves_); //%6+1
//         if (chance < movesCount_) playerWon_= player;
//         }
//     }

//    void printWinner(){
//       cout << playerWon_<<;
//    }

// private:
//    static const int numPlayers_ = 8; // max number of players
//    static const int minMoves_ = 20; // nobody wins before minMoves_
//    static const int maxMoves_ = 200; // somebody wins before maxMoves_
// };
class DiceRoll: public Game {
public:

    void initializeGame(){
        playersCount_ = 2; // initalize players
    }

    void makeMove(int player){
        static int compSum = 0;
        static int peopleSum = 0;
        char ch, playerPass;
        int count = 1;
        int passing;
        //start looping depending on choice
        do{
            passing = rand() % 2; // for random computer pass or not
            if(passing == 0){
                cout << "Computer rolled: ";
                for (int j = 0; j < 5; ++j){
                    int result = rand() % 6 + 1;
                    cout << result << " ";
                    compSum = compSum + result ;
                }
                
                cout <<", Computer Score = " << compSum << " " << endl;
                if(compSum > compHigh) 
                    compHigh = compSum;
                compSum = 0;
            }
            else {
                cout << "Computer passed. Score is " << compHigh << endl;
            }
            cout << "Do you want to pass? ";
            cin >> playerPass; 
            if(playerPass == 'n'){
                cout << "Player rolled : ";
                for (int j = 0; j < 5; ++j){
                    int result = rand() % 6 + 1;
                    cout << result << " ";
                    peopleSum = peopleSum + result;
                }
                cout << "Player Score = " << peopleSum << " " << endl;
                if(peopleSum > peopleHigh) 
                    peopleHigh = peopleSum;
                peopleSum = 0;
                ++count;
                if(count == 4){
                    // cout << "Wanna play again? "; 
                    // cin >> ch;
                    break;
                }
            }
            else{
                cout << "Player passed. Score is: " << peopleHigh << endl;
            }
            if(playerPass == 'y' && passing == 1) break;
        }
        while(playerPass == 'n' && count <= 3);
            
        if(peopleHigh > compHigh)
            playerWon_ = 0;
        if(peopleHigh < compHigh)
            playerWon_ = 0;
        if(peopleHigh == compHigh)
            playerWon_ = 0;
    }

    void printWinner(){
        // if(playerWon_== 0){
        //   cout<<"Computer Wins"<<endl;
        // }
        // else{//playerWon_=11
        //   cout <<"Player Wins"<<endl;
        // }
        if(peopleHigh < compHigh){
        cout << "Game Over!! The Computer score Won! LOSER!!!" << endl;
        }
        if(peopleHigh > compHigh){
        cout << "You Won! unfortunate...." << endl;
        }
  }

private:
    int compHigh = 0; //computer score
    int peopleHigh = 0; //player score
    static const int numPlayers_ = 2; // max number of players
    int score[numPlayers_];  // 0 is for computer 1 is for Player player
};
// Chess - another game implementing
// primitive operations
// class Chess: public Game {
// public:
//    void initializeGame(){
//       playersCount_ = numPlayers_; // initalize players
//       for(int i=0; i < numPlayers_; ++i) 
// 	     experience_[i] = rand() % maxExperience_ + 1 ; 
//    }

//    void makeMove(int player){
//       if (movesCount_ > minMoves_){
// 	 const int chance = (rand() % maxMoves_) / experience_[player];
// 	 if (chance < movesCount_) playerWon_= player;
//       }
//    }

//    void printWinner(){
//       cout << "Chess, player " << playerWon_ 
// 	   << " with experience " << experience_[playerWon_]
// 	   << " won in "<< movesCount_ << " moves over"
// 	   << " player with experience " << experience_[playerWon_== 0 ? 1:0] 
//            << endl;
//    }

// private:
//    static const int numPlayers_ = 2;
//    static const int minMoves_ = 5; // nobody wins before minMoves_
//    static const int maxMoves_ = 100; // somebody wins before maxMoves_
//    static const int maxExperience_ = 5; // player's experience
//                               // the higher, the greater probability of winning
//    int experience_[numPlayers_]; 
// };

int main() {
   srand(time(nullptr));

   Game* gp = nullptr;
    gp = new DiceRoll;
    gp -> playGame();
    delete gp;
//    // play chess 7 times
//    for (int i = 0; i < 7; ++i){ 
//       gp = new Chess;
//       gp -> playGame(); 
//       delete gp;
//    }
      

//    // play monopoly 7 times
//    for (int i = 0; i < 7; ++i){
//       gp = new Monopoly;
//       gp -> playGame(); 
//       delete gp;
//    }
}