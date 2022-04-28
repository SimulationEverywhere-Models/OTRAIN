[top]
components : StationQueue@StationQueue
in : StationNumber
in : PassengerIn
out : PassengerOut

Link : StationNumber StationNumberIn@StationQueue
Link : PassengerIn PassengerIn@StationQueue
Link : PassengerOut@StationQueue PassengerOut

[StationQueue]
StationParameter : 3
