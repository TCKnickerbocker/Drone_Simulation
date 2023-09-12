#ifndef LIBS_TRANSIT_INCLUDE_ASTARSTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_ASTARSTRATEGY_H_

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
class AstarStrategy : public IStrategy {
 public:
  /**
   * @brief AstarStrategy's constructor.
   * @param position A vector3 of the current position of the IEntity.
   * @param destination A vector3 of the destination for the IEntity.
   * @param graph Pointer to the IGraph map being used.
   **/
  AstarStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
  /**
   * @brief AstarStrategy's destructor.
   **/
  ~AstarStrategy();
  /**
   * @brief AstarStrategy's movement function.
   * @param entity Pointer to the IEntity object that we are moving.
   * @param dt Time represented as a double.
   * @return Float representing the distance traveled.
   **/
  float Move(IEntity* entity, double dt);
  /**
   * @brief Checks if the AstarStrategy's movement is completed.
   * @return Boolean, true: completed, false: uncompleted.
   **/
  bool IsCompleted();

 private:
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // LIBS_TRANSIT_INCLUDE_ASTARSTRATEGY_H_
