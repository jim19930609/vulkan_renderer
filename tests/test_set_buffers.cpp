#include "framework/renderer/renderer.hpp"

std::vector<Vertex> vertices0 = {
    {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
    {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
    {{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}}
};

// 1st triangle: vertex #0, #1, #2
// 2nd triangle: vertex #2, #3, #0
std::vector<uint16_t> indices0 = {
    0, 1, 2, 2, 3, 0
};

std::vector<Vertex> vertices1 = {
    {{-0.2f, -0.2f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
    {{0.8f, -0.8f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.2f, 0.2f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
    {{-0.8f, 0.8f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}}
};

// 1st triangle: vertex #0, #1, #2
// 2nd triangle: vertex #2, #3, #0
std::vector<uint16_t> indices1 = {
    0, 1, 3, 1, 3, 0
};

int main() {
    Renderer renderer;
    for(size_t i = 0; i < 100000; i++) {
        if(i % 2 == 0) {
            renderer.set_indices(indices0);
            renderer.set_vertices(vertices0);
        } else {
            renderer.set_indices(indices1);
            renderer.set_vertices(vertices1);
        }
        renderer.drawOneFrame();
    }
}
