#include "framework/renderer/renderer.hpp"

std::vector<Vertex> vertices = {
    {{-0.5f, -0.5f, 0.5f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
    {{0.5f, -0.5f, -0.8f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
    {{0.5f, 0.5f, 0.6f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
    {{-0.5f, 0.5f, -0.9f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}}
};

// 1st triangle: vertex #0, #1, #2
// 2nd triangle: vertex #2, #3, #0
std::vector<uint16_t> indices = {
    0, 1, 2, 2, 3, 0
};

int main() {
    Renderer renderer;
    renderer.set_indices(indices);
    renderer.set_vertices(vertices);
    for(size_t i = 0; i < 100000; i++) {
        renderer.drawOneFrame();
    }
}
