#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

int wygrana;
string getFileContents (std::ifstream&);

string getFileContents (std::ifstream& File)
{
    std::string Lines = "";

    if (File)
    {
	while (File.good ())
	{
	    std::string TempLine;
	    std::getline (File , TempLine);
	    TempLine += "\n";

	    Lines += TempLine;
	}
	return Lines;
    }
    else
    {
	return "Nie znaleziono pliku z obrazem";
    }
}


void kuznia()
{
    std::ifstream Reader ("kuznia.txt");
    std::string Art = getFileContents (Reader);
    std::cout << Art << std::endl;
    Reader.close ();

}

void walka_odbicie(int max_atk1, int max_atk2, int min_atk1, int min_atk2, int hp1, int hp2, string nazw1, string nazw2, int kryt1, int kryt2)
{
    wygrana = 1;
    int max1 = max_atk1 - min_atk1;
    int max2 = max_atk2 - min_atk2;
    srand( time( NULL ) );
    int hpmaxi1 = hp1;
    int hpmaxi2 = hp2;


   do
   {
        int kryt = ( std::rand() % kryt1 ) + 1;
        if(kryt == 1)
        {

            int a = ( std::rand() % max1 ) + min_atk1;
            a = a * 1.5;
             hp2 = hp2 - a;
            cout<<nazw1 <<" zadaje atak krytyczny o wartosci: "<< a <<" obrazen! ["<<hp2<<"/"<<hpmaxi2<<"] \n";

        }

        else
        {

       int a = ( std::rand() % max1 ) + min_atk1;
        hp2 = hp2 - a;
       cout<<nazw1 <<" atakuje zadajac: "<< a <<" obrazen ["<<hp2<<"/"<<hpmaxi2<<"] \n";

        }

       if( 1 > hp2)
       {
            break;
       }
       Sleep(1000);

       int krytB = ( std::rand() % kryt2 ) + 1;
        if(krytB == 1)
        {

            int a = ( std::rand() % max2 ) + min_atk2;
            a = a * 1.5;
            hp1 = hp1 - a;
            cout<<nazw2 <<" zadaje atak krytyczny o wartosci: "<< a <<" obrazen! ["<<hp1<<"/"<<hpmaxi1<<"] \n";
            int odbicie = a * 0.1;
            Sleep(1000);
             hp2 = hp2 - odbicie;
            cout<<nazw1 <<" odbija "<<odbicie<<" obrazen ["<<hp2<<"/"<<hpmaxi2<<"] \n";

        }

        else
       {

       int b = ( std::rand() % max2  ) + min_atk2;
        hp1 = hp1 - b;
       cout<<nazw2 <<" atakuje zadajac: "<< b <<" obrazen ["<<hp1<<"/"<<hpmaxi1<<"] \n";
       int odbicie = b * 0.1;
        hp2 = hp2 - odbicie;
        Sleep(1000);
        cout<<nazw1 <<" odbija "<<odbicie<<" obrazen ["<<hp2<<"/"<<hpmaxi2<<"] \n";



       if( 1 > hp1)

        {
             break;
        }
       Sleep(1000);
       }

   }while(hp1 > 0 || hp2 > 0);

   if( 1 > hp1 )
   {

       cout<<"\nNiestety przegrales z "<<nazw2<<" pozostalo mu "<< hp2 <<" zycia\n";
       wygrana = 0;

   }

   if(1 > hp2)
   {

       cout<<"\nWygrales z "<<nazw2<<" pozostalo mu "<< hp2 <<" zycia\n";
       wygrana = 1;

   }





}

void walka_leczenie(int max_atk1, int max_atk2, int min_atk1, int min_atk2, int hp1, int hp2, string nazw1, string nazw2, int kryt1, int kryt2)
{
    wygrana = 1;
    int max1 = max_atk1 - min_atk1;
    int max2 = max_atk2 - min_atk2;
    srand( time( NULL ) );
    int hpmaxi1 = hp1;
    int hpmaxi2 = hp2;
    int lecz;


   do
   {
        int kryt = ( std::rand() % kryt1 ) + 1;
        if(kryt == 1)
        {

            int a = ( std::rand() % max1 ) + min_atk1;
            a = a * 1.5;
             hp2 = hp2 - a;
             lecz = a * 0.1;
             if(hp1 < hpmaxi1)
             {
             hp1 = hp1 + lecz;
             }
            cout<<nazw1 <<" zadaje atak krytyczny o wartosci: "<< a <<" obrazen! ["<<hp2<<"/"<<hpmaxi2<<"] \n";
            Sleep(1000);
            cout<<nazw1 <<" leczy sie o "<<lecz<<" punktow zycia ["<<hp1<<"/"<<hpmaxi1<<"] \n";

        }

        else
        {

       int a = ( std::rand() % max1 ) + min_atk1;
        hp2 = hp2 - a;
        lecz = a * 0.1;
        if(hp1 < hpmaxi1)
             {
             hp1 = hp1 + lecz;
             }
       cout<<nazw1 <<" atakuje zadajac: "<< a <<" obrazen ["<<hp2<<"/"<<hpmaxi2<<"] \n";
       Sleep(1000);
       cout<<nazw1 <<" leczy sie o "<<lecz<<" punktow zycia ["<<hp1<<"/"<<hpmaxi1<<"] \n";

        }

       if( 1 > hp2)
       {
            break;
       }
       Sleep(1000);

       int krytB = ( std::rand() % kryt2 ) + 1;
        if(krytB == 1)
        {

            int a = ( std::rand() % max2 ) + min_atk2;
            a = a * 1.5;
            hp1 = hp1 - a;
            cout<<nazw2 <<" zadaje atak krytyczny o wartosci: "<< a <<" obrazen! ["<<hp1<<"/"<<hpmaxi1<<"] \n";

        }

        else
       {

       int b = ( std::rand() % max2  ) + min_atk2;
        hp1 = hp1 - b;
       cout<<nazw2 <<" atakuje zadajac: "<< b <<" obrazen ["<<hp1<<"/"<<hpmaxi1<<"] \n";



       if( 1 > hp1)

        {
             break;
        }
       Sleep(1000);
       }

   }while(hp1 > 0 || hp2 > 0);

   if( 1 > hp1 )
   {

       cout<<"\nNiestety przegrales z "<<nazw2<<" pozostalo mu "<< hp2 <<" zycia\n";
       wygrana = 0;

   }

   if(1 > hp2)
   {

       cout<<"\nWygrales z "<<nazw2<<" pozostalo mu "<< hp2 <<" zycia\n";
       wygrana = 1;

   }





}

void walka_ogloszenie(int max_atk1, int max_atk2, int min_atk1, int min_atk2, int hp1, int hp2, string nazw1, string nazw2, int kryt1, int kryt2)
{
    int hpmaxi1 = hp1;
    int hpmaxi2 = hp2;
    wygrana = 1;
    int max1 = max_atk1 - min_atk1;
    int max2 = max_atk2 - min_atk2;
    srand( time( NULL ) );

   do
   {

        int kryt = ( std::rand() % kryt1 ) + 1;
        if(kryt == 1)
        {

            int a = ( std::rand() % max1 ) + min_atk1;
            a = a * 1.5;
             hp2 = hp2 - a;
            cout<<nazw1 <<" zadaje atak krytyczny o wartosci: "<< a <<" obrazen! ["<<hp2<<"/"<<hpmaxi2<<"] \n";

        }

        else
        {

       int a = ( std::rand() % max1 ) + min_atk1;
          hp2 = hp2 - a;
       cout<<nazw1 <<" atakuje zadajac: "<< a <<" obrazen ["<<hp2<<"/"<<hpmaxi2<<"] \n";

        }
        Sleep(1000);
       int ogl = ( std::rand() % 5 ) + 1;
       if(ogl == 1)
       {
            cout<<nazw2<<" zostaje ogloszony\n";
            Sleep(1000);
             int kryt = ( std::rand() % kryt1 ) + 1;
        if(kryt == 1)
        {

            int a = ( std::rand() % max1 ) + min_atk1;
            a = a * 1.5;
             hp2 = hp2 - a;
            cout<<nazw1 <<" zadaje atak krytyczny o wartosci: "<< a <<" obrazen! ["<<hp1<<"/"<<hpmaxi1<<"] \n";

        }

        else
        {

       int a = ( std::rand() % max1 ) + min_atk1;
        hp2 = hp2 - a;
       cout<<nazw1 <<" atakuje zadajac: "<< a <<" obrazen ["<<hp2<<"/"<<hpmaxi2<<"] \n";

        }
            Sleep(1000);

       }

       if( 1 > hp2)
       {
            break;
       }

       int b = ( std::rand() % max2  ) + min_atk2;
        hp1 = hp1 - b;
       cout<<nazw2 <<" atakuje zadajac: "<< b <<" obrazen ["<<hp1<<"/"<<hpmaxi1<<"] \n";
       if( 1 > hp1)
        {
             break;
        }
       Sleep(1000);

   }while(hp1 > 0 || hp2 > 0);

   if( 1 > hp1 )
   {

       cout<<"\nNiestety przegrales z "<<nazw2<<" pozostalo mu "<< hp2 <<" zycia\n";
       wygrana = 0;

   }

   if(1 > hp2)
   {

       cout<<"\nWygrales z "<<nazw2<<" pozostalo mu "<< hp2 <<" zycia\n";
       wygrana = 1;

   }


}


void sakwa()
{

    std::ifstream Reader ("hajs.txt");
    std::string Art = getFileContents (Reader);
    std::cout << Art << std::endl;
    Reader.close ();

}


void sklep()
{
    std::ifstream Reader ("sklep.txt");
    std::string Art = getFileContents (Reader);
    std::cout << Art << std::endl;
    Reader.close ();


}

void gracz()
{

    std::ifstream Reader ("gracz.txt");
    std::string Art = getFileContents (Reader);
    std::cout << Art << std::endl;
    Reader.close ();

}



void arenaobraz()
{

    std::ifstream Reader ("arena.txt");
    std::string Art = getFileContents (Reader);
    std::cout << Art << std::endl;
    Reader.close ();

}




void walka(int max_atk1, int max_atk2, int min_atk1, int min_atk2, int hp1, int hp2, string nazw1, string nazw2, int kryt1, int kryt2)
{
    wygrana = 1;
    int max1 = max_atk1 - min_atk1;
    int max2 = max_atk2 - min_atk2;
    srand( time( NULL ) );
    int hpmaxi1 = hp1;
    int hpmaxi2 = hp2;


   do
   {
        int kryt = ( std::rand() % kryt1 ) + 1;
        if(kryt == 1)
        {

            int a = ( std::rand() % max1 ) + min_atk1;
            a = a * 1.5;
             hp2 = hp2 - a;
            cout<<nazw1 <<" zadaje atak krytyczny o wartosci: "<< a <<" obrazen! ["<<hp2<<"/"<<hpmaxi2<<"] \n";

        }

        else
        {

       int a = ( std::rand() % max1 ) + min_atk1;
        hp2 = hp2 - a;
       cout<<nazw1 <<" atakuje zadajac: "<< a <<" obrazen ["<<hp2<<"/"<<hpmaxi2<<"] \n";

        }

       if( 1 > hp2)
       {
            break;
       }
       Sleep(1000);

       int krytB = ( std::rand() % kryt2 ) + 1;
        if(krytB == 1)
        {

            int a = ( std::rand() % max2 ) + min_atk2;
            a = a * 1.5;
            hp1 = hp1 - a;
            cout<<nazw2 <<" zadaje atak krytyczny o wartosci: "<< a <<" obrazen! ["<<hp1<<"/"<<hpmaxi1<<"] \n";

        }

        else
       {

       int b = ( std::rand() % max2  ) + min_atk2;
        hp1 = hp1 - b;
       cout<<nazw2 <<" atakuje zadajac: "<< b <<" obrazen ["<<hp1<<"/"<<hpmaxi1<<"] \n";



       if( 1 > hp1)

        {
             break;
        }
       Sleep(1000);
       }

   }while(hp1 > 0 || hp2 > 0);

   if( 1 > hp1 )
   {

       cout<<"\nNiestety przegrales z "<<nazw2<<" pozostalo mu "<< hp2 <<" zycia\n";
       wygrana = 0;

   }

   if(1 > hp2)
   {

       cout<<"\nWygrales z "<<nazw2<<" pozostalo mu "<< hp2 <<" zycia\n";
       wygrana = 1;

   }





}


int main(int argc, char *argv[])
{
    srand( time( NULL ) );
    string kula;
    int szatan = 0;
    int m1 = 0;
    int m2 = 0;
    int m3 = 0;
    int m4 = 0;
    int m5 = 0;
    int kul1 = 0;
    int kul2 = 0;
    int kul3 = 0;
    int krytG = 100;
    int koszt1 = 50;
    int koszt2 = 50;
    int koszt3 = 50;
    int kup1 = 0;
    int kup2 = 0;
    int kup3 = 0;
    int hajs = 0;
    string NazwaGracza;
    int lvlG = 1;
    int nextexp = 250;
    int exp = 0;
    int premmax = 0;
    int premmin = 0;
    int premhp = 0;
    int ogl = 0;
    int odb = 0;
    int lecz = 0;
    int debug = 0;
    int cfel = 0;
    int atakcfel = 0;
    int atakmincfel = 0;

    cout<<"Witaj w grze Colloseum!";
    Sleep(2000);
    system("cls");
    std::ifstream Reader ("rycerz.txt");
    std::string Art = getFileContents (Reader);
    std::cout << Art << std::endl;
    Reader.close ();
    cout << "\nPodaj imie: ";
    cin>>NazwaGracza;

    menu:
        if(NazwaGracza == "debug" && debug == 0)
        {

            hajs = 69696969;
            lvlG = 69;
            debug = 1;
            cin.get();
            cin.get();
        }

        int mno = lvlG * 15;
        int mno2 = lvlG * 4;
        int hpG = 85 + mno + premhp - szatan;
        int maxatakG = 27 + mno2 + premmax - atakcfel;
        int minatakG = 17 + mno2 + premmin - atakmincfel;
        int wybor;
        system("cls");
        cout<<"                                          //////////////////////////////////////////////\n";
        cout<<"                                          // [1] - Moja postac                        //\n";
        cout<<"                                          // [2] - Arena                              //\n";
        cout<<"                                          // [3] - Koloseum                           //\n";
        cout<<"                                          // [4] - Stan sakiewki                      //\n";
        cout<<"                                          // [5] - Sklep                              //\n";
        cout<<"                                          // [6] - Wybor kuli umiejetnosci            //\n";
        cout<<"                                          // [7] - Transakcje z Szatanem (od 15 poz.) //\n";
        cout<<"                                          // [8] - Kuznia                             //\n";
        cout<<"                                          // [9] - Wyjscie                            //\n";
        cout<<"                                          //////////////////////////////////////////////\n";
        cin>>wybor;
            switch(wybor)
            {
                 default:
                     {

                    cout<<"\nPodales nieprawidlawa liczbe!\n";
                    cin.get();
                    cin.get();
                    goto menu;

                     }


                case 1:
                    system("cls");
                    cout<<"Nazywasz sie "<<NazwaGracza;
                    if(krytG > 0)
                    {

                        cout<<". Masz "<<lvlG<<" poziom. \nTwoj atak wynosi "<<minatakG<<" - "<<maxatakG<<" obrazen. \nMasz "<<hpG<<" pkt zdrowia. \nTwoja szansa na atak krytyczny wynosi "<<100 / krytG<<" %";

                    }

                    else if(krytG == 0)
                    {

                      cout<<". Masz "<<lvlG<<" poziom. \nTwoj atak wynosi "<<minatakG<<" - "<<maxatakG<<" obrazen. \nMasz "<<hpG<<" pkt zdrowia. \nTwoja szansa na atak krytyczny wynosi 0";

                    }

                    cout<<"\nNacisnij enter, aby powrocic do menu\n\n";
                    gracz();
                    cin.get();
                    cin.get();
                    goto menu;


                case 2:
                    arena:
                    system("cls");
                    arenaobraz();
                    cout<<"                                         Witaj na arenie, z kim chcesz walczyc?\n";
                    cout<<"                ///////////////////////////////////////////        ///////////////////////////////////////////\n";
                    cout<<"                //          - Ghoul -                    //        //          - Cyklop -                   //\n";
                    cout<<"                // [1] - informacje o Ghoulu             //        // [9] - informacje o Cyklopie           //\n";
                    cout<<"                // [2] - walka z Ghoulem (lvl 1)         //        // [10] - walka z Cyklopem (lvl 15)      //\n";
                    cout<<"                //          - Minotaur -                 //        //          - Demon -                    //\n";
                    cout<<"                // [3] - informacje o Minotaurze         //        // [11] - informacje o Demonie           //\n";
                    cout<<"                // [4] - Walka z Minotaurem (lvl 3)      //        // [12] - Walka z Demonem (lvl 19)       //\n";
                    cout<<"                //          - Ognisty Nietoperz -        //        //          - Smok -                     //\n";
                    cout<<"                // [5] - informacje o O. Nietoperzu      //        // [13] - informacje o Smoku             //\n";
                    cout<<"                // [6] - Walka z O. Nietoperzem  (lvl 6) //        // [14] - Walka ze Smokiem (lvl 23)      //\n";
                    cout<<"                //          - Mlody smok -               //        //          - Lord Demonów -             //\n";
                    cout<<"                // [7] - informacje o mlodym smoku       //        // [15] - informacje o Lordzie Demonow   //\n";
                    cout<<"                // [8] - Walka z mlodym smokiem (lvl 11) //        // [16] - Walka z L. Demonow (lvl 26)    //\n";
                    cout<<"                //                                       //        //                                       //\n";
                    cout<<"                // [17] - powrot do menu                 //        // [17] - powrot do menu                 //\n";
                    cout<<"                ///////////////////////////////////////////        ///////////////////////////////////////////\n\n";
                    int wyboo;
                    cin>>wyboo;
                    if(wyboo == 1)
                        {
                                system("cls");
                                std::ifstream Reader ("ghoul.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"Nazwa: Ghoul\n";
                                cout<<"Poziom: 1\n";
                                cout<<"Atak: 25-40\n";
                                cout<<"Zdrowie: 70\n";
                                cin.get();
                                cin.get();
                                goto arena;
                        }




                        else if(wyboo == 2)
                        {
                            system("cls");
                            int krytP1 = 15;
                            int hpP1 = 70;
                            int maxatakP1 = 40;
                            int minatakP1 = 25;
                            string P1 = "Ghoul";
                            cout<<"Rozpoczyna sie walka z Ghoulem!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla0;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla0;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla0;

                            }


                            Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            walkaogla0:

                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 15 ) + 5;
                                cout<<"\nOtrzymujesz 50 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 50;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.20;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }


                            else if(wygrana == 0)
                            {
                                int strata = 0.20 * hajs;
                                int proc = 0.05 * exp;
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety tracisz "<<proc<<" pkt doswiadczenia oraz "<<strata<<" sztuk zlota\n";
                                exp = exp - proc;
                                hajs = hajs - strata;
                            }


                            cout<<"\nNacisnij enter aby powrocic na arene";
                            cin.get();
                            cin.get();
                            goto arena;

                        }


                        else if(wyboo == 3)
                        {
                                system("cls");
                                std::ifstream Reader ("minotaur.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"Nazwa: Minotaur\n";
                                cout<<"Poziom: 3\n";
                                cout<<"Zdrowie: 215\n";
                                cout<<"Atak: 20-30\n";
                                cin.get();
                                cin.get();
                                goto arena;


                        }

                        else if(wyboo == 4)
                        {
                            system("cls");
                            int krytP1 = 10;
                            int hpP1 = 215;
                            int maxatakP1 = 30;
                            int minatakP1 = 20;
                            string P1 = "Minotaur";
                            cout<<"Rozpoczyna sie walka z Minotaurem!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogl2;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogl2;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogl2;

                            }
                            Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            walkaogl2:

                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                int gold = ( std::rand() % 15 ) + 20;
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nOtrzymujesz 125 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 125;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.20;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }


                            else if(wygrana == 0)
                            {
                                int strata = 0.20 * hajs;
                                int proc = 0.05 * exp;
                                std::ifstream Reader ("smierc2.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety tracisz "<<proc<<" pkt doswiadczenia oraz "<<strata<<" sztuk zlota\n";
                                exp = exp - proc;
                                hajs = hajs - strata;
                            }


                            cout<<"\nNacisnij enter aby powrocic na arene";
                            cin.get();
                            cin.get();
                            goto arena;

                        }

                        else if(wyboo == 5)
                        {
                                system("cls");
                                std::ifstream Reader ("nietoper.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"Nazwa: Ognisty Nietoperz\n";
                                cout<<"Poziom: 6\n";
                                cout<<"Zdrowie: 250\n";
                                cout<<"Atak: 35-45\n";
                                cin.get();
                                cin.get();
                                goto arena;
                        }



                    else if(wyboo == 6)
                        {
                            system("cls");
                            int krytP1 = 5;
                            int hpP1 = 250;
                            int maxatakP1 = 45;
                            int minatakP1 = 35;
                            string P1 = "Ognisty Nietoperz";
                            cout<<"Rozpoczyna sie walka z Ognistym Nietoperzem!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogl;

                            }


                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogl;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogl;

                            }
                            Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            walkaogl:

                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 15 ) + 35;
                                cout<<"\nOtrzymujesz 200 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 200;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.20;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }

                             else if(wygrana == 0)
                            {
                                int strata = 0.20 * hajs;
                                int proc = 0.05 * exp;
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety tracisz "<<proc<<" pkt doswiadczenia oraz "<<strata<<" sztuk zlota\n";
                                exp = exp - proc;
                                hajs = hajs - strata;
                            }


                            cout<<"\nNacisnij enter aby powrocic na arene";
                            cin.get();
                            cin.get();
                            goto arena;

                        }


                             else if(wyboo == 7)
                        {
                                system("cls");
                                std::ifstream Reader ("msmok.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"Nazwa: Mlody Smok\n";
                                cout<<"Poziom: 11\n";
                                cout<<"Zdrowie: 450\n";
                                cout<<"Atak: 15-30\n";
                                cin.get();
                                cin.get();
                                goto arena;
                        }


                        else if(wyboo == 8)
                        {
                            system("cls");
                            int krytP1 = 6;
                            int hpP1 = 450;
                            int maxatakP1 = 30;
                            int minatakP1 = 15;
                            string P1 = "Mlody Smok";
                            cout<<"Rozpoczyna sie walka z Mlodym Smokiem!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                                goto powalce;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                                goto powalce;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto powalce;

                            }


                              Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            powalce:

                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 15 ) + 50;
                                cout<<"\nOtrzymujesz 320 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 320;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.20;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }


                            else if(wygrana == 0)
                            {
                                int strata = 0.20 * hajs;
                                int proc = 0.05 * exp;
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety tracisz "<<proc<<" pkt doswiadczenia oraz "<<strata<<" sztuk zlota\n";
                                exp = exp - proc;
                                hajs = hajs - strata;
                            }


                            cout<<"\nNacisnij enter aby powrocic na arene";
                            cin.get();
                            cin.get();
                            goto arena;
//                                       //
                        }

                        else if(wyboo == 9)
                        {
                                system("cls");
                                std::ifstream Reader ("cyklop.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"Nazwa: Cyklop\n";
                                cout<<"Poziom: 15\n";
                                cout<<"Zdrowie: 600\n";
                                cout<<"Atak: 20-50\n";
                                cin.get();
                                cin.get();
                                goto arena;
                        }

                        else if(wyboo == 10)
                        {
                            system("cls");
                            int krytP1 = 8;
                            int hpP1 = 600;
                            int maxatakP1 = 50;
                            int minatakP1 = 20;
                            string P1 = "Cyklop";
                            cout<<"Rozpoczyna sie walka z Cyklopem!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                                goto powalce2;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                                goto powalce2;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto powalce2;

                            }


                              Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            powalce2:


                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 15 ) + 65;
                                cout<<"\nOtrzymujesz 500 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 500;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.20;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }


                            else if(wygrana == 0)
                            {
                                int strata = 0.20 * hajs;
                                int proc = 0.05 * exp;
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety tracisz "<<proc<<" pkt doswiadczenia oraz "<<strata<<" sztuk zlota\n";
                                exp = exp - proc;
                                hajs = hajs - strata;
                            }


                            cout<<"\nNacisnij enter aby powrocic na arene";
                            cin.get();
                            cin.get();
                            goto arena;
//                                       //
                        }



                        else if(wyboo == 11)
                        {
                                system("cls");
                                std::ifstream Reader ("demon.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"Nazwa: Demon\n";
                                cout<<"Poziom: 19\n";
                                cout<<"Zdrowie: 800\n";
                                cout<<"Atak: 40-50\n";
                                cin.get();
                                cin.get();
                                goto arena;
                        }

                        else if(wyboo == 12)
                        {
                            system("cls");
                            int krytP1 = 6;
                            int hpP1 = 800;
                            int maxatakP1 = 50;
                            int minatakP1 = 40;
                            string P1 = "Demon";
                            cout<<"Rozpoczyna sie walka z Demonem!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                                goto powalce3;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                                goto powalce3;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto powalce3;

                            }


                              Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            powalce3:


                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 70 ) + 80;
                                cout<<"\nOtrzymujesz 850 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 850;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.20;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }


                            else if(wygrana == 0)
                            {
                                int strata = 0.20 * hajs;
                                int proc = 0.05 * exp;
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety tracisz "<<proc<<" pkt doswiadczenia oraz "<<strata<<" sztuk zlota\n";
                                exp = exp - proc;
                                hajs = hajs - strata;
                            }


                            cout<<"\nNacisnij enter aby powrocic na arene";
                            cin.get();
                            cin.get();
                            goto arena;
//                                       //
                        }

                        else if(wyboo == 13)
                        {
                                system("cls");
                                std::ifstream Reader ("smok.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"Nazwa: Smok\n";
                                cout<<"Poziom: 23\n";
                                cout<<"Zdrowie: 1500\n";
                                cout<<"Atak: 15-70\n";
                                cin.get();
                                cin.get();
                                goto arena;
                        }

                        else if(wyboo == 14)
                        {
                            system("cls");
                            int krytP1 = 6;
                            int hpP1 = 1500;
                            int maxatakP1 = 70;
                            int minatakP1 = 15;
                            string P1 = "Smok";
                            cout<<"Rozpoczyna sie walka ze Smokiem!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                                goto powalce4;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                                goto powalce4;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto powalce4;

                            }


                              Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            powalce4:


                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 350 ) + 150;
                                cout<<"\nOtrzymujesz 1200 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 1200;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.20;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }



                            else if(wygrana == 0)
                            {
                                int strata = 0.20 * hajs;
                                int proc = 0.05 * exp;
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety tracisz "<<proc<<" pkt doswiadczenia oraz "<<strata<<" sztuk zlota\n";
                                exp = exp - proc;
                                hajs = hajs - strata;
                            }


                            cout<<"\nNacisnij enter aby powrocic na arene";
                            cin.get();
                            cin.get();
                            goto arena;

                        }

                             else if(wyboo == 15)
                        {
                                system("cls");
                                std::ifstream Reader ("lord.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"Nazwa: Lord Demonow\n";
                                cout<<"Poziom: 26\n";
                                cout<<"Zdrowie: 2000\n";
                                cout<<"Atak: 40-80\n";
                                cin.get();
                                cin.get();
                                goto arena;
                        }



//                                       //


                        else if(wyboo == 16)
                        {
                            system("cls");
                            int krytP1 = 5;
                            int hpP1 = 2000;
                            int maxatakP1 = 80;
                            int minatakP1 = 40;
                            string P1 = "Lord Demonow";
                            cout<<"Rozpoczyna sie walka z Lordem Demonow!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                                goto powalce52;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                                goto powalce52;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto powalce52;

                            }


                              Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            powalce52:


                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 1000 ) + 500;
                                cout<<"\nOtrzymujesz 1800 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 1800;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.20;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }

                             else if(wygrana == 0)
                            {
                                int strata = 0.20 * hajs;
                                int proc = 0.05 * exp;
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety tracisz "<<proc<<" pkt doswiadczenia oraz "<<strata<<" sztuk zlota\n";
                                exp = exp - proc;
                                hajs = hajs - strata;
                            }


                            cout<<"\nNacisnij enter aby powrocic na arene";
                            cin.get();
                            cin.get();
                            goto arena;

                        }




                         else if(wyboo == 17)
                            goto menu;


                    else
                        {
                            cout<<"\nPodales nieprawidlawa liczbe!";
                            cin.get();
                            cin.get();
                            goto arena;
                        }



                case 3:
                kolo:
                system("cls");
                cout<<"Witaj w Koloseum, wybierz jednego z 5 mistrzow\n";
                cout<<"[1] - Razrows (5 lvl)\n";
                cout<<"[2] - Endeeur (10 lvl)\n";
                cout<<"[3] - Nephrat (15 lvl)\n";
                cout<<"[4] - Morgu (20 lvl)\n";
                cout<<"[5] - Mythezor (wladca areny)\n";
                cout<<"[6] - Powrot do menu\n";
                int mistrz;
                cin>>mistrz;
                if(mistrz == 1)
                {
                    if(m1 == 1)
                    {

                        cout<<"Juz pokonales tego mistrza";
                        cin.get();
                        cin.get();
                        goto menu;

                    }

                            system("cls");
                            int krytP1 = 10;
                            int hpP1 = 400;
                            int maxatakP1 = 45;
                            int minatakP1 = 20;
                            string P1 = "mistrz Razrows";
                            cout<<"Rozpoczyna sie walka z mistrzem Razrows!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla2;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla2;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla2;

                            }


                            Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            walkaogla2:

                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                m1 = 1;
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 25 ) + 100;
                                cout<<"\nOtrzymujesz 200 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 200;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.20;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }


                            else if(wygrana == 0)
                            {
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety tracisz przeceniles swoje sily stawajac do walki z mistrzem Razrows\n";

                            }


                            cout<<"\nNacisnij enter aby powrocic do koloseum";
                            cin.get();
                            cin.get();
                            goto kolo;

                        }





                 if(mistrz == 2)
                {
                    if(m2 == 1)
                    {

                        cout<<"Juz pokonales tego mistrza";
                        cin.get();
                        cin.get();
                        goto menu;

                    }

                            system("cls");
                            int krytP1 = 7;
                            int hpP1 = 700;
                            int maxatakP1 = 60;
                            int minatakP1 = 30;
                            string P1 = "mistrz Endeur";
                            cout<<"Rozpoczyna sie walka z mistrzem Endeur!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla1;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla1;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla1;

                            }


                            Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            walkaogla1:

                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                m2 = 1;
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 100 ) + 300;
                                cout<<"\nOtrzymujesz 500 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 500;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.20;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }


                            else if(wygrana == 0)
                            {
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety tracisz przeceniles swoje sily stawajac do walki z mistrzem Endeur\n";

                            }


                            cout<<"\nNacisnij enter aby powrocic do koloseum";
                            cin.get();
                            cin.get();
                            goto kolo;

                        }

                         if(mistrz == 3)
                {
                    if(m3 == 1)
                    {

                        cout<<"Juz pokonales tego mistrza";
                        cin.get();
                        cin.get();
                        goto menu;

                    }

                            system("cls");
                            int krytP1 = 7;
                            int hpP1 = 1400;
                            int maxatakP1 = 70;
                            int minatakP1 = 20;
                            string P1 = "mistrz Nephrat";
                            cout<<"Rozpoczyna sie walka z mistrzem Nephrat!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla3;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla3;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla3;

                            }


                            Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            walkaogla3:

                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                m2 = 1;
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 100 ) + 600;
                                cout<<"\nOtrzymujesz 800 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 800;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.20;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }


                            else if(wygrana == 0)
                            {
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety tracisz przeceniles swoje sily stawajac do walki z mistrzem Nephrat\n";

                            }


                            cout<<"\nNacisnij enter aby powrocic do koloseum";
                            cin.get();
                            cin.get();
                            goto kolo;

                        }


                if(mistrz == 4)
                {
                    if(m4 == 1)
                    {

                        cout<<"Juz pokonales tego mistrza";
                        cin.get();
                        cin.get();
                        goto menu;

                    }

                            system("cls");
                            int krytP1 = 9;
                            int hpP1 = 2000;
                            int maxatakP1 = 80;
                            int minatakP1 = 45;
                            string P1 = "mistrz Morgu";
                            cout<<"Rozpoczyna sie walka z mistrzem Morgu!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla4;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla4;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla4;

                            }


                            Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            walkaogla4:

                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                m2 = 1;
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 250 ) + 1000;
                                cout<<"\nOtrzymujesz 1000 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 1000;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.20;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }


                            else if(wygrana == 0)
                            {
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety tracisz przeceniles swoje sily stawajac do walki z mistrzem Morgu\n";

                            }


                            cout<<"\nNacisnij enter aby powrocic do koloseum";
                            cin.get();
                            cin.get();
                            goto kolo;

                        }


                        if(mistrz == 5)
                {
                    if(m4 == 1)
                    {

                        cout<<"Juz pokonales tego mistrza";
                        cin.get();
                        cin.get();
                        goto menu;

                    }

                            system("cls");
                            int krytP1 = 6;
                            int hpP1 = 5000;
                            int maxatakP1 = 140;
                            int minatakP1 = 55;
                            string P1 = "mistrz Mythezor";
                            cout<<"Rozpoczyna sie walka z mistrzem Mythezor!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla7;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla7;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla7;

                            }


                            Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            walkaogla7:

                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                m2 = 1;
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 1000 ) + 1000;
                                cout<<"\nOtrzymujesz 4000 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                cout<<"\n TERAZ TO TY JESTEŚ NAJLEPSZYM Z NAJLEPSZYCH NA ARENIE";
                                exp = exp + 1000;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.20;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }


                            else if(wygrana == 0)
                            {
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety przeceniles swoje sily stawajac do walki z mistrzem Mythezor\n";

                            }


                            cout<<"\nNacisnij enter aby powrocic do koloseum";
                            cin.get();
                            cin.get();
                            goto kolo;

                        }


                        else if(mistrz == 6)
                        {
                            goto menu;
                        }


                        else
                        {
                            cout<<"\npodaj prawidlawa liczbe";
                            cin.get();
                            cin.get();
                            goto kolo;
                        }






                case 4:


                    system("cls");
                    cout<<"Posiadzasz obecie "<<hajs<<" sztuk zlota.\n";
                    sakwa();
                    cout<<"Nacisnij enter aby powrocic do menu.";
                    cin.get();
                    cin.get();
                    goto menu;



                case 5:
                    if(cfel == 1)
                    {
                        medyk:
                        system("cls");
                        cout<<"lekasz nie potszebuje broni!\n";
                        cout<<"Sklep dla medykuf\n";
                        cout<<"                                 //////////////////////////////////////////////////////////////////////\n";
                        cout<<"                                 //[1] - zastszyk + 20 do zastszykowania (dla medykuf za darmo)      //\n";
                        cout<<"                                 //[2] - bandasz + pincset do bandaszowania (dla medykuf za darmo)   //\n";
                        cout<<"                                 //[3] - pofrut do meni                                              //\n";
                        cout<<"                                 //////////////////////////////////////////////////////////////////////\n";
                        int wybl;
                        cin>>wybl;
                        if(wybl == 1)
                        {

                            cout<<"kupiles zastszyk za friko";
                            atakcfel = atakcfel + 20;
                            atakmincfel = atakmincfel + 20;
                            cin.get();
                            cin.get();
                            goto medyk;

                        }

                        else if(wybl == 2)
                        {

                            cout<<"kupiles bandasz za friko";
                            atakcfel = atakcfel + 500;
                            atakmincfel = atakmincfel + 500;
                            cin.get();
                            cin.get();
                            goto medyk;

                        }

                        else if(wybl == 3)
                        {

                            goto menu;

                        }

                        else
                        {

                            cout<<"dobsze napisz, a nie piszesz gupoty!";
                            cin.get();
                            cin.get();
                            goto medyk;


                        }

                        cin.get();
                        cin.get();
                        goto menu;

                    }
                    sklep:
                    system("cls");
                    sklep();

                    cout<<"                              Witaj w sklepie! Co chcesz kupic?\n";
                    cout<<"               [1] - Zardzewialy dlugi miecz (+ 3 do ataku, 5% szans na atak krytyczny)  80 sztuk zlota\n";
                    cout<<"               [2] - Stara, skorzana zbroja(+ 20 do zdrowia)  100 sztuk zlota\n";
                    cout<<"               [3] - Kula ogloszenia(20% szans na gloszenie przeciwnika) 550 sztuk zlota\n";
                    cout<<"               [4] - Miecz poltorareczny (+ 6 do ataku, 10% szans na atak krytyczny) 160 sztuk zlota\n";
                    cout<<"               [5] - Zbroja plytowa (+ 50 do zdrowia)  240 sztuk zlota\n";
                    cout<<"               [6] - Katana (+ 15 do maksymalnego ataku, 20% szans na atak krytyczny) 300 sztuk zlota\n";
                    cout<<"               [7] - Kolczuga (+ 130 do zdrowia ) 420 sztuk zlota\n";
                    cout<<"               [8] - Kula leczenia (leczy za 10% zadanych obrazen) 1000 sztuk zlota\n";
                    cout<<"               [9] - Uriziel (+ 20 do ataku, premia + 10 do max. ataku, , 20% szans na atak kryt.) 650 sztuk zlota\n";
                    cout<<"               [10] - Demoniczna Zbroja (+ 300 do zdrowia, premia +10 do maks. ataku) 1000 sztuk zlota\n";
                    cout<<"               [11] - Kula odbicia (zadaje wrogowi 10% przyjetych obrazen) 1500 sztuk zlota\n";
                    cout<<"               [12] - Powrot do menu\n";
                    int wyb;
                    cin>>wyb;
                    if(wyb == 1)
                   {

                       if(hajs >= 80)
                       {
                           int atkm1 = 3;
                           if(atkm1 > premmax)
                           {

                               premmax = premmax + atkm1;
                               premmin = premmin + atkm1;
                               krytG = 20;
                               cout<<"\n Zakupiono Zardzewialy dlugi miecz za 80 sztuk zlota";
                                hajs = hajs - 80;
                                cin.get();
                                cin.get();
                                goto sklep;


                           }

                           else if(atkm1 < premmax)
                           {
                                cout<<"Masz juz silniejsza bron, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep;
                           }

                       }

                       else if(hajs < 80)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto sklep;


                       }

                   }


                   else if(wyb == 2)
                   {

                       if(hajs >= 100)
                       {
                           int hpz1 = 20;
                           if(hpz1 > premhp)
                           {

                               premhp = premhp + hpz1;
                               cout<<"\n Zakupiono Stara, skorzana zbroje za 100 sztuk zlota";
                                hajs = hajs - 100;
                                cin.get();
                                cin.get();
                                goto sklep;


                           }

                           else if(hpz1 < premhp)
                           {
                                cout<<"Masz juz silniejsza zbroje, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep;
                           }

                       }

                       else if(hajs < 100)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto sklep;


                       }

                   }

                   else if(wyb == 3)
                   {
                        if(hajs >= 550)
                       {
                           if(ogl == 0)
                           {

                               cout<<"\n Zakupiono Kule ogloszenia za 550 sztuk zlota";
                                hajs = hajs - 550;
                                kul1 = 1;
                                cin.get();
                                cin.get();
                                goto sklep;


                           }

                           else if(kul1 == 1)
                           {
                                cout<<"Masz juz kule ogloszenia, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep;
                           }

                       }

                       else if(hajs < 550)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto sklep;


                       }

                   }

                   else if(wyb == 4)
                   {

                       if(hajs >= 160)
                       {
                           int atkm1 = 6;
                           if(atkm1 > premmax)
                           {

                               premmax = premmax + atkm1;
                               premmin = premmin + atkm1;
                               krytG = 10;
                               cout<<"\n Zakupiono miecz poltorareczny za 160 sztuk zlota";
                                hajs = hajs - 160;
                                cin.get();
                                cin.get();
                                goto sklep;


                           }

                           else if(atkm1 < premmax)
                           {
                                cout<<"Masz juz silniejsza bron, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep;
                           }

                       }

                       else if(hajs < 160)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto sklep;


                       }

                   }

                   else if(wyb == 5)
                   {

                       if(hajs >= 240)
                       {
                           int hpz1 = 50;
                           if(hpz1 > premhp)
                           {

                               premhp = premhp + hpz1;
                               cout<<"\n Zakupiono zbroje plytowa za 240 sztuk zlota";
                                hajs = hajs - 240;
                                cin.get();
                                cin.get();
                                goto sklep;


                           }

                           else if(hpz1 < premhp)
                           {
                                cout<<"Masz juz silniejsza zbroje, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep;
                           }

                       }

                       else if(hajs < 240)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto sklep;


                       }

                   }

                   else if(wyb == 6)
                   {

                       if(hajs >= 300)
                       {
                           int atkm1 = 15;
                           if(atkm1 > premmax)
                           {

                               premmax = premmax + atkm1;
                               krytG = 5;
                               cout<<"\n Zakupiono katane za 300 sztuk zlota";
                                hajs = hajs - 300;
                                cin.get();
                                cin.get();
                                goto sklep;


                           }

                           else if(atkm1 < premmax)
                           {
                                cout<<"Masz juz silniejsza bron, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep;
                           }

                       }

                       else if(hajs < 300)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto sklep;


                       }

                   }

                   else if(wyb == 7)
                   {

                       if(hajs >= 420)
                       {
                           int hpz1 = 130;
                           if(hpz1 > premhp)
                           {

                               premhp = premhp + hpz1;
                               cout<<"\n Zakupiono kolczuge za 420 sztuk zlota";
                                hajs = hajs - 420;
                                cin.get();
                                cin.get();
                                goto sklep;


                           }

                           else if(hpz1 < premhp)
                           {
                                cout<<"Masz juz silniejsza zbroje, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep;
                           }

                       }

                       else if(hajs < 420)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto sklep;


                       }

                   }

                   else if(wyb == 8)
                   {
                      if(hajs >= 1000)
                       {
                           if(ogl == 0)
                           {

                               cout<<"\n Zakupiono Kule leczenia za 1000 sztuk zlota";
                                hajs = hajs - 1000;
                                kul2 = 1;
                                cin.get();
                                cin.get();
                                goto sklep;


                           }

                           else if(kul2 == 1)
                           {
                                cout<<"Masz juz kule leczenia, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep;
                           }


                   }


                   }


                   else if(wyb == 9)
                   {

                       if(hajs >= 650)
                       {
                           int atkm1 = 20;
                           if(atkm1 > premmax)
                           {

                               premmax = premmax + atkm1 + 10;
                               premmin = premmin + atkm1;
                               krytG = 5;
                               cout<<"\n Zakupiono Uriziel za 650 sztuk zlota";
                                hajs = hajs - 650;
                                cin.get();
                                cin.get();
                                goto sklep;


                           }

                           else if(atkm1 < premmax)
                           {
                                cout<<"Masz juz silniejsza bron, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep;
                           }

                       }

                       else if(hajs < 650)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto sklep;


                       }

                   }

                   else if(wyb == 10)
                   {

                       if(hajs >= 1000)
                       {
                           int hpz1 = 300;
                           int atkm1 = 10;

                           if(hpz1 > premhp)
                           {
                                premmax = premmax + atkm1;
                               premhp = premhp + hpz1;
                               cout<<"\n Zakupiono demoniczna zbroje za 1000 sztuk zlota";
                                hajs = hajs - 1000;
                                cin.get();
                                cin.get();
                                goto sklep;


                           }

                           else if(hpz1 < premhp)
                           {
                                cout<<"Masz juz silniejsza zbroje, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep;
                           }

                       }

                       else if(hajs < 1000)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto sklep;


                       }

                   }


                    else if(wyb == 11)
                   {
                        if(hajs >= 1500)
                       {
                           if(odb == 0)
                           {

                               cout<<"\n Zakupiono Kule odbicia za 1500 sztuk zlota";
                                hajs = hajs - 1500;
                                kul3 = 1;
                                cin.get();
                                cin.get();
                                goto sklep;


                           }

                           else if(kul3 == 1)
                           {
                                cout<<"Masz juz kule odbicia, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep;
                           }

                       }

                       else if(hajs < 1500)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto sklep;


                       }

                   }

                    else if(wyb == 12)
                   {

                        goto menu;

                   }


                   else
                   {

                        cout<<"Podaj prawidlowa liczbe!";
                        cin.get();
                        cin.get();
                        goto sklep;

                   }
if(wyboo == 2)
                        {
                            system("cls");
                            int krytP1 = 15;
                            int hpP1 = 70;
                            int maxatakP1 = 35;
                            int minatakP1 = 15;
                            string P1 = "Ghoul";
                            cout<<"Rozpoczyna sie walka z Ghoulem!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto walkaogla;

                            }


                            Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            walkaogla:

                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 10 ) + 5;
                                cout<<"\nOtrzymujesz 50 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 50;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.40;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }


                            else if(wygrana == 0)
                            {
                                int strata = 0.20 * hajs;
                                int proc = 0.05 * exp;
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNiestety tracisz "<<proc<<" pkt doswiadczenia oraz "<<strata<<" sztuk zlota\n";
                                exp = exp - proc;
                                hajs = hajs - strata;
                            }


                            cout<<"\nNacisnij enter aby powrocic na arene";
                            cin.get();
                            cin.get();
                            goto arena;

                        }

                case 6:
                    kule:
                    system("cls");
                    cout<<"Obecnie wybrana masz "<<kula<<endl;
                    cout<<"Wybierz kule: \n";
                    cout<<"[1] - kula ogloszenia\n";
                    cout<<"[2] - kula leczenia\n";
                    cout<<"[3] - kula odbicia\n";
                    cout<<"[4] powrot do menu\n";
                    int wyb2;
                    cin>>wyb2;
                    if(wyb2 == 1)
                    {
                        if(kul1 == 0)
                        {
                            cout<<"Nie posiadasz tej kuli\n";
                            cin.get();
                            cin.get();
                            goto kule;

                        }

                        cout<<"Wybrano kule ogloszenia\n";
                        kula = "kule ogloszenia";
                        ogl = 1;
                        odb = 0;
                        lecz = 0;
                        cin.get();
                        cin.get();
                        goto kule;

                    }

                    else if(wyb2 == 2)
                    {
                        if(kul2 == 0)
                        {
                            cout<<"Nie posiadasz tej kuli\n";
                            cin.get();
                            cin.get();
                            goto kule;

                        }

                        cout<<"Wybrano kule leczenia\n";
                        kula = "kule leczenia";
                        ogl = 0;
                        odb = 0;
                        lecz = 1;
                        cin.get();
                        cin.get();
                        goto kule;

                    }

                    else if(wyb2 == 3)
                    {
                        if(kul2 == 0)
                        {
                            cout<<"Nie posiadasz tej kuli\n";
                            cin.get();
                            cin.get();
                            goto kule;

                        }

                        cout<<"Wybrano kule odbicia\n";
                        kula = "kule odbicia";
                        ogl = 0;
                        odb = 1;
                        lecz = 0;
                        cin.get();
                        cin.get();
                        goto kule;

                    }



                    else if(wyb2 == 4)
                    {

                        goto menu;

                    }

                    else
                    {

                        cout<<"Wybrales nieprawidlowa liczbe";
                        cin.get();
                        cin.get();
                        goto kule;

                    }





                case 7:
                    sklep2:
                    system("cls");
                    if(lvlG < 15)
                    {

                        cout<<"Nie osiagnales odpowiedniego poziomy aby tu wejsc";
                        cin.get();
                        cin.get();
                        goto menu;

                    }

                    cout<<"Witaj, czy chcialbys cos kupic?\n";
                    cout<<"[1] - Miecz krwi (+ 40 do ataku max, + 20 do ataku min, 20% szans na atak krytyczny)\nKoszt - 1200 sztuk zlota, poswiecenie 70 hp\n";
                    cout<<"[2] - Zbroja Mocy (+ 600 do zdrowia, + 15 do ataku minimalnego)\nKoszt - 1550 sztuk zlota, poswiecenie 100 hp\n";
                    cout<<"[3] - Miecz Zniszczenia (+60 ataku, 15% szans na atak krytyczny)\nKoszt - 1700 sztuk zlota, poswiecenie 120 hp\n";
                    cout<<"[4] - Zbroja niesmiertelnosci (+ 1000 do zdrowia)\nKoszt - 2000 sztuk zlota, poswiecenie 150 hp\n";
                    cout<<"[5] - Powrot do menu\n";
                    int wybb;
                    cin>>wybb;
                    if(wybb == 1)
                   {

                       if(hajs >= 1200)
                       {
                           int atak = 40;
                           if(atak > premmax)
                           {

                               premmax = premmax + atak;
                               premmin = premmin + 20;
                               krytG = 5;
                               cout<<"\n Zakupiono Miecz krwi za 1200 sztuk zlota oraz 70 punktow zdrowia";
                                hajs = hajs - 1200;
                                szatan = szatan + 70;
                                cin.get();
                                cin.get();
                                goto sklep2;


                           }

                           else if(atak < premmax)
                           {
                                cout<<"Masz juz silniejsza bron, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep2;
                           }

                       }

                       else if(hajs < 1200)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto sklep2;


                       }

                   }

                    else if(wybb == 2)
                   {

                       if(hajs >= 1550)
                       {
                           int hpz1 = 600;
                           int atkm1 = 15;

                           if(hpz1 > premhp)
                           {
                                premmin = premmin + atkm1;
                               premhp = premhp + hpz1;
                               cout<<"\n Zakupiono zbroje mocy za 1550 sztuk zlota oraz 100 punktow zdrowia";
                                hajs = hajs - 1550;
                                szatan = szatan + 100;
                                cin.get();
                                cin.get();
                                goto sklep2;


                           }

                           else if(hpz1 < premhp)
                           {
                                cout<<"Masz juz silniejsza zbroje, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep2;
                           }

                       }

                   }




                    else if(wybb == 3)
                   {

                       if(hajs >= 1700)
                       {
                           int atkm1 = 60;
                           if(atkm1 > premmax)
                           {

                               premmax = premmax + atkm1;
                               premmin = premmin + atkm1;
                               krytG = 6;
                               cout<<"\n Zakupiono Miecz zniszczenia za 1700 sztuk zlota oraz 120 punktow zdrowia";
                                hajs = hajs - 1700;
                                szatan = szatan + 120;
                                cin.get();
                                cin.get();
                                goto sklep2;


                           }

                           else if(atkm1 < premmax)
                           {
                                cout<<"Masz juz silniejsza bron, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep2;
                           }

                       }

                       else if(hajs < 1700)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto sklep2;


                       }

                   }

                   else if(wybb == 4)
                   {

                       if(hajs >= 2000)
                       {
                           int hpz1 = 1000;

                           if(hpz1 > premhp)
                           {
                               premhp = premhp + hpz1;
                               cout<<"\n Zakupiono zbroje niesmiertelnosci za 2000 sztuk zlota oraz 150 punktow zdrowia";
                                hajs = hajs - 2000;
                                szatan = szatan + 150;
                                cin.get();
                                cin.get();
                                goto sklep2;


                           }

                           else if(hpz1 < premhp)
                           {
                                cout<<"Masz juz silniejsza zbroje, nie dokonano zakupu.";
                                cin.get();
                                cin.get();
                                goto sklep2;
                           }

                       }



                       else if(hajs < 2000)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto sklep;


                       }

                   }


                   else if(wybb == 5)
                   {
                       goto menu;
                   }

                   else
                   {

                       cout<<"Podaj prawidlawa liczbe";
                       cin.get();
                       cin.get();
                       goto sklep2;

                   }

                case 8:

                    if(cfel == 1)
                    {
                        cout<<"pszeciesz ty broni ni mosz";
                        cin.get();
                        cin.get();
                        goto menu;

                    }

                    kuznia:
                    system("cls");

                    if(kup1 == 1)
                    {

                        koszt1 = koszt1 * 1.10;
                        kup1 = 0;

                    }

                    if(kup2 == 1)
                    {

                        koszt2 = koszt2 * 1.10;
                        kup2 = 0;

                    }

                    if(kup3 == 1)
                    {

                        koszt3 = koszt3 * 1.10;
                        kup3 = 0;

                    }

                    kuznia();
                    cout<<"\n              Witaj w kuzni, co chcesz ulepszyc?\n";
                    cout<<"[1] - Ulepszenie ataku maksymalnego (+ 3) "<<koszt1<<" sztuk zlota\n";
                    cout<<"[2] - Ulepszenie ataku minimalnego (+ 3) "<<koszt2<<" sztuk zlota\n";
                    cout<<"[3] - Ulepszenie pancerza (+ 20 do zdrowia) "<<koszt3<<" sztuk zlota\n";
                    cout<<"[4] - Powrot do menu\n";
                    int wyb1;
                    cin>>wyb1;


                    if (wyb1 == 1)
                    {

                       if(hajs >= koszt1)
                       {
                           int atkm1 = 3;
                            premmax = premmax + atkm1;
                            cout<<"\n Ulepszono maksymalny atak za "<<koszt1<<" sztuk zlota";
                            hajs = hajs - koszt1;
                            kup1 = 1;
                            cin.get();
                            cin.get();
                            goto kuznia;


                       }

                       else if(hajs < koszt1)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto kuznia;


                       }

                    }

                    else if(wyb1 == 2)
                    {

                        int premnowy = minatakG + premmin + mno2;
                      if(premnowy > maxatakG)

                       {

                           cout<<"Nie mozesz ulepszyc ataku minimalnego ponad maksymalny";
                           cin.get();
                            cin.get();
                            goto kuznia;

                       }


                             else if(hajs >= koszt2 && premnowy <= maxatakG)
                        {


                           int atkm1 = 3;
                            premmin = premmin + atkm1;
                            cout<<"\n Ulepszono minimalny atak za "<<koszt2<<" sztuk zlota";
                            hajs = hajs - koszt2;
                            kup2 = 1;
                            cin.get();
                            cin.get();
                            goto kuznia;



                        }






                       else if(hajs < koszt2)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto kuznia;


                       }

                    }

                    else if(wyb1 == 3)
                    {

                        int zdrowie = 20;

                       if(hajs >= koszt3)
                       {
                            premhp = premhp + zdrowie;
                            cout<<"\n Ulepszono zbroje za "<<koszt3<<" sztuk zlota";
                            hajs = hajs - koszt3;
                            kup3 = 1;
                            cin.get();
                            cin.get();
                            goto kuznia;


                       }

                       else if(hajs < koszt3)
                       {

                           cout<<"Nie masz odpowiedniej ilosci sztuk zlota";
                           cin.get();
                            cin.get();
                            goto kuznia;


                       }

                    }

                    else if(wyb1 == 4)

                    {

                         goto menu;

                    }


                    else
                    {

                        cout<<"Podaj prawidlowa liczbe!";
                        cin.get();
                        cin.get();
                        goto kuznia;

                    }




                case 9:
                    wyjscie:
                    system("cls");
                     cout<<"Czy na pewno chcesz wyjs? [tak/nie]\n";
                    string argh;
                    cin>>argh;


                    if(argh == "Jacu")
                    {

                            system("cls");
                            int krytP1 = 100;
                            int hpP1 = 20;
                            int maxatakP1 = 2;
                            int minatakP1 = 1;
                            string P1 = "Jacus";
                            cout<<"Rozpoczyna sie walka ze Jacusiem!\n";
                            if(ogl == 1)
                            {

                               walka_ogloszenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                                goto powalce554;

                            }

                            if(lecz == 1)
                            {

                               walka_leczenie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                                goto powalce554;

                            }

                            if(odb == 1)
                            {

                               walka_odbicie(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);
                               goto powalce554;

                            }


                              Sleep(1000);
                            walka(maxatakG, maxatakP1, minatakG, minatakP1, hpG, hpP1, NazwaGracza, P1, krytG, krytP1);

                            powalce554:


                            Sleep(1000);
                            if(wygrana == 1)
                            {
                                std::ifstream Reader ("wygrana.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                int gold = ( std::rand() % 1 ) + 1;
                                cout<<"\nOtrzymujesz 1 pkt doswiadczenia oraz "<<gold<<" sztuk zlota";
                                exp = exp + 1;
                                hajs = hajs + gold;
                                if(exp >= nextexp)
                                {
                                        cout<<"\nGratulacje awansowales na kolejny poziom!";
                                        int wyme = nextexp * 1.40;
                                        nextexp = nextexp + wyme;
                                        lvlG++;

                                }


                            }



                            else if(wygrana == 0)
                            {
                                int strata = 0.20 * hajs;
                                int proc = 0.05 * exp;
                                std::ifstream Reader ("smierc.txt");
                                std::string Art = getFileContents (Reader);
                                std::cout << Art << std::endl;
                                Reader.close ();
                                cout<<"\nNie mozesz tego przegrac, oszukales!";
                            }


                            cout<<"\nNacisnij enter aby powrocic na arene";
                            cin.get();
                            cin.get();
                            goto arena;

                        }



                    if(argh == "nie")
                    {

                        system("cls");
                        goto menu;

                    }

                    else if(argh == "tak")
                    {

                    goto out;

                    }

                    else if(argh != "tak" || argh != "nie" || argh != "Jacu")
                    {
                        cout<<"\nPodaj prawidlowa odpowiedz:";
                        cin.get();
                        cin.get();
                        goto wyjscie;
                    }





            }

            out:

            return 0;

}







