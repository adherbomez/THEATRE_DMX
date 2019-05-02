//---------------------------------------------------------------------------

#pragma hdrstop

#include "Node.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


	bool Node::localCheckIntersection(Node * n1, Node * n2)
	{
        return n2->startInterval<n1->endInterval && n1->startInterval<n2->endInterval;
	}
