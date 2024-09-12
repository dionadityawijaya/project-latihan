#include <iostream>
#include <vector>
#include <limits> // Untuk std::numeric_limits

using namespace std;

const int BOARD_SIZE = 3;
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

// Fungsi untuk mencetak papan permainan
void printBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j];
            if (j < BOARD_SIZE - 1) cout << " | ";
        }
        if (i < BOARD_SIZE - 1) cout << "\n---------\n";
    }
    cout << "\n";
}

// Fungsi untuk memeriksa apakah ada pemain yang menang
bool checkWin(const vector<vector<char>>& board, char player) {
    // Memeriksa baris dan kolom
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // Memeriksa diagonal
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}

// Fungsi untuk memeriksa apakah permainan seri
bool isDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY) return false;
        }
    }
    return true;
}

// Fungsi untuk menginput posisi dari pemain
pair<int, int> getPlayerMove(char currentPlayer) {
    int row, col;
    while (true) {
        cout << "Pemain " << currentPlayer << ", masukkan baris (0-2) dan kolom (0-2): ";
        cin >> row >> col;

        // Validasi input untuk memastikan pemain memasukkan angka
        if (cin.fail() || row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            cout << "Input tidak valid. Masukkan angka antara 0-2.\n";
            cin.clear(); // Menghapus flag error dari cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membuang input yang salah
        } else {
            break; // Keluar dari loop jika input valid
        }
    }
    return {row, col};
}

// Fungsi utama untuk menjalankan permainan
void playGame() {
    vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY));
    char currentPlayer = PLAYER_X;
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);
        auto [row, col] = getPlayerMove(currentPlayer);

        if (board[row][col] == EMPTY) {
            board[row][col] = currentPlayer;
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Pemain " << currentPlayer << " menang!\n";
                gameOver = true;
            } else if (isDraw(board)) {
                printBoard(board);
                cout << "Permainan seri!\n";
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
            }
        } else {
            cout << "Posisi sudah terisi. Coba lagi.\n";
        }
    }
}

// Fungsi utama program
int main() {
    char playAgain;
    do {
        playGame();
        cout << "Apakah Anda ingin bermain lagi? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
