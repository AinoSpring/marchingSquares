//
// Created by ainols on 13.04.23.
//

#ifndef MARCHING_SQUARES_MARCHINGSQUARES_H
#define MARCHING_SQUARES_MARCHINGSQUARES_H

#include <vector>
#include <map>

class MarchingSquares {

private:
    std::map<std::vector<bool>, std::vector<unsigned int>> ConnectionTable;

public:
    unsigned int Width;
    unsigned int Height;
    std::vector<std::vector<float>> Points;
    std::vector<std::vector<unsigned int>> Connections; // 2x scaled up

    MarchingSquares(std::vector<std::vector<float>> Points);
    std::vector<std::vector<unsigned int>> SquareConnections(unsigned int x, unsigned int y);
    void Compute();

};


#endif //MARCHING_SQUARES_MARCHINGSQUARES_H
