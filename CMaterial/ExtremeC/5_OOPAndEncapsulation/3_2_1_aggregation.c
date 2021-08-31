/**
 * As opposed to the composition case, in aggregation the life time of the contained object is independent of the
 * object is independent of the container. 
 * 
 * An example is given below, where a gun object is created independently of the player holding the gun. As such,
 * the gun is created somewhere else, and possibly destroyed long after the player has been destroyed.
 * 
 * Notice that we define the gun_t in the player header one more time so that we won't have to include the header
 * inside the player header, which in turn would bring the private functions of gun into that header as well.
 * 
 * A note from me: Notice that the pointer may not be null, but the gun object may have been invalidated in the 
 * memory (a dangling pointer.) This is something we should be cautious about. Perhaps not necessarily in the
 * case of gun and player, but it's possible for aggregates.
 */

/* The gun which is the aggregated object
#ifndef GUN_H
#define GUN_H

typedef int bool_t;
// Type forward declarations
struct gun_t;

// Memory allocator
struct gun_t* gun_new();

// Constructor
void gun_ctor(struct gun_t*, int);

// Destructor
void gun_dtor(struct gun_t*);

// Behavior functions
bool_t gun_has_bullets(struct gun_t*);

void gun_trigger(struct gun_t*);
void gun_refill(struct gun_t*);

#endif
*/

/* The container
#ifndef PLAYER_H
#define PLAYER_H

// Type forward declarations
struct player_t;
struct gun_t;

// Memory allocator
struct player_t* player_new();

// Constructor
void player_ctor(struct player_t*, const char*);

// Destructor
void player_dtor(struct player_t*);

// Behavior functions
void player_pickup_gun(struct player_t*, struct gun_t*);
void player_shoot(struct player_t*);
void player_drop_gun(struct player_t*);
#endif
*/