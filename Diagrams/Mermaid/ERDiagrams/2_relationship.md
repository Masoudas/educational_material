```mermaid
erDiagram

%% Relationships may be classified as either identifying or non-identifying and these are rendered with either solid or dashed lines respectively. This is relevant when one of the entities in question can not have independent existence without the other. For example a firm that insures people to drive cars might need to store data on NAMED-DRIVERs. In modelling this we might start out by observing that a CAR can be driven by many PERSON instances, and a PERSON can drive many CARs - both entities can exist without the other, so this is a non-identifying relationship that we might specify in Mermaid as: PERSON }|..|{ CAR : "driver". Note the two dots in the middle of the relationship that will result in a dashed line being drawn between the two entities. But when this many-to-many relationship is resolved into two one-to-many relationships, we observe that a NAMED-DRIVER cannot exist without both a PERSON and a CAR - the relationships become identifying and would be specified using hyphens, which translate to a solid line:

% If you want the relationship label to be more than one word, you must use double quotes around the phrase
% If you don't want a label at all on a relationship, you must use an empty double-quoted string

    CAR ||--o{ NAMED-DRIVER : allows
    PERSON ||--o{ NAMED-DRIVER : is

```