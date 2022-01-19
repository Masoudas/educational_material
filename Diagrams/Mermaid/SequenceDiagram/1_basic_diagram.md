```mermaid
sequenceDiagram
    participant B as Bob
    participant A as Alice
    A->>B: 1. Hello Bob
    B->>A: 2. Yeah. Whatever!
    activate B
    A->>B: Seriously, I activated you this time.
    B-->>A: An I'm deactivating myself!
    deactivate B