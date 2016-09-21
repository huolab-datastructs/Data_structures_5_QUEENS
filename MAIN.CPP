#include "QUEENS.H"
 
void main()
/* 
 
Pre:  The user enters a valid board size.
Post: All solutions to the n-queens puzzle for the selected
board size are printed.
Uses: The class Queens and the recursive function solve_from.
 
*/
{
   int board_size;
   print_information();
   cout << "What is the size of the board? " << flush;
   cin  >> board_size;
   if (board_size < 0 || board_size > max_board)
      cout << "The number must be between 0 and " << max_board << endl;
   else {
      Queens configuration(board_size); //   Initialize empty configuration.
      solve_from(configuration);  //  Find all solutions extending configuration.
   }
}
