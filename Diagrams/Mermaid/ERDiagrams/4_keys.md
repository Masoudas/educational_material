```mermaid
erDiagram
%% This feature is not working still in VS Code.
    CAR ||--o{ NAMED-DRIVER : allows
    PERSON ||--o{ NAMED-DRIVER : is

    CAR {
        string allowedDriver FK 'The license of the allowed driver'
        string registrationNumber
        string make
        string model
    }

    PERSON {
        string driversLicense PK 'The license #'
        string firstName
        string lastName
        int age
    }

```