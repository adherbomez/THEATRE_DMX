//---------------------------------------------------------------------------

#ifndef NodeH
#define NodeH
#include "Graph.h"
#include "Arc.h"

class Node
{
	private:
		int startInterval;
		int endInterval;
	public:
		static bool localCheckIntersection(Node * n1, Node * n2);
};
//---------------------------------------------------------------------------
#endif
