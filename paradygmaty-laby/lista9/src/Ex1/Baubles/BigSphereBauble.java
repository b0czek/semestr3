package Ex1.Baubles;

public class BigSphereBauble extends Bauble {

    public BigSphereBauble(String color, String pattern) {
        super(color, pattern);
    }


    @Override
    public String toString() {
        return "Duża kula bombka {" +
                "color='" + color + '\'' +
                ", pattern='" + pattern + '\'' +
                ", isBroken=" + isBroken +
                '}';
    }
}
