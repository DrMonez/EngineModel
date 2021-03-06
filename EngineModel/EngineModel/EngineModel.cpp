#include "TestStand.h"
#include "Communication.h"

int main()
{
	double ambientTemperature = consoleCommunication::ReadTemperature();
	engines::InternalCombustionEngine engine;
	standArrea::TestStand<engines::InternalCombustionEngine> stand(engine, ambientTemperature);
	consoleCommunication::WriteTime(stand.StartEngine());
	return 0;
}
