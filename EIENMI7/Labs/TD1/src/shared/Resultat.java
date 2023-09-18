package shared;

import java.io.Serializable;

public class Resultat implements Serializable {
    int value;

    String cb = "5131301173727636";

    public Resultat(int value) {
        this.value = value;
    }

    public String getCb() {
        return cb;
    }

    public void setCb(String cb) {
        this.cb = cb;
    }

    @Override
    public String toString() {
        return "Result <value=" + value + ", cb=" + cb + ">";
    }
}
