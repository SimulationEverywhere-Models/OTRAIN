[top]
out : PassengerArrived
out : PassengerInitial
components : BayviewStation@StationGenerator CarlingStation@StationGenerator
components : CarletonStation@StationGenerator ConfedStation@StationGenerator
components : GreenboroStation@StationGenerator
components : BayviewQueue@StationQueue CarlingQueue@StationQueue
components : CarletonQueue@StationQueue ConfedQueue@StationQueue
components : GreenboroQueue@StationQueue
components : OTrain
Link :  PassengerInitial@BayviewStation PassengerIn@BayviewQueue
Link :  PassengerInitial@CarlingStation PassengerIn@CarlingQueue 
Link :  PassengerInitial@CarletonStation PassengerIn@CarletonQueue 
Link :  PassengerInitial@ConfedStation PassengerIn@ConfedQueue 
Link :  PassengerInitial@GreenboroStation PassengerIn@GreenboroQueue

Link : StationNumber@OTrain StationNumberIn@BayviewQueue
Link : StationNumber@OTrain StationNumberIn@CarlingQueue
Link : StationNumber@OTrain StationNumberIn@CarletonQueue
Link : StationNumber@OTrain StationNumberIn@ConfedQueue
Link : StationNumber@OTrain StationNumberIn@GreenboroQueue

Link : PassengerOut@BayviewQueue PassengerIn@OTrain
Link : PassengerOut@CarlingQueue PassengerIn@OTrain  
Link : PassengerOut@CarletonQueue PassengerIn@OTrain  
Link : PassengerOut@ConfedQueue PassengerIn@OTrain
Link : PassengerOut@GreenboroQueue PassengerIn@OTrain

Link : PassengerInitial@BayviewStation PassengerInitial
Link : PassengerInitial@CarlingStation PassengerInitial
Link : PassengerInitial@CarletonStation PassengerInitial
Link : PassengerInitial@ConfedStation PassengerInitial
Link : PassengerInitial@GreenboroStation PassengerInitial

Link : PassengerOut@OTrain PassengerArrived

[BayviewStation]
distribution : normal
mean : 15
deviation : 10
StationStart : 1
[CarlingStation]
distribution : normal
mean : 25
deviation : 10
StationStart : 2
[CarletonStation]
distribution : normal
mean : 15
deviation : 10
StationStart : 3
[ConfedStation]
distribution : normal
mean : 25
deviation : 10
StationStart : 4
[GreenboroStation]
distribution : normal
mean : 15
deviation : 10
StationStart : 5

[BayviewQueue]
StationParameter : 1
[CarlingQueue]
StationParameter : 2
[CarletonQueue]
StationParameter : 3
[ConfedQueue]
StationParameter : 4
[GreenboroQueue]
StationParameter : 5

[OTrain]
in : PassengerIn
out : PassengerOut
out : StationNumber
components : BayviewPassengers@InTrainQueue CarlingPassengers@InTrainQueue
components : CarletonPassengers@InTrainQueue ConfedPassengers@InTrainQueue
components : GreenboroPassengers@InTrainQueue
components : StationArrival@StationArrivalGenerator

Link : StationNumberOut@StationArrival StationNumberIn@BayviewPassengers
Link : StationNumberOut@StationArrival StationNumberIn@CarlingPassengers
Link : StationNumberOut@StationArrival StationNumberIn@CarletonPassengers
Link : StationNumberOut@StationArrival StationNumberIn@ConfedPassengers
Link : StationNumberOut@StationArrival StationNumberIn@GreenboroPassengers

Link : StationNumberOut@StationArrival StationNumber

Link : PassengerIn PassengerIn@BayviewPassengers
Link : PassengerIn PassengerIn@CarlingPassengers
Link : PassengerIn PassengerIn@CarletonPassengers
Link : PassengerIn PassengerIn@ConfedPassengers
Link : PassengerIn PassengerIn@GreenboroPassengers

Link : PassengerOut@BayviewPassengers PassengerOut
Link : PassengerOut@CarlingPassengers PassengerOut
Link : PassengerOut@CarletonPassengers PassengerOut
Link : PassengerOut@ConfedPassengers PassengerOut
Link : PassengerOut@GreenboroPassengers PassengerOut

[BayviewPassengers]
StationParameter : 1
[CarlingPassengers]
StationParameter : 2
[CarletonPassengers]
StationParameter : 3
[ConfedPassengers]
StationParameter : 4
[GreenboroPassengers]
StationParameter : 5

