#ifndef LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
#define LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_

#include "IController.h"
#include "CompositeFactory.h"
#include "IEntity.h"
#include "graph.h"
#include "Singleton.h"
#include "RegiceFactory.h"
#include "RegirockFactory.h"
#include "RegisteelFactory.h"
#include "IEntityFactory.h"

using namespace routing;

//--------------------  Model ----------------------------

/// Simulation Model handling the transit simulation.  The model can communicate
/// with the controller.

/**
 * @brief Simulation Model handling the transit simulation. 
 * The model can communicate with the controller.
 **/
class SimulationModel {
 public:
  /**
   * @brief SimulationModel's Constructor.
   * @param controller IController inhereted classes can 
   * be created with the SimulationModel.
   **/
  SimulationModel(IController& controller);
  /**
   * @brief Sets the graph for the simulation model to use.
   * @param graph an IGraph pointer for the graph we want to use.
   * @return void.
   **/
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /// Creates an simulation entity
  /**
   * @brief Creates an simulation entity.
   * @param entity a JsonObject for the entity we want to make.
   * @return void.
   **/
  void CreateEntity(JsonObject& entity);
  /// Schedules a trip for an object in the scene.
  /**
   * @brief Schedules a trip for an object in the scene.
   * @param details a Jasonobject representing the details of a trip.
   * @return void.
   **/
  void ScheduleTrip(JsonObject& details);
  /// Updates the simulation
  /**
   * @brief Updates the simulation.
   * @param dt double representing time.
   * @return void.
   **/
  void Update(double dt);
  // Adds a new entity type
  /**
   * @brief Adds a new entity type.
   * @param factory The new factory being added.
   * @return void.
   **/
  void AddFactory(IEntityFactory* factory);
  /**
   * @brief Writes data to csv file.
   * @return void.
   **/
  void WriteToCSV() {
    std::cout << "Calling writeToCSV()" << std::endl;
    s->writeToCSV();
  }

  // destructor which will call singleton's writeToCSV()
  ~SimulationModel();

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  const IGraph* graph;
  CompositeFactory* compFactory;
  IEntityFactory* regiceFactory;
  IEntityFactory* regirockFactory;
  IEntityFactory* registeelFactory;
  Singleton* s;
  double time;
};

#endif  // LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
