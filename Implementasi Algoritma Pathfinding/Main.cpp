#include "Grid.h"

int main(int argc, char const *argv[])
{
    int rows, cols;
    std::cout << "Masukkan jumlah baris dan kolom peta: ";
    std::cin >> rows >> cols;
    std::cin.ignore();

    Grid grid(rows, cols);

    std::cout << "Masukkan peta (0 untuk terbuka, 1 untuk tertutup): \n";

    for (int i = 0; i < rows; ++i) {
        std::string line;
        std::getline(std::cin, line);

        for (int j = 0; j < cols; ++j) {
            if (j < line.length()) {
                int value = line[j] - '0';
                grid.setCell(i, j, value);
            }
        }
    }

    int startX, startY, endX, endY;
    std::cout << "Masukkan koordinat titik awal (x y): ";
    std::cin >> startX >> startY;
    std::cout << "Masukkan koordinat titik tujuan (x y): ";
    std::cin >> endX >> endY;

    std::pair<int, int> start = {startX, startY};
    std::pair<int, int> end = {endX, endY};

    std::vector<std::pair<int, int>> path = grid.findPath(start, end);

    if (!path.empty()) {
        std::cout << "jalur terpendek ditemukan:\n";
        for (const auto& [x, y] : path) {
            std::cout << "(" << x << ", " << y << ") ";
        }
        std::cout << std::endl;
    grid.print();
    } else {
        std::cout << "Tidak ada jalur yang ditemukan dari titik awal ke titk tujuan.\n";
    }

    
    return 0;
}
