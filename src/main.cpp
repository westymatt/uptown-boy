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
    Scene::init();
    auto sprite = make_unique<Sprite>(Rect{0, 0, 80, 80}, Rect{0, 0, 100, 100});
    this->kenSheet = make_unique<Spritesheet>(move(sprite));
    // Vector2f scale = Vector2f(2.0, 2.0);
    // this->kenSheet->sprite->setScale(scale);
    this->kenSheet->sprite->setAnchorPoint(Point{0, 0});
    this->kenSheet->sprite->loadTexture("resources/example.png",
                                        this->renderer);
    this->addChild(this->kenSheet->sprite.get());
    return true;
  }

  virtual void update() override {
    Scene::update();
    // if (Keyboard::isPressed(SDL_SCANCODE_LEFT)) {
    //   this->kenSheet->sprite->dstRect_.decX(1);
    // }
    // if (Keyboard::isPressed(SDL_SCANCODE_RIGHT)) {
    //   this->kenSheet->sprite->dstRect_.incX(1);
    //   this->kenSheet->sprite->setPosition(Point{100, 100});
    // }
    // if (Keyboard::isPressed(SDL_SCANCODE_UP)) {
    //   this->kenSheet->sprite->dstRect_.decY(1);
    // }
    // if (Keyboard::isPressed(SDL_SCANCODE_DOWN)) {
    //   this->kenSheet->sprite->dstRect_.incY(1);
    // }
    // if (Keyboard::isPressed((SDL_SCANCODE_SPACE))) {
    //   auto moveby = new MoveBy(1);
    // }
  }

private:
  SpritesheetUPtr kenSheet;
};

int main(int argc, char *args[]) {
  GameConfig config;
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
    game.runScene(move(scene));
    game.clean();
  }
  return 0;
}