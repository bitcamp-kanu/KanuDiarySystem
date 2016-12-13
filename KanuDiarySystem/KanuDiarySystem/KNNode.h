#pragma once

class KNNode
{
	friend class KNList;

private :
	KNNode *next;

public :
	KNNode();
	virtual ~KNNode();
};