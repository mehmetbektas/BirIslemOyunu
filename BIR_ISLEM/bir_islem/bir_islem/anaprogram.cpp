#include<allegro.h>
#include<stdlib.h>
#include<time.h>
#include"degiskenler.h"
#include"tanimlamalar.h"
#include"fonksiyonlar.h"


int main()
{
	oyunu_yukle();
	yuklemeler();

	yeni=0;
	basla_tik=0;
	
	while(!key[KEY_ESC])
	{
		c=0;
		kontrol=2;
		ana_ekran();
		show_mouse(arakatman);
		select_mouse_cursor (MOUSE_CURSOR_ALLEGRO);
		mouse_kontrolleri();
		halkalara_yaz();

		if(yeni==1)
		{
			srand(time(NULL));
			for(k=0;k<5;k++) sayilar[k]=rand()%10+1;
			sayilar[5]=rand()%100+50;
			hedef=rand()%900+100;
			
			for(k=0;k<6;k++) alti_sayi[k]=sayilar[k];
			
			yeni=0;
			kontrol=0;
			
		}	
									
		
		while(basla_tik==1) //çözüm bulunuyor
		{	
			dongu_ekrani();
			show_mouse(arakatman);
			select_mouse_cursor (MOUSE_CURSOR_BUSY);
			halkalara_yaz();
			
			if(hedef != sonuc) //alti1
			{
				do
				{
					s1=rand()%6+0;
					s2=rand()%6+0;
				}while(s1==s2);
				
				op=operator_uret(alti_sayi[s1],alti_sayi[s2]);
				sonuc=islem_yap(alti_sayi[s1],alti_sayi[s2],op);

				if(op==1) textprintf_ex(arakatman,font,550,250,makecol(0,255,0),0,"%d + %d = %d",alti_sayi[s1],alti_sayi[s2],sonuc);
				if(op==2) textprintf_ex(arakatman,font,550,250,makecol(0,255,0),0,"%d - %d = %d",alti_sayi[s1],alti_sayi[s2],sonuc);
				if(op==3) textprintf_ex(arakatman,font,550,250,makecol(0,255,0),0,"%d x %d = %d",alti_sayi[s1],alti_sayi[s2],sonuc);
				if(op==4) textprintf_ex(arakatman,font,550,250,makecol(0,255,0),0,"%d / %d = %d",alti_sayi[s1],alti_sayi[s2],sonuc);

				l=0;
				for(k=0;k<6;k++)
				{
					if(k!=s1 && k!=s2)
					{
						bes_sayi[l]=alti_sayi[k];
						l++;
					}
					else continue;
				}
				bes_sayi[4]=sonuc;

		/*******************************************************************************************************************/
					
				kutux=kutular_x+20; kutuy=kutular_y+20;
				for(k=0;k<5;k++)
				{
					textprintf_ex(arakatman,font,kutux,kutuy,makecol(255,255,0),-1,"%d",bes_sayi[k]);
					kutux+=75;
				}
	//*****************************************************************************************************************************************			
				if(hedef != sonuc) //bes
				{
					do
					{
						s1=rand()%5+0;
						s2=rand()%5+0;
					}while(s1==s2);

					op=operator_uret(bes_sayi[s1],bes_sayi[s2]);
					sonuc=islem_yap(bes_sayi[s1],bes_sayi[s2],op);
								
					if(op==1) textprintf_ex(arakatman,font,550,300,makecol(0,255,0),1,"%d + %d = %d",bes_sayi[s1],bes_sayi[s2],sonuc);
					if(op==2) textprintf_ex(arakatman,font,550,300,makecol(0,255,0),1,"%d - %d = %d",bes_sayi[s1],bes_sayi[s2],sonuc);
					if(op==3) textprintf_ex(arakatman,font,550,300,makecol(0,255,0),1,"%d x %d = %d",bes_sayi[s1],bes_sayi[s2],sonuc);
					if(op==4) textprintf_ex(arakatman,font,550,300,makecol(0,255,0),1,"%d / %d = %d",bes_sayi[s1],bes_sayi[s2],sonuc);
						
					l=0;
					for(k=0;k<5;k++)
					{
						if(k!=s1 && k!=s2)
						{
							dort_sayi[l]=bes_sayi[k];
							l++;
						}
						else continue;
					}
					dort_sayi[3]=sonuc;

						
					kutux=kutular_x+20; kutuy=kutular_y+58;
					for(k=0;k<4;k++)
					{
						textprintf_ex(arakatman,font,kutux,kutuy,makecol(255,255,0),-1,"%d",dort_sayi[k]);
						kutux+=75;
					}

		//	*******************************************************************************************************************

					if(hedef != sonuc) //dört
					{
						do
						{
							s1=rand()%4+0;
							s2=rand()%4+0;
						}while(s1==s2);
							
						op=operator_uret(dort_sayi[s1],dort_sayi[s2]);
						sonuc=islem_yap(dort_sayi[s1],dort_sayi[s2],op);
							
						if(op==1) textprintf_ex(arakatman,font,550,350,makecol(0,255,0),1,"%d + %d = %d",dort_sayi[s1],dort_sayi[s2],sonuc);
						if(op==2) textprintf_ex(arakatman,font,550,350,makecol(0,255,0),1,"%d - %d = %d",dort_sayi[s1],dort_sayi[s2],sonuc);
						if(op==3) textprintf_ex(arakatman,font,550,350,makecol(0,255,0),1,"%d x %d = %d",dort_sayi[s1],dort_sayi[s2],sonuc);
						if(op==4) textprintf_ex(arakatman,font,550,350,makecol(0,255,0),1,"%d / %d = %d",dort_sayi[s1],dort_sayi[s2],sonuc);
							
						l=0;
						for(k=0;k<4;k++)
						{
							if(k!=s1 && k!=s2)
							{
								uc_sayi[l]=dort_sayi[k];
								l++;
							}
							else continue;
						}
						uc_sayi[2]=sonuc;
	
						
						kutux=kutular_x+20; kutuy=kutular_y+96;
						for(k=0;k<3;k++)
						{
							textprintf_ex(arakatman,font,kutux,kutuy,makecol(255,255,0),-1,"%d",uc_sayi[k]);
							kutux+=75;
						}

				//*************************************************************************************
		
						if(hedef != sonuc) //uc
						{
							do
							{
								s1=rand()%3+0;
								s2=rand()%3+0;
							}while(s1==s2);
								
							op=operator_uret(uc_sayi[s1],uc_sayi[s2]);
							sonuc=islem_yap(uc_sayi[s1],uc_sayi[s2],op);
								
							if(op==1) textprintf_ex(arakatman,font,550,400,makecol(0,255,0),1,"%d + %d = %d",uc_sayi[s1],uc_sayi[s2],sonuc);
							if(op==2) textprintf_ex(arakatman,font,550,400,makecol(0,255,0),1,"%d - %d = %d",uc_sayi[s1],uc_sayi[s2],sonuc);
							if(op==3) textprintf_ex(arakatman,font,550,400,makecol(0,255,0),1,"%d x %d = %d",uc_sayi[s1],uc_sayi[s2],sonuc);
							if(op==4) textprintf_ex(arakatman,font,550,400,makecol(0,255,0),1,"%d / %d = %d",uc_sayi[s1],uc_sayi[s2],sonuc);
								
							l=0;
							for(k=0;k<3;k++)
							{
								if(k!=s1 && k!=s2)
								{
									iki_sayi[l]=uc_sayi[k];
									l++;
								}
								else continue;
							}	
							iki_sayi[1]=sonuc;
		
							kutux=kutular_x+20; kutuy=kutular_y+134;
							for(k=0;k<2;k++)
							{
								textprintf_ex(arakatman,font,kutux,kutuy,makecol(255,255,0),-1,"%d",iki_sayi[k]);
								kutux+=75;
							}
							//************************************************************************************
								
							if(hedef != sonuc) //iki
							{
								// zaten dizi iki elemanli oldugu için rastgele sayý üretme yok
									
								op=operator_uret(iki_sayi[s1],iki_sayi[s2]);
								sonuc=islem_yap(iki_sayi[s1],iki_sayi[s2],op);
									
								if(op==1) textprintf_ex(arakatman,font,550,450,makecol(0,255,0),1,"%d + %d = %d",iki_sayi[s1],iki_sayi[s2],sonuc);
								if(op==2) textprintf_ex(arakatman,font,550,450,makecol(0,255,0),1,"%d - %d = %d",iki_sayi[s1],iki_sayi[s2],sonuc);
								if(op==3) textprintf_ex(arakatman,font,550,450,makecol(0,255,0),1,"%d x %d = %d",iki_sayi[s1],iki_sayi[s2],sonuc);
								if(op==4) textprintf_ex(arakatman,font,550,450,makecol(0,255,0),1,"%d / %d = %d",iki_sayi[s1],iki_sayi[s2],sonuc);
									
								kutux=kutular_x+20; kutuy=kutular_y+172;
								textprintf_ex(arakatman,font,kutux,kutuy,makecol(255,255,0),-1,"%d",sonuc);
								
							}	//2
						}	//3	1
					}	//4
				}	//5
			}	//6

			textprintf_ex(arakatman,font,50,450,makecol(255,255,0),-1,"ISLEM SAYISI = %d",c);
			c++;
			textprintf_ex(arakatman,font,50,470,makecol(255,255,0),-1,"GECEN SURE = %d Saniye",c/550);
			
			if(c>=20000)
			{
				kontrol=0;
				basla_tik=0;
				break;
			}
			else if(sonuc==hedef)
			{
				kontrol=1;
				basla_tik=0;
				break; 
			}

			ekrani_temizle();
		}	//basla

		stop_sample(islemyaparken);
		

		if(kontrol==0 && c>0)
		{
			
			play_sample(basarisiz,255,0,1000,0);
			blit(bulunamadi,arakatman,0,0,300,300,800,600);	
			blit(arakatman,screen,0,0,0,0,800,600);
			while(!mouse_b & 1) {}
		}
		else if(c<20000 && kontrol==1)
		{
			play_sample(basarili,255,0,1000,0);
			blit(bulundu,arakatman,0,0,300,300,800,600);
			blit(arakatman,screen,0,0,0,0,800,600);
			while(!mouse_b & 1) {}
		}

	    ekrani_temizle();
		
	}	//esc

	clear_keybuf();
	return 0;
}
END_OF_MAIN();