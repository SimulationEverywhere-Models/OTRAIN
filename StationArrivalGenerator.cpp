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

/** include files **/
#include "TrainModel.h"
#include "realfunc.h"// class Distribution
#include "distri.h"        // class Distribution
#include "StationArrival.h"       // base header
#include "message.h"       // class InternalMessage
#include "mainsimu.h"      // class Simulator
#include "strutil.h"       // str2Value( ... )

/*******************************************************************
* Function Name: Generator1
* Description: constructor
********************************************************************/
StationArrivalGenerator::StationArrivalGenerator( const string &name )
: Atomic( name )
, StationNumberOut( addOutputPort( STATION_NUMBER_OUT) )
{ }
/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &StationArrivalGenerator::initFunction()
{
	Bayview=true;
	CarlingUp=CarlingDown=CarletonUp=CarletonDown=ConfedUp=ConfedDown=Greenboro=false;
	holdIn( active, Time::Zero ) ;
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &StationArrivalGenerator::internalFunction( const InternalMessage & msg)
{
	if(Bayview)
	{
		Bayview=false;
		CarlingDown=true;
		holdIn( active,Time(0,3,45,0));
	}
	else if(CarlingDown){
		CarlingDown=false;
		CarletonDown=true;
		holdIn( active,Time(0,3,45,0));
	}
	else if (CarletonDown){
		CarletonDown=false;
		ConfedDown=true;
		holdIn( active,Time(0,3,45,0));
	}
	else if(ConfedDown){
		ConfedDown=false;
		Greenboro=true;
		holdIn( active,Time(0,3,45,0));
	}
	else if(Greenboro){
		Greenboro=false;
		ConfedUp=true;
		holdIn(active,Time(0,3,45,0));
	}
	else if(ConfedUp){
		ConfedUp=false;
		CarletonUp=true;
		holdIn(active,Time(0,3,45,0));
	}
	else if(CarletonUp){
		CarletonUp=false;
		CarlingUp=true;
		holdIn(active,Time(0,3,45,0));
	}
	else if(CarlingUp){
		CarlingUp=false;
		Bayview=true;
		holdIn(active,Time(0,3,45,0));
	}

	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &StationArrivalGenerator::outputFunction( const InternalMessage &msg )
{
	//The output will be a parsed number, where the first number is the station number and the second number is the
	//direction of the train
	//Bayview=1, Carling=2, Carleton=3, Confederation=4, Greenboro=5
	//Direction N->S (or down)=0, S->N (or up)=1;
	if(Bayview)
	{
		sendOutput( msg.time(), StationNumberOut, 01 ) ;
	}
	else if(CarlingDown){
		sendOutput( msg.time(), StationNumberOut, 02);
	}
	else if(ConfedDown){
		sendOutput( msg.time(), StationNumberOut, 04);
	}
	else if(CarletonDown){
		sendOutput( msg.time(), StationNumberOut, 03);
	}
	else if(Greenboro){
		sendOutput( msg.time(), StationNumberOut, 15);
	}
	else if(ConfedUp){
		sendOutput( msg.time(), StationNumberOut, 14);
	}
	else if(CarletonUp){
		sendOutput( msg.time(), StationNumberOut, 13);
	}
	else if(CarlingUp){
		sendOutput( msg.time(), StationNumberOut, 12);
	}

	return *this ;
}

Model &StationArrivalGenerator::externalFunction( const ExternalMessage &msg )
{

	return *this;
}


