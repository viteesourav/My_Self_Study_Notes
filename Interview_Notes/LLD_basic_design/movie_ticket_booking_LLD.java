import java.util.ArrayList;
import java.util.Date;
import java.util.List;

// Enum to represent seat status
enum Status {
    AVAILABLE, RESERVED
}

// Class representing a movie
class Movie {
    private int id;
    private String title;
    private String genre;
    private int duration; // Duration in minutes

    public Movie(int id, String title, String genre, int duration) {
        this.id = id;
        this.title = title;
        this.genre = genre;
        this.duration = duration;
    }

    public String getTitle() {
        return title;
    }

    public String getGenre() {
        return genre;
    }

    public int getDuration() {
        return duration;
    }
}

// Class representing a theater
class Theater {
    private int id;
    private String name;
    private List<Screen> screens;

    public Theater(int id, String name) {
        this.id = id;
        this.name = name;
        this.screens = new ArrayList<>();
    }

    public void addScreen(Screen screen) {
        screens.add(screen);
    }

    public List<Screen> getScreens() {
        return screens;
    }
}

// Class representing a screen in a theater
class Screen {
    private int id;
    private int capacity;
    private List<Show> shows;

    public Screen(int id, int capacity) {
        this.id = id;
        this.capacity = capacity;
        this.shows = new ArrayList<>();
    }

    public void addShow(Show show) {
        shows.add(show);
    }

    public List<Show> getShows() {
        return shows;
    }
}

// Class representing a movie show
class Show {
    private int id;
    private Movie movie;
    private Date startTime;
    private Date endTime;

    public Show(int id, Movie movie, Date startTime, Date endTime) {
        this.id = id;
        this.movie = movie;
        this.startTime = startTime;
        this.endTime = endTime;
    }

    public Movie getMovie() {
        return movie;
    }

    public Date getStartTime() {
        return startTime;
    }

    public Date getEndTime() {
        return endTime;
    }
}

// Class representing a seat in a theater
class Seat {
    private int id;
    private Status status;

    public Seat(int id) {
        this.id = id;
        this.status = Status.AVAILABLE;
    }

    public void reserve() {
        status = Status.RESERVED;
    }

    public void release() {
        status = Status.AVAILABLE;
    }

    public Status getStatus() {
        return status;
    }
}

// Class representing a booking
class Booking {
    private int id;
    private User user;
    private Show show;
    private List<Seat> seats;

    public Booking(int id, User user, Show show) {
        this.id = id;
        this.user = user;
        this.show = show;
        this.seats = new ArrayList<>();
    }

    public void addSeat(Seat seat) {
        seats.add(seat);
        seat.reserve();
    }

    public void removeSeat(Seat seat) {
        seats.remove(seat);
        seat.release();
    }

    public double getTotalPrice() {
        // Implement pricing logic
        return seats.size() * 10.0; // Example price per seat
    }
}

// Class representing a user
class User {
    private int id;
    private String name;
    private String email;
    private List<Booking> bookings;

    public User(int id, String name, String email) {
        this.id = id;
        this.name = name;
        this.email = email;
        this.bookings = new ArrayList<>();
    }

    public void createBooking(Booking booking) {
        bookings.add(booking);
    }

    public void cancelBooking(Booking booking) {
        bookings.remove(booking);
    }
}

// Class managing the online booking system
class OnlineBookingSystem {
    private List<Movie> movies;
    private List<Theater> theaters;
    private List<User> users;
    private List<Booking> bookings;

    public OnlineBookingSystem() {
        movies = new ArrayList<>();
        theaters = new ArrayList<>();
        users = new ArrayList<>();
        bookings = new ArrayList<>();
    }

    public List<Movie> searchMovies(String title) {
        // Search movies by title
        List<Movie> result = new ArrayList<>();
        for (Movie movie : movies) {
            if (movie.getTitle().equalsIgnoreCase(title)) {
                result.add(movie);
            }
        }
        return result;
    }

    public Booking bookTicket(User user, Show show, List<Seat> seats) {
        Booking booking = new Booking(bookings.size() + 1, user, show);
        for (Seat seat : seats) {
            booking.addSeat(seat);
        }
        user.createBooking(booking);
        bookings.add(booking);
        return booking;
    }
}

// Main class to run the online booking system
public class Main {
    public static void main(String[] args) {
        OnlineBookingSystem system = new OnlineBookingSystem();
        // Example usage (details omitted for brevity)
        // Add movies, theaters, screens, shows, and users
        // Make a booking
    }
}


/*

 *Great question! When an interviewer asks whether your code follows design principles and patterns, they're typically looking for how well the code adheres to best practices for object-oriented design and software architecture. Here’s how you can tackle this question for the Online Movie Booking System:

### **Design Principles**

1. **Single Responsibility Principle (SRP)**: 
   - **Observation**: Each class has a single responsibility. For example, `Movie` handles movie details, `Booking` manages booking details, and so on.
   - **Answer**: “Yes, the code follows the Single Responsibility Principle. Each class is designed to manage only one aspect of the system.”

2. **Open/Closed Principle (OCP)**:
   - **Observation**: The classes are designed to be open for extension but closed for modification. For instance, adding new features like promotions or discounts would involve creating new classes or methods without modifying existing ones.
   - **Answer**: “The system is designed with the Open/Closed Principle in mind. For example, new types of seat pricing or additional booking features can be added without changing the core classes.”

3. **Liskov Substitution Principle (LSP)**:
   - **Observation**: The system doesn’t currently use inheritance, but if you introduced a `VIPSeat` class extending `Seat`, it should be interchangeable without altering the correctness of the system.
   - **Answer**: “While the current implementation doesn’t use inheritance, if we were to extend classes in the future, such as adding a `VIPSeat`, it would be done in a way that adheres to the Liskov Substitution Principle.”

4. **Interface Segregation Principle (ISP)**:
   - **Observation**: The system doesn’t use interfaces, but each class has a focused set of methods. If interfaces were used, they would be designed to ensure that classes only implement methods they actually use.
   - **Answer**: “If interfaces were used, they would be designed to ensure that each class only implements the methods it needs, adhering to the Interface Segregation Principle.”

5. **Dependency Inversion Principle (DIP)**:
   - **Observation**: The system doesn’t explicitly use dependency injection, but components are loosely coupled. For example, `OnlineBookingSystem` depends on abstractions (`Movie`, `Theater`) rather than concrete implementations.
   - **Answer**: “The system is designed to follow the Dependency Inversion Principle by depending on abstractions rather than concrete implementations. Although dependency injection isn’t used, the code is structured to be loosely coupled.”

### **Design Patterns**

1. **Factory Pattern**:
   - **Observation**: The system does not use a Factory Pattern, but it could be implemented for creating objects like `Movie`, `Booking`, or `Show`.
   - **Answer**: “The current design does not explicitly use the Factory Pattern, but it could be applied to create instances of `Movie`, `Booking`, or `Show`, centralizing object creation.”

2. **Singleton Pattern**:
   - **Observation**: The `OnlineBookingSystem` class could be a candidate for the Singleton Pattern if only one instance is required throughout the application.
   - **Answer**: “Currently, the system doesn’t use the Singleton Pattern, but it could be applied to the `OnlineBookingSystem` class if we need a single instance across the application.”

3. **Observer Pattern**:
   - **Observation**: Not explicitly used, but could be used for notifying users about booking confirmations or show changes.
   - **Answer**: “The Observer Pattern is not used in this design, but it could be beneficial for features like notifying users of booking confirmations or show changes.”

4. **Strategy Pattern**:
   - **Observation**: The system does not use a Strategy Pattern, but it could be used for different pricing strategies or seat reservation algorithms.
   - **Answer**: “While the Strategy Pattern is not used, it could be applied to implement various pricing strategies or reservation algorithms.”

### **General Tips**

- **Be Honest**: If a pattern or principle isn't used, acknowledge it and explain how it could be incorporated.
- **Show Awareness**: Demonstrate an understanding of how these principles and patterns can be applied to improve the design.
- **Be Specific**: Provide concrete examples of how each principle or pattern would be used or how the design could be improved.

Feel free to ask if you need more examples or clarifications! 
 * 
 * 
 */



