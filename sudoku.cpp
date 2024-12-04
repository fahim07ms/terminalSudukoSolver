// Program for solving sudoku

#include <iostream>

using namespace std;

// Global variables
const int N = 9;

// Sudoku grid
int sudokuGrid[N][N];

//Prototypes
void get_sudoku_grid();
void print_grid();
bool isValid(int row, int column, int possible_solution);
bool find_unassigned_value(int &row, int &col);
bool solve();
void print_solution();


int main(void)
{
    // Getting sudoku grid from user
    cout << "Enter the " << N << "*" << N << " Sudoku grid(Use 0 for empty cells):\n";
    get_sudoku_grid();

    // Print grid
    print_grid();

    // Solve grid
    if (solve() == true)
    {
        // Printing the solution grid
        print_solution();
    }


}

// Function;for getting sudoku grid
void get_sudoku_grid()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> sudokuGrid[i][j];
        }
    }
}

// The number is valid in the cell or not
bool isValid(int row, int column, int possible_solution)
{
    bool row_validity = true;
    bool column_validity = true;
    bool grid_validity = true;

    // Checking in the column
    for (int i = 0; i < N; i++)
    {
        if (sudokuGrid[i][column] == possible_solution)
        {
            column_validity = false;
            break;
        }

    }

    // Checking in the row
    for (int j = 0; j < N; j++)
    {
        if (sudokuGrid[row][j] == possible_solution)
        {
            row_validity = false;
            break;
        }

    }

    // Grid validity
    row = row - (row%3);
    column = column - (column%3);

    for (int ii = row; ii < (row+3); ii++)
    {
        for (int jj = column; jj < (column+3); jj++)
        {
            if (sudokuGrid[ii][jj] == possible_solution)
            {
                grid_validity = false;
                break;
            }
        }
    }

    if (row_validity == true && column_validity == true && grid_validity == true)
    {
        return true;
    }

    return false;
}

// Function for printing grid
void print_grid()
{
    cout << "\n\nProblem:\n\n";

    for (int i = 0; i < N; i++)
    {
        // Print first row of drawing
        if (i == 0)
        {
            for (int j = 0; j < ((N*2)+1); j++)
            {
                if (j == 0 || j == (N*2))
                {
                    cout << "+";
                }
                else
                {
                    cout << "-";
                }
            }
            cout << "\n";
        }

        // Print the numbers
        for (int j = 0; j < N; j++)
        {
            if (j%3 == 0)
            {
                if (sudokuGrid[i][j] == 0)
                    cout << "|" <<  "  ";
                else
                    cout << "|" << sudokuGrid[i][j] << " ";
            }
            else if (j%3 == 1)
            {
                if (sudokuGrid[i][j] == 0)
                    cout << "  ";
                else
                    cout << sudokuGrid[i][j] << " ";
            }
            else
            {
                if (sudokuGrid[i][j] == 0)
                    cout << " ";
                else
                    cout << sudokuGrid[i][j];
            }

            if (j == (N-1))
            {
                cout << "|";
            }
        }

        cout << "\n";

        // Print last row of drawing
        if (i == (N-1))
        {
            for (int j = 0; j < ((N*2)+1); j++)
            {
                if (j == 0 || j == (N*2))
                {
                    cout << "+";
                }
                else
                {
                    cout << "-";
                }
            }
            cout << "\n";
        }
        // Print rows of drawing except 1st and last
        else
        {
            for (int j = 0; j < ((N*2)+1); j++)
            {
                if (i%3 == 2)
                {
                    cout << "-";
                }
            }
            if (i%3 == 2)
            {
                cout << "\n";
            }
        }

    }
}

bool find_unassigned_value(int &row, int &col)
{
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (sudokuGrid[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

// Solve the grid
bool solve()
{
    int row, col;

    if (!find_unassigned_value(row, col))
    {
        return true;
    }

    for (int k = 1; k <= N; k++)
    {
        if (isValid(row, col, k))
        {
            sudokuGrid[row][col] = k;
            if (solve())
            {
                return true;
            }
            sudokuGrid[row][col] = 0;
        }


    }

    return false;
}

// Function for printing grid
void print_solution()
{
    cout << "\n\nSolution:\n\n";

    for (int i = 0; i < N; i++)
    {
        // Print first row of drawing
        if (i == 0)
        {
            for (int j = 0; j < ((N*2)+1); j++)
            {
                if (j == 0 || j == (N*2))
                {
                    cout << "+";
                }
                else
                {
                    cout << "-";
                }
            }
            cout << "\n";
        }

        // Print the numbers
        for (int j = 0; j < N; j++)
        {
            if (j%3 == 0)
            {
                cout << "|" << sudokuGrid[i][j] << " ";
            }
            else if (j%3 == 1)
            {
                cout << sudokuGrid[i][j] << " ";
            }
            else
            {
                cout << sudokuGrid[i][j];
            }

            if (j == (N-1))
            {
                cout << "|";
            }
        }

        cout << "\n";

        // Print last row of drawing
        if (i == (N-1))
        {
            for (int j = 0; j < ((N*2)+1); j++)
            {
                if (j == 0 || j == (N*2))
                {
                    cout << "+";
                }
                else
                {
                    cout << "-";
                }
            }
            cout << "\n";
        }
        // Print rows of drawing except 1st and last
        else
        {
            for (int j = 0; j < ((N*2)+1); j++)
            {
                if (i%3 == 2)
                {
                    cout << "-";
                }
            }
            if (i%3 == 2)
            {
                cout << "\n";
            }
        }

    }
}