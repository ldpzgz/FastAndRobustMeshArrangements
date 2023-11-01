#include<iostream>
#include<vector>
#include<bitset>
#include<string>
/*
* 三角化有相交的三角形
*/
bool solveIntersectTriangles(std::vector<double>& in_coords,
    std::vector<unsigned int>& in_tris,
    std::vector<double>& out_coords,
    std::vector<unsigned int>& out_tris);
/*
* 三角化有相交的三角形，label标记三角形属于哪个mesh，
* out_labels标记输出的三角形属于哪个mesh
*/
bool solveIntersectTriangles(std::vector<double>& in_coords,
    std::vector<unsigned int>& in_tris,
    std::vector< std::bitset<32>>& in_labels,
    std::vector<double>& out_coords,
    std::vector<unsigned int>& out_tris,
    std::vector< std::bitset<32>>& out_labels);
