#ifndef LIBS_TRANSIT_INCLUDE_ROBOT_H_
#define LIBS_TRANSIT_INCLUDE_ROBOT_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
/**
 * @brief this class inhertis from the IEntity class and represents a robot
 * in a physical system. Robots move using euler integration based on a
 * specified velocity and direction.
 **/
class Robot : public IEntity {
 public:
  /**
   * @brief Robot constructor, creates robot with a name.
   * @param obj JsonObject representing the name.
   **/
  Robot(JsonObject& obj);
  /**
   * @brief Robot destructor.
   **/
  ~Robot() override = default;
  /**
   * @brief Gets the robot's position.
   * @return Vector3 of the robot's position.
   **/
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets the robot's direction.
   * @return Vector3 of the robot's direction.
   **/
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets the robot's destination.
   * @return Vector3 of the robot's destination.
   **/
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets the robot's availability.
   * @return Boolean of the robot's availability.
   **/
  bool GetAvailability() const { return available; }
  /**
   * @brief Gets the robot's details.
   * @return JsonObject of the robot's details.
   **/
  JsonObject GetDetails() const override;
  /**
   * @brief Gets the speed of a robot.
   * @return Float of the robot's speed.
   **/
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets the name of the stratgy being used by the robot.
   * @return String of the name of the stratgy being used.
   */
  std::string GetStrategyName() { return strategyName; }
  /**
   * @brief Sets the availability of a robot.
   * @param choice the availability as a boolean.
   **/
  void SetAvailability(bool choice);
  /**
   * @brief Sets the robot's position.
   * @param pos_ A Vector3 representing the position.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Set the robot's direction.
   * @param dir_ a Vector3 representing direction.
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the robot's destination.
   * @param des_ Vector3 representing the robot's destination.
   **/
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Sets the stratgy being used represented as a string.
   * @param strategyName_ name of the strategy being set.
   */
  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }
  /**
   * @brief Rotates a robot.
   * @param angle Double representing the angle to rotate.
   **/
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
};
#endif  // LIBS_TRANSIT_INCLUDE_ROBOT_H_
