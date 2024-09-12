#include "Grid.h"
#include <cmath>
#include <set>
#include <iomanip>

Grid::Grid(int r, int c) : rows(r), cols(c), map(r, std::vector<int>(c, 0)) {}

void Grid::setCell(int x, int y, int value) {
    if (isValid(x, y)) {
        map[x][y] = value;
    }
}

int Grid::getCell(int x, int y) const {
    return isValid(x, y) ? map[x][y] : 1;
}

bool Grid::isValid(int x, int y) const {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

bool Grid::isBlocked(int x, int y) const {
    return getCell(x, y) == 1;
}

double Grid::heuristic(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
    // Menggunakan jarak Manhattan sebagai heuristic
    return std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

void Grid::print() const {
    for (const auto& row : map) {
        for (int cell : row) {
            std::cout << (cell == 1 ? "#" : ".") << " ";

        }
        std::cout << std::endl;
    }
}

std::vector<std::pair<int, int>> Grid::findPath(const std::pair<int, int>& start, const std::pair<int, int>& end) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openList;
    std::set<std::pair<int, int>> closedSet;
    openList.emplace(start);

    while (!openList.empty()) {
        Node current = openList.top();
        openList.pop();

        if (current.position == end) {
            std::vector<std::pair<int, int>> path;
            for (Node* p = &current; p != nullptr; p = p->parent) {
                path.push_back(p->position);
            }
            std::reverse(path.begin(), path.end());
            return path;
        }
        closedSet.insert(current.position);

        const std::vector<std::pair<int, int>> directions {{0, 1},{1, 0},{0, -1},{-1, 0}};

        for (const auto& dir : directions) {
            int newX = current.position.first + dir.first;
            int newY = current.position.second + dir.second;
            std::pair<int, int> neighborPos(newX, newY);

            if (!isValid(newX, newY) || isBlocked(newX, newY) || closedSet.count(neighborPos)) {
                continue;
            }

            double gCost = current.gCost + 1.0;
            double hCost = heuristic(neighborPos, end);
            openList.emplace(neighborPos, gCost, hCost, new Node(current));
        }
    }
    return {};
}

void Grid::saveMapToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Tidak dapat membuka file untuk menulis.\n";
        return;
    }
    for (const auto& row : map) {
        for (int cell : row) {
            file << cell << ' ';
        }
        file << '\n';
    }
}

void Grid::loadMapFromFile(const std::string& filename) {
    std::ifstream file (filename);
    if (!file) {
        std::cerr << "Tidak dapat membuka file untuk membaca.\n";
    }
    map.clear();
    rows = cols = 0;

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream ss(line);
        int value;
        while (ss >> value) {
            row.push_back(value);
        }
        if (cols == 0) {
            cols = row.size();
        }
        rows++;
        map.push_back(row);
    }
}
