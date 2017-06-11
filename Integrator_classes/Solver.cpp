#include "Solver.h"


Solver::Solver()
{
	this->model  = nullptr;
	this->method = nullptr;
	this->denerateTime   = 0;
	this->step           = 0;
	this->sigFreq        = 0;
	this->sigRange       = 0;
	this->noiseIntensity = 0;
}

Solver::Solver(Method *methodA, Model *modelA)
{
	this->model  = modelA;
	this->method = methodA;
	this->denerateTime = 0;
	this->step = 0;
	this->sigFreq = 0;
	this->sigRange = 0;
	this->noiseIntensity = 0;
}

Solver::~Solver()
{
}

void Solver::setModel(Model *modelA)
{
	this->model = modelA;
}

void Solver::setMethod(Method *methodA)
{
	this->method = methodA;
}

void Solver::setMethodParams()
{
	this->method->setModel(this->model);
	this->method->setNoiseParam(sqrt(2 * this->noiseIntensity * this->step));
	this->method->setStep(this->step);
}

void Solver::setModelParams()
{
	this->model->setInitParams(this->sigRange, this->sigFreq);
}