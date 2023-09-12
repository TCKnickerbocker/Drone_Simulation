#ifndef LIBS_TRANSIT_INCLUDE_DRONE_H_
#define LIBS_TRANSIT_INCLUDE_DRONE_H_

#include <vector>

#include "DeliveryData.h"
#include "IEntity.h"
#include "IStrategy.h"
#include "Singleton.h"
#include "math/vector3.h"

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
/**
 * @brief this class inhertis from the IEntity class and represents a drone
 * in a physical system. Drones move using euler integration based on a
 * specified velocity and direction.
 **/
class Drone : public IEntity {
 public:
  // Drones are created with a name
  /**
   * @brief Drone constructor, creates drone with a name.
   * @param obj JsonObject representing the name.
   **/
  Drone(JsonObject& obj);
  // Destructor
  /**
   * @brief Drone destructor.
   **/
  ~Drone();
  /**
   * @brief Gets the speed of a drone.
   * @return Float of the drone's speed.
   **/
  float GetSpeed() const { return speed; }

  // Gets the drone position
  // Gets the drone position
  /**
   * @brief Gets the drone's position.
   * @return Vector3 of the drone's position.
   **/
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets the drone's direction.
   * @return Vector3 of the drone's direction.
   **/
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets the drone's destination.
   * @return Vector3 of the drone's destination.
   **/
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets the drone's details.
   * @return JsonObject of the drone's details.
   **/
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Gets the drone's availability.
   * @return Boolean of the drone's availability.
   **/
  bool GetAvailability() const { return available; }
  /**
   * @brief Gets the drone's nearest entity.
   * @param scheduler Vector of IEntity pointers.
   * @return Void.
   **/
  void GetNearestEntity(std::vector<IEntity*> scheduler);
  /**
   * @brief Gets the drone's Id number.
   * @return Integer corresponding to the drone's Id.
   **/
  int GetId() { return GetDetails()["id"]; }
  // Updates the drone's position
  /**
   * @brief Updates the drone's position.
   * @param dt Time represented as a double.
   * @param scheduler Vector of IEntity pointers.
   **/
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief Sets the drone's position.
   * @param pos_ A Vector3 representing the position.
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }
  // Sets the drone's direction
  /**
   * @brief Set the drone's direction.
   * @param dir_ a Vector3 representing direction.
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }
  // Sets the drone's speed
  /**
   * @brief Set the drone's speed.
   * @param speed_multiplier a float representing speed multiplier.
   **/
  void SetSpeed(float speed_multiplier) { speed = speed * speed_multiplier; }
  /**
   * @brief Sets the drone's destination.
   * @param des_ Vector3 representing the drone's destination.
   **/
  void SetDestination(Vector3 des_) { destination = des_; }

  // Rotates a drone
  /**
   * @brief Rotates a drone.
   * @param angle Double representing the angle to rotate.
   **/
  void Rotate(double angle);
  /**
   * @brief Makes the drone jump.
   * @param height Double representing the height the drone will jump.
   **/
  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that drones cannot be coppied.
  Drone(const Drone& drone) = delete;
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
  // singleton variables
  DeliveryData* curDelivery = NULL;
  Singleton* s = NULL;
};
#endif  // LIBS_TRANSIT_INCLUDE_DRONE_H_
