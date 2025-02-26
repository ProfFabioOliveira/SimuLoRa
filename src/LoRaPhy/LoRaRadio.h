#ifndef __LORARADIO_H_
#define __LORARADIO_H_

#include "inet/physicallayer/wireless/apsk/packetlevel/ApskRadio.h"

namespace inet {
namespace physicallayer {

class LoRaRadio : public ApskRadio
{
  private:
    // Parâmetros LoRa (agora privados)
    int spreadingFactor;
    double bandwidth;
    double codingRate;
    double preambleLength;
    bool implicitHeaderMode;
    double txPower;
    double sensitivity;

    // Método para calcular o Time on Air (ToA)
    double calculateToA(int payloadSize);

  protected:
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;


};

} // namespace physicallayer
} // namespace inet

#endif
