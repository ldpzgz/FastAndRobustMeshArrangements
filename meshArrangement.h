#include<iostream>
#include<vector>
#include<bitset>
#include<string>
#include<functional>
#define NBIT 32
enum BoolOp {UNION, INTERSECTION, SUBTRACTION, XOR, NONE};
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
    std::vector< std::bitset<NBIT>>& in_labels,
    std::vector<double>& out_coords,
    std::vector<unsigned int>& out_tris,
    std::vector< std::bitset<NBIT>>& out_labels);

void setAnotherSolver(std::function<bool(std::vector<double>&,
                   std::vector<unsigned int>&,
                   std::vector<std::bitset<NBIT>>&,
                   std::vector<double>&,
                   std::vector<unsigned int>&,
                   std::vector<std::bitset<NBIT>>&)>& func);

void booleanPipeline(const std::vector<double> &in_coords, const std::vector<unsigned int> &in_tris,
                            const std::vector<unsigned int> &in_labels, const BoolOp &op, std::vector<double> &bool_coords,
                            std::vector<unsigned int> &bool_tris, std::vector< std::bitset<NBIT> > &bool_labels);

void writeObj(const std::string& fn,const std::vector<double> &in_coords, const std::vector<unsigned int> &in_tris);