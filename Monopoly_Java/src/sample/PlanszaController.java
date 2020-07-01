package sample;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.shape.Circle;
import java.util.Random;

public class PlanszaController {

    @FXML                                       //wstrzykiwanie elementów interfejsu
    private Button rzutK;
    @FXML
    private Button kup;
    @FXML
    private Button koniectury;
    @FXML
    private Circle pion1;
    @FXML
    private Circle pion2;
    @FXML
    private Label tpole;
    @FXML
    private Label twlasciciel;
    @FXML
    private Label tcena;
    @FXML
    private Label tczynsz;
    @FXML
    private Label stankonta;
    @FXML
    private Label stanKontaAI;
    @FXML
    private Label wynikRzutu;


    Pole pole0 = new Pole(0, 0, -1, 0, 0, 0);           //Deklaracja Obiektów Pól
    Pole pole1 = new Pole(1, 80, 0, 0, 0, 40);
    Pole pole2 = new Pole(2, 100, 0, 0, 0, 50);
    Pole pole3 = new Pole(3, 0, -1, 0, 100, 0);
    Pole pole4 = new Pole(4, 130, 0, 0, 0, 70);
    Pole pole5 = new Pole(5, 0, -1, 150, 0, 0);
    Pole pole6 = new Pole(6, 0, -1, 0, 0, 0);
    Pole pole7 = new Pole(7, 150, 0, 0, 0, 90);
    Pole pole8 = new Pole(8, 160, 0, 0, 0, 100);
    Pole pole9 = new Pole(9, 0, -1, 130, 0, 0);
    Pole pole10 = new Pole(10, 180, 0, 0, 0, 120);
    Pole pole11 = new Pole(11, 0, -1, 0, 160, 0);
    Pole pole12 = new Pole(12, 0, -1, 0, 0, 0);
    Pole pole13 = new Pole(13, 200, 0, 0, 0, 140);
    Pole pole14 = new Pole(14, 0, -1, 0, 160, 0);
    Pole pole15 = new Pole(15, 210, 0, 0, 0, 0);
    Pole pole16 = new Pole(16, 230, 0, 0, 0, 160);
    Pole pole17 = new Pole(17, 0, -1, 180, 0, 0);
    Pole pole18 = new Pole(18, 0, -1, 0, 0, 0);
    Pole pole19 = new Pole(19, 240, 0, 0, 0, 170);
    Pole pole20 = new Pole(20, 260, 0, 0, 0, 180);
    Pole pole21 = new Pole(21, 0, -1, 0, 210, 0);
    Pole pole22 = new Pole(22, 280, 0, 0, 0, 190);
    Pole pole23 = new Pole(23, 0, -1, 200, 0, 0);

    Pole[] pl = {pole0, pole1, pole2, pole3, pole4, pole5, pole6, pole7, pole8, pole9, pole10, pole11, pole12,
            pole13, pole14, pole15, pole16, pole17, pole18, pole19, pole20, pole21, pole22, pole23};


    Gracz gracz = new Gracz(1, 0, 2000, false);             //Deklaracja obiektów graczy
    Gracz ai = new Gracz(2, 0, 2000, false);

    Random generator = new Random();

    public void procesRuchGracza(){
        int lx = 714, ly = 715, lyy = 115, lxx = 114;

        int poz = gracz.getPozycja();
        int rzut = 0;
        rzut = 1 + generator.nextInt(5);
        wynikRzutu.setText("Wynik Rzutu: "+(Integer.toString(rzut)));
        poz = poz + rzut;


        if (poz > 23) {
            poz = poz - 23;
            int start = 250;
            int kasa = gracz.getKasa();
            kasa = kasa + start;
            gracz.setKasa(kasa);
            stankonta.setText(Integer.toString(gracz.getKasa())+"$");
        }

        if (poz == 18) {                                                                //więzienie
            poz = 6;
            gracz.setWiezienie(true);
        }

        if (poz >= 0 && poz <= 6) {                                                    // ruch pionka gracza
            pion1.setLayoutY(715);
            lx = lx - poz * 100;
            pion1.setLayoutX(lx);
        }
        if (poz >= 7 && poz <= 12) {
            pion1.setLayoutX(114);
            ly = ly - (poz - 6) * 100;
            pion1.setLayoutY(ly);
        }
        if (poz >= 13 && poz <= 18) {
            pion1.setLayoutY(115);
            lxx = lxx + (poz - 12) * 100;
            pion1.setLayoutX(lxx);
        }
        if (poz >= 19 && poz <= 23) {
            pion1.setLayoutX(714);
            lyy = lyy + (poz - 18) * 100;
            pion1.setLayoutY(lyy);
        }

        gracz.setPozycja(poz);
        tpole.setText("Pole: " + Integer.toString(poz));
        tcena.setText("Cena: " + Integer.toString(pl[poz].getCena()));
        tczynsz.setText("Czynsz: " + Integer.toString(pl[poz].getCzynsz()));
        if (pl[poz].getWlasnosc() == 0) twlasciciel.setText("Właściciel: brak");
        else if (pl[poz].getWlasnosc() == 1) twlasciciel.setText("Właściciel: Gracz");
        else if (pl[poz].getWlasnosc() == 2) twlasciciel.setText("Właściciel: AI");
        else {
            twlasciciel.setText(" ");
            tcena.setText(" ");
            tczynsz.setText(" ");
        }

        if (pl[poz].getWlasnosc() == 0 && gracz.getKasa()>pl[poz].getCena())
            kup.setDisable(false);
        else
            kup.setDisable(true);

        if (pl[poz].getWlasnosc() == 2) {
            gracz.setKasa(gracz.getKasa() - pl[poz].getCzynsz());
            ai.setKasa(ai.getKasa()+pl[poz].getCzynsz());
            System.out.print("Płacisz czynsz " + pl[poz].getCzynsz() + "$!\n");
            stankonta.setText(Integer.toString(gracz.getKasa())+"$");
        }

        if (pl[poz].getKara() != 0) {
            int kasa = gracz.getKasa();
            kasa = kasa - pl[poz].getKara();
            gracz.setKasa(kasa);
            System.out.print("Straciłeś " + pl[poz].getKara() + "$!\n");
            stankonta.setText(Integer.toString(gracz.getKasa())+"$");
        }

        if (pl[poz].getNagroda() != 0) {
            int kasa = gracz.getKasa();
            kasa = kasa + pl[poz].getNagroda();
            gracz.setKasa(kasa);
            System.out.print("Zdobyłeś " + pl[poz].getNagroda() + "$!\n");
            stankonta.setText(Integer.toString(gracz.getKasa())+"$");
        }


        System.out.print("Gracz:\npozycja:" + gracz.getPozycja() + "\n" + "stan konta: " + gracz.getKasa() + "\n");
    }

    public void ruchgracza() {                                 //ruch gracza

        if(ai.isWiezienie()==true){
            for(int i = 3; i>0;i--){
                procesRuchGracza();
            }
            ai.setWiezienie(false);
        }else{
            procesRuchGracza();
        }


        rzutK.setDisable(true);
        koniectury.setDisable(false);

        if(gracz.kasa<=0) {
            Dialogs.dialogApplicationGracz();
            Platform.exit();
        }
        if(ai.kasa<=0) {
            Dialogs.dialogApplicationAI();
            Platform.exit();
        }
    }

    public void kup() {
        int poz = gracz.getPozycja();
        int cena = pl[poz].getCena();
        if (cena < gracz.getKasa() && pl[poz].getWlasnosc() == 0) {
            int kasa = gracz.getKasa();
            kasa = kasa - cena;
            gracz.setKasa(kasa);
            pl[poz].setWlasnosc(1);
            twlasciciel.setText("Właściciel: Gracz");
            System.out.print("Pole " + poz + " należy teraz do gracza\n");
            stankonta.setText(Integer.toString(gracz.getKasa())+"$");
        } else System.out.print("Nie możesz kupić tego pola!\n");
        kup.setDisable(true);
    }

    public void procesRuchAi(){
        int lx = 700, ly = 715, lyy = 115, lxx = 100;
        int poz = ai.getPozycja();
        int rzut = 0;
        rzut = 1 + generator.nextInt(5);
        wynikRzutu.setText("Wynik Rzutu: "+(Integer.toString(rzut)));
        poz = poz + rzut;
        if (poz > 23) {
            poz = poz - 23;
            int start = 250;
            int kasa = ai.getKasa();
            kasa = kasa + start;
            ai.setKasa(kasa);
            stanKontaAI.setText(Integer.toString(ai.getKasa())+"$");
        }

        if (poz == 18) {                                           //więzienie
            poz = 6;
            ai.setWiezienie(true);
        }

        if (poz >= 0 && poz <= 6) {                                // ruch pionka AI
            pion2.setLayoutY(715);
            lx = lx - poz * 100;
            pion2.setLayoutX(lx);
        }
        if (poz >= 7 && poz <= 12) {
            pion2.setLayoutX(100);
            ly = ly - (poz - 6) * 100;
            pion2.setLayoutY(ly);
        }
        if (poz >= 13 && poz <= 18) {
            pion2.setLayoutY(115);
            lxx = lxx + (poz - 12) * 100;
            pion2.setLayoutX(lxx);
        }
        if (poz >= 19 && poz <= 23) {
            pion2.setLayoutX(700);
            lyy = lyy + (poz - 18) * 100;
            pion2.setLayoutY(lyy);
        }

        ai.setPozycja(poz);

        if (pl[poz].getWlasnosc() == 1) {
            ai.setKasa(ai.getKasa() - pl[poz].getCzynsz());
            gracz.setKasa((gracz.getKasa()+pl[poz].getCzynsz()));
            System.out.print("AI płaci czynsz " + pl[poz].getCzynsz() + "$!\n");
            stankonta.setText(Integer.toString(gracz.getKasa())+"$");
            stanKontaAI.setText(Integer.toString(ai.getKasa())+"$");
        }

        if (pl[poz].getKara() != 0) {
            int kasa = ai.getKasa();
            kasa = kasa - pl[poz].getKara();
            ai.setKasa(kasa);
            stanKontaAI.setText(Integer.toString(ai.getKasa())+"$");
        }

        if (pl[poz].getNagroda() != 0) {
            int kasa = ai.getKasa();
            kasa = kasa + pl[poz].getNagroda();
            ai.setKasa(kasa);
            stanKontaAI.setText(Integer.toString(ai.getKasa())+"$");
        }

        if (ai.getKasa() > pl[poz].getCena() && pl[poz].getWlasnosc() == 0) {
            int kasa = ai.getKasa();
            int cena = pl[poz].getCena();
            kasa = kasa - cena;
            ai.setKasa(kasa);
            stanKontaAI.setText(Integer.toString(ai.getKasa())+"$");
            pl[poz].setWlasnosc(2);
            System.out.print("Pole " + poz + " należy do AI\n");
        }

        System.out.print("AI:\npozycja:" + ai.getPozycja() + "\n" + "stan konta: " + ai.getKasa() + "\n");
    }

    public void ruchai() {
        kup.setDisable(true);
        if (gracz.isWiezienie() == true){
            for (int i = 3; i > 0; i--) {
                procesRuchAi();
            }
            gracz.setWiezienie(false);
        }
        else {
            {
                procesRuchAi();
            }

            rzutK.setDisable(false);
            koniectury.setDisable(true);

            if(gracz.kasa<=0) {
                Dialogs.dialogApplicationGracz();
                Platform.exit();
            }
            if(ai.kasa<=0) {
                Dialogs.dialogApplicationAI();
                Platform.exit();
            }
        }
    }
}
