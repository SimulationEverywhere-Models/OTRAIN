/*******************************************************************
*
*  DESCRIPTION: class Generator
*
*  AUTHOR: Heather Morris
*
*  EMAIL: mailto:hmorris@connect.carleton.ca
*
*  DATE: 27/10/2010
*
*******************************************************************/

#ifndef __StationArrivalGenerator_H
#define __StationArrivalGenerator_H

/** include files **/
#include "atomic.h"     // class Atomic
#include "except.h"     // class InvalidMessageException

/** forward declarations **/
class Distribution ;

/** declarations **/
class StationArrivalGenerator : public Atomic
{
public:
	StationArrivalGenerator( const string &name = "StationArrivalGenerator" );				  // Default constructor

	// ~StationArrivalGenerator();

	virtual string className() const
		{return "StationArrivalGenerator";}

protected:
	Model &initFunction() ;

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	bool Bayview, CarlingUp, CarlingDown, CarletonUp, CarletonDown, ConfedUp, ConfedDown, Greenboro;
	int StationNumber;
	Port &StationNumberOut;


};	// class StationArrivalGenerator


#endif   //__StationArrivalGenerator_H
