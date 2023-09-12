#include "SimulationModel.h"
#include "DroneFactory.h"
#include "RobotFactory.h"
#include "CarFactory.h"
#include "HelicopterFactory.h"
#include "RegiceFactory.h"
#include "RegirockFactory.h"
#include "RegisteelFactory.h"


SimulationModel::SimulationModel(IController& controller)
    : controller(controller) {
  compFactory = new CompositeFactory();
  AddFactory(new DroneFactory());
  AddFactory(new RobotFactory());
  AddFactory(new CarFactory());
  AddFactory(new HelicopterFactory());
  s = Singleton::GetInstance();
  std::cout << "Sim model loaded in" << std::endl;
  regiceFactory = new RegiceFactory();
  regirockFactory = new RegirockFactory();
  registeelFactory = new RegisteelFactory();
  AddFactory(regiceFactory);
  AddFactory(regirockFactory);
  AddFactory(registeelFactory);
}

void SimulationModel::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  std::string name = entity["name"];
  JsonArray position = entity["position"];
  std::cout << name << ": " << position << std::endl;
  if ((name == "Regice-1") || (name == "Regirock-1")
    || (name == "Registeel-1")) {
    return;
  }

  IEntity* myNewEntity = compFactory->CreateEntity(entity);
  myNewEntity->SetGraph(graph);

  // Call AddEntity to add it to the view
  controller.AddEntity(*myNewEntity);
  entities.push_back(myNewEntity);
}

/// Schedules a trip for an object in the scene
void SimulationModel::ScheduleTrip(JsonObject& details) {
  std::string name = details["name"];
  JsonArray start = details["start"];
  JsonArray end = details["end"];
  std::cout << name << ": " << start << " --> " << end << std::endl;

  for (auto entity : entities) {  // Add the entity to the scheduler
    JsonObject detailsTemp = entity->GetDetails();
    std::string nameTemp = detailsTemp["name"];
    std::string typeTemp = detailsTemp["type"];
    if (name.compare(nameTemp) == 0 &&
    typeTemp.compare("robot") == 0 && entity->GetAvailability()) {
      std::string strategyName = details["search"];
      entity->SetStrategyName(strategyName);
      entity->SetDestination(Vector3(end[0], end[1], end[2]));
      scheduler.push_back(entity);
      break;
    }
  }
  controller.SendEventToView("TripScheduled", details);
}

/// Updates the simulation
void SimulationModel::Update(double dt) {
  for (int i = 0; i < entities.size(); i++) {
    entities[i]->Update(dt, scheduler);
    controller.UpdateEntity(*entities[i]);
    if (regiceFactory->regice != NULL && !regiceFactory->loweredSpeed) {
      entities[i]->SetSpeed(2.0);
      regiceFactory->loweredSpeed = true;
    }
    if (regirockFactory->regirock != NULL && !regirockFactory->loweredSpeed) {
      entities[i]->SetSpeed(0.75);
      regirockFactory->loweredSpeed = true;
    }
    if (registeelFactory->registeel != NULL &&
     !registeelFactory->loweredSpeed) {
      entities[i]->SetSpeed(0.25);
      registeelFactory->loweredSpeed = true;
    }
  }
}

void SimulationModel::AddFactory(IEntityFactory* factory) {
  compFactory->AddFactory(factory);
}

SimulationModel::~SimulationModel() {
  std::cout << "Ending Simulation..." << std::endl;
  s->writeToCSV();
}