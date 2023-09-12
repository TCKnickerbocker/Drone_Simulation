#ifndef LIBS_TRANSIT_INCLUDE_REGISTEELFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_REGISTEELFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Registeel.h"

#include <vector>

/**
 * @brief this class is a inherits from the IEntityFactory class and is
 * responsible for using the factory method to create entities.
 **/
class RegisteelFactory : public IEntityFactory {
 public:
  /**
  * @brief Create new Registeel
  * @param entity JsonObject containing information on the entity to be
  * created.
  * @return pointer to new Registeel
  **/
  IEntity* CreateEntity(JsonObject& entity);
  bool loweredSpeed = false;
  IEntity* registeel = NULL;
};

#endif  // LIBS_TRANSIT_INCLUDE_REGISTEELFACTORY_H_
