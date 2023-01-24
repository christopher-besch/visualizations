#include "warshall.h"

using namespace godot;

void Warshall::next_k()
{
    int n = m_graph->get_adj().size();
    int cur_k {m_k};
    while(m_k < n) {
        next_path_without_next_slide();
        // satisfied?
        if(m_k > cur_k)
            return;
    }
    next_slide();
}
void Warshall::next_path()
{
    if(next_path_without_next_slide())
        next_slide();
}
bool Warshall::next_path_without_next_slide()
{
    int n = m_graph->get_adj().size();
    for(; m_k < n; ++m_k) {
        for(; m_i < n; ++m_i) {
            for(; m_j < n; ++m_j) {
                int new_dist = m_dist_matrix[m_i][m_k] + m_dist_matrix[m_k][m_j];
                if(new_dist < m_dist_matrix[m_i][m_j]) {
                    set_label_mat_val(m_i, m_j, new_dist);
                    m_dist_matrix[m_i][m_j] = new_dist;
                    m_path_matrix[m_i][m_j] = m_path_matrix[m_i][m_k];
                    // only true when this is last option
                    return m_k == n - 1 && m_i == n - 1 && m_j == n - 1;
                }
            }
            m_j = 0;
        }
        m_i = 0;
    }
    return true;
}

std::vector<int> Warshall::get_path(int start, int target)
{
    std::vector<int> path;
    int              cur = start;
    path.push_back(cur);
    while(cur != target) {
        cur = m_path_matrix[cur][target];
        path.push_back(cur);
    }
    return path;
}
