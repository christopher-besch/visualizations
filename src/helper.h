#pragma once

#include <set>
#include <sstream>
#include <vector>

#define prt(x) Godot::print(String((std::stringstream("") << x).str().c_str()))

using adjacency_list = std::vector<std::set<int>>;
