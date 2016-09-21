#include "QUEENS.H"
Queens::Queens(int size)
/* 
 
Post: The Queens object is set up as an empty
configuration on a chessboard with size squares in
each row and column.
 
*/

{
   board_size = size;
   count = 0;
   for (int i = 0; i < board_size; i++) col_free[i] = true;
   for (int j = 0; j < (2 * board_size - 1); j++) upward_free[j] = true;
   for (int k = 0; k < (2 * board_size - 1); k++) downward_free[k] = true;
}
 
void Queens::print() const
{
   int i, j;
   for (i = 0; i < board_size; i++)
      cout << "--";
   cout << "--\n";
   for (i = 0; i < board_size; i++) {
      cout << queen_in_row[i];
      for (j = 0; j < board_size; j++)
         if (j == queen_in_row[i]) cout << " Q";
         else cout << " .";
      cout << endl;
   }
}
 
bool Queens::unguarded(int col) const
/* 
 
Post: Returns true or false according as the square in the first
unoccupied row (row count) and column col is not guarded by any queen.
 
*/

{
   return  col_free[col]
           && upward_free[count + col]
           && downward_free[count - col + board_size - 1];
}
 
void Queens::insert(int col)
/* 
 
Pre:   The square in the first unoccupied row (row count) and column col 
is not guarded by any queen.
Post: A queen has been inserted into the square at row count and column
col; count has been incremented by 1.
 
*/

{
   queen_in_row[count] = col;
   col_free[col] = false;
   upward_free[count + col] = false;
   downward_free[count - col + board_size - 1] = false;
   count++;
}
 
void Queens::remove(int col)
/* 
 
Pre:   There is a queen in the square in row count - 1 and column col.
Post: The above queen has been removed; count has been decremented by 1.
 
*/

{
   count--;
   col_free[col] = true;
   upward_free[count + col] = true;
   downward_free[count - col + board_size - 1] = true;
}
 
void print_information()
{
   cout << "This program determines all the ways to place n queens\n"
        << "on an n by n chessboard, where n <= " << max_board << endl;
}
 
bool Queens::is_solved() const
/* 
 
Post: Returns true if the number of queens
already placed equals board_size, otherwise return false.
 
*/

{
   if (count == board_size) return true;
   else return false;
}
 
void solve_from(Queens &configuration)
/* 
 
Pre: 
The Queens configuration represents a partially completed
arrangement of non-attack-ing queens on a chessboard.
Post:
All n-queens solutions that extend the given configuration 
are printed.
The configuration is restored to its initial state.
Uses:
The class Queens and the function solve_from, recursively.
 
*/

{
   if (configuration.is_solved()) configuration.print();
   else
      for (int col = 0; col < configuration.board_size; col++)
         if (configuration.unguarded(col)) {
            configuration.insert(col);
            solve_from(configuration);   //   Recursively continue to add queens.
            configuration.remove(col);
         }
}
