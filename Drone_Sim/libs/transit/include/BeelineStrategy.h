#ifndef LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_

/**
 * include
 */
#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/**
 * @brief this class inherits from the IStrategy class and is responsible for
 * generating the beeline that the drone will take.
 **/
class BeelineStrategy : public IStrategy {
 public:
  /**
   * @brief BeelineStrategy's constructor.
   * @param position A vector3 of the currect position of the IEntity.
   * @param destination A vector3 of the destination for the IEntity.
   **/
  BeelineStrategy(Vector3 position, Vector3 destination);
  /**
   * @brief BeelineStrategy's destructor.
   **/
  ~BeelineStrategy();
  /**
   * @brief BeelineStrategy's movement function.
   * @param entity Pointer to the IEntity object that we are moving.
   * @param dt Time represented as a double.
   * @return Float representing the distance traveled.
   **/
  float Move(IEntity* entity, double dt);
  /**
   * @brief Checks if the BeelineStrategy's movement is completed.
   * @return Boolean, true: completed, false: uncompleted.
   **/
  bool IsCompleted();

 private:
  Vector3 position;
  Vector3 destination;
};      // end class
#endif  // LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_
