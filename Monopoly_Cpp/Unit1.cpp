//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <conio>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TP1 *P1;
int lok1=1;
int lok2=1;
int odsiadka1=0;
int odsiadka2=0;
int wlas[23]={0};


// bank gracza
        int bank1=1500;
//bank przeciwnika
        int bank2=1500;

//---------------------------------------------------------------------------
__fastcall TP1::TP1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TP1::Button3Click(TObject *Sender)
{
        if(odsiadka1==0){

                if(lok1==1)
        cz1->Visible=false;

	        else if(lok1==2)
        cz2->Visible=false;

		else if(lok1==3)
        cz3->Visible=false;

		else if(lok1==4)
        cz4->Visible=false;

		else if(lok1==5)
        cz5->Visible=false;

		else if(lok1==6)
        cz6->Visible=false;

		else if(lok1==7)
        cz7->Visible=false;

		else if(lok1==8)
        cz8->Visible=false;

		else if(lok1==9)
        cz9->Visible=false;

		else if(lok1==10)
        cz10->Visible=false;

		else if(lok1==11)
        cz11->Visible=false;

		else if(lok1==12)
        cz12->Visible=false;

		else if(lok1==13)
        cz13->Visible=false;

		else if(lok1==14)
        cz14->Visible=false;

		else if(lok1==15)
        cz15->Visible=false;

		else if(lok1==16)
        cz16->Visible=false;

		else if(lok1==17)
        cz17->Visible=false;

		else if(lok1==18)
        cz18->Visible=false;

		else if(lok1==19)
        cz19->Visible=false;

		else if(lok1==20)
        cz20->Visible=false;

		else if(lok1==21)
        cz21->Visible=false;

		else if(lok1==22)
        cz22->Visible=false;

        randomize();
        int rez;
        int spec=0;
        rez=random(6)+1;
        Label1->Caption = rez;
        lok1+=rez;
        if(lok1>22)
        {
                lok1=lok1-22;
                bank1+=100;
                Label5->Caption=bank1;
        }

        if(wlas[lok1]==2)                          //czynsz
        {
                int czynsz=100+(100*(lok2/22));
                bank2+=czynsz;
                bank1-=czynsz;
                Label5->Caption=bank1;
                Label6->Caption=bank2;

        }

        if(lok1==1){
        cz1->Visible=true;
        spec=1;
        }

	        else if(lok1==2)
        cz2->Visible=true;

		else if(lok1==3)
        cz3->Visible=true;

		else if(lok1==4)
        cz4->Visible=true;

		else if(lok1==5)
        cz5->Visible=true;

		else if(lok1==6)
        cz6->Visible=true;

		else if(lok1==7){
                spec=1;
        cz7->Visible=true;
        }

		else if(lok1==8)
        cz8->Visible=true;

		else if(lok1==9)
        cz9->Visible=true;

		else if(lok1==10)
        cz10->Visible=true;

		else if(lok1==11)
        cz11->Visible=true;

		else if(lok1==12){
                spec=1;
        cz12->Visible=true;
        }

		else if(lok1==13)
        cz13->Visible=true;

		else if(lok1==14)
        cz14->Visible=true;

		else if(lok1==15)
        cz15->Visible=true;

		else if(lok1==16)
        cz16->Visible=true;

		else if(lok1==17)
        cz17->Visible=true;

		else if(lok1==18){    //wiezienie
                lok1=7;
        cz7->Visible=true;
        odsiadka1=2;
        spec=1;
        }

		else if(lok1==19)
        cz19->Visible=true;

		else if(lok1==20)
        cz20->Visible=true;

		else if(lok1==21)
        cz21->Visible=true;

		else if(lok1==22)
        cz22->Visible=true;



        // bonusy i podatki gracza

        if(cz4->Visible==true)
	{
	bank1+=100;
		Label5->Caption=bank1;
                spec=1;
	}
	if(cz6->Visible==true)
	{
	bank1-=150;
		Label5->Caption=bank1;
                spec=1;
	}
	if(cz10->Visible==true)
	{
	bank1-=130;
		Label5->Caption=bank1;
                spec=1;
	}
	if(cz14->Visible==true)
	{
	bank1+=160;
		Label5->Caption=bank1;
                spec=1;
	}
	if(cz17->Visible==true)
	{
	bank1-=180;
		Label5->Caption=bank1;
                spec=1;
	}
	if(cz21->Visible==true)
	{
	bank1+=210;
		Label5->Caption=bank1;
                spec=1;
	}

        if(wlas[lok1]==0&&spec!=1)
        Button2->Enabled=true;

} else
{
Application->MessageBox("Jestes w wiezeniu! Nie mozesz wykonac ruchu, zakoncz ture","Jestes w wiezieniu!",MB_OK);
odsiadka1--;
}


        Button3->Cursor=crDefault;
        Button1->Cursor=crHandPoint;
        Button2->Cursor=crHandPoint;
        Button3->Enabled=false;
        Button1->Enabled=true;


        if(bank1<=0)
	{
        Label5->Caption=0;
        Application->MessageBox("Koniec gry! Wygrywa PRZECIWNIK!\nKliknij OK, aby wyjsc z gry.","KONIEC GRY",MB_OK);
        exit(0);
        }
        else if (bank2<=0)
        {
        Label6->Caption=0;
         Application->MessageBox("Koniec gry! Wygrywa GRACZ!\nKliknij OK, aby wyjsc z gry.","KONIEC GRY",MB_OK);
         exit(0);
        }

}
//---------------------------------------------------------------------------
void __fastcall TP1::Button1Click(TObject *Sender)
{
     if(odsiadka2==0)
     {
                if(lok2==1)
        nb1->Visible=false;

                if(lok2==2)
        nb2->Visible=false;

		if(lok2==3)
        nb3->Visible=false;

		if(lok2==4)
        nb4->Visible=false;

		if(lok2==5)
        nb5->Visible=false;

		if(lok2==6)
        nb6->Visible=false;

		if(lok2==7)
        nb7->Visible=false;

		if(lok2==8)
        nb8->Visible=false;

		if(lok2==9)
        nb9->Visible=false;

		if(lok2==10)
        nb10->Visible=false;

		if(lok2==11)
        nb11->Visible=false;

		if(lok2==12)
        nb12->Visible=false;

		if(lok2==13)
        nb13->Visible=false;

		if(lok2==14)
        nb14->Visible=false;

		if(lok2==15)
        nb15->Visible=false;

		if(lok2==16)
        nb16->Visible=false;

		if(lok2==17)
        nb17->Visible=false;

		if(lok2==18)
        nb18->Visible=false;

		if(lok2==19)
        nb19->Visible=false;

		if(lok2==20)
        nb20->Visible=false;

		if(lok2==21)
        nb21->Visible=false;

		if(lok2==22)
        nb22->Visible=false;

        randomize();
        int rez;
        rez=random(5)+1;                       //ruch AI
        Label1->Caption = rez;
        lok2+=rez;
        if(lok2>22)                             //Przejscie STARTu
        {
                lok2=lok2-22;
                bank2+=100;
                Label6->Caption=bank2;
        }
        if(wlas[lok2]==1)                      // czynsz
        {
                int czynsz=100+(100*(lok2/22));
                bank2-=czynsz;
                Label6->Caption=bank2;
                bank1+=czynsz;
                Label5->Caption=bank1;

        }

                if(lok2==1)
        nb1->Visible=true;

                if(lok2==2)
        nb2->Visible=true;

		if(lok2==3)
        nb3->Visible=true;

		if(lok2==4)
        nb4->Visible=true;

		if(lok2==5)
        nb5->Visible=true;

		if(lok2==6)
        nb6->Visible=true;

		if(lok2==7)
        nb7->Visible=true;

		if(lok2==8)
        nb8->Visible=true;

		if(lok2==9)
        nb9->Visible=true;

		if(lok2==10)
        nb10->Visible=true;

		if(lok2==11)
        nb11->Visible=true;

		if(lok2==12)
        nb12->Visible=true;

		if(lok2==13)
        nb13->Visible=true;

		if(lok2==14)
        nb14->Visible=true;

		if(lok2==15)
        nb15->Visible=true;

		if(lok2==16)
        nb16->Visible=true;

		if(lok2==17)
        nb17->Visible=true;

		if(lok2==18)
        {                               //wiezienie
                lok2=7;
                nb7->Visible=true;
                odsiadka2=2;
        }

		if(lok2==19)
        nb19->Visible=true;

		if(lok2==20)
        nb20->Visible=true;

		if(lok2==21)
        nb21->Visible=true;

		if(lok2==22)
        nb22->Visible=true;








        // bank przeciwnika


	if(wlas[lok2]==0&&bank2>300)
        {
        if(nb2->Visible==true)
	{
                bank2-=80;
		Label6->Caption=bank2;
                wlas[2]=2;
                znnb2->Visible=true;
	}
	if(nb3->Visible==true)
	{
		bank2-=100;
		Label6->Caption=bank2;
                wlas[3]=2;
                znnb3->Visible=true;
	}
	if(nb5->Visible==true)
	{
	bank2-=130;
		Label6->Caption=bank2;
                wlas[5]=2;
                znnb5->Visible=true;

	}
	if(nb8->Visible==true)
	{
	bank2-=150;
		Label6->Caption=bank2;
                wlas[8]=2;
                znnb8->Visible=true;
	}
	if(nb9->Visible==true)
	{
	bank2-=160;
		Label6->Caption=bank2;
                wlas[9]=2;
                znnb9->Visible=true;
	}
	if(nb11->Visible==true)
	{
	bank2-=180;
		Label6->Caption=bank2;
                wlas[11]=2;
                znnb11->Visible=true;
	}
	if(nb13->Visible==true)
	{
	bank2-=200;
		Label6->Caption=bank2;
                wlas[13]=2;
                znnb13->Visible=true;
	}
	if(nb15->Visible==true)
	{
	bank2-=210;
		Label6->Caption=bank2;
                wlas[15]=2;
                znnb15->Visible=true;
	}
	if(nb16->Visible==true)
	{
	bank2-=230;
		Label6->Caption=bank2;
                wlas[16]=2;
                znnb16->Visible=true;
	}
	if(nb19->Visible==true)
	{
	bank2-=240;
		Label6->Caption=bank2;
                wlas[19]=2;
                znnb19->Visible=true;
	}
	if(nb20->Visible==true)
	{
	bank2-=260;
		Label6->Caption=bank2;
                wlas[20]=2;
                znnb20->Visible=true;
	}
	if(nb22->Visible==true)
	{
	bank2-=280;
		Label6->Caption=bank2;
                wlas[22]=2;
                znnb22->Visible=true;
	}

        }


        // bonusy i podatki przeciwnika
        if(nb4->Visible==true)
	{
	bank2+=100;
		Label6->Caption=bank2;
	}
	if(nb6->Visible==true)
	{
	bank2-=150;
		Label6->Caption=bank2;
	}
	if(nb10->Visible==true)
	{
	bank2-=130;
		Label6->Caption=bank2;
	}
	if(nb14->Visible==true)
	{
	bank2+=160;
		Label6->Caption=bank2;
	}
	if(nb17->Visible==true)
	{
	bank2-=180;
		Label6->Caption=bank2;
	}
	if(nb21->Visible==true)
	{
	bank2+=210;
		Label6->Caption=bank2;
	}

     }  else odsiadka2--;




        Button3->Cursor=crHandPoint;
        Button1->Cursor=crDefault;
        Button2->Cursor=crDefault;


        Button3->Enabled=true;
        Button2->Enabled=false;
        Button1->Enabled=false;

        if(bank1<=0)
	{
        Label5->Caption=0;
        Application->MessageBox("Koniec gry! Wygrywa PRZECIWNIK!\nKliknij OK, aby wyjsc z gry.","KONIEC GRY", MB_OK);
        exit(0);
        }
        else if (bank2<=0)
        {
        Label6->Caption=0;
         Application->MessageBox("Koniec gry! Wygrywa GRACZ!\nKliknij OK, aby wyjsc z gry.","KONIEC GRY", MB_OK);
         exit(0);
        }

}
//---------------------------------------------------------------------------


void __fastcall TP1::Button2Click(TObject *Sender)
{

         // kupowanie
	if(cz2->Visible==true){
        if(bank1>80){
                bank1-=80;
		Label5->Caption=bank1;
                wlas[2]=1;
                zncz2->Visible=true;
	}       else Application->MessageBox("Nie stac cie!","BRAK FUNDUSZY", MB_OK);
        }
	if(cz3->Visible==true){
        if(bank1>100){
		bank1-=100;
		Label5->Caption=bank1;
                wlas[3]=1;
                zncz3->Visible=true;
	}       else Application->MessageBox("Nie stac cie!","BRAK FUNDUSZY", MB_OK);}
	if(cz5->Visible==true){
        if(bank1>130){
	        bank1-=130;
		Label5->Caption=bank1;
                wlas[5]=1;
                zncz5->Visible=true;
	}       else Application->MessageBox("Nie stac cie!","BRAK FUNDUSZY", MB_OK);}
	if(cz8->Visible==true){
	if(bank1>150){
	bank1-=150;
		Label5->Caption=bank1;
                wlas[8]=1;
                zncz8->Visible=true;
	}       else Application->MessageBox("Nie stac cie!","BRAK FUNDUSZY", MB_OK);}
	if(cz9->Visible==true){
	if(bank1>160){
	bank1-=160;
		Label5->Caption=bank1;
                wlas[9]=1;
                zncz9->Visible=true;
	}       else Application->MessageBox("Nie stac cie!","BRAK FUNDUSZY", MB_OK);}
	if(cz11->Visible==true){
	if(bank1>180) {
	bank1-=180;
		Label5->Caption=bank1;
                wlas[11]=1;
                zncz11->Visible=true;

	}       else Application->MessageBox("Nie stac cie!","BRAK FUNDUSZY", MB_OK);}
	if(cz13->Visible==true&&bank1>200){
	if(bank1>180){
	bank1-=200;
		Label5->Caption=bank1;
                wlas[13]=1;
                zncz13->Visible=true;
	}       else Application->MessageBox("Nie stac cie!","BRAK FUNDUSZY", MB_OK);}
	if(cz15->Visible==true){
	if(bank1>210){
	bank1-=210;
		Label5->Caption=bank1;
                wlas[15]=1;
                zncz15->Visible=true;
	}       else Application->MessageBox("Nie stac cie!","BRAK FUNDUSZY", MB_OK);}
	if(cz16->Visible==true){
	if(bank1>230){
	        bank1-=230;
		Label5->Caption=bank1;
                wlas[16]=1;
                zncz16->Visible=true;
	}       else Application->MessageBox("Nie stac cie!","BRAK FUNDUSZY", MB_OK);}
	if(cz19->Visible==true){
	if(bank1>240){
	        bank1-=240;
		Label5->Caption=bank1;
                wlas[19]=1;
                zncz19->Visible=true;
	}       else Application->MessageBox("Nie stac cie!","BRAK FUNDUSZY", MB_OK); }
	if(cz20->Visible==true){
	if(bank1>260){
	        bank1-=260;
		Label5->Caption=bank1;
                wlas[20]=1;
                zncz20->Visible=true;
	}       else Application->MessageBox("Nie stac cie!","BRAK FUNDUSZY", MB_OK);}
	if(cz22->Visible==true) {
	if(bank1>280){
	        bank1-=280;
		Label5->Caption=bank1;
                wlas[22]=1;
                zncz22->Visible=true;
	}       else Application->MessageBox("Nie stac cie!","BRAK FUNDUSZY", MB_OK);}


        Button2->Cursor=crDefault;

        Button2->Enabled=false;
}
//---------------------------------------------------------------------------

















