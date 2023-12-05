#pragma once
#ifndef SILJEKT_H
#define SILJEKT_H

#include "Path.h"
#include "TerrainMap.h"
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <set>

class Siljekt : public Path
{
public:
	Siljekt(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);
	~Siljekt();
	virtual bool find();
private:

};




#endif