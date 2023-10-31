/*****************************************************************************************
 *              MIT License                                                              *
 *                                                                                       *
 * Copyright (c) 2020 Gianmarco Cherchi, Marco Livesu, Riccardo Scateni e Marco Attene   *
 *                                                                                       *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this  *
 * software and associated documentation files (the "Software"), to deal in the Software *
 * without restriction, including without limitation the rights to use, copy, modify,    *
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to    *
 * permit persons to whom the Software is furnished to do so, subject to the following   *
 * conditions:                                                                           *
 *                                                                                       *
 * The above copyright notice and this permission notice shall be included in all copies *
 * or substantial portions of the Software.                                              *
 *                                                                                       *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,   *
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A         *
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT    *
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION     *
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE        *
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                *
 *                                                                                       *
 * Authors:                                                                              *
 *      Gianmarco Cherchi (g.cherchi@unica.it)                                           *
 *      https://people.unica.it/gianmarcocherchi/                                        *
 *                                                                                       *
 *      Marco Livesu (marco.livesu@ge.imati.cnr.it)                                      *
 *      http://pers.ge.imati.cnr.it/livesu/                                              *
 *                                                                                       *
 *      Riccardo Scateni (riccardo@unica.it)                                             *
 *      https://people.unica.it/riccardoscateni/                                         *
 *                                                                                       *
 *      Marco Attene (marco.attene@ge.imati.cnr.it)                                      *
 *      https://www.cnr.it/en/people/marco.attene/                                       *
 *                                                                                       *
 * ***************************************************************************************/

#ifdef _MSC_VER // Workaround for known bugs and issues on MSVC
#define _HAS_STD_BYTE 0  // https://developercommunity.visualstudio.com/t/error-c2872-byte-ambiguous-symbol/93889
#define NOMINMAX // https://stackoverflow.com/questions/1825904/error-c2589-on-stdnumeric-limitsdoublemin
#endif

#include <iostream>

#include "solve_intersections.h"
#include "io_functions.h"
#include "meshArrangement.h"
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

int main(int argc, char **argv)
{
    /*std::string filename;

    if(argc > 1)
        filename = argv[1];
    else
    {
        std::cout << "input file missing" << std::endl;
        return -1;
    }*/
    //solveIntersection
    std::vector<double> in_coords{0,0,0,
        2,0,0,
        1,2,0,
        1,0.3,-0.5,
        1.1,0.3,1,
        0.9,0.3,1
    };
    std::vector<double> out_coords;
    std::vector<uint> in_tris{0,1,2,3,4,5};
    std::vector<std::bitset<32>> in_labels{0x01,0x02};
    std::vector<uint> out_tris;
    std::vector<std::bitset<32>> out_labels;
    std::vector<genericPoint*> gen_points;
    point_arena arena;

    std::cout<<"solve start\n";
    solveIntersectTriangles(in_coords,in_tris,in_labels,out_coords,out_tris,out_labels);
    std::cout<<"solve end\n";
    std::cout<<out_tris.size()<<","<<out_coords.size()<<","<<out_labels.size()<<std::endl;
    for (int i = 0; i < out_tris.size() / 3; ++i) {
        std::cout<<"p1:"<<out_coords[3*out_tris[i * 3]]<<","
            <<out_coords[3*out_tris[i * 3]+1]<<","
            <<out_coords[3*out_tris[i * 3]+2]<<std::endl;
        std::cout<<"p2:"<<out_coords[3*out_tris[i * 3+1]]<<","
            <<out_coords[3*out_tris[i * 3+1]+1]<<","
            <<out_coords[3*out_tris[i * 3+1]+2]<<std::endl;
        std::cout<<"p3:"<<out_coords[3*out_tris[i * 3+2]]<<","
            <<out_coords[3*out_tris[i * 3+2]+1]<<","
            <<out_coords[3*out_tris[i * 3+2]+2]<<std::endl;
        std::cout<<"label:"<<out_labels[i] << std::endl;
    }
    return 0;
    //load(filename, in_coords, in_tris);

    ///*-------------------------------------------------------------------
    // * There are 4 versions of the solveIntersections function. Please
    // * refer to the solve_intersections.h file to see how to use them. */

    //solveIntersections(in_coords, in_tris, arena, gen_points, out_tris);

    //computeApproximateCoordinates(gen_points, out_coords);
    //
    //save("output.obj", out_coords, out_tris);

    return 0;
}



