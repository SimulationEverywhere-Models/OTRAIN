/*******************************************************************
*
*  DESCRIPTION: Header file for atomic model for the queues within the train model
*
*  AUTHOR: Heather Morris
*
*
*  DATE: 27/10/2010
*
*******************************************************************/

#ifndef __StationQueue_H
#define __StationQueue_H

#include <list>
#include "atomic.h"     // clase Atomic

class StationQueue : public Atomic
{
public:
	StationQueue( const string &name = "StationQueue" );
	virtual ~StationQueue() { }
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:

	Port &StationNumberIn;
	Port &PassengerIn;
	Port &PassengerOut;
	bool FillQueue, EmptyQueue;
	typedef list<Value> ElementList ;
	ElementList elements;
	int StationDestNumber;

};	// class InTrainQueue

// ** inline ** //
inline
string StationQueue::className() const
{
	return "StationQueue" ;
}

#endif   //__StationQueue_H
