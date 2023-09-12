#ifndef LIBS_TRANSIT_INCLUDE_DIJKSTRASTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_DIJKSTRASTRATEGY_H_

/**
 * include
 */
#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for
 * generating the beeline that the drone will take.
 **/
class DijkstraStrategy : public IStrategy {
 public:
  /**
   * @brief DijkstraStrategy's constructor.
   * @param position A vector3 of the current position of the IEntity.
   * @param destination A vector3 of the destination for the IEntity.
   * @param graph Pointer to the IGraph map being used.
   **/
  DijkstraStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
  /**
   * @brief DijkstraStrategy's destructor.
   **/
  ~DijkstraStrategy();
  /**
   * @brief DijkstraStrategy's movement function.
   * @param entity Pointer to the IEntity object being moved.
   * @param dt Time represented as a double.
   * @return Float representing distance traveled.
   **/
  float Move(IEntity* entity, double dt);
  /**
   * @brief Checks if the DijkstraStrategy's movement is completed.
   * @return Boolean, true: completed, false: uncompleted.
   **/
  bool IsCompleted();

 private:
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // LIBS_TRANSIT_INCLUDE_DIJKSTRASTRATEGY_H_
