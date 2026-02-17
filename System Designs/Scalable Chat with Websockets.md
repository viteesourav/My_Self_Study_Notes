## Complete System Design use-case:

1. Design a Scalable Chat / Notification System.

-- Design a system where:

1. user A sends a message.
2. user B receives the message instantly.
3. System should work even in Offline mode.

4. Requirement Analysis:

-- Functional:

1. Send and Receive messages support.
2. Real time message notification.
3. Offline supports.

-- NON-Functional:

1. Have multiple messages.
2. should scale with the no of users -> multiple users -> traffic.
3. security. -> Authentication.
4. Always Available -> eventual consistency is acceptable.

5. HLD Design:

Client (React) --> Web socket --> Web socket Service ---> Chat service --> Kafka --> Message Database.

Other:
-> Redis (shared Memory)
-> Load Balancer

3. Client

-- Client opens App --> a new connection is made to webSocket --> const ws = new WebSocket("wss://chat.app/ws");
-- Connection stays open.
-- Client sends token as { type: "Auth", token: "jwt-token" } --> Websockets validate + Extracts the userId.

4. Redis Cache.

-- Stores connection meta-data.
-- When a user logins --> socket:ws_1001 -> user_42, we can maintain a map inside Redis to store socket mapping.
-- eg: user:user_43 -> [ws_1001, ws_1002] --> user can be loggedin from multiple devices.

-- When user opens a chat --> He subscribe to chat:chat_789 and in the Redis it will have: chat:chat_789 => [ws_1001, ws_1002]
-- i.e User is currently viewing this chat.

5. Sending a message over web-socket:

-- when a user sends a message over ws: payload -> {type: "send_msg", chatId: "chat_789", messageId: "msg_890", text: "hi"}.
-- MessageId is generated at client level --> Imp for Retries & duplicates.

-- websocket receives it and forward it to chat service. ---> Chat service validate if the user is allowed, is message valid.

6. Kafka Needed.

-- why not directly write in DB ? ==> DB can be slow, If DB down msg lost, Hard to scale write.
-- Kafka
-> Acts like a durable broker between service & DB.
-- Chat service publish the msg on Kafka.
-> payload: {chatId: "chat_789", messageId: "msg_890", sender: "user_456", text: "hi"}.
-> Kafka topic:  
 Topic: chat-messages // this make sure they are for the same usecase.
Partition key: chatId // this group the events based on chat they belong to.

7. Database:

-- why needed ? => offline users, Message history, Reliablity.
-- Choice of DB ?
-> NoSQL ==> since Write heavy and Eventual consistency is acceptable.
-> Schema:
messages { chatId, timestamp, messageId, senderId, text }
-> Partition by chatId. ==> Can scale horizontally for huge data.
-> sorted by timestamped.

-- Kafka Consumer will reads the data --> write it to DB.

8. Message Delivery Real-Time

-- WebSocket handles the real-time message delivery.
-> Message stored -> delivery event is triggered.
-> WS service Reads message evt --> Ask Redis who is viewing this chat.
-> Redis replies with [ws_1001, ws_1002]
-> WS push messages to those sockets.

9. Client how it will consume ?

-> Client will include:
ws.onmessage = (evt) => {
const data = JSON.parse(evt.data);

      if(data.type === 'New_message') {
         addMessagetoUI(data.message);
      }

}
-> UI adds the new message to the message list.
-> Offline case:
-> If the user is offline -> messages are fetched when he connects.

10. Race Conditions:

1. Duplicate Messages:
   -- usecase: user sends message ==> Network fails ==> resend the message. ==> Duplicate message.
   -- solution:
   -> Message will have unique messageId from client.
   -> DB enforces unique messageId.
   -> SO If duplicates comes --> It is ignored.

1. Ordering ?
   -- Kafka has partition key as chatId.
   -> Messages are stored as per their respective chatId.
   -> Different Chats can process parallel.

1. Security ?

   -- JWT auth on websocket handshake, Chat service checks user if it's a member.
   -- Rate Limit messages per user.

1. Scalability ?
   -- websocket service: multiple ws servers, Redis shared state, Load balancer with sticky sessions.
   -- kafka: Increase Partitions, scale Consumers.
   -- Database: sharded by chatId, Horizontal scaling.

## AI Chat Service integration

--> websocket connections with AI Orchestraction service.
--> AI orchestraction service -> Context building, prompt Engineering + streamin token by token.
--> Websocket conncted to stream it back to UI.
