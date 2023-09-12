#ifndef LIBS_TRANSIT_INCLUDE_SINGLETON_H_
#define LIBS_TRANSIT_INCLUDE_SINGLETON_H_

#include <fstream>
#include <iostream>
#include <vector>

#include "DeliveryData.h"
  /**
  * @brief Uses singlton method to update drone info to a CSV file.
  **/
class Singleton {
 public:
  /**
   * @brief Gets the single instance created by the constructor.
   * @return a Singleton* representing an instance.
   **/
  static Singleton* GetInstance();
  /**
   * @brief Singleton destructor.
   **/
  ~Singleton() { delete instance; }
  /**
   * @brief Writes values to the CSV file deliveryOutput.csv.
   **/
  void writeToCSV();
  /**
   * @brief pushes DeliveryData object into a vector containing all delivery
   *data.
   * @param newDel DeliveryData object.
   **/
  void addDelivery(DeliveryData newDel) {
    deliveries.push_back(newDel);
    std::cout << "Delivery Added" << std::endl;
  }

 protected:
  /**
   * @brief Singleton constructor, only called once
   **/
  Singleton() {}
  static Singleton* instance;
  std::vector<DeliveryData> deliveries;
  bool writtenBefore = false;
};

#endif  // LIBS_TRANSIT_INCLUDE_SINGLETON_H_
