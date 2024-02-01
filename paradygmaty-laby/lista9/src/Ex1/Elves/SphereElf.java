package Ex1.Elves;

import Ex1.Baubles.Bauble;
import Ex1.Baubles.BigSphereBauble;
import Ex1.Baubles.SmallSphereBauble;

import java.security.InvalidParameterException;
import java.util.ArrayList;

public class SphereElf extends Elf {
    protected int secondaryTypeBoxCapacity;
    protected int secondaryTypeCounter = 0;

    public SphereElf(int smallCapacity, int bigCapacity) {
        super(smallCapacity);
        this.secondaryTypeBoxCapacity = bigCapacity;
    }

    @Override
    boolean baubleFits(Bauble bauble) {
        return bauble instanceof SmallSphereBauble;
    }
    boolean baubleFitsSecondary(Bauble bauble) {
        return bauble instanceof BigSphereBauble;
    }

    @Override
    protected boolean isBoxFull(Bauble bauble) {
        if(bauble instanceof BigSphereBauble) {
            return secondaryTypeCounter == secondaryTypeBoxCapacity;
        }
        return (boxedBaubles.size() - secondaryTypeCounter) == boxCapacity;
    }

    @Override
    protected boolean canDrawAnotherBox() {
        return boxedBaubles.size() == (secondaryTypeBoxCapacity + boxCapacity);
    }

    @Override
    protected void addToBox(Bauble bauble) {
        if(bauble instanceof BigSphereBauble) {

            secondaryTypeCounter++;
        }
        super.addToBox(bauble);
  }

    @Override
    protected void drawNewBox() {
        secondaryTypeCounter = 0;
        super.drawNewBox();
    }

    @Override
    public void boxBauble(Bauble bauble) {
        if(bauble == null) {
            throw new InvalidParameterException();
        }

        if(!baubleFitsSecondary(bauble) || !tryToAddToBox(bauble)) {
            super.boxBauble(bauble);

        }
    }


}
