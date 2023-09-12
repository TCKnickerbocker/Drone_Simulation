#include "SpinDecorator.h"

bool SpinDecorator::IsCompleted() {
  return this->CelebrationDecorator::IsCompleted();
}

float SpinDecorator::Move(IEntity* entity, double dt) {
  if (strategy->IsCompleted() && !IsCompleted()) {
    time = time + dt;
    entity->Rotate(dt * 10);
  } else {
    strategy->Move(entity, dt);
  }
  return 0.0;
}
