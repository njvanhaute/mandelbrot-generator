//
//  helperfunctions.cpp
//  MandelbrotGenerator
//
//  Created by Nicholas Vanhaute on 11/24/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include "helperfunctions.hpp"

double dist(double x1, double y1, double x2, double y2) {
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;
}
