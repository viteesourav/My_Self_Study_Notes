import java.util.ArrayList;
import java.util.List;

// Enum to represent direction
enum Direction {
    UP, DOWN, NONE
}

// Enum to represent elevator status
enum Status {
    MOVING, STOPPED
}

// Class representing an elevator
class Elevator {
    private int id; // Elevator ID
    private int currentFloor; // Current floor
    private Direction direction; // Current direction
    private Status status; // Current status

    public Elevator(int id) {
        this.id = id;
        this.currentFloor = 0; // Assume starting at floor 0
        this.direction = Direction.NONE;
        this.status = Status.STOPPED;
    }

    public void moveToFloor(int floor) {
        // Implement logic to move elevator to the specified floor
        this.currentFloor = floor;
        this.status = Status.MOVING;
        System.out.println("Elevator " + id + " moving to floor " + floor);
        // After moving
        this.status = Status.STOPPED;
    }

    public int getCurrentFloor() {
        return currentFloor;
    }

    public Direction getDirection() {
        return direction;
    }

    public Status getStatus() {
        return status;
    }
}

// Class representing a floor
class Floor {
    private int floorNumber; // Floor number
    private List<Request> requests; // List of requests from this floor

    public Floor(int floorNumber) {
        this.floorNumber = floorNumber;
        this.requests = new ArrayList<>();
    }

    public void addRequest(Request request) {
        requests.add(request);
    }

    public List<Request> getRequests() {
        return requests;
    }
}

// Class representing a request
class Request {
    private int sourceFloor; // Source floor
    private int destinationFloor; // Destination floor
    private Direction direction; // Direction of request

    public Request(int sourceFloor, int destinationFloor, Direction direction) {
        this.sourceFloor = sourceFloor;
        this.destinationFloor = destinationFloor;
        this.direction = direction;
    }

    public int getSource() {
        return sourceFloor;
    }

    public int getDestination() {
        return destinationFloor;
    }

    public Direction getDirection() {
        return direction;
    }
}

// Class managing the elevator system
class ElevatorSystem {
    private List<Elevator> elevators; // List of elevators
    private List<Floor> floors; // List of floors

    public ElevatorSystem(int numElevators, int numFloors) {
        elevators = new ArrayList<>();
        floors = new ArrayList<>();

        // Initialize elevators
        for (int i = 0; i < numElevators; i++) {
            elevators.add(new Elevator(i));
        }

        // Initialize floors
        for (int i = 0; i < numFloors; i++) {
            floors.add(new Floor(i));
        }
    }

    public void requestElevator(int floor, Direction direction) {
        // Implement logic to handle elevator requests
        System.out.println("Request received for floor " + floor + " in direction " + direction);
        Request request = new Request(floor, floor, direction);
        assignElevator(request);
    }

    private void assignElevator(Request request) {
        // Implement logic to assign an elevator to a request
        Elevator bestElevator = elevators.get(0); // For simplicity, select the first elevator
        bestElevator.moveToFloor(request.getSource());
        System.out.println("Elevator " + bestElevator.getCurrentFloor() + " assigned to request.");
    }
}

// Main class to run the elevator system
public class Main {
    public static void main(String[] args) {
        ElevatorSystem system = new ElevatorSystem(3, 5); // 3 elevators, 5 floors
        system.requestElevator(2, Direction.UP);
    }
}
