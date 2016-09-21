#include "../../C/UTILITY.H"
const int max_board = 30;
 
class Queens {
public:
   Queens(int size);
   bool is_solved() const;
   void print() const;
   bool unguarded(int col) const;
   void insert(int col);
   void remove(int col);
   int board_size;
private:
   int  count;
   bool col_free[max_board];
   bool upward_free[2 * max_board - 1];
   bool downward_free[2 * max_board - 1];
   int  queen_in_row[max_board];  //   column number of queen in each row
};

void print_information();
void solve_from(Queens &configuration);