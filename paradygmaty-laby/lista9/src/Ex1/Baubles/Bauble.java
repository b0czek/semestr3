package Ex1.Baubles;

abstract public class Bauble {
    protected String color;
    protected String pattern;

    protected boolean isBroken = false;

    public Bauble(String color, String pattern) {
        this.color = color;
        this.pattern = pattern;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String getPattern() {
        return pattern;
    }

    public void setPattern(String pattern) {
        this.pattern = pattern;
    }

    public boolean isBroken() {
        return isBroken;
    }

    public void setBroken(boolean broken) {
        isBroken = broken;
    }

    @Override
    public String toString() {
        return "Bombka {" +
                "color='" + color + '\'' +
                ", pattern='" + pattern + '\'' +
                ", isBroken=" + isBroken +
                '}';
    }
}
