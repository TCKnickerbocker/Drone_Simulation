#include "BeelineStrategy.h"

BeelineStrategy::BeelineStrategy(Vector3 position, Vector3 destination) {
    this->position = position;
    this->destination = destination;
}

bool BeelineStrategy::IsCompleted() {
    return (destination - position).Magnitude() < 1.0;
}

float BeelineStrategy::Move(IEntity* entity, double dt) {
    position = entity->GetPosition();
    Vector3 dir = (destination - position).Unit();
    float speed = entity->GetSpeed();
    position = position + dir * speed * dt;
    float distanceTraveled = entity->GetPosition().Distance(position);
    entity->SetPosition(position);
    entity->SetDirection(dir);
    return distanceTraveled;
}
