#include <HAL/CAN.h>
#include <iostream>

class LiDAR
{
private:
public:
	LiDAR() {}

	void test() {
		uint32_t messageID = 1421;
		uint32_t messageIDMask = 0x1FFFFFFF;
		uint8_t data[8];
		uint8_t dataSize;
		uint32_t timeStamp;
		int32_t status;

		HAL_CAN_ReceiveMessage(&messageID, messageIDMask, data, &dataSize, &timeStamp, &status);

		std::cout << "messageID: " << messageID << "\n";
		std::cout << "dataSize: " << dataSize << "\n";
		std::cout << "data: " << data[0] << " " << data[1] << " " << data[2] << " " << data[3] << " " << data[4] << "\n";
	}
};
