#include "Siljekt.h"


Siljekt::Siljekt(TerrainMap& m, std::string name_in, Point start_in, Point finish_in) : Path(m, name_in, start_in, finish_in)
{
}

Siljekt::~Siljekt()
{
}

bool Siljekt::find()
{
	std::priority_queue<Point, std::vector<Point>, std::greater<Point>> to_search;
	//std::set<Point> visited;
	to_search.push(start);
	Matrix<int> navstiveno(map.nx, map.ny);
	Matrix<Point> cesty(map.nx, map.ny);
	navstiveno.zero();
	while (true)
	{
		Point tmp = to_search.top();
		//std::cout << tmp.x << " " << tmp.y << " " << to_search.size() << std::endl;
		if (tmp == finish)
		{
			cesty(start.x, start.y) = Point(0, 0);
			//std::cout << tmp.r << std::endl;
			while (cesty(tmp.x, tmp.y).x != 0 && cesty(tmp.x, tmp.y).y != 0)
			{
				path.push_back(tmp);
				tmp = cesty(tmp.x, tmp.y);
				//std::cout << tmp.x << " " << tmp.y << std::endl;
			}
			return true;
		}
		to_search.pop();
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				Point dir(i, j);
				Point n = tmp + dir;
				if (map.validCoords(n))
				{
					if ((i == 0 && j == 0) || (map.alt(n) > 0 && std::abs(map.alt(n) - map.alt(tmp)) / dir.length() / 1000 > 0.06)) { continue; } //|| map.alt(n) < 0 || std::abs(map.alt(n)- map.alt(tmp))/dir.length()/1000>0.08
					if (navstiveno(n.x, n.y) == 0)
					{
						float c = 1;
						if (map.alt(n) < 0) { c = 4; }
						navstiveno(n.x, n.y) = 1;
						n.r = tmp.r + dir.length()*c - (tmp - finish).length() + (n - finish).length();
						cesty(n.x, n.y) = tmp;
						to_search.push(n);
					}
				}
			}
		}
	}

	return false;

}
