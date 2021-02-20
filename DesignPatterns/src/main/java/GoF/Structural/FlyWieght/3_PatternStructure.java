package GoF.Structural.FlyWieght;

/**
 * The participant class are shown here
 * 
 * class FlyweightFactory{
 *      getFlyweight(key){ // Key here is an intrinsic state.
 *          if (key exists){
 *              return the instance of key from the pool.
 *          }
 *          else{
 *              add the key to the pool and create class.
 *              return the new instance.
 *          }
 *      }
 * }
 * 
 * interface Flyweight{
 *      // This is the interface a client has to deal with.
 *      operation(extrinsicState)
 * }
 * 
 * class ConcreteFlyweight implements Flyweight{
 *      intrinsicState; // This is the desired intrinsic state we seek.
 *      operation(extrinsicState)
 * }
 * 
 * class UnSharedFlyweight implements Flyweight{
 *      // This class here is to indicate that we don't need to share all
 *      states using concrete implementation. Some states can remain unshared. The
 *      pattern does no force sharing.
 *      allState;   // 
 *      operation(extrinsicState)
 * }
 */