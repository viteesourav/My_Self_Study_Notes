## Complete System Design use-case:

1. Design a Real-time Ticket List / Dashboard - pagination, real-time updates, caching, FE Performance, APIs, Design.

-- Design a system where:

1. user sees a list of tickets.
2. Tickets updates in real-time.
3. List supports Paginated view / Infinite scroll.
4. Clicked on any Row he must be able to see details of

5. Requirement Analysis:

-- Functional:

1. users must see list of tickets.
2. Ticket must supports paginated or Infinite scroll.
3. Ticket updates in real time (status, priority comments)
4. filtering and sorting support.

-- Non-Function:

1. Millions of tickets.
2. Thousands of concurrent agents.
3. Low UI latency.
4. high availability.
5. secure.

6. High Level Design of the System:

Frontend (React) --> API Gateway ---> Ticket service --> Primary Database --> Event Stream (Kafka) --> WebSocket service --> Clients.

Additionally:
Redis - For caching (Fast access + co-ordination)
Load balancers - To handle multiple Requests.
Auth Service - Handle Authentication.
Rate Limiters - Limit a fix no of requests per second [saves from unwanted DDOS attacks]

3. Frontend Architecture
   -- Tickets can be too many -> rendering overhead --> use virtualization with Paginated API.
   -- Real-time update:

   - local state stores the tickets to be shown or React Query stores in cache.
   - After setting the data, Open a web socket connection -> read any events -> update specific ticket.
     -> WebSocket connection opened with login.
     -> it keeps a persistent TCP Connection, Allows backed to Push updates instantly.
     -> When update arrives -> Merge the update into existing ticket state.
     -> Re-render only affected row.

4. Backend Architecture

-- API Layer: RESTful services. [cacheable, simple paginated data]
-- Service Layer : Ticket Service
-> Validate ticket update,
-> enforce permission,
-> handle concurrent updates,
-> emit domain events.

5. Database Design

-- Database Choice: MySQL Reason: Structured data, Transactional, strong consistency (Every read gets the latest write)
-- schema Design:
tickets -> id, title, status, priority, assignedTo, updatedAt, createdAt, version.
-> indexes at -> updatedAt, status, priority and assignedTo. [For faster search]
-> Race Condition:
-> 2 users try to update the same row at the same time.
-> sol: 1. Each ticket has a version -> Client sends version it last read -> update successfully only if matches. 2. If no records -> conflict detected, re-fetch fresh data and try again.
-> Benefit: 1. No blocking, scales well and conflicts are rare so perfect solution.

6. Event Driven with Kafka

-- why need ?

1. Notify websocket service
2. Update cache.
3. trigger analytics.
4. Avoid tight coupling

-- why not directly from DB to WS ? -> no durability, no scaling, no retries.

-- Event pattern:

-> Database is the source of truth. Event comes after commit. ==> Ticket update transaction commits -> Ticket service publishes event to Kafka.
-> Event contains: type, ticketId, changes and version. [only type and important changes that happened]

7. WebSocket Service + Redis (IMP for real-time data read)

-- why ? Maintain active connection, Maps users to sockets and delivers events to the subscribed events.
-- Role:
-> On Connect: Authenticate using JWT, extract userId and TeamId, stores mapping in Redis eg: team:payment -> socketIds[]
-> why redis ? -> Shared across ws nodes, Fast, in-memory.
-- Event Delivery ?
-> Kafka consumers receives ticket event.
-> WebSocket service queries Redis: Which socket subscribed to this team ? --> Push events to that sockets.
-- Handle delays:
-> Each event has version, client applies updates only if it's a new version.

-- Redis stores which sockets are interested in which tickets or teams. When an update happens, WebSocket can push the message to the right connect browser.

8. Security:

-- Authentication: JWT tokens -> short expiry, refresh tokens.
-- Authorization: ticket visibility enforced in backend, WS subscription validated per user.
-- websocket security:
-> Auth during handshake.
-> Connection is dropped if handshake expires.
-> Rate limit messages.

9. Scalability

-- Backend: stateless APIs, Horizontal scaling, Read Replicas for DB.
-- WebSocket: Mutiple Ws servers, Load balancer for sticky sissions, Redis shared state.
-- Database: vertical scaling initially, Read replicas, Sharding by ticketId id needed [Most probably range based split]

DONE !!
