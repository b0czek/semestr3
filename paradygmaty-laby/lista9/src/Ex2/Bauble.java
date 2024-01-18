package Ex2;

public class Bauble {
    BaubleType type;
    protected String color;
    protected String pattern;

    protected boolean isBroken = false;

    public Bauble(BaubleType type, String color, String pattern) {
        this.type = type;
        this.color = color;
        this.pattern = pattern;
    }

    @Override
    public String toString() {
        return "Bauble{" +
                "type=" + type +
                ", color='" + color + '\'' +
                ", pattern='" + pattern + '\'' +
                ", isBroken=" + isBroken +
                '}';
    }

    public BaubleType getType() {
        return type;
    }

    public void setType(BaubleType type) {
        this.type = type;
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
}
