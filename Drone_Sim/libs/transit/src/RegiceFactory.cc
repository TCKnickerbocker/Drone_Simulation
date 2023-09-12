#include "RegiceFactory.h"

IEntity* RegiceFactory::CreateEntity(JsonObject& entity) {
  if (regice != NULL) {
    return nullptr;
  }
  std::string type = entity["type"];
  if (type.compare("regice") == 0) {
    std::cout << "Regice Created" << std::endl;
    regice = new Regice(entity);
    return regice;
  }
  return nullptr;
}
