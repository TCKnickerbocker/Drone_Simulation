#ifndef LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_

#include <vector>

#include "Helicopter.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/**
 * @brief this class inhertis from the IEntityFactory class and is responsible
 * for using the factory method to create helicopters.
 **/
class HelicopterFactory : public IEntityFactory {
 public:
  /**
   * @brief Destroy HelicopterFactory.
   */
  virtual ~HelicopterFactory() {}
  /**
   * @brief Create new HelicopterFactory IEntityFactory.
   *
   * @param entity JsonObject containing information on the entity to be
   *created.
   * @return Pointer to new entity.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_
