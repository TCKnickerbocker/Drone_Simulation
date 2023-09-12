#ifndef LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_

#include <vector>
#include "graph.h"
#include "IEntity.h"

using namespace routing;
/**
 * @brief Parent class IStrategy, used to represent abstract movement methods.
 **/
class IStrategy {
 public:
  /**
  * @brief IStrategy's movement function.
  * @param entity pointer to the IEntity being moved.
  * @param dt time represented as a double.
  * @return Float for distance traveled.
  **/
  virtual float Move(IEntity* entity, double dt) = 0;
  /**
  * @brief Checks if the IStrategy's movement is completed.
  * @return Boolean, true: completed, false: uncompleted.
  **/
  virtual bool IsCompleted() = 0;
 protected:
  // IGraph object to be used in the simulation.
  const IGraph* graph;
};  // close class
#endif  // LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
