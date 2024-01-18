package Ex2;

import java.security.InvalidParameterException;
import java.util.ArrayList;

public class Elf {
    protected BaubleType collectedBaublesType;
    protected ArrayList<Bauble> boxedBaubles = new ArrayList<>();

    protected int boxCapacity;

    protected Elf neighbour = null;

    public Elf(BaubleType collectedBaublesType, int boxCapacity) {
        this.collectedBaublesType = collectedBaublesType;
        this.boxCapacity = boxCapacity;
    }


    public void boxBauble(Bauble bauble) {
        if(bauble == null) {
            throw new InvalidParameterException();
        }
        if(bauble.getType() == collectedBaublesType) {
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


    public BaubleType getCollectedBaublesType() {
        return collectedBaublesType;
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
