#pragma once

#include "graph/graph.h"
#include "helper.h"

#include <Button.hpp>
#include <Camera2D.hpp>
#include <Godot.hpp>
#include <MeshInstance2D.hpp>
#include <Node2D.hpp>
#include <Position2D.hpp>
#include <RichTextLabel.hpp>
#include <SpinBox.hpp>
#include <ViewportContainer.hpp>

namespace godot {
class Warshall: public Node2D {
    GODOT_CLASS(Warshall, Node2D)

private:
    // for whatever reason this can't be put into a seperate file on wasm
    const char* slide_0_text = "This is a graph. It is defined by a set of nodes and edges. Think of them as towns and roads between them. There are no one way streets so the graph is undirected.\n"
                               "You can describe the graph using an adjacency matrix. Each cell in the adjacency matrix is either 1 or 0. When the cell in the i-th column and j-th row is 1, there is an edge from the i-th to the j-th node in the graph. When it is 0 there is no edge.\n"
                               "Fun Fact: In the case of an undirected graph this is a symmetric matrix (along its diagonal—everywhere the row and column index are equal).\n"
                               "\n"
                               "Hover over the nodes and you will see their respective rows and columns in the matrix highlighted.";
    const char* slide_1_text = "Say you wanted to calculate the minimum path length between node a and node b. The path length is the amount of edges on the path; not the amount of nodes.\n"
                               "And now say you wanted to calculate this path length for any two nodes a and b. This results in a distance matrix, with the value in the i-th column and j-th row representing the path length from node i to node j. If there is no path between these nodes, the value is inf.\n"
                               "\n"
                               "The Floyd-Warshall algorithm can be used to calculate this matrix. It populates an initial distance matrix with 0 on the diagonal, 1 wherever there is a 1 in the adjacency matrix (i.e. there is an edge from a and b), and inf everywhere else. Nothing of this is new information, we are only preparing for the real algorithm.\n"
                               "\n"
                               "Now that the initial distance matrix has been specified, you can hover over the nodes and see their direct connections. You can also hover over the matrix's entries and the corresponding path will be highlighted in the graph.";
    const char* slide_2_text = "Action! The algorithm goes through all nodes k (highlighted in blue) and checks for all other nodes a and b if the path from a to b can be shortened using k. If the path from a to k plus from k to b is shorter than from a to b without using k, the matrix gets updated.\n"
                               "\n"
                               "Once you have done that for every node k, you end up with the desired distance matrix.\n"
                               "You can run the algorithm until one path got updated by clicking 'Next Path' and until a new k is needed with 'Next k'.";
    const char* slide_3_text = "Now we have calculated every possible path length. Feel free to play around hovering over all matrix cells.\n"
                               "\n"
                               "This is the end of our little adventure. You can change the size of the graph below and restart the presentation with a new graph.";

    ViewportContainer* m_graph_viewport_container {nullptr};
    Graph*             m_graph {nullptr};
    Camera2D*          m_camera {nullptr};
    Position2D*        m_sidebar {nullptr};
    MeshInstance2D*    m_sidebar_background {nullptr};
    Position2D*        m_matrix_parent {nullptr};
    RichTextLabel*     m_text {nullptr};
    Button*            m_next_path_button {nullptr};
    Button*            m_next_k_button {nullptr};
    Button*            m_next_slide_button {nullptr};
    Button*            m_toggle_fullscreen_button {nullptr};
    Button*            m_reset_button {nullptr};
    SpinBox*           m_node_num_input {nullptr};

    const float         m_sidebar_width {840.0f};
    int                 m_cur_slide {-1};
    matrix              m_dist_matrix;
    matrix              m_path_matrix;
    matrix_temp<Label*> m_label_matrix;
    std::vector<Label*> m_matrix_cols;
    std::vector<Label*> m_matrix_rows;
    const int           m_matrix_size {32};
    const Vector2       m_cell_size {Vector2(25, 20)};
    const Color         m_hover_color = Color(1.0, 0.0, 0.0);

    int m_k {-1};
    int m_i {-1};
    int m_j {-1};

public:
    static void _register_methods();

    Warshall() {};
    ~Warshall() {};

    void _init();
    void _ready();
    void _process(float delta);

    void toggle_fullscreen();
    void reset();
    void next_slide();
    void next_k();
    void next_path();

private:
    void slide_0();
    void slide_1();
    void slide_2();
    void slide_3();

    void create_matrix();
    void reset_matrix_styles();

    void set_label_mat_val(int i, int j, int val)
    {
        m_label_matrix[i][j]->set_text(std::to_string(val).c_str());
    }
    void set_mat_inf(int i, int j)
    {
        m_label_matrix[i][j]->set_text("inf");
    }
    void set_mat_style(int i, int j, Color color)
    {
        m_label_matrix[i][j]->add_color_override("font_color", color);
    }
    void set_mat_row_style(int j, Color color)
    {
        m_matrix_rows[j]->add_color_override("font_color", color);
    }
    void set_mat_col_style(int i, Color color)
    {
        m_matrix_cols[i]->add_color_override("font_color", color);
    }

    bool is_label_hovered(const Label* label) const;
    void color_hovered();
    void color_path(int i, int j, Color color);
    void color_node(int i, Color color);

    // return true when everything done
    bool next_path_without_next_slide();

    std::vector<int> get_path(int start, int target);
};

} // namespace godot
