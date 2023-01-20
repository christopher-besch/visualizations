#pragma once

#include <limits>
#include <set>
#include <sstream>
#include <vector>

#define prt(x) Godot::print(String((std::stringstream() << x).str().c_str()))

using adjacency_list  = std::vector<std::set<int>>;
using distance_matrix = std::vector<std::vector<int>>;

constexpr float     finf  = std::numeric_limits<float>::max() / 2;
constexpr double    dinf  = std::numeric_limits<double>::max() / 2;
constexpr int       iinf  = std::numeric_limits<int>::max() / 2;
constexpr long      linf  = std::numeric_limits<long>::max() / 2;
constexpr long long llinf = std::numeric_limits<long long>::max() / 2;
