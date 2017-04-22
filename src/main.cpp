#include <honeycrisp/honeycrisp.h>
#include <memory>
#include <utility>

using std::make_unique;
using std::unique_ptr;
using std::make_shared;
using std::move;

USING_NS_HC;

class ExampleScene1 : public Scene {
public:
  virtual bool init() override {
    this->ken = make_unique<Sprite>(Rect{0, 0, 80, 80}, Rect{0, 0, 100, 100});
    this->ken->setAnchorPoint(Point{0, 0});
    this->ken->loadTexture("resources/example.png", this->gc->renderer);
    this->ken->setScale(2, 2);
    this->addChild(this->ken.get());
    return true;
  }

  virtual void update() override {
    if (this->gc->keyboard->isPressed(SDL_SCANCODE_LEFT)) {
      this->ken->dstRect.point.x -= 1;
    }
    if (this->gc->keyboard->isPressed(SDL_SCANCODE_RIGHT)) {
      this->ken->dstRect.point.x += 1;
      this->ken->setPosition(Point{100, 100});
    }
    if (this->gc->keyboard->isPressed(SDL_SCANCODE_UP)) {
      this->ken->dstRect.point.y += 1;
    }
    if (this->gc->keyboard->isPressed(SDL_SCANCODE_DOWN)) {
      this->ken->dstRect.point.y -= 1;
    }
    if (this->gc->keyboard->isPressed((SDL_SCANCODE_SPACE))) {
      auto moveby = new MoveBy(1);
    }
  }

private:
  SpriteUPtr ken;
};

int main(int argc, char *args[]) {
  hcGameConfig config;
  config.title = "Uptown Boy";
  config.fps = 60;
  config.xpos = 100;
  config.ypos = 100;
  config.width = 800;
  config.height = 600;
  config.flags = 0;

  hcGame game(config);
  if (game.init()) {
    auto scene = make_unique<ExampleScene1>();
    game.loadScene(move(scene));
    game.run();
    game.clean();
  }
  return 0;
}
