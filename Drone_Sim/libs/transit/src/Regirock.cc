#define _USE_MATH_DEFINES
#include "Regirock.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "AstarStrategy.h"
#include "DijkstraStrategy.h"
#include "SpinDecorator.h"
#include "JumpDecorator.h"

#include <cmath>
#include <limits>

Regirock::Regirock(const JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  available = true;
}

Regirock::~Regirock() {
  // Delete dynamically allocated variables
}

void Regirock::GetNearestEntity(std::vector<IEntity*> scheduler) {
  unsigned int seed = time(NULL);
  float xPos = rand_r(&seed) % (2900) - 1400;
  float yPos = 400;
  float zPos = rand_r(&seed) % (1600) - 800;

  destination = Vector3(xPos, yPos, zPos);

  toTargetDestStrategy = new BeelineStrategy(this->GetPosition(), destination);
  available = false;
}

void Regirock::Update(double dt, std::vector<IEntity*> scheduler) {
  if (available) {
    GetNearestEntity(scheduler);
  }

  if (toTargetDestStrategy) {
    toTargetDestStrategy->Move(this, dt);
    if (toTargetDestStrategy->IsCompleted()) {
        delete toTargetDestStrategy;
        toTargetDestStrategy = NULL;
        available = true;
    }
  }
}

void Regirock::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}

void Regirock::Jump(double height) {
  if (goUp) {
    position.y += height;
    jumpHeight += height;
    if (jumpHeight > 5) {
      goUp = false;
    }
  } else {
    position.y -= height;
    jumpHeight -= height;
    if (jumpHeight < 0) {
      goUp = true;
    }
  }
}

void Regirock::SetPosition(Vector3 pos_) {
  if (pos_.x > -1400 && pos_.x < 1500 && pos_.y > 240 &&
  pos_.z > -800 && pos_.z < 800) {
    position = pos_;
  } else {
    std::cout << "Regice tried to move out of bounds" << std::endl;
  }
}
