## Real time Ticket management system --> System Design.

1. Functional Requirements:
   -> A user should be able to view all tickets -> He should be able filter,sorting.
   -> When he clicks on any row -> It should open a side panel.
   -> User should be able to see real-time updates. [USP]

2. NON Functional Requiremnts:
   -> Performance -> Tickets to be consistent -> every read must fetch latest write. [Database point truth] -> latency should less.
   -> Scalabiltiy -> the no of tickets can be huge, agents -> grow in number.
   -> Security -> Authorized and Authenticated.
   -> Reliable -> If there is any failure -> Should display proper error message.

3. High-Level Arch:

   Client [REact] ----> RESTAPI ---> TicketService [Authorization, validation] ----> Primary Database --> Kafka --> Websockects --> Client listens to events.

4. Client [React]

-> resp for rendering a huge list of table. --> DOM is slow.
-> solution: 1. we can have a paginated data from server --> currPage -> 1 per page it will fetch only 100 Tickets. 2. Virtualization -> For rendering large list items. -> It will keep the data in memory and only renderes items that are on the view-port.
-> From Client for API Optimization:
-> React Query -> This will provide you with out of the box loading, error states, and it will also cache the data. [staletime, fetchonRegainWindowFocus, enable]
-> We will try to keep the components as dumb as possible ---> will push all the major logic part into re-usuable hooks.
-> React memo, useMemo and useCallback. --> will be used for re-render optimization.
-> Lazy Loading ->
-> When user clicks on any Row, A side panel pops up. -> Maybe it fetching a lot of additional data for the ticket [API call] + In-corporates AI Chat panel.
-> Lazy Load the whole component --> Till it loads we will use <suspense> to show a fallback UI.
-> Relaiblility:
-> Higher order components --> usecase would be to show a common loading indicators or for error logging.
-> access to ComponentDidCatch -> Error Boundary --> we will be implementing using Class Component by implementating the life-cycle events.
-> This will catch any errors and show a zero-state screen.
-> State management:
-> UI component => local state. like usestate -> Controlled component.
-> API caching --> React Query will maintain the cache.
-> Global Level --> 1. App level -> Redux or RTX -> state changes more frequently and at global level. 2. A particular DOM Tree in the application -> context API. --> If your state changes is less and it only needs to cover a part DOM.
-> Accessibility
-> JSX -> Semantic HTML, Add the keyboard naivagtion, ARIA LABEL and ROLES -> more info to the screen reader.

5. Backend Structure:
1. REST API service --> Stateless, scalable and it easy use.
1. Whenever a user lets say he updates any Ticket --> /ticket/Id -> PATCH or PUT method.
1. Task Service:
   1. Authorized this req. --> Is this user allowed to make change or not. 2. It should be validate if the payload is correct or not ? 3. It can go ahead and update the primary Database. 4. Trigger the update Event.

1. Database:

Which Database ? MYSQL => Super consistent, scalable , structured table approach.
optimization:
-> indexes: efficient quering. -> updateAt, status/priority, assignedTo.
-> If in Race conditions
-> What if 2 users are updating the same row ?
-> 2 Possible ways: 1. optimistic lock at the row level in database. ==> High traffic and conflict scenario efficient => blocking the DB. 2. {version: } in your ticket schema.
-> With every update --> we will in increment the version Id.
-> version -> 6 --> after update --> version -> 7.
-> other user a proper conflict message --> ask him to re-fetch the data.
Scaling Scerio:  
 -> This entire system is read heavy.
-> read replicas -> for reach functionality
-> master database -> handles write operations.
-> sharding:
range-based or hashed-based or geo-location.

5. Kafka Side:

   -> Why ? -> it acts as a decoupled, async message broker, scalability.
   -> Task service --> will emit an event --> {type: "ticket_Updated", version: '5', ticketId: '45', status: '', priority: ""}
   -> Pushed to kafka.
   -> Kafka Topic: "Tickets_Updates"
   partition key: ticket_ID.

6. WebSocket Arch: + Redis:

-> WebSocket will consume this event -> Who is the listener to this event --> send the event to that scoketId.
-> Client space:
-> After you load the intial data.
-> You will open a webscoket connection. ==> Auth Validation (JWT), Rate-limiters -> store the connection meta-data in redis.
userA: [ws_1001, ws_1002]
ticket:ticket_34 --> [ws_1001, ws_1002]; -> Fast, stores in-memory.
-> Ws.onMessage( (event) => merege the changes in the local state that stores the ticket details)
-> Befinite:
-> omits the use of polling.
-> Real-time updates. --> you will update the local state for tickets only if the version is different.
-> Client is aware of the changes --> It will render only the Row which is affected instead of re-rendering the whole list from scratch.

SOCKET.io -> .onMessage(), .close();
