#ifndef LIBS_TRANSIT_INCLUDE_REGIROCK_H_
#define LIBS_TRANSIT_INCLUDE_REGIROCK_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a regirock in a physical system.
// regirocks move using the beeline strategy
class Regirock : public IEntity {
 public:
  // regirock are created with a name
  /**
  * @brief Represents regirock in physical system. Implements IEntity.
  * 
  * @param obj JSON object w/ regirock info
  * @return Instance of regirock.
  **/
  Regirock(const JsonObject& obj);
  /**
  * @brief Destroys regirock.
  * 
  **/
  ~Regirock();
/**
 * @brief Retireve speed value of regirock
 * @return speed of regirock class instance
 **/
  float GetSpeed() const { return speed; }
/**
 * @brief Gets the regirock position
 * @return Position vector3 of regirock class instance
 **/
  Vector3 GetPosition() const { return position; }
/**
 * @brief Current direction value of regirock
 * @return Direction vector3 of regirock class instance
 **/
  Vector3 GetDirection() const { return direction; }
/**
 * @brief Current destination value of regirock
 * @return Destination vector3 of regirock class instance
 **/
  Vector3 GetDestination() const { return destination; }
/**
 * @brief Get JSON details
 * @return details JSON object
 **/
  JsonObject GetDetails() const { return details; }
/**
 * @brief Gets regirock availability status
 * @return boolean of if regirock is available
 **/
  bool GetAvailability() const { return available; }
/**
 * @brief Retrieve nearest entity to regirock
 * 
 * @param scheduler Vector of entity pointers, named schedular
 * @return Entity with the least distance to regirock instance
 **/
  void GetNearestEntity(std::vector<IEntity*> scheduler);

 /**
 * @brief Updates the regirock's position
 * 
 * @param dt Time passed since last move
 * @param scheduler Vector of entity destinations along route
 * @return void, but regirock will now have new position along route
 **/
  void Update(double dt, std::vector<IEntity*> scheduler);
 /**
 * @brief Sets the regirock's position
 * 
 * @param pos_ Vector of new regirock cords
 * @return void, but regirock will have new coordinates
 **/
  void SetPosition(Vector3 pos_);
 /**
 * @brief Sets the regirock's direction
 * 
 * @param dir_ Vector of new regirock direction
 * @return void, but regirock will have new direction
 **/
  void SetDirection(Vector3 dir_) { direction = dir_; }
 /**
 * @brief Sets the regirock's destination
 * 
 * @param des_ Vector of new regirock destination
 * @return void, but regirock will have new destination
 **/
  void SetDestination(Vector3 des_) { destination = des_; }
 /**
 * @brief Rotates a regirock
 * 
 * @param angle double representing angle change
 * @return void, but regirock will have new orientation (direction)
 **/
  void Rotate(double angle);
 /**
 * @brief Causes regirock to jump in place
 * 
 * @param height double representing power of jump
 * @return void, but regirock may have a new y-coordinate after jump executed
 **/
  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that regirock cannot be copied.
  Regirock(const Regirock& regirock) = delete;
  Regirock& operator=(const Regirock& regirock) = delete;

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

#endif  // LIBS_TRANSIT_INCLUDE_REGIROCK_H_
