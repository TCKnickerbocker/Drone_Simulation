#ifndef LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_

#include <vector>

#include "IStrategy.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for
 * decorating an entity in a celebration animation.
 **/
class CelebrationDecorator : public IStrategy {
 public:
  /**
   * @brief CelebrationDecorator's constructor, sets the time to 0.
   * @param strategy An IStrategy pointer.
   **/
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }
  /**
   * @brief CelebrationDecorator's movement method, checks if previous strategy
   * has completed then completes current strategy.
   * @param entity Pointer to the IEntity object being moved.
   * @param dt Time represented as a double.
   * @return Float representing distance traveled.
   **/
  float Move(IEntity *entity, double dt);
  /**
   * @brief CelebrationDecorator's IsCompleted function, determines if the
   * current strategy has completed.
   * @return Boolean, will return true if the time has lived for 1.5 seconds.
   **/
  bool IsCompleted();

 protected:
  IStrategy *strategy;
  float time;
};  // close class
#endif  // LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
