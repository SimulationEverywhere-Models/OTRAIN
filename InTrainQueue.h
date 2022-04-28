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

#ifndef __InTrainQueue_H
#define __InTrainQueue_H

#include <list>
#include "atomic.h"     // clase Atomic

class InTrainQueue : public Atomic
{
public:
	InTrainQueue( const string &name = "InTrainQueue" );
	virtual ~InTrainQueue() { }
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
string InTrainQueue::className() const
{
	return "InTrainQueue" ;
}

#endif   //__InTrainQueue_H
