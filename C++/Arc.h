//---------------------------------------------------------------------------

#ifndef ArcH
#define ArcH

class Node;

class Conflict
{
	public:
		Conflict(Node * n1,Node * n2);
		Node*n1;
		Node*n2;
};
//---------------------------------------------------------------------------
#endif
