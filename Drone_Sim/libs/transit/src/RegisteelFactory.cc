#include "RegisteelFactory.h"

IEntity* RegisteelFactory::CreateEntity(JsonObject& entity) {
  if (registeel != NULL) {
    return nullptr;
  }
  std::string type = entity["type"];
  if (type.compare("registeel") == 0) {
    std::cout << "Registeel Created" << std::endl;
    registeel = new Registeel(entity);
    return registeel;
  }
  return nullptr;
}


