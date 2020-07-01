package sample;

import javafx.scene.control.Alert;

public class Dialogs {

    public static void dialogApplicationAI(){

        Alert informationAlert = new Alert(Alert.AlertType.INFORMATION);
        informationAlert.setTitle("Koniec Gry");
        informationAlert.setContentText("Wygrywa Gracz!");
        informationAlert.setHeaderText("Brawo!");
        informationAlert.showAndWait();
    }

    public static void dialogApplicationGracz(){

        Alert informationAlert = new Alert(Alert.AlertType.INFORMATION);
        informationAlert.setTitle("Koniec Gry");
        informationAlert.setContentText("Wygrywa AI!");
        informationAlert.setHeaderText("Przegrałeś!");
        informationAlert.showAndWait();
    }
}
