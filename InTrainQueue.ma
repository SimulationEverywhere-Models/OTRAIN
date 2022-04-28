[top]
components : InTrainQueue@InTrainQueue
in : StationNumber
in : PassengerIn
out : PassengerOut

Link : StationNumber StationNumberIn@InTrainQueue
Link : PassengerIn PassengerIn@InTrainQueue
Link : PassengerOut@InTrainQueue PassengerOut

[InTrainQueue]
StationParameter : 3
