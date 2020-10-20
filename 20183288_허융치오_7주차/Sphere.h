#pragma once

#include "Object_7.h"

class Sphere : public RenderableObject, public IUpdater
{
public:
	virtual void shutDown() override;
};