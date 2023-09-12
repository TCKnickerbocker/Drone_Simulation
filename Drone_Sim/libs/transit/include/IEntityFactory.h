#ifndef LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"
#include "util/json.h"

/**
 * @brief this class is a parent class and is responsible
 * for using the factory method to create entities.
 **/
class IEntityFactory {
 public:
  /**
   * @brief Destroy IEntityFactory
   **/
  virtual ~IEntityFactory() {}
  /**
   * @brief Create new IEntity
   * @param entity JsonObject containing information on the entity to be
   * created.
   * @return pointer to new entity
   **/
  virtual IEntity* CreateEntity(JsonObject& entity) = 0;
  // added regice factory member variables
  bool loweredSpeed;
  bool regiceIn;
  IEntity* regice;
  IEntity* regirock;
  IEntity* registeel;
};
#endif  // LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
