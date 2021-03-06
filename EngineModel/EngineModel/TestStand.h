#pragma once
#include "Engines.h"

#define ABSOLUTE_ERROR 10e-2
#define MAX_TIME 1800

namespace standArrea
{
	template <typename T>
	class TestStand
	{
		int numberOfMandV;
		double engineTemperature;
		double ambientTemperature;
		T* engine;

	public:
		int StartEngine();
		TestStand(T& engine, const double ambientTemperature);
	};

	template<typename T>
	TestStand<T>::TestStand(T & engine, const double ambientTemperature)
	{
		numberOfMandV = 0;
		this->engine = &engine;
		this->engine->M = engine.startM[numberOfMandV];
		this->engine->V = engine.startV[numberOfMandV];
		engineTemperature = ambientTemperature;
		this->ambientTemperature = ambientTemperature;
	}


	template<typename T>
	int TestStand<T>::StartEngine()
	{
		double a = engine->M * engine->I;
		double eps = engine->overheatTemperature - engineTemperature;
		int time = 0;
		while (eps > ABSOLUTE_ERROR && time < MAX_TIME)
		{
			time++;
			engine->V += a;
			if (numberOfMandV < engine->startM.size() - 2)
				numberOfMandV += engine->V < engine->startV[numberOfMandV + 1] ? 0 : 1;
			double up = (engine->V - engine->startV[numberOfMandV]);
			double down = (engine->startV[numberOfMandV + 1] - engine->startV[numberOfMandV]);
			double factor = (engine->startM[numberOfMandV + 1] - engine->startM[numberOfMandV]);
			engine->M = up / down * factor + engine->startM[numberOfMandV];

			engineTemperature += engine->Vc(ambientTemperature, engineTemperature) + engine->Vh();

			a = engine->M * engine->I;

			eps = engine->overheatTemperature - engineTemperature;
		}
		return time;
	}

}