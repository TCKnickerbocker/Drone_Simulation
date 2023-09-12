#ifndef LIBS_TRANSIT_INCLUDE_REGIROCKFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_REGIROCKFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Regirock.h"

#include <vector>

/**
 * @brief this class is a inherits from the IEntityFactory class and is
 * responsible for using the factory method to create entities.
 **/
class RegirockFactory : public IEntityFactory {
 public:
  /**
  * @brief Create new Regirock
  * @param entity JsonObject containing information on the entity to be
  * created.
  * @return pointer to new Regirock
  **/
  IEntity* CreateEntity(JsonObject& entity);
  bool loweredSpeed = false;
  IEntity* regirock = NULL;
};

#endif  // LIBS_TRANSIT_INCLUDE_REGIROCKFACTORY_H_