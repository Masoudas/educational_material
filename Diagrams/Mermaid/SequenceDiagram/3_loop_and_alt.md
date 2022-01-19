```mermaid
sequenceDiagram
    loop
    Alice-->>Bob: Call me!
    Bob-->>Alice: No!
    end
    alt:
    Alice-->>Bob: But what if you did?
    Bob->>Alice: No.
    else:
    Alice-->>Bob: But you could do it.
    Bob->>Alice: No!
    end
    opt Extra response
        Alice-->>Bob: I love you!
    end