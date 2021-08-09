/**
 * If a class member is not initialized properly,  its members don't have a value. In fact because the memory is 
 * allocated to the class, it just contains garbage values.
 * 
 * Always make sure to fully initialize the members of the class, and never let them hanging. In particular, recall
 * the famous Q_Object pointer member which you didn't initialize, and caused all sorts of problems.
 */