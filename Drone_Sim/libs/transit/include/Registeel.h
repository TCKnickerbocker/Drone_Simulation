#ifndef LIBS_TRANSIT_INCLUDE_REGISTEEL_H_
#define LIBS_TRANSIT_INCLUDE_REGISTEEL_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a registeel in a physical system.
// registeels move using the beeline strategy
class Registeel : public IEntity {
 public:
  // registeel are created with a name
  /**
  * @brief Represents registeel in physical system. Implements IEntity.
  * 
  * @param obj JSON object w/ registeel info
  * @return Instance of registeel.
  **/
  Registeel(const JsonObject& obj);
  /**
  * @brief Destroys registeel.
  * 
  **/
  ~Registeel();
/**
 * @brief Retireve speed value of registeel
 * @return speed of registeel class instance
 **/
  float GetSpeed() const { return speed; }
/**
 * @brief Gets the registeel position
 * @return Position vector3 of registeel class instance
 **/
  Vector3 GetPosition() const { return position; }
/**
 * @brief Current direction value of registeel
 * @return Direction vector3 of registeel class instance
 **/
  Vector3 GetDirection() const { return direction; }
/**
 * @brief Current destination value of registeel
 * @return Destination vector3 of registeel class instance
 **/
  Vector3 GetDestination() const { return destination; }
/**
 * @brief Get JSON details
 * @return details JSON object
 **/
  JsonObject GetDetails() const { return details; }
/**
 * @brief Gets registeel availability status
 * @return boolean of if registeel is available
 **/
  bool GetAvailability() const { return available; }
/**
 * @brief Retrieve nearest entity to registeel
 * 
 * @param scheduler Vector of entity pointers, named schedular
 * @return Entity with the least distance to registeel instance
 **/
  void GetNearestEntity(std::vector<IEntity*> scheduler);

 /**
 * @brief Updates the registeel's position
 * 
 * @param dt Time passed since last move
 * @param scheduler Vector of entity destinations along route
 * @return void, but registeel will now have new position along route
 **/
  void Update(double dt, std::vector<IEntity*> scheduler);
 /**
 * @brief Sets the registeel's position
 * 
 * @param pos_ Vector of new registeel cords
 * @return void, but registeel will have new coordinates
 **/
  void SetPosition(Vector3 pos_);
 /**
 * @brief Sets the registeel's direction
 * 
 * @param dir_ Vector of new registeel direction
 * @return void, but registeel will have new direction
 **/
  void SetDirection(Vector3 dir_) { direction = dir_; }
 /**
 * @brief Sets the registeel's destination
 * 
 * @param des_ Vector of new registeel destination
 * @return void, but registeel will have new destination
 **/
  void SetDestination(Vector3 des_) { destination = des_; }
 /**
 * @brief Rotates a registeel
 * 
 * @param angle double representing angle change
 * @return void, but registeel will have new orientation (direction)
 **/
  void Rotate(double angle);
 /**
 * @brief Causes registeel to jump in place
 * 
 * @param height double representing power of jump
 * @return void, but registeel may have a new y-coordinate after jump executed
 **/
  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that registeel cannot be copied.
  Registeel(const Registeel& registeel) = delete;
  Registeel& operator=(const Registeel& registeel) = delete;

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
};

#endif  // LIBS_TRANSIT_INCLUDE_REGISTEEL_H_
