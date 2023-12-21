/*
Name: Manan Patel
UIN: 658283328
This project is about a maze where we have to write the code and find the correct maze for 2 strings which are regular maze and twisty maze. In the regular maze, we 
just have to follow the directions and write it on the paper then it will automatically gives us the correct string where as the twisty one is time consuming. In that
we have to write the address of each directions and it will connect with different directions. Like North connects with North. In the end we will get 2 correct strings 
that will find 3 magical items which are spellbook, wand, and potion.  
*/
#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

/* Change constant kYourNetID to store your netID 
 *    - your submission will be manually inspected to ensure
 *      you have used the exact string that is your netID
 *    - thus, it is vital you understand what your netID is
 *    - ex: Professor Reckinger's email is scotreck@uic.edu, so
 *          Professor Reckinger's netID is scotreck     
 *    - ex: Professor Kidane's email is ekidan2@uic.edu, so
 *          Professor Kidane's netID is ekidan2     
 *    - ex: Student Sparky's email is sspark211@uic.edu, so
 *          Student Sparky's netID is sspark211 
 * WARNING: Once you've set set this constant and started 
 * exploring your maze, do NOT edit the value of kYourNetID. 
 * Changing kYourNetID will change which maze you get back, 
 * which might invalidate all your hard work!
 */
const string kYourNetID = "mpate360";

/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "SSSNNESSEWNNEESS";  //found the correct maze string

const string kPathOutOfTwistyMaze = "SWSNWSNNE";  //found the correct maze string

bool isPathToFreedom(MazeCell *start, const string& moves) {
    
    
    /* TO DO: Delete this comment and the next few lines, 
     * then implement this function.
     */
    // (void) start;
    // (void) moves;
    // return false;
    bool sp=false;  
    bool wa=false;
    bool po=false;
    
    MazeCell* currentCell=start;  //assining start pointer to currentCell

    for(size_t i=0;i<moves.length();i++)  //loop through the length of moves 
    {
        if(moves[i]!='N' && moves[i]!='S' && moves[i]!='E' && moves[i]!='W')  // checks if moves array not equal N,S,E,W
        {
            return false;  //returning false
        }
    }

    if(currentCell->whatsHere=="Spellbook") //checks if currentCell pointer points to Spellbook
    {
        sp=true; 
    }
    if(currentCell->whatsHere=="Wand") //checks if currentCell pointer points to Wand
    {
        wa=true; 
    }
    if(currentCell->whatsHere=="Potion") //checks if currentCell pointer points to Potion
    {
        po=true; 
    }

    for(size_t i=0;i<moves.size();i++) //Loop through the size of moves
    {
        char move=moves[i];  // assining moves array to char move
        switch(move) // using switch case to check pointer is assining to north, south, east, and west
        {
            case 'N':
                if(currentCell->north) //if currentCell is notrth
                {
                    currentCell=currentCell->north;  //then it assings it to north
                } 
                else 
                {
                    return false; // else returning false
                }
                break;
            case 'S':
                if(currentCell->south) //if currentCell is South
                {
                    currentCell=currentCell->south;  //then it assings it to south
                } 
                else 
                {
                    return false;  // else returning false
                }
                break;
            case 'E':
                if(currentCell->east) //if currentCell is east
                {
                    currentCell=currentCell->east;  //then it assings it to east
                } 
                else 
                {
                    return false;  // else returning false
                }
                break;
            case 'W':
                if(currentCell->west) //if currentCell is west
                {
                    currentCell=currentCell->west;  //then it assings it to west
                } 
                else 
                {
                    return false;  // else returning false
                }
                break;
            default:
                return false; // else returning false
        }
        //return currentCell != nullptr && currentCell->whatsHere.empty(); // Reached the exit

        if(currentCell->whatsHere=="Spellbook") //checks if currentCell pointer points to Spellbook
        {
            sp=true; 
        }
        if(currentCell->whatsHere=="Wand") //checks if currentCell pointer points to Wand
        {
            wa=true; 
        }
        if(currentCell->whatsHere=="Potion") //checks if currentCell pointer points to Potion
        {
            po=true; 
        }
        if(sp && wa && po)  
        {
            return true;  //returning true to all sp, wa, and po
        }
        //return currentCell!=nullptr && currentCell->whatsHere.empty() && sp && wa && po;
    }
    return false;
}
