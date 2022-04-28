/*******************************************************************
*
*  DESCRIPCION: Atomic Model of in Train Queue
*
*  AUTOR: Heather Morris
*
*  FECHA: 27/10/2010
*
*******************************************************************/

#include "StationQueue.h"      // clase InTrainQueue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )
#include <stdlib.h>
#include <stdio.h>

/*******************************************************************
* Function Name: InTrainQueue
* Description:
********************************************************************/
StationQueue::StationQueue( const string &name )
: Atomic( name )
, StationNumberIn( addInputPort( "StationNumberIn" ) )
, PassengerIn( addInputPort( "PassengerIn" ) )
, PassengerOut( addOutputPort( "PassengerOut" ) )
{
	StationDestNumber = str2Value(MainSimulator::Instance().getParameter( description(), "StationParameter" ));
}

/*******************************************************************
* Function Name: initFunction
* Description:
* Precondition:
********************************************************************/
Model &StationQueue::initFunction()
{
FillQueue=EmptyQueue=false;
elements.erase( elements.begin(), elements.end() ) ;
passivate();

return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &StationQueue::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == PassengerIn && !EmptyQueue){

			int number;
			number = static_cast<int>(msg.value());
			if(number%10 != StationDestNumber){
				FillQueue=true;
				elements.push_back( msg.value() ) ;
				holdIn(active, Time(0,0,0,0));
			}
		}


	if( (msg.port() == StationNumberIn )){

		int number;
		number = static_cast<int>(msg.value());
		if(number%10 == StationDestNumber && elements.size() != 0){
			EmptyQueue=true;
			holdIn(active, Time(0,0,0,25));
		}
	}

return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &StationQueue::internalFunction( const InternalMessage & )
{

	if(EmptyQueue){
		elements.pop_front();
		FillQueue=false;
		if (elements.size() > 0){
			holdIn(active, Time(0,0,0,25));

			EmptyQueue=true;
		}
		else {
			EmptyQueue=false;
			passivate();
		}

	}

	if(FillQueue){
		FillQueue=false;
		passivate();
	}

return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &StationQueue::outputFunction( const InternalMessage &msg )
{

	if(EmptyQueue && elements.size() >0){
		sendOutput(msg.time(), PassengerOut, elements.front());
	}

return *this ;
}
