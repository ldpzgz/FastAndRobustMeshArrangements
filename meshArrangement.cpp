/*****************************************************************************************
 *              MIT License                                                              *
 *                                                                                       *
 * Copyright (c) 2022 G. Cherchi, F. Pellacini, M. Attene and M. Livesu                  *
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
 *      https://www.gianmarcocherchi.com                                                 *
 *                                                                                       *
 *      Fabio Pellacini (fabio.pellacini@uniroma1.it)                                    *
 *      https://pellacini.di.uniroma1.it                                                 *
 *                                                                                       *
 *      Marco Attene (marco.attene@ge.imati.cnr.it)                                      *
 *      https://www.cnr.it/en/people/marco.attene/                                       *
 *                                                                                       *
 *      Marco Livesu (marco.livesu@ge.imati.cnr.it)                                      *
 *      http://pers.ge.imati.cnr.it/livesu/                                              *
 *                                                                                       *
 * ***************************************************************************************/
#define NOMINMAX
#ifdef _HAS_STD_BYTE
#undef _HAS_STD_BYTE
#endif
#define _HAS_STD_BYTE 0

#include "solve_intersections.h"
#include <cinolib/io/write_OBJ.h>

#ifdef WIN32
#define EXPORT_INTERFACE __declspec(dllexport)
#else
#define EXPORT_INTERFACE
#endif

bool EXPORT_INTERFACE solveIntersectTriangles(std::vector<double>& in_coords,
    std::vector<uint>& in_tris,
    std::vector<double>& out_coords,
    std::vector<uint>& out_tris)
{
    point_arena arena;
    std::vector<genericPoint*> vertices;
    std::vector< std::bitset<NBIT>> tmp_in_labels(in_tris.size() / 3), out_labels;

    bool b = meshArrangementPipeline(in_coords, in_tris, tmp_in_labels, arena, vertices, out_tris, out_labels);
    if(!b){
        return b;
    }
    computeApproximateCoordinates(vertices, out_coords);
    //freePointsMemory(vertices);
    return b;
}

bool EXPORT_INTERFACE solveIntersectTriangles(std::vector<double>& in_coords,
    std::vector<uint>& in_tris,
    std::vector< std::bitset<32>>& in_labels,
    std::vector<double>& out_coords,
    std::vector<uint>& out_tris,
    std::vector< std::bitset<32>>& out_labels)
{
    point_arena arena;
    std::vector<genericPoint*> vertices;

    bool b = meshArrangementPipeline(in_coords, in_tris, in_labels, arena, vertices, out_tris, out_labels);
    if(!b){
        return b;
    }
    computeApproximateCoordinates(vertices, out_coords);
    //freePointsMemory(vertices);
    return b;
}

void writeObj(const std::string& fn,const std::vector<double> &in_coords, const std::vector<unsigned int> &in_tris){
    std::vector<std::vector<uint>> poly;
    for(int i=0; i<in_tris.size(); i+=3){
        std::vector<uint> p;
        p.push_back(in_tris[i]);
        p.push_back(in_tris[i+1]);
        p.push_back(in_tris[i+2]);
        poly.emplace_back(p);
    }
    cinolib::write_OBJ(fn.c_str(),in_coords,poly);
}

#include"booleans.h"