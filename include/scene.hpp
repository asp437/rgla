#pragma once

#include "common.hpp"
#include "math.hpp"
#include "sprite.hpp"

#include <deque>
#include <memory>

namespace RGLA {
    class Scene {
    public:
        void AddSprite(std::weak_ptr<ISpriteBase> sprite);
        bool RemoveSprite(std::weak_ptr<ISpriteBase> sprite);

        void Render() const;

        Vec2f Position;
    protected:
        std::deque<std::weak_ptr<ISpriteBase>> _sprites;
    };
}
