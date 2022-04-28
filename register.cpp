/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Heather Morris
*
*  EMAIL: hmorris@connect.carleton.ca
*
*  DATE: 27/10/2010
*
*******************************************************************/

#include "modeladm.h"
#include "mainsimu.h"
#include "StationArrival.h" // class Generator
#include "InTrainQueue.h"
#include "StationGenerator.h"
#include "StationQueue.h"


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic(NewAtomicFunction<StationArrivalGenerator>() , "StationArrivalGenerator" ) ;
	SingleModelAdm::Instance().registerAtomic(NewAtomicFunction<InTrainQueue>() , "InTrainQueue" ) ;
	SingleModelAdm::Instance().registerAtomic(NewAtomicFunction<StationGenerator>() , "StationGenerator") ;
	SingleModelAdm::Instance().registerAtomic(NewAtomicFunction<StationQueue>() , "StationQueue") ;
	//SingleModelAdm::Instance().registerAtomic(NewAtomicFunction<Searcher>() , "Searcher") ;
	//SingleModelAdm::Instance().registerAtomic(NewAtomicFunction<Conveyor>() , "Conveyor") ;
}
