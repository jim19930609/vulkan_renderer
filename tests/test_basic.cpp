#include "framework/renderer/renderer.hpp"
std::vector<Vertex> vertices = {
    /*
    {{ 1.f, -1.f, -1.f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
    {{-1.f, -1.f,  1.f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
    {{ 1.f,  1.f,  1.f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
    {{-1.f,  1.f, -1.f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
    {{ 1.f, -1.f,  1.f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
    {{-1.f,  1.f,  1.f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
    {{ 1.f,  1.f, -1.f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
    {{-1.f, -1.f, -1.f}, {0.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
    */
    {{-1.f, -1.f,  1.f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
    {{-1.f, -1.f, -1.f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
    {{ 1.f, -1.f,  1.f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
    {{ 1.f, -1.f, -1.f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
    {{-1.f,  1.f,  1.f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
    {{-1.f,  1.f, -1.f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
    {{ 1.f,  1.f,  1.f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
    {{ 1.f,  1.f, -1.f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
};

// 1st triangle: vertex #0, #1, #2
// 2nd triangle: vertex #2, #3, #0
std::vector<uint16_t> indices = {
    0, 1, 2,
    1, 2, 3,
    2, 3, 7,
    2, 6, 7,
    1, 3, 7,
    1, 5, 7,
    0, 1, 5,
    0, 4, 5,
    0, 2, 6,
    0, 4, 6,
    4, 6, 7,
    4, 5, 7
};

int main() {

    Renderer renderer;
    renderer.set_indices(indices);
    renderer.set_vertices(vertices);
    
    renderer.draw();
}
