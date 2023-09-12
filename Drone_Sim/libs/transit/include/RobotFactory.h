#ifndef LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

#include <vector>
/**
 * @brief this class inhertis from the IEntityFactory class and is responsible
 * for using the factory method to create robots.
 **/
class RobotFactory : public IEntityFactory {
 public:
  /**
  * @brief Create new robot.
  * @param entity JsonObject containing information on the entity to be created.
  * @return pointer to new entity.
  **/
  IEntity* CreateEntity(JsonObject& entity);
};
#endif  // LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
