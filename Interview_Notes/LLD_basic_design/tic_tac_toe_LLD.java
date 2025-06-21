// Represents a cell in the Tic-Tac-Toe board
class Cell {
    private int row;
    private int col;
    private char symbol;  // 'X', 'O', or empty (' ')

    // Constructor
    public Cell(int row, int col) {
        this.row = row;
        this.col = col;
        this.symbol = ' ';  // Initially empty
    }

    // Getters and Setters
    public int getRow() {
        return row;
    }

    public int getCol() {
        return col;
    }

    public char getSymbol() {
        return symbol;
    }

    public void setSymbol(char symbol) {
        this.symbol = symbol;
    }
}

// Represents the Tic-Tac-Toe board
class Board {
    private Cell[][] grid;  // 2D array of cells
    private int size;       // Size of the board (3 for 3x3)

    // Constructor
    public Board(int size) {
        this.size = size;
        grid = new Cell[size][size];

        // Initialize each cell in the grid
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = new Cell(i, j);
            }
        }
    }

    // Places a symbol on the board
    public boolean placeSymbol(int row, int col, char symbol) {
        if (grid[row][col].getSymbol() == ' ') { // Check if the cell is empty
            grid[row][col].setSymbol(symbol);
            return true;
        }
        return false;
    }

    // Checks if there is a winner
    public boolean checkWin(char symbol) {
        // Check rows, columns, and diagonals for a win
        return (checkRows(symbol) || checkColumns(symbol) || checkDiagonals(symbol));
    }

    // Helper methods to check rows, columns, and diagonals
    private boolean checkRows(char symbol) {
        for (int i = 0; i < size; i++) {
            boolean win = true;
            for (int j = 0; j < size; j++) {
                if (grid[i][j].getSymbol() != symbol) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
        return false;
    }

    private boolean checkColumns(char symbol) {
        for (int i = 0; i < size; i++) {
            boolean win = true;
            for (int j = 0; j < size; j++) {
                if (grid[j][i].getSymbol() != symbol) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
        return false;
    }

    private boolean checkDiagonals(char symbol) {
        boolean win = true;
        for (int i = 0; i < size; i++) {
            if (grid[i][i].getSymbol() != symbol) {
                win = false;
                break;
            }
        }
        if (win) return true;

        win = true;
        for (int i = 0; i < size; i++) {
            if (grid[i][size - i - 1].getSymbol() != symbol) {
                win = false;
                break;
            }
        }
        return win;
    }

    // Checks if the board is full (i.e., no empty cells)
    public boolean isFull() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j].getSymbol() == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    // Display the board (for visual representation)
    public void displayBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(grid[i][j].getSymbol() + " ");
            }
            System.out.println();
        }
    }
}

// Represents a player in the Tic-Tac-Toe game
class Player {
    private String name;
    private char symbol;  // 'X' or 'O'

    // Constructor
    public Player(String name, char symbol) {
        this.name = name;
        this.symbol = symbol;
    }

    // Getters
    public String getName() {
        return name;
    }

    public char getSymbol() {
        return symbol;
    }
}

// Manages the overall game flow
class Game {
    private Board board;
    private Player player1;
    private Player player2;
    private Player currentPlayer;

    // Constructor
    public Game(Player player1, Player player2, int boardSize) {
        this.player1 = player1;
        this.player2 = player2;
        this.board = new Board(boardSize);
        this.currentPlayer = player1;  // Player 1 starts the game
    }

    // Main game loop
    public void start() {
        while (true) {
            board.displayBoard();
            System.out.println(currentPlayer.getName() + "'s turn (" + currentPlayer.getSymbol() + "). Enter row and column: ");
            // For simplicity, using console input (not included here)
            // Assume valid input for row and col
            int row = /* ... */;
            int col = /* ... */;
            
            if (board.placeSymbol(row, col, currentPlayer.getSymbol())) {
                if (board.checkWin(currentPlayer.getSymbol())) {
                    board.displayBoard();
                    System.out.println(currentPlayer.getName() + " wins!");
                    break;
                } else if (board.isFull()) {
                    board.displayBoard();
                    System.out.println("It's a draw!");
                    break;
                } else {
                    // Switch turns
                    currentPlayer = (currentPlayer == player1) ? player2 : player1;
                }
            } else {
                System.out.println("Cell is already occupied. Try again.");
            }
        }
    }
}
