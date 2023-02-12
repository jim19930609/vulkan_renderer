#include "framework/render_api.hpp"

int main() {
    RenderAPI render_api;
    render_api.draw_object(glm::vec3(0.5, 0.5, 0.5), glm::vec3(1.0f, 0.0f, 0.0f), ObjectType::BOX);
    for(size_t i = 0; i < 100000; i++) {
       render_api.render_one_frame(); 
    }
}
