#ifndef LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_

#include <vector>

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/**
 * @brief this class inhertis from the IEntityFactory class and is responsible
 * for using the factory method to create drones.
 **/
class DroneFactory : public IEntityFactory {
 public:
  /**
   * @brief Destroy DroneFactory.
   **/
  virtual ~DroneFactory() {}
  /**
   * @brief Create new drone.
   * @param entity JsonObject containing information on the entity to be
   *created.
   * @return pointer to new entity.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};
#endif  // LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
