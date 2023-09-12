#ifndef LIBS_TRANSIT_INCLUDE_DELIVERYDATA_H_
#define LIBS_TRANSIT_INCLUDE_DELIVERYDATA_H_
#include <string>
// stores the data for a single drone delivery. Data will be stored in an
// instance of the class. Each drone can do several deliveries, so a drone
// will have a vector of potentially several deliveries, where each delivery
// contains droneID, deliveryDistance, etc..

/**
 * @brief  stores the data for a single drone delivery. Data will be stored
 * in an instance of the class. Each drone can do several deliveries, so a
 * drone will have a vector of potentially several deliveries, where each
 * delivery contains droneID, deliveryDistance, etc.. 
 **/
class DeliveryData {
 public:
  /**
   * @brief DeliveryData Constructor.
   * @param ID ID to represent a name for the delivery data.
   **/
  DeliveryData(int ID);
  /**
   * @brief Returns the ID of a drone.
   * @return The intiger ID for a drone.
   **/
  int getDroneID() {return droneID;}
  /**
   * @brief Returns the delivery distance for a drone.
   * @return Float representing the distance.
   **/
  float getDeliveryDistance() {return deliveryDistance;}
  /**
   * @brief Returns the amount of money earned for a delivery.
   * @return Float reprenting money earned.
   **/
  float getMoneyEarned() { return moneyEarned; }
  /**
   * @brief Returns strategy being used by drone.
   * @return String representing strategy name.
   **/
  std::string getStrategyName() {return strategyName;}
  /**
   * @brief Returns status of IsComplete.
   * @return Boolean representing status of IsComplete.
   **/
  bool getIsComplete() {return isComplete;}
  /**
   * @brief Returns time of delivery.
   * @return double representing the time a delivery takes.
   **/
  double getDeliveryTime() {return deliveryTime;}
  /**
   * @brief Set the id for a drone.
   * @param id the new id we are setting a drone to.
   * @return void.
   **/
  void setDroneID(int id) {droneID = id;}
  /**
   * @brief Set the strategy to the name given.
   * @param name the new strategy we are setting a drone to use.
   * @return void.
   **/
  void setStrategyName(std::string name) {strategyName = name;}
  /**
   * @brief Set the IsComplete status.
   * @param completion boolean representing the state of a drones delivery.
   * @return void.
   **/
  void setIsComplete(bool completion) {isComplete = completion;}
  /**
   * @brief Set the delivery distance for a drone..
   * @param distanceTraveled the distance we traveled.
   * @return void.
   **/
  void updateDeliveryDistance(float distanceTraveled)
  {deliveryDistance += distanceTraveled; }
  /**
   * @brief updates the money a drone has earned.
   * @return void.
   **/
  void updateMoney();
  /**
   * @brief updates the delivery time for a drone.
   * @param time representing the time taken.
   * @return void.
   **/
  void updateDeliveryTime(double time) {deliveryTime += time;}

 private:
  int droneID;
  float deliveryDistance = 0.0;
  float moneyEarned = 0.0;
  float deliveryBonus = 15.0;
  std::string strategyName;
  bool isComplete = false;
  double deliveryTime = 0.0;
};

#endif  // LIBS_TRANSIT_INCLUDE_DELIVERYDATA_H_
