#ifndef LIBS_TRANSIT_INCLUDE_REGICEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_REGICEFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Regice.h"

#include <vector>

/**
 * @brief this class is a inherits from the IEntityFactory class and is
 * responsible for using the factory method to create entities.
 **/
class RegiceFactory : public IEntityFactory {
 public:
  /**
  * @brief Create new Regice
  * @param entity JsonObject containing information on the entity to be
  * created.
  * @return pointer to new Regice
  **/
  IEntity* CreateEntity(JsonObject& entity);
  bool loweredSpeed = false;
  IEntity* regice = NULL;
};

#endif  // LIBS_TRANSIT_INCLUDE_REGICEFACTORY_H_
