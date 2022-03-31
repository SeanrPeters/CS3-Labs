
#ifndef TDICE_H_
#define TDICE_H_
#include <ctime>
#include <cstdlib>
#include <iostream>

using std::cout; using std::endl;

// template for any game where players take
// turns to make moves
// and there is a winner
class Game {
public:
        Game() :playersCount_(0), movesCount_(0), playerWon_(noWinner) {}

        // template method
        void playGame(const int playersCount = 0) {
                playersCount_ = playersCount;
                movesCount_ = 0;

                initializeGame();

                for (int i = 0; !endOfGame(); i = (i + 1) % playersCount_) {
                        makeMove(i);
                        if (i == playersCount_ - 1)
                                ++movesCount_;
                }

                printWinner();
        }

        virtual ~Game() {}

protected:
        // primitive operations
        virtual void initializeGame() = 0;
        virtual void makeMove(int player) = 0;
        virtual void printWinner() = 0;
        virtual bool endOfGame() { return playerWon_ != noWinner; } // this is a hook
                                        // returns true if winner is decided
        static const int noWinner = -1;
       int movesCount_;
        int playerWon_;
};

// Monopoly - a concrete game implementing primitive
// operations for the template method
class Monopoly : public Game {
public:
        // implementing concrete methods
        void initializeGame() {
                playersCount_ = rand() % numPlayers_ + 1; // initialize players
        }

        void makeMove(int player) {
                if (movesCount_ > minMoves_) {
                        const int chance = minMoves_ + rand() % (maxMoves_ - minMoves_);
                        if (chance < movesCount_) playerWon_ = player;
                }
        }

        void printWinner() {
                cout << "Monopoly, player " << playerWon_ << " won in "
                        << movesCount_ << " moves." << endl;
        }

private:
        static const int numPlayers_ = 8; // max number of players
        static const int minMoves_ = 20; // nobody wins before minMoves_
        static const int maxMoves_ = 200; // somebody wins before maxMoves_
};

// Chess - another game implementing
// primitive operations
class Chess : public Game {
public:
        void initializeGame() {
                playersCount_ = numPlayers_; // initalize players
                for (int i = 0; i < numPlayers_; ++i)
                        experience_[i] = rand() % maxExperience_ + 1;
        }

        void makeMove(int player) {
                if (movesCount_ > minMoves_) {
                        if (chance < movesCount_) playerWon_ = player;
                }
        }

        void printWinner() {
                cout << "Chess, player " << playerWon_
                        << " with experience " << experience_[playerWon_]
                        << " won in " << movesCount_ << " moves over"
                        << " player with experience " << experience_[playerWon_ == 0 ? 1 : 0]
                        << endl;
        }

private:
        static const int numPlayers_ = 2;
        static const int minMoves_ = 2; // nobody wins before minMoves_
        static const int maxMoves_ = 100; // somebody wins before maxMoves_
        static const int maxExperience_ = 3; // player's experience
                                                           // the higher, the greater probab$
        int experience_[numPlayers_];
};






class Dice : public Game
{
public:
        int playerMax = 0;
        int computerMax = 0;
        bool CompsDecision = false;
        bool playersDecision = false;

        void initializeGame()
        {
                playersCount_ = numPlayers_;

        }
        void makeMove(int player)
        {
                char toRoll;
                int compRoll;
         if (maxMoves_ > movesCount_)
{
                        for (int i = 0; i < 5; ++i)
                                roll_[i] = rand() % 6 + 1;

                        if (player == 0)
                        {
                                if (!CompsDecision)
                                {
                                        theScore = roll_[0] + roll_[1] + roll_[2] + roll_[3]$
                                        if (theScore > computerMax)
                                         computerMax = theScore;

                                        cout << "computer rolled: " << roll_[0] << " " << ro$
                                                 << "computers high score = " << computerMax$
                                        compRoll = rand() % 4 + 1;
                                        if (compRoll == 4)
                                                CompsDecision = true;


                                }
                                else
                                        cout << "Computer rolled: passed , computer's cigh c$


                        }


                        if (player == 1) {
                                if (!playersDecision)
                                {
                                        theScore = roll_[0] + roll_[1] + roll_[2] + roll_[3]$
                                        if (theScore > playerMax)
                                                playerMax = theScore;

                                        cout << "you rolled: " << roll_[0] << " " << roll_[1]
                                                << " " << roll_[2] << " " << roll_[3] << " "$
                                                << ", " << "your high score = " << playerMax$

                                        if (movesCount_ != maxMoves_ - 1)
                                        {
                                                cout << "roll again [y/n]: ";

                                                if (toRoll == 'n')  playersDecision = true;


                                        }
                                }
                                else {
                                        cout << "you rolled: passed, your high score = " << $
                                }
                        }

                }

                if (CompsDecision && playersDecision)
                {
                        cout << "both computer and player kept score, the players score:" <<$
                }
        }

        bool endOfGame()
        {
                // the game ends if the count is 3 or greater
                if (movesCount_ >= 3)
                        return true;

                //the game ends if the computer and the player choses to keep score
                else if (playersDecision && CompsDecision)
                        return true;

                // else, game wont end
                else
                        return false;


        }

        void printWinner()
        {
                if (computerMax > playerMax)
                        cout << "you lose" << endl;
                else if (computerMax == playerMax)
                        cout << "you lose" << endl;
            else
                        cout << "you win" << endl;

        }
private:
        static const int numPlayers_ = 2;
        static const int minMoves_ = 1;
        static const int maxMoves_ = 3;

        int roll_[5] = { 0,0,0,0,0 };

};

#endif


