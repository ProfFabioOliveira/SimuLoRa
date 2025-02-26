
package simulora.LoRaPhy;

import inet.physicallayer.wireless.apsk.packetlevel.ApskRadio;


simple LoRaRadio extends ApskRadio{
    parameters:
        // Parâmetros LoRa
        int spreadingFactor @prompt("Spreading Factor (7-12)") = default(7);
        double bandwidth @prompt("Bandwidth (Hz)") = default(125000); // 125 kHz, 250 kHz, 500 kHz
        double codingRate @prompt("Coding Rate (4/5, 4/6, 4/7, 4/8)") = default(4.0/5.0);
        double preambleLength @prompt("Preamble Length") = default(8);
        bool implicitHeaderMode @prompt("Implicit Header Mode") = default(false);
        double txPower @prompt("Tx Power (dBm)") = default(20);
        double sensitivity @prompt("Receiver Sensitivity (dBm)") = default(-120);

        @class(LoRaRadio);
}