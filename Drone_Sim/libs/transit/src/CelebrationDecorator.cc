#include "CelebrationDecorator.h"

bool CelebrationDecorator::IsCompleted() { return time >= 1.5; }

float CelebrationDecorator::Move(IEntity* entity, double dt) {
  strategy->Move(entity, dt);
}
