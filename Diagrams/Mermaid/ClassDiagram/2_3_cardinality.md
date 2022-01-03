```mermaid
%% 1 Only 1
%% 0..1 Zero or One
%% 1..* One or more
%% * Many
%% n n {where n>1}
%% 0..n zero to n {where n>1}
%% 1..n one to n {where n>1}

classDiagram
    Customer "1" --> "*" Ticket
    Student "1" --> "1..*" Course
    Galaxy --> "many" Star : Contains
```
