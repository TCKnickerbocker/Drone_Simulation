#ifndef LIBS_TRANSIT_INCLUDE_CAR_H_
#define LIBS_TRANSIT_INCLUDE_CAR_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
// Represents a car in a physical system.
// Cars move around using Astar
/**
 * @brief this class inherits from the IEntity class and is responsible for
 *representing a car in a physicalk system as well as allowing them to move
 *around using Astar.
 **/
class Car : public IEntity {
 public:
  // Cars are created with a name
  /**
   * @brief Represents car in physical system. Implements IEntity.
   *
   * @param obj JSON object w/ car info
   * @return Instance of car.
   **/
  Car(const JsonObject& obj);
  /**
   * @brief Destroys car.
   *
   **/
  ~Car();
  /**
   * @brief Retireve speed value of car
   * @return speed of car class instance
   **/
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets the car position
   * @return Position vector3 of car class instance
   **/
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Current direction value of car
   * @return Direction vector3 of car class instance
   **/
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Current destination value of car
   * @return Destination vector3 of car class instance
   **/
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Get JSON details
   * @return details JSON object
   **/
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Gets car availability status
   * @return boolean of if car is available
   **/
  bool GetAvailability() const { return available; }
  /**
   * @brief Retrieve nearest entity to car
   *
   * @param scheduler Vector of entity pointers, named schedular
   * @return Entity with the least distance to car instance
   **/
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * @brief Updates the car's position
   *
   * @param dt Time passed since last move
   * @param scheduler Vector of entity destinations along route
   * @return void, but car will now have new position along route
   **/
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief Sets the car's position
   *
   * @param pos_ Vector of new car cords
   * @return void, but car will have new coordinates
   **/
  void SetPosition(Vector3 pos_);
  /**
   * @brief Sets the car's direction
   *
   * @param dir_ Vector of new car direction
   * @return void, but car will have new direction
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the car's destination
   *
   * @param des_ Vector of new car destination
   * @return void, but car will have new destination
   **/
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Rotates a car
   *
   * @param angle double representing angle change
   * @return void, but car will have new orientation (direction)
   **/
  void Rotate(double angle);
  /**
   * @brief Causes car to jump in place
   *
   * @param height double representing power of jump
   * @return void, but car may have a new y-coordinate after jump executed
   **/
  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that cars cannot be copied.
  Car(const Car& car) = delete;
  Car& operator=(const Car& car) = delete;

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

#endif  // LIBS_TRANSIT_INCLUDE_CAR_H_
