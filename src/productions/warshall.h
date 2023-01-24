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
    Button*            m_reset_button {nullptr};
    SpinBox*           m_node_num_input {nullptr};

    float               m_sidebar_width {-1.0f};
    int                 m_cur_slide {-1};
    matrix              m_dist_matrix;
    matrix              m_path_matrix;
    matrix_temp<Label*> m_label_matrix;
    std::vector<Label*> m_matrix_cols;
    std::vector<Label*> m_matrix_rows;
    int                 m_matrix_size {32};
    Color               m_hover_color = Color(1.0, 0.0, 0.0);

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

private:
    void reset();
    void next_slide();

    void slide_0();
    void slide_1();
    void slide_2();
    void slide_3();

    void create_matrix();
    void reset_label_matrix();
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

    String get_slide_text(int slide_idx);

    bool is_label_hovered(const Label* label) const;
    void color_path(int i, int j, Color color);
    void color_node(int i, Color color);

    void next_k();
    void next_path();
    // return true when everything done
    bool next_path_without_next_slide();

    std::vector<int> get_path(int start, int target);
};

} // namespace godot