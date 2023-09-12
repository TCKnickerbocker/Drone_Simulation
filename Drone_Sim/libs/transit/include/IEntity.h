#ifndef LIBS_TRANSIT_INCLUDE_IENTITY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View
/// Controller Pattern
/**
 * @brief Parent class IEntity. Abstract controller class used in the
 * Transit Service. Uses the Model View Controller Pattern.
 **/
class IEntity {
 public:
  /**
   * @brief IEntity constructor, creates IEntity with a ID.
   **/
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }
  /**
   * @brief IEntity destructor.
   **/
  virtual ~IEntity() {}
  /**
   * @brief Gets the ID of a IEntity.
   * @return Intiger representing an ID.
   */
  virtual int GetId() const { return id; }
  /**
   * @brief Gets the IEntity's position.
   * @return Vector3 of the IEntity's position.
   **/
  virtual Vector3 GetPosition() const = 0;
  /**
   * @brief Gets the IEntity's direction.
   * @return Vector3 of the IEntity's direction.
   **/
  virtual Vector3 GetDirection() const = 0;
  /**
   * @brief Gets the IEntity's destination.
   * @return Vector3 of the IEntity's destination.
   **/
  virtual Vector3 GetDestination() const = 0;
  /**
   * @brief Gets the IEntity's details.
   * @return JsonObject of the IEntity's details.
   **/
  virtual JsonObject GetDetails() const = 0;
  /**
   * @brief Gets the speed of a IEntity.
   * @return Float of the IEntity's speed.
   **/
  virtual float GetSpeed() const = 0;
  /**
   * @brief Gets the IEntity's availability.
   * @return Boolean of the IEntity's availability.
   **/
  virtual bool GetAvailability() const {}
  /**
   * @brief Gets the name of the stratgy being used by the IEntity.
   * @return String of the name of the stratgy being used.
   */
  virtual std::string GetStrategyName() {}
  /**
   * @brief Sets the availability of a IEntity.
   * @param choice the availability as a boolean.
   **/
  virtual void SetAvailability(bool choice) {}
  /**
   * @brief Updates the IEntity's position.
   * @param dt Time represented as a double.
   * @param scheduler Vector of IEntity pointers.
   **/
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}
  /**
   * @brief Sets the nodes in a graph to be used for paths with delivery
   * @param graph an IGraph pointer representing the graph we want to use.
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
   * @brief Sets the IEntity's position.
   * @param pos_ A Vector3 representing the position.
   **/
  virtual void SetPosition(Vector3 pos_) {}
  /**
   * @brief Set the IEntity's direction.
   * @param dir_ A Vector3 representing direction.
   **/
  virtual void SetDirection(Vector3 dir_) {}
  // Sets the IEntity's speed
  /**
   * @brief Set the IEntity's speed.
   * @param speed_multiplier a float representing speed multiplier.
   **/
  void SetSpeed(float speed_multiplier) {}
  /**
   * @brief Sets the IEntity's destination.
   * @param des_ Vector3 representing the IEntity's destination.
   **/
  virtual void SetDestination(Vector3 des_) {}
  /**
   * @brief Sets the stratgy being used represented as a string.
   * @param strategyName_ name of the strategy being set.
   */
  virtual void SetStrategyName(std::string strategyName_) {}
  /**
   * @brief Rotates a IEntity.
   * @param angle Double representing the angle to rotate.
   **/
  virtual void Rotate(double angle) {}
  /**
   * @brief Makes the IEntity jump.
   * @param height Double representing the height the drone will jump.
   **/
  virtual void Jump(double height) {}

 protected:
  int id;
  const IGraph* graph;
};
#endif  // LIBS_TRANSIT_INCLUDE_IENTITY_H_
