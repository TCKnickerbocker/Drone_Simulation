#include "Singleton.h"
Singleton* Singleton::instance = nullptr;

Singleton *Singleton::GetInstance() {
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}

void Singleton::writeToCSV() {
    std::cout << "Writing to CSV..." << std::endl;
    std::ofstream myFile;
    if (!writtenBefore) {
        myFile = std::ofstream("deliveryOutput.csv");
        myFile << "DroneID,DeliveryDistance,MoneyEarned,"
        << "DeliveryTime,StrategyName,IsComplete\n";
        // optional TODO: add weather encountered to output string
        writtenBefore = true;
    } else {
        myFile = std::ofstream("simulationOutput.csv", std::ios_base::app);
    }
    for (int i=0; i < deliveries.size(); i++) {
        myFile << deliveries.at(i).getDroneID() << ",";
        myFile << deliveries.at(i).getDeliveryDistance() << ",";
        myFile << "$" << deliveries.at(i).getMoneyEarned() << ",";
        myFile << deliveries.at(i).getDeliveryTime() << "s,";
        myFile << deliveries.at(i).getStrategyName() << ",";
        // TODO(knick073): weather encountered
        // myFile << "WEATHER PLACEHOLDER" << ",";
        std::string completeStatus =
        deliveries.at(i).getIsComplete() ? "true" : "false";
        myFile << completeStatus;
        myFile << "\n";
    }
    myFile.close();
    deliveries.clear();
    std::cout << "done writing" << std::endl;
}
