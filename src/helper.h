#pragma once

#include <limits>
#include <set>
#include <sstream>
#include <vector>

#define prt(x) Godot::print(String((std::stringstream("") << x).str().c_str()))

using adjacency_list = std::vector<std::set<int>>;
constexpr float finf = std::numeric_limits<float>::max();
