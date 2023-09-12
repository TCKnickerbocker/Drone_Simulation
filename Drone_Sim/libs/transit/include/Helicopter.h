#ifndef LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
#define LIBS_TRANSIT_INCLUDE_HELICOPTER_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a helicopter in a physical system.
// Helicopters move in the air using the beeline strategy.
/**
 * @brief this class inhertis from the IEntity class and represents a
 * helicopter in a physical system. Helocopters move using euler
 * integration based on a specified velocity and direction.
 * Helicopters move in the air using beeline strategy.
 **/
class Helicopter : public IEntity {
 public:
  // Helicopters are created with a name
  /**
   * @brief Represents helicopter in physical system. Implements IEntity.
   *
   * @param obj JSON object w/ helicopter info
   * @return Instance of helicopter.
   **/
  Helicopter(const JsonObject& obj);
  /**
   * @brief Destroys helicopter.
   *
   **/
  ~Helicopter();
  /**
   * @brief Retireve speed value of helicopter
   * @return speed of helicopter class instance
   **/
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets the helicopter position
   * @return Position vector3 of helicopter class instance
   **/
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Current direction value of helicopter
   * @return Direction vector3 of helicopter class instance
   **/
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Current destination value of helicopter
   * @return Destination vector3 of helicopter class instance
   **/
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Get JSON details
   * @return details JSON object
   **/
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Gets helicopter availability status
   * @return boolean of if helicopter is available
   **/
  bool GetAvailability() const { return available; }
  /**
   * @brief Retrieve nearest entity to helicopter
   *
   * @param scheduler Vector of entity pointers, named schedular
   * @return Entity with the least distance to helicopter instance
   **/
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * @brief Updates the helicopter's position
   *
   * @param dt Time passed since last move
   * @param scheduler Vector of entity destinations along route
   * @return void, but helicopter will now have new position along route
   **/
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief Sets the helicopter's position
   *
   * @param pos_ Vector of new helicopter cords
   * @return void, but helicopter will have new coordinates
   **/
  void SetPosition(Vector3 pos_);
  /**
   * @brief Sets the helicopter's direction
   *
   * @param dir_ Vector of new helicopter direction
   * @return void, but helicopter will have new direction
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the helicopter's destination
   *
   * @param des_ Vector of new helicopter destination
   * @return void, but helicopter will have new destination
   **/
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Rotates a helicopter
   *
   * @param angle double representing angle change
   * @return void, but helicopter will have new orientation (direction)
   **/
  void Rotate(double angle);
  /**
   * @brief Causes helicopter to jump in place
   *
   * @param height double representing power of jump
   * @return void, but helicopter may have a new y-coordinate after jump
   *executed
   **/
  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that helicopters cannot be copied.
  Helicopter(const Helicopter& heli) = delete;
  Helicopter& operator=(const Helicopter& heli) = delete;

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

#endif  // LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
