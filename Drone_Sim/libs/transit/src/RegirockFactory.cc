#include "RegirockFactory.h"

IEntity* RegirockFactory::CreateEntity(JsonObject& entity) {
  if (regirock != NULL) {
    return nullptr;
  }
  std::string type = entity["type"];
  if (type.compare("regirock") == 0) {
    std::cout << "Regirock Created" << std::endl;
    regirock = new Regirock(entity);
    return regirock;
  }
  return nullptr;
}

