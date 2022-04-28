/*******************************************************************
*
*  DESCRIPCION: Header File for StationGenerator
*
*  AUTOR: Heather Morris
*
*
*  FECHA: 27/10/2010
*
*******************************************************************/

#ifndef __StationGenerator_H
#define __StationGenerator_H

/** Archivos de inclucion **/
#include "atomic.h"     // clase Atomic
#include "except.h"     // clase InvalidMessageException

class Distribution ;

/** declaraciones **/
class StationGenerator : public Atomic
{
public:
	StationGenerator( const string &name = "StationGenerator" );

	~StationGenerator();

	virtual string className() const
		{return "StationGenerator";}

protected:
	Model &initFunction() ;

	Model &externalFunction( const ExternalMessage & )
			{throw InvalidMessageException();}

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	Port &PassengerInitial ;
	double WaitTime;
	int Station,PassengerNumber, PassengerOutput, StationStartNumber;
	Distribution *dist ;

	Distribution &distribution()
			{return *dist;}

};	// clase Generador


#endif   //__StationGenerator_H
