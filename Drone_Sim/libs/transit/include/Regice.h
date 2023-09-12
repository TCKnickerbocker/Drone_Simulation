#ifndef LIBS_TRANSIT_INCLUDE_REGICE_H_
#define LIBS_TRANSIT_INCLUDE_REGICE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a regice in a physical system.
// Regices move using the beeline strategy
class Regice : public IEntity {
 public:
  // Regice are created with a name
  /**
  * @brief Represents Regice in physical system. Implements IEntity.
  * 
  * @param obj JSON object w/ Regice info
  * @return Instance of regice.
  **/
  Regice(const JsonObject& obj);
  /**
  * @brief Destroys Regice.
  * 
  **/
  ~Regice();
/**
 * @brief Retireve speed value of Regice
 * @return speed of Regice class instance
 **/
  float GetSpeed() const { return speed; }
/**
 * @brief Gets the Regice position
 * @return Position vector3 of Regice class instance
 **/
  Vector3 GetPosition() const { return position; }
/**
 * @brief Current direction value of Regice
 * @return Direction vector3 of Regice class instance
 **/
  Vector3 GetDirection() const { return direction; }
/**
 * @brief Current destination value of Regice
 * @return Destination vector3 of Regice class instance
 **/
  Vector3 GetDestination() const { return destination; }
/**
 * @brief Get JSON details
 * @return details JSON object
 **/
  JsonObject GetDetails() const { return details; }
/**
 * @brief Gets Regice availability status
 * @return boolean of if Regice is available
 **/
  bool GetAvailability() const { return available; }
/**
 * @brief Retrieve nearest entity to Regice
 * 
 * @param scheduler Vector of entity pointers, named schedular
 * @return Entity with the least distance to Regice instance
 **/
  void GetNearestEntity(std::vector<IEntity*> scheduler);

 /**
 * @brief Updates the Regice's position
 * 
 * @param dt Time passed since last move
 * @param scheduler Vector of entity destinations along route
 * @return void, but Regice will now have new position along route
 **/
  void Update(double dt, std::vector<IEntity*> scheduler);
 /**
 * @brief Sets the Regice's position
 * 
 * @param pos_ Vector of new Regice cords
 * @return void, but Regice will have new coordinates
 **/
  void SetPosition(Vector3 pos_);
 /**
 * @brief Sets the Regice's direction
 * 
 * @param dir_ Vector of new Regice direction
 * @return void, but Regice will have new direction
 **/
  void SetDirection(Vector3 dir_) { direction = dir_; }
 /**
 * @brief Sets the Regice's destination
 * 
 * @param des_ Vector of new Regice destination
 * @return void, but Regice will have new destination
 **/
  void SetDestination(Vector3 des_) { destination = des_; }
 /**
 * @brief Rotates a Regice
 * 
 * @param angle double representing angle change
 * @return void, but Regice will have new orientation (direction)
 **/
  void Rotate(double angle);
 /**
 * @brief Causes Regice to jump in place
 * 
 * @param height double representing power of jump
 * @return void, but Regice may have a new y-coordinate after jump executed
 **/
  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that Regice cannot be copied.
  Regice(const Regice& regice) = delete;
  Regice& operator=(const Regice& regice) = delete;

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

#endif  // LIBS_TRANSIT_INCLUDE_REGICE_H_
