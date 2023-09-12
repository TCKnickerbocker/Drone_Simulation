#ifndef LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_

#include "IEntityFactory.h"

/**
 * @brief this class inhertis from the IEntityFactory class and is responsible
 * for creating various factories. It acts as a generic factory creation mechanism.
 **/
class CompositeFactory : public IEntityFactory {
 public:
  /**
   * @brief Create new IEntity using the factory relating to the inputted
   * entity.
   * @param entity JsonObject containing information on the entity to be
   * created.
   * @return pointer to new entity.
   **/
  IEntity* CreateEntity(JsonObject& entity);
  /**
   * @brief Add a factory to the component factories vector.
   * @param factoryEntity A pointer to an IEntityFactory* that we are adding.
   * @return Void.
   **/
  void AddFactory(IEntityFactory* factoryEntity);
  /**
   * @brief Destroy CompositeFactory.
   **/
  virtual ~CompositeFactory();

 private:
  std::vector<IEntityFactory*> componentFactories;
};
#endif  // LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
