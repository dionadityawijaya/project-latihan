#include "Node.h"
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

class Grid {
    private:
        std::vector<std::vector<int>> map;
        int rows, cols;

        bool isValid(int x, int y) const;
        bool isBlocked(int x, int y) const;
        double heuristic(const std::pair<int, int>& a, const std::pair<int, int>& ) const;

    public:
        Grid(int r, int c);
        void setCell(int x, int y, int value);
        int getCell(int x, int y) const;
        void print() const;
        std::vector<std::pair<int, int>> findPath(const std::pair<int, int>& start, const std::pair<int, int>& end);
        void saveMapToFile(const std::string& filename) const;
        void loadMapFromFile(const std::string& filename);


};