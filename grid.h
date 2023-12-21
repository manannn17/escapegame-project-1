//-------------------------------------------------
// TODO:  Write file header.
//-------------------------------------------------
/*
Name: Manan Patel
UIN: 658283328
This project is about a maze where we have to write the code and find the correct maze for 2 strings which are regular maze and twisty maze. In the regular maze, we 
just have to follow the directions and write it on the paper then it will automatically gives us the correct string where as the twisty one is time consuming. In that
we have to write the address of each directions and it will connect with different directions. Like North connects with North. In the end we will get 2 correct strings 
that will find 3 magical items which are spellbook, wand, and potion.  
*/
//-------------------------------------------------
// TODO:  Update the member function comments in 
//        your own style.
//-------------------------------------------------

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename T>
class Grid {
private:
  struct ROW {
    T*  Cols;     // array of column elements
    size_t NumCols;  // total # of columns (0..NumCols-1)
  };

  ROW* Rows;     // array of ROWs
  size_t  NumRows;  // total # of rows (0..NumRows-1)
    
public:
  //
  // default constructor:
  //
  // Called automatically by to construct a 4x4 Grid. 
  // All elements initialized to default value of T.
  //
  Grid() {
    Rows = new ROW[4];  // 4 rows
    NumRows = 4;

    // initialize each row to have 4 columns:
    for (size_t r = 0; r < NumRows; ++r) {
      Rows[r].Cols = new T[4];
      Rows[r].NumCols = 4;

      // initialize the elements to their default value:
      for (size_t c = 0; c < Rows[r].NumCols; ++c) {
        Rows[r].Cols[c] = T();  // default value for type T:
      }
    }
  }

  //
  // parameterized constructor:
  //
  // Called automatically to construct a Grid 
  // with R rows, where each row has C columns. 
  // All elements initialized to default value of T.
  //
  Grid(size_t R, size_t C) {
    //-------------------------------------------------
    // TODO:  Write this parameterized constructor.
    //-------------------------------------------------
    if(R<1) //checks if R is less than 1 or not
    {
        throw invalid_argument("Grid::constructor: # of rows must be at least 1");  //if it is then it shows the number of rows
    }
    if(C<1) //checks if C is less than 1 or not
    {
        throw invalid_argument("Grid::constructor: # of columns must be at least 1");  //if it is then it shows the number of columns
    }
    NumRows=R;
    Rows=new ROW[R];

    for(size_t r=0;r<R;r++)   //checks the size of r also it checks if r is less than NumRows or not
    {
        Rows[r].Cols=new T[C];  //assigns T to the Rows[r].Cols
        Rows[r].NumCols=C;  //Assigns new character C to Rows[r].NumCols

        for(size_t c=0;c<C;c++)   //nested loop runs over the columns with rows
        {
            Rows[r].Cols[c]=T();  //it initializes with T()
        }
    }
  }
    
  //
  // destructor:
  //
  // Called automatically to free memory for this Grid.
  //
  virtual ~Grid() {

      //-------------------------------------------------
      // TODO:  Write this destructor.
      //-------------------------------------------------

    for (size_t r=0;r<NumRows;r++)   //A loop iterates over each row in the current object
    {
        delete[] Rows[r].Cols;  //it deallocates the memory for the character array associated with the current row
    }
    delete[] Rows;  //this frees the memory associated with the array of ROW
  }


  //
  // copy constructor:
  //
  // Called automatically to construct a Grid that contains a
  // copy of an existing Grid.  Example: this occurs when passing
  // Grid as a parameter by value
  //
  //   void somefunction(Grid<int> G2)  <--- G2 is a copy:
  //   { ... }
  //
  Grid(const Grid<T>& other) {
      
      //-------------------------------------------------
      // TODO:  Write this copy constructor.
      //-------------------------------------------------
    
    NumRows=other.NumRows;  //assigns other.NumRows to NumRows
    Rows=new ROW[other.NumRows];  //allocates the new memory for the array of row 

    for(size_t r=0;r<NumRows;r++)   //checks the size of r and checks if it is less than 
    {
        //size_t other_numcols=other.Rows[r].NumCols; //it checks the number of columns in the current row to other 
        Rows[r].NumCols=other.Rows[r].NumCols;    // assigns the other_numcols to the property of NumCols
        Rows[r].Cols=new T[Rows[r].NumCols];    //this allocates memory for a new array of character

        for(size_t c=0;c<Rows[r].NumCols;c++)   //nested loop runs over the columns with rows
        {
            Rows[r].Cols[c]=other.Rows[r].Cols[c];  //it copies the character value from other objects row and column to letterGrind
        }
    }
  }
    
  //
  // copy operator=
  //
  // Called when one Grid is assigned into another, i.e. this = other;
  //
  Grid& operator=(const Grid& other) {
      //Grid<T> temp;
      
      //-------------------------------------------------
      // TODO:  Write this copy operator.
      //-------------------------------------------------
    
    if(this==&other)  //checks whether the current object this is the same as the other object.
    {
        return *this;
    }
    
    for(size_t r=0;r<NumRows;r++)  //A loop iterates over each row in the current object 
    {
        delete[] Rows[r].Cols;  //it deallocates the memory for the character array associated with the current row
    }
    delete[] Rows;  //this frees the memory associated with the array of ROW 
    
    NumRows = other.NumRows;  //it sets the property of NumRows to letterGrind
    Rows = new ROW[NumRows];  //it allocates memory for a new array of ROW
    
    for(size_t r=0;r<NumRows;r++) // loop to copy each row and column from the other object
    {
        //size_t other_numcols = other.Rows[r].NumCols;  
        
        Rows[r].NumCols=other.Rows[r].NumCols;
        Rows[r].Cols=new T[Rows[r].NumCols];
        
        for(size_t c=0;c<Rows[r].NumCols;c++) 
        {
            Rows[r].Cols[c]=other.Rows[r].Cols[c];
        }
    }
    return *this;  //returns the reference to *this  
  }

  //
  // numrows
  //
  // Returns the # of rows in the Grid.  
  // The indices for these rows are 0..numrows-1.
  //
  size_t numrows() const {
      
    //-------------------------------------------------
    // TODO:  Write this function.
    //-------------------------------------------------
        
    return NumRows;  // Returning NumRows since the function chcekc the size of it
  }
  

  //
  // numcols
  //
  // Returns the # of columns in row r.  
  // The indices for these columns are 0..numcols-1.  
  // For now, each row has the same number of columns.
  //
  size_t numcols(size_t r) const {
      
      //-------------------------------------------------
      // TODO:  Write this function.
      //-------------------------------------------------
      
    if(r>=NumRows)   //maybe it should be r>=numrows 
    {
        throw out_of_range("Invalid row index");
    }
    return Rows[r].NumCols;
  }


  //
  // size
  //
  // Returns the total # of elements in the Grid.
  //
  size_t size() const {
      
      //-------------------------------------------------
      // TODO:  Write this function.
      //-------------------------------------------------
      
    size_t totalSize=0;
    for(size_t r=0;r<NumRows;r++) 
    {
        totalSize+=Rows[r].NumCols;
    }
    return totalSize;
  }


  //
  // ()
  //
  // Returns a reference to the element at location (r, c);
  // this allows you to access or assign the element:
  //
  //    grid(r, c) = ...
  //    cout << grid(r, c) << endl;
  //
  T& operator()(size_t r, size_t c) {
      //T temp;
      
    
      //-------------------------------------------------
      // TODO:  Write the parentheses overloaded operator
      //-------------------------------------------------
    if(r<NumRows && c<Rows[r].NumCols)
    {
        return Rows[r].Cols[c];
    }
    else
    {
        throw std::out_of_range("Invalid indices");
    }
  }

  //
  // _output
  //
  // Outputs the contents of the grid; for debugging purposes.  
  // This is not tested.
  //
  void _output() {

      //-------------------------------------------------
      // TODO:  Write this function.
      //-------------------------------------------------
    for(size_t r=0;r<NumRows;r++)  //loop that finds each row of the grid with NumRows
    {
        for(size_t c=0;c<Rows[r].NumCols;c++)  //nested loop iterates through each column within the current row
        {
            cout<<Rows[r].Cols[c]<< " "; //it prints the character at the r, c position in the grid. it also adds '|' and spaces
        }
        cout << endl;
    }    
  }

};
