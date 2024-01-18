package Ex1.Elves;

import Ex1.Baubles.Bauble;
import Ex1.Baubles.MushroomBauble;

public class MushroomBaubleElf  extends Elf{
    public MushroomBaubleElf(int boxCapacity) {
        super(boxCapacity);
    }


    @Override
    boolean baubleFits(Bauble bauble) {
        return bauble instanceof MushroomBauble;
    }
}
