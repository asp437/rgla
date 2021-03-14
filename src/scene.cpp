#include "scene.hpp"

#include <algorithm>

namespace RGLA {
    void Scene::AddSprite(std::weak_ptr<ISpriteBase> sprite) {
        _sprites.push_back(sprite);
    }

    bool Scene::RemoveSprite(std::weak_ptr<ISpriteBase> sprite) {
        auto sprite_ptr = sprite.lock();
        if (!sprite_ptr) {
            return false;;
        }
        auto it = find_if(_sprites.begin(), _sprites.end(), [sprite_ptr] (std::weak_ptr<ISpriteBase> wptr) {
            if (auto ptr = wptr.lock()) {
                return ptr == sprite_ptr;
            }
            return false;
        });

        if (it == _sprites.end()) {
            return false;
        }

        _sprites.erase(it);
        return true;
    }

    void Scene::Render() const {
        for (const auto& wptr : _sprites) {
            if (auto ptr = wptr.lock()) {
                ptr->Render(Position);
            } else {
                // TODO: Remove deleted sprites
            }
        }
    }
}
