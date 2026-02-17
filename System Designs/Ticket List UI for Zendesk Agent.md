## Ticket List UI for Zendesk Agent

-> Requirement Analysis

1. users ? -> internal support agents -> so desktop view.
2. scale ? -> how many tickets ? 50k-100k per account.-> tickets to multiple agents possible ?
3. updates ? -> Tickets needs to update. -> status / priority.
4. Need to include Accessibility -> Keyboard Nav + Screen readers

-> user flow:

1. Ticket List view (Primary) -> scrolling list (virtualization/ Pagination) + Tables [colId, Ticket Title, status, Priority, updateAt]
2. Filter Panel -> filter based on status, priority, assignedUser.
3. Ticket Detail -> Click on a Row -> Opens a side view with details.

-> Component Architecture:

1. <App>
    -> TicketPage -> Container.
     -> FilterBar
         -> TicketList [rendering + virtualization/pagintion]
         -> TicketRow  [Pure Presentation component + memo]
         -> Ticket Detail Panel  [Lazy loaded, code-split]

2. State Management
3. Ticket List Data: React Query + Redux -> shared + cacheable.
4. Filters: URL + Global state
5. Selected Ticket: Local State
6. Real-time update: Websocket Handler -> push-based.

Data Fetching methods:

1. cursor-based pagination.
   -> Fetch data from the url and pages changed in memory.
   -> Background refresh on focus / reconnect.

Real-time update:

1. websocket
   -> ticket.created or ticket.update
2. Merge in cache,
   -> update exisiting ticket, Insert new ticket at correct pos, Avoid duplicates.
