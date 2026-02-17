### System Design Challenge for Frontend

1. Data Related.

-- How is data fetched ? Pagination or Infinite scroll ?

## Design Approach:

-- server-side driven pagination approach, Fetch fields which are needed.
-- Introduced Caching of the API data -> React Query.

## Implementation:

-- Large List -> Pagination + Virtualization.
-- Repeated Access -> Client cache [local storage or Session Storage]
-- Unstable Network -> Retry + Fallback UI.

2. Performance Centric. [IMP]

-- How to scale for 100+ items ? Slow Devices ? avoid un-necessary re-renders ?

## Design Approach:

-- Rendering cost is higher ! So will go with memorization and virtualization.

## Implementation:

-- virtualization for large List [Memory Optimized]
-- useMemo and useCallback -> Handles re-renders due to props/state changes.
-- code splitting -> Lazy Loading, HOCs.

3. Scalability.

-- What happens for 10x traffic ? slow APIs ? re-usability of a feature ?

## Design Approach:

-- Component re-usability.
-- feature-based architecture.
-- Keep UI dumb ==> Push Logic into hooks so feature can scale without

## Implementation:

UI Components --> Container/ Hook Layer --> Data Layer (API/Cache) --> Backend.

4. State & Consistency.

-- handle more states ? Local or global ? avoid stale data ? if 2 user updates the same entity ?

## Design Appraoch:

--
UI state --> Local component level state.
API Data --> React Query.
Global UI state --> Redux [updated more freq] / Context [less freq updated]

-- Optimistic Handling --> Single point of truth i.e backend.
-- Failure handling --> Rollback.
-- Server reconciliation. ??

5. Real-time & Sync.

-- show live updates ? websockets integration ? avoid UI flickering ?

## Design Approach:

--  
 Backend --- websocket event ---> Update Cahche --> UI-rerenders.

-- WebSocket pushes events, not full data.
-- Update React Query / Redux store.
-- Handle reconnect + re-sync.

6. Reliability & UX

-- API fails ? user is offline ? zero-state screen ?

## Design:

-- Retry logic.
-- Skeleton UI
-- Graceful degradation.

## Implementation:

Every async interaction will have loading, error, and empty states to avoid poor UX.

7. Security & Maintainability.

-- Handle Auth ? role-based access or breaking changes ?

## Security:

-- token-based auth --> jwt
-- No sensitive information in frontend.
-- Role based rendering ui.

## Implementation

-- Feature based folder structure.
-- API versioning.
