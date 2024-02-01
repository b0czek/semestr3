package Ex2;

import java.util.ArrayList;




public class BaubleBox {
    private BaubleType baubleType;
    private int capacity;

    private ArrayList<Bauble> baubles = new ArrayList<>();

    public BaubleBox(BaubleType baubleType, int capacity) {
        this.baubleType = baubleType;
        this.capacity = capacity;
    }

    public BaubleType getBaubleType() {
        return baubleType;
    }

    public void setBaubleType(BaubleType baubleType) {
        this.baubleType = baubleType;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public ArrayList<Bauble> getBaubles() {
        return baubles;
    }



}
