#include "framework/renderer/renderer.hpp"
#include <memory>

enum class ObjectType {
    BOX,
};

class RenderAPI {
 private:
    std::shared_ptr<Renderer> renderer = nullptr;
    std::vector<Vertex> vertices_;
    std::vector<uint16_t> indices_;
    bool update_buffers = false;

    void draw_box(glm::vec3 center_pos, glm::vec3 color) {
        float length = 0.5;
        float hl = length / 2;
        // up/down, left/right, front/back        
        glm::vec3 dlb = (center_pos - hl, center_pos - hl, center_pos - hl);
        glm::vec3 dlf = (center_pos - hl, center_pos - hl, center_pos + hl);
        glm::vec3 drb = (center_pos - hl, center_pos + hl, center_pos - hl);
        glm::vec3 drf = (center_pos - hl, center_pos + hl, center_pos + hl);
        
        glm::vec3 urf = (center_pos + hl, center_pos + hl, center_pos + hl);
        glm::vec3 ulf = (center_pos + hl, center_pos - hl, center_pos + hl);
        glm::vec3 urb = (center_pos + hl, center_pos + hl, center_pos - hl);
        glm::vec3 ulb = (center_pos + hl, center_pos - hl, center_pos - hl);
        
        /*
        glm::vec3 dlb = glm::vec3(0.2, 0.0, 0.1);
        glm::vec3 dlf = glm::vec3(0.3, 0.3, 0.0);
        glm::vec3 drb = glm::vec3(0.1, 0.0, 0.2);
        vertices_.push_back({dlb, {1.0f, 0.0f, 0.0f}, glm::vec2(0, 0)});
        vertices_.push_back({dlf, {0.0f, 1.0f, 0.0f}, glm::vec2(0, 0)});
        vertices_.push_back({drb, {0.0f, 0.0f, 1.0f}, glm::vec2(0, 0)});
        */
        vertices_.push_back({dlb, color, glm::vec2(0, 0)});
        vertices_.push_back({dlf, color, glm::vec2(0, 0)});
        vertices_.push_back({drb, color, glm::vec2(0, 0)});
        vertices_.push_back({drf, color, glm::vec2(0, 0)});
        vertices_.push_back({urf, color, glm::vec2(0, 0)});
        vertices_.push_back({urb, color, glm::vec2(0, 0)});
        vertices_.push_back({ulf, color, glm::vec2(0, 0)});
        vertices_.push_back({ulb, color, glm::vec2(0, 0)});
        
        /*
        std::vector<uint16_t> box_indices = { 
                                             0, 1, 2, // down
                                            };
        */

        std::vector<uint16_t> box_indices = { 
                                             0, 1, 2, // down
                                             1, 2, 3, // down
                                             4, 5, 6, // up
                                             5, 6, 7, // up
                                             0, 1, 7, // left
                                             1, 6, 7, // left
                                             2, 3, 5, // right
                                             3, 4, 5, // right
                                             1, 3, 4, // front
                                             1, 4, 6, // front
                                             0, 2, 5, // back
                                             0, 5, 7, // back
                                            };
        indices_.insert(indices_.end(), box_indices.begin(), box_indices.end());
    }
 
 public:
    RenderAPI() {
        renderer = std::make_shared<Renderer>();
    }

    void render_one_frame() {
        if(update_buffers) {
            renderer->set_vertices(vertices_);
            renderer->set_indices(indices_);
            update_buffers = false;
        }
        renderer->drawOneFrame();
    }
    
    void draw_object(glm::vec3 center_pos, glm::vec3 color, ObjectType type) {
        switch (type) {
            case ObjectType::BOX: {
                draw_box(center_pos, color);
                break;
            }
            default: {
                throw std::runtime_error("Invalid GeometryType");
            }
        }
        update_buffers = true;
    }

    void clear_geometries() {
        vertices_.clear();
        indices_.clear();
    }
};
