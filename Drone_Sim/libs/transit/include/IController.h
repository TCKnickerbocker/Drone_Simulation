#ifndef LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_
#define LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View
/// Controller Pattern
/**
 * @brief Abstract controller class used in the Transit Service. 
 * Uses the Model View Controller Pattern.
 **/
class IController {
 public:
  /**
   * @brief IController's destructor.
   **/
  virtual ~IController() {}
  /// Adds an entity to the program
  /**
   * @brief Adds an entity to the program.
   * @param entity The IEntity being added.
   * @return void.
   **/
  virtual void AddEntity(const IEntity& entity) = 0;
  /// Adds an entity to the program
  /**
   * @brief Updates an entity in the program.
   * @param entity The IEntity being updated.
   * @return void.
   **/
  virtual void UpdateEntity(const IEntity& entity) = 0;
  /// Removes an entity from the program
  /**
   * @brief Removes an entity to the program.
   * @param entity The IEntity being removed.
   * @return void.
   **/
  virtual void RemoveEntity(int id) = 0;
  /// Adds a path to the program
  /**
   * @brief Adds an path to the program.
   * @param id the id for the path we're adding.
   * @param path a std::vector<std::vector<float> >& representing the path.
   * @return void.
   **/
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;
  /// Removes a path from the program
  /**
   * @brief Removes an path to the program.
   * @param id the id for the path we're removing.
   * @return void.
   **/
  virtual void RemovePath(int id) = 0;
  /// Allows messages to be passed back to the view
  /**
   * @brief Allows messages to be passed back to the view.
   * @param event std::string& representing the event to be sent.
   * @param details a JsonObject& representing its details.
   * @return void.
   **/
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_
