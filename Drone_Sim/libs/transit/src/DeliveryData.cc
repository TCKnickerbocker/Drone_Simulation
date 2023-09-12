#include "DeliveryData.h"

DeliveryData::DeliveryData(int ID) {
    droneID = ID;
}
void DeliveryData::updateMoney() {
    if (getIsComplete()) {
        moneyEarned = deliveryTime * 1.00 + deliveryBonus;
    } else {
        moneyEarned = deliveryTime * 1.00;
    }
}
