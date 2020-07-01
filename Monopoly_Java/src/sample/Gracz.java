package sample;

public class Gracz {
    int id;
    int pozycja;
    int kasa;
    boolean wiezienie;

    public Gracz(int id, int pozycja, int kasa,boolean wiezienie){
        this.id=id;
        this.pozycja=pozycja;
        this.kasa=kasa;
        this.wiezienie=wiezienie;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getPozycja() {
        return pozycja;
    }

    public void setPozycja(int pozycja) {
        this.pozycja = pozycja;
    }

    public int getKasa() {
        return kasa;
    }

    public void setKasa(int kasa) {
        this.kasa = kasa;
    }

    public boolean isWiezienie() {
        return wiezienie;
    }

    public void setWiezienie(boolean wiezienie) {
        this.wiezienie = wiezienie;
    }
}
