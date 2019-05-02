//---------------------------------------------------------------------------

#ifndef GraphH
#define GraphH
#include <vector>

#include "Node.h"
#include "Arc.h"

class Graph
{
	private:
	public:
		std::vector<Node*> nodes;
		std::vector<Conflict*> conflicts;


};
//---------------------------------------------------------------------------
#endif
