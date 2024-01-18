package Ex1.Elves;

import Ex1.Baubles.Bauble;
import Ex1.Baubles.BigSphereBauble;

import java.security.InvalidParameterException;
import java.util.ArrayList;

public abstract class Elf {
    protected ArrayList<Bauble> boxedBaubles = new ArrayList<>();

    protected int boxCapacity;

    protected Elf neighbour = null;

    public Elf(int boxCapacity) {
        this.boxCapacity = boxCapacity;
    }

    abstract boolean baubleFits(Bauble bauble);

    public void boxBauble(Bauble bauble) {
        if(bauble == null) {
            throw new InvalidParameterException();
        }
        if(baubleFits(bauble)) {
            if(boxedBaubles.size() < boxCapacity) {
                System.out.println("bombka trafiła do pudełka");
                boxedBaubles.add(bauble);
                if(boxedBaubles.size() == boxCapacity) {
                    System.out.println("pudełko pełne");

                }
            }
            else {
                System.out.println("brak miejsca w pudełku na ten rodzaj bombki");
            }
        } else {
            if(neighbour != null) {
                System.out.println("bombka została przekaza następnemu elfowi");
                neighbour.boxBauble(bauble);
            }
            else {
                bauble.setBroken(true);
                System.out.println("bombka trafiła na podłoge");
            }
        }
    }



    public ArrayList<Bauble> getBoxedBaubles() {
        return boxedBaubles;
    }

    public int getBoxCapacity() {
        return boxCapacity;
    }

    public Elf getNeighbour() {
        return neighbour;
    }

    public void setNeighbour(Elf neighbour) {
        this.neighbour = neighbour;
    }


}
