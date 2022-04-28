/*******************************************************************
*
*  Description: Generator for People at each station
*
*  AUTOR: Heather Morris
*
*  FECHA: 27/10/2010
*
*******************************************************************/

/** Archivos de incluciones **/
#include "StationGenerator.h"       // Header base
#include "message.h"       // clase InternalMessage
#include "mainsimu.h"      // clase Simulator
#include "distri.h"        // clase Distribution
#include "strutil.h"       // str2Value( ... )
#include "time.h"
#include <stdio.h>

/*******************************************************************
* Function Name: Generador
* Description: constructor
********************************************************************/
StationGenerator::StationGenerator( const string &name )
: Atomic( name )
, PassengerInitial( addOutputPort( "PassengerInitial" ) )
{

	StationStartNumber = str2Value(MainSimulator::Instance().getParameter( description(), "StationStart" ));

try
{
dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribution" ) );
MASSERT( dist ) ;
for ( register int i = 0; i < dist->varCount(); i++ )
	{
	string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar( i ) ) ) ;
	dist->setVar( i, str2Value( parameter ) ) ;
	}

} catch( InvalidDistribution &e )
	{
	e.addText( "Your Model " + description() + " is having distribution Problems!!" ) ;
	e.print(cerr);
	MTHROW( e ) ;
} catch( MException &e )
	{
	MTHROW( e ) ;
	}
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &StationGenerator::initFunction()
{
	PassengerNumber=0;
	holdIn( active, Time(0, 0, 0, 0));

return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &StationGenerator::internalFunction( const InternalMessage & )
{

	WaitTime = fabs( distribution().get() );
	Station = fabs(distribution().get() );
	PassengerNumber++;
	if(Station < 10){
		PassengerOutput=PassengerNumber*100+StationStartNumber*10+1;
	}
	else if(Station >= 10 && Station < 12){
		PassengerOutput=PassengerNumber*100+StationStartNumber*10+2;
	}
	else if(Station >= 12 && Station < 18){
		PassengerOutput=PassengerNumber*100+StationStartNumber*10+3;
	}
	else if(Station >= 18 && Station < 20){
		PassengerOutput=PassengerNumber*100+StationStartNumber*10+4;
	}
	else{
		PassengerOutput=PassengerNumber*100+StationStartNumber*10+5;
	}
	holdIn(active, Time(0,0,WaitTime,0));

return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &StationGenerator::outputFunction( const InternalMessage &msg )
{
	if(PassengerOutput%10 == StationStartNumber){

	}
	else{
	sendOutput( msg.time(), PassengerInitial, PassengerOutput);
	}

return *this ;
}
/*******************************************************************
* Function Name:
********************************************************************/
StationGenerator::~StationGenerator()
{
delete dist;
}

