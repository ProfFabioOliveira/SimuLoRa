#include "inet/physicallayer/common/packetlevel/SignalTag_m.h"
#include <cmath>
#include "inet/common/Simsignals_m.h"

namespace inet {
namespace physicallayer {

Define_Module(LoRaRadio);

void LoRaRadio::initialize(int stage)
{
    // É importante chamar o initialize da classe base *antes* de fazer qualquer coisa
    ApskRadio::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        // Lê os parâmetros do NED
        spreadingFactor = par("spreadingFactor");
        bandwidth = par("bandwidth");
        codingRate = par("codingRate");
        preambleLength = par("preambleLength");
        implicitHeaderMode = par("implicitHeaderMode");
        txPower = par("txPower");
        sensitivity = par("sensitivity");
    }
}
void LoRaRadio::handleMessage(cMessage *msg)
{
      ApskRadio::handleMessage(msg);

}

double LoRaRadio::calculateToA(int payloadSize) {
    // Implementação da formula, você pode encontrar a formula na internet.
    double Tsym = std::pow(2.0, spreadingFactor) / bandwidth;
    double Tpreamble = (preambleLength + 4.25) * Tsym;
    int crc = 1; // 1 if CRC is enabled, 0 otherwise
    int IH = implicitHeaderMode ? 1 : 0; // 1 if implicit header mode is enabled, 0 otherwise
    int DE = (spreadingFactor >= 11) ? 1 : 0;   // 1 if low data rate optimization is enabled, 0 otherwise
    double payloadSymbNb = 8 + std::max(std::ceil((8 * payloadSize - 4 * spreadingFactor + 28 + 16 * crc - 20 * IH ) / (4.0 * (spreadingFactor - 2 * DE))) * codingRate, 0.0);
    double Tpayload = payloadSymbNb * Tsym;
    double ToA = Tpreamble + Tpayload;
    return ToA;

}

} // namespace physicallayer
} // namespace inet
