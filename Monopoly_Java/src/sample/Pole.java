package sample;

public class Pole {
    int id;
    int cena;
    int wlasnosc;
    int kara;
    int nagroda;
    int czynsz;

    public Pole(int id, int cena, int wlasnosc, int kara, int nagroda, int czynsz){
        this.id=id;
        this.cena = cena;
        this.wlasnosc = wlasnosc;
        this.kara = kara;
        this.nagroda = nagroda;
        this.czynsz = czynsz;

        }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getCena() {
        return cena;
    }

    public void setCena(int cena) {
        this.cena = cena;
    }

    public int getWlasnosc() {
        return wlasnosc;
    }

    public void setWlasnosc(int wlasnosc) {
        this.wlasnosc = wlasnosc;
    }

    public int getKara() {
        return kara;
    }

    public void setKara(int kara) {
        this.kara = kara;
    }

    public int getNagroda() {
        return nagroda;
    }

    public void setNagroda(int nagroda) {
        this.nagroda = nagroda;
    }

    public int getCzynsz() {
        return czynsz;
    }

    public void setCzynsz(int czynsz) {
        this.czynsz = czynsz;
    }
}
