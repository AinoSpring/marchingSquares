//
// Created by ainols on 13.04.23.
//

#include "MarchingSquares.h"

MarchingSquares::MarchingSquares(std::vector<std::vector<float>> Points)
: Points(Points), Width(Points.size()), Height(Points[0].size()) {

    //  TOP      LEFT,   TOP     RIGHT,
    //  BOTTOM   Left,   BOTTOM  RIGHT

    ConnectionTable[{false, false, false, false}] = {};

    ConnectionTable[{false, false, false, true}] = {2, 3};
    ConnectionTable[{false, false, true, false}] = {1, 3};
    ConnectionTable[{false, true, false, false}] = {0, 2};
    ConnectionTable[{true, false, false, false}] = {0, 1};

    ConnectionTable[{false, false, true, true}] = {1, 2};
    ConnectionTable[{true, false, true, false}] = {0, 3};
    ConnectionTable[{true, true, false, false}] = {1, 2};
    ConnectionTable[{false, true, false, true}] = {0, 3};

    ConnectionTable[{true, false, false, true}] = {0, 2, 1, 3};
    ConnectionTable[{false, true, true, false}] = {0, 1, 2, 3};

    ConnectionTable[{false, true, true, true}] = {0, 1};
    ConnectionTable[{true, false, true, true}] = {0, 2};
    ConnectionTable[{true, true, false, true}] = {1, 3};
    ConnectionTable[{true, true, true, false}] = {2, 3};

}

std::vector<std::vector<unsigned int>> MarchingSquares::SquareConnections(unsigned int x, unsigned int y) {

    std::vector<std::vector<unsigned int>> ComputedConnections;

    std::vector<std::vector<unsigned int>> ConnectionCoordinates = {
            {1, 0},
            {0, 1},
            {2, 1},
            {1, 2}
    };


    std::vector<bool> Square = {
            Points[x][y] > 0,
            Points[x + 1][y] > 0,
            Points[x][y + 1] > 0,
            Points[x + 1][y + 1] > 0
    };

    std::vector<unsigned int> SquareConnections = ConnectionTable[Square];

    for (unsigned int i = 0; i < SquareConnections.size(); i += 2) {

        ComputedConnections.push_back({ConnectionCoordinates[SquareConnections[i]][0] + (2 * x), ConnectionCoordinates[SquareConnections[i]][1] + (2 * y)});
        ComputedConnections.push_back({ConnectionCoordinates[SquareConnections[i + 1]][0] + (2 * x), ConnectionCoordinates[SquareConnections[i + 1]][1] + (2 * y)});

    }

    return ComputedConnections;

}

void MarchingSquares::Compute() {


    for (unsigned int x = 0; x < Width - 1; x++) {

        for (unsigned int y = 0; y < Height - 1; y++) {


            std::vector<std::vector<unsigned int>> ComputedConnections = SquareConnections(x, y);

            for (unsigned int i = 0; i < ComputedConnections.size(); i++) {

                Connections.push_back(ComputedConnections[i]);

            }

        }

    }

}