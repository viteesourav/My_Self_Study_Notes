import java.time.LocalDateTime;
import java.util.*;

enum VehicleType { CAR, BIKE, TRUCK }
enum SpotType { COMPACT, LARGE, HANDICAPPED }

class ParkingSpot {
    private int number;
    private SpotType type;
    private boolean isAvailable;

    public ParkingSpot(int number, SpotType type) {
        this.number = number;
        this.type = type;
        this.isAvailable = true;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public void occupy() {
        isAvailable = false;
    }

    public void vacate() {
        isAvailable = true;
    }

    public SpotType getType() {
        return type;
    }
}

class Vehicle {
    private String licensePlate;
    private VehicleType type;

    public Vehicle(String licensePlate, VehicleType type) {
        this.licensePlate = licensePlate;
        this.type = type;
    }

    public VehicleType getType() {
        return type;
    }
}

class Ticket {
    private String ticketId;
    private Vehicle vehicle;
    private ParkingSpot spot;
    private LocalDateTime entryTime;
    private LocalDateTime exitTime;

    public Ticket(String ticketId, Vehicle vehicle, ParkingSpot spot, LocalDateTime entryTime) {
        this.ticketId = ticketId;
        this.vehicle = vehicle;
        this.spot = spot;
        this.entryTime = entryTime;
    }

    public void setExitTime(LocalDateTime exitTime) {
        this.exitTime = exitTime;
    }

    public double calculateFee(ParkingRate rate) {
        long duration = java.time.Duration.between(entryTime, exitTime).toMinutes();
        return rate.getRate(vehicle.getType()) * duration;
    }
}

class ParkingRate {
    private Map<VehicleType, Double> rates;

    public ParkingRate() {
        rates = new HashMap<>();
        rates.put(VehicleType.CAR, 2.0);
        rates.put(VehicleType.BIKE, 1.0);
        rates.put(VehicleType.TRUCK, 3.0);
    }

    public double getRate(VehicleType type) {
        return rates.get(type);
    }
}

class ParkingLot {
    private String name;
    private List<ParkingSpot> spots;
    private List<Ticket> tickets;

    public ParkingLot(String name) {
        this.name = name;
        this.spots = new ArrayList<>();
        this.tickets = new ArrayList<>();
    }

    public void addSpot(ParkingSpot spot) {
        spots.add(spot);
    }

    public Ticket parkVehicle(Vehicle vehicle) {
        for (ParkingSpot spot : spots) {
            if (spot.isAvailable() && spot.getType() == SpotType.COMPACT) {
                spot.occupy();
                Ticket ticket = new Ticket(UUID.randomUUID().toString(), vehicle, spot, LocalDateTime.now());
                tickets.add(ticket);
                return ticket;
            }
        }
        return null; // No available spot
    }

    public void leaveParking(Ticket ticket) {
        ticket.setExitTime(LocalDateTime.now());
        ticket.spot.vacate();
        double fee = ticket.calculateFee(new ParkingRate());
        new Payment().processPayment(fee);
    }
}

class Payment {
    public void processPayment(double amount) {
        // Payment processing logic
        System.out.println("Paid: $" + amount);
    }
}

public class Main {
    public static void main(String[] args) {
        ParkingLot lot = new ParkingLot("City Center");
        lot.addSpot(new ParkingSpot(1, SpotType.COMPACT));
        lot.addSpot(new ParkingSpot(2, SpotType.COMPACT));

        Vehicle car = new Vehicle("ABC123", VehicleType.CAR);
        Ticket ticket = lot.parkVehicle(car);
        
        // Simulate some time passing
        try { Thread.sleep(2000); } catch (InterruptedException e) { e.printStackTrace(); }
        
        lot.leaveParking(ticket);
    }
}



/*
 * Sure! Let's go over the design principles and patterns used in the parking lot system's low-level design (LLD).

### **1. Design Principles**

#### **Single Responsibility Principle (SRP)**
- **Observation**: Each class in the parking lot system has a single responsibility.
  - **`ParkingLot`**: Manages the entire parking lot and coordinates between different components like parking floors and vehicles.
  - **`ParkingFloor`**: Manages a specific floor within the parking lot, including its parking spots.
  - **`ParkingSpot`**: Represents an individual parking spot and handles vehicle assignment.
  - **`Vehicle`**: Represents a vehicle and stores its type and registration details.
  - **`Ticket`**: Handles the parking ticket, including entry time and the associated vehicle.
  
- **Explanation**: This design follows SRP because each class focuses on one aspect of the parking lot system, making the code more modular and easier to maintain.

#### **Open/Closed Principle (OCP)**
- **Observation**: The classes are designed to be open for extension but closed for modification.
  - **Example**: If you wanted to introduce new types of vehicles or parking spots (e.g., electric vehicle charging spots), you could extend the `Vehicle` or `ParkingSpot` classes without modifying the existing code.
  
- **Explanation**: This allows for new features to be added without altering existing code, which minimizes the risk of introducing bugs.

#### **Liskov Substitution Principle (LSP)**
- **Observation**: The system uses inheritance where `ParkingSpot` could be a base class, and specific types of spots (e.g., `CompactSpot`, `LargeSpot`) could be derived from it.
  - **Example**: A `CompactSpot` or `LargeSpot` class can be used wherever a `ParkingSpot` is expected without breaking the application logic.
  
- **Explanation**: This principle ensures that derived classes can substitute base classes without affecting the correctness of the program.

#### **Interface Segregation Principle (ISP)**
- **Observation**: The system does not use interfaces in the code provided, but if it did, it would ensure that each class only implements the methods it needs.
  - **Example**: If the system were to use interfaces like `IParkingSpot` or `IVehicle`, each interface would be focused and would only include methods relevant to the specific type of object.
  
- **Explanation**: This principle prevents classes from being forced to implement methods they don't use, keeping the code clean and focused.

#### **Dependency Inversion Principle (DIP)**
- **Observation**: The code indirectly follows DIP by depending on abstractions (like `ParkingSpot`, `Vehicle`) rather than concrete implementations.
  - **Example**: The `ParkingLot` class could depend on the `ParkingSpot` abstraction rather than specific implementations like `CompactSpot` or `LargeSpot`.
  
- **Explanation**: This reduces the coupling between classes and makes the system more flexible and easier to extend.

### **2. Design Patterns**

#### **Factory Pattern**
- **Observation**: The Factory Pattern could be used in the system to create instances of `Vehicle` or `ParkingSpot` based on the type.
  - **Example**: A `VehicleFactory` could create `Car`, `Bike`, or `Truck` instances based on input, making the object creation process centralized and more manageable.
  
- **Explanation**: The Factory Pattern simplifies the object creation process and allows for easy extension when new types of vehicles or parking spots are added.

#### **Singleton Pattern**
- **Observation**: The `ParkingLot` class could be a Singleton, ensuring that only one instance of the parking lot exists throughout the application.
  - **Example**: This would be implemented by making the constructor of `ParkingLot` private and providing a static method to access the single instance.
  
- **Explanation**: The Singleton Pattern is useful when only one instance of a class is needed, such as managing a single parking lot in the application.

#### **Strategy Pattern**
- **Observation**: The Strategy Pattern could be applied to manage different parking strategies (e.g., nearest spot, random spot, etc.).
  - **Example**: Different parking strategies could be implemented as separate classes, and the `ParkingLot` class could choose which strategy to use at runtime.
  
- **Explanation**: The Strategy Pattern allows the parking lot to choose different ways to allocate parking spots without changing the core logic.

#### **Observer Pattern**
- **Observation**: Not used explicitly, but could be used for notifying users when a parking spot becomes available.
  - **Example**: A notification system could be implemented using the Observer Pattern to inform users when a parking spot is freed.
  
- **Explanation**: The Observer Pattern is helpful in scenarios where multiple objects need to be notified of changes to a particular object’s state, such as spot availability.

### **How to Tackle the Interview Question**

When asked if your code follows design principles and patterns, you can answer confidently:

1. **Acknowledge the Principles Used**:
   - “The design follows the Single Responsibility Principle as each class has a specific responsibility. For instance, `ParkingSpot` only manages individual parking spots, and `Vehicle` only stores vehicle details.”
   - “It adheres to the Open/Closed Principle by allowing extensions for new vehicle types or parking strategies without modifying existing code.”

2. **Discuss Patterns Applied or Could be Applied**:
   - “Although the code does not currently implement the Factory Pattern, it could be used to centralize the creation of `Vehicle` and `ParkingSpot` instances.”
   - “The `ParkingLot` could be implemented as a Singleton to ensure only one instance is used throughout the application, making the system more robust.”

3. **Highlight Areas for Improvement**:
   - “The system could benefit from the Strategy Pattern if different parking allocation strategies were required. This would allow the `ParkingLot` class to adapt to different strategies without changing its core logic.”

By structuring your response this way, you demonstrate a solid understanding of design principles and patterns and show the interviewer that you’re aware of how to apply them to improve the design.
 * 
 * 
 * 
 */