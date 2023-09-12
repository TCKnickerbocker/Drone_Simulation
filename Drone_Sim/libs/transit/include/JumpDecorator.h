#ifndef LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"
/**
 * @brief this class inhertis from the CelebrationDecorator class and is
 * responsible for decorating an entity in a jump animation.
 **/
class JumpDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief JumpDecorator's constructor, sets the time to 0.
   * @param strategy An IStrategy pointer.
   **/
  JumpDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  /**
   * @brief JumpDecorator's IsCompleted function, determines if the current
   *strategy has completed.
   * @return Boolean, will return true if the time has lived for 1.5 seconds.
   **/
  bool IsCompleted();
  /**
   * @brief JumpDecorator's movement method, checks if previous strategy has
   *completed then completes current strategy.
   * @param entity Pointer to the IEntity object being moved.
   * @param dt Time represented as a double.
   * @return Void/
   **/
  float Move(IEntity* entity, double dt);
};  // close class
#endif  // LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
