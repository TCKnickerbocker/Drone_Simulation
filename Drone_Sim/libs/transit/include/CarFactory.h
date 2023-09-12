#ifndef LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_CARFACTORY_H_

#include <vector>

#include "Car.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/**
 * @brief this class inhertis from the IEntityFactory class and is responsible
 * for using the factory method to create cars.
 **/
class CarFactory : public IEntityFactory {
 public:
  /**
   * @brief Destroy CarFactory
   **/
  virtual ~CarFactory() {}
  /**
   * @brief Create new car IEntityFactory
   *
   * @param entity JsonObject containing information on the entity to be
   *created.
   * @return pointer to new entity
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
