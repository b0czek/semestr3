package Ex1.Elves;

import Ex1.Baubles.Bauble;

import java.security.InvalidParameterException;
import java.util.ArrayList;

public abstract class Elf {

    protected ArrayList<ArrayList<Bauble>> fullBoxes = new ArrayList<>();

    protected ArrayList<Bauble> boxedBaubles = new ArrayList<>();

    protected int boxCapacity;

    protected Elf neighbour = null;

    public Elf(int boxCapacity) {
        this.boxCapacity = boxCapacity;
    }

    abstract boolean baubleFits(Bauble bauble);

    protected boolean isBoxFull(Bauble bauble) {
        return boxCapacity == boxedBaubles.size();
    }
    protected boolean canDrawAnotherBox() {
        return true;
    }

    protected void addToBox(Bauble bauble) {
        System.out.println("bombka trafiła do pudełka");
        boxedBaubles.add(bauble);
    }

    protected void drawNewBox() {
        fullBoxes.add(boxedBaubles);
        boxedBaubles = new ArrayList<>();
    }

    protected boolean tryToAddToBox(Bauble bauble) {
        if(isBoxFull(bauble)) {
            return false;
        }

        addToBox(bauble);

        if(isBoxFull(bauble)) {
            System.out.println("pudełko zapełnione");
            if(canDrawAnotherBox()) {
                drawNewBox();
            }

        }
        return true;
    }

    public void boxBauble(Bauble bauble) {
        if(bauble == null) {
            throw new InvalidParameterException();
        }
        if(!baubleFits(bauble) || !tryToAddToBox(bauble)) {
            if(neighbour != null) {
                System.out.println("bombka została przekazana następnemu elfowi");
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
