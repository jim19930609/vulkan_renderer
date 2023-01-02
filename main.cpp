#include "renderer.hpp"

int main() {
    Renderer renderer;
    for(size_t i = 0; i < 100000; i++) {
        renderer.drawOneFrame();
    }
}
