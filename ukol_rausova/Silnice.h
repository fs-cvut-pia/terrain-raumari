#pragma once
#ifndef SILNICE_H
#define SILNICE_H

#include "Path.h"
#include "TerrainMap.h"
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <set>

class Silnice : public Path
{
public:
	Silnice(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);
	~Silnice();
	virtual bool find();
private:

};





#endif