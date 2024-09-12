#pragma once
#include <utility>

class Node {
public:
    std::pair<int, int> position;  // Koordinat (x, y) di dalam grid
    double gCost;                  // Biaya jalan dari titik awal ke node ini
    double hCost;                  // Perkiraan biaya dari node ini ke tujuan (heuristic)
    Node* parent;                  // Node induk untuk rekonstruksi jalur

    Node(const std::pair<int, int>& pos, double g = 0.0, double h = 0.0, Node* p = nullptr)
        : position(pos), gCost(g), hCost(h), parent(p) {}

    double getFCost() const { return gCost + hCost; }

    // Operator perbandingan untuk menentukan urutan prioritas (untuk priority_queue)
    bool operator>(const Node& other) const {
        return getFCost() > other.getFCost();
    }
};
