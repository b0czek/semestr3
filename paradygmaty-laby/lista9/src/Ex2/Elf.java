package Ex2;

import java.security.InvalidParameterException;
import java.util.ArrayList;
import java.util.List;

public class Elf {

    protected List<BaubleBox> collectedBaubles = new ArrayList<>();
    protected List<BaubleBoxParams> collectedParams;

    protected Elf neighbour = null;

    public Elf(List<BaubleBoxParams> collectedParams) {
        this.collectedParams = collectedParams;
        createBoxes();
    }

    private void createBoxes() {
        collectedParams
                .forEach(params -> collectedBaubles.add(new BaubleBox(params.type, params.capacity)));
    }
    private boolean allFull() {
        return collectedBaubles.stream().allMatch(box -> box.getCapacity() == box.getBaubles().size());
    }


    public void boxBauble(Bauble bauble) {
        if(bauble == null) {
            throw new InvalidParameterException();
        }
        for(int i = 0 ; i < collectedBaubles.size(); i++)
        {
            BaubleBox box = collectedBaubles.get(i);
            if(box.getBaubleType() == bauble.getType()) {
                if(box.getCapacity() > box.getBaubles().size()) {
                    System.out.println("bombka trafiła do pudełka");
                    box.getBaubles().add(bauble);
                    if(allFull()) {
                        System.out.println("pudełko pełne");
                        collectedBaubles = new ArrayList<>();
                        createBoxes();
                    }
                    return;
                }
            }
        }
        if(neighbour != null) {
            System.out.println("bombka została przekaza następnemu elfowi");
            neighbour.boxBauble(bauble);
        }
        else {
            bauble.setBroken(true);
            System.out.println("bombka trafiła na podłoge");
        }

    }



    public void setNeighbour(Elf neighbour) {
        this.neighbour = neighbour;
    }


}
