/**
In test driven development, we write tests before writing the code. The test are written in a way
that we like the code to be read and used.

For example with the following test, we're led to the a design decision to use only integers for rooms, 
and not using a room class.

Now consider TDD_1. A payroll is supposed to connect to a database to get the information regarding pay,
then talk to employer class to calculate his payment, and then tell the check writer to write a check
for him. With this design, it's unclear how to deal with a database, or how to write a check and verify it.
So naturally, we create interfaces, and then mock objects for those interfaces, as I did in the four polar project.
This is shown in TDD_2.gif, and note that there's a mock employer class, which is there for if the employer
class is in fact to complex for just testing the pay function (hence, we would partially implement it).
*/
class Name
{
    public void testMove()
    {
        WumpusGame g = new WumpusGame();
        g.connect(4,5,"E");
        g.setPlayerRoom(4);
        g.east();
        assertEquals(5, g.getPlayerRoom());
    }    
}
