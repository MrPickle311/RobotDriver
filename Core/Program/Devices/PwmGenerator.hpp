#pragma once

#include <cstdint>

namespace Program
{

class PwmGenerator
{
public:
	PwmGenerator();
	virtual ~PwmGenerator() = default;
	PwmGenerator(const PwmGenerator &other) = delete;
	PwmGenerator(PwmGenerator &&other) = delete;
	PwmGenerator& operator=(const PwmGenerator &other) = delete;
	PwmGenerator& operator=(PwmGenerator &&other) = delete;
public:

	void startGenerating();
	void stopGenerating();

	void setPwmSignalFilling(uint16_t filling);

	static PwmGenerator& getInstance();
};

}
