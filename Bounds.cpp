//
// Created by ainols on 14.04.23.
//

#include "Bounds.h"
#include <vector>
#include <cmath>

Line ComputeLine(float x1, float y1, float x2, float y2) {

    float offset = (x1 * y2 - y1 * x2) / x1 - x2;
    float slope;
    if (y1 == y2) {

        slope = INFINITY;

    } else {

        if (x1 != 0) {

            slope = (y1 - offset) / x1;

        } else if (x2 != 0) {

            slope = (y2 - offset) / x2;

        } else {

            slope = 0;

        }

    }

    return {x1, y1, x2, y2, slope, offset};

}

float LineEqualsX(Line Line, float x) {

    return Line.slope * x + Line.offset;

}

float LineEqualsY(Line Line, float y) {

    if (Line.slope == 0) {

        return INFINITY;

    }

    return (Line.offset - y) / Line.slope;

}

Bounds::Bounds(std::vector<Line> Lines)
: Lines(Lines) {



}

bool Bounds::InBounds(float x, float y) {

    unsigned int xCount;
    unsigned int yCount;

    for (unsigned int i = 0; i < Lines.size(); i++) {

        if (LineEqualsX(Lines[i], x) >= y || (Lines[i].slope == INFINITY && Lines[i].x1 == x)) {

            yCount++;

        }

        if (LineEqualsY(Lines[i], y) >= x || (Lines[i].slope == 0 && Lines[i].offset == y)) {

            xCount++;

        }

    }

    return xCount % 2 == 1 && yCount % 2 == 1;

}